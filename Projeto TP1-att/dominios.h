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
//Matricula: 202021749
// Felipe Dantas Borges
class Email {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:
        void setValor(string);             // Método para atribuir valor.
        string getValor() const;           // Método para recuperar valor.
};

inline string Email::getValor() const{
    return valor;
}

//----------------------------------------------------------------------- */
//Matricula: 202021749
// Felipe Dantas Borges
class Data {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:
        void setValor(string);             // Método para atribuir valor.
        string getValor() const;           // Método para recuperar valor.
};

inline string Data::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
//Matricula: 202021749
// Felipe Dantas Borges
class Endereco {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:
        void setValor(string);             // Método para atribuir valor.
        string getValor() const;           // Método para recuperar valor.
};

inline string Endereco::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
//Matricula: 202021749
// Felipe Dantas Borges
class Titulo {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};
inline string Titulo::getValor() const{
    return valor;
}
//----------------------------------------------------------------------- */
// Matricula: 202006448
// Rafael Hamú Campos
class Idioma {
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(char);
        string getValor() const;
};

inline string Idioma::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202006448
// Rafael Hamú Campos
class Nota {
    private:
        const int valor;
        void validar(int);
    public:
        void setValor(int);
        int getValor() const;
};

inline int Nota::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202006448
// Rafael Hamú Campos
class Duracao {
    private:
        const int valor;
        void validar(int);
    public:
        void setValor(int);
        int getValor() const;
};

inline int Duracao::getValor() const{
    return valor;
}


//----------------------------------------------------------------------- */
// Matricula: 202006448
// Rafael Hamú Campos
class Descricao {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor() const;
};

inline string Descricao::getValor() const{
    return valor;
}

#endif // DOMINIOS_H_INCLUDED
