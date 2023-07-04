#ifndef CANAL_H
#define CANAL_H

#include <iostream>

class Canal {
private:
  std::string nome;

public:
  Canal();
  virtual ~Canal();
  Canal(std::string nome);

  void setNome(std::string nome);

  std::string getNome();

  bool operator==(const Canal &other) const;
};

#endif // !CANAL_H
