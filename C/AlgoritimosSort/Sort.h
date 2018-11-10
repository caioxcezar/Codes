#ifndef HACKUDO_H_INCLUDED
#define HACKUDO_H_INCLUDED
#include <bits/stdc++.h> 
void ExibirVetor(int x[], int tam){
    for(int i = 0;i<tam;i++)
        printf("%d ",x[i]);
    printf("\n");
}
void TROCA(int v[], int pos1, int pos2){
    int aux = v[pos2];
    v[pos2] = v[pos1];
    v[pos1] = aux;
}
void Bubble_Sort(int v[], int tam){
   int nTroca=0;
   for (int i = 0; i < tam-1; i++)
       for (int j = 0; j < tam-i-1; j++)
           if (v[j] > v[j+1]){
               TROCA(v, j, j+1);
               nTroca++;
           }
    printf("Quantidade de Trocas: %d\nVetor: ", nTroca);
    ExibirVetor(v, tam);
}
void Select_Sort(int v[] , int tam){
    int aux, nTroca = 0;
    for (int i = 0; i < tam-1; i++){
        aux = i;
        for (int j = i+1; j < tam; j++)
            if (v[aux] > v[j]){
                aux = j;
            }
        if(aux!=i){
            TROCA(v, i, aux);
            nTroca++;
        }
    }
    printf("Quantidade de Trocas: %d\nVetor: ", nTroca);
    ExibirVetor(v, tam);
}

void Iniciar_Array(int v[], int tam){
    for(int i = 0; i<tam; i++)
        v[i] = INT_MAX/2;
}

void Insert_Sort(int v[], int tam){
    int atual, j, nTroca = 0;
    for(int i = 1; i<tam; i++){
        atual = v[i];
        for(j = i-1; j >= 0 && v[j] > atual; j--){
            v[j+1] = v[j];
            nTroca++;
        }
        v[j+1] = atual;
    }
    printf("Quantidade de Trocas: %d\nVetor: ", nTroca);
    ExibirVetor(v, tam);
}

#endif // HACKUDO_H_INCLUDED