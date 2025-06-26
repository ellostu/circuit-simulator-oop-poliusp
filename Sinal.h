#include "Grafico.h"
#ifndef SINAL_H
#define SINAL_H
#include <string>
using namespace std;

class Sinal {
 private:
  double *sequencia;
  int comprimento;
  double constante;
  string nomeDoSinal;
 public:
  Sinal(double *sequencia, int comprimento); //EP1
  Sinal(double constante, int comprimento);
  virtual ~Sinal();
  double* getSequencia();
  int getComprimento();
  void imprimir(string nomeDoSinal); //EP1
  void imprimir(); // para testes
  void imprimir(int tamanho);
};

#endif // SINAL_H