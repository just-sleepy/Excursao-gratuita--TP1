#include "dominios.h"
#include<stdio.h>
#include<string.h>
#include<iostream>
using  namespace std;

// --------------------------------------------------------------------------
// Implementações de métodos de classe domínio.

// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
//Titulo

void Titulo::validar(string valor){
    int len = valor.lengh()
    int ponto, espaco, valido = 1;
    string p1("."),p2(" ");

    for (int i = 0; s[i] != '\0'; i++){
        string c;
        c = s[i];
        if (std::isdigit(s[i]) == 1){
            valido = 0;
        }
        else if (bool(c == p1) == 1){
            ++ ponto;
            cout <<ponto << "entrou";
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

    if((len < 5 ) || (len > 20)){
        throw invalid_argument("Argumento invalido.");
    }
    else if (valido == 0){
        throw invalid_argument("Argumento invalido.");
    }
void Titulo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

