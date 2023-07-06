# Caminho para o Concordo
EXECUTABLE="build/Concordo"

# Opções do Valgrind
VALGRIND_OPTIONS="--leak-check=full --show-leak-kinds=all"

# Comando para executar o Valgrind no seu programa
valgrind $VALGRIND_OPTIONS ./$EXECUTABLE

