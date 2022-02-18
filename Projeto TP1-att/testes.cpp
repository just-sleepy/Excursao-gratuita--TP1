#include "testes.h"

// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade.
//Matricula: 202021749
// Felipe Dantas Borges
//Email
void TUEmail::setUp(){
    email = new Email();
    estado = SUCESSO;
}

void TUEmail::tearDown(){
    delete email;
}

void TUEmail::testarCenarioSucesso(){
    try{
        email->setValor(VALOR_VALIDO);
        if (email->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUEmail::testarCenarioFalha(){
    try{
        email->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (email->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUEmail::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
////Matricula: 202021749
// Felipe Dantas Borges
//Data
void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioSucesso(){
    try{
        data->setValor(VALOR_VALIDO);
        if (data->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUData::testarCenarioFalha(){
    try{
        data->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (data->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUData::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
////Matricula: 202021749
// Felipe Dantas Borges
//Endereco
void TUEndereco::setUp(){
    endereco = new Endereco();
    estado = SUCESSO;
}

void TUEndereco::tearDown(){
    delete endereco;
}

void TUEndereco::testarCenarioSucesso(){
    try{
        endereco->setValor(VALOR_VALIDO);
        if (endereco->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUEndereco::testarCenarioFalha(){
    try{
        endereco->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (endereco->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUEndereco::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
////Matricula: 202021749
// Felipe Dantas Borges
//Titulo
void TUTitulo::setUp(){
    titulo = new Titulo();
    estado = SUCESSO;
}

void TUTitulo::tearDown(){
    delete titulo;
}

void TUTitulo::testarCenarioSucesso(){
    try{
        titulo->setValor(VALOR_VALIDO);
        if (titulo->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUTitulo::testarCenarioFalha(){
    try{
        titulo->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (titulo->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUTitulo::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Cidade:

void TUCidade::setUp(){
    cidade = new Cidade();
    estado = SUCESSO;
}

void TUCidade::tearDown(){
    delete cidade;
}

void TUCidade::testarCenarioSucesso(){
    try{
        cidade->setValor(VALOR_VALIDO);
        if (cidade->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCidade::testarCenarioFalha(){
    try{
        cidade->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (cidade->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCidade::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Codigo:

void TUCodigo::setUp(){
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown(){
    delete codigo;
}

void TUCodigo::testarCenarioSucesso(){
    try{
        codigo->setValor(VALOR_VALIDO);
        if (codigo->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioFalha(){
    try{
        codigo->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (codigo->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCodigo::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Horario:

void TUHorario::setUp(){
    horario = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown(){
    delete horario;
}

void TUHorario::testarCenarioSucesso(){
    try{
        horario->setValor(VALOR_VALIDO);
        if (horario->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUHorario::testarCenarioFalha(){
    try{
        horario->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (horario->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUHorario::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Senha:

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try{
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha(){
    try{
        senha->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Nome:

void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioSucesso(){
    try{
        nome->setValor(VALOR_VALIDO);
        if (nome->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalha(){
    try{
        nome->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (nome->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUNome::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
