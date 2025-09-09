public class Exo7 {
    static class Mariage {
        String lieu;
        int date;
        private Homme mari;
        private Femme epouse;
        private Contrat contrat;
        Mariage(String name, int date) {
            this.lieu = name;
            this.date = date;
        }

        public void marier(Homme mari, Femme epouse) {
            this.mari = mari;
            this.epouse = epouse;

        }

        public void passer(Contrat contrat){
            this.contrat = contrat;
        }

        public void afficher() {
            System.out.println("Mariage à " + lieu + " le " + date);
            System.out.println("Mari : " + mari.nom + " (" + mari.age + " ans)");
            System.out.println("Epouse : " + epouse.nom + " (" + epouse.age + " ans)");
            System.out.println("Contrat n° " + contrat.numero);
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

    static class Contrat {
        int numero;
        Contrat(int numero) {
            this.numero = numero;
        }
    }
    public static void main(String[] args) {
        Homme h1 = new Homme("Raphael", 19);
        Femme f1 = new Femme("bodypillow", 6);
        Mariage m1 = new Mariage("Cave", 11092001);
        Contrat c1 = new Contrat(5);

        m1.marier(h1, f1);
        m1.passer(c1);
        m1.afficher();
    }
}
