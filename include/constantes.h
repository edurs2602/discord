#ifndef CONSTANTES_H 
#define CONSTANTES_H

#include <iostream>
#include <vector>

namespace cte {

const std::string SAIR = "quit";
const std::string CRIAR_USUARIO = "create-user";
const std::string LOGIN = "login";
const std::string DESCONECTAR = "disconnect";
const std::string CRIAR_SERVIDOR = "create-server";
const std::string MUDAR_DESCRICAO_SERVIDOR = "set-server-desc";
const std::string MUDAR_CONVITE_SERVIDOR = "set-server-invite-code";
const std::string LISTAR_SERVIDORES = "list-servers";
const std::string REMOVER_SERVIDOR = "remove-server";
const std::string ENTRAR_SERVIDOR = "enter-server";
const std::string SAIR_SERVIDOR = "leave-server";
const std::string LISTAR_PARTICIPANTES = "list-participants";
const std::string LISTAR_CANAIS = "list-channels";
const std::string CRIAR_CANAL = "create-channel";
const std::string ENTRAR_CANAL = "enter-channel";
const std::string SAIR_CANAL = "leave-channel";
const std::string ENVIAR_MENSAGEM = "send-message";
const std::string LISTAR_MENSAGENS = "list-messages";

const int USUARIO_NAO_LOGADO = -1;
const std::string SERVIDOR_INDEFINIDO = "";
const int CANAL_INDEFINIDO = -1;
const int USUARIO_NAO_ENCONTRADO = -1;

const std::vector<std::pair<std::string, int>> commands_simple_args = {

  {SAIR, 0},
  {CRIAR_USUARIO, 2},
  {LOGIN, 2},
  {DESCONECTAR, 0},
  {CRIAR_SERVIDOR, 1},
  {MUDAR_DESCRICAO_SERVIDOR, 1},
  {MUDAR_CONVITE_SERVIDOR, 1},
  {LISTAR_SERVIDORES, 0},
  {REMOVER_SERVIDOR, 1},
  {ENTRAR_SERVIDOR, 1},
  {SAIR_SERVIDOR, 0},
  {LISTAR_PARTICIPANTES, 0},
  {LISTAR_CANAIS, 0},
  {CRIAR_CANAL, 2},
  {ENTRAR_CANAL, 1},
  {SAIR_CANAL, 0},
  {ENVIAR_MENSAGEM, 1},
  {LISTAR_MENSAGENS, 0}

};

}


#endif // !


