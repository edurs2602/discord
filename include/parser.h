#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>

class Parser{
  private:
    std::string comando;
    std::vector<std::string> args;
    std::string argsEspace;

  public:
    bool parse(std::string entrada);
    void print();
    std::string getComando();
    std::string getArg(int index);
    std::string getArgsEspace();
    int qtdArgs(std::string comando);

};

#endif // !PARSER_H



