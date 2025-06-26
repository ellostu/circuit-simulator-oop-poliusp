#include "Amplificador.h"
#include "CircuitoSISO.h"

Amplificador::Amplificador(double ganho) : CircuitoSISO(), ganho(ganho), sinalAmpli(nullptr){ }

Amplificador::~Amplificador(){
    // Delete o sinalAmpli no menu
}

Sinal* Amplificador::processar(Sinal* sinalIN) {
    // Retorna um novo Sinal
    // Quem invoca o método deve deletar o novo sinal criado
    seqAmplif = new double [sinalIN->getComprimento()];

    for (int i = 0; i < sinalIN->getComprimento(); i++) {
        seqAmplif[i] = sinalIN->getSequencia()[i];
        seqAmplif[i] = seqAmplif[i] * ganho;
    }

    sinalAmpli = new Sinal(seqAmplif, sinalIN->getComprimento());
    delete[] seqAmplif;
    return sinalAmpli;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

double Amplificador::getGanho(){
    return this->ganho;
}
