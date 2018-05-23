import java.util.Scanner;
class Cap3{
  public static void main (String[] args){
    char opc;
    do{
      int x = 0;
      double y = 0;
      System.out.print("Escolha o exercicio: ");
      Scanner sc = new Scanner(System.in);
      opc = sc.next().charAt(0);
      switch(opc){
        case '1':
          for(int i = 150; i <=300; i++)
            System.out.print(i+"\t");
          break;
        case '2':
          for(int i = 1; i <=1000; i++)
          {
            x += i;
            System.out.print(x+"\t");
          }
          break;
        case '3':
          for(int i = 1; i<= 100; i++)
            if(i%3==0)
              System.out.print(i+"\t");
          break;
        case '4':
          for(int i = 1;i<=10;i++){
            x = 1;
            for(int j = i;j>=1;j--)
              x *= j;
            System.out.println("Fatorial de: " + i + " = " + x);
          }
          break;
        case '5':
          for(int i = 1;i<=20;i++){
            y = 1;
            for(int j = i;j>=1;j--)
              y *= j;
              System.out.println("Fatorial de: " + i + " = " + y);
            }
          break;
        case '6'://Desafio
            int b = 1, c = 0;
            System.out.println(0);
            System.out.println(1);
            while(b<=100){
              System.out.println((b + c));
              b += c; c = b - c;
            }
          break;
        case '7':
          System.out.print("Digite o valor de x: ");
          x = sc.nextInt();
          if(x%2!=0)
            System.out.println("Numero impar: "+(3*x+1));
          else
            System.out.println("Numero par: "+(x/2));
          break;
        default:
          System.out.println("Caracter invalido");
          break;
        case '8':
          System.out.print("Digite o tamanho da tabela: ");
          x = sc.nextInt();
          for(int i = 1; i<=x; i++){
            for(int j = 1; j<=x; j++){
              if(j<=i)
                System.out.print(i * j+ " ");
            }
            System.out.println("");
          }
      }
    }while(opc!='9');
  }
}
