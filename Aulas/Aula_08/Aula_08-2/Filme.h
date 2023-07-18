#ifndef FILME_H
#define FILME_H
#include "Item.h"
#include <string>

using namespace std;

class Filme : public Item {
public:
    Filme(string nome, int duracao);
    ~Filme();

    void imprimir();
};

#endif  // FILME_H