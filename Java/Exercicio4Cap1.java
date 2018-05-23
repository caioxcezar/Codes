import javax.swing.JOptionPane;
class Exercicio4Cap1{
  public static void main (String[] args){
    String aux = "";
    float arq;
    aux = JOptionPane.showInputDialog("Digite o tamanho do arquivo em bytes: ");
    arq = Float.parseFloat(aux);
    JOptionPane.showMessageDialog(null, "Tamanho do arquivo em bytes: " + arq + "\nSegundos necessarios para donwload: " + (arq / 2048),
      "Tempo de conclusao do download",
      JOptionPane.INFORMATION_MESSAGE);
  }
}
