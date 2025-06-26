#include "Sinal.h"
#include <stdexcept> 

Sinal::Sinal(double *sequencia, int comprimento) : sequencia (sequencia), comprimento (comprimento) {
    if (this->comprimento <= 0) {
        throw new invalid_argument("comprimento invalido");
    }

    this->sequencia = new double [comprimento];

    for (int i = 0; i < comprimento; i++){
        this->sequencia[i] = sequencia[i];
    }
    
}

Sinal::Sinal(double constante, int comprimento) : comprimento (comprimento), constante (constante) {
    if (this->comprimento <= 0) {
        throw new invalid_argument("comprimento invalido");
    }

    this->sequencia = new double [comprimento];

    for (int i = 0; i < comprimento; i++){
        this->sequencia[i] = this->constante;
    }

}

Sinal::~Sinal(){
    delete[] sequencia;
}

double* Sinal::getSequencia(){
    return this->sequencia;
}

void Sinal::imprimir(string nomeDoSinal){
    this->nomeDoSinal = nomeDoSinal;
    Grafico *imprimir = new Grafico(nomeDoSinal, this->sequencia, this->comprimento);
    imprimir->plot();
    delete imprimir;
}

void Sinal::imprimir() {
    for (int i = 0; i < this->comprimento; i++) {
        cout << i << "- " << sequencia[i] << endl;
    }
    cout << "--" << endl;
}

void Sinal::imprimir(int tamanho) {
    if (comprimento < tamanho) {
        for (int i = 0; i < this->comprimento; i++) {
            cout << i << "- " << sequencia[i] << endl;
        }
        cout << "--" << endl;
    } else {
        for (int i = 0; i < (tamanho-1); i++) {
            cout << i << "- " << sequencia[i] << endl;
        }
        cout << "--" << endl;
    }
}

int Sinal::getComprimento(){
    return this->comprimento;
}
