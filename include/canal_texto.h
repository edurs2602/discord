#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <iostream>
#include <vector>

#include "canal.h"
#include "mensagem.h"

/*
 * Classe Canal Texto que herda de Canal
 * com um vetor de Mensagem chamado texto
 * e uma função construtora e destrutura
 */
class Canal_Texto : public Canal {
private:
  std::vector<Mensagem> mensagens;

public:
  std::vector<Mensagem> texto;

  Canal_Texto();
  ~Canal_Texto();
  Canal_Texto(std::string nome);

  void adicionarMensagem(const Mensagem &mensagem);
};

#endif
