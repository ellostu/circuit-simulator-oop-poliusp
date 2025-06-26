#include "ModuloEmParalelo.h"
#include "Somador.h"
#include <stdexcept>

ModuloEmParalelo::ModuloEmParalelo() {}

ModuloEmParalelo::~ModuloEmParalelo() {}

Sinal *ModuloEmParalelo::processar(Sinal *sinalIN){
    double v[sinalIN->getComprimento()];

    for (int i = 0; i < sinalIN->getComprimento(); i++){
        v[i] = 0;
    }

    Sinal *sinalSoma = new Sinal(v, sinalIN->getComprimento());
    Somador *som = new Somador();

    list<CircuitoSISO *> *listparalelo = getCircuitos();
    
    if (listparalelo->empty()){
        throw new logic_error("Sem elementos na lista");
    }

    list<CircuitoSISO *>::iterator i = listparalelo->begin();
    while (i != listparalelo->end()) {
        sinalSoma = som->processar(sinalSoma, (*i)->processar(sinalIN));
        i++;
    }

    delete som;
    return sinalSoma;
}