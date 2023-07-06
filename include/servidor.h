#include "canal.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#ifndef SERVIDOR_H
#define SERVIDOR_H

/**
 * Classe que representa um servidor.
 */

class Servidor {
private:
  int idDono;                // ID do dono do servidor.
  std::string nome;          // Nome do servidor.
  std::string descricao;     // Descrição do servidor.
  std::string codigoConvite; // Código de convite do servidor.

public:
  /**
   * Construtor padrão da classe Servidor.
   */
  Servidor();

  /**
   * Destrutor da classe Servidor.
   */
  ~Servidor();

  /**
   * Construtor da classe Servidor com parâmetros.
   * @param idDono O ID do dono do servidor.
   * @param nome O nome do servidor.
   * @param descricao A descrição do servidor.
   */
  Servidor(int idDono, std::string nome, std::string descricao);

  std::vector<int>
      participantesID;         // Vetor de IDs dos participantes do servidor.
  std::vector<Canal *> canais; // Vetor de ponteiros para os canais do servidor.

  /**
   * Define o nome do servidor.
   * @param nome O nome do servidor.
   */
  void setNome(std::string nome);

  /**
   * Define a descrição do servidor.
   * @param descricao A descrição do servidor.
   */
  void setDescricao(std::string descricao);

  /**
   * Define o código de convite do servidor.
   * @param codigo O código de convite do servidor.
   */
  void setCodigo(std::string codigo);

  /**
   * Obtém o ID do dono do servidor.
   * @return O ID do dono do servidor.
   */
  int getDono();

  /**
   * Obtém o nome do servidor.
   * @return O nome do servidor.
   */
  std::string getNome();

  /**
   * Obtém a descrição do servidor.
   * @return A descrição do servidor.
   */
  std::string getDesc();

  /**
   * Obtém o código de convite do servidor.
   * @return O código de convite do servidor.
   */
  std::string getCodigo();

  /**
   * Obtém os IDs dos participantes do servidor.
   * @return Um vetor contendo os IDs dos participantes.
   */
  std::vector<int> getParticipantesId();

  std::vector<Canal *> getCanais();
};

#endif // !SERVIDOR_H
