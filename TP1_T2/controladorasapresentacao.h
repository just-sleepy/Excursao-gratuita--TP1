#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include <iostream>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interface.h"
#define CLR_SCR system("cls");

#include <list>

//--------------------------------------------------------------------------------------------
// Classes controladoras da camada de apresentaçăo.

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo controle.

class CntrApresentacaoControle{
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoConta *cntrApresentacaoConta;
        IApresentacaoExcursao *cntrApresentacaoExcursao;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoConta(IApresentacaoConta*);
        void setCntrApresentacaoExcursao(IApresentacaoExcursao*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoConta(IApresentacaoConta *cntr){
            cntrApresentacaoConta = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoExcursao(IApresentacaoExcursao *cntr){
    cntrApresentacaoExcursao = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo autenticaçăo.

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Email*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo conta.

class CntrApresentacaoConta:public IApresentacaoConta{
    private:
        IServicoConta *cntrServicoConta;
        IServicoExcursao *cntrServicoExcursao;
        void editar(Email);
        void descadastrar(Email);
    public:
        void executar(Email);
        void cadastrar();
        void setCntrServicoConta(IServicoConta*);
        void setCntrServicoExcursao(IServicoExcursao*);
};

inline void CntrApresentacaoConta::setCntrServicoConta(IServicoConta *cntr){
    cntrServicoConta = cntr;
}

inline void CntrApresentacaoConta::setCntrServicoExcursao(IServicoExcursao *cntr){
    cntrServicoExcursao = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo excursão.

class CntrApresentacaoExcursao:public IApresentacaoExcursao{
    private:
        IServicoExcursao *cntr;
        void cadastrarExcursao(Email);
        void consultarExcursao();
        void descadastrarExcursao(Email);
        void listarExcursao();
        void editarExcursao(Email);

        void cadastrarAvaliacao(Email);
        void consultarAvaliacao(Email);
        void descadastrarAvaliacao(Email);
        void listarAvaliacao(Email);
        void editarAvaliacao(Email);

        void cadastrarSessao(Email);
        void consultarSessao(Email);
        void descadastrarSessao(Email);
        void listarSessao(Email);
        void editarSessao(Email);

    public:
        void executar();
        void executar(Email);
        void setCntrServicoExcursao(IServicoExcursao*);
};

inline void CntrApresentacaoExcursao::setCntrServicoExcursao(IServicoExcursao *cntr){
    this->cntr = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
