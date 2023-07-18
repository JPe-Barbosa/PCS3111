#ifndef CATALOGO_H
#define CATALOGO_H
#include <string>
using namespace std;
#include "Filme.h"

//Modifique a classe Catalogo para que seus filmes estejam em um container vector
#include <vector>
class Catalogo {
public:

    Catalogo(string nome);
    virtual ~Catalogo();

    string getNome();
    void adicionar(Filme *f);
    int getDuracaoTotal();
    vector <Filme*>* getFilmes(); 
    void imprimir();

private:
    // int maximoFilmes;
    // int quantidadeFilmes;
    vector<Filme*>* filmes;
    //Filme** filmes;
    string nome;
};

#endif // CATALOGO_H
