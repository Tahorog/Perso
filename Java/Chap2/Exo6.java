public class Exo6 {
    static class Mariage {
        String lieu;
        int date;
        private Homme mari;
        private Femme épouse;
        Mariage(String name, int date) {
            this.lieu = name;
            this.date = date;
        }

        public void marier(Homme mari, Femme épouse) {
            this.mari = mari;
            this.épouse = épouse;

        }
    }

    static class Homme{
        String nom;
        int age;
        Homme(String name, int age) {
            this.nom = name;
            this.age = age;
        }
    }

    static class Femme {
        String nom;
        int age;
        Femme(String name, int age) {
            this.nom = name;
            this.age = age;
        }
    }
    public static void main(String[] args) {
        Homme h1 = new Homme("Raphael", 19);
        Femme f1 = new Femme("bodypillow", 6);
        Mariage m1 = new Mariage("Cave", 11092001);

        m1.marier(h1, f1);
    }
}
