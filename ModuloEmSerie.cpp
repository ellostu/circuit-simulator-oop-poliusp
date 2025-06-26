#include "ModuloEmSerie.h"
#include <stdexcept>

ModuloEmSerie::ModuloEmSerie() {}

ModuloEmSerie::~ModuloEmSerie(){}

Sinal* ModuloEmSerie::processar(Sinal* sinalIN) {
    list<CircuitoSISO*>* listserie = getCircuitos();
    if (listserie->empty()){
        throw new logic_error("Sem elementos na lista");
    }

    Sinal* anterior = sinalIN;

    list<CircuitoSISO *>::iterator i = listserie->begin();

    while (i != listserie->end()) {
        anterior = (*i)->processar(anterior);
        i++;
    }
    return anterior;
}