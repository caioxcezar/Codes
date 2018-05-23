#include <iostream>
#define max 30

struct pilha{
    int valor[max], topo;
};

pilha novaPilha(){
    pilha pilha;
    pilha.topo = -1;
    return pilha;
}

bool pilhaVazia(pilha p){
    return (p.topo != -1 ? false : true);
}

bool pilhaCheia(pilha p){
    return ((p.topo-1 != max) ? false : true);
}

void inserir(pilha *p, int valor){
    p->topo++;
    p->valor[p->topo] = valor;
}

void remover(pilha *p){
    p->topo--;
}

int topo(pilha p){
    if(!pilhaVazia(p)){
        return p.valor[p.topo];
    }else{
        return false;
    }
}
int main(){
    using namespace std;
    pilha p = novaPilha();
    cout << "\n Pilha vazia? " << (pilhaVazia(p) ? "Sim" : "Nao") << "\n";
    

    if(!pilhaCheia(p))
        inserir(&p, 74);
    else
        cout << "Pilha cheia";

    cout << "\n Topo: " << topo(p) << "\n";

    if(!pilhaCheia(p))
        inserir(&p, 37);
    else
        cout << "Pilha cheia";

    cout << "\n Topo: " << topo(p) << "\n";

    if(!pilhaVazia(p))
        remover(&p);
    else
        cout << "pilha vazia";
    
    cout << "\n Topo: " << topo(p) << "\n";

    cout << "\n Pilha vazia? " << (pilhaVazia(p) ? "Sim" : "Nao") << "\n";

    return 0;
}