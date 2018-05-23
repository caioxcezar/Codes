import javax.swing.JOptionPane;
class martinha{
  public static void integral3X2 (float a, float b, int c)
  {
    float largura = ((b-a)/c);
    float altura = ((largura/2) + a);
    float resultado = 0;
    for(int i = 0; i < c; i++) {
      resultado += 3.0f*(Math.pow(altura,2.0f))*(largura);
      altura += largura;
    }
    JOptionPane.showMessageDialog(null, "\nA area estimada: " + resultado + "\nA area real: " + ((float) (3*(Math.pow(b,3)/3) - 3*(Math.pow(a,3)/3))));
    //resultado = (float) (3*(Math.pow(b,3)/3) - 3*(Math.pow(a,3)/3));
    //JOptionPane.showMessageDialog(null, "\nA area real: " + resultado);
  }
  public static void main (String[] args){
    float a, b;
    int n, opc = 0;
    String aux = "";
    while(opc != 4) {
      aux = JOptionPane.showInputDialog("Grupos de Funcao - 3\n1. 3X^2\n2. e^x\n3. -cos(x)\n4. Sair");
      opc = Integer.parseInt(aux);
      aux = JOptionPane.showInputDialog("Digite o limite inicial");
      a = Float.parseFloat(aux);
      aux = JOptionPane.showInputDialog("Digite o limite final");
      b = Float.parseFloat(aux);
      aux = JOptionPane.showInputDialog("Digite a quantidade de retangulos");
      n = Integer.parseInt(aux);
      switch (opc) {
        case 1:
          integral3X2(a, b, n);
          break;
        case 2:
          //integralEX(a, b, n);
          break;
        case 3:
          //integralCosX(a, b, n);
          break;
        default:
          JOptionPane.showMessageDialog(null, "Codigo invalido");
      }
      aux = JOptionPane.showInputDialog("Digite 1 para reiniciar e 4 para sair");
      opc = Integer.parseInt(aux);
    }
  }
}
