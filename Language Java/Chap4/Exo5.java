public class Exo5 {

    interface Animal {
        void manger();
        void dormir();
        void faireSon();
    }

    static class Chien implements Animal {
        private String nom;
        private String race;

        public Chien(String nom, String race) {
            this.nom = nom;
            this.race = race;
        }

        public void manger() {
            System.out.println(nom + "Race : " + race + ", mange.");
        }

        public void dormir() {
            System.out.println(nom + " dort.");
        }

        public void faireSon() {
            System.out.println(nom + " aboie.");
        }
    }

    static class Chat implements Animal {
        private String nom;
        private String couleur;

        public Chat(String nom, String couleur) {
            this.nom = nom;
            this.couleur = couleur;
        }

        public void manger() {
            System.out.println(nom + "Couleur du chat : " + couleur + ", mange.");
        }

        public void dormir() {
            System.out.println(nom + " dort.");
        }

        public void faireSon() {
            System.out.println(nom + " miaule.");
        }
    }

    static class Oiseau implements Animal {
        private String espece;

        public Oiseau(String espece) {
            this.espece = espece;
        }

        public void manger() {
            System.out.println("L'oiseau (" + espece + ") mange.");
        }

        public void dormir() {
            System.out.println("L'oiseau (" + espece + ") dort.");
        }

        public void faireSon() {
            System.out.println("L'oiseau (" + espece + ") piaille.");
        }
    }


    public static void main(String[] args) {
        Animal a1 = new Chien("Dimitri", "Chihuahua");
        Animal a2 = new Chat("Orion", "Orange");
        Animal a3 = new Oiseau("Pigeon");

        a1.manger();
        a2.manger();
        a3.manger();

        a1.faireSon();
        a2.faireSon();
        a3.faireSon();

        if (a1 instanceof Chien) {
            Chien c = (Chien) a1;
            System.out.println("Ceci est bien un chien !");
        }

        if (a2 instanceof Chat) {
            Chat chat = (Chat) a2;
            System.out.println("Ceci est bien un chat !");
        }

        if (a3 instanceof Oiseau) {
            Oiseau o = (Oiseau) a3;
            System.out.println("Ceci est bien un oiseau !");
        }

    }
}
