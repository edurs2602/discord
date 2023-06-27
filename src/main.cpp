#include <iostream>

#include "../include/constantes.h"
#include "../include/parser.h"
#include "../include/servidor.h"
#include "../include/sistema.h"
#include "../include/usuario.h"

int main(int argc, char *argv[]) {
  Sistema *sistema = new Sistema();

  sistema->iniciar();

  delete sistema;
}
