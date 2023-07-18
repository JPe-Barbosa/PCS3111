#ifndef PLANO_H
#define PLANO_H

#include <list>
#include "Catalogo.h"

class Plano {
public:

    Plano(string tipo);
    virtual ~Plano();

    void adicionar(Catalogo* c);
    list<Catalogo*>* getCatalogos();

    void imprimir();

private:
    string tipo;
    list<Catalogo*>* catalogos;
    
};

#endif // PLANO_H
