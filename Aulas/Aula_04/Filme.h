#ifndef FILME_H
#define FILME_H
#include <string>

using namespace std;

class Filme {
    private:
        string nome;
        int duracao;
    public:
        void imprimir();
        string getNome();
        void setNome(string nome);
        int getDuracao();
        void setDuracao(int duracao);

};
#endif