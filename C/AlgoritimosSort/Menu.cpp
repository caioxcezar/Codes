#include  <iostream>
#include  <stdlib.h>
#include  <stdio.h>
#include "Sort.h"

using namespace std;

void stop(){
    cout << "Press enter to continue ...";
    cin.get();
    cin.get();
}

int main (){
    int pause;
    int tam = 0;
    int opcao = -1;
    cout << "====================== ALGORITMO DE INSERÇÃO V0.0.3 ==============================\n";
    cout << "Insira o tamanho  do seu vetor: ";
    cin >> tam;
    int vet[tam];
    for (int i = 0 ; i < tam ; i++){
            cout << "\nValor da " << i+1 << "º posição: ";
        cin >> vet[i];
    }
    do{
        system("clear");
        cout << "Agora escolha o metodo de ordenação : \n (1)- Troca \n (2)-Bubble Sort \n (3)-Select sort \n (4) - Insert Sort \n (5)- Exibir Vetor \n (0)-Sair \n => ";
        cin >> opcao;
        switch(opcao){
            case 1:{
                cout << "Troca selecionado \n";
                int num1, num2;
                cout << "Digite o primeiro valor: ";
                cin >> num1;
                cout << "Digite o segundo valor: ";
                cin >> num2;
                TROCA(vet, num1, num2);
                break;
            }
            case 2:{
                cout << "Bubble Sort selecionado !! \n";
                Bubble_Sort(vet, tam);
                stop();
                break;
            }
            case 3:{
                cout << "Select Sort  selecionado !! \n";
                Select_Sort(vet, tam);
                stop();
                break;
            }
            case 4:{
                cout << "insert Sort  selecionado !! \n";
                Insert_Sort(vet, tam);
                stop();
                break;
            }
            case 5:{
                ExibirVetor(vet, tam);
                stop();
                break;
            }
            case 0:{
                cout << "Saindo....\n";
                break;
            }
        }
    }while(opcao!=0);
}