cmake_minimum_required(VERSION 3.25.1)
project(Concordo VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( Concordo
                src/canal.cpp
                src/main.cpp
                src/mensagem.cpp
                src/parser.cpp
                src/servidor.cpp
                src/sistema.cpp
                src/usuario.cpp
                src/canal_texto.cpp
                src/canal_voz.cpp
              )