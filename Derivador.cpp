#include "Derivador.h"

Derivador::Derivador() : sinalDerivado(nullptr){}

Derivador::~Derivador(){
    // Delete no menu
}

Sinal *Derivador::processar(Sinal *sinalIN){
    seqDerivada = new double [sinalIN->getComprimento()];

    seqDerivada[0] = sinalIN->getSequencia()[0];

    for (int i = 1; i < sinalIN->getComprimento(); i++){
        seqDerivada[i] = sinalIN->getSequencia()[i] - sinalIN->getSequencia()[i-1];
    }

    sinalDerivado = new Sinal(seqDerivada,sinalIN->getComprimento());

    delete[] seqDerivada;

    return sinalDerivado;
}
