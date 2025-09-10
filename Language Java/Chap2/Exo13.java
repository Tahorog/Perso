public class Exo13 {
    static class Vertebres {
        public String nom;
        public int age;

        public Vertebres() {
            this.nom = "inconnu";
            this.age = 0;
        }

        public Vertebres(String nom, int age) {
            this.nom = nom;
            this.age = age;
        }

        public void afficher(){
            System.out.println("Nom : " + this.nom + " | Age : " + this.age);
        }
    }

    static class Poissons extends Vertebres {
        public int taille;
        public Poissons() {
            super();
            this.taille = 0;

        }

        public Poissons(String nom, int taille, int age) {
            super(nom, age);
            this.taille = taille;
        }

        public void afficher(){
            System.out.println("Poisson : " + this.taille + " / " + this.age + " / " + this.nom);
        }
    }

    static class Oiseaux extends Vertebres {
        public String couleur;
        public Oiseaux() {
            super();
            this.couleur = "Inconnue";

        }

        public Oiseaux(String nom, String couleur, int age) {
            super(nom, age);
            this.couleur = couleur;
        }

        public void afficher(){
            System.out.println("Oiseaux : " + this.couleur + " / " + this.age + " / " + this.nom);
        }
    }

    static class Reptiles  extends Vertebres {
        public boolean venin;
        public Reptiles() {
            super();
            this.venin = false;
        }
        public Reptiles(String nom, int age, boolean venin) {
            super(nom, age);
            this.venin = true;
        }
        public void afficher(){
            System.out.println("Reptiles : " + this.venin + " / " + this.age + " / " + this.nom);
        }
    }

    static class Batraciens  extends Vertebres {
        public int croassement;
        public Batraciens(){
            super();
            this.croassement = 0;
        }
        public Batraciens(String nom, int age, int croassement) {
            super(nom, age);
            this.croassement = croassement;
        }
        public void afficher(){
            System.out.println("Batraciens : " + this.croassement +  " / " + this.age + " / " + this.nom);
        }
    }

    static class Mammifères  extends Vertebres {
        public int masse;
        public Mammifères() {
            super();
            this.masse = 0;
        }

        public Mammifères(String nom, int age, int masse) {
            super(nom, age);
            this.masse = masse;
        }
        public void afficher(){
            System.out.println("Mammifères : " + this.masse +  " / " + this.age + " / " + this.nom);
        }
    }
    public static void main(String[] args) {
        Poissons poisson = new Poissons("Piranha", 12, 3);
        Reptiles reptiles = new Reptiles("Cocodile", 3, false);
        Mammifères mammifères = new Mammifères("La maman de raph", 247, 65000378);
        Oiseaux oiseaux = new Oiseaux("Pigeon", "vert", 1);
        Batraciens batraciens = new Batraciens("Crapeau", 12, 3);
        Vertebres v1 = new Vertebres();
        Vertebres v2 = new Vertebres("Raphael", 19);


        poisson.afficher();
        System.out.println("____________________");
        reptiles.afficher();
        System.out.println("____________________");
        mammifères.afficher();
        System.out.println("____________________");
        oiseaux.afficher();
        System.out.println("____________________");
        batraciens.afficher();
        System.out.println("____________________");
        v1.afficher();
        System.out.println("____________________");
        v2.afficher();
    }
}
