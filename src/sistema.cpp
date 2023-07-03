#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "../include/canal_texto.h"
#include "../include/canal_voz.h"
#include "../include/constantes.h"
#include "../include/mensagem.h"
#include "../include/parser.h"
#include "../include/sistema.h"

Sistema::~Sistema() {
  for (int i = 0; i < servidores.size(); i++)
    delete servidores[i];

  for (int i = 0; i < usuarios.size(); i++)
    delete usuarios[i];
}

std::vector<Usuario *> Sistema::downloadUsuarios() { return this->usuarios; }

std::vector<Servidor *> Sistema::downloadServidores() {
  return this->servidores;
}

std::string Sistema::getNomeServidorAtual = cte::SERVIDOR_INDEFINIDO;
int Sistema::getIdUsuarioAtual = cte::USUARIO_NAO_LOGADO;
int Sistema::getIdCanalAtual = cte::CANAL_INDEFINIDO;

bool Sistema::procurarEmail(const std::string &email) {
  for (auto it = usuarios.begin(); it != usuarios.end(); it++) {
    if (email == (*it)->getEmail()) {
      return true;
    }
  }

  return false;
}

bool Sistema::procurarServidor(const std::string &nome) {
  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if (nome == (*it)->getNome()) {
      return true;
    }
  }

  return false;
}

bool Sistema::procurarCanal(const std::string &nome, const std::string &tipo) {
  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if ((*it)->getNome() == nomerServidorAtual) {
      for (std::vector<Canal *>::iterator ch = (*it)->canais.begin();
           ch != (*it)->canais.end();) {
        Canal_Texto *chTexto = dynamic_cast<Canal_Texto *>(*ch);
        Canal_Voz *chVoz = dynamic_cast<Canal_Voz *>(*ch);
        if (tipo == "texto" || tipo == "Texto") {
          if (chTexto != nullptr) {
            if (chTexto->getNome() == nome) {
              return true;
            }
          }
        } else if (tipo == "voz" || tipo == "Voz") {
          if (chVoz != nullptr) {
            if (chVoz->getNome() == nome)
              return true;
          }
        }
      }
    }
  }

  return false;
}

bool Sistema::quit() {
  std::cout << "Finalizando o Concordo..." << std::endl;
  return true;
}

bool Sistema::create_user(const std::string email, const std::string senha,
                          const std::string nome) {
  if (procurarEmail(email)) {
    std::cout << "Este Email já foi cadastrado" << std::endl;
    return false;
  };

  if (email == "" || senha == "" || nome == "") {
    std::cout << "Preencha todos os campos obrigatórios para poder concluir o "
                 "cadastro"
              << std::endl;
    return false;
  }

  usuarios.push_back(new Usuario(email, senha, nome));

  std::cout << "usuário criado com sucesso." << std::endl;
  return true;
}

void Sistema::login(const std::string email, const std::string senha) {
  nomerServidorAtual = "";
  if (idUsuarioAtual != 0) {
    if (procurarEmail(email) == false) {
      for (std::vector<Usuario *>::iterator iu = usuarios.begin();
           iu != usuarios.end(); iu++) {
        if (email == (*iu)->getEmail()) {
          if (senha == (*iu)->getSenha()) {
            if (idUsuarioAtual == (*iu)->getId()) {
              std::cout << "Logado como " + (*iu)->getEmail() << std::endl;
            }

            idUsuarioAtual = (*iu)->getId();
            std::cout << "Trocando de usuário... Logado como " +
                             (*iu)->getEmail()
                      << std::endl;
          }
        }
      }
    }
    std::cout << "Senha ou usuário inválidos!" << std::endl;
  } else {
    if (procurarEmail(email)) {
      for (std::vector<Usuario *>::iterator iu = usuarios.begin();
           iu != usuarios.end(); iu++) {
        if (email == (*iu)->getEmail()) {
          if (senha == (*iu)->getSenha()) {
            idUsuarioAtual = (*iu)->getId();
            std::cout << "Logado como " + (*iu)->getEmail() << std::endl;
          }
        }
      }
    }
  }
}

void Sistema::disconnect() {
  if (idUsuarioAtual != 0) {
    for (std::vector<Usuario *>::iterator iu = usuarios.begin();
         iu != usuarios.end(); iu++) {
      if (idUsuarioAtual == (*iu)->getId()) {
        idUsuarioAtual = 0;
        nomerServidorAtual = "";
        std::cout << "Desconectando usuário... " + (*iu)->getEmail()
                  << std::endl;
        break;
      }
    }
  }
  std::cout << "Este Usuario não está conectado" << std::endl;
}

void Sistema::create_server(const std::string nome) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario precisa estar logado para efetuar esta operação"
              << std::endl;
  } else {
    if (nome == "") {
      std::cout << "O Servidor precisa ter um nome" << std::endl;
    }

    nomerServidorAtual = "";
    std::string codigo = "";
    std::string desc = "";
    if (procurarServidor(nome) == false) {
      Servidor *servidor = new Servidor(idUsuarioAtual, nome, desc);
      servidores.push_back(servidor);
      nomerServidorAtual = nome;
      std::cout << "Servidor Criado" << std::endl;
    } else {
      std::cout << "Já existe um servidor com este nome" << std::endl;
    }
  }
}

void Sistema::set_server_desc(const std::string nome, const std::string desc) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario precisa estar logado para efetuar esta operação"
              << std::endl;
  } else {
    if (servidores.empty() != true) {
      if (procurarServidor(nome)) {
        for (std::vector<Servidor *>::iterator is = servidores.begin();
             is != servidores.end(); is++) {
          if (nome == (*is)->getNome()) {
            if (idUsuarioAtual == (*is)->getDono()) {
              (*is)->setDescricao('"' + desc + '"');
              std::cout << "Descrição Atualizada" << std::endl;
            } else {
              std::cout << "Ação não permitida, você não é o dono do servidor"
                        << std::endl;
            }
          }
        }
      } else {
        std::cout << "Não existe servidor com este nome" << std::endl;
      }
    } else {
      std::cout << "Sem servidores cadastrados" << std::endl;
    }
  }
}

void Sistema::set_server_invite_code(const std::string nome,
                                     const std::string codigo) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario precisa estar logado para efetuar esta operação"
              << std::endl;
  } else {
    if (servidores.empty() != true) {
      if (procurarServidor(nome)) {
        for (std::vector<Servidor *>::iterator is = servidores.begin();
             is != servidores.end(); is++) {
          if (nome == (*is)->getNome()) {
            if (idUsuarioAtual == (*is)->getDono()) {
              (*is)->setCodigo(codigo);
              std::cout << "Codigo foi Atualizado" << std::endl;
            } else {
              std::cout << "Ação não permitida, você não é o dono do servidor"
                        << std::endl;
            }
          }
        }
      } else {
        std::cout << "Não existe servidor com este nome" << std::endl;
      }
    } else {
      std::cout << "Sem servidores cadastrados" << std::endl;
    }
  }
}

void Sistema::list_servers() {
  std::string print;

  if (idUsuarioAtual == 0) {
    std::cout << "Usuário precisa estar logado para poder listar os servidores "
                 "disponíveis."
              << std::endl;
  } else {
    if (servidores.empty() == false) {
      for (std::vector<Servidor *>::iterator is = servidores.begin();
           is != servidores.end(); is++) {
        if (print == "") {
          print = (*is)->getNome() + "\n" + (*is)->getDesc() + "\n";
          if ((*is)->getCodigo() == "") {
            print = print + "Servidor aberto";
          } else {
            print = print + (*is)->getCodigo();
          }
        } else {
          print =
              print + "\n" + (*is)->getNome() + "\n" + (*is)->getDesc() + "\n";
          if ((*is)->getCodigo() == "") {
            print = print + "Servidor aberto";
          } else {
            print = print + (*is)->getCodigo();
          }
        }
      }
    } else {
      std::cout << "Ainda não há servidores cadastrados" << std::endl;
    }
  }
  std::cout << print << std::endl;
}

void Sistema::remove_server(const std::string nome) {
  if (idUsuarioAtual == 0) {
    std::cout << "Usuário precisa estar logado para poder listar os servidores "
                 "disponíveis."
              << std::endl;
  } else {
    if (!servidores.empty()) {
      if (procurarServidor(nome)) {
        for (std::vector<Servidor *>::iterator is = servidores.begin();
             is != servidores.end(); ++is) {
          if (nome == (*is)->getNome()) {
            if (idUsuarioAtual == (*is)->getDono()) {
              delete *is;
              servidores.erase(is);
              std::cout << "O Servidor '" + nome + "' foi removido"
                        << std::endl;
              return;
            } else {
              std::cout << "Você não é o dono do servidor '" + nome + "'"
                        << std::endl;
              return;
            }
          }
        }
      }
      std::cout << "Servidor '" + nome + "' não encontrado" << std::endl;
    }
  }
}

void Sistema::enter_server(const std::string nome, const std::string convite) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario precisa estar logado." << std::endl;
  }
  if (nomerServidorAtual == nome) {
    std::cout << "O Usuario já está neste servidor" << std::endl;
  } else {
    for (std::vector<Servidor *>::iterator ser = servidores.begin();
         ser != servidores.end(); ser++) {
      if (nome == (*ser)->getNome()) {
        if (idUsuarioAtual == (*ser)->getDono()) {
          std::vector<int> participantesId = (*ser)->getParticipantesId();
          for (std::vector<int>::iterator i = participantesId.begin();
               i != participantesId.end(); i++) {
            if (idUsuarioAtual == *i) {
              nomerServidorAtual = (*ser)->getNome();
              std::cout << "Entrou no servidor: " << nomerServidorAtual
                        << " com sucesso" << std::endl;
            }
          }
        }

        std::vector<int> participantesId = (*ser)->getParticipantesId();
        for (std::vector<int>::iterator i = participantesId.begin();
             i != participantesId.end(); i++) {
          if (idUsuarioAtual == *i) {
            nomerServidorAtual = (*ser)->getNome();
            std::cout << "Entrou no servidor: " << nomerServidorAtual
                      << " com sucesso" << std::endl;
          }
        }

        if ((*ser)->getCodigo() == "") {
          (*ser)->participantesID.push_back(idUsuarioAtual);
          nomerServidorAtual = (*ser)->getNome();
          std::cout << "Entrou no servidor: " << nomerServidorAtual
                    << " com sucesso" << std::endl;
        }

        if (convite == (*ser)->getCodigo()) {
          (*ser)->participantesID.push_back(idUsuarioAtual);
          nomerServidorAtual = (*ser)->getNome();
          std::cout << "Entrou no servidor: " << nomerServidorAtual
                    << " com sucesso" << std::endl;
        } else {
          std::cout << "O servidor necessita de código de convite" << std::endl;
        }
      } else {
        std::cout << "Servidor " << nome << " não encontrado" << std::endl;
      }
    }
  }
}

void Sistema::leave_server() {
  std::string sairServer = nomerServidorAtual;
  if (nomerServidorAtual == "") {
    std::cout << "O Usuario não está em nenhum servidor" << std::endl;
  }
  nomerServidorAtual = "";
  std::cout << "Saindo do servidor: " << sairServer << std::endl;
}

void Sistema::list_participants() {
  std::string print = "";
  if (nomerServidorAtual == "") {
    std::cout << "Usuário não está conectado em nenhum servidor" << std::endl;
  } else {
    for (std::vector<Servidor *>::iterator ser = servidores.begin();
         ser != servidores.end(); ser++) {
      if (nomerServidorAtual == (*ser)->getNome()) {
        for (std::vector<int>::iterator i = (*ser)->participantesID.begin();
             i != (*ser)->participantesID.end(); i++) {
          for (std::vector<Usuario *>::iterator use = usuarios.begin();
               use != usuarios.end(); use++) {
            if (*i == (*use)->getId()) {
              if (print == "") {
                print = (*use)->getNome();
              } else {
                print = print + "\n" + (*use)->getNome();
              }
            }
          }
        }
      }
    }
  }
  std::cout << print << std::endl;
}

void Sistema::list_channels() {
  std::string chTexto = "";
  std::string chVoz = "";

  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario Precisa estar logado" << std::endl;
  }

  if (nomerServidorAtual == "") {
    std::cout << "É necessario estar em algum servidor" << std::endl;
  } else {
    chTexto += "#Canal de texto";
    chVoz += "#Canal de voz";
    for (std::vector<Servidor *>::iterator ser = servidores.begin();
         ser != servidores.end(); ser++) {
      if ((*ser)->getNome() == nomerServidorAtual) {
        for (std::vector<Canal *>::iterator chs = (*ser)->canais.begin();
             chs != (*ser)->canais.end(); chs++) {
          Canal_Texto *chT = dynamic_cast<Canal_Texto *>(*chs);
          Canal_Voz *chV = dynamic_cast<Canal_Voz *>(*chs);
          if (chT != nullptr) {
            chTexto = chTexto + "\n" + chT->getNome();
          } else if (chT != nullptr) {
            chVoz = chVoz + "\n" + chV->getNome();
          }
        }
      }
    }
  }
  std::cout << chTexto + "\n" + chVoz << std::endl;
}

void Sistema::create_channel(const std::string nome, const std::string tipo) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario Precisa estar logado" << std::endl;
  }

  if (nomerServidorAtual == "") {
    std::cout << "É necessario estar em algum servidor" << std::endl;
  }

  if (nome == "" || tipo == "") {
    std::cout << "Preencha corretamente os campos para se criar um canal"
              << std::endl;
  }

  if (procurarCanal(nome, tipo)) {
    if (tipo == "texto" || tipo == "Texto") {
      std::cout << "Canal de texto '" + nome + "' já existe!" << std::endl;
    } else {
      std::cout << "Canal de voz '" + nome + "' já existe!" << std::endl;
    }
  }

  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if ((*it)->getNome() == nomerServidorAtual) {
      if ((*it)->getDono() == idUsuarioAtual) {
        if (tipo == "texto" || tipo == "Texto") {
          Canal *canal = new Canal_Texto;
          canal->setNome(nome);
          (*it)->canais.push_back(canal);
          nomeCanalAtual = nome;
          std::cout << "Canal " << nome << " de texto criado" << std::endl;
        } else if (tipo == "voz" || tipo == "Voz") {
          Canal *canal = new Canal_Voz;
          canal->setNome(nome);
          (*it)->canais.push_back(canal);
          nomeCanalAtual = nome;
          std::cout << "Canal " << nome << " de voz criado" << std::endl;
        }
      } else {
        std::cout << "Permissão Negada" << std::endl;
      }
    }
  }

  std::cout << "Servidor não encontrado" << std::endl;
}

void Sistema::iniciar() {
  Parser *par = new Parser();

  std::string comandoL, nome, email, senha, desc, codigo, comandoP;
  bool parserOk;

  while (true) {
    std::getline(std::cin, comandoL);

    if (!par->parse(comandoL)) {
      continue;
    }

    comandoP = par->getComando();

    if (comandoP == cte::SAIR) {
      if (quit()) {
        std::exit(0);
      } else {
        continue;
      }
    } else if (comandoP == cte::CRIAR_USUARIO) {
      email = par->getArg(0);
      senha = par->getArg(1);
      nome = par->getArgsEspace();
      create_user(email, senha, nome);
    } else if (comandoP == cte::LOGIN) {
      email = par->getArg(0);
      senha = par->getArg(1);
      login(email, senha);
    } else if (comandoP == cte::DESCONECTAR) {
      disconnect();
    } else if (comandoP == cte::CRIAR_SERVIDOR) {
      nome = par->getArg(0);
      create_server(nome);
    } else if (comandoP == cte::MUDAR_DESCRICAO_SERVIDOR) {
      nome = par->getArg(0);
      desc = par->getArgsEspace();
      set_server_desc(nome, desc);
    } else if (comandoP == cte::MUDAR_CONVITE_SERVIDOR) {
      nome = par->getArg(0);
      codigo = par->getArgsEspace();
      set_server_invite_code(nome, codigo);
    } else if (comandoP == cte::LISTAR_SERVIDORES) {
      list_servers();
    } else if (comandoP == cte::REMOVER_SERVIDOR) {
      nome = par->getArg(0);
      remove_server(nome);
    } else if (comandoP == cte::ENTRAR_SERVIDOR) {
      nome = par->getArg(0);
      codigo = par->getArgsEspace();
      enter_server(nome, codigo);
    } else if (comandoP == cte::SAIR_SERVIDOR) {
      leave_server();
    } else if (comandoP == cte::LISTAR_PARTICIPANTES) {
      list_participants();
    }
  }
}
