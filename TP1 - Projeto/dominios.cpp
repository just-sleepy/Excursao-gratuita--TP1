#include "dominios.h"
#include<stdio.h>
#include<string.h>
#include<iostream>
using  namespace std;

// --------------------------------------------------------------------------
// Implementações de métodos de classe domínio.
// --------------------------------------------------------------------------
//Data:
//Matricula: 202021749
// Felipe Dantas Borges

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
//Endereco:
//Matricula: 202021749
// Felipe Dantas Borges

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
//Titulo:
//Matricula: 202021749
// Felipe Dantas Borges

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

