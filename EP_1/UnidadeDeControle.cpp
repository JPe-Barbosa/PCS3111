#include "UnidadeDeControle.h"
#include <iostream>

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados){
    this->pc = 0;
    this->registradores = registradores;
    this->instrucoes = instrucoes;
    this->dados = dados;
}

UnidadeDeControle::~UnidadeDeControle(){
    delete this->registradores;
    delete this->instrucoes;
    delete this->dados;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
    return registradores;
}

MemoriaDeDados* UnidadeDeControle::getMemoriaDeDados(){
    return dados;
}

MemoriaDeInstrucoes* UnidadeDeControle::getMemoriaDeInstrucoes(){
    return instrucoes;
}

int UnidadeDeControle::getPC(){
    return this->pc;
}

void UnidadeDeControle::setPC(int pc){
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao(){
    if(getMemoriaDeInstrucoes()->ler(this->pc) == NULL){
        this->pc++;
        return;
    }   

    if(getMemoriaDeInstrucoes()->ler(this->pc)->getOpcode() == TIPO_R){
        if(getMemoriaDeInstrucoes()->ler(this->pc)->getFuncao() == FUNCAO_ADD){
            getBancoDeRegistradores()->setValor(getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino()), getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1()) + getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2()));
        }

        if(getMemoriaDeInstrucoes()->ler(this->pc)->getFuncao() == FUNCAO_SUB){
            getBancoDeRegistradores()->setValor(getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino()), getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1()) - getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2()));
        }

        if(getMemoriaDeInstrucoes()->ler(this->pc)->getFuncao() == FUNCAO_MULT){
            getBancoDeRegistradores()->setValor(24,getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1())  * getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2()));
        }

        if(getMemoriaDeInstrucoes()->ler(this->pc)->getFuncao() == FUNCAO_DIV){
            getBancoDeRegistradores()->setValor(24, getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1()) / getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2()));
            getBancoDeRegistradores()->setValor(25, getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1()) % getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2()));
        }
        this->pc++;
        return;
    }
    if(getMemoriaDeInstrucoes()->ler(this->pc)->getOpcode() == J){
        setPC(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato());
        return;
    }

    if(getMemoriaDeInstrucoes()->ler(this->pc)->getOpcode() == BNE){  
        if(getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1()) != getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2())){
            setPC(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato());
        }else{
            this->pc++;
        } 
        return;
    }

    if(getMemoriaDeInstrucoes()->ler(this->pc)->getOpcode() == BEQ){
        if(getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1()) == getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2())){
            setPC(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato());
        }else{
            this->pc++;
        }
        return;
    }

    if(getMemoriaDeInstrucoes()->ler(this->pc)->getOpcode() == LW){
        if (getMemoriaDeDados()->ler(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato()) == NULL){
            getBancoDeRegistradores()->setValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino(), 0);
        }
        else{
            getBancoDeRegistradores()->setValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino(), getMemoriaDeDados()->ler(this->pc)->getValor());
        }
        this->pc++;
        return;
    }

    if(getMemoriaDeInstrucoes()->ler(this->pc)->getOpcode() == SW){
        getMemoriaDeDados()->escrever(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato(),new Dado(getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino())));
        this->pc++;
        return;
    }
}