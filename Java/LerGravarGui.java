import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.lang.String;
class LerGravarGui{
      public static void main(String[] args) {
        JFrame frame = new JFrame("Encriptator 2000");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 400);

        JPanel painel = new JPanel();
        JLabel texto = new JLabel("Caminho do texto");
        JTextField campoTexto = new JTextField(40);
        JButton ok = new JButton("OK");

        JButton cancelar = new JButton("Cancelar");
        painel.add(texto);
        painel.add(campoTexto);
        painel.add(ok);
        painel.add(cancelar);

        JPanel painel2 = new JPanel();
        JTextArea areaTexto = new JTextArea(27, 30);
        ImageIcon icon = new ImageIcon("nene-chan.jpg");
        painel2.add(areaTexto);
        painel2.add(new JLabel(icon));


        ok.addActionListener(e -> {
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

        cancelar.addActionListener(e -> {
            areaTexto.setText("");
        });

        JMenuBar barraMenu = new JMenuBar();
        JMenuItem menu2 = new JMenuItem(new AbstractAction("ler") {
            public void actionPerformed(ActionEvent e) {
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
            }
        });
        JMenuItem menu3 = new JMenuItem(new AbstractAction("Encriptar") {
            public void actionPerformed(ActionEvent e) {
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
                    String saida = JOptionPane.showInputDialog("Digite o nome do arquivo(sem a extensão)");
                    Writer arquivoTexto = new BufferedWriter(new FileWriter(saida+".criptator"));
                    for(int i = 0;i<textoArquivo.length();i++){
                        iCript = textoArquivo.charAt(i)-40;
                        sCript += (char) iCript;
                    }
                    arquivoTexto.write(sCript);
                    arquivoTexto.close();
                    areaTexto.setText(sCript);
                } catch (IOException ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(null, "Erro");
                }
            }
        });
        JMenuItem menu4 = new JMenuItem(new AbstractAction("Descriptar") {
            public void actionPerformed(ActionEvent e) {
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
                    String saida = JOptionPane.showInputDialog("Digite o nome do arquivo");
                    Writer arquivoTexto = new BufferedWriter(new FileWriter(saida));
                    for(int i = 0;i<textoArquivo.length();i++){
                        iCript = textoArquivo.charAt(i)+40;
                        sCript += (char) iCript;
                    }
                    arquivoTexto.write(sCript);
                    arquivoTexto.close();
                    areaTexto.setText(sCript);
                } catch (IOException ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(null, "Erro");
                }
            }
        });
        barraMenu.add(menu2);
        barraMenu.add(menu3);
        barraMenu.add(menu4);

        frame.getContentPane().add(BorderLayout.SOUTH, painel);
        frame.getContentPane().add(BorderLayout.CENTER, painel2);
        frame.getContentPane().add(BorderLayout.NORTH, barraMenu);
        frame.setVisible(true);
    }
}
