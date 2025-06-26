#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <iostream>
#include <string>
using namespace std;

class Circuito {
 private:
  int id;
  static int ultimoId;
 public:
  Circuito();
  virtual ~Circuito() = 0;
  int getID();
  void imprimir();
  static int getUltimoID();
};

#endif // CIRCUITO_H