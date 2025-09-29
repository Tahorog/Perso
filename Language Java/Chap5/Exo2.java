import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Exo2 {
    static class Fichier{
        public String nom;

        public Fichier(String nom){
            this.nom = nom;
        }

        public void openFile() {
            try {
                Scanner sc = new Scanner(new File(nom));
                while (sc.hasNextLine()) {
                    System.out.println(sc.nextLine());
                }
                sc.close();
            } catch (FileNotFoundException e) {
                System.out.println("Erreur : fichier '" + nom + "' introuvable !");
            }
        }
    }

    public static void main(String[] args){
        Scanner clavier = new Scanner(System.in);
        System.out.print("Entrez le nom du fichier : ");
        String nomFichier = clavier.nextLine();

        Fichier f = new Fichier(nomFichier);
        f.openFile();
    }
}
