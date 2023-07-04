#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <vector>

#include "../include/constantes.h"
#include "../include/parser.h"

/**
 * Obtém a quantidade de argumentos necessários para um determinado comando.
 * @param comando O comando a ser verificado.
 * @return A quantidade de argumentos necessários para o comando.
 */
int Parser::qtdArgs(std::string comando) {
  for (auto dict : cte::commands_simple_args) {
    if (dict.first == comando)
      return dict.second;
  }

  return 0;
}

/**
 * Faz o parsing da entrada fornecida e armazena as informações relevantes.
 * @param entrada A entrada a ser analisada.
 * @return true se a análise for bem-sucedida, false caso contrário.
 */
bool Parser::parse(std::string entrada) {
  if (entrada.empty()) {
    std::cout << entrada << "Comando Inválido" << std::endl;
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
    std::cout << "É necessário mais argumentos" << std::endl;

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

/**
 * Obtém o comando extraído da análise da entrada.
 * @return O comando da entrada.
 */
std::string Parser::getComando() { return comando; }

/**
 * Obtém os argumentos concatenados por espaços.
 * @return Os argumentos concatenados por espaços.
 */
std::string Parser::getArgsEspace() { return argsEspace; }

/**
 * Obtém o argumento na posição especificada.
 * @param index O índice do argumento desejado.
 * @return O argumento na posição especificada.
 */
std::string Parser::getArg(int index) {
  if (index >= args.size())
    std::cout << "Posição do argumento inválida." << std::endl;

  return args[index];
}
