#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include "canal.h"
#include "mensagem.h"

class Canal_Voz : public Canal {
private:
  Mensagem ultima;

public:
  Canal_Voz();
  ~Canal_Voz();

  void setUltima(Mensagem x);

  std::string getUltima();
};

#endif