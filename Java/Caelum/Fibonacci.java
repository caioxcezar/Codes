import javax.swing.JOptionPane;
class Fibonacci{
  static float fibonacci(int n){
    if(n < 2)
      return n;
    else
      return fibonacci(n-1)+fibonacci(n-2);
  }
  public static void main(String[] args){
    int n = Integer.parseInt(JOptionPane.showInputDialog("Digite um numero: "));
    for(int i = 0; i<n;i++)
      System.out.println(fibonacci(i) + "\t");
  }
}
