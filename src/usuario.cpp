#include "../include/usuario.h"
#include <iostream>
#include <string>

/**
 * Função auxiliar para gerar um ID único.
 * @return O próximo ID disponível.
 */
int generateId() {
  static int s_id{0};
  s_id++;

  return s_id;
};

/**
 * Construtor padrão da classe Usuario.
 */
Usuario::Usuario(){};

/**
 * Destrutor da classe Usuario.
 */
Usuario::~Usuario(){};

/**
 * Construtor da classe Usuario.
 * @param email O email do usuário.
 * @param senha A senha do usuário.
 * @param nome O nome do usuário.
 */
Usuario::Usuario(std::string email, std::string senha, std::string nome) {
  this->id = generateId();
  this->email = email;
  this->senha = senha;
  this->nome = nome;
};

/**
 * Define o ID do usuário.
 * @param id O novo ID do usuário.
 */
void Usuario::setId(int id) { this->id = id; };

/**
 * Define o nome do usuário.
 * @param nome O novo nome do usuário.
 */
void Usuario::setNome(std::string nome) { this->nome = nome; };

/**
 * Define o email do usuário.
 * @param email O novo email do usuário.
 */
void Usuario::setEmail(std::string email) { this->email = email; };

/**
 * Define a senha do usuário.
 * @param senha A nova senha do usuário.
 */
void Usuario::setSenha(std::string senha) { this->senha = senha; };

/**
 * Obtém o ID do usuário.
 * @return O ID do usuário.
 */
int Usuario::getId() const { return this->id; }

/**
 * Obtém o nome do usuário.
 * @return O nome do usuário.
 */
std::string Usuario::getNome() const { return this->nome; }

/**
 * Obtém o email do usuário.
 * @return O email do usuário.
 */
std::string Usuario::getEmail() const { return this->email; }

/**
 * Obtém a senha do usuário.
 * @return A senha do usuário.
 */
std::string Usuario::getSenha() const { return this->senha; }

/**
 * Sobrecarga do operador de igualdade para comparar dois usuários.
 * @param usuario O usuário a ser comparado.
 * @return true se os usuários possuem o mesmo ID, false caso contrário.
 */
bool Usuario::operator==(const Usuario &usuario) const {
  return this->getId() == usuario.getId();
}
