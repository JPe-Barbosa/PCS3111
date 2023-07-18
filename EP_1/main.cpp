#include <iostream>
#include <string>
using namespace std;

#include "Dado.h"
#include "Instrucao.h"
#include "BancoDeRegistradores.h"
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"
#include "UnidadeDeControle.h"

int main(){
    UnidadeDeControle *uniControle = new UnidadeDeControle(new BancoDeRegistradores(), new MemoriaDeInstrucoes(16), new MemoriaDeDados(16));
    int loop1 = 1,loop2, escolha1=1, escolha2, D1, D2; 
    
    uniControle->getMemoriaDeInstrucoes()->escrever(0,new Instrucao(35, 0, 0, 8, 0, 0));//LW 8, 0
    uniControle->getMemoriaDeInstrucoes()->escrever(1,new Instrucao(35, 0, 0, 9, 1, 0));//LW 9, 1
    uniControle->getMemoriaDeInstrucoes()->escrever(2,new Instrucao(35, 0, 0, 10, 2, 0));//LW 10, 2
    uniControle->getMemoriaDeInstrucoes()->escrever(3,new Instrucao(5, 9, 10, 0, 7, 0));//BNE 9, 10, 7 
    uniControle->getMemoriaDeInstrucoes()->escrever(4,new Instrucao(0, 8, 10, 0, 0, 24));//MULT 8, 10
    uniControle->getMemoriaDeInstrucoes()->escrever(5,new Instrucao(43, 0, 0, 24, 3, 0));//SW 24, 3
    uniControle->getMemoriaDeInstrucoes()->escrever(6,new Instrucao(2, 0, 0, 0, 0, 0));//J 0 
    uniControle->getMemoriaDeInstrucoes()->escrever(7,new Instrucao(0, 10, 8, 9, 0, 32));//ADD 9, 10, 8
    uniControle->getMemoriaDeInstrucoes()->escrever(8,new Instrucao(43, 0, 0, 9, 3, 0));//SW 9, 3
    uniControle->getMemoriaDeInstrucoes()->escrever(9,new Instrucao(2, 0, 0, 0, 10, 0));//J 10 

    while(loop1){
        cout << "Emulador de MIPS"<< endl;
        cout << "1) Memoria de Dados" << endl;
        cout << "2) Registradores" << endl;
        cout << "3) Executar proxima instrucao" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha1;
        cout << endl;
        if (escolha1 == 0){
            delete uniControle;
            loop1 = 0;
        } 
        if (escolha1 == 1){
            loop2 = 1;
            while(loop2){
                cout << "Memoria de Dados"<< endl;
                cout << "1) Alterar Valor" << endl;
                cout << "2) Imprimir" << endl;
                cout << "0) Voltar" << endl;
                cout << "Escolha uma opcao: ";
                cin >> escolha2;
                cout << endl;
                if(escolha2 == 0) loop2 = 0;
                if(escolha2 == 1){
                    cout << "Posicao a ser alterada: ";
                    cin >> D1;
                    cout << "Novo valor: ";
                    cin >> D2;
                    uniControle->getMemoriaDeDados()->escrever(D1,new Dado(D2));
                    cout << endl;
                }
                if(escolha2 == 2){
                    uniControle->getMemoriaDeDados()->imprimir();
                    cout << endl;
                }
            }
        }
        if(escolha1 == 2){
            loop2 = 1;
            while(loop2){
                cout << "Registradores"<< endl;
                cout << "1) Alterar Valor" << endl;
                cout << "2) Imprimir" << endl;
                cout << "0) Volta" << endl;
                cout << "Escolha uma opcao: ";
                cin >> escolha2;
                cout << endl;
                if(escolha2 == 0) loop2 = 0;
                if(escolha2 == 1){
                    cout << "Registrador a ser alterada: ";
                    cin >> D1;
                    cout << "Novo valor: ";
                    cin >> D2;
                    uniControle->getBancoDeRegistradores()->setValor(D1,D2);
                    cout << endl;
                }
                if(escolha2 == 2){
                    uniControle->getBancoDeRegistradores()->imprimir();
                    cout << endl;
                }
            }
        }
        if(escolha1 == 3){
            cout << "PC: " << uniControle->getPC() << endl;
            uniControle->getBancoDeRegistradores();
            uniControle->executarInstrucao();
            cout << "Instrucao executada" << endl;
            cout << "PC: " << uniControle->getPC() << endl;
            cout << endl;
        }

    }

}