#include "controladorasservico.h"

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
//Classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

//---------------------------------------------------------------------------
//Classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

//---------------------------------------------------------------------------
//Classe ComandoSQL.

void ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }
        desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(Email email) {
        comandoSQL = "SELECT senha FROM usuarios WHERE email = '";
        comandoSQL += email.getValor();
        comandoSQL += "'";
}

string ComandoLerSenha::getResultado() {
        ElementoResultado resultado;
        string senha;

        //Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario) {
        comandoSQL = "INSERT INTO usuarios VALUES (";
        comandoSQL += "'" + usuario.getNome().getValor() + "', ";
        comandoSQL += "'" + usuario.getEmail().getValor() + "', ";
        comandoSQL += "'" + usuario.getSenha().getValor() + "', ";
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarUsuario.

ComandoDescadastrarUsuario::ComandoDescadastrarUsuario(Email email) {
        comandoSQL = "DELETE FROM usuarios WHERE email = '";
        comandoSQL += email.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoEditarUsuario.

ComandoEditarUsuario::ComandoEditarUsuario(Usuario usuario) {
        comandoSQL = "UPDATE usuarios ";
        comandoSQL += "SET nome = '" + usuario.getNome().getValor();
        comandoSQL += "', senha = '" + usuario.getSenha().getValor();
        comandoSQL += "' WHERE email = '" + usuario.getEmail().getValor() + "'";
}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarExcursao.

ComandoCadastrarExcursao::ComandoCadastrarExcursao(Excursao excursao, Email email) {

        comandoSQL = "INSERT INTO excursao VALUES (";
        comandoSQL += "'" + excursao.getCodigo().getValor() + "', ";
        comandoSQL += "'" + excursao.getTitulo().getValor() + "', ";
        comandoSQL += "'" + to_string(excursao.getNota().getValor()) + "', ";
        comandoSQL += "'" + excursao.getCidade().getValor() + "', ";
        comandoSQL += "'" + to_string(excursao.getDuracao().getValor()) + "', ";
        comandoSQL += "'" + excursao.getDescricao().getValor() + "', ";
        comandoSQL += "'" + excursao.getEndereco().getValor() + "', ";
        comandoSQL += "'" + email.getValor() + "')";
}

//---------------------------------------------------------------------------
//Classe ComandoLerEmailExcursao.

ComandoLerEmailExcursao::ComandoLerEmailExcursao(Codigo codigo) {
        comandoSQL = "SELECT email FROM excursao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

string ComandoLerEmailExcursao::getResultado() {
        ElementoResultado resultado;
        string email;

        //Remover email;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        email = resultado.getValorColuna();

        return email;
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarExcursao.

ComandoDescadastrarExcursao::ComandoDescadastrarExcursao(Codigo codigo) {
        comandoSQL = "DELETE FROM excursao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoListarExcursao.

ComandoListarExcursao::ComandoListarExcursao() {
        comandoSQL = "SELECT * FROM excursao";
}

list<Excursao> ComandoListarExcursao::getResultado(list<Email>* listaEmails) {
        ElementoResultado resultado;
        Excursao excursao;
        list<Excursao> listaExcursao;

        Codigo codigoExcursao;
        Titulo tituloExcursao;
        Nota notaExcursao;
        Cidade cidadeExcursao;
        Duracao duracaoExcursao;
        Descricao descricaoExcursao;
        Endereco enderecoExcursao;

        Email emailUsuario;

        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");

        while (!listaResultado.empty()){
            resultado = listaResultado.back();
            listaResultado.pop_back();
            codigoExcursao.setValor(resultado.getValorColuna());
            excursao.setCodigo(codigoExcursao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            tituloExcursao.setValor(resultado.getValorColuna());
            excursao.setTitulo(tituloExcursao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            notaExcursao.setValor(stoi(resultado.getValorColuna()));
            excursao.setNota(notaExcursao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            cidadeExcursao.setValor(resultado.getValorColuna());
            excursao.setCidade(cidadeExcursao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            duracaoExcursao.setValor(stoi(resultado.getValorColuna()));
            excursao.setDuracao(duracaoExcursao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            descricaoExcursao.setValor(resultado.getValorColuna());
            excursao.setDescricao(descricaoExcursao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            enderecoExcursao.setValor(resultado.getValorColuna());
            excursao.setEndereco(enderecoExcursao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            emailUsuario.setValor(resultado.getValorColuna());

            listaExcursao.push_back(excursao);
            listaEmails->push_back(emailUsuario);
        }

        return listaExcursao;
}

//---------------------------------------------------------------------------
//Classe ComandoEditarExcursao.

ComandoEditarExcursao::ComandoEditarExcursao(Excursao excursao) {
        comandoSQL = "UPDATE excursao ";
        comandoSQL += "SET titulo = '" + excursao.getTitulo().getValor();
        comandoSQL += "', nota = '" + to_string(excursao.getNota().getValor());
        comandoSQL += "', cidade = '" + excursao.getCidade().getValor();
        comandoSQL += "', duracao = '" + to_string(excursao.getDuracao().getValor());
        comandoSQL += "', descricao = '" + excursao.getDescricao().getValor();
        comandoSQL += "', endereco = '" + excursao.getEndereco().getValor();
        comandoSQL += "' WHERE codigo = '" + excursao.getCodigo().getValor();
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarExcursaoPorEmail.

ComandoDescadastrarExcursaoPorEmail::ComandoDescadastrarExcursaoPorEmail(Email email) {
        comandoSQL = "DELETE FROM excursao WHERE email = '";
        comandoSQL += email.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarExcursao.

ComandoPesquisarExcursao::ComandoPesquisarExcursao(Codigo codigo) {
        comandoSQL = "SELECT * FROM excursao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

Excursao ComandoPesquisarExcursao::getResultado(Email* emailUsuario) {
        ElementoResultado resultado;
        Excursao excursao;

        Codigo codigo;
        Titulo titulo;
        Nota nota;
        Cidade cidade;
        Duracao duracao;
        Descricao descricao;
        Endereco endereco;
        Email email;

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setValor(resultado.getValorColuna());
        excursao.setCodigo(codigo);

        // Remover titulo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        titulo.setValor(resultado.getValorColuna());
        excursao.setTitulo(titulo);

        // Remover nota;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nota.setValor(stoi(resultado.getValorColuna()));
        excursao.setNota(nota);

        // Remover cidade;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        cidade.setValor(resultado.getValorColuna());
        excursao.setCidade(cidade);

        // Remover duracao;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        duracao.setValor(stoi(resultado.getValorColuna()));
        excursao.setDuracao(duracao);

        // Remover descricao;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        descricao.setValor(resultado.getValorColuna());
        excursao.setDescricao(descricao);

        // Remover endereco;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        endereco.setValor(resultado.getValorColuna());
        excursao.setEndereco(endereco);

        // Remover email
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        emailUsuario->setValor(resultado.getValorColuna());

        return excursao;
}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarAvaliacao.

ComandoCadastrarAvaliacao::ComandoCadastrarAvaliacao(Avaliacao avaliacao, Email email, Codigo codigo) {

        comandoSQL = "INSERT INTO avaliacao VALUES (";
        comandoSQL += "'" + avaliacao.getCodigo().getValor() + "', ";
        comandoSQL += "'" + to_string(avaliacao.getNota().getValor()) + "', ";
        comandoSQL += "'" + avaliacao.getDescricao().getValor() + "', ";
        comandoSQL += "'" + email.getValor() + "', ";
        comandoSQL += "'" + codigo.getValor() + "')";
}

//---------------------------------------------------------------------------
//Classe ComandoLerEmailAvaliacao.

ComandoLerEmailAvaliacao::ComandoLerEmailAvaliacao(Codigo codigo) {
        comandoSQL = "SELECT email FROM avaliacao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

string ComandoLerEmailAvaliacao::getResultado() {
        ElementoResultado resultado;
        string email;

        //Remover email;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        email = resultado.getValorColuna();

        return email;
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacao.

ComandoDescadastrarAvaliacao::ComandoDescadastrarAvaliacao(Codigo codigo) {
        comandoSQL = "DELETE FROM avaliacao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAvaliacao.

ComandoPesquisarAvaliacao::ComandoPesquisarAvaliacao(Codigo codigo) {
        comandoSQL = "SELECT * FROM avaliacao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

Avaliacao ComandoPesquisarAvaliacao::getResultado(Email* emailUsuario, Codigo* codigoExcursao) {
        ElementoResultado resultado;
        Avaliacao avaliacao;

        Codigo codigo;
        Nota nota;
        Descricao descricao;

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setValor(resultado.getValorColuna());
        avaliacao.setCodigo(codigo);

        // Remover nota;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nota.setValor(stoi(resultado.getValorColuna()));
        avaliacao.setNota(nota);

        // Remover descricao;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        descricao.setValor(resultado.getValorColuna());
        avaliacao.setDescricao(descricao);

        // Remover email
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        emailUsuario->setValor(resultado.getValorColuna());

        // Remover codigo_excursao
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigoExcursao->setValor(resultado.getValorColuna());

        return avaliacao;
}

//---------------------------------------------------------------------------
//Classe ComandoListarAvaliacao.

ComandoListarAvaliacao::ComandoListarAvaliacao() {
        comandoSQL = "SELECT * FROM avaliacao";
}

list<Avaliacao> ComandoListarAvaliacao::getResultado(list<Codigo>* listaCodigos, list<Email>* listaEmails) {
        ElementoResultado resultado;
        Avaliacao avaliacao;
        list<Avaliacao> listaAvaliacao;

        Codigo codigoAvaliacao;
        Nota notaAvaliacao;
        Descricao descricaoAvaliacao;

        Codigo codigoExcursao;
        Email emailUsuario;

        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");

        while (!listaResultado.empty()){
            resultado = listaResultado.back();
            listaResultado.pop_back();
            codigoAvaliacao.setValor(resultado.getValorColuna());
            avaliacao.setCodigo(codigoAvaliacao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            notaAvaliacao.setValor(stoi(resultado.getValorColuna()));
            avaliacao.setNota(notaAvaliacao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            descricaoAvaliacao.setValor(resultado.getValorColuna());
            avaliacao.setDescricao(descricaoAvaliacao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            emailUsuario.setValor(resultado.getValorColuna());

            resultado = listaResultado.back();
            listaResultado.pop_back();
            codigoExcursao.setValor(resultado.getValorColuna());

            listaAvaliacao.push_back(avaliacao);
            listaEmails->push_back(emailUsuario);
            listaCodigos->push_back(codigoExcursao);
        }

        return listaAvaliacao;
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacaoPorEmail.

ComandoDescadastrarAvaliacaoPorEmail::ComandoDescadastrarAvaliacaoPorEmail(Email email) {
        comandoSQL = "DELETE FROM avaliacao WHERE email = '";
        comandoSQL += email.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacaoPorCodigoExcursao.

ComandoDescadastrarAvaliacaoPorCodigoExcursao::ComandoDescadastrarAvaliacaoPorCodigoExcursao(Codigo codigo) {
        comandoSQL = "DELETE FROM avaliacao WHERE codigo_excursao = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAvaliacaoDeExcursaoDeUsuario.

ComandoDescadastrarAvaliacaoDeExcursaoDeUsuario::ComandoDescadastrarAvaliacaoDeExcursaoDeUsuario(Email email) {
        comandoSQL = "DELETE FROM avaliacao WHERE codigo IN ";
        comandoSQL += "(SELECT codigo FROM (SELECT avaliacao.codigo, excursao.email ";
        comandoSQL += "FROM avaliacao, excursao ";
        comandoSQL += "WHERE avaliacao.codigo_excursao = excursao.codigo) WHERE email = '";
        comandoSQL += email.getValor();
        comandoSQL += "')";
}
//---------------------------------------------------------------------------
//Classe ComandoCadastrarSessao.

ComandoCadastrarSessao::ComandoCadastrarSessao(Sessao sessao, Email email, Codigo codigo) {

        comandoSQL = "INSERT INTO sessao VALUES (";
        comandoSQL += "'" + sessao.getCodigo().getValor() + "', ";
        comandoSQL += "'" + sessao.getData().getValor() + "', ";
        comandoSQL += "'" + sessao.getHorario().getValor() + "', ";
        comandoSQL += "'" + sessao.getIdioma().getValor() + "', ";
        comandoSQL += "'" + email.getValor() + "', ";
        comandoSQL += "'" + codigo.getValor() + "')";
}

//---------------------------------------------------------------------------
//Classe ComandoLerEmailSessao.

ComandoLerEmailSessao::ComandoLerEmailSessao(Codigo codigo) {
        comandoSQL = "SELECT email FROM sessao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

string ComandoLerEmailSessao::getResultado() {
        ElementoResultado resultado;
        string email;

        //Remover email;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        email = resultado.getValorColuna();

        return email;
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessao.

ComandoDescadastrarSessao::ComandoDescadastrarSessao(Codigo codigo) {
        comandoSQL = "DELETE FROM sessao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarSessao.

ComandoPesquisarSessao::ComandoPesquisarSessao(Codigo codigo) {
        comandoSQL = "SELECT * FROM sessao WHERE codigo = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

Sessao ComandoPesquisarSessao::getResultado(Email* emailUsuario, Codigo* codigoExcursao) {
        ElementoResultado resultado;
        Sessao sessao;

        Codigo codigo;
        Data data;
        Horario horario;
        Idioma idioma;

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setValor(resultado.getValorColuna());
        sessao.setCodigo(codigo);

        // Remover data;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        data.setValor(resultado.getValorColuna());
        sessao.setData(data);

        // Remover horario;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        horario.setValor(resultado.getValorColuna());
        sessao.setHorario(horario);

        // Remover idioma;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        idioma.setValor(resultado.getValorColuna());
        sessao.setIdioma(idioma);

        // Remover email
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        emailUsuario->setValor(resultado.getValorColuna());

        // Remover codigo_excursao
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigoExcursao->setValor(resultado.getValorColuna());

        return sessao;
}

//---------------------------------------------------------------------------
//Classe ComandoListarSessao.

ComandoListarSessao::ComandoListarSessao() {
        comandoSQL = "SELECT * FROM sessao";
}

list<Sessao> ComandoListarSessao::getResultado(list<Codigo>* listaCodigos, list<Email>* listaEmails) {
        ElementoResultado resultado;
        Sessao sessao;
        list<Sessao> listaSessao;

        Codigo codigoSessao;
        Data dataSessao;
        Horario horarioSessao;
        Idioma idiomaSessao;

        Codigo codigoExcursao;
        Email emailUsuario;

        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");

        while (!listaResultado.empty()){
            resultado = listaResultado.back();
            listaResultado.pop_back();
            codigoSessao.setValor(resultado.getValorColuna());
            sessao.setCodigo(codigoSessao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            dataSessao.setValor(resultado.getValorColuna());
            sessao.setData(dataSessao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            horarioSessao.setValor(resultado.getValorColuna());
            sessao.setHorario(horarioSessao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            idiomaSessao.setValor(resultado.getValorColuna());
            sessao.setIdioma(idiomaSessao);

            resultado = listaResultado.back();
            listaResultado.pop_back();
            emailUsuario.setValor(resultado.getValorColuna());

            resultado = listaResultado.back();
            listaResultado.pop_back();
            codigoExcursao.setValor(resultado.getValorColuna());

            listaSessao.push_back(sessao);
            listaEmails->push_back(emailUsuario);
            listaCodigos->push_back(codigoExcursao);
        }

        return listaSessao;
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessaoPorEmail.

ComandoDescadastrarSessaoPorEmail::ComandoDescadastrarSessaoPorEmail(Email email) {
        comandoSQL = "DELETE FROM sessao WHERE email = '";
        comandoSQL += email.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessaoPorCodigoExcursao.

ComandoDescadastrarSessaoPorCodigoExcursao::ComandoDescadastrarSessaoPorCodigoExcursao(Codigo codigo) {
        comandoSQL = "DELETE FROM sessao WHERE codigo_excursao = '";
        comandoSQL += codigo.getValor();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarSessaoDeExcursaoDeUsuario.

ComandoDescadastrarSessaoDeExcursaoDeUsuario::ComandoDescadastrarSessaoDeExcursaoDeUsuario(Email email) {
        comandoSQL = "DELETE FROM sessao WHERE codigo IN ";
        comandoSQL += "(SELECT codigo FROM (SELECT sessao.codigo, excursao.email ";
        comandoSQL += "FROM sessao, excursao ";
        comandoSQL += "WHERE sessao.codigo_excursao = excursao.codigo) WHERE email = '";
        comandoSQL += email.getValor();
        comandoSQL += "')";
}

//---------------------------------------------------------------------------
//Classe ComandoContarEntidade.

ComandoContarEntidade::ComandoContarEntidade(string entidade, string chave, string instancia) {
        comandoSQL = "SELECT count(";
        comandoSQL += chave;
        comandoSQL += ") FROM ";
        comandoSQL += entidade;
        comandoSQL += " WHERE ";
        comandoSQL += chave;
        comandoSQL += " = '";
        comandoSQL += instancia;
        comandoSQL += "' GROUP by ";
        comandoSQL += chave;
}

int ComandoContarEntidade::getResultado() {
        string contagem;
        ElementoResultado resultado;

        // Remover matricula;
        if (listaResultado.empty())
                return 0;

        resultado = listaResultado.back();
        listaResultado.pop_back();
        contagem = resultado.getValorColuna();

        return stoi(contagem);
}

//---------------------------------------------------------------------------
//Classe ComandoContarEntidadeDuplo.

ComandoContarEntidadeDuplo::ComandoContarEntidadeDuplo(string entidade, string chaveBase, string chaveUm, string chaveDois, string instanciaUm, string instanciaDois) {
        // ChaveBase é a chave que será contada.
        // ChaveUm será filtrada a partir de instanciaUm, e o mesmo para chaveDois e instanciaDois.

        comandoSQL = "SELECT count(";
        comandoSQL += chaveBase;
        comandoSQL += ") FROM ";
        comandoSQL += entidade;
        comandoSQL += " WHERE ";
        comandoSQL += chaveUm;
        comandoSQL += " = '";
        comandoSQL += instanciaUm;
        comandoSQL += "' AND ";
        comandoSQL += chaveDois;
        comandoSQL += " = '";
        comandoSQL += instanciaDois;
        comandoSQL += "'";
}

int ComandoContarEntidadeDuplo::getResultado() {
        string contagem;
        ElementoResultado resultado;

        // Remover matricula;
        if (listaResultado.empty())
                return 0;

        resultado = listaResultado.back();
        listaResultado.pop_back();
        contagem = resultado.getValorColuna();

        return stoi(contagem);
}

//---------------------------------------------------------------------------

bool checarUsuarioCadastrado(Email email){
    // Todo serviço que precisa de usuário cadastrado precisa chegar primeiro se o usuário está cadastrado.
    // Isso evita usuário descadastrado continuando a executar serviços.

    ComandoContarEntidade comandoContarUsuario("usuarios", "email", email.getValor());
    comandoContarUsuario.executar();

    if (comandoContarUsuario.getResultado() == 0)
        return false;

    return true;
}

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos das classes controladoras da camada de serviço.


//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora serviço autenticaçăo.

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha){

    ComandoLerSenha comandoLerSenha(email);

    try {
        comandoLerSenha.executar();

        string senhaRecuperada;

        senhaRecuperada = comandoLerSenha.getResultado();

        if (senhaRecuperada == senha.getValor())
            return true;

        return false;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora serviço conta.

bool CntrServicoConta::cadastrarUsuario(Usuario usuario){

    ComandoCadastrarUsuario comandoCadastrar(usuario);

    try{
        comandoCadastrar.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

bool CntrServicoConta::descadastrarUsuario(Email email){

    if (!checarUsuarioCadastrado(email))
        return false;

    // Ao descadastrar um usuário, é preciso descadastrar todas as avaliacoes ligadas a suas excursoes.
    ComandoDescadastrarAvaliacaoDeExcursaoDeUsuario comandoDescadastrarAvaliacaoDeExcursaoDeUsuario(email);
    comandoDescadastrarAvaliacaoDeExcursaoDeUsuario.executar();

    // Ao descadastrar um usuário, é preciso descadastrar também todas as suas excursoes.
    ComandoDescadastrarExcursaoPorEmail comandoDescadastrarExcursao(email);
    comandoDescadastrarExcursao.executar();

    // As avaliacoes veiculadas ao e-mail também são excluídas.
    ComandoDescadastrarAvaliacaoPorEmail comandoDescadastrarAvaliacao(email);
    comandoDescadastrarAvaliacao.executar();

    ComandoDescadastrarUsuario comandoDescadastrar(email);

    try{
        comandoDescadastrar.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

bool CntrServicoConta::editarUsuario(Usuario usuario){

    if (!checarUsuarioCadastrado(usuario.getEmail()))
    return false;

    ComandoEditarUsuario comandoEditarUsuario(usuario);

    try{
        comandoEditarUsuario.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora serviço excursões.

Codigo CntrServicoExcursao::gerarCodigo(){

    int digitoChar;
    string digitoAleatorio;
    string stringCodigoAleatorio = "";
    Codigo codigoAleatorio;

    for (int i = 0; i < 5; i++)
    {
        digitoChar = rand() % 2;

        if (digitoChar)
            digitoAleatorio = 'A' + rand()%26;
        else
            digitoAleatorio = to_string(rand() % 10);

        stringCodigoAleatorio += digitoAleatorio;
    }

    codigoAleatorio.setValor(stringCodigoAleatorio);

    return codigoAleatorio;
}

bool CntrServicoExcursao::codigoValido(string entidade, Codigo codigo){
    int validadeCodigo;

    ComandoContarEntidade contarCodigoEntidade(entidade, "codigo", codigo.getValor());
    contarCodigoEntidade.executar();
    validadeCodigo = contarCodigoEntidade.getResultado();

    if (validadeCodigo == 0)
        return true;
    return false;
}

Codigo CntrServicoExcursao::gerarCodigoValido(string entidade){

    Codigo codigoAleatorio;
    bool codigoValidoEncontrado = false;

    while (!codigoValidoEncontrado){
        codigoAleatorio = gerarCodigo();

        if (codigoValido(entidade, codigoAleatorio))
            codigoValidoEncontrado = true;
    }

    return codigoAleatorio;
}
/*
//int CntrServicoExcursao::compararUnidadesData(int unidadeUm, int unidadeDois)
{
    if (unidadeDois > unidadeUm)
        return 3;
    if (unidadeDois < unidadeUm)
        return 1;
    if (unidadeDois == unidadeUm)
        return 2;
}

int CntrServicoExcursao::compararDatas(Data dataUm, Data dataDois)
{
    // Checar se a dataDois é maior ou igual à dataUm.

    char delim = '-';
	int posicaoPrimeiroDelim = 2;
	int posicaoSegundoDelim = 5;

	int diaUm, mesUm, anoUm;
	int diaDois, mesDois, anoDois;

    diaUm = stoi(dataUm.getValor().substr(0, 2));
	mesUm = stoi(dataUm.getValor().substr(posicaoPrimeiroDelim + 1, 2));
	anoUm = stoi(dataUm.getValor().substr(posicaoSegundoDelim + 1, 2));

    diaDois = stoi(dataDois.getValor().substr(0, 2));
	mesDois = stoi(dataDois.getValor().substr(posicaoPrimeiroDelim + 1, 2));
	anoDois = stoi(dataDois.getValor().substr(posicaoSegundoDelim + 1, 2));

    switch (compararUnidadesData(anoUm, anoDois)){
        case 3:
            return 3;
        case 1:
            return 1;
        case 2:
            switch (compararUnidadesData(mesUm, mesDois)){
                case 3:
                    return 3;
                case 1:
                    return 1;
                case 2:
                    return compararUnidadesData(diaUm, diaDois);
            }
    }
}

bool CntrServicoImoveis::checarIntervaloDatas(Data primeiroDataUm, Data primeiroDataDois, Data segundoDataUm, Data segundoDataDois)
{
    // Considerando o primeiro como a data à qual a segunda precisa se ajustar.
    // Assim, segundoDataUm precisa ser maior ou igual a primeiroDataUm.
    // E segundoDataDois precisa ser menor ou igual a primeiroDataDois.

    if (compararDatas(primeiroDataUm, segundoDataUm) == 1)
        return false;

    if (compararDatas(primeiroDataDois, segundoDataDois) == 3)
        return false;

    return true;
}

double CntrServicoImoveis::moedaParaDouble(Moeda moeda)
{
    string valor;
    valor = moeda.getValor();

	while (valor.find(".") != string::npos)
		valor.replace(valor.find("."), 1, "");

	while (valor.find(",") != string::npos)
		valor.replace(valor.find(","), 1, ".");

    // Conversăo do valor em formato certo para double.
	return stod(valor);
}
*/
bool CntrServicoExcursao::validarAvaliacaoCadastro(Avaliacao avaliacao, Codigo codigo){
    return true;
}

bool CntrServicoExcursao::cadastrarExcursao(Excursao excursao, Email email){

    if (!checarUsuarioCadastrado(email))
        return false;

    ComandoContarEntidade comandoContarExcursao("excursao", "email", email.getValor());
    comandoContarExcursao.executar();

    if (comandoContarExcursao.getResultado() < -1)
        return false;

    // Gerar código aleatório válido, considerando entidade excursao.
    excursao.setCodigo(gerarCodigoValido("excursao"));

    ComandoCadastrarExcursao comandoCadastrarExcursao(excursao, email);

    try{
        comandoCadastrarExcursao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

bool CntrServicoExcursao::consultarExcursao(Excursao* excursao, Email* email){

    Excursao excursaoConsultada;

    ComandoPesquisarExcursao comandoPesquisarExcursao(excursao->getCodigo());

    try{
        comandoPesquisarExcursao.executar();

        excursaoConsultada = comandoPesquisarExcursao.getResultado(email);
    }
    catch(EErroPersistencia &exp) {
        return false;
    }

    excursao->setTitulo(excursaoConsultada.getTitulo());
    excursao->setNota(excursaoConsultada.getNota());
    excursao->setCidade(excursaoConsultada.getCidade());
    excursao->setDuracao(excursaoConsultada.getDuracao());
    excursao->setDescricao(excursaoConsultada.getDescricao());
    excursao->setEndereco(excursaoConsultada.getEndereco());

    return true;
}

bool CntrServicoExcursao::descadastrarExcursao(Codigo codigo, Email email){

    if (!checarUsuarioCadastrado(email))
        return false;

    // Se o código dado não existe, não há o que descadastrar.
    ComandoContarEntidade contarExcursaoDada("excursao", "codigo", codigo.getValor());
    contarExcursaoDada.executar();

    if (contarExcursaoDada.getResultado() == 0)
        return false;

    // Não é possível usuário descadastrar excursao que não anunciou.
    ComandoLerEmailExcursao comandoEmailExcursao(codigo);
    comandoEmailExcursao.executar();

    if (comandoEmailExcursao.getResultado() != email.getValor())
        return false;

    // Quando um excursao é descadastrada, todas as avaliacoes associadas a ela também devem ser descadastradas.
    ComandoDescadastrarAvaliacaoPorCodigoExcursao comandoDescadastrarAvaliacaoPorCodigoExcursao(codigo);
    comandoDescadastrarAvaliacaoPorCodigoExcursao.executar();

    ComandoDescadastrarExcursao comandoDescadastrarExcursao(codigo);

    try{
        comandoDescadastrarExcursao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

bool CntrServicoExcursao::listarExcursao(list<Excursao>* listaExcursao){

    list<Email> listaEmails;

    ComandoListarExcursao comandoListarExcursao;

    try{
        comandoListarExcursao.executar();
        *listaExcursao = comandoListarExcursao.getResultado(&listaEmails);
    }
    catch(EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CntrServicoExcursao::editarExcursao(Excursao excursao, Email email){

    if (!checarUsuarioCadastrado(email))
        return false;

    // Se o código dado não existe, não há o que descadastrar.
    ComandoContarEntidade contarExcursaoDada("excursao", "codigo", excursao.getCodigo().getValor());
    contarExcursaoDada.executar();

    if (contarExcursaoDada.getResultado() == 0)
        return false;

    // Não é possível usuário descadastrar excursao que não anunciou.
    ComandoLerEmailExcursao comandoEmailExcursao(excursao.getCodigo());
    comandoEmailExcursao.executar();

    if (comandoEmailExcursao.getResultado() != email.getValor())
        return false;

    ComandoEditarExcursao comandoEditarExcursao(excursao);

    try{
        comandoEditarExcursao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

bool CntrServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao, Email email, Codigo codigo){

    if (!checarUsuarioCadastrado(email))
        return false;

    // Uma avaliação só pode ser feita para um excursao cadastrada.
    ComandoContarEntidade comandoContarExcursao("excursao", "codigo", codigo.getValor());
    comandoContarExcursao.executar();

    if (comandoContarExcursao.getResultado() == 0)
        return false;

    // Um usuário só pode fazer 1 avaliacao para cada excursao.
    ComandoContarEntidadeDuplo comandoContarAvaliacaoUsuario("avaliacao", "codigo", "codigo_excursao", "email", codigo.getValor(), email.getValor());
    comandoContarAvaliacaoUsuario.executar();

    if (comandoContarAvaliacaoUsuario.getResultado() >= 1)
        return false;

    // Processo de chegagem de que a avaliacao cadastrada bate com a excursao em nota e descricao.
    if (!validarAvaliacaoCadastro(avaliacao, codigo))
        return false;

    // Gerar código aleatório válido, considerando entidade excursoes.
    avaliacao.setCodigo(gerarCodigoValido("avaliacao"));

    ComandoCadastrarAvaliacao comandoCadastrarAvaliacao(avaliacao, email, codigo);

    try{
        comandoCadastrarAvaliacao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

bool CntrServicoExcursao::descadastrarAvaliacao(Codigo codigo, Email email){

    if(!checarUsuarioCadastrado(email))
        return false;

    // Se o código dado não existe, não há o que descadastrar.
    ComandoContarEntidade contarAvaliacaoDada("avaliacao", "codigo", codigo.getValor());
    contarAvaliacaoDada.executar();

    if (contarAvaliacaoDada.getResultado() == 0)
        return false;

    // Não é possível usuário descadastrar avaliacao que não cadastrou.
    ComandoLerEmailAvaliacao comandoEmailAvaliacao(codigo);
    comandoEmailAvaliacao.executar();

    if (comandoEmailAvaliacao.getResultado() != email.getValor())
        return false;

    ComandoDescadastrarAvaliacao comandoDescadastrarAvaliacao(codigo);

    try{
        comandoDescadastrarAvaliacao.executar();
        return true;
    }
    catch(EErroPersistencia &exp) {
        return false;
    }
}

bool CntrServicoExcursao::consultarAvaliacao(Email emailUsuario, Avaliacao* avaliacao, Email* email, Codigo* codigo){

    if (!checarUsuarioCadastrado(emailUsuario))
        return false;

    Avaliacao avaliacaoConsultada;
    Email emailUsuarioConsultado;
    Codigo codigoExcursaoConsultada;

    ComandoPesquisarAvaliacao comandoPesquisarAvaliacao(avaliacao->getCodigo());

    try{
        comandoPesquisarAvaliacao.executar();

        avaliacaoConsultada = comandoPesquisarAvaliacao.getResultado(&emailUsuarioConsultado, &codigoExcursaoConsultada);
    }
    catch(EErroPersistencia &exp) {
        return false;
    }

    // Se o e-mail vinculado à avaliacao for igual ao email do usuário e a avaliacao é dele, ele pode ter acesso.
    if (emailUsuarioConsultado.getValor() == emailUsuario.getValor()){
        *avaliacao = avaliacaoConsultada;
        *email = emailUsuarioConsultado;
        *codigo = codigoExcursaoConsultada;

        return true;
    }

    // Se o e-mail vinculado a excursao da avaliacao for igual ao e-mail do usuário, a avaliacao é sobre um excursao dele.
    Excursao excursaoConsultada;
    Email emailExcursaoConsultada;

    ComandoPesquisarExcursao comandopesquisarExcursao(codigoExcursaoConsultada);

    try{
        comandopesquisarExcursao.executar();

        excursaoConsultada = comandopesquisarExcursao.getResultado(&emailExcursaoConsultada);
    }
    catch(EErroPersistencia &exp) {
        return false;
    }

    if (emailExcursaoConsultada.getValor() == emailUsuario.getValor()){
        *avaliacao = avaliacaoConsultada;
        *email = emailUsuarioConsultado;
        *codigo = codigoExcursaoConsultada;

        return true;
    }

    // Se a avaliacao não tiver sido feita pelo usuário ou em cima de uma excursao por ele cadastrado,
    // ele não pode ter acesso à avaliacao.
    return false;
}

bool CntrServicoExcursao::listarAvaliacao(Email emailUsuario, list<Avaliacao>* listaAvaliacaoUsuario, list<Codigo>* listaCodigosExcursaoUsuario){

    if(!checarUsuarioCadastrado(emailUsuario))
        return false;

    list<Email> listaEmails;
    list<Avaliacao> listaAvaliacao;
    list<Codigo> listaCodigos;

    ComandoListarAvaliacao comandoListarAvaliacao;

    try{
        comandoListarAvaliacao.executar();
        listaAvaliacao = comandoListarAvaliacao.getResultado(&listaCodigos, &listaEmails);
    }
    catch(EErroPersistencia &exp) {
        return false;
    }

    // A lista de propostas deve conter apenas aquelas feitas pelo usuário.
    list<Avaliacao>::iterator avaliacao = listaAvaliacao.begin();
    list<Codigo>::iterator codigo = listaCodigos.begin();

    for(list<Email>::iterator email = listaEmails.begin(); email != listaEmails.end(); email++){

        if (email->getValor() == emailUsuario.getValor()){
            listaAvaliacaoUsuario->push_back(*avaliacao);
            listaCodigosExcursaoUsuario->push_back(*codigo);
        }

        avaliacao++;
        codigo++;
    }

    return true;
}
/*
 bool CntrServicoExcursao::listarAvaliacaoDeExcursao(Email emailUsuario, Codigo codigoExcursao, list<Avaliacao>* listaAvaliacaoUsuario, list<Codigo>* listaCodigosExcursaoUsuario){

    if(!checarUsuarioCadastrado(emailUsuario))
        return false;

    // Se a excursao não existir, não há o que ver.
    ComandoContarEntidade contarExcursaoDada("excursao", "codigo", codigoExcursao.getValor());
    contarExcursaoDada.executar();

    if (contarExcursaoDada.getResultado() == 0)
        return false;

    // Não é possível ver avaliacoes de excursao que não é seu.
    Excursao excursaoConsultada;
    Email emailExcursaoConsultada;

    ComandoPesquisarExcursao comandoPesquisarExcursao(codigoExcursao);

    try{
        comandoPesquisarExcursao.executar();
        excursaoConsultada = comandoPesquisarExcursao.getResultado(&emailExcursaoConsultada);
    }
    catch(EErroPersistencia &exp) {
        return false;
    }

    if (emailExcursaoConsultada.getValor() != emailUsuario.getValor())
        return false;

    list<Avaliacao> listaAvaliacao;
    list<Codigo> listaCodigosExcursao;
    list<Email> listaEmails;

    ComandoListarAvaliacao comandoListarAvaliacao;

    try{
        comandoListarAvaliacao.executar();
        listaAvaliacao = comandoListarAvaliacao.getResultado(&listaCodigosExcursao, &listaEmails);
    }
    catch(EErroPersistencia &exp) {
        return false;
    }

    list<Avaliacao>::iterator avaliacaoLoop = listaAvaliacao.begin();

    for(list<Codigo>::iterator codigoLoop = listaCodigosExcursao.begin(); codigoLoop != listaCodigosExcursao.end(); codigoLoop++){

        if (codigoLoop->getValor() == codigoImovel.getValor()){
            listaAvaliacaosUsuario->push_back(*AvaliacaoLoop);
            listaCodigosExcursaoUsuario->push_back(*codigoLoop);
        }

        AvaliacaoLoop++;
    }

    return true;
}
*/
