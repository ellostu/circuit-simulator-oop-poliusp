#include "Circuito.h"
#include <iostream>

#include <string>
using namespace std;

int Circuito::ultimoId = 0;

Circuito::Circuito() {
    this->id = ultimoId + 1;
    ultimoId ++;
}

Circuito::~Circuito(){}

int Circuito::getID() {
    return this->id;
}

void Circuito::imprimir() {
    cout << "Circuito com ID " << id << endl;
}

int Circuito::getUltimoID() {
    return ultimoId;
}
