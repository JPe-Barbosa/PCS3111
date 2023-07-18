#ifndef GEREDEMEMORIA
#define GEREDEMEMORIA
#include "MemoriaRAM.h"
#include <iostream>

class GerenciadorDeMemoria{
    public:
        GerenciadorDeMemoria();
        virtual ~GerenciadorDeMemoria();
        virtual void load(string arquivo, MemoriaRAM* m);
        virtual void dump(string arquivo, MemoriaRAM* m);
};

#endif