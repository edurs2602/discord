#include <iostream>
#include <string>

#include "../include/canal.h"

Canal::Canal() {}

Canal::~Canal() {}

Canal::Canal(std::string nome) { this->nome = nome; }

void Canal::setNome(std::string nome) { this->nome = nome; }

std::string Canal::getNome() { return this->nome; }

bool Canal::operator==(const Canal &other) const { return nome == other.nome; }