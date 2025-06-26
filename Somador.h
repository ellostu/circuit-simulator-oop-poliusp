
#ifndef SOMADOR_H
#define SOMADOR_H

#include <iostream>
#include "Sinal.h"
#include "CircuitoMISO.h"

using namespace std;

class Somador : public CircuitoMISO {
 private:
  Sinal* sinalSoma;
  double* seqSoma;
 public:
  Somador();
  virtual ~Somador();
  Sinal *processar(Sinal *sinalIN1, Sinal *sinalIN2);
};

#endif // SOMADOR_H