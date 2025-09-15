public class Exo6 {
    static class Arbre{
        private int taille;

        public  Arbre(){
            this.taille = 0;
        }

        public Arbre(int taille){
            this.taille = taille;
        }

        public void afficher(){
            System.out.println("Taille: " + taille);
        }
    }

    public static void main(String[] args) {
        Arbre a1 = new Arbre();
        a1.afficher();

        Arbre a2 = new Arbre(120);
        a2.afficher();
    }
}
