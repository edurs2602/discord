#include "canal.h"
#include <iostream>
#include <string>
#include <vector>

#ifndef SERVIDOR_H
#define SERVIDOR_H

class Servidor {
private:
  int idDono;
  std::string nome;
  std::string descricao;
  std::string codigoConvite;

public:
  Servidor();
  ~Servidor();
  Servidor(int idDono, std::string nome, std::string descricao);

  std::vector<int> participantesID;
  std::vector<Canal *> canais;

  void setNome(std::string nome);
  void setDescricao(std::string descricao);
  void setCodigo(std::string codigo);

  int getDono();
  std::string getNome();
  std::string getDesc();
  std::string getCodigo();
  std::vector<int> getParticipantesId();
};

#endif // !SERVIDOR_H
