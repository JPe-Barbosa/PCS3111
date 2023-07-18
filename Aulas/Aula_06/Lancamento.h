#ifndef LANCAMENTO_H
#define LANCAMENTO_H
#include"Filme.h"

class Lancamento : public Filme {
private:
    int preco; 
    int dataDeLancamento;
public:
    Lancamento(int preco, int dataDeLancamento, string nome, int duracao);
    ~Lancamento();

    int getPreco();
    int getDataDeLancamento();

    void imprimir();
};

#endif // LANCAMENTO_H
