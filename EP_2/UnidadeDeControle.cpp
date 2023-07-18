#include "UnidadeDeControle.h"
#include"Instrucao.h"
#include <iostream>

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria){
    this->pc = 0;
    this->registradores = registradores;
    this->memoria = memoria;
}

UnidadeDeControle::~UnidadeDeControle(){
    delete this->registradores;
    delete this->memoria;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
    return registradores;
}

Memoria* UnidadeDeControle::getMemoria(){
    return memoria;
}

int UnidadeDeControle::getPC(){
    return this->pc;
}

void UnidadeDeControle::setPC(int pc){
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao(){
    Instrucao *instrucao = dynamic_cast<Instrucao*>(getMemoria()->ler(this->pc)); // não tenho certeza mas não pensei em outra forma, malsss
    if(instrucao == NULL){
        this->pc++;
        return;
    }   


    if(instrucao->getOpcode() == 0){
        if(instrucao->getFuncao() == 32){ //ADD
            //registra(dores[instrucoes[pc]->ler(pc)->getDestino()]->setValor(instrucoes[pc]->ler(pc)->getDestino(), registradores[instrucoes[pc]->ler(pc)->getOrigem1()]->getValor(instrucoes[pc]->ler(pc)->getOrigem1()) + registradores[instrucoes[pc]->ler(pc)->getOrigem2()]->getValor(instrucoes[pc]->ler(pc)->getOrigem2()));
            registradores->setValor(instrucao->getDestino(),registradores->getValor(instrucao->getOrigem1()) + registradores->getValor(instrucao->getOrigem2()));
        }

        if(instrucao->getFuncao() == 34){ //SUB
            registradores->setValor(instrucao->getDestino(),registradores->getValor(instrucao->getOrigem1()) - registradores->getValor(instrucao->getOrigem2()));
        }

        if(instrucao->getFuncao() == FUNCAO_MULT){ //MULT
            //getBancoDeRegistradores()->setValor(24, getMemoriaDeInstrucoes()->ler(pc)->getOrigem1() * getMemoriaDeInstrucoes()->ler(pc)->getOrigem2());
            registradores->setValor(24,registradores->getValor(instrucao->getOrigem1()) * registradores->getValor(instrucao->getOrigem2()));
        }

        if(instrucao->getFuncao() == 26){ //DIV
            //getBancoDeRegistradores()->setValor(24, getMemoriaDeInstrucoes()->ler(pc)->getOrigem1() / getMemoriaDeInstrucoes()->ler(pc)->getOrigem2());
            //getBancoDeRegistradores()->setValor(25, getMemoriaDeInstrucoes()->ler(pc)->getOrigem1() % getMemoriaDeInstrucoes()->ler(pc)->getOrigem2());
            registradores->setValor(24,registradores->getValor(instrucao->getOrigem1()) / registradores->getValor(instrucao->getOrigem2()));
            registradores->setValor(25,registradores->getValor(instrucao->getOrigem1()) % registradores->getValor(instrucao->getOrigem2()));            
        }
    }

      if(instrucao->getOpcode() == J){
        //setPC(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato());
        setPC(instrucao->getImediato());
        return;
    }

    // daqui para frente é tudo freestyle. necessário revisão

    if(instrucao->getOpcode() == BNE){  
        //if(getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem1()) != getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getOrigem2())){
        //não sei como implementar estou usando consteudo da memoria na origem 1 em vez do conteudo do regeistrador na origem 1
        if(registradores->getValor(instrucao->getOrigem1()) != registradores->getValor(instrucao->getOrigem2())){
            setPC(instrucao->getImediato());
        }else{
            this->pc++;
        } 
        return;
    }

    if(instrucao->getOpcode() == BEQ){
        //mesmo do que no bne
        if(registradores->getValor(instrucao->getOrigem1()) == registradores->getValor(instrucao->getOrigem2())){
            setPC(instrucao->getImediato());
        }else{
            this->pc++;
        }
        return;
    }

    if(instrucao->getOpcode() == LW){
        //if (getMemoriaDeDados()->ler(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato()) == NULL){
        Dado *d = getMemoria()->ler(instrucao->getImediato());
        if(d == NULL){
            //getBancoDeRegistradores()->setValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino(), 0);
            registradores->setValor(instrucao->getDestino(),0);
        }
        else{
            //getBancoDeRegistradores()->setValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino(), getMemoriaDeDados()->ler(this->pc)->getValor());
            registradores->setValor(instrucao->getDestino(),d->getValor());

        }
        this->pc++;
        return;
    }

    if(instrucao->getOpcode() == SW){
        //getMemoriaDeDados()->escrever(getMemoriaDeInstrucoes()->ler(this->pc)->getImediato(),new Dado(getBancoDeRegistradores()->getValor(getMemoriaDeInstrucoes()->ler(this->pc)->getDestino())));
        getMemoria()->escrever(instrucao->getImediato(), new Dado(registradores->getValor(instrucao->getDestino())));
        this->pc++;
        return;
    }
    
    this->pc++;
}