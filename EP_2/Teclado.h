#ifndef TECLADO 
#define TECLADO

#include"Dado.h"
#include "Dispositivo.h"

class Teclado : public Dispositivo{
public:
    Teclado();
    virtual ~Teclado();

    //metodos redefinidos
    Dado* ler();
    void escrever(Dado* d); 
};
#endif