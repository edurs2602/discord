#ifndef CANAL_H
#define CANAL_H

#include <iostream>
#include <vector>

/*
 * Classe Canal
 * com um atributo privado chamado de nome do tipo string
 * com funções construtura e destrutora
 * função que seta o nome do Canal
 * outra função que retorna o nome do canal
 * e uma sobrecarga de operador
 */

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
