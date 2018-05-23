import javax.swing.JOptionPane;
class Exercicio2Cap1{
  public static void main (String[] args){
    String aux = "";
    float peso, altura, imc;
    aux = JOptionPane.showInputDialog("Digite a altura: ");
    altura = Float.parseFloat(aux);
    aux = JOptionPane.showInputDialog("Digite o peso: ");
    peso = Float.parseFloat(aux);
    imc = peso/(altura*altura);
    if(imc < 18.5)
      JOptionPane.showMessageDialog(null, "Aabaixo do peso");
    else if(imc <= 18.5 || imc >= 24.4)
      JOptionPane.showMessageDialog(null, "Peso Ideal");
    else if(imc <= 24.5 || imc >= 29.9)
      JOptionPane.showMessageDialog(null, "Pre-Obesidade");
    else if(imc <= 30 || imc >= 34.9)
      JOptionPane.showMessageDialog(null, "Obesidade I");
    else if(imc <= 35 || imc >= 39.9)
      JOptionPane.showMessageDialog(null, "Obesidade II");
    else if(imc > 39.9)
      JOptionPane.showMessageDialog(null, "Obesidade III");
  }
}
