//les relations entre classe se traduisent par des méthodes
public class Exo1 {
    static class Chien {
        public String race;

        public Chien(String race) {
            this.race = race;
        }
        public void manger(Os o) {
            System.out.println("Le chien a mangé " + o.nombre+ " os.");
        }
    }
    static class Maitre {
        public String nom;
        public Maitre(String nom) {
            this.nom = nom;
        }

        public void nourrir(Chien c, Os o) {
            System.out.println("Le chien de race " + c.race + " a eu " + o.nombre + " os.");
            c.manger(o);
        }
    }
    static class Os {
        public int nombre;
        public Os(int nombre) {
            this.nombre = nombre;
        }
    }

    public static void main(String[] args) {
        Maitre lemaitre = new Maitre("Pascal");
        Chien race = new Chien("Golden Retriever");
        Os nombre = new Os(12);

        lemaitre.nourrir(race, nombre);
    }
}
