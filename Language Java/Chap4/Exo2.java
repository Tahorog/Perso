public class Exo2 {
    static abstract class Personnels {
        protected int heuresTravaillees;

        public Personnels() {
            this.heuresTravaillees = 0;
        }

        public void setHeuresTravaillees(int heures) {
            this.heuresTravaillees = heures;
        }

        public abstract void afficher();
    }

    static class Enseignant extends Personnels {
        public void afficher() {
            System.out.println("Enseignant : donne des cours, "
                    + heuresTravaillees + " heures travaillées.");
        }
    }

    static class Technicien extends Personnels {
        public void afficher(){
            System.out.println("Technicien : assure la maintenance, "
                    + heuresTravaillees + " heures travaillées.");
        }
    }

    static class Administratif extends Personnels {
        public void afficher(){
            System.out.println("Administratif : gère la paperasse, "
                    + heuresTravaillees + " heures travaillées.");
        }
    }

    public static void main(String[] args) {
        Enseignant prof = new Enseignant();
        Technicien tech = new Technicien();
        Administratif admin = new Administratif();

        prof.setHeuresTravaillees(20);
        tech.setHeuresTravaillees(35);
        admin.setHeuresTravaillees(40);

        prof.afficher();
        tech.afficher();
        admin.afficher();
    }
}
