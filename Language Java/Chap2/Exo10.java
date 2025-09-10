public class Exo10 {
    static class Pile {
        private Liste liste;

        public Pile(Liste liste) {
            this.liste = liste;
        }

        public Livre depiler(){
            liste.Dernier();
            Livre livre = liste.Supprimer();
            return livre;
        }

        public void empiler(Livre livre){
            liste.Dernier();
            liste.ajouter(livre);
        }

        public void afficherPile() {
            liste.afficher();
        }
    }
    static class Liste {
        public static final int MAX = 3;
        public Livre[] tab =  new Livre[MAX];
        public int position = -1;

        public Liste(){
            this.position = -1;
            this.tab = new Livre[MAX];
        }

        public void Premier(){
            this.position = 0;
        }
        public void Dernier() {
            int dernier = -1;
            for(int i = 0; i < MAX; i++) {
                if(tab[i] != null) {
                    dernier = i;
                }
            }
            position = dernier;
        }
        public Livre Suivant(){
            if (position == -1 || position == MAX - 1){
                return null;
            } else {
                position++;
                return tab[position];
            }
        }

        public Livre Supprimer(){
            if (position == -1){
                return null;
            } else {
                Livre livre = tab[position];
                tab[position] = null;
                position--;
                return livre;
            }
        }

        public void ajouter(Livre livre) {
            try {
                position++;
                tab[position] = livre;
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Liste pleine, impossible d'ajouter.");
                position--;
            }
        }

        public void afficher() {
            for (int i = 0; i <= position; i++) {
                System.out.println(tab[i]);
            }
        }
    }

    static class Livre {
        private int isbn;
        private String titre;


        Livre(int isbn, String titre) {
            this.isbn = isbn;
            this.titre = titre;

        }

        public String toString() {
            return "Livre{isbn=" + isbn + ", titre='" + titre + "'}";
        }

    }

    public static void main(String[] args) {
        Livre l1 = new Livre(1, "L'apprenti assassin");
        Livre l2 = new Livre(2, "L’assassin du roi");
        Livre l3 = new Livre(3, "La nef du crépuscule");
        Livre l4 = new Livre(4, "Le poison de la vengeance");

        Liste liste = new Liste();
        Pile p1 = new Pile(liste);

        p1.afficherPile();
        System.out.println("___________________________________");

        p1.empiler(l1);
        p1.afficherPile();
        System.out.println("___________________________________");
        p1.empiler(l2);
        p1.afficherPile();
        System.out.println("___________________________________");
        p1.empiler(l3);
        p1.afficherPile();
        System.out.println("___________________________________");
        p1.empiler(l4);
        p1.afficherPile();
        System.out.println("___________________________________");

        p1.depiler();
        p1.afficherPile();
        System.out.println("___________________________________");
        p1.depiler();
        p1.afficherPile();
        System.out.println("___________________________________");
        p1.depiler();
        p1.afficherPile();
        System.out.println("___________________________________");
        p1.depiler();
        p1.afficherPile();
        System.out.println("___________________________________");
    }
}
