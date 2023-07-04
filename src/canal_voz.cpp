#include "../include/canal_voz.h"
#include <vector>

/**
 * Construtor padrão da classe Canal_Voz.
 */
Canal_Voz::Canal_Voz() {}

/**
 * Destrutor da classe Canal_Voz.
 */
Canal_Voz::~Canal_Voz() {}

/**
 * Define a última mensagem enviada no canal de voz.
 * @param x A última mensagem enviada.
 */
void Canal_Voz::setUltima(Mensagem x) { ultima = x; }

/**
 * Obtém o conteúdo da última mensagem enviada no canal de voz.
 * @return O conteúdo da última mensagem.
 */
std::string Canal_Voz::getUltima() { return ultima.getConteudo(); }
