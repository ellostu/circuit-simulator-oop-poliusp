
#ifndef DERIVADOR_H
#define DERIVADOR_H

#include <iostream>
#include "CircuitoSISO.h"
#include "Sinal.h"

using namespace std;

class Derivador : public CircuitoSISO {
 private:
  Sinal* sinalDerivado;
  double* seqDerivada;
 public:
  Derivador();
  virtual ~Derivador();
  Sinal* processar(Sinal* sinalIN);
};

#endif // DERIVADOR_H