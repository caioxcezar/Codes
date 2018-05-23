import java.util.*;
class Cap4{
  public static void main(String[] args) {
    Conta c1 = new Conta();
    Scanner sc = new Scanner(System.in);
    String tipo;
    double valor;
    System.out.print("Digite o numero da conta: ");
    c1.numero = sc.nextInt();
    System.out.print("Digite o titular da conta: ");
    c1.titular = sc.next();
    System.out.print("Digite o agencia da conta: ");
    c1.agencia = sc.next();
    System.out.print("Digite o data de abertura: ");
    c1.abertura = sc.next();
    System.out.print("Digite o saldo da conta: ");
    c1.saldo = sc.nextDouble();
    do{
      System.out.print("Digite o tipo de movimentacao: ");
      tipo = sc.next();
      System.out.print("Digite o valor: ");
      valor = sc.nextFloat();
    }while(!c1.movimentacao(tipo, valor));
    System.out.println(c1.dadosDaConta());
    System.out.println(c1.calcularRendimento());
  }
}
class Conta{
  String titular, agencia, abertura;
  int numero;
  double saldo;
  boolean movimentacao(String tipo, double valor){
    if(tipo.equals("saque"))
      this.saldo -= valor;
    else if(tipo.equals("deposito"))
      this.saldo += valor;
    else
      return false;
    return true;
  }
  String dadosDaConta(){
    String data = "O numero da conta: " + this.numero;
    data += "\nO titular da conta: " + this.titular;
    data += "\nA agencia da conta: " + this.agencia;
    data += "\nA data de abertura: " + this.abertura;
    data += "\nO saldo da conta: " + this.saldo;
    return data;
  }
  double calcularRendimento(){
    return (this.saldo *= 0.1);
  }
}
