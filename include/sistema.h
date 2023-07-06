#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>

#include "servidor.h"
#include "usuario.h"

/**
 * Classe que representa o sistema.
 */

class Sistema {
private:
  std::vector<Usuario *> usuarios;    // Vetor de ponteiros para usuários.
  std::vector<Servidor *> servidores; // Vetor de ponteiros para servidores.
  int idUsuarioAtual;                 // ID do usuário atual.
  std::string nomeCanalAtual;         // Nome do canal atual.
  std::string nomerServidorAtual;     // Nome do servidor atual.
  void downloadServidores();
  void downloadUsuarios();

public:
  /**
   * Construtor padrão da classe Sistema.
   */
  Sistema() = default;

  /**
   * Destrutor da classe Sistema.
   */
  ~Sistema();

  /**
  * Chama as duas funções: downloadUsuarios e downloadServidores
  */
  void download();
  

  static std::string
      getNomeServidorAtual;     // Getter para o nome do servidor atual.
  static int getIdUsuarioAtual; // Getter para o ID do usuário atual.
  static int getIdCanalAtual;   // Getter para o ID do canal atual.

  /**
   * Obtém a hora atual para uso nas mensagens.
   * @return Uma string contendo a hora atual.
   */
  std::string timeMessage();

  /**
   * Verifica se um email já está cadastrado.
   * @param email O email a ser verificado.
   * @return True se o email já está cadastrado, False caso contrário.
   */
  bool procurarEmail(const std::string &email);

  /**
   * Verifica se um servidor já existe.
   * @param nome O nome do servidor a ser verificado.
   * @return True se o servidor já existe, False caso contrário.
   */
  bool procurarServidor(const std::string &nome);

  /**
   * Verifica se um canal já existe em um servidor.
   * @param nome O nome do canal a ser verificado.
   * @param tipo O tipo do canal a ser verificado.
   * @return True se o canal já existe, False caso contrário.
   */
  bool procurarCanal(const std::string &nome, const std::string &tipo);

  // funcionalidades pt 1

  /**
   * Inicia o sistema.
   */
  void iniciar();

  /**
   * Encerra o sistema.
   * @return True se o sistema deve ser encerrado, False caso contrário.
   */
  bool quit();

  /**
   * Cria um novo usuário.
   * @param email O email do usuário.
   * @param senha A senha do usuário.
   * @param nome O nome do usuário.
   * @return True se o usuário foi criado com sucesso, False caso contrário.
   */
  bool create_user(const std::string email, const std::string senha,
                   const std::string nome);

  /**
   * Faz o login de um usuário.
   * @param email O email do usuário.
   * @param senha A senha do usuário.
   */
  void login(const std::string email, const std::string senha);

  /**
   * Desconecta o usuário atual.
   */
  void disconnect();

  /**
   * Cria um novo servidor.
   * @param nome O nome do servidor.
   */
  void create_server(const std::string nome);

  /**
   * Define a descrição de um servidor.
   * @param nome O nome do servidor.
   * @param desc A descrição do servidor.
   */
  void set_server_desc(const std::string nome, const std::string desc);

  /**
   * Define o código de convite de um servidor.
   * @param nome O nome do servidor.
   * @param convite O código de convite do servidor.
   */
  void set_server_invite_code(const std::string nome,
                              const std::string convite);

  /**
   * Lista os servidores disponíveis.
   */
  void list_servers();

  /**
   * Remove um servidor.
   * @param nome O nome do servidor a ser removido.
   */
  void remove_server(const std::string nome);

  /**
   * Entra em um servidor.
   * @param nome O nome do servidor.
   * @param convite O código de convite do servidor.
   */
  void enter_server(const std::string nome, const std::string convite);

  /**
   * Sai do servidor atual.
   */
  void leave_server();

  /**
   * Lista os participantes do servidor atual.
   */
  void list_participants();

  // funcionalidades pt 2

  /**
   * Cria um novo canal no servidor atual.
   * @param nome O nome do canal.
   * @param tipo O tipo do canal.
   */
  void create_channel(const std::string nome, const std::string tipo);

  /**
   * Lista os canais do servidor atual.
   */
  void list_channels();

  /**
   * Entra em um canal do servidor atual.
   * @param nome O nome do canal.
   */
  void enter_channel(const std::string nome);

  /**
   * Sai do canal atual.
   */
  void leave_channel();

  /**
   * Envia uma mensagem para o canal atual.
   * @param mensagem A mensagem a ser enviada.
   */
  void send_message(const std::string mensagem);

  /**
   * Lista as mensagens do canal atual.
   */
  void list_messages();
};

#endif // !DEBUG
