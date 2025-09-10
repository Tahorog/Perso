public class Exo15 {
    static class Personne {
        public boolean vivant;
        private Personne conjoint;
        public String nom;

        public Personne(boolean vivant, String nom) {
            this.vivant = vivant;
            this.nom = nom;
        }

        public void pacser(Personne p) {
            this.conjoint =p;
            p.conjoint=this;

            System.out.println("Pacse entre : " + p.nom + " / " + this.nom);
        }

    }

    static class Homme extends Personne {
        public Homme(boolean vivant, String nom) {
            super(vivant, nom);
        }
    }

    static class Femme extends Personne {
        public Femme(boolean vivant, String nom) {
            super(vivant, nom);
        }
    }

    public static void main (String [] args){
        Homme h1 = new Homme(true, "Raph");
        Femme f1 = new Femme(false, "Rat");

        h1.pacser(f1);
    }
}
