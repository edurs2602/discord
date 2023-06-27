#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <vector>

#include "../include/constantes.h"
#include "../include/parser.h"

int Parser::qtdArgs(std::string comando) {
  for (auto dict : cte::commands_simple_args) {
    if (dict.first == comando)
      return dict.second;
  }
}

bool Parser::parse(std::string entrada) {
  if (entrada.empty()) {
    std::cout << "Comando Inválido" << std::endl;
    return false;
  }

  std::string chave;
  std::vector<std::string> token;
  std::stringstream ss(entrada);
  int argsComando = -1;
  args.clear();
  argsEspace.clear();

  while (getline(ss, chave, ' '))
    token.push_back(chave);

  comando = token.at(0);
  argsComando = qtdArgs(comando);

  if (token.size() - 1 < argsComando)
    std::cout << "É necessario mais argumentos" << std::endl;

  int i = 1;

  while (i < token.size() && i <= argsComando) {
    args.push_back(token.at(i));
    ++i;
  }

  chave.clear();

  i = argsComando + 1;
  if (i < token.size()) {
    chave += token.at(1);
  }

  i++;

  while (i < token.size()) {
    chave += (" " + token.at(1));
    i++;
  }

  argsEspace = chave;

  return true;
};

std::string Parser::getComando() { return comando; }

std::string Parser::getArgsEspace() { return argsEspace; }

std::string Parser::getArg(int index) {
  if (index >= args.size())
    std::cout << "posição do argumento inválida." << std::endl;

  return args[index];
}
