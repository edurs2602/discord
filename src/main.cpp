#include <iostream>

#include "../include/constantes.h"
#include "../include/parser.h"
#include "../include/servidor.h"
#include "../include/sistema.h"
#include "../include/usuario.h"

/**
 * Função principal que inicia o programa.
 * @param argc O número de argumentos de linha de comando.
 * @param argv Os argumentos de linha de comando.
 * @return O código de saída do programa.
 */
int main(int argc, char *argv[]) {
  Sistema *sistema = new Sistema();

  sistema->iniciar();

  delete sistema;

  return 0;
}
