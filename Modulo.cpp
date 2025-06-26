#include "Modulo.h"

Modulo::Modulo() : CircuitoSISO(){
    listcirc = new list<CircuitoSISO *>();
}

Modulo::~Modulo(){
    delete listcirc;
}

void Modulo::imprimir(){
    cout << "Modulo com ID " << getID() << " e :" << endl;

    list<CircuitoSISO *>::iterator i = listcirc->begin();
    
    while (i != listcirc->end()) {
        cout << "Circuito com ID " << (*i)->getID() << endl;
        i++;
    }
}

void Modulo::adicionar(CircuitoSISO *circ){
    listcirc->push_back(circ);
}

list<CircuitoSISO *> *Modulo::getCircuitos(){
    return listcirc;
}