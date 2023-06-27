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
  std::vector<Canal *> canais;
  std::vector<int> participantesID;

public:
  Servidor();
  ~Servidor();
  Servidor(int idDono, std::string nome, std::string descricao);

  void setNome(std::string nome);
  void setDescricao(std::string descricao);
  void setCodigo(std::string codigo);

  int getDono();
  std::string getNome();
  std::string getDesc();
  std::string getCodigo();
};

#endif // !SERVIDOR_H
