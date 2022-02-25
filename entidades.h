#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

// -----------------------------------------------------------------------
// Exemplo de declaração de classe entidade e implementações de métodos.
// Matricula: 202021749
// Felipe Dantas Borges

//Excursao:
///
///@brief Padr&atilde;o para representa&ccedil;&atilde;o de Excurs&atilde;o
///
///
///Excurs&atilde;o cont&eacute;m dom&iacute;nios Codigo, Titulo, Nota, Cidade, Duracao, Descricao e Endereco


class Excursao {
private:
    Codigo codigo;
    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;
public:
/// Armazena codigo.
///
/// @param valor codigo.
///
/// @return
///
/// - Retorna true  caso codigo tenha sido armazenado.
/// - Retorna false caso codigo n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setCodigo(const Codigo&);
/// Retorna codigo.
///
/// @return codigo
///
    Codigo getCodigo() const;
//-------------------------------------------------------------------------------
/// Armazena titulo.
///
/// @param valor titulo.
///
/// @return
///
/// - Retorna true  caso titulo tenha sido armazenado.
/// - Retorna false caso titulo n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setTitulo(const Titulo&);
/// Retorna titulo.
///
/// @return titulo
///
    Titulo getTitulo() const;

//-------------------------------------------------------------------------------
/// Armazena nota.
///
/// @param valor nota.
///
/// @return
///
/// - Retorna true  caso nota tenha sido armazenado.
/// - Retorna false caso nota n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setNota(const Nota&);
/// Retorna nota.
///
/// @return nota
///
    Nota getNota() const;

//-------------------------------------------------------------------------------
/// Armazena cidade.
///
/// @param valor cidade.
///
/// @return
///
/// - Retorna true  caso cidade tenha sido armazenado.
/// - Retorna false caso cidade n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setCidade(const Cidade&);
/// Retorna cidade.
///
/// @return cidade
///
    Cidade getCidade() const;

//-------------------------------------------------------------------------------
/// Armazena duracao.
///
/// @param valor duracao.
///
/// @return
///
/// - Retorna true  caso duracao tenha sido armazenado.
/// - Retorna false caso duracao n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setDuracao(const Duracao&);
/// Retorna duracao.
///
/// @return duracao
///
    Duracao getDuracao() const;

//-------------------------------------------------------------------------------
/// Armazena descricao.
///
/// @param valor descricao.
///
/// @return
///
/// - Retorna true  caso descricao tenha sido armazenado.
/// - Retorna false caso descricao n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setDescricao(const Descricao&);
/// Retorna descricao.
///
/// @return descricao
///
    Descricao getDescricao() const;

//-------------------------------------------------------------------------------
/// Armazena endereco.
///
/// @param valor endereco.
///
/// @return
///
/// - Retorna true  caso endereco tenha sido armazenado.
/// - Retorna false caso endereco n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setEndereco(const Endereco&);
/// Retorna endereco.
///
/// @return endereco
///
    Endereco getEndereco() const;
};
//#--------------------------------------------------------
inline void Excursao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}
inline Codigo Excursao::getCodigo() const {
    return codigo;
}
//#---------------------
inline void Excursao::setTitulo(const Titulo& titulo){
    this->titulo = titulo;
}
inline Titulo Excursao::getTitulo() const {
    return titulo;
}
//#---------------------
inline void Excursao::setNota(const Nota& nota){
    this->nota = nota;
}
inline Nota Excursao::getNota() const {
    return nota;
}
//#---------------------
inline void Excursao::setCidade(const Cidade& cidade){
    this->cidade = cidade;
}
inline Cidade Excursao::getCidade() const {
    return cidade;
}
//#---------------------
inline void Excursao::setDuracao(const Duracao& duracao){
    this->duracao = duracao;
}
inline Duracao Excursao::getDuracao() const {
    return duracao;
}
//#---------------------
inline void Excursao::setDescricao(const Descricao& descricao){
    this->descricao = descricao;
}
inline Descricao Excursao::getDescricao() const {
    return descricao;
}
//#---------------------
inline void Excursao::setEndereco(const Endereco& endereco){
    this->endereco = endereco;
}
inline Endereco Excursao::getEndereco() const {
    return endereco;
}


// -----------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling
// Sessão:

///
///@brief Padr&atilde;o para representa&ccedil;&atilde;o de Sess&atilde;o
///
///
///Sess&atilde;o cont&eacute;m dom&iacute;nios Codigo, Data, Horario e Idioma

class Sessao {
private:
    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;

public:
/// Armazena codigo.
///
/// @param valor codigo.
///
/// @return
///
/// - Retorna true  caso codigo tenha sido armazenado.
/// - Retorna false caso codigo n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///

    void setCodigo(const Codigo&);
/// Retorna codigo.
///
/// @return codigo
///
    Codigo getCodigo() const;
//-------------------------------------------------------------------------------
/// Armazena data.
///
/// @param valor data.
///
/// @return
///
/// - Retorna true  caso data tenha sido armazenado.
/// - Retorna false caso data n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setData(const Data&);
/// Retorna data.
///
/// @return data
///
    Data getData() const;
//-------------------------------------------------------------------------------
/// Armazena horario.
///
/// @param valor horario.
///
/// @return
///
/// - Retorna true  caso horario tenha sido armazenado.
/// - Retorna false caso horario n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///

    void setHorario(const Horario&);
/// Retorna horario.
///
/// @return horario
///
    Horario getHorario() const;
//-------------------------------------------------------------------------------
/// Armazena idioma.
///
/// @param valor idioma.
///
/// @return
///
/// - Retorna true  caso idioma tenha sido armazenado.
/// - Retorna false caso idioma n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///

    void setIdioma(const Idioma&);
/// Retorna idioma.
///
/// @return idioma
///
    Idioma getIdioma() const;
};
//#--------------------------------------------------------
inline void Sessao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}
inline Codigo Sessao::getCodigo() const {
    return codigo;
}
//#---------------------
inline void Sessao::setData(const Data& data){
    this->data = data;
}
inline Data Sessao::getData() const {
    return data;
}
//#---------------------
inline void Sessao::setHorario(const Horario& horario){
    this->horario = horario;
}
inline Horario Sessao::getHorario() const {
    return horario;
}
//#---------------------
inline void Sessao::setIdioma(const Idioma& idioma){
    this->idioma = idioma;
}
inline Idioma Sessao::getIdioma() const {
    return idioma;
}

//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
//Avaliacao:
///
///@brief Padr&atilde;o para representa&ccedil;&atilde;o de Avalia&ccedil;&atilde;o
///
///
///Avalia&ccedil;&atilde;o cont&eacute;m dom&iacute;nios Codigo, Nota e Descricao
class Avaliacao{
private:

    Codigo codigo;
    Nota nota ;
    Descricao descricao ;

public:
/// Armazena codigo.
///
/// @param valor codigo.
///
/// @return
///
/// - Retorna true  caso codigo tenha sido armazenado.
/// - Retorna false caso codigo n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setCodigo(const Codigo&);
/// Retorna codigo.
///
/// @return codigo
///
    Codigo getCodigo() const;
//-------------------------------------------------------------------------------
/// Armazena nota.
///
/// @param valor nota.
///
/// @return
///
/// - Retorna true  caso nota tenha sido armazenado.
/// - Retorna false caso nota n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setNota(const Nota&);
/// Retorna nota.
///
/// @return nota
    Nota getNota() const;
//-------------------------------------------------------------------------------
/// Armazena descri&ccedil;&atilde;o.
///
/// @param valor descri&ccedil;&atilde;o.
///
/// @return
///
/// - Retorna true  caso descri&ccedil;&atilde;o tenha sido armazenado.
/// - Retorna false caso descri&ccedil;&atilde;o n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setDescricao(const Descricao&);
/// Retorna descri&ccedil;&atilde;o.
///
/// @return descri&ccedil;&atilde;o
    Descricao getDescricao() const;

};

//#--------------------------------------------------------
inline void Avaliacao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}
inline Codigo Avaliacao::getCodigo() const {
    return codigo;
}
//#---------------------
inline void Avaliacao::setNota(const Nota& nota){
    this->nota = nota;
}
inline Nota Avaliacao::getNota() const {
    return nota;
}
//#---------------------
inline void Avaliacao::setDescricao(const Descricao& descricao){
    this->descricao = descricao;
}
inline Descricao Avaliacao::getDescricao() const {
    return descricao;
}
//----------------------------------------------------------------------- */
//Matricula: 202006448
// Rafael Hamú Campos
///
///@brief Padr&atilde;o para representa&ccedil;&atilde;o de Usuario
///
///
///Usuario cont&eacute;m dom&iacute;nios Nome, Email e Senha
class Usuario{
private:
    Nome nome;
    Email email;
    Senha senha;
public:
//-------------------------------------------------------------------------------
/// Armazena nome.
///
/// @param valor nome.
///
/// @return
///
/// - Retorna true  caso nome tenha sido armazenado.
/// - Retorna false caso nome n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setNome(const Nome&);
/// Retorna nome.
///
/// @return nome
    Nome getNome() const;
//-------------------------------------------------------------------------------
/// Armazena email.
///
/// @param valor email.
///
/// @return
///
/// - Retorna true  caso email tenha sido armazenado.
/// - Retorna false caso email n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setEmail(const Email&);
/// Retorna email.
///
/// @return email
    Email getEmail() const;
//-------------------------------------------------------------------------------
/// Armazena senha.
///
/// @param valor senha.
///
/// @return
///
/// - Retorna true  caso senha tenha sido armazenado.
/// - Retorna false caso senha n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///
    void setSenha(const Senha&);
/// Retorna senha.
///
/// @return senha
    Senha getSenha() const;
};

//#---------------------
inline void Usuario::setNome(const Nome& nome){
    this->nome = nome;
}
inline Nome Usuario::getNome() const {
    return nome;
}
//#---------------------
inline void Usuario::setEmail(const Email& email){
    this->email = email;
}
inline Email Usuario::getEmail() const {
    return email;
}
//#---------------------
inline void Usuario::setSenha(const Senha& senha){
    this->senha = senha;
}
inline Senha Usuario::getSenha() const {
    return senha;
}


#endif // ENTIDADES_H_INCLUDED
