import javax.swing.*;
import java.io.File;
public class Exo1 {
    public static void main(String[] args) {
        JFileChooser chooser = new JFileChooser("D:/Java");

        int returnVal = chooser.showOpenDialog(null);

        if (returnVal == JFileChooser.APPROVE_OPTION) {

            File fichier = chooser.getSelectedFile();

            System.out.println("Fichier sélectionné : " + fichier.getName());
            System.out.println("Chemin complet : " + fichier.getAbsolutePath());
        } else {
            System.out.println("Aucun fichier sélectionné.");
        }
    }
}
