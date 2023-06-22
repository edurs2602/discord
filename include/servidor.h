#include <iostream>
#include <vector>
#include <string>
#include "canal.h"

#ifndef SERVIDOR_H
#define SERVIDOR_H


class Servidor{
  private:
    int idDono;
    std::string nome;
    std::string descricao;
    std::string codigoConvite;
    std::vector<Canal*> canais;
    std::vector<int> participantesID;

  public:
    Servidor();
    ~Servidor();
    Servidor(int idDono, std::string nome, std::string descricao);

    void setNome(std::string nome);
    void setDescricao(std::string descricao);

};


#endif // !SERVIDOR_H
