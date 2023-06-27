#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "../include/constantes.h"
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
  std::cout << getIdUsuarioAtual << std::endl;
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
    }
  }
}