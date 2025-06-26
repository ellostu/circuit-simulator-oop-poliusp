#include "Integrador.h"

Integrador::Integrador() : sinalIntegrado(nullptr){}

Integrador::~Integrador(){
    // Delete no menu
}

Sinal *Integrador::processar(Sinal *sinalIN){
    seqIntegrada = new double [sinalIN->getComprimento()];

    seqIntegrada[0] = sinalIN->getSequencia()[0];
    
    for (int i = 1; i < sinalIN->getComprimento(); i++){
        seqIntegrada[i] = sinalIN->getSequencia()[i] + seqIntegrada[i-1];
    }

    sinalIntegrado = new Sinal(seqIntegrada,sinalIN->getComprimento());

    delete[] seqIntegrada;

    return sinalIntegrado;
}
