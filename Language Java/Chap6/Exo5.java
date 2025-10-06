import javax.swing.*;
import java.awt.*;

public class Exo5 {
    public static void main(String[] args) {
        JFrame fenetre = new JFrame("Mes boutons");
        JPanel panneau = new JPanel();

        panneau.setLayout(null);

        JButton bouton1 = new JButton("Un");
        JButton bouton2 = new JButton("Deux");
        JButton bouton3 = new JButton("Trois");
        JButton bouton4 = new JButton("Quatre");
        JButton bouton5 = new JButton("Cinq");

        bouton1.setBounds(34, 20, 90, 35);
        bouton2.setBounds(115, 82, 134, 36);
        bouton3.setBounds(60, 130, 90, 35);
        bouton4.setBounds(160, 180, 90, 35);
        bouton5.setBounds(100, 230, 90, 35);

        panneau.add(bouton1);
        panneau.add(bouton2);
        panneau.add(bouton3);
        panneau.add(bouton4);
        panneau.add(bouton5);

        fenetre.getContentPane().add(panneau);

        fenetre.setSize(300, 300);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);
    }
}