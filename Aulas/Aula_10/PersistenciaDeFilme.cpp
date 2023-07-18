#include "PersistenciaDeFilme.h"
#include"Catalogo.h"
#include "Filme.h"
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

// Adicione includes necessarios e implemente os metodos da classe

PersistenciaDeFilme::PersistenciaDeFilme(string arquivo): arquivo(arquivo){
    
}

PersistenciaDeFilme::~PersistenciaDeFilme() {
}

void PersistenciaDeFilme::inserir(Filme* filme) {
    ofstream output;
    output.open(arquivo,ios_base::app);
    output << filme->getNome() << endl << filme->getDuracao() << endl << filme->getVisualizacoes() << endl;
}
Catalogo* PersistenciaDeFilme::obter(){
    ifstream entrada;
    entrada.open ("teste2.txt");
    //persebe se o arquivo existe
    if (entrada.fail() ) {
        throw new invalid_argument("Erro de leitura");
    }
    //percebe se o arquivo está vazio
    string nome;
    entrada >> nome;
    if(entrada.eof()){
        return NULL;
    }
    //armazena os filmes em um catálogo
    int contagem = 0, duracao, visualizacao;
    Catalogo* c1= new Catalogo(10);

    while (entrada){
        if(contagem == 0){
            entrada >> duracao;
        }
        if(contagem == 1){
            entrada >> visualizacao;
        }
        if(contagem == 2){
            entrada >> nome;
        }
        if(contagem == 1){
            Filme* f1 = new Filme(nome,duracao);
            for (int i = 0; i < visualizacao; i++){
                f1->assistir(duracao);
            }
            c1->adicionar(f1);
            
        }
        if(contagem == 2){
            contagem = 0;
        }else{
            contagem++;
        }
    }
    return c1;
}
