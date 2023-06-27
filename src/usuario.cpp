#include "../include/usuario.h"
#include <iostream>
#include <string>

int generateId() {
  static int s_id{0};
  s_id++;

  return s_id;
};

Usuario::Usuario(){};

Usuario::~Usuario(){};

Usuario::Usuario(std::string email, std::string senha, std::string nome) {
  this->id = generateId();
  this->nome = nome;
  this->email = email;
  this->senha = senha;
};

void Usuario::setId(int id) { this->id = id; };

void Usuario::setNome(std::string nome) { this->nome = nome; };

void Usuario::setEmail(std::string email) { this->email = email; };

void Usuario::setSenha(std::string senha) { this->senha = senha; };

int Usuario::getId() const { return this->id; }

std::string Usuario::getNome() const { return this->nome; }

std::string Usuario::getEmail() const { return this->email; }

std::string Usuario::getSenha() const { return this->senha; }

bool Usuario::operator==(const Usuario &usuario) const {
  return this->getId() == usuario.getId();
}
