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
    virtual ~Filme();

    string getNome() const;
    int getDuracao() const;

    void imprimir() const;
};

#endif  // FILME_H
