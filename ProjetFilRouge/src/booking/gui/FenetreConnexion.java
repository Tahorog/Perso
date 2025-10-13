package booking.gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FenetreConnexion extends JFrame {
    private JTextField emailField;
    private JPasswordField passwordField;
    private JButton btnConnexion;
    private JButton btnAnnuler;

    public FenetreConnexion() {
        setTitle("Connexion - Booking");
        setSize(400, 250);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new GridLayout(4, 2, 10, 10));

        JLabel emailLabel = new JLabel("Email :");
        emailField = new JTextField();
        JLabel passwordLabel = new JLabel("Mot de passe :");
        passwordField = new JPasswordField();

        btnConnexion = new JButton("Se connecter");
        btnAnnuler = new JButton("Annuler");

        add(emailLabel); add(emailField);
        add(passwordLabel); add(passwordField);
        add(btnConnexion); add(btnAnnuler);

        btnConnexion.addActionListener(e -> {
            String email = emailField.getText();
            JOptionPane.showMessageDialog(this, "Bienvenue " + email + " !");
            dispose();
        });

        btnAnnuler.addActionListener(e -> dispose());

        setVisible(true);
    }
}
