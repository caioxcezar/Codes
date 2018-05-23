import java.util.*;
public class Exercicio1Cap1 {
    public static void main (String[] args){
        float base, altura;
        System.out.println("Programa para calcular a area de um triangulo");
        System.out.print("Digite a base: ");
        Scanner sc = new Scanner(System.in);
        base = sc.nextFloat();
        System.out.print("Digite a alt2ura: ");
        sc = new Scanner(System.in);
        altura = sc.nextFloat();
        System.out.println("A area deste triangulo: " + (base*altura/2));
    }
}
