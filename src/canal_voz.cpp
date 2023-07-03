#include "../include/canal_voz.h"
#include <vector>

Canal_Voz::Canal_Voz() {}

Canal_Voz::~Canal_Voz() {}

void Canal_Voz::setUltima(Mensagem x) { ultima = x; }

std::string Canal_Voz::getUltima() { return ultima.getConteudo(); }
