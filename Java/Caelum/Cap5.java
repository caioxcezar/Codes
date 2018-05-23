import java.util.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
class Cap5{
  public static void main(String[] args) {
    Conta c1 = new Conta();
    Scanner sc = new Scanner(System.in);
    String tipo;
    double valor;
    System.out.print("Digite o numero da conta: ");
    c1.setNumero(sc.nextInt());
    System.out.print("Digite o titular da conta: ");
    c1.setTitular(sc.next());
    System.out.print("Digite o data de abertura: ");
    c1.setAbertura(sc.next());
    System.out.println(c1.abertura);
    /*System.out.print("Digite o agencia da conta: ");
    c1.agencia = sc.next();
    System.out.print("Digite o saldo da conta: ");
    c1.saldo = sc.nextDouble();*/
    do{
      System.out.print("Digite o tipo de movimentacao: ");
      tipo = sc.next();
      System.out.print("Digite o valor: ");
      valor = sc.nextFloat();
    }while(!c1.movimentacao(tipo, valor));
    System.out.println(c1.dadosDaConta());
    System.out.println(c1.getRendimento());
  }
}
class Conta{
  SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
  private static int identificador;
  private String titular, agencia;
  Date abertura;
  private int numero;
  private double saldo;
  public Conta(){ Conta.identificador += 1; }
  public Conta(String titular){ Conta.identificador += 1; }
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
  public double getRendimento(){ return (this.saldo *= 0.1); }
  public String getTitular(String titular){ return this.titular; }
  public void setTitular(String titular){ this.titular = titular; }
  public void setNumero(int numero){ this.numero = numero; }
  public int getIdentificador(int identificador){ return Conta.identificador; }
  public void setAbertura(String data){
    try {
        this.abertura = formatter.parse(data);
    } catch (ParseException e) { e.printStackTrace(); }
  }
}
