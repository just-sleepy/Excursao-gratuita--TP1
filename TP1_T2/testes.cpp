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


// --------------------------------------------------------------------------
//Matricula: 20206448
// Rafael Hamu Campos
//Nota
void TUNota::setUp(){
    nota = new Nota();
    estado = SUCESSO;
}

void TUNota::tearDown(){
    delete nota;
}

void TUNota::testarCenarioSucesso(){
    try{
        nota->setValor(VALOR_VALIDO);
        if (nota->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUNota::testarCenarioFalha(){
    try{
        nota->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (nota->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUNota::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
//Matricula: 20206448
// Rafael Hamu Campos
//Idioma
void TUIdioma::setUp(){
    idioma = new Idioma();
    estado = SUCESSO;
}

void TUIdioma::tearDown(){
    delete idioma;
}

void TUIdioma::testarCenarioSucesso(){
    try{
        idioma->setValor(VALOR_VALIDO);
        if (idioma->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUIdioma::testarCenarioFalha(){
    try{
        idioma->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (idioma->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUIdioma::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
// --------------------------------------------------------------------------
//Matricula: 20206448
// Rafael Hamu Campos
//Duracao
void TUDuracao::setUp(){
    duracao = new Duracao();
    estado = SUCESSO;
}

void TUDuracao::tearDown(){
    delete duracao;
}

void TUDuracao::testarCenarioSucesso(){
    try{
        duracao->setValor(VALOR_VALIDO);
        if (duracao->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUDuracao::testarCenarioFalha(){
    try{
        duracao->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (duracao->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUDuracao::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
// --------------------------------------------------------------------------
//Matricula: 20206448
// Rafael Hamu Campos
//Descricao
void TUDescricao::setUp(){
    descricao = new Descricao();
    estado = SUCESSO;
}

void TUDescricao::tearDown(){
    delete descricao;
}

void TUDescricao::testarCenarioSucesso(){
    try{
        descricao->setValor(VALOR_VALIDO);
        if (descricao->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUDescricao::testarCenarioFalha(){
    try{
        descricao->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (descricao->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUDescricao::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}










//Entidade------------------------------------------------------------------------
// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// ENTIDADE Sessao:

void TUSessao::setUp(){
    sessao = new Sessao();
    estado = SUCESSO;
}

void TUSessao::tearDown(){
    delete sessao;
}

void TUSessao::testarCenarioSucesso(){
    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;

    try{
        codigo.setValor(VALOR_VALIDO_CODIGO);
        data.setValor(VALOR_VALIDO_DATA);
        horario.setValor(VALOR_VALIDO_HORARIO);
        idioma.setValor(VALOR_VALIDO_IDIOMA);

        sessao->setCodigo(codigo);
        sessao->setData(data);
        sessao->setHorario(horario);
        sessao->setIdioma(idioma);


        if (sessao->getCodigo().getValor() != VALOR_VALIDO_CODIGO && sessao->getData().getValor() != VALOR_VALIDO_DATA &&
            sessao->getHorario().getValor() != VALOR_VALIDO_HORARIO && sessao->getIdioma().getValor() != VALOR_VALIDO_IDIOMA)
            estado = FALHA;
    }

    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int TUSessao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// ENTIDADE Excursao:

void TUExcursao::setUp(){
    excursao = new Excursao();
    estado = SUCESSO;
}

void TUExcursao::tearDown(){
    delete excursao;
}

void TUExcursao::testarCenarioSucesso(){
    Codigo codigo;
    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;

    try{
        codigo.setValor(VALOR_VALIDO_CODIGO);
        titulo.setValor(VALOR_VALIDO_TITULO);
        nota.setValor(VALOR_VALIDO_NOTA);
        cidade.setValor(VALOR_VALIDO_CIDADE);
        duracao.setValor(VALOR_VALIDO_DURACAO);
        descricao.setValor(VALOR_VALIDO_DESCRICAO);
        endereco.setValor(VALOR_VALIDO_ENDERECO);


        excursao->setCodigo(codigo);
        excursao->setTitulo(titulo);
        excursao->setNota(nota);
        excursao->setCidade(cidade);
        excursao->setDuracao(duracao);
        excursao->setDescricao(descricao);
        excursao->setEndereco(endereco);

        if (excursao->getCodigo().getValor() != VALOR_VALIDO_CODIGO && excursao->getTitulo().getValor() != VALOR_VALIDO_TITULO &&
            excursao->getNota().getValor() != VALOR_VALIDO_NOTA && excursao->getCidade().getValor() != VALOR_VALIDO_CIDADE &&
            excursao->getDuracao().getValor() != VALOR_VALIDO_DURACAO && excursao->getDescricao().getValor() != VALOR_VALIDO_DESCRICAO &&
            excursao->getEndereco().getValor() != VALOR_VALIDO_ENDERECO)
            estado = FALHA;
    }

    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int TUExcursao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

// ENTIDADE Usuario:
//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos

void TUUsuario::setUp(){
    usuario = new Usuario();
    estado = SUCESSO;
}

void TUUsuario::tearDown(){
    delete usuario;
}

void TUUsuario::testarCenarioSucesso(){
    Nome nome;
    Email email;
    Senha senha;

    try{
        nome.setValor(VALOR_VALIDO_NOME);
        email.setValor(VALOR_VALIDO_EMAIL);
        senha.setValor(VALOR_VALIDO_SENHA);

        usuario->setNome(nome);
        usuario->setEmail(email);
        usuario->setSenha(senha);



        if (usuario->getSenha().getValor() != VALOR_VALIDO_SENHA && usuario->getEmail().getValor() != VALOR_VALIDO_EMAIL &&
            usuario->getSenha().getValor() != VALOR_VALIDO_SENHA)
            estado = FALHA;
    }

    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int TUUsuario::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

// ENTIDADE Avaliacao:
//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos

void TUAvaliacao::setUp(){
    avaliacao = new Avaliacao();
    estado = SUCESSO;
}

void TUAvaliacao::tearDown(){
    delete avaliacao;
}

void TUAvaliacao::testarCenarioSucesso(){
    Codigo codigo;
    Nota nota;
    Descricao descricao;

    try{
        codigo.setValor(VALOR_VALIDO_CODIGO);
        nota.setValor(VALOR_VALIDO_NOTA);
        descricao.setValor(VALOR_VALIDO_DESCRICAO);


        avaliacao->setCodigo(codigo);
        avaliacao->setNota(nota);
        avaliacao->setDescricao(descricao);


        if (avaliacao->getCodigo().getValor() != VALOR_VALIDO_CODIGO && avaliacao->getNota().getValor() != VALOR_VALIDO_NOTA && avaliacao->getDescricao().getValor() != VALOR_VALIDO_DESCRICAO)
            estado = FALHA;
    }

    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

int TUAvaliacao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
