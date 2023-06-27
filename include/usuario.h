#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario {
private:
  int id;
  std::string nome;
  std::string email;
  std::string senha;

public:
  Usuario();
  ~Usuario();
  Usuario(std::string email, std::string senha, std::string nome);

  void setId(int id);
  void setNome(std::string nome);
  void setEmail(std::string email);
  void setSenha(std::string senha);

  int getId() const;
  std::string getNome() const;
  std::string getEmail() const;
  std::string getSenha() const;

  bool operator==(const Usuario &usuario) const;
};

#endif // !USUARIO_H
