#include <iostream>
#include <string>
#include "../include/usuario.h"

int generateId(){
  static int s_id{ 0 };
  return s_id;
  
  s_id++;
};

Usuario::Usuario(){};

Usuario::~Usuario(){};

Usuario::Usuario(int id, std::string nome, std::string email, std::string senha){
  this->id = id;
  this->nome = nome;
  this->email = email;
  this->senha = senha;
};

void Usuario::setId(int id){
  this->id = generateId();
};

void Usuario::setNome(std::string nome){
  this->nome = nome; 
};

void Usuario::setEmail(std::string email){
  this->email = email;
};

void Usuario::setSenha(std::string senha){
  this->senha = senha;
};


