package booking.gui;

import javax.swing.*;
import java.awt.*;

public class FenetrePrincipale extends JFrame {
    public FenetrePrincipale() {
        setTitle("Booking - Accueil");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel titre = new JLabel("Bienvenue sur Booking", SwingConstants.CENTER);
        titre.setFont(new Font("Arial", Font.BOLD, 20));

        JButton btnReserver = new JButton("Réserver un hébergement");
        JButton btnConnexion = new JButton("Se connecter");

        JPanel panel = new JPanel(new GridLayout(3,1,10,10));
        panel.add(titre);
        panel.add(btnReserver);
        panel.add(btnConnexion);

        add(panel);
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new FenetrePrincipale());
    }
}
