#ifndef PERSISTENCIA
#define PERSISTENCIA

#include <iostream>
#include <string>
#include "Modulo.h"
using namespace std;

class PersistenciaDeModulo {
 private:
    string nomeDoArquivo;
    Modulo* mod;
    void resto(Modulo *mod, ofstream& arquivo);
    void resto2(Modulo* mod, ifstream& arquivo);
 public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
};

#endif