#include "../include/no.h"

    
No::No(int coeficiente, int expoente){ // foi implementado o construtor do No
    this->coeficiente=coeficiente;
    this->expoente=expoente;

    this->proximo=nullptr;
}

No::~No(){ // foi implementado o destrutor do No
    this->proximo=nullptr;
    delete this;
}

int No::getCoeficiente(){ // foi implementado o get e set do coeficiente
    return this->coeficiente;
}
void No::setCoeficiente(int valor){ 
    this->coeficiente=valor;
}

int No::getExpoente(){ // foi implementado o get e set do expoente
    return this->expoente; // retorna o expoente
}
void No::setExpoente(int valor){ // seta o expoente
    this->expoente=valor; // seta o expoente
}

No* No::ProximoNo(){ // foi implementado o get e set do proximo
    return this->proximo; // retorna o proximo no
}
void No::setProximoNo(No* no){ // seta o proximo no
    this->proximo=no; // seta o proximo no
}
