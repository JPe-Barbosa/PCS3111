#ifndef MEMRAM
#define MEMRAM

#include <list>
#include"Dado.h"
#include"Memoria.h"
using namespace std;

class MemoriaRAM : public Memoria{
    public:
    MemoriaRAM(int tamanho);
    virtual ~MemoriaRAM();
    virtual void escrever(list<Dado*>* dados); 
    int getTamanho();// redefini o metodo
    Dado* ler(int posicao);// redefini
    void escrever(int posicao, Dado* d); // redefini
    virtual void imprimir(); // redefini

    private:
    Dado** dados;
    int tamanho;

};

#endif