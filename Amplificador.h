#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include <iostream>
#include "Sinal.h"
#include "CircuitoSISO.h"

using namespace std;

class Amplificador : public CircuitoSISO {
 private:
  double ganho;
  double *seqAmplif;
  Sinal *sinalAmpli;
 public:
  Sinal* processar(Sinal* sinalIN);
  Amplificador(double ganho);
  virtual ~Amplificador();
  void setGanho(double ganho);
  double getGanho();
};

#endif // AMPLIFICADOR_H