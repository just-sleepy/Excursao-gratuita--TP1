#include "dominios.h"
#include<stdio.h>
#include<string.h>
#include<iostream>
using  namespace std;

// --------------------------------------------------------------------------
// Implementações de métodos de classe domínio.
// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Cidade:

void Cidade::validar(string valor){
    string cidades_validas[15] = {"Hong Kong", "Bangkok", "Macau", "Singapura", "Londres", "Paris", "Dubai",
    "Delhi", "Istambul", "Kuala Lumpur", "Nova Iorque", "Antalya", "Mumbai", "Shenzhen", "Phuket"};
    bool valido = false;
    //Confere se valor está no array de cidades_validas
    for(int i=0; i < 15; i++){
        if (valor == cidades_validas){
            valido = true;
        }
    }
    //Confere se é válido
    if(valido == false){
        throw invalid_argument("Argumento invalido.");
    }
}

void Cidade::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Codigo:

void Codigo::validar(string valor){
    bool valido = true;
    int soma = 0;
    if(valor.size() != 7){
        throw invalid_argument("Argumento invalido.");
    }
    for(int i=0; i < valor.size()-1; i++){
        if (int(valor[i]) < 48 || int(valor[i]) > 57){
            valido = false;
        }
        else {
            soma += (int(valor[i]) - 48);
        }
    }
    if ( soma%10 != (int(valor[valor.size()-1]) - 48) ){
        valido = false;
    }
    if (valido == false || valor.substr(0, 6) == "000000"){
        throw invalid_argument("Argumento invalido.");
    }
}

void Codigo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Horario:

void Horario::validar(string valor){
    //armazena as horas e os minutos informados seguindo o formato(HH:MM)
    string horas_str = valor.substr(0, 2);
    string minutos_str = valor.substr(3, 5);

    //transforma em inteiro
    int horas = stoi(horas_str);
    int minutos = stoi(minutos_str);

    //verifica o tamanho da string, a presença de ":" entre as horas e os minutos e espaço amostral das horas e dos minutos.
    if(valor.size() != 5 || valor[2] != ':' || horas < 0 || horas > 23 || minutos < 0 || minutos > 59){
        throw invalid_argument("Argumento invalido.");
    }
}

void Horario::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Senha:

void Senha::validar(string valor){
    bool valido = true;
    bool letra_maius = false;
    bool letra_min = false;
    bool digito = false;
    if(valor.size() != 6){
        throw invalid_argument("Argumento invalido.");
    }
    for(int i=0; i < valor.size();i++){
        if (int(valor[i]) >= 65 && int(valor[i]) <= 90){
            letra_maius = true;
        }
        else if (int(valor[i]) >= 97 && int(valor[i]) <= 122){
            letra_min = true;
        }
        else if (int(valor[i]) >= 48 && int(valor[i]) <= 57){
            digito = true;
        }
        else {
            valido = false;
        }
        for(int j=0; j < valor.size(); j++){
            if(i != j && int(valor[i]) == int(valor[j])){
                valido = false;
            }
        }
    }
    if(letra_maius == false || letra_min == false || digito == false || valido == false){
        throw invalid_argument("Argumento invalido.");
    }
}

void Senha::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}


// --------------------------------------------------------------------------
// Matricula: 202006420
// Gustavo Pierre Starling

// Nome:

void Nome::validar(string valor){
    bool valido = true;
    if(valor.size() < 5 || valor.size() > 20){
        throw invalid_argument("Argumento invalido.");
    }
    for(int i=0; i < valor.size(); i++){
        // verifica o primeiro index
        if (i == 0){
            // verifica letra maiuscula
            if (int(valor[i]) < 65 || int(valor[i]) > 90){
                valido = false;
            }
        }

        // verifica os demais index
        else {
            //verifica se o '.' esta empregado corretamente
            if (valor[i] == '.'){
                //precedido por letra
                if (int(valor[i-1]) < 65 || 90 < (int(valor[i-1]) && int(valor[i-1]) < 97) || int(valor[i-1]) > 122) {
                    valido = false;
                }
                //ultimo caractere ou seguido por ' '
                else if (i != valor.size()-1 && valor[i+1] != ' '){
                    valido = false;
                }
            }
            //verifica se o ' ' esta empregado corretamente
            else if (int(valor[i]) == 32){
                //dois ' ' seguidos
                if (int(valor[i+1]) == 32){
                    valido = false;
                }
                else if (int(valor[i+1]) < 65 || 90 < (int(valor[i+1]))){
                    valido = false;
                }
            }
            //verifica se escreveu letras
            else if (valor[i] < 65 || (90 < valor[i] && valor[i] < 97) || valor[i] > 122){
                valido = false;
            }
        }
    }
    if (valido == false){
        throw invalid_argument("Argumento invalido.");
    }
}

void Nome::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}


// --------------------------------------------------------------------------
// Matricula: 202021749
// Felipe Dantas Borges

// Data:

void Data::validar(string valor){
    char valor[] = "13-Apr-2002";
    //Separa no formato DD-MES-AAAA
    string DDstr = strtok(valor, "-");
    string MES = strtok(NULL, "-");
    string AAAAstr = strtok(NULL, "-");

    int DD = stoi(DDstr); //converte str para int
    int AAAA = stoi(AAAAstr); //converte str para int

    //Confere espaco amostral de dias
    if ((DD < 1) || (DD > 31)){
        throw invalid_argument("Argumento invalido.");
    }

    //Confere espaco amostral de Mes





    //Confere espaco amostral de Anos
    if ((2000< 1) || (AAAA > 9999)){
        throw invalid_argument("Argumento invalido.");
    }

void Data::setValor(string valor) {
    validar(valor);
    this->valor = valor;


// --------------------------------------------------------------------------
//Matricula: 202021749
// Felipe Dantas Borges

//Endereco:

void Endereco::validar(string valor){
    int len = valor.size();
    int ponto, espaco, valido = 1;
    string p1("."),p2(" ");

    for (int i = 0; valor[i] != '\0'; i++){
        string c;
        c = valor[i];
        if (bool(c == p1) == 1){
            ++ ponto;
            espaco = 0;  //zera a contagem de espacos
            if (ponto == 2){
                valido = 0;
            }
        }
        else if(bool(c == p2) == 1){
            ++ espaco ;
            ponto = 0;//zera a contagem de pontos
            if (espaco == 2){
                valido = 0;
            }
        }
        else{
            ponto = 0;
            espaco = 0;
        }
    }

    if((len <= 0 ) || (len >= 20)){
        throw invalid_argument("Argumento invalido.");
    }
    else if (valido == 0){
        throw invalid_argument("Argumento invalido.");
    }

void Endereco::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}


// --------------------------------------------------------------------------
//Matricula: 202021749
// Felipe Dantas Borges

//Titulo:

void Titulo::validar(string valor){
    int len = valor.size();
    int ponto, espaco, valido = 1;
    string p1("."),p2(" ");

    for (int i = 0; valor[i] != '\0'; i++){
        string c;
        c = valor[i];
        if (std::isdigit(s[i]) == 1){
            valido = 0;
        }
        else if (bool(c == p1) == 1){
            ++ ponto;
            espaco = 0;  //zera a contagem de espacos
            if (ponto == 2){
                valido = 0;
            }
        }
        else if(bool(c == p2) == 1){
            ++ espaco ;
            ponto = 0;//zera a contagem de pontos
            if (espaco == 2){
                valido = 0;
            }
        }
        else{
            ponto = 0;
            espaco = 0;
        }
    }

    if((len <= 5 ) || (len >= 20)){
        throw invalid_argument("Argumento invalido.");
    }
    else if (valido == 0){
        throw invalid_argument("Argumento invalido.");
    }

void Titulo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

