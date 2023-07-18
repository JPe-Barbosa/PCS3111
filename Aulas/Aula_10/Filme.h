#ifndef FILME_H
#define FILME_H

#include <string>

using namespace std;

class Filme {
private:
    string nome;
    int duracao;
    int visualizacoes;

public:
    Filme(string nome, int duracao);
    Filme(string nome, int duracao, int visualizacoes);
    ~Filme();

    string getNome();
    int getDuracao();
    int getVisualizacoes();

    void assistir(int tempo);

    void imprimir();
};

#endif  // FILME_H