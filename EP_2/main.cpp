#include "BancoDeRegistradores.h"
#include "Dado.h"
#include "Dispositivo.h"
#include "ESMapeadaNaMemoria.h"
#include "GerenciadorDeMemoria.h"
#include "Instrucao.h"
#include "Memoria.h"
#include "MemoriaRAM.h"
#include "Monitor.h"
#include "MonitorDeChar.h"
#include "Teclado.h"
#include "TecladoDeChar.h"
#include "UnidadeDeControle.h"
using namespace std;

int main(){
    BancoDeRegistradores* banco = new BancoDeRegistradores();
    MemoriaRAM* memram = new MemoriaRAM(64);
    ESMapeadaNaMemoria* mapeada = new ESMapeadaNaMemoria(memram);
    mapeada->adicionar(new Teclado);
    mapeada->adicionar(new TecladoDeChar);
    mapeada->adicionar(new Monitor);
    mapeada->adicionar(new MonitorDeChar);
    UnidadeDeControle* uniControle = new UnidadeDeControle(banco, mapeada);
    
    int loop1 = 1, escolha1, loop2, escolha2;

    while(loop1){
        cout << endl;
        cout << "Emulador de MIPS"<< endl;
        cout << "1) Memoria" << endl;
        cout << "2) Registradores" << endl;
        cout << "3) Executar proxima instrucao" << endl;
        cout << "4) Executar ate PC = 0"<< endl;
        cout << "5) Load" << endl;
        cout << "6) Dump" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha1;
        cout << endl;

        if(escolha1 == 0){
            delete uniControle;
            return 0;
        }
        
        else if(escolha1 == 1){
            loop2 = 1;
            while(loop2){
                cout << "Memoria" << endl;
                cout << "1) Alterar dado" << endl;
                cout << "2) Imprimir" << endl;
                cout << "0) Voltar" << endl;
                cout << "Escolha uma opcao: ";
                cin >> escolha2;
                cout << endl;

                if(escolha2 == 0) loop2 = 0;
                else if(escolha2 == 1){
                    int D1,D2;
                    cout << "Posicao a ser alterada: ";
                    cin >> D1;
                    cout << "Novo valor: ";
                    cin >> D2;
                    uniControle->getMemoria()->escrever(D1,new Dado(D2));
                    cout << endl;
                }
                else if(escolha2 == 2){
                    uniControle->getMemoria()->imprimir();
                    cout << endl;
                }
            }
        }

        else if(escolha1 == 2){
            loop2 = 1;
            while (loop2){
                cout << "Registradores"<< endl;
                cout << "1) Alterar Valor" << endl;
                cout << "2) Imprimir" << endl;
                cout << "0) Voltar" << endl;
                cout << "Escolha uma opcao: ";
                cin >> escolha2;
                cout << endl;

                if(escolha2 == 0) loop2 = 0;
                else if(escolha2 == 1){
                    int D1, D2;
                    cout << "Registrador a ser alterado: ";
                    cin >> D1;
                    cout << "Novo valor: ";
                    cin >> D2;
                    uniControle->getBancoDeRegistradores()->setValor(D1,D2);
                    cout << endl;
                }
                else if(escolha2 == 2){
                    uniControle->getBancoDeRegistradores()->imprimir();
                    cout << endl;
                }
            }
        }

        else if(escolha1 == 3){
            try {
                cout << "PC: " << uniControle->getPC() << endl;
                uniControle->executarInstrucao();
                cout << "Instrucao executada" << endl;
                cout << "PC: " << uniControle->getPC() << endl;
                cout << endl;
            } catch (exception *e){
                cout << e->what() << endl;
                delete e;
            }
        }

        else if(escolha1 == 4){
            loop2 = 1;
            try{ 
                while(loop2){
                uniControle->executarInstrucao();
                if(uniControle->getPC() == 0) loop2 = 0;
                }
            } catch (exception *e){
                cout << e->what() << endl;
                delete e;
            }
        }

        else if(escolha1 == 5){
            try{
                string arquivo;
                cout << "Arquivo origem: ";
                cin >> arquivo;
                GerenciadorDeMemoria* gerenciador = new GerenciadorDeMemoria;
                gerenciador->load(arquivo, memram);
            } catch(runtime_error *r){
                cout << r->what();
                delete r;
            }
        }

        else if(escolha1 == 6){
            try{
                string arquivo;
                cout << "Arquivo destino: ";
                cin >> arquivo;
                GerenciadorDeMemoria* gerenciador = new GerenciadorDeMemoria;
                gerenciador->dump(arquivo, memram);
            } catch(runtime_error *r){
                cout << r->what() << endl;
                delete r;
            }
        }
    }
}