#ifndef ESMNM
#define ESMNM

#include <vector>
#include "Memoria.h"
#include "MemoriaRAM.h"
#include "Dispositivo.h"

using namespace std;

class ESMapeadaNaMemoria : public Memoria{
    public:
    ESMapeadaNaMemoria(MemoriaRAM* m);
    ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos);
    virtual ~ESMapeadaNaMemoria();
    
    virtual MemoriaRAM* getMemoriaSubjacente();
    virtual void adicionar(Dispositivo* d);
    virtual vector<Dispositivo*>* getDispositivos();

    //metodos redefinidos
    int getTamanho();
    Dado* ler(int posicao);
    void escrever(int posicao, Dado* d);
    void imprimir();
    
    private:
    MemoriaRAM* memram;
    vector<Dispositivo*>* dispositivos;
};

#endif