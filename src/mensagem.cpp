#include <iostream>
#include <string>

#include "../include/mensagem.h"

Mensagem::Mensagem() {}

Mensagem::~Mensagem() {}

Mensagem::Mensagem(int enviadaPor, std::string dataHora, std::string conteudo) {
  this->enviadaPor = enviadaPor;
  this->dataHora = dataHora;
  this->conteudo = conteudo;
}

void Mensagem::setEnviadoPor(int id) { this->enviadaPor = id; }

void Mensagem::setDataHora(std::string dataHora) { this->dataHora = dataHora; }

void Mensagem::setConteudo(std::string conteudo) { this->conteudo = conteudo; }

int Mensagem::getEnviadoPor() { return this->enviadaPor; }

std::string Mensagem::getDataHora() { return this->dataHora; }

std::string Mensagem::getConteudo() { return this->conteudo; }
