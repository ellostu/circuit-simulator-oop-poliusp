#ifndef MODULO_EM_PARALELO
#define MODULO_EM_PARALELO
#include "Modulo.h"


class ModuloEmParalelo : public Modulo {
 public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    Sinal* processar(Sinal* sinalIN);
};

#endif