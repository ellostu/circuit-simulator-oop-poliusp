#ifndef MODULO_EM_SERIE
#define MODULO_EM_SERIE
#include "Modulo.h"


class ModuloEmSerie : public Modulo {
 private:
    list<CircuitoSISO*>* listserie;
 public:
    ModuloEmSerie();
    virtual ~ModuloEmSerie();
    Sinal* processar(Sinal* sinalIN);
};






#endif