#include "Somador.h"
#include "CircuitoMISO.h"

Somador::Somador() : CircuitoMISO(), sinalSoma(nullptr){}

Somador::~Somador(){
    // Delete no menu
}

Sinal *Somador::processar(Sinal *sinalIN1, Sinal *sinalIN2){
    int comprimentoSoma;
    if (sinalIN1->getComprimento()<= sinalIN2->getComprimento()){
        comprimentoSoma = sinalIN1->getComprimento();
    } else {
        comprimentoSoma = sinalIN2->getComprimento();
    }
    
    seqSoma = new double [comprimentoSoma];

    for (int i = 0; i < comprimentoSoma; i++){
        seqSoma[i] = (sinalIN1->getSequencia()[i]) + (sinalIN2->getSequencia()[i]);
    }

    sinalSoma = new Sinal(seqSoma,comprimentoSoma);

    delete[] seqSoma;

    return sinalSoma;
}
