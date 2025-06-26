#ifndef MODULO_H
#define MODULO_H
#include <iostream>
#include "CircuitoSISO.h"
#include <list>

using namespace std;

class Modulo : public CircuitoSISO {
 private:
    list<CircuitoSISO*>* listcirc;
 public :
    Modulo();
    virtual ~Modulo() ;
    virtual void adicionar(CircuitoSISO* circ);
    virtual list<CircuitoSISO*>* getCircuitos();
    void imprimir();
};

#endif