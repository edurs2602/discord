#include "../include/servidor.h"

Servidor::Servidor() {}

Servidor::~Servidor() {
  for (auto canal : canais) {
    delete canal;
  }
}

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

std::vector<int> Servidor::getParticipantesId() { return participantesID; }

std::string Servidor::getNome() { return nome; }

std::string Servidor::getDesc() { return descricao; }

std::string Servidor::getCodigo() { return codigoConvite; }
