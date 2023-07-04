#include <iostream>
#include <string>

#include "../include/canal.h"

/**
 * Construtor padrão da classe Canal.
 */
Canal::Canal() {}

/**
 * Destrutor da classe Canal.
 */
Canal::~Canal() {}

/**
 * Construtor da classe Canal que recebe o nome do canal.
 * @param nome O nome do canal.
 */
Canal::Canal(std::string nome) { this->nome = nome; }

/**
 * Define o nome do canal.
 * @param nome O nome do canal.
 */
void Canal::setNome(std::string nome) { this->nome = nome; }

/**
 * Obtém o nome do canal.
 * @return O nome do canal.
 */
std::string Canal::getNome() { return this->nome; }

/**
 * Sobrecarga do operador de igualdade para comparar dois objetos Canal.
 * @param other O objeto Canal a ser comparado.
 * @return True se os objetos têm o mesmo nome, False caso contrário.
 */
bool Canal::operator==(const Canal &other) const { return nome == other.nome; }
