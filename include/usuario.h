#include <iostream>
#include <string>

#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
  private:
    int id;
    std::string nome;
    std::string email;
    std::string senha;

  public:
    Usuario();
    ~Usuario();
    Usuario(int id, std::string nome, std::string email, std::string senha);

    void setId(int id);
    void setNome(std::string nome);
    void setEmail(std::string email);
    void setSenha(std::string senha);

    int getId();
    std::string getNome();
    std::string getEmail();

};

#endif // !USUARIO_H

