// Diretivas de compilação para controlar processo de inclusão.

#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

// Incluir cabeçalhos.

#include "entidades.h"

using namespace std;

// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Email:
class TUEmail {
private:
    const string VALOR_VALIDO   = "naruto2002&~@fmail12";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "naruto2002@..fmail12&~";   // Definição de constante para evitar número mágico.
    Email *email;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Data:

class TUData {
private:
    const string VALOR_VALIDO   = "13-Abr-2002";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "30-Fev-1999";   // Definição de constante para evitar número mágico.
    Data *data;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Endereco:

class TUEndereco {
private:
    const string VALOR_VALIDO   = "QTLP.214";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "QTLP..2144545435447I9s";   // Definição de constante para evitar número mágico.
    Endereco *endereco;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
////Matricula: 202021749
// Felipe Dantas Borges

// Titulo:

class TUTitulo {
private:
    const string VALOR_VALIDO   = "Yosemite";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "Yo..s3mite";   // Definição de constante para evitar número mágico.
    Titulo *titulo;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Cidade:

class TUCidade {
private:
    const string VALOR_VALIDO   = "Hong Kong";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "Brasil";   // Definição de constante para evitar número mágico.
    Cidade *cidade;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Codigo:

class TUCodigo {
private:
    const string VALOR_VALIDO   = "0000011";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "0000017";   // Definição de constante para evitar número mágico.
    Codigo *codigo;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Horario:

class TUHorario {
private:
    const string VALOR_VALIDO   = "23:58";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "24:68";   // Definição de constante para evitar número mágico.
    Horario *horario;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Senha:

class TUSenha {
private:
    const string VALOR_VALIDO   = "Ba34dy";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "AAAAAA";   // Definição de constante para evitar número mágico.
    Senha *senha;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Nome:

class TUNome {
private:
    const string VALOR_VALIDO   = "Mr. Dal";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "Mr  .Dal";   // Definição de constante para evitar número mágico.
    Nome *nome;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
class TUIdioma {
private:
    const string VALOR_VALIDO   = "Ingles";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "Blablabla";   // Definição de constante para evitar número mágico.
    Idioma *idioma;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
class TUNota {
private:
    const int VALOR_VALIDO   = 0;   // Definição de constante para evitar número mágico.
    const int VALOR_INVALIDO = 7;   // Definição de constante para evitar número mágico.
    Nota *nota;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};
//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
class TUDuracao {
private:
    const int VALOR_VALIDO   = 30;   // Definição de constante para evitar número mágico.
    const int VALOR_INVALIDO = 0;   // Definição de constante para evitar número mágico.
    Duracao *duracao;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};
//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
class TUDescricao {
private:
    const string VALOR_VALIDO   = "Teste";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "tes.. te";   // Definição de constante para evitar número mágico.
    Descricao *descricao;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
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
    Sessao *sessao;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.

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
    Excursao *excursao;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.

};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
// ENTIDADE Avaliacao:
class TUAvaliacao {
private:
    const string VALOR_VALIDO_CODIGO  = "0000011";
    const int VALOR_VALIDO_NOTA    = 4;
    const string VALOR_VALIDO_DESCRICAO = "TESTE";

    Avaliacao *avaliacao;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.

};

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
// ENTIDADE Avaliacao:
class TUUsuario {
private:
    const string VALOR_VALIDO_NOME  = "Rafael";
    const string VALOR_VALIDO_EMAIL = "partelocal@dominio";
    const string VALOR_VALIDO_SENHA = "Senha1";

    Usuario *usuario;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.

};

#endif // TESTES_H_INCLUDED
