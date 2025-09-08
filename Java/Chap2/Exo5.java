public class Exo5 {
    static class Oeuvre {
        private String nom;
        private String auteur;
        private Livre[] liste;
        private int index;

        Oeuvre(String nom, String auteur) {
            this.nom = nom;
            this.auteur = auteur;
            this.liste = new Livre[3];
            this.index = 0;
        }

        public void donnerLieu(Livre livre){
            if (index < this.liste.length) {
                this.liste[index] = livre;
                index++;
                livre.issu(this);
            }
        }
        public void afficher() {
            System.out.println("Œuvre : " + nom + " (" + auteur + ")");
            for (int i = 0; i < index; i++) {
                System.out.println("  Livre ISBN : " + liste[i].isbn + " (lié à " + liste[i].oeuvre.nom + ") : " +  liste[i].titre);
            }
        }

    }

    static class Livre {
        private int isbn;
        private String titre;
        private Oeuvre oeuvre;


        Livre(int isbn, String titre) {
            this.isbn = isbn;
            this.titre = titre;

        }

        public void issu(Oeuvre oeuvre) {
            this.oeuvre = oeuvre;
        }
    }

    public static void main(String[] args) {
        Oeuvre o1 = new Oeuvre("L'assassin royal", "Robin Hobb");
        Livre l1 = new Livre(1, "L'apprenti assassin");
        Livre l2 = new Livre(2, "L’assassin du roi");
        Livre l3 = new Livre(3, "La nef du crépuscule");

        o1.donnerLieu(l1);
        o1.donnerLieu(l2);
        o1.donnerLieu(l3);

        o1.afficher();
    }
}
