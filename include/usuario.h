#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

/**
 * Classe que representa um usuário.
 */

class Usuario {
private:
  int id;            // ID do usuário.
  std::string nome;  // Nome do usuário.
  std::string email; // Email do usuário.
  std::string senha; // Senha do usuário.

public:
  /**
   * Construtor padrão da classe Usuario.
   */
  Usuario();

  /**
   * Destrutor da classe Usuario.
   */
  ~Usuario();

  /**
   * Construtor da classe Usuario que recebe o email, senha e nome.
   * @param email O email do usuário.
   * @param senha A senha do usuário.
   * @param nome O nome do usuário.
   */
  Usuario(std::string email, std::string senha, std::string nome);

  /**
   * Define o ID do usuário.
   * @param id O ID do usuário.
   */
  void setId(int id);

  /**
   * Define o nome do usuário.
   * @param nome O nome do usuário.
   */
  void setNome(std::string nome);

  /**
   * Define o email do usuário.
   * @param email O email do usuário.
   */
  void setEmail(std::string email);

  /**
   * Define a senha do usuário.
   * @param senha A senha do usuário.
   */
  void setSenha(std::string senha);

  /**
   * Obtém o ID do usuário.
   * @return O ID do usuário.
   */
  int getId() const;

  /**
   * Obtém o nome do usuário.
   * @return O nome do usuário.
   */
  std::string getNome() const;

  /**
   * Obtém o email do usuário.
   * @return O email do usuário.
   */
  std::string getEmail() const;

  /**
   * Obtém a senha do usuário.
   * @return A senha do usuário.
   */
  std::string getSenha() const;

  /**
   * Sobrecarga do operador de igualdade para comparar dois objetos Usuario.
   * @param usuario O objeto Usuario a ser comparado.
   * @return True se os objetos são iguais, False caso contrário.
   */
  bool operator==(const Usuario &usuario) const;
};

#endif // !USUARIO_H
