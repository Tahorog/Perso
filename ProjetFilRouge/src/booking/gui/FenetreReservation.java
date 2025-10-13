package booking.gui;

import booking.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Date;

public class FenetreReservation extends JFrame {
    private JComboBox<String> hebergementsBox;
    private JButton btnReserver;
    private JTextArea resultatArea;

    public FenetreReservation(CollectionHebergements collection, Client client) {
        setTitle("Réserver un hébergement");
        setSize(500, 300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        hebergementsBox = new JComboBox<>();
        for (Hebergement h : collection.getHebergements())
            hebergementsBox.addItem(h.retournerInfos());

        btnReserver = new JButton("Réserver");
        resultatArea = new JTextArea(5, 30);
        resultatArea.setEditable(false);

        JPanel panel = new JPanel(new GridLayout(3, 1, 10, 10));
        panel.add(hebergementsBox);
        panel.add(btnReserver);
        panel.add(new JScrollPane(resultatArea));

        btnReserver.addActionListener(e -> {
            Hebergement h = collection.getHebergements().get(hebergementsBox.getSelectedIndex());
            client.reserverHebergement(h, new Date(), new Date());
            resultatArea.setText("Réservation effectuée pour " + client.getNom() + " :\n" + h.retournerInfos());
        });

        add(panel);
        setVisible(true);
    }
}
