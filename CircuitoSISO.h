#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include <iostream>
#include <string>
using namespace std;

#include "Circuito.h"
#include "Sinal.h"

class CircuitoSISO : public Circuito {
 public:
  CircuitoSISO();
  virtual ~CircuitoSISO();
  virtual Sinal* processar(Sinal* sinalIN) = 0; // abstrato
};

#endif // CIRCUITOSISO_H