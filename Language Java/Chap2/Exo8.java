public class Exo8 {
    static class Revue{
        public String titre;
        public PointDeVente adresse;

        public Revue(String titre) {
            this.titre = titre;
        }

        public void stocker(PointDeVente adresse) {
            this.adresse = adresse;
        }
    }

    static class Vente{
        public int nombre;
        public Vente(int nombre){
            this.nombre = nombre;
        }

        public void vendre(Revue revue, PointDeVente adresse, Semaine semaine){
            this.nombre++;
        }
    }

    static class PointDeVente {
        public String lieu;
        private int index;
        public Revue[] stock;

        public PointDeVente(String lieu, int capacite) {
            this.lieu = lieu;
            this.index = 0;
            this.stock = new Revue[capacite];
        }

        public void garder(Revue revue){

            if (index < stock.length){
                stock[index++] = revue;
                revue.adresse = this;
                System.out.println("L'article " + revue.titre + " est stocké dans l'entrepôt " + this.lieu);
            } else {
                System.out.println("L'entrepot est plein !");
            }

        }
    }

    static class Semaine{
        public int numero;
        public Semaine(int numero) {
            this.numero = numero;
        }
    }

    public static void main(String[] args) {
        Vente v1 = new Vente(1);
        Revue r1 = new Revue("Patate");
        Semaine s1 = new Semaine(1);
        PointDeVente p1 = new PointDeVente("Cave", 6);

        r1.stocker(p1);
        p1.garder(r1);

        v1.vendre(r1, p1, s1);

        System.out.println("\n--- Récapitulatif ---");
        System.out.println("Revue : " + r1.titre + " | Adresse : " + r1.adresse.lieu);
        System.out.println("Point de vente : " + p1.lieu);
        System.out.println("Semaine n° " + s1.numero);
        System.out.println("Nombre de ventes : " + v1.nombre);

    }
}
