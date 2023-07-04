#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "usuario.h"
#include <iostream>

/**
 * Classe que representa uma mensagem.
 */

class Mensagem {
private:
  int enviadaPor;       // ID do usuário que enviou a mensagem.
  std::string dataHora; // Data e hora em que a mensagem foi enviada.
  std::string conteudo; // Conteúdo da mensagem.

public:
  /**
   * Construtor padrão da classe Mensagem.
   */
  Mensagem();

  /**
   * Destrutor da classe Mensagem.
   */
  ~Mensagem();

  /**
   * Construtor da classe Mensagem com parâmetros.
   * @param dataHora A data e hora da mensagem.
   * @param enviadaPor O ID do usuário que enviou a mensagem.
   * @param conteudo O conteúdo da mensagem.
   */
  Mensagem(std::string dataHora, int enviadaPor, std::string conteudo);

  /**
   * Define o ID do usuário que enviou a mensagem.
   * @param id O ID do usuário.
   */
  void setEnviadoPor(int id);

  /**
   * Define a data e hora da mensagem.
   * @param dataHora A data e hora da mensagem.
   */
  void setDataHora(std::string dataHora);

  /**
   * Define o conteúdo da mensagem.
   * @param conteudo O conteúdo da mensagem.
   */
  void setConteudo(std::string conteudo);

  /**
   * Obtém o ID do usuário que enviou a mensagem.
   * @return O ID do usuário.
   */
  int getEnviadoPor() const;

  /**
   * Obtém a data e hora da mensagem.
   * @return A data e hora da mensagem.
   */
  std::string getDataHora() const;

  /**
   * Obtém o conteúdo da mensagem.
   * @return O conteúdo da mensagem.
   */
  std::string getConteudo() const;

  /**
   * Sobrecarga do operador de igualdade.
   * Verifica se duas mensagens são iguais.
   * @param mensagem A mensagem a ser comparada.
   * @return True se as mensagens são iguais, False caso contrário.
   */
  bool operator==(Mensagem &mensagem);
};

#endif // !MENSAGEM_H
