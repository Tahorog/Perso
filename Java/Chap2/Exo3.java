public class Exo3 {
    static class Article {
        public int numero;
        public String nom;
        public Entrepot entrepot;

        public Article(int numero, String nom) {
            this.numero = numero;
            this.nom = nom;
        }
    }

    static class Entrepot{
        public String nom;
        public String adresse;
        public Article[] stock;
        private int index;

        public Entrepot(String nom, String adresse){
            this.nom = nom;
            this.adresse = adresse;
            this.stock = new Article[3];
        }

        public void garder(Article article){

            if (index < stock.length){
                stock[index++] = article;
                article.entrepot = this;
                System.out.println("L'article " + article.nom + " est stocké dans l'entrepôt " + this.adresse);
            } else {
                System.out.println("L'entrepot est plein !");
            }

        }

        public void afficher() {
            System.out.println("Articles stockés dans l'entrepôt " + " (" + this.adresse + "):");
            if (index == 0) {
                System.out.println(" - Aucun article en stock.");
            } else {
                for (int i = 0; i < index; i++) {
                    System.out.println(" - " + stock[i].nom);
                }
            }
        }
    }
    public static void main(String[] args) {
        Article a1 = new Article(1, "table");
        Article a2 = new Article(1, "boite");
        Article a3 = new Article(1, "chaise");
        Entrepot entrepot1 = new Entrepot("Entrepot", "Paris");

        entrepot1.afficher();

        entrepot1.garder(a1);
        entrepot1.garder(a2);
        entrepot1.garder(a3);

    }
}
