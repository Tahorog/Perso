// Imports nécessaires
import javax.swing.*;
import java.awt.*;

public class Exo2 extends JFrame {
    public static void main(String[] args) {

        Exo2 fenetre = new Exo2();

        JPanel panneau = new JPanel();
        panneau.setLayout(new BorderLayout());

        JButton bouton1 = new JButton("Un");
        JButton bouton2 = new JButton("Deux");
        JButton bouton3 = new JButton("Trois");
        JButton bouton4 = new JButton("Quatre");
        JButton bouton5 = new JButton("Cinq");

        panneau.add(bouton1, BorderLayout.NORTH);
        panneau.add(bouton2, BorderLayout.EAST);
        panneau.add(bouton3, BorderLayout.CENTER);
        panneau.add(bouton4, BorderLayout.WEST);
        panneau.add(bouton5, BorderLayout.SOUTH);

        fenetre.getContentPane().add(panneau);

        fenetre.setTitle("Mes boutons");
        fenetre.setSize(new Dimension(496, 78));
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);
    }
}
