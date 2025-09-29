import java.util.Scanner;

public class Exo1 {
    static class DivisionParZero extends Exception {
        private int dividende;
        private int diviseur;

        public DivisionParZero(int dividende, int diviseur) {
            this.dividende = dividende;
            this.diviseur = diviseur;
        }

        public DivisionParZero(String message) {
            super(message);
        }

        public String getError(){
            return super.getMessage();
        }

        public float diviserNombres() throws DivisionParZero {
            if (diviseur == 0) {
                throw new DivisionParZero(dividende, diviseur);
            }
            return (float) dividende / diviseur;
        }

        public void afficherNombres() {
            System.out.println("Dividende : " + dividende + ", Diviseur : " + diviseur);
        }

        public void afficherErreur() {
            System.out.println(getError());
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Entrez le dividende : ");
            int a = Integer.parseInt(sc.nextLine());

            System.out.print("Entrez le diviseur : ");
            int b = Integer.parseInt(sc.nextLine());

            DivisionParZero division = new DivisionParZero(a, b);

            try {
                float resultat = division.diviserNombres();
                System.out.println("Résultat de la division : " + resultat);
            } catch (DivisionParZero e) {
                e.afficherErreur();
            } finally {
                division.afficherNombres();
            }

        } catch (Exception e) {
            System.out.println("Erreur de saisie.");
        }

        sc.close();
    }
}
