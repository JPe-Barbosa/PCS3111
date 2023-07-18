#ifndef EPISODIO_H
#define EPISODIO_H
#include "Item.h"
#include <string>

using namespace std;

class Episodio : public Item{
    public:
    Episodio(string nome,int duracao);
    void imprimir();
};

#endif  // EPISODIO_H