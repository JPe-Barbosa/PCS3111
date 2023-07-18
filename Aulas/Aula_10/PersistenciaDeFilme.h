#ifndef PERSISTENCIA_FILME_H
#define PERSISTENCIA_FILME_H

#include <string>
#include "Filme.h"
#include "Catalogo.h"

using namespace std;

class PersistenciaDeFilme {
private:
    string arquivo;
public:
    PersistenciaDeFilme(string arquivo);
    virtual ~PersistenciaDeFilme();
    Catalogo* obter();

    void inserir(Filme* filme);
};

#endif  // PERSISTENCIA_FILME_H