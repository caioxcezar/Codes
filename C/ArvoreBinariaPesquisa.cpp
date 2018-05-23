#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define true 1
#define false 0

//typedef int bool;
typedef int TIPOCHAVE;

using namespace std;

typedef struct aux{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT adiciona(PONT raiz, PONT no){
  if(raiz == NULL)
    return(no);
  if(no->chave < raiz->chave)
    raiz->esq = adiciona(raiz->esq, no);
  else
    raiz->dir = adiciona(raiz->dir, no);
  return(raiz);
}

PONT inicializa(){
  return(NULL);
}

PONT criarNovoNo(TIPOCHAVE ch){
  PONT novoNo = (PONT)malloc(sizeof(NO));
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  novoNo->chave = ch;
  return(novoNo);
}
int numeroNos(PONT raiz){
  if(!raiz)
    return 0;
  return(numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

int main(){
  int escolha, valor;
  PONT r = inicializa();
  cout << "Arvore Binaria\n";
  do{
    system("clear");
    cout << "1. Adicionar um valor\n2. Numero de Nos\n===> ";
    cin >> escolha;
    switch (escolha) {
      case 1:{
        cout << "valor: ";
        cin >> valor;
        PONT no = criarNovoNo(valor);
        r = adiciona(r, no);
        break;
      }
      case 2:
        cout << "Numero de Nos: " << numeroNos(r);
        break;
    }
  }while(escolha!=3);
  return 0;
}
