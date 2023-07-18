#include "Filme.h"
#define NUMERO_MAXIMO_VALORES 10

class Catalogo {
    private:
        Filme *filmes[NUMERO_MAXIMO_VALORES];
        int quantidade = 0;

    public:
        bool adicionar(Filme* f);
        int getQuantidade();
        int getDuracaoTotal();
        void imprimir();
};