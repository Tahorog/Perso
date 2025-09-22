public class Exo6 {
    static class Personne {
        protected String nom;
        protected int age;
        protected Sport sport;

        public Personne(String nom, int age, Sport sport) {
            this.nom = nom;
            this.age = age;
            this.sport = sport;
        }

        public void afficherInfos() {
            System.out.println("Nom: " + nom + ", Âge: " + age);
            if (sport != null) {
                System.out.println("Sport pratiqué: " + sport.getNom());
            } else {
                System.out.println("Aucun sport pratiqué.");
            }
        }
    }

    static class Salarie extends Personne {
        private String entreprise;

        public Salarie(String nom, int age, String entreprise, Sport sport) {
            super(nom, age, sport);
            this.entreprise = entreprise;
        }

        public void afficherInfos() {
            super.afficherInfos();
            System.out.println("Entreprise: " + entreprise);
        }
    }

    static class Liberal extends Personne {
        private String profession;

        public Liberal(String nom, int age, String profession, Sport sport) {
            super(nom, age, sport);
            this.profession = profession;
        }

        public void afficherInfos() {
            super.afficherInfos();
            System.out.println("Profession libérale: " + profession);
        }
    }

    static class Sport {
        private String nom;

        public Sport(String nom) {
            this.nom = nom;
        }

        public String getNom() {
            return nom;
        }
    }


    public static void main(String[] args) {
        Sport boxe = new Sport("Boxe");
        Sport mma = new Sport("MMA");

        Salarie s1 = new Salarie("Capucine", 30, "Poubelle&Cie", boxe);

        Liberal l1 = new Liberal("Bob", 40, "Chômeur", mma);

        s1.afficherInfos();
        System.out.println("-------------------");
        l1.afficherInfos();
    }


}
