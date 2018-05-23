import javax.swing.*;
class GifTeste{
  public static void main(String[] args) {

      Icon icon = new ImageIcon("pika.gif");
      JLabel label = new JLabel(icon);

      JFrame f = new JFrame("Animation");
      f.getContentPane().add(label);
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      f.pack();
      f.setLocationRelativeTo(null);
      f.setVisible(true);
  }
}
