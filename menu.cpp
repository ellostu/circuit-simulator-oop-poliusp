#define _USE_MATH_DEFINES
#include <cmath>
#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "Sinal.h"
#include "Modulo.h"
#include "ModuloRealimentado.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "CircuitoSISO.h"
#include "PersistenciaDeModulo.h"
#include <fstream>
#include <stdexcept>

#include <iostream>
using namespace std;

#define tamanho 60


Sinal *novoSinal();
void novaOperacao(Sinal *sinalIN, Modulo *mod);
void salvarEmArquivo(Modulo *mod);

void menu(){
    try{
        int qSimulacao = 0;
        Sinal *s1;
        string nomeDoArquivo;

        cout << "\tSimulink em C++" << endl;
        cout << "Qual simulacao voce gostaria de fazer?" << endl;
        cout << "1) Circuito advindo de arquivo" << endl;
        cout << "2) Sua propria sequencia de operacoes" << endl;
        cout << "Escolha: ";
        cin >> qSimulacao; 
        cout << endl;
        
        s1 = novoSinal();   // Processo de aquisicao de um novo sinal 

        // Simulacao 1

        if (qSimulacao == 1){
            Modulo *m1;
            cout << "Qual o nome do arquivo a ser lido?" << endl;
            cout << "Nome: ";
            cin >> nomeDoArquivo;
            cout << endl;

            // Aquisicao do sinal do arquivo 

            PersistenciaDeModulo *pdm1 = new PersistenciaDeModulo(nomeDoArquivo);
            m1 = pdm1->lerDeArquivo();
            s1 = m1->processar(s1);
            s1->imprimir("Resultado Final");

            salvarEmArquivo(m1);
            delete pdm1;
            delete m1;
            delete s1;

            return;
        }

        // Simulacao 2
        if (qSimulacao == 2){
            Modulo *mod;
            int escolha;
            cout << "Qual estrutura de operacoes voce deseja ter como base?" << endl;
            cout << "1) Operacoes em serie nao realimentadas" << endl;                      // Modulo Em Serie
            cout << "2) Operacoes em paralelo nao realimentadas" << endl;                   // Modulo Em Paralelo
            cout << "3) Operacoes em serie realimentadas" << endl;                          // Modulo Realimentado
            cout << "Escolha: ";
            cin >> escolha;
            cout << endl;

            if (escolha == 1) {     // 1) Operacoes em serie nao realimentadas
                mod = new ModuloEmSerie();
                novaOperacao(s1,mod);

            } else if (escolha == 2) {     // 2) Operacoes em paralelo nao realimentadas
                mod = new ModuloEmParalelo();
                novaOperacao(s1,mod);
                
            } else if (escolha == 3) {      // 3) Operacoes em serie realimentadas
                mod = new ModuloRealimentado();
                novaOperacao(s1,mod);
            }
            
            delete mod;
            delete s1;
            return;
        }

    } catch(invalid_argument *e) {
        cout << "Erro: " << e->what() << endl;
        delete e;
    } catch(logic_error *e) {
        cout << "Erro: " << e->what() << endl;
        delete e;
    } 
    return;
}

Sinal *novoSinal(){
    int tipoS;
    double escolha = 0;
    double sequencia[tamanho];

    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl;
    cout << "1) 5+3*cos(n*pi/8)" << endl;
    cout << "2) constante" << endl;
    cout << "3) rampa" << endl;
    cout << "Escolha: " ;
    cin >> tipoS;
    cout << endl;


    if (tipoS == 3){    // 3) rampa
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cout << "a = ";
        cin >> escolha;
        cout << endl;

        for (int i = 0; i < tamanho; i++){
            sequencia[i] = escolha * i;
        }
        
        Sinal *s1 = new Sinal(sequencia, tamanho);
        return s1;
    } 
    
    if (tipoS == 2){    // 2) constante
        cout << "Qual o valor dessa constante?" << endl;
        cout << "C = ";
        cin >> escolha;
        cout << endl;

        for (int i = 0; i < tamanho; i++){
            sequencia[i] = escolha;
        }
        
        Sinal *s1 = new Sinal(sequencia, tamanho);
        return s1;
    }

    if (tipoS == 1){    // 1) 5+3*cos(n*pi/8)
        for (int i = 0; i < tamanho; i++){
            sequencia[i] = 5 + 3*cos(i*M_PI/8);
        }

        Sinal *s1 = new Sinal(sequencia, tamanho);
        return s1;
    }

    return nullptr;
}

void novaOperacao(Sinal *sinalIN, Modulo *mod){
    //Apesar da sugestao/dica de implementacao, decidimos utilizar uma funcao void para o recursivo
    int operacao = 0;
    int refaz = 0;

    Amplificador *a1 = nullptr;
    Derivador *d1 = nullptr;
    Integrador *i1 = nullptr;


    cout << "Qual operacao voce gostaria de fazer?" << endl;
    cout << "1) Amplificar" << endl;
    cout << "2) Derivar" << endl;
    cout << "3) Integrar" << endl;
    cout << "Escolha: ";
    cin >> operacao;
    cout << endl;

    if (operacao == 1){     // 1) Amplificar
        double ganhoA;          
        cout << "Qual o ganho dessa amplificacao" << endl;
        cout << "g = ";
        cin >> ganhoA;
        cout << endl;
    
        a1 = new Amplificador(ganhoA);
        mod->adicionar(a1);
    }

    if (operacao == 2){     // 2) Derivar
        d1 = new Derivador();
        mod->adicionar(d1);
    }

    if (operacao == 3){     // 3) Integrar
        i1 = new Integrador();
        mod->adicionar(i1);
    }
    
    cout << "O que voce quer fazer agora?" << endl;
    cout << "1) Realizar mais uma operacao no resultado" << endl;
// Ficamos na duvida nessa questao uma vez que o bloco de aquisicao amarelo esta escrito isso (Realizar...), no entanto o exemplo fornecido tem outra frase (Insrir...)
    cout << "2) Imprimir o resultado" << endl;
    cout << "Escolha: ";
    cin >> refaz;
    cout << endl;

    if (refaz == 2){        // Nao Refaz - So imprime e salva
        sinalIN = mod->processar(sinalIN);
        sinalIN->imprimir("Resultado");
        salvarEmArquivo(mod);
    }
    else if(refaz == 1){         // Refaz
        novaOperacao(sinalIN, mod);
    }
}

void salvarEmArquivo(Modulo *mod){
    int salvarEmArquivo;

    cout << "Voce gostaria de salvar o circuito em um novo arquivo?" << endl;
    cout << "1) Sim" << endl;
    cout << "2) Nao" << endl;
    cout << "Escolha: ";
    cin >> salvarEmArquivo;
    cout << endl;

    if (salvarEmArquivo == 2) {      // 2) Nao
        return;
    }

    if (salvarEmArquivo == 1) {      // 1) Sim
        // salvar  em arquivo
        string nomeArquivoSalvar;
        cout << "Qual o nome do arquivo a ser escrito?" << endl;
        cout << "Nome: ";
        cin >> nomeArquivoSalvar;
        cout << endl;

        PersistenciaDeModulo *pdm1 = new PersistenciaDeModulo(nomeArquivoSalvar);
        pdm1->salvarEmArquivo(mod);
        delete pdm1;

        return;
    }
}
