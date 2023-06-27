#ifndef CANAL_H
#define CANAL_H

#include <iostream>

class Canal{
  private:
    std::string nome;

  public:
    Canal();
    ~Canal();
    Canal(std::string nome);

    void setNome(std::string nome);

    std::string getNome();

    bool operator==(Canal& canal);
};

#endif // !CANAL_H
