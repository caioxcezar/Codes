#include <iostream>
#include <string>
#define ZERO 0
using namespace std;
struct no{
    string valor;
    struct no *esquerda, *direita;
};

typedef no *arvore;
arvore raiz;

arvore addValor(string valor){
    arvore n = new(no);
    n->valor = valor;
    n->esquerda = ZERO;
    n->direita = ZERO;
    return n;
}

struct no* addNo(struct no *n, string valor){
    if(n==ZERO)
        n = addValor(valor);
    else if(n->valor > valor)
        n->direita = addNo(n->direita, valor);
    else if(n->valor < valor)
        n->esquerda = addNo(n->esquerda, valor);
    return n;
}

void preOrdem(struct no *p){
    if(p!= ZERO){
        cout << "["<< p->valor <<"] ";
        preOrdem(p->esquerda);
        preOrdem(p->direita);
     }
    return;
}
void posOrdem(struct no *p){
    if(p!= ZERO){ 
        posOrdem(p->esquerda);
        posOrdem(p->direita);
        cout << "["<< p->valor <<"] ";
     }
    return;
}
void ordemSimetrica(struct no *p){
    if(p!= ZERO){ 
        ordemSimetrica(p->esquerda);
        cout << "["<< p->valor <<"] ";
        ordemSimetrica(p->direita);
     }
    return;
}
int main(){
    arvore raiz, novo, aux;
    char escolha;
    string valor;
    cout << "Valor da Raiz: ";
    cin >> valor;
    raiz = addValor(valor);
    do{
        system("cls");
        cout << "1. Inserir\n2. Pre ordem\n3. Pos Ordem\n4. Ordem Simetrica\n5. Sair\n=> ";
        cin >> escolha;
        switch(escolha){
            case '1':{
                cout << "Insira o valor: ";
                cin >> valor;
                addNo(raiz, valor);
                break;
            }case '2':{
                preOrdem(raiz);
                system("pause");
                break;
            }case '3':{
                posOrdem(raiz);
                system("pause");
                break;
            }case '4':{
                ordemSimetrica(raiz);
                system("pause");
                break;
            }
        }
    }while(escolha!='5');
    return 0;
}