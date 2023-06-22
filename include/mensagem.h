#include <iostream>
#include <string>
#include "usuario.h"

#ifndef MENSAGEM_H
#define MENSAGEM_H


class Mensagem{
  private:
    int enviadaPor;
    std::string dataHora;
    std::string conteudo;

  public:
    Mensagem();
    ~Mensagem();
    Mensagem(int enviadaPor, std::string dataHora, std::string conteudo);

    void setEnviadoPor(int enviadaPor);
    void setDataHora(std::string dataHora);
    void setConteudo(std::string conteudo);

    id getEnviadoPor();
    std::string getDataHora();
    std::string getConteudo();

};

#endif // !MENSAGEM_H
