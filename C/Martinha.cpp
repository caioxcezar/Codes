#include <iostream>
#include <climits>
#include <cmath>
#include <stdio.h>
#define E 2.7182818284590452
//Riemann sums in summation notation (f(2n-1)*largura)
using namespace std;
void integral3X2 (double a, double b, int c){
  double largura = (b-a)/c, altura = (largura/2) + a, resultado = 0;
  for(int i = 0; i < c; i++){
    resultado += 3*(pow(altura,2))*(largura);
    altura += largura;
  }
  printf("\nA area estimada: %f", resultado);
  resultado = 3*(pow(b,3)/3) - 3*(pow(a,3)/3);
  printf("\nA area real: %f", resultado);
}
void integralEX (double a, double b, int c){
  double largura = (b-a)/c, altura = (largura/2) + a, resultado = 0;
  for(int i = 0; i < c; i++){
    resultado += pow(E,altura)*(largura);
    altura += largura;
  }
  printf("\nA area estimada: %.7f", resultado);
  resultado = pow(E,b) - pow(E,a);
  printf("\nA area real: %.7f", resultado);
}
void integralCosX (double a, double b, int c){
  double largura = (b-a)/c, altura = (largura/2) + a, resultado = 0;
  for(int i = 0; i < c; i++){
    resultado += (-1*cos(altura))*(largura);
    altura += largura;
  }
  printf("\nA area estimada: %.7f", resultado);
  resultado = (-1*cos(b)) - (-1*cos(a));
  printf("\nA area real: %.7f", resultado);
}
int main(){
  inicio:
  system("cls");
  double a, b;
  int n, opc = 0;
  try{
    while(opc !=4){
      cout << "Grupos de Funcao - 3\n1. 3X^2\n2. e^x\n3. -cos(x)\n4. Sair\n====> ";
      cin >> opc;
      if(!cin.good())
        throw 1;
      cout << "Digite o limite inicial: ";
      cin >> a;
      cout << "Digite o limite final: ";
      cin >> b;
      cout << "Digite a quantidade de retangulos: ";
      cin >> n;
      switch (opc) {
        case 1:
          integral3X2(a, b, n);
          break;
        case 2:
          integralEX(a, b, n);
          break;
        case 3:
          integralCosX(a, b, n);
          break;
        }
        cout << "\nDigite 1 para reiniciar e 4 para sair: ";
        cin >> opc;
      }
    } catch (...) {
        cout << "Digite um caracter valido\n";
        system("pause");
        cin.clear();
        cin.ignore();
    }
    goto inicio;
  return 0;
}
