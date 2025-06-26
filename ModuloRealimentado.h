
#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include <iostream>
#include "Somador.h"
#include "Derivador.h"
#include "ModuloEmSerie.h"

using namespace std;

class ModuloRealimentado : public Modulo{
 private:
  ModuloEmSerie *mod;
  double* seqSaidaInvertida;
  double* seqDiferenca;
  Sinal *saida;
  Sinal *diferenca;
  Sinal *saidaInvertida;
 public:
  ModuloRealimentado();
  virtual ~ModuloRealimentado();
  Sinal* processar(Sinal* sinalIN);
  virtual void adicionar(CircuitoSISO *circ);
  virtual list<CircuitoSISO*>* getCircuitos();
};

#endif // MODULOREALIMENTADO_H