#ifndef ARVORE_H
#define ARVORE_H
#include "No.h"
#include <iostream>

using namespace std;

template <typename T>
class Arvore{
private:
    No<T>* raiz;
    int n;

    void erd(No<T>* r){
        if(r){
            erd(r->esq);
            cout << **r << endl;
            erd(r->dir);
        }
    }

    void destrutor(No<T>* s){
        if(s){
            destrutor(s->esq);
            destrutor(s->dir);
            delete(s);
        }
    }
public:
    Arvore(): raiz(NULL), n(0){

    }

    void erd(){
        erd(raiz);
    }


    void edr(){
        edr(raiz);
    }


    bool insere(T valor){
        No<T>* novo = new No<T>(valor);
        if(!novo)
            return false;

        No<T>* atual = raiz;
        No<T>* anterior = NULL;
        while(atual){
            anterior = atual;
            if(valor <= atual->valor){
                atual = atual->esq;
            }else{
                atual = atual->dir;
            }
        }

        novo->pai = anterior;

        if(anterior){
            if(valor <= anterior->valor)
                anterior->esq = novo;
            else
                anterior->dir = novo;
        }else{
            raiz = novo;
        }

        n++;
        return true;
    }

    No<T>* busca(T valor){
        No<T>* atual = raiz;
        while(atual){
            if(valor==atual->valor)
                return atual;

            if(valor <= atual->valor){
                atual = atual->esq;

            }else{
                atual = atual->dir;
            }
        }
    }

    ~Arvore(){
        destrutor(raiz);
    }
};

#endif