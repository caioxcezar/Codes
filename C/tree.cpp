#include <iostream>
#define ZERO 0
struct no{
    int valor;
    struct no *esquerda, *direita;
};

typedef no *arvore;
arvore raiz;

arvore addValor(int valor){
    arvore n = new(no);
    n->valor = valor;
    n->esquerda = ZERO;
    n->direita = ZERO;
    return n;
}

struct no* addNo(struct no *n, int valor){
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
        printf("[%2d] ",p->valor);
        preOrdem(p->esquerda);
        preOrdem(p->direita);
     }
    return;
}
void posOrdem(struct no *p){
    if(p!= ZERO){ 
        posOrdem(p->esquerda);
        posOrdem(p->direita);
        printf("[%2d] ",p->valor);
     }
    return;
}
void ordemSimetrica(struct no *p){
    if(p!= ZERO){ 
        ordemSimetrica(p->esquerda);
        printf("[%2d] ",p->valor);
        ordemSimetrica(p->direita);
     }
    return;
}
int main(){
    using namespace std;
    arvore raiz, novo, aux;
    int escolha, valor;
    printf("Valor da Raiz: ");
    scanf("%d", &valor);
    raiz = addValor(valor);
    do{
        system("cls");
        printf("1. Inserir\n2. Pre ordem\n3. Pos Ordem\n4. Ordem Simetrica\n5. Sair\n=> ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{
                printf("Insira o valor: ");
                scanf("%d", &valor);
                addNo(raiz, valor);
                break;
            }case 2:{
                preOrdem(raiz);
                system("pause");
                break;
            }case 3:{
                posOrdem(raiz);
                system("pause");
                break;
            }case 4:{
                ordemSimetrica(raiz);
                system("pause");
                break;
            }
        }
    }while(escolha!=5);
    return 0;
}