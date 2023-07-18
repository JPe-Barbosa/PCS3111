#ifndef UNIDADEDECONTROLE_H
#define UNIDADEDECONTROLE_H
#define TIPO_R 0
#define FUNCAO_ADD 32
#define FUNCAO_SUB 34
#define FUNCAO_MULT 24
#define FUNCAO_DIV 26
#define J 2
#define BNE 5
#define BEQ 4
#define LW 35
#define SW 43
#include "BancoDeRegistradores.h"
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"

class UnidadeDeControle{
    private:
        int pc;
        BancoDeRegistradores* registradores;
        MemoriaDeInstrucoes* instrucoes;
        MemoriaDeDados* dados;
    public:
        UnidadeDeControle(BancoDeRegistradores* registradores, MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados);
        virtual ~UnidadeDeControle();
        BancoDeRegistradores* getBancoDeRegistradores();
        MemoriaDeDados* getMemoriaDeDados();
        MemoriaDeInstrucoes* getMemoriaDeInstrucoes();
        int getPC();
        void setPC(int pc);
        void executarInstrucao(); 
};

#endif