import java.util.ArrayList;

public class Exo8 {
    static class Pile {
        private Liste liste;
        public Pile(Liste liste) {
            this.liste = liste;
        }
        public Object depiler() {
            liste.Dernier();
            Object obj = liste.Supprimer();
            return obj;
        }
        public void empiler(Object obj) {
            liste.Dernier();
            liste.Ajouter(obj);
        }
        public void afficherPile() {
            liste.afficher();
        }
    }
    static class Liste {
        private ArrayList<Object> tab;
        private int position;

        public Liste() {
            this.tab = new ArrayList<>();
            this.position = -1;
        }
        public void Premier() {
            this.position = 0;
        }
        public void Dernier() {
            if (tab.isEmpty()) {
                System.out.println("Erreur.");
                position = -1;
            } else {
                position = tab.size() - 1;
            }
        }
        public Object Suivant() {
            if (tab.isEmpty()) {
                return null;
            }
            if (position >= tab.size() - 1) {
                return null;
            }
            position++;
            return tab.get(position);
        }
        public Object Supprimer() {
            if (tab.isEmpty() || position == -1) {
                return null;
            }
            Object obj = tab.remove(position);
            position--;
            return obj;
        }
        public void Ajouter(Object obj) {
            if (position == -1 || position >= tab.size()) {
                tab.add(obj);
                position = tab.size() - 1;
            } else {
                tab.add(position + 1, obj);
                position++;
            }
        }
        public void afficher() {
            if (tab.isEmpty()) {
                System.out.println("Liste vide.");
            } else {
                for (Object obj : tab) {
                    System.out.println(obj);
                }
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
