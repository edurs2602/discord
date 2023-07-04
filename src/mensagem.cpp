#include <iostream>
#include <string>

#include "../include/mensagem.h"

/**
 * Construtor padrão da classe Mensagem.
 */
Mensagem::Mensagem() {}

/**
 * Destrutor da classe Mensagem.
 */
Mensagem::~Mensagem() {}

/**
 * Construtor da classe Mensagem que recebe a data e hora, o remetente e o
 * conteúdo da mensagem.
 * @param dataHora A data e hora da mensagem.
 * @param enviadaPor O ID do remetente da mensagem.
 * @param conteudo O conteúdo da mensagem.
 */
Mensagem::Mensagem(std::string dataHora, int enviadaPor, std::string conteudo) {
  this->dataHora = dataHora;
  this->enviadaPor = enviadaPor;
  this->conteudo = conteudo;
}

/**
 * Define o remetente da mensagem.
 * @param id O ID do remetente.
 */
void Mensagem::setEnviadoPor(int id) { this->enviadaPor = id; }

/**
 * Define a data e hora da mensagem.
 * @param dataHora A data e hora da mensagem.
 */
void Mensagem::setDataHora(std::string dataHora) { this->dataHora = dataHora; }

/**
 * Define o conteúdo da mensagem.
 * @param conteudo O conteúdo da mensagem.
 */
void Mensagem::setConteudo(std::string conteudo) { this->conteudo = conteudo; }

/**
 * Obtém o ID do remetente da mensagem.
 * @return O ID do remetente.
 */
int Mensagem::getEnviadoPor() const { return this->enviadaPor; }

/**
 * Obtém a data e hora da mensagem.
 * @return A data e hora da mensagem.
 */
std::string Mensagem::getDataHora() const { return this->dataHora; }

/**
 * Obtém o conteúdo da mensagem.
 * @return O conteúdo da mensagem.
 */
std::string Mensagem::getConteudo() const { return this->conteudo; }
