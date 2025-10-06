import javax.swing.*;
import java.awt.*;

public class Exo4 {
    public static void main(String[] args) {
        JFrame fenetre = new JFrame("Mes boutons");

        // Création du panneau avec disposition GridLayout : 2 rangées, 3 colonnes
        JPanel panneau = new JPanel();
        panneau.setLayout(new GridLayout(2, 3));

        // Création des boutons
        JButton bouton1 = new JButton("Un");
        JButton bouton2 = new JButton("Deux");
        JButton bouton3 = new JButton("Trois");
        JButton bouton4 = new JButton("Quatre");
        JButton bouton5 = new JButton("Cinq");

        // Ajout des boutons au panneau
        panneau.add(bouton1);
        panneau.add(bouton2);
        panneau.add(bouton3);
        panneau.add(bouton4);
        panneau.add(bouton5);

        // Ajout du panneau à la fenêtre
        fenetre.getContentPane().add(panneau);

        // Paramètres de la fenêtre
        fenetre.setSize(new Dimension(496, 78));
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fenetre.setVisible(true);
    }
}