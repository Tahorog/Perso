import javax.swing.*;
import java.awt.*;

public class Exo6 extends JFrame {

    private JButton bouton;

    public Exo6(String titre) {

        super(titre);

        Container contenu = this.getContentPane();

        contenu.setLayout(new FlowLayout());

        bouton = new JButton("Mon bouton");

        contenu.add(bouton);

        this.setSize(200, 100);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.setVisible(true);
    }

    public static void main(String[] args) {
        new Exo6("Mon Bouton");
    }
}
