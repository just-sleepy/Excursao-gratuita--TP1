#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

/* -----------------------------------------------------------------------
// Estrutura de código para declaração de classe domínio.
// Substituir Dominio por nome da classe.
// Substituir Tipo.

class Dominio {
    private:
        Tipo valor;                      // Atributo para armazenar valor.
        void validar(Tipo);              // Método para validar valor.
    public:
        void setValor(Tipo);             // Método para atribuir valor.
        Tipo getValor() const;           // Método para recuperar valor.
};

inline Tipo Dominio::getValor() const{
    return valor;
}

//----------------------------------------------------------------------- */
// Matricula: 202006420
// Gustavo Pierre Starling
class Cidade {
    private:
        const string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Cidade::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202006420
// Gustavo Pierre Starling
class Codigo {
    private:
        const string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Codigo::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202006420
// Gustavo Pierre Starling
class Horario {
    private:
        const string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Horario::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202006420
// Gustavo Pierre Starling
class Senha {
    private:
        const string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Senha::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202006420
// Gustavo Pierre Starling
class Nome {
    private:
        const string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Nome::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202021749
// Felipe Dantas Borges
class Data {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Endereco::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202021749
// Felipe Dantas Borges
class Endereco {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Endereco::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202021749
// Felipe Dantas Borges
class Titulo {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;

inline string Titulo::getValor() const{
    return valor;
}


