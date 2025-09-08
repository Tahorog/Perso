public class Exo2 {
    static class Article {
        public int numero;
        public String nom;
        public Entrepot entrepot;

        public Article(int numero, String nom) {
            this.numero = numero;
            this.nom = nom;
        }

        public void stocker(Entrepot e){
            this.entrepot = e;
            System.out.println("L'objet est stocké dans l'entrepot");
        }
    }

    static class Entrepot{
        public String nom;
        public String adresse;

        public Entrepot(String nom, String adresse){
            this.nom = nom;
            this.adresse = adresse;
        }
    }
    public static void main(String[] args) {
        Article a1 = new Article(1, "table");
        Entrepot entrepot1 = new Entrepot("Entrepot", "Paris");

        a1.stocker(entrepot1);

        System.out.println("Article : " + a1.nom + " est stocké dans " + a1.entrepot.nom);
        System.out.println("Adresse de l'entrepôt : " + a1.entrepot.adresse);
    }
}
