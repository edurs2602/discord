#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <iostream>
#include <vector>

/*
 *  Arquivo de constantes
 */

namespace cte {

const std::string SAIR = "quit"; // Comando para sair do programa.
const std::string CRIAR_USUARIO =
    "create-user";                 // Comando para criar um novo usuário.
const std::string LOGIN = "login"; // Comando para fazer login.
const std::string DESCONECTAR =
    "disconnect"; // Comando para desconectar do servidor.
const std::string CRIAR_SERVIDOR =
    "create-server"; // Comando para criar um novo servidor.
const std::string MUDAR_DESCRICAO_SERVIDOR =
    "set-server-desc"; // Comando para mudar a descrição de um servidor.
const std::string MUDAR_CONVITE_SERVIDOR =
    "set-server-invite-code"; // Comando para mudar o código de convite de um
                              // servidor.
const std::string LISTAR_SERVIDORES =
    "list-servers"; // Comando para listar os servidores disponíveis.
const std::string REMOVER_SERVIDOR =
    "remove-server"; // Comando para remover um servidor.
const std::string ENTRAR_SERVIDOR =
    "enter-server"; // Comando para entrar em um servidor.
const std::string SAIR_SERVIDOR =
    "leave-server"; // Comando para sair de um servidor.
const std::string LISTAR_PARTICIPANTES =
    "list-participants"; // Comando para listar os participantes de um servidor.
const std::string LISTAR_CANAIS =
    "list-channels"; // Comando para listar os canais de um servidor.
const std::string CRIAR_CANAL =
    "create-channel"; // Comando para criar um novo canal em um servidor.
const std::string ENTRAR_CANAL =
    "enter-channel"; // Comando para entrar em um canal.
const std::string SAIR_CANAL =
    "leave-channel"; // Comando para sair de um canal.
const std::string ENVIAR_MENSAGEM =
    "send-message"; // Comando para enviar uma mensagem.
const std::string LISTAR_MENSAGENS =
    "list-messages"; // Comando para listar as mensagens de um canal.

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

} // namespace cte

#endif // !
