#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado(){
    mod = new ModuloEmSerie();
    diferenca = saida = saidaInvertida = nullptr;
}

ModuloRealimentado::~ModuloRealimentado(){
    delete mod;
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN){
    // Declaracoes
    seqSaidaInvertida = new double[sinalIN->getComprimento()];
    // Caso inicial
    double vInicial = 0;
    seqSaidaInvertida[0] = vInicial * (-1);
    diferenca = new Sinal(sinalIN->getSequencia(), 1);
    saida = mod->processar(diferenca);
    delete diferenca;

    // Iteracoes
    for (int i = 1; i < sinalIN->getComprimento(); i++){
        seqSaidaInvertida[i]= saida->getSequencia()[i-1] * (-1);
        saidaInvertida = new Sinal(seqSaidaInvertida, i+1);
        Somador *soma = new Somador;
        diferenca = soma->processar(sinalIN, saidaInvertida);
        delete saida;
        saida = new Sinal(mod->processar(diferenca)->getSequencia(), i+1);
        delete saidaInvertida;
        delete diferenca;
        delete soma;
    }
    delete[] seqSaidaInvertida;
    return saida;
}
void ModuloRealimentado::adicionar(CircuitoSISO *circ){
    mod->adicionar(circ);
}

list<CircuitoSISO*>* ModuloRealimentado::getCircuitos() {
    return mod->getCircuitos();
}