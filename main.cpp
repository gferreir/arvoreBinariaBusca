#include "Arvore.h"

int main(){
    Arvore<int> a;
    a.insere(5);
    a.insere(2);
    a.insere(7);
    a.insere(1);
    a.insere(3);
    a.insere(6);

    a.erd();

    cout << "BUSCAAAAAAAAAA" << endl;
    cout << a.busca(5)->getValor() <<endl;

    return 0;
}