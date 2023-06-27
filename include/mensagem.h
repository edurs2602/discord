#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>
#include "usuario.h"

class Mensagem{
  private:
    int enviadaPor;
    std::string dataHora;
    std::string conteudo;

  public:
    Mensagem();
    ~Mensagem();
    Mensagem(int enviadaPor, std::string dataHora, std::string conteudo);

    void setEnviadoPor(int id);
    void setDataHora(std::string dataHora);
    void setConteudo(std::string conteudo);

    id getEnviadoPor();
    std::string getDataHora();
    std::string getConteudo();

    bool operator==(Mensagem& mensagem);
};

#endif // !MENSAGEM_H
