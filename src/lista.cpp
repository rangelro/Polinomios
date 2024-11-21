#include <iostream>
#include "../include/lista.h"
#include "no.cpp"

class Lista
{
private:
    No* cabeca;
    int tamanho;
public:

    Lista::Lista(){ // construtor da lista
        cabeca = nullptr;
        tamanho = 0;
    }

    Lista::~Lista(){ // destrutor da lista
        No* atual = cabeca;
        No* proximo = nullptr; // para guardar o proximo no
        while(atual != nullptr){ // enquanto o no atual for diferente de nulo
            proximo = atual->ProximoNo(); // guarda o proximo no para nao perder a referencia
            delete atual;
            atual = proximo; // atualiza o no atual para o proximo
        }
    }

    No* Lista::ObterProximo(No* no){ // obtem o proximo no
        if (no != nullptr){ // se o no for diferente de nulo
            return no->ProximoNo(); // retorna o proximo no
        }
        return nullptr;   // se nao retorna nulo
        
    }

    //ObterValor  --
    
    void Lista::AlterarNo(No* no, int coeficiente, int expoente){ // altera o no
        if (no != nullptr){             // se o no for diferente de nulo
            no->setCoeficiente(coeficiente); // seta o coeficiente
            no->setExpoente(expoente); // seta o expoente
        }
    }

    int Lista::Tamanho(){ // retorna o tamanho da lista
        return tamanho;
    }

    bool Lista::Existe(No* no){  // verifica se o no existe
        No* atual = cabeca; // pega o no atual
        while(atual != nullptr){ // enquanto o no atual for diferente de nulo
            if (atual == no){ // se o no atual for igual ao no passado
                return true; // retorna verdadeiro
            }
            atual = atual->ProximoNo(); // atualiza o no atual para o proximo
        }
        return false; // se nao retorna falso
    }

   // Lista::mostrarAll  não sei implementar/perguntar a Olodum Junior

    No* Lista::Buscar(int coeficiente){
        No* atual = cabeca; // pega o no atual
        while(atual != nullptr){ // enquanto o no atual for diferente de nulo
            if (atual->getCoeficiente() == coeficiente){ // se o coeficiente do no atual for igual ao coeficiente passado
                return atual; // retorna o no atual
            }
            atual = atual->ProximoNo(); // atualiza o no atual para o proximo
        }
        return nullptr; // se nao retorna nulo
    }

    void Lista::Inserir(int coeficiente, int expoente){
        if (coeficiente == 0){ // se o coeficiente for igual a 0
            return; // retorna
        }
        
        No* novoNo = new No(coeficiente, expoente); // cria um novo no
        
        if (cabeca == nullptr){ // se a cabeca for nula
            cabeca = novoNo; // a cabeca recebe o novo no
        } else { 
            No* atual = cabeca; // pega o no atual
            No* anterior = nullptr; // pega o no anterior
        
        while(atual != nullptr && atual->getExpoente() > expoente){ // enquanto o no atual for diferente de nulo e o expoente do no atual for maior que o expoente passado
            anterior = atual; // o no anterior recebe o no atual
            atual = atual->ProximoNo(); // atualiza o no atual para o proximo
        }
        if (atual != nullptr && atual->getExpoente() == expoente){ // se o no atual for diferente de nulo e o expoente do no atual for igual ao expoente passado
            atual->setCoeficiente(atual->getCoeficiente() + coeficiente); // seta o coeficiente do no atual para o coeficiente do no atual mais o coeficiente passado
            delete novoNo; // deleta o novo no
        } else { 
            
            if (anterior == nullptr){ // se o no anterior for nulo
                novoNo->setProximoNo(cabeca); // seta o proximo no do novo no para a cabeca
                cabeca = novoNo; // a cabeca recebe o novo no
            } else {
                novoNo->setProximoNo(atual); // seta o proximo no do novo no para o atual
                anterior->setProximoNo(novoNo); // seta o proximo no do anterior para o novo no
            }
            }
        }

    }

    void Lista::Excluir(No* no){
        if (no == nullptr){ // se o no for nulo
            return;
        }
        if (cabeca == no){ // se a cabeca for igual ao no
            cabeca = no->ProximoNo(); // a cabeca recebe o proximo no
            delete no; // deleta o no
            return;
        }
        No* atual = cabeca; // pega o no atual

        while(atual != nullptr && atual->ProximoNo() != no){ // enquanto o no atual for diferente de nulo e o proximo no do no atual for diferente do no
            No* temporario = atual->ProximoNo(); // pega o proximo no do no atual
            if (temporario == no){ // se o temporario for igual ao no
                atual->setProximoNo(no->ProximoNo()); // seta o proximo no do no atual para o proximo no do no
                delete no; // deleta o no
                return;
            }
            atual = atual->ProximoNo(); // atualiza o no atual para o proximo
        }
        
        
    }

};
