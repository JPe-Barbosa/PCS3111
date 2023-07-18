#ifndef TECLADODC
#define TECLADODC

#include"Dado.h"
#include "Teclado.h"

class TecladoDeChar : public Teclado{
public:
    TecladoDeChar();
    virtual ~TecladoDeChar();

    //metodo redefinidos
    virtual Dado* ler();
};
#endif