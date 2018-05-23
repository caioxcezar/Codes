import javax.swing.JOptionPane;
class Fatorial{
  static int fatorial(int x){
    if(x <= 1)
      return 1;
    return x*fatorial(x-1);
  }
  public static void main(String[] args) {
    int n = Integer.parseInt(JOptionPane.showInputDialog("Digite um numero: "));
    System.out.println(fatorial(n) + "\t");
  }
}
