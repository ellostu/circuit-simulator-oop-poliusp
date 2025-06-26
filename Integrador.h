
#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include <iostream>
#include "CircuitoSISO.h"
#include "Sinal.h"

using namespace std;

class Integrador : public CircuitoSISO {
 private:
  Sinal* sinalIntegrado;
  double* seqIntegrada;
 public:
  Integrador();
  virtual ~Integrador();
  Sinal* processar(Sinal* sinalIN);
};

#endif // INTEGRADOR_H