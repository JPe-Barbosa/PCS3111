#ifndef FILME_H
#define FILME_H

#include <string>

using namespace std;

class Filme {
private:
    string nome;
    int duracao;

public:
    Filme(string nome, int duracao);
    ~Filme();
    
    string getNome();
    int getDuracao();

    void imprimir();
};

#endif  // FILME_H
