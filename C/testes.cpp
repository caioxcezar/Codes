#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <cmath>
#include <locale.h> //necessário para usar setlocale
using namespace std;

struct str{
  int a,b,c;
};
void test(int x[])
{
  for(int i = 0;i<=(sizeof(x)/sizeof(x[0]));i++)
    printf("%d\n", x[i]);
}
int main()
{
  setlocale(LC_ALL,"Portuguese");
  cout << "5^2: " << pow(5,2) << "\n";
  system("pause");
  int f = 8;
  scanf("%d", &f);
  //da pra subrair direto do scanf
  printf("Valor: %d", f - 1);
  int e[] = {1,2,3};
  test(e);
  int a = 10;
  int *b;
  //recebe o ponteiro da variavel a
  b = &a;
  //mostra o conteudo da varivel b, ou seja, o ponteiro da variavel a
  cout<< "\n" << b;
  //mostra o conteudo que esta no ponteiro
  cout << "\n" << *b << "\n";
  //mesma coisa só q com struct
    str c;
    c.a = 1;
    c.b = 2;
    c.c = 3;
    str *d;
    d = &c;
    cout << (*d).a;

  int valor;

  printf ("Digite um valor de 1 a 7: ");
  scanf("%d", &valor);

  switch ( valor )
  {
     case 1 :
       printf ("Domingo\n");
     break;

     case 2 :
       printf ("Segunda\n");
     break;

     case 3 :
        printf ("Terça\n");
     break;

     case 4 :
        printf ("Quarta\n");
     break;

     case 5 :
        printf ("Quinta\n");
     break;

     case 6 :
        printf ("Sexta\n");
     break;

     case 7 :
        printf ("Sabado\n");
     break;

     default :
       printf ("Valor invalido!\n");
  }

  getch();
  return 0;
}
