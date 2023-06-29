#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <iostream>
#include <vector>

#include "canal.h"
#include "mensagem.h"

class Canal_Texto : public Canal {
public:
  std::vector<Mensagem> texto;

  Canal_Texto();
  ~Canal_Texto();
};

#endif