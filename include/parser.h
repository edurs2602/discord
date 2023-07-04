#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>

/**
 * Classe responsável por realizar o parsing de comandos.
 */

class Parser {
private:
  std::string comando;           // O comando extraído da entrada.
  std::vector<std::string> args; // Os argumentos extraídos da entrada.
  std::string argsEspace; // Os argumentos concatenados separados por espaço.

public:
  /**
   * Realiza o parsing da entrada fornecida.
   * @param entrada A entrada a ser parseada.
   * @return True se o parsing foi bem-sucedido, False caso contrário.
   */
  bool parse(std::string entrada);

  /**
   * Imprime as informações do parser.
   */
  void print();

  /**
   * Obtém o comando extraído da entrada.
   * @return O comando extraído.
   */
  std::string getComando();

  /**
   * Obtém o argumento na posição especificada.
   * @param index O índice do argumento desejado.
   * @return O argumento na posição especificada.
   */
  std::string getArg(int index);

  /**
   * Obtém os argumentos concatenados separados por espaço.
   * @return Os argumentos concatenados separados por espaço.
   */
  std::string getArgsEspace();

  /**
   * Obtém a quantidade de argumentos para um determinado comando.
   * @param comando O comando desejado.
   * @return A quantidade de argumentos necessários para o comando.
   */
  int qtdArgs(std::string comando);
};

#endif // !PARSER_H
