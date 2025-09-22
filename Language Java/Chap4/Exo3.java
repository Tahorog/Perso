import java.util.Scanner;

public class Exo3 {
    static abstract class  Personnels {
        protected int heuresTravaillees;
        protected String nom;

        public Personnels(String nom) {
            this.heuresTravaillees = 0;
            this.nom = nom;
        }
        public void setHeuresTravaillees(int heures) {
            this.heuresTravaillees = heures;
        }
        public abstract void afficher();
    }

    static class Enseignants extends Personnels {
        public Enseignants(String nom) {
            super(nom);
        }
        public void afficher() {
            System.out.println("Enseignants : " + this.nom);
        }


    }public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Nom de l'enseignant : ");
        String nom = sc.nextLine();

        Enseignants e1 = new Enseignants(nom);

        int a;
        do {
            System.out.print("Heures travaillées : ");
            a = sc.nextInt();
            if (a <= 0) {
                System.out.println("Il faut une valeur strictement positive.");
            }
        } while (a <= 0);

        e1.setHeuresTravaillees(a);
        e1.afficher();
        sc.close();
    }
}
