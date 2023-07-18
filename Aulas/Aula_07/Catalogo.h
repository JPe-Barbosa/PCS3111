#ifndef CATALOGO_H
#define CATALOGO_H
#include "Filme.h"
#include "Lancamento.h"
//Faca os includes necessarios a medida em que faz os exercicios


class Catalogo {
public:
    //Declare os metodos pedidos no enunciado
    Catalogo(int tamanhoMaximo);
    ~Catalogo();
    bool adicionar(Filme *f);
    bool adicionar(string categoria);
    int getDuracaoTotal();
    int getTotalDeVisualizacoes();
    Filme** getFilmes();
    string* getCategorias();
    Lancamento** getLancamentos(int &quantidadedeLancamentos);

    void imprimir();

private:
    int tamanhoMaximo;
    Filme** filmes;
    string* categorias;

    int quantidadeFilmes;
    int quantidadeCategorias;

};

#endif // CATALOGO_H
