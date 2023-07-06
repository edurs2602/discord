#include "../include/canal_texto.h"

/**
 * Construtor padrão da classe Canal_Texto.
 */
Canal_Texto::Canal_Texto() {}

/**
 * Destrutor da classe Canal_Texto.
 */
Canal_Texto::~Canal_Texto() {}

Canal_Texto::Canal_Texto(std::string nome) : Canal(nome) {}

void Canal_Texto::adicionarMensagem(const Mensagem &mensagem) {
  mensagens.push_back(mensagem);
}