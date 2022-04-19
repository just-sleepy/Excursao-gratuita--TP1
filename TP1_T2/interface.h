#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Adequar as declaraçőes das interfaces de acordo com as necessidades.
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

// Forward declarations.

class IServicoAutenticacao;
class IServicoConta;
class IServicoExcursao;

//--------------------------------------------------------------------------------------------
// Declaraçőes das interfaces da camada de apresentaçăo.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoConta{
    public:
        virtual void executar(Email) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoConta(IServicoConta*) = 0;
        virtual void setCntrServicoExcursao(IServicoExcursao*) = 0;
        virtual ~IApresentacaoConta(){}
};

class IApresentacaoExcursao{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoExcursao(IServicoExcursao*) = 0;
        virtual ~IApresentacaoExcursao(){}
};

//--------------------------------------------------------------------------------------------
// Declaraçőes das interfaces da camada de serviço.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoConta{
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual bool editarUsuario(Usuario) = 0;
        virtual bool descadastrarUsuario(Email) = 0;
        virtual ~IServicoConta(){}
};

class IServicoExcursao{
public:
        virtual bool cadastrarExcursao(Excursao, Email) = 0;
        virtual bool consultarExcursao(Excursao*, Email*) = 0;
        virtual bool descadastrarExcursao(Codigo, Email) = 0;
        virtual bool listarExcursao(list<Excursao>*) = 0;
        virtual bool editarExcursao(Excursao, Email) = 0;

        virtual bool cadastrarAvaliacao(Avaliacao, Email, Codigo) = 0;
        virtual bool consultarAvaliacao(Email, Avaliacao*, Email*, Codigo*) = 0;
        virtual bool descadastrarAvaliacao(Codigo, Email) = 0;
        virtual bool listarAvaliacao(Email, list<Avaliacao>*, list<Codigo>*) = 0;
        virtual bool editarAvaliacao(Avaliacao) = 0;

        virtual bool cadastrarSessao(Sessao, Email, Codigo) = 0;
        virtual bool consultarSessao(Email, Sessao*, Email*, Codigo*) = 0;
        virtual bool descadastrarSessao(Codigo, Email) = 0;
        virtual bool listarSessao(Email, list<Sessao>*, list<Codigo>*) = 0;
        virtual bool editarSessao(Sessao) = 0;

        virtual ~IServicoExcursao(){}
};

#endif // INTERFACES_H_INCLUDED
