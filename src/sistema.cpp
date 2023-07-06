#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../include/canal_texto.h"
#include "../include/canal_voz.h"
#include "../include/constantes.h"
#include "../include/mensagem.h"
#include "../include/parser.h"
#include "../include/sistema.h"

/**
 * Destrói o objeto Sistema, liberando a memória alocada para os servidores e
 * usuários.
 */
Sistema::~Sistema() {
  // Desaloca os usuarios
  for (Usuario *usuario : usuarios) {
    delete usuario;
  }

  // Desaloca os servidores
  for (Servidor *servidor : servidores) {
    delete servidor;
  }
}

/**
 * Método para realizar o download dos usuários do sistema e salvar em um
 * arquivo.
 */
void Sistema::downloadUsuarios() {
  std::ofstream arquivo(
      "../logs/usuarios.txt"); // Abre o arquivo no modo de escrita

  if (arquivo.is_open()) {
    arquivo << usuarios.size()
            << "\n"; // Escrevendo o total de usuários no arquivo

    for (Usuario *usuario : usuarios) {
      arquivo << usuario->getId() << "\n";    // Escrevendo o ID do usuário
      arquivo << usuario->getNome() << "\n";  // Escrevendo o nome do usuário
      arquivo << usuario->getEmail() << "\n"; // Escrevendo o email do usuário
      arquivo << usuario->getSenha() << "\n"; // Escrevendo a senha do usuário
    }

    arquivo.close(); // Fechando o arquivo
  } else {
    std::cout << "Erro ao abrir o arquivo\n";
  }
}

/**
 * Método para realizar o download dos servidores do sistema e salvar em um
 * arquivo.
 */
void Sistema::downloadServidores() {
  std::ofstream arquivo(
      "../logs/servidores.txt"); // Abre o arquivo no modo de escrita

  if (arquivo.is_open()) {
    arquivo << servidores.size()
            << "\n"; // Escrevendo o total de servidores no arquivo

    for (Servidor *servidor : servidores) {
      arquivo << servidor->getDono()
              << "\n"; // Escrevendo o ID do dono do servidor
      arquivo << servidor->getNome() << "\n"; // Escrevendo o nome do servidor
      arquivo << servidor->getDesc()
              << "\n"; // Escrevendo a descrição do servidor

      if (servidor->getCodigo() == "") {
        arquivo << "\n"; // Escrevendo uma linha vazia caso não haja código de
                         // convite
      } else {
        arquivo << servidor->getCodigo()
                << "\n"; // Escrevendo o código de convite do servidor
      }

      arquivo << servidor->getParticipantesId().size()
              << "\n"; // Escrevendo o número de participantes do servidor

      for (int participanteId : servidor->getParticipantesId()) {
        arquivo << participanteId << "\n"; // Escrevendo o ID do participante
      }

      arquivo << servidor->getCanais().size()
              << "\n"; // Escrevendo o número de canais do servidor

      for (Canal *canal : servidor->getCanais()) {
        arquivo << canal->getNome() << "\n"; // Escrevendo o nome do canal

        bool isTexto = (canal->getNome().find("texto") != std::string::npos);
        std::string tipoCanal = isTexto ? "TEXTO" : "VOZ";
        arquivo << tipoCanal << "\n"; // Escrevendo o tipo do canal

        Canal_Texto *txt = dynamic_cast<Canal_Texto *>(canal);
        Canal_Voz *voz = dynamic_cast<Canal_Voz *>(canal);

        if (tipoCanal == "TEXTO") {
          arquivo << txt->texto.size()
                  << "\n"; // Escrevendo o número de mensagens do canal de texto

          for (auto im = txt->texto.begin(); im != txt->texto.end(); im++) {
            arquivo << im->getEnviadoPor()
                    << "\n"; // Escrevendoo ID do remetente da mensagem
            arquivo << im->getDataHora()
                    << "\n"; // Escrevendo a data/hora da mensagem
            arquivo << im->getConteudo()
                    << "\n"; // Escrevendo o conteúdo da mensagem
          }
        } else if (tipoCanal == "VOZ") {
          arquivo << voz->getUltima()
                  << "\n"; // Escrevendo o conteúdo da última mensagem do canal
                           // de voz
        }
      }
    }

    arquivo.close(); // Fechando o arquivo
  } else {
    std::cout << "Erro ao abrir o arquivo\n";
  }
}

/**
 * Método para realizar o download de usuários e servidores do sistema.
 */
void Sistema::download() {
  downloadUsuarios();
  downloadServidores();
}

/**
 * Retorna uma string com a data e hora atuais no formato "<dd/mm/yyyy -
 * hh:mm:ss>".
 *
 * @return uma string com a data e hora atuais.
 */
std::string Sistema::timeMessage() {
  std::time_t now = std::time(nullptr);
  std::tm *timeNow = std::gmtime(&now);

  std::ostringstream oss;
  oss << "<";

  int day = (timeNow->tm_hour <= 2) ? timeNow->tm_mday - 1 : timeNow->tm_mday;
  oss << std::setfill('0') << std::setw(2) << day << "/";
  oss << std::setfill('0') << std::setw(2) << (timeNow->tm_mon + 1) << "/";
  oss << (timeNow->tm_year + 1900) << " - ";

  int hour = (timeNow->tm_hour) % 24;
  if (hour < 0) {
    hour += 24;
  }
  oss << std::setfill('0') << std::setw(2) << hour << ":";
  oss << std::setfill('0') << std::setw(2) << timeNow->tm_min << ":";
  oss << std::setfill('0') << std::setw(2) << timeNow->tm_sec;

  oss << ">";
  return oss.str();
}

/**
 * Verifica se um determinado email já está cadastrado no sistema.
 *
 * @param email o email a ser verificado.
 * @return true se o email já estiver cadastrado, false caso contrário.
 */
bool Sistema::procurarEmail(const std::string &email) {
  for (auto it = usuarios.begin(); it != usuarios.end(); it++) {
    if (email == (*it)->getEmail()) {
      return true;
    }
  }

  return false;
}

/**
 * Verifica se um determinado servidor já está cadastrado no sistema.
 *
 * @param nome o nome do servidor a ser verificado.
 * @return true se o servidor já estiver cadastrado, false caso contrário.
 */
bool Sistema::procurarServidor(const std::string &nome) {
  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if (nome == (*it)->getNome()) {
      return true;
    }
  }

  return false;
}

/**
 * Verifica se um determinado canal de um servidor está cadastrado no sistema.
 *
 * @param nome o nome do canal a ser verificado.
 * @param tipo o tipo do canal ("texto" ou "voz").
 * @return true se o canal estiver cadastrado, false caso contrário.
 */
bool Sistema::procurarCanal(const std::string &nome, const std::string &tipo) {
  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if ((*it)->getNome() == nomerServidorAtual) {
      for (std::vector<Canal *>::iterator ch = (*it)->canais.begin();
           ch != (*it)->canais.end(); ch++) {
        Canal_Texto *chTexto = dynamic_cast<Canal_Texto *>(*ch);
        Canal_Voz *chVoz = dynamic_cast<Canal_Voz *>(*ch);
        if (tipo == "texto" || tipo == "Texto") {
          if (chTexto != nullptr && chTexto->getNome() == nome) {
            return true;
          }
        } else if (tipo == "voz" || tipo == "Voz") {
          if (chVoz != nullptr && chVoz->getNome() == nome) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

/**
 * Finaliza o sistema Concordo.
 *
 * @return true, indicando que o sistema deve ser finalizado.
 */
bool Sistema::quit() {
  std::cout << "Finalizando o Concordo..." << std::endl;
  download();
  return true;
}

/**
 * Cria um novo usuário com o email, senha e nome fornecidos.
 *
 * @param email o email do usuário.
 * @param senha a senha do usuário.
 * @param nome o nome do usuário.
 * @return true se o usuário foi criado com sucesso, false caso contrário.
 */
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
  download();

  std::cout << "usuário criado com sucesso." << std::endl;
  return true;
}

/**
 * Realiza o login de um usuário com o email e senha fornecidos.
 *
 * @param email o email do usuário.
 * @param senha a senha do usuário.
 */
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

/**
 * Desconecta o usuário atual.
 */
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

/**
 * Cria um novo servidor com o nome fornecido.
 *
 * @param nome o nome do servidor.
 */
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
      download();
      nomerServidorAtual = nome;
      std::cout << "Servidor Criado" << std::endl;
    } else {
      std::cout << "Já existe um servidor com este nome" << std::endl;
    }
  }
}

/**
 * Define a descrição de um servidor existente.
 *
 * @param nome o nome do servidor.
 * @param desc a nova descrição do servidor.
 */
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
              download();
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

/**
 * Define o código de convite de um servidor existente.
 *
 * @param nome o nome do servidor.
 * @param codigo o novo código de convite do servidor.
 */
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
              download();
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

/**
 * Lista os servidores disponíveis no sistema.
 */
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

/**
 * Remove um servidor do sistema.
 */
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
              download();
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

/**
 * Método para entrar em um servidor.
 *
 * @param nome     O nome do servidor para entrar.
 * @param convite  O código de convite para o servidor (opcional).
 */
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
              return;
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
            return;
          }
        }

        if ((*ser)->getCodigo() == "") {
          (*ser)->participantesID.push_back(idUsuarioAtual);
          nomerServidorAtual = (*ser)->getNome();
          std::cout << "Entrou no servidor: " << nomerServidorAtual
                    << " com sucesso" << std::endl;
          return;
        }

        if (convite == (*ser)->getCodigo()) {
          (*ser)->participantesID.push_back(idUsuarioAtual);
          nomerServidorAtual = (*ser)->getNome();
          std::cout << "Entrou no servidor: " << nomerServidorAtual
                    << " com sucesso" << std::endl;
          return;
        } else {
          std::cout << "O servidor necessita de código de convite" << std::endl;
        }
      }
    }
  }
}

/**
 * Método para sair do servidor atual.
 */
void Sistema::leave_server() {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario precisa estar logado." << std::endl;
  }

  if (nomerServidorAtual == "") {
    std::cout << "O Usuario não está em nenhum servidor" << std::endl;
  }

  nomerServidorAtual = "";
  std::cout << "Saindo do servidor..." << std::endl;
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

/**
 * Método para listar todos os canais do servidor.
 */
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
            chTexto += "\n" + chT->getNome();
          } else if (chV != nullptr) {
            chVoz += "\n" + chV->getNome();
          }
        }
      }
    }
  }
  std::cout << chTexto + "\n" + chVoz << std::endl;
}

/**
 * Método para criar os canais no servidor.
 * @param nome     O nome do canal para criar.
 * @param tipo    O tipo de canal para se criar.
 */
void Sistema::create_channel(const std::string nome, const std::string tipo) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario Precisa estar logado" << std::endl;
    return;
  }

  if (nomerServidorAtual == "") {
    std::cout << "É necessario estar em algum servidor" << std::endl;
    return;
  }

  if (nome == "" || tipo == "") {
    std::cout << "Preencha corretamente os campos para se criar um canal"
              << std::endl;
    return;
  }

  if (procurarCanal(nome, tipo)) {
    std::cout << "Canal '" + nome + "' já existe!" << std::endl;
    return;
  }

  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if ((*it)->getNome() == nomerServidorAtual) {
      if ((*it)->getDono() == idUsuarioAtual) {
        Canal *canal = nullptr;

        if (tipo == "texto" || tipo == "Texto") {
          canal = new Canal_Texto();
          canal->setNome(nome);
          (*it)->canais.push_back(canal);
          download();
          nomeCanalAtual = nome;
          std::cout << "Canal " << nome << " de texto criado" << std::endl;
        } else if (tipo == "voz" || tipo == "Voz") {
          canal = new Canal_Voz();
          canal->setNome(nome);
          (*it)->canais.push_back(canal);
          download();
          nomeCanalAtual = nome;
          std::cout << "Canal " << nome << " de voz criado" << std::endl;
        }

        return;
      } else {
        std::cout << "Permissão Negada" << std::endl;
        return;
      }
    }
  }
}

/**
 * Método para entrar no canal disponiveis no servidor.
 * @param nome     O nome do canal para entrar nele se existir.
 */
void Sistema::enter_channel(const std::string nome) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario Precisa estar logado" << std::endl;
  }

  if (nomerServidorAtual == "") {
    std::cout << "É necessario estar em algum servidor" << std::endl;
  }

  if (nomeCanalAtual == nome) {
    std::cout << "O Usuario já está no canal" << std::endl;
  } else {
    for (auto it = servidores.begin(); it != servidores.end(); it++) {
      if (nomerServidorAtual == (*it)->getNome()) {
        for (auto chs = (*it)->canais.begin(); chs != (*it)->canais.end();
             chs++) {
          if ((*chs)->getNome() == nome) {
            nomeCanalAtual = (*chs)->getNome();
            std::cout << "Entrou no canal: " << nome << std::endl;
          }
        }
      }
    }
  }
}

/**
 * Método para sair do canal.
 */
void Sistema::leave_channel() {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario Precisa estar logado" << std::endl;
  }

  if (nomeCanalAtual == "") {
    std::cout << "É necessario estar em algum canal" << std::endl;
  }

  nomeCanalAtual = "";
  std::cout << "Saindo do canal..." << std::endl;
}

void Sistema::send_message(const std::string mensagem) {
  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario Precisa estar logado" << std::endl;
  }

  if (nomerServidorAtual == "") {
    std::cout << "É necessario estar em algum servidor" << std::endl;
  }

  if (nomeCanalAtual == "") {
    std::cout << "É necessario estar em algum canal" << std::endl;
  }

  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if ((*it)->getNome() == nomerServidorAtual) {
      for (auto chs = (*it)->canais.begin(); chs != (*it)->canais.end();
           chs++) {
        Canal_Texto *txt = dynamic_cast<Canal_Texto *>(*chs);
        if (txt != nullptr) {
          Mensagem sms(timeMessage(), idUsuarioAtual, mensagem);
          txt->texto.push_back(sms);
          download();
          std::cout << "Mensagem de texto enviada\n";
        }
      }
      for (auto chs = (*it)->canais.begin(); chs != (*it)->canais.end();
           chs++) {
        Canal_Voz *voz = dynamic_cast<Canal_Voz *>(*chs);
        if (voz != nullptr) {
          Mensagem sms(timeMessage(), idUsuarioAtual, mensagem);
          voz->setUltima(sms);
          download();
          std::cout << "Mensagem de voz enviada\n";
          std::cout << "Mensagem de voz: " << voz->getUltima() + "\n";
        }
      }
    }
  }
}

/**
 * Método para listar as mensagens do servidor.
 */
void Sistema::list_messages() {
  std::string print = "";

  if (idUsuarioAtual == 0) {
    std::cout << "O Usuario Precisa estar logado" << std::endl;
  }

  if (nomerServidorAtual == "") {
    std::cout << "É necessario estar em algum servidor" << std::endl;
  }

  if (nomeCanalAtual == "") {
    std::cout << "É necessario estar em algum canal" << std::endl;
  }

  for (auto it = servidores.begin(); it != servidores.end(); it++) {
    if ((*it)->getNome() == nomerServidorAtual) {
      for (auto chs = (*it)->canais.begin(); chs != (*it)->canais.end();
           chs++) {
        Canal_Texto *txt = dynamic_cast<Canal_Texto *>(*chs);
        Canal_Voz *voz = dynamic_cast<Canal_Voz *>(*chs);
        if (txt != nullptr) {
          for (auto im = txt->texto.begin(); im != txt->texto.end(); im++) {
            for (auto usr = usuarios.begin(); usr != usuarios.end(); usr++) {
              if (im->getEnviadoPor() == (*usr)->getId()) {
                if (print == "") {
                  print = (*usr)->getNome() + im->getDataHora() + ": " +
                          im->getConteudo();
                } else {
                  print += "\n" + (*usr)->getNome() + im->getDataHora() + ": " +
                           im->getConteudo();
                }
              }
            }
          }
          if (print == "") {
            std::cout
                << "Nao foi encontrada nenhuma mensagem de texto para exibir\n";
          }
        } else if (voz != nullptr) {
          if (voz->getUltima() == "") {
            std::cout
                << "Nao foi encontrada nenhuma mensagem de voz para exibir\n";
          } else {
            for (auto usr = usuarios.begin(); usr != usuarios.end(); usr++) {
              print += (*usr)->getNome() + voz->getUltima() + "\n";
            }
          }
        }
      }
    }
  }
  std::cout << print << "\n";
}

/**
 * Método para iniciar o Parser do sistema.
 * e pegar os comandos e argumentos passados pelo usuario.
 */
void Sistema::iniciar() {
  Parser *par = new Parser();

  std::string comandoL, nome, email, senha, desc, codigo, tipo, msg, comandoP;
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
    } else if (comandoP == cte::LISTAR_CANAIS) {
      list_channels();
    } else if (comandoP == cte::CRIAR_CANAL) {
      nome = par->getArg(0);
      tipo = par->getArg(1);
      create_channel(nome, tipo);
    } else if (comandoP == cte::ENTRAR_CANAL) {
      nome = par->getArg(0);
      enter_channel(nome);
    } else if (comandoP == cte::SAIR_CANAL) {
      leave_channel();
    } else if (comandoP == cte::ENVIAR_MENSAGEM) {
      std::string conteudo = comandoL.substr(comandoP.length());
      msg = conteudo;
      send_message(msg);
    } else if (comandoP == cte::LISTAR_MENSAGENS) {
      list_messages();
    }
  }
}
