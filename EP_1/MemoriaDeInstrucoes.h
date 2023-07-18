#ifndef MEMORIADEINSTRUCOES_H
#define MEMORIADEINSTRUCOES_H
#include "Instrucao.h"

class MemoriaDeInstrucoes {
    private:
        int tamanho;
        Instrucao** instrucao;
    public:
        MemoriaDeInstrucoes(int tamanho);
        virtual ~MemoriaDeInstrucoes();
        int getTamanho();
        Instrucao* ler(int posicao);
        bool escrever(int posicao, Instrucao* d); 
};

#endif