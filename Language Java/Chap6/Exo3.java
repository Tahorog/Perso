// Imports nécessaires
import javax.swing.*;
import java.awt.*;

public class Exo3 extends JFrame {
    public static void main(String[] args) {

        Exo3 fenetre = new Exo3();

        JPanel panneau = new JPanel();
        panneau.setLayout(new FlowLayout());

        JButton bouton1 = new JButton("Un");
        JButton bouton2 = new JButton("Deux");
        JButton bouton3 = new JButton("Trois");
        JButton bouton4 = new JButton("Quatre");
        JButton bouton5 = new JButton("Cinq");

        panneau.add(bouton1);
        panneau.add(bouton2);
        panneau.add(bouton3);
        panneau.add(bouton4);
        panneau.add(bouton5);

        fenetre.getContentPane().add(panneau);

        fenetre.setTitle("Mes boutons");
        fenetre.setSize(new Dimension(496, 78));
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);
    }
}
