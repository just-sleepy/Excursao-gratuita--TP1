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
    // Codigo:
    TUCodigo testedecodigo;
    switch(testedecodigo.run()){
    case TUCodigo::SUCESSO:
        cout << "Codigo: SUCESSO" << endl;
        break;
    case TUCodigo::FALHA:
        cout << "Codigo: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Gustavo Pierre Starling
    // Horario:
    TUHorario testedehorario;
    switch(testedehorario.run()){
    case TUHorario::SUCESSO:
        cout << "Horario: SUCESSO" << endl;
        break;
    case TUHorario::FALHA:
        cout << "Horario: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Gustavo Pierre Starling
    // Senha:
    TUSenha testedesenha;
    switch(testedesenha.run()){
    case TUSenha::SUCESSO:
        cout << "Senha: SUCESSO" << endl;
        break;
    case TUSenha::FALHA:
        cout << "Senha: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Gustavo Pierre Starling
    // Nome:
    TUNome testedenome;
    switch(testedenome.run()){
    case TUNome::SUCESSO:
        cout << "Nome: SUCESSO" << endl;
        break;
    case TUNome::FALHA:
        cout << "Nome: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Felipe Dantas Borges

    // Email:

    TUEmail testeemail;
    switch(testeemail.run()){
    case TUEmail::SUCESSO:
        cout << "Email: SUCESSO" << endl;
        break;
    case TUEmail::FALHA:
        cout << "Email: FALHA" << endl;
        break;
    }

        // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Felipe Dantas Borges

    // Data:

    TUData testedata;
    switch(testedata.run()){
    case TUEmail::SUCESSO:
        cout << "Data: SUCESSO" << endl;
        break;
    case TUEmail::FALHA:
        cout << "Data: FALHA" << endl;
        break;
    }

    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Felipe Dantas Borges

    // Titulo:

    TUTitulo testetitulo;
    switch(testetitulo.run()){
    case TUEmail::SUCESSO:
        cout << "Titulo: SUCESSO" << endl;
        break;
    case TUEmail::FALHA:
        cout << "Titulo: FALHA" << endl;
        break;
    }

    // --------------------------------------------------------------------------
    // Matricula: 202006420
    // Felipe Dantas Borges

    // Titulo:

    TUEndereco testeendereco;
    switch(testeendereco.run()){
    case TUEndereco::SUCESSO:
        cout << "Endereco: SUCESSO" << endl;
        break;
    case TUEndereco::FALHA:
        cout << "Endereco: FALHA" << endl;
        break;
    }


// --------------------------------------------------------------------------
    // Matricula: 202006448
    // Rafael Hamú Campos
    // Idioma:

    TUIdioma testeidioma;
    switch(testeidioma.run()){
    case TUIdioma::SUCESSO:
        cout << "Idioma: SUCESSO" << endl;
        break;
    case TUIdioma::FALHA:
        cout << "Idioma: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006448
    // Rafael Hamú Campos

    // nota:

    TUNota testedenota;
    switch(testedenota.run()){
    case TUNota::SUCESSO:
        cout << "Nota: SUCESSO" << endl;
        break;
    case TUNota::FALHA:
        cout << "Nota: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006448
    // Rafael Hamú Campos

    //Duracao:

    TUDuracao testededuracao;
    switch(testededuracao.run()){
    case TUDuracao::SUCESSO:
        cout << "Duracao: SUCESSO" << endl;
        break;
    case TUDuracao::FALHA:
        cout << "Duracao: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006448
    // Rafael Hamú Campos

    // Descricao:

    TUDescricao testededescricao;
    switch(testededescricao.run()){
    case TUDescricao::SUCESSO:
        cout << "Descricao: SUCESSO" << endl;
        break;
    case TUDescricao::FALHA:
        cout << "Descricao: FALHA" << endl;
        break;
    }






//ENTIDADES----------------------------------------------------------------------------------------
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


    // --------------------------------------------------------------------------
    // Matricula:202021749
    // Felipe Dantas Borges

    // Excursao:

    TUExcursao testeexcursao;
    switch(testeexcursao.run()){
    case TUExcursao::SUCESSO:
        cout << "Excursao: SUCESSO" << endl;
        break;
    case TUSessao::FALHA:
        cout << "Excursao: SUCESSO" << endl;
        break;
    }



// --------------------------------------------------------------------------
    // Matricula: 202006448
    // Rafael Hamú Campos

    // Usuario:

    TUUsuario testedeusuario;
    switch(testedeusuario.run()){
    case TUUsuario::SUCESSO:
        cout << "Usuario: SUCESSO" << endl;
        break;
    case TUUsuario::FALHA:
        cout << "Usuario: FALHA" << endl;
        break;
    }
    // --------------------------------------------------------------------------
    // Matricula: 202006448
    // Rafael Hamú Campos

    // Avaliacao:

    TUAvaliacao testedeavaliacao;
    switch(testedeavaliacao.run()){
    case TUAvaliacao::SUCESSO:
        cout << "Avaliacao: SUCESSO" << endl;
        break;
    case TUAvaliacao::FALHA:
        cout << "Avaliacao: FALHA" << endl;
        break;
    }

    return 0;
}
