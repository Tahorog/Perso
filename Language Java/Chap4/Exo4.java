public class Exo4 {
    interface Client {
        void commander();
        void acheter();
    }

    interface Employe {
        void travailler();
    }

    interface Sportif {
        void jouer();
    }

    static public class Personne implements Client, Employe, Sportif {

        private String nom;

        public Personne(String nom) {
            this.nom = nom;
        }

        public void commander() {
            System.out.println(nom + " passe une commande.");
        }

        public void acheter() {
            System.out.println(nom + " achète un produit.");
        }

        public void travailler() {
            System.out.println(nom + " travaille.");
        }

        public void jouer() {
            System.out.println(nom + " joue à un sport.");
        }

        public static void main(String[] args) {
            Personne p1 = new Personne("Alice");

            p1.commander();
            p1.acheter();
            p1.travailler();
            p1.jouer();
        }
    }
}
