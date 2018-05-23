#include <iostream>
#include <unistd.h>
#include <locale.h>

using namespace std;
struct aviao {
  char modelo[15];
  int capacidade, capAtual;
};
struct voo {
  int id;
  char destino[45], origem[45], piloto[30], coopiloto[30];
  float preco;
  aviao *aviao;
};
int escolhaAviao(aviao aviao[], int size) {
  int escolha = 0;
  printf("Escolha entre os avioes disponiveis: \n");
  for(int i = 0;i<size;i++) {
    printf("\n%d. Modelo %s com capacidade %d",i+1, aviao[i].modelo, aviao[i].capacidade);
  }
  while(escolha > size || escolha <= 0)
  {
  	printf("\nEscolha o modelo: ");
    cin >> escolha;
  }
    return (escolha - 1);
}
int escolhaVoo(voo voo[], int size) {
  int escolha;
  printf("Voos disponiveis: \n");
  for(int i = 0;i<size;i++) {
    printf("\n%d. ID do voo: %d",i+1, voo[i].id);
  }
  printf("\nEscolha o voo: ");
  cin >> escolha;
  if(escolha > size || escolha <= 0) {
    printf("erro");
    printf("\nEscolha o modelo: ");
    cin >> escolha;
  } else {
    return (escolha - 1);
  }
}
int main() {
  setlocale(LC_ALL, "Portuguese");
  int qtdAvioes, qtdVoos;
  char e = '0';
  inicio:
  printf("Amiibo Airline");
  printf("\nInforme a quantidade de avioes: ");
  cin >> qtdAvioes;
  if(qtdAvioes<=0) {
      system("cls");
      printf("Numero invalido");
      sleep(2);
      system("cls");
      goto inicio;
    }
  aviao aviao[qtdAvioes];
  for(int i = 0; i<qtdAvioes;i++) {
    printf("Digite o modelo do %d aviao: ", i+1);
    cin >> aviao[i].modelo;
    printf("Digite a capacidade do %d aviao: ", i+1);
    cin >> aviao[i].capacidade;
    aviao[i].capAtual = aviao[i].capacidade;
  }
  printf("\nInforme quantos voos serao cadastrados: ");
  cin >> qtdVoos;
  voo voo[qtdVoos];
  for(int i = 0; i<qtdVoos;i++) {
    printf("Digite o id do %d voo: ", i+1);
    cin >> voo[i].id;
    int x = escolhaAviao(aviao, qtdAvioes);
    voo[i].aviao = &aviao[x];
    voo[i].aviao->capacidade = aviao[x].capacidade;
    voo[i].aviao->capAtual = aviao[x].capacidade;
    voo[i].aviao->modelo[15] = aviao[x].modelo[15];
    printf("Digite o nome do piloto: ");
    cin >> voo[i].piloto;
    printf("Digite o nome do coopiloto: ");
    cin >> voo[i].coopiloto;
    printf("Digite o preco: ");
    cin >> voo[i].preco;
  }

  char escolha = 'o';
  while(escolha != '5') {
    system("cls");
    printf("Amiibo Airline\nMenu Principal:\n1) Vender passagem\n2) Cancelar passagem\n3) Relat�rio de passagens vendidas\n4) Consultar total de lugares disponiveis\n5) Sair do programa.");
    cin >> escolha;
    switch(escolha) {
      case '1': {
        int nVoo = escolhaVoo(voo, qtdVoos);
        voo[nVoo].aviao->capAtual--;
        printf("Passagem vendida com sucesso!\n");
        system("pause");
      break;
      }
      case '2': {
        int nVoo = escolhaVoo(voo, qtdVoos);
        voo[nVoo].aviao->capAtual++;
        printf("Passagem cancelada com sucesso!\n");
        system("pause");
      break;
      }
      case '3': {
        for(int i = 0; i<qtdVoos;i++)
          printf("Voo %d: Foram vendidas %d passagens\n", voo[i].id, (voo[i].aviao->capacidade-voo[i].aviao->capAtual));
          system("pause");
      break;
      }
      case '4': {
        for(int i = 0; i<qtdVoos;i++)
          printf("Voo %d: Ha %d lugares disponiveis\n", voo[i].id, voo[i].aviao->capacidade);
          system("pause");
      break;
      }
      case '5': {
        system("cls");
        escolha = '5';
      break;
      }
      default: {
        system("cls");
        printf("Opcao invalida");
        sleep(2);
        break;
      }
    }
  }
}
