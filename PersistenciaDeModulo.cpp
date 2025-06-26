#include "PersistenciaDeModulo.h"
#include <fstream>
#include "ModuloEmSerie.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "ModuloEmParalelo.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "Derivador.h"
#include <stdexcept>

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo){
    this->nomeDoArquivo = nomeDoArquivo;
}

PersistenciaDeModulo::~PersistenciaDeModulo() {}

void PersistenciaDeModulo::resto(Modulo *mod, ofstream &arquivo){
    list<CircuitoSISO *> *lista = nullptr;
    ModuloRealimentado *v4 = dynamic_cast<ModuloRealimentado *>((mod));

    if (v4 != NULL){
        lista = v4->getCircuitos();
    } 
    else lista = mod->getCircuitos();

    list<CircuitoSISO *>::iterator i = lista->begin();

    ModuloEmParalelo *v1;
    ModuloEmSerie *v2;
    ModuloRealimentado *v3;

    v1 = dynamic_cast<ModuloEmParalelo *>((mod));
    v2 = dynamic_cast<ModuloEmSerie *>((mod));
    v3 = dynamic_cast<ModuloRealimentado *>((mod));
    
    if (v1 != NULL){
        arquivo << "P" << endl;
    } else if (v2 != NULL)
        arquivo << "S" << endl;
    else if (v3 != NULL)
        arquivo << "R" << endl;

    while (i != lista->end()){
        if (dynamic_cast<Amplificador *>((*i))){
            Amplificador *amp = dynamic_cast<Amplificador *>((*i));
            arquivo << "A " << amp->getGanho() << endl;
        } else if (dynamic_cast<Integrador *>((*i)))
            arquivo << "I" << endl;
        else if (dynamic_cast<Derivador *>((*i)))
            arquivo << "D" << endl;
        else{
            Modulo *mod2 = dynamic_cast<Modulo *>((*i));
            resto(mod2, arquivo);
            arquivo << "f" << endl;
        }
        i++;
    }
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod)
{
    list<CircuitoSISO *> *lista = nullptr;
    ModuloRealimentado *v4 = dynamic_cast<ModuloRealimentado *>((mod));
    if (v4 != NULL)
        lista = v4->getCircuitos();
    else
        lista = mod->getCircuitos();
    list<CircuitoSISO *>::iterator i = lista->begin();
    if (lista->empty())
    {

        cout << "NAAO" << endl;
    }
    ofstream arquivo;
    arquivo.open(nomeDoArquivo);
    if (arquivo.fail())
        throw new invalid_argument("Erro ao abrir o arquivo para leitura.");
    ModuloEmParalelo *v1;
    ModuloEmSerie *v2;
    ModuloRealimentado *v3;
    v1 = dynamic_cast<ModuloEmParalelo *>((mod));
    v2 = dynamic_cast<ModuloEmSerie *>((mod));
    v3 = dynamic_cast<ModuloRealimentado *>((mod));

    if (v1 != NULL)
        arquivo << "P" << endl;
    else if (v2 != NULL)
        arquivo << "S" << endl;
    else if (v3 != NULL)
        arquivo << "R" << endl;
    while (i != lista->end())
    {
        if (dynamic_cast<Amplificador *>((*i)))
        {
            Amplificador *amp = dynamic_cast<Amplificador *>((*i));
            arquivo << "A " << amp->getGanho() << endl;
        }
        else if (dynamic_cast<Integrador *>((*i))) 
            arquivo << "I" << endl;
        else if (dynamic_cast<Derivador *>((*i)))
            arquivo << "D" << endl;
        else
        {
            Modulo *mod2 = dynamic_cast<Modulo *>((*i));
            resto(mod2, arquivo);
            arquivo << "f" << endl;
        }
        i++;
    }
    arquivo << "f" << endl;
    arquivo.close();
}

Modulo *PersistenciaDeModulo::lerDeArquivo()
{
    // inicializacao
    Modulo* mod;
    string letra;
    double ganho;

    ifstream arquivo;
    arquivo.open(nomeDoArquivo);
    if (arquivo.fail())
        throw new invalid_argument("Erro ao abrir o arquivo para leitura.");

    while (arquivo >> letra && letra != "f")
    {
        if (letra != "S" && letra != "P" && letra != "R" && letra != "A" && letra != "I" && letra != "D" && letra != "f") {
            throw new logic_error("Arquivo mal formatado"); 
        }

        if (letra == "S")
        {
            mod = new ModuloEmSerie();
            resto2(mod, arquivo);
        }
        else if (letra == "P"){
            mod = new ModuloEmParalelo();
            resto2(mod, arquivo);
        }
        else if (letra == "R"){
            mod = new ModuloRealimentado();
            resto2(mod, arquivo);
        }
    }
    arquivo.close();
    return mod;
}

void PersistenciaDeModulo::resto2(Modulo *mod, ifstream &arquivo)
{
    string letra;
    double ganho;
    arquivo >> letra;

        while (letra != "f") {
            
        if (letra != "S" && letra != "P" && letra != "R" && letra != "A" && letra != "I" && letra != "D" && letra != "f") {
            throw new logic_error("Arquivo mal formatado2");
        }

            if (letra == "S")
            {
                ModuloEmSerie *mod2 = new ModuloEmSerie();
                mod->adicionar(mod2);
                resto2(mod2, arquivo);
            }
            else if (letra == "P")
            {
                ModuloEmParalelo *mod2 = new ModuloEmParalelo();
                mod->adicionar(mod2);
                resto2(mod2, arquivo);
            }
            else if (letra == "R")
            {
                ModuloRealimentado *mod2 = new ModuloRealimentado();
                mod->adicionar(mod2);
                resto2(mod2, arquivo);
            }
            else if (letra == "A")
            {
                arquivo >> ganho;
                Amplificador *amp = new Amplificador(ganho);
                mod->adicionar(amp);
            }
            else if (letra == "I")
            {
                Integrador *inte = new Integrador();
                mod->adicionar(inte);
            }
            else if (letra == "D")
            {
                Derivador *deriv = new Derivador;
                mod->adicionar(deriv);
            }
            arquivo >> letra;
            if (letra == "f") {
            return;
            }
        }
}