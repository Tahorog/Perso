import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Exo7 extends JFrame implements ActionListener {

    private JButton okButton;
    private JButton cancelButton;
    private JLabel label;

    public Exo7(String titre) {
        super(titre);

        Container container = getContentPane();
        container.setLayout(new BorderLayout());

        okButton = new JButton("OK");
        cancelButton = new JButton("Cancel");
        label = new JLabel("Zone de texte", JLabel.CENTER);

        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());
        panel.add(okButton);
        panel.add(cancelButton);

        okButton.addActionListener(this);
        cancelButton.addActionListener(this);

        container.add(panel, BorderLayout.CENTER);
        container.add(label, BorderLayout.SOUTH);

        setSize(100, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == okButton) {
            label.setText("OK");
        } else if (e.getSource() == cancelButton) {
            label.setText("Cancel");
        }
    }

    public static void main(String[] args) {
        new Exo7("Mon Bouton");
    }
}
