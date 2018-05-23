import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.lang.String;
class Criptator{
      public static void main(String[] args) {
        JFrame frame = new JFrame("Encriptator 2000");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 400);

        JPanel painel = new JPanel();
        JLabel texto = new JLabel("Caminho do texto");
        JTextField campoTexto = new JTextField(25);
        JButton gravarButton = new JButton("Gravar");
        JButton limparButton = new JButton("Limpar Texto");
        painel.add(texto);
        painel.add(campoTexto);
        painel.add(gravarButton);
        painel.add(limparButton);

        JPanel painel2 = new JPanel();
        JTextArea areaTexto = new JTextArea(27, 30);
        ImageIcon icon = new ImageIcon("nene-chan.jpg");
        painel2.add(areaTexto);
        painel2.add(new JLabel(icon));


        gravarButton.addActionListener(e -> {
            String textoArquivo = areaTexto.getText();
            String caminho = campoTexto.getText();
            File arquivo = new File(caminho);
            JOptionPane.showMessageDialog(null, "Sucesso!");
            try (Writer arquivoTexto = new BufferedWriter(new FileWriter(arquivo))) {
                arquivoTexto.write(textoArquivo);
                arquivoTexto.close();
            } catch (IOException ex) {
                ex.printStackTrace();
                JOptionPane.showMessageDialog(null, "Erro");
            }
        });

        limparButton.addActionListener(e -> {
            areaTexto.setText("");
        });

        JPanel topPanel = new JPanel();
        JButton lerButton = new JButton("Ler Texto");
        JButton encriptarButton = new JButton("Encriptar");
        JButton desencriptarButton = new JButton("Desencriptar");
        lerButton.addActionListener(e -> {
          String textoArquivo = "", st;
          String caminho = campoTexto.getText();
          File arquivo = new File(caminho);
          try(BufferedReader br = new BufferedReader(new FileReader(arquivo))){
              while ((st = br.readLine()) != null){
                  textoArquivo+=st;
                  textoArquivo+="\n";
              }
              areaTexto.setText(textoArquivo);
          } catch (IOException ex) {
              ex.printStackTrace();
              JOptionPane.showMessageDialog(null, "Erro");
          }
        });
        encriptarButton.addActionListener(e -> {
          String textoArquivo = "", st, sCript = "";
          int iCript;
          String caminho = campoTexto.getText();
          File arquivo = new File(caminho);
          try{
              BufferedReader br = new BufferedReader(new FileReader(arquivo));
              while ((st = br.readLine()) != null){
                  textoArquivo+=st;
                  textoArquivo+="\n";
              }
              String saida = JOptionPane.showInputDialog("Digite o nome do arquivo de saida (sem a extensão)");
              if(saida != null){
                Writer arquivoTexto = new BufferedWriter(new FileWriter(saida+".criptator"));
                for(int i = 0;i<textoArquivo.length();i++){
                    iCript = (textoArquivo.charAt(i))-10;
                    sCript += (char) iCript;
                }
                arquivoTexto.write(sCript);
                arquivoTexto.close();
                JOptionPane.showMessageDialog(null, "Sucesso!");
                areaTexto.setText(sCript);
              }
          } catch (IOException ex) {
              ex.printStackTrace();
              JOptionPane.showMessageDialog(null, "Erro");
          }
        });
        desencriptarButton.addActionListener(e -> {
          String textoArquivo = "", st, sCript = "";
          int iCript;
          String caminho = campoTexto.getText();
          File arquivo = new File(caminho);
          try{
              BufferedReader br = new BufferedReader(new FileReader(arquivo));
              while ((st = br.readLine()) != null){
                  textoArquivo+=st;
                  textoArquivo+="\n";
              }
              String saida = JOptionPane.showInputDialog("Digite o nome do arquivo de saida");
              if(saida!=null){
                Writer arquivoTexto = new BufferedWriter(new FileWriter(saida));
                for(int i = 0;i<textoArquivo.length();i++){
                    iCript = textoArquivo.charAt(i)+10;
                    sCript += (char) iCript;
                }
                arquivoTexto.write(sCript);
                arquivoTexto.close();
                JOptionPane.showMessageDialog(null, "Sucesso!");
                areaTexto.setText(sCript);
              }
          } catch (IOException ex) {
              ex.printStackTrace();
              JOptionPane.showMessageDialog(null, "Erro");
          }
        });
        topPanel.add(lerButton);
        topPanel.add(encriptarButton);
        topPanel.add(desencriptarButton);

        frame.getContentPane().add(BorderLayout.SOUTH, painel);
        frame.getContentPane().add(BorderLayout.CENTER, painel2);
        frame.getContentPane().add(BorderLayout.NORTH, topPanel);
        frame.setVisible(true);
    }
}
/*
JFileChooser fc = new JFileChooser();
int option = fc.showOpenDialog(jPanel1);
if (option == JFileChooser.APPROVE_OPTION) {
    File file = fc.getSelectedFile();
    System.out.println("Arquivo selecionado: " + file.getCanonicalPath());
} else {
    System.out.println("Nenhum arquivo selecionado!"<img src="http://javafree.uol.com.br/forum/images/smiles/icon_wink.gif">;
}
*/
