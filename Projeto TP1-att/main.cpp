#include <iostream>
#include "testes.h"

using namespace std;

int main()
{
    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Gustavo Pierre Starling

    // Cidade:

    TUCidade testedecidade;
    switch(testedecidade.run()){
    case TUCidade::SUCESSO:
        cout << "Cidade: SUCESSO" << endl;
        break;
    case TUCidade::FALHA:
        cout << "Cidade: FALHA" << endl;
        break;
    }


    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Gustavo Pierre Starling

    // Sessao:

    TUSessao testedesessao;
    switch(testedesessao.run()){
    case TUSessao::SUCESSO:
        cout << "Sessao: SUCESSO" << endl;
        break;
    case TUSessao::FALHA:
        cout << "Sessao: SUCESSO" << endl;
        break;
    }



    return 0;
}
