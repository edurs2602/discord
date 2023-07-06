#include "../include/servidor.h"
#include <vector>

/**
 * Construtor padrão da classe Servidor.
 */
Servidor::Servidor() {}

/**
 * Destrutor da classe Servidor.
 * Libera a memória alocada para os objetos do tipo Canal.
 */
Servidor::~Servidor() {
  for (auto canal : canais) {
    delete canal;
  }
}

/**
 * Construtor da classe Servidor.
 * @param idDono O ID do dono do servidor.
 * @param nome O nome do servidor.
 * @param descricao A descrição do servidor.
 */
Servidor::Servidor(int idDono, std::string nome, std::string descricao) {
  this->idDono = idDono;
  this->nome = nome;
  this->descricao = descricao;
  this->codigoConvite = "";
}

/**
 * Define o nome do servidor.
 * @param nome O novo nome do servidor.
 */
void Servidor::setNome(std::string nome) { this->nome = nome; }

/**
 * Define a descrição do servidor.
 * @param descricao A nova descrição do servidor.
 */
void Servidor::setDescricao(std::string descricao) {
  this->descricao = descricao;
}

/**
 * Define o código de convite do servidor.
 * @param codigo O novo código de convite do servidor.
 */
void Servidor::setCodigo(std::string codigo) { this->codigoConvite = codigo; }

/**
 * Obtém o ID do dono do servidor.
 * @return O ID do dono do servidor.
 */
int Servidor::getDono() { return idDono; }

/**
 * Obtém os IDs dos participantes do servidor.
 * @return Um vetor contendo os IDs dos participantes do servidor.
 */
std::vector<int> Servidor::getParticipantesId() { return participantesID; }

/**
 * Obtém o nome do servidor.
 * @return O nome do servidor.
 */
std::string Servidor::getNome() { return nome; }

/**
 * Obtém a descrição do servidor.
 * @return A descrição do servidor.
 */
std::string Servidor::getDesc() { return descricao; }

/**
 * Obtém o código de convite do servidor.
 * @return O código de convite do servidor.
 */
std::string Servidor::getCodigo() { return codigoConvite; }

std::vector<Canal *> Servidor::getCanais() { return canais; }
