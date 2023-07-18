#ifndef MONITOR
#define MONITOR

#include "Dispositivo.h"

class Monitor : public Dispositivo{
    public:
    Monitor();
    virtual ~Monitor(); 

    //metodos redefinidos
    Dado* ler();
    void escrever(Dado* d); 
};

#endif