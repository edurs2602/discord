#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include "canal.h"
#include "mensagem.h"

/*
 * Classe Canal Voz que herda de Canal
 * com um atributo privado de Mensagem chamado ultima
 * uma função construtora e destrutura
 * uma função que seta a ultima mensagem
 * e outra que retorna a ultima mensagem
 */

class Canal_Voz : public Canal {
private:
  Mensagem ultima;

public:
  Canal_Voz();
  ~Canal_Voz();
  Canal_Voz(std::string nome);

  void setUltima(Mensagem x);

  std::string getUltima();
};

#endif