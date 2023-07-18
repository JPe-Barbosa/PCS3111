#ifndef MONDCHAR
#define MONDCHAR

#include "Monitor.h"

class MonitorDeChar : public Monitor{
    public:
    MonitorDeChar();
    virtual ~MonitorDeChar(); 

    //metodo redefinido
    virtual void escrever(Dado* d); 
};

#endif