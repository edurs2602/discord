#include <iostream>
#include <string>

#ifndef CANAL_H
#define CANAL_H


class Canal{
  private:
    std::string nome;

  public:
    Canal();
    ~Canal();
    Canal(std::string nome);

    void setNome(std::string nome);

    std::string getNome();
};

#endif // !CANAL_H
