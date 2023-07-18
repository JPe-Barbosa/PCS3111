#include "Instrucao.h"
#include <iostream>
using namespace std;

int Instrucao::getOpcode(){
    return getValor();  
}

int Instrucao::getOrigem1(){
    return origem1;
}  

int Instrucao::getOrigem2(){
    return origem2;
}  

int Instrucao::getDestino(){
    return destino;
}  

int Instrucao::getImediato(){
    return imediato;
}  

int Instrucao::getFuncao(){
    return funcao;
}  

Instrucao* Instrucao::criarLW(int destino, int imediato){
    return new Instrucao(LW,0,0,destino,imediato,0);
}
Instrucao* Instrucao::criarSW(int destino, int imediato){
    return new Instrucao(SW,0,0,destino,imediato,0);
}
Instrucao* Instrucao::criarJ(int imediato){
    return new Instrucao(J,0,0,0,imediato,0);
}
Instrucao* Instrucao::criarBNE(int origem1, int origem2, int imediato){
    return new Instrucao(BNE,origem1,origem2,0,imediato,0);
}
Instrucao* Instrucao::criarBEQ(int origem1, int origem2, int imediato){
    return new Instrucao(BEQ,origem1,origem2,0,imediato,0);
}
Instrucao* Instrucao::criarADD(int destino, int origem1, int origem2){
    return new Instrucao(0,origem1,origem2,destino,0,FUNCAO_ADD);
}
Instrucao* Instrucao::criarSUB(int destino, int origem1, int origem2){
    return new Instrucao(0,origem1,origem2,destino,0,FUNCAO_SUB);
}
Instrucao* Instrucao::criarMULT(int origem1, int origem2){
    return new Instrucao(0,origem1,origem2,0,0,FUNCAO_MULT);
}
Instrucao* Instrucao::criarDIV(int origem1, int origem2){
    return new Instrucao(0,origem1,origem2,0,0,FUNCAO_DIV);
}

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao):Dado(opcode){
    this->origem1 = origem1;
    this->origem2 = origem2;
    this->destino = destino;
    this->imediato = imediato;
    this->funcao = funcao;
}

void Instrucao::imprimir(){
    cout << "Instrucao " << getOpcode();
}

Instrucao::~Instrucao(){}