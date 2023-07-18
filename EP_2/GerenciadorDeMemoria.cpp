#include "GerenciadorDeMemoria.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include "Instrucao.h"
using namespace std;

GerenciadorDeMemoria::GerenciadorDeMemoria(){}
GerenciadorDeMemoria::~GerenciadorDeMemoria(){}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m){
    ifstream input;
    input.open(arquivo);
    
    if(input.fail()) throw new runtime_error("mensagem de erro");
    int tamanho;
    input >> tamanho;
    if(tamanho > m->getTamanho()) throw new runtime_error("mensagem de erro");

    list<Dado*>* dados = new list<Dado*>();
    Instrucao* inst;
    while(!input.eof()){
        string a;
        input >> a;
        if(a == "D"){ 
            int j;
            input >> j;
            dados->push_back(new Dado(j));
        }
        else if(a == "ADD" || a == "SUB"){
            int x, y, z;
            input >> x >> y >> z;
            if(a == "ADD") dados->push_back(inst->criarADD(x, y, z));
            else dados->push_back(inst->criarSUB(x,y,z));
        }
        else if(a == "MULT" || a == "DIV"){
            int x,y;
            input >> x >> y;
            if(a == "MULT") dados->push_back(inst->criarMULT(x,y));
            else dados->push_back(inst->criarDIV(x,y));
        }
        else if(a == "BNE" || a == "BEQ"){
            int x,y,z;
            input >> x >> y >> z;
            if(a == "BNE") dados->push_back(inst->criarBNE(x,y,z));
            else dados->push_back(inst->criarBEQ(x,y,z));
        }
        else if(a == "J"){
            int x;
            input >> x;
            dados->push_back(inst->criarJ(x));

        }
        else if(a == "LW" || a == "SW"){
            int x,y;
            input >> x >> y;
            if(a == "LW") dados->push_back(inst->criarLW(x,y));
            else dados->push_back(inst->criarSW(x,y));
        }
        else continue;
    }
    input.close();
    m->escrever(dados);
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m){
    ofstream output;
    output.open(arquivo);
    if(output.fail()) throw new runtime_error("mensagem de erro");

    output << m->getTamanho() << endl;
    int j = 0;
    while(j < m->getTamanho()){
        if(m->ler(j) != NULL){
            output << "D " << m->ler(j) << endl;
            j++;
        }
        else{
            output << "-" << endl;
            j++;
        }
    }
    output.close();
}