#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interface.h"

#include <list>

#include <iostream>

#include <string>
#include <stdio.h>

#include "sqlite3.h"

//--------------------------------------------------------------------------------------------
// Classe ErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
            nomeBancoDados = "tp1_t2_db.db";
        }
        void executar();
};

//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Email);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

class ComandoCadastrarUsuario:public ComandoSQL {
public:
        ComandoCadastrarUsuario(Usuario);
};
//---------------------------------------------------------------------------
//Classe ComandoEditarUsuario.

class ComandoEditarUsuario:public ComandoSQL {
public:
        ComandoEditarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarUsuario.

class ComandoDescadastrarUsuario:public ComandoSQL {
public:
        ComandoDescadastrarUsuario(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarExcursao.

class ComandoCadastrarExcursao:public ComandoSQL {
public:
        ComandoCadastrarExcursao(Excursao, Email);
};

//---------------------------------------------------------------------------
//Classe ComandoLerEmailExcursao.

class ComandoLerEmailExcursao:public ComandoSQL {
public:
        ComandoLerEmailExcursao(Codigo);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarExcursao.

class ComandoDescadastrarExcursao:public ComandoSQL {
    public:
        ComandoDescadastrarExcursao(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoListarExcursao.

class ComandoListarExcursao:public ComandoSQL {
public:
        ComandoListarExcursao();
        list<Excursao> getResultado(list<Email>*);
};

//---------------------------------------------------------------------------
//Classe ComandoEditarExcursao.

class ComandoEditarExcursao:public ComandoSQL {
public:
        ComandoEditarExcursao(Excursao);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarExcursaoPorEmail.

class ComandoDescadastrarExcursaoPorEmail:public ComandoSQL {
    public:
        ComandoDescadastrarExcursaoPorEmail(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarExcursao.

class ComandoPesquisarExcursao:public ComandoSQL {
public:
        ComandoPesquisarExcursao(Codigo);
        Excursao getResultado(Email*);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarAvaliacao.

class ComandoCadastrarAvaliacao:public ComandoSQL {
public:
        ComandoCadastrarAvaliacao(Avaliacao, Email, Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoLerEmailAvaliacao.

class ComandoLerEmailAvaliacao:public ComandoSQL {
public:
        ComandoLerEmailAvaliacao(Codigo);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacao.

class ComandoDescadastrarAvaliacao:public ComandoSQL {
    public:
        ComandoDescadastrarAvaliacao(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAvaliacao.

class ComandoPesquisarAvaliacao:public ComandoSQL {
public:
        ComandoPesquisarAvaliacao(Codigo);
        Avaliacao getResultado(Email*, Codigo*);
};

//---------------------------------------------------------------------------
//Classe ComandoListarAvaliacao.

class ComandoListarAvaliacao:public ComandoSQL {
public:
        ComandoListarAvaliacao();
        list<Avaliacao> getResultado(list<Codigo>*, list<Email>*);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacaoPorEmail.

class ComandoDescadastrarAvaliacaoPorEmail:public ComandoSQL {
    public:
        ComandoDescadastrarAvaliacaoPorEmail(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacaoPorCodigoExcursao.

class ComandoDescadastrarAvaliacaoPorCodigoExcursao:public ComandoSQL {
    public:
        ComandoDescadastrarAvaliacaoPorCodigoExcursao(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacaoDeExcursaoDeUsuario.

class ComandoDescadastrarAvaliacaoDeExcursaoDeUsuario:public ComandoSQL {
    public:
        ComandoDescadastrarAvaliacaoDeExcursaoDeUsuario(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarSessao.

class ComandoCadastrarSessao:public ComandoSQL {
public:
        ComandoCadastrarSessao(Sessao, Email, Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoLerEmailSessao.

class ComandoLerEmailSessao:public ComandoSQL {
public:
        ComandoLerEmailSessao(Codigo);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessao.

class ComandoDescadastrarSessao:public ComandoSQL {
    public:
        ComandoDescadastrarSessao(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarSessao.

class ComandoPesquisarSessao:public ComandoSQL {
public:
        ComandoPesquisarSessao(Codigo);
        Sessao getResultado(Email*, Codigo*);
};

//---------------------------------------------------------------------------
//Classe ComandoListarSessao.

class ComandoListarSessao:public ComandoSQL {
public:
        ComandoListarSessao();
        list<Sessao> getResultado(list<Codigo>*, list<Email>*);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessaoPorEmail.

class ComandoDescadastrarSessaoPorEmail:public ComandoSQL {
    public:
        ComandoDescadastrarSessaoPorEmail(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessaoPorCodigoExcursao.

class ComandoDescadastrarSessaoPorCodigoExcursao:public ComandoSQL {
    public:
        ComandoDescadastrarSessaoPorCodigoExcursao(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessaoDeExcursaoDeUsuario.

class ComandoDescadastrarSessaoDeExcursaoDeUsuario:public ComandoSQL {
    public:
        ComandoDescadastrarSessaoDeExcursaoDeUsuario(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoContarEntidade.

class ComandoContarEntidade:public ComandoSQL {
public:
        ComandoContarEntidade(string, string, string);
        int getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoContarEntidadeDuplo.

class ComandoContarEntidadeDuplo:public ComandoSQL {
public:
        ComandoContarEntidadeDuplo(string, string, string, string, string, string);
        int getResultado();
};

// Método que checa se usuário está cadastrado no programa.

bool checarUsuarioCadastrado(Email);

//--------------------------------------------------------------------------------------------
// Classes controladoras da camada de serviços.

//--------------------------------------------------------------------------------------------
// Classe controladora de serviço autenticaçăo.

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe controladora de serviço pessoal.

class CntrServicoConta:public IServicoConta{
    public:
        bool cadastrarUsuario(Usuario);
        bool descadastrarUsuario(Email);
        bool editarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------
// Classe controladora de serviço excursao.

class CntrServicoExcursao:public IServicoExcursao{
    private:
        static const string INVALIDO;

        Codigo gerarCodigo();
        bool codigoValido(string, Codigo);
        Codigo gerarCodigoValido(string);

        bool validarAvaliacaoCadastro(Avaliacao, Codigo);

    public:
        virtual bool cadastrarExcursao(Excursao, Email);
        virtual bool consultarExcursao(Excursao*, Email*);
        virtual bool descadastrarExcursao(Codigo, Email);
        virtual bool listarExcursao(list<Excursao>*);
        virtual bool editarExcursao(Excursao, Email);

        virtual bool cadastrarAvaliacao(Avaliacao, Email, Codigo);
        virtual bool consultarAvaliacao(Email, Avaliacao*, Email*, Codigo*);
        virtual bool descadastrarAvaliacao(Codigo, Email);
        virtual bool listarAvaliacao(Email, list<Avaliacao>*, list<Codigo>*);
        virtual bool editarAvaliacao(Avaliacao);

        virtual bool cadastrarSessao(Sessao, Email, Codigo);
        virtual bool consultarSessao(Email, Sessao*, Email*, Codigo*);
        virtual bool descadastrarSessao(Codigo, Email);
        virtual bool listarSessao(Email, list<Sessao>*, list<Codigo>*);
        virtual bool editarSessao(Sessao);

};

#endif // CONTROLADORASSERVICO_H_INCLUDED
