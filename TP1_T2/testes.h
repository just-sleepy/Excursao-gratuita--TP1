// Diretivas de compila��o para controlar processo de inclus�o.

#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

// Incluir cabe�alhos.

#include "entidades.h"

using namespace std;

// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Email:
class TUEmail {
private:
    const string VALOR_VALIDO   = "naruto2002&~@fmail12";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "naruto2002@..fmail12&~";   // Defini��o de constante para evitar n�mero m�gico.
    Email *email;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Data:

class TUData {
private:
    const string VALOR_VALIDO   = "13-Abr-2002";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "30-Fev-1999";   // Defini��o de constante para evitar n�mero m�gico.
    Data *data;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Endereco:

class TUEndereco {
private:
    const string VALOR_VALIDO   = "QTLP.214";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "QTLP..2144545435447I9s";   // Defini��o de constante para evitar n�mero m�gico.
    Endereco *endereco;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
////Matricula: 202021749
// Felipe Dantas Borges

// Titulo:

class TUTitulo {
private:
    const string VALOR_VALIDO   = "Yosemite";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "Yo..s3mite";   // Defini��o de constante para evitar n�mero m�gico.
    Titulo *titulo;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Cidade:

class TUCidade {
private:
    const string VALOR_VALIDO   = "Hong Kong";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "Brasil";   // Defini��o de constante para evitar n�mero m�gico.
    Cidade *cidade;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Codigo:

class TUCodigo {
private:
    const string VALOR_VALIDO   = "0000011";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "0000017";   // Defini��o de constante para evitar n�mero m�gico.
    Codigo *codigo;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Horario:

class TUHorario {
private:
    const string VALOR_VALIDO   = "23:58";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "24:68";   // Defini��o de constante para evitar n�mero m�gico.
    Horario *horario;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Senha:

class TUSenha {
private:
    const string VALOR_VALIDO   = "Ba34dy";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "AAAAAA";   // Defini��o de constante para evitar n�mero m�gico.
    Senha *senha;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Nome:

class TUNome {
private:
    const string VALOR_VALIDO   = "Mr. Dal";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "Mr  .Dal";   // Defini��o de constante para evitar n�mero m�gico.
    Nome *nome;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Ham� Campos
class TUIdioma {
private:
    const string VALOR_VALIDO   = "Ingles";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "Blablabla";   // Defini��o de constante para evitar n�mero m�gico.
    Idioma *idioma;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Ham� Campos
class TUNota {
private:
    const int VALOR_VALIDO   = 0;   // Defini��o de constante para evitar n�mero m�gico.
    const int VALOR_INVALIDO = 7;   // Defini��o de constante para evitar n�mero m�gico.
    Nota *nota;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};
//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Ham� Campos
class TUDuracao {
private:
    const int VALOR_VALIDO   = 30;   // Defini��o de constante para evitar n�mero m�gico.
    const int VALOR_INVALIDO = 0;   // Defini��o de constante para evitar n�mero m�gico.
    Duracao *duracao;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};
//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Ham� Campos
class TUDescricao {
private:
    const string VALOR_VALIDO   = "Teste";   // Defini��o de constante para evitar n�mero m�gico.
    const string VALOR_INVALIDO = "tes.. te";   // Defini��o de constante para evitar n�mero m�gico.
    Descricao *descricao;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.
    void testarCenarioFalha();              // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.
};









//ENTIDADE----------------------------------------------------------------------------------
// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// ENTIDADE Sessao:
class TUSessao {
private:
    const string VALOR_VALIDO_CODIGO  = "0000011";
    const string VALOR_VALIDO_DATA    = "13-Abr-2002";
    const string VALOR_VALIDO_HORARIO = "23:58";
    const string VALOR_VALIDO_IDIOMA  = "Ingles";
    Sessao *sessao;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.

};

// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Excursao:

class TUExcursao {
private:
    const string VALOR_VALIDO_CODIGO  = "0000011";
    const string VALOR_VALIDO_TITULO= "Yosemite";
    const int VALOR_VALIDO_NOTA   = 4;
    const string VALOR_VALIDO_CIDADE   = "Hong Kong";
    const int VALOR_VALIDO_DURACAO  = 60;
    const string VALOR_VALIDO_DESCRICAO   = "maneiro";
    const string VALOR_VALIDO_ENDERECO   = "QTLP.214";
    Excursao *excursao;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.

};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Ham� Campos
// ENTIDADE Avaliacao:
class TUAvaliacao {
private:
    const string VALOR_VALIDO_CODIGO  = "0000011";
    const int VALOR_VALIDO_NOTA    = 4;
    const string VALOR_VALIDO_DESCRICAO = "TESTE";

    Avaliacao *avaliacao;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.

};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Ham� Campos
// ENTIDADE Avaliacao:
class TUUsuario {
private:
    const string VALOR_VALIDO_NOME  = "Rafael";
    const string VALOR_VALIDO_EMAIL = "partelocal@dominio";
    const string VALOR_VALIDO_SENHA = "Senha1";

    Usuario *usuario;                         // Refer�ncia para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // M�todo para criar unidade em teste.
    void tearDown();                        // M�todo para destruir unidade em teste.
    void testarCenarioSucesso();            // Cen�rio de teste.

public:
    const static int SUCESSO =  0;          // Defini��o de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Defini��o de constante para reportar resultado de teste.
    int run();                              // M�todo para executar teste.

};

#endif // TESTES_H_INCLUDED
