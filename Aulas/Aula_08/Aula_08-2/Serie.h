#ifndef SERIE_H
#define SERIE_H

#include"Item.h"
#include"Episodio.h"

class Serie: public Item{
private:
    Episodio** episodios;
    int quantidade;
    int quantidadeMaxima;
public:
    Serie(string nome, int quantidadeMaxima);
    virtual ~Serie();

    bool adicionar(Episodio* ep);
    Episodio** getEpisodios();
    int getQuantidadeEpisodios();
    void imprimir();
};

#endif  // SERIE_H