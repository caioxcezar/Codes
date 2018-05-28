#include <stdio.h>
#include <stdlib.h>     /* malloc, calloc, realloc, free */
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

arvore addNo(arvore n, int valor){
    if(n==ZERO)
        n = addValor(valor);
    else if(n->valor < valor)
        n->direita = addNo(n->direita, valor);
    else if(n->valor > valor)
        n->esquerda = addNo(n->esquerda, valor);
    return n;
}

arvore maiorFilho(arvore t, arvore pai, int valor){
    arvore aux;
    if(t->direita == ZERO){
        aux = t;
        if(pai->valor == valor)
            pai->esquerda = t->esquerda;
        else
            pai->direita = t->esquerda;
    }else{
        pai = t;
        aux = maiorFilho(t->direita,t,valor);
    }
    return aux;
}

arvore rmNo(arvore t, int valor, arvore pai){
    arvore aux;
    //caso chegue ao fim da arvore sem encontrar o valor
    if(t==ZERO)
        return 0;
    //Valor encontrado
    if(valor == t->valor){
        aux = t;
        if(t->esquerda = ZERO){
            if(pai->esquerda == t)
                pai->esquerda = t->direita;
            if(pai->direita == t)
                pai->direita = t->direita;
        }else{
            if(t->direita == ZERO){
                if(pai->esquerda == t)
                    pai->esquerda = t->esquerda;
                if(pai->direita == t)
                    pai->direita = t->esquerda;
            }else{
                aux = maiorFilho(t->esquerda, t, valor);
                t->valor = aux->valor;
            }
            free(aux);
            return(aux);
        }
    }else{
        if(valor<t->valor)
            rmNo(t->esquerda,valor,t);
        else
            rmNo(t->direita,valor,t);
    }
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
/*
int main(){
    using namespace std;
    arvore raiz;
    int escolha, valor;
    printf("Valor da Raiz: ");
    scanf("%d", &valor);
    raiz = addValor(valor);
    do{
        system("cls");
        printf("1. Inserir\n2. Pre ordem\n3. Pos Ordem\n4. Ordem Simetrica\n5. Remover Valor\n6. Sair\n=> ");
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
            case 5:{
                printf("Digite o falor a ser removido: ");
                scanf("%d",&valor);
                rmNo(raiz, valor);
            }
        }
    }while(escolha!=6);
    return 0;
}
*/
int main(){
    arvore raiz;
    raiz = addValor(5);
    addNo(raiz, 3);
    addNo(raiz, 7);
    addNo(raiz, 2);
    addNo(raiz, 4);
    addNo(raiz, 6);
    addNo(raiz, 8);
    rmNo(raiz, 6, raiz);
    ordemSimetrica(raiz);
}