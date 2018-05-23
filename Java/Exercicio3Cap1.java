import javax.swing.JOptionPane;
class Exercicio3Cap1{
  public static void main (String[] args){
    String aux = "";
    float v1, v2, imc;
    aux = JOptionPane.showInputDialog("Digite o numero 1: ");
    v1 = Float.parseFloat(aux);
    aux = JOptionPane.showInputDialog("Digite o numero 2: ");
    v2 = Float.parseFloat(aux);
    JOptionPane.showMessageDialog(null, "Soma: " + (v1+v2) + "\nSubtracao: " +
      (v1-v2) + "\nDivisao: " + (v1/v2) + "\nMultiplicacao: " + (v1*v2),
      "4 operacoes matematicas",
      JOptionPane.INFORMATION_MESSAGE);
  }
}
