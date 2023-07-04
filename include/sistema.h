#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>

#include "servidor.h"
#include "usuario.h"

class Sistema {
private:
  std::vector<Usuario *> usuarios;
  std::vector<Servidor *> servidores;
  int idUsuarioAtual;
  std::string nomeCanalAtual;
  std::string nomerServidorAtual;

public:
  Sistema() = default;
  ~Sistema();

  std::vector<Usuario *> downloadUsuarios();
  std::vector<Servidor *> downloadServidores();
  static std::string getNomeServidorAtual;
  static int getIdUsuarioAtual;
  static int getIdCanalAtual;

  std::string timeMessage();

  bool procurarEmail(const std::string &email);
  bool procurarServidor(const std::string &nome);
  bool procurarCanal(const std::string &nome, const std::string &tipo);

  // funcionalidades pt 1
  void iniciar();
  bool quit();
  bool create_user(const std::string email, const std::string senha,
                   const std::string nome);
  void login(const std::string email, const std::string senha);
  void disconnect();
  void create_server(const std::string nome);
  void set_server_desc(const std::string nome, const std::string desc);
  void set_server_invite_code(const std::string nome,
                              const std::string convite);
  void list_servers();
  void remove_server(const std::string nome);
  void enter_server(const std::string nome, const std::string convite);
  void leave_server();
  void list_participants();

  // funcionalidades pt 2
  void create_channel(const std::string nome, const std::string tipo);
  void list_channels();
  void enter_channel(const std::string nome);
  void leave_channel();
  void send_message(const std::string mensagem);
  void list_messages();
};

#endif // !DEBUG
