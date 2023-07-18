#ifndef SEMVISUALIZACOES
#define SEMVISUALIZACOES

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

class SemVisualizacoes : public logic_error{
public:
    SemVisualizacoes(string mensagem);
    ~SemVisualizacoes();
};

#endif