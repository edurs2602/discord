#include "../include/servidor.h"

Servidor::Servidor() {}

Servidor::~Servidor() {}

Servidor::Servidor(int idDono, std::string nome, std::string descricao) {
  this->idDono = idDono;
  this->nome = nome;
  this->descricao = descricao;
  this->codigoConvite = "";
}

void Servidor::setNome(std::string nome) { this->nome = nome; }

void Servidor::setDescricao(std::string descricao) {
  this->descricao = descricao;
}

void Servidor::setCodigo(std::string codigo) { this->codigoConvite = codigo; }

int Servidor::getDono() { return idDono; }

std::string Servidor::getNome() { return nome; }

std::string Servidor::getDesc() { return descricao; }