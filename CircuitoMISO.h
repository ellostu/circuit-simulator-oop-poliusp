#ifndef CIRCUITOMISO_H
#define CIRCUITOMISO_H

#include <iostream>
#include <string>
using namespace std;

#include "Circuito.h"
#include "Sinal.h"

class CircuitoMISO : public Circuito {
  public:
    CircuitoMISO();
    virtual ~CircuitoMISO();
    virtual Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2) = 0; // abstrato
};

#endif // CIRCUITOMISO_H