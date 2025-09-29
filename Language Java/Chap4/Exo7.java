import java.util.Scanner;

public class Exo7 {
    static class Voiture {
        public int anneeFabrication;
        public Proprietaire proprietaire;
        public Modele modele;
        public void saisir() {
            Scanner sc = new Scanner(System.in);
            System.out.print("Entrez l'année de fabrication : ");
            anneeFabrication = sc.nextInt();
        }
        public void afficher() {
            System.out.println("Année de fabrication : " + anneeFabrication);
        }
    }
    static class Proprietaire {
        public String nom;
        public int nbVoitures;
        public Voiture[] voitures;
        private int compteur = 0;
        public Proprietaire(String nom, int nbVoitures) {
            this.nom = nom;
            this.nbVoitures = nbVoitures;
            voitures = new Voiture[nbVoitures];
        }
        public void ajouter(Voiture v) {
            if (compteur < nbVoitures) {
                voitures[compteur] = v;
                v.proprietaire = this;
                compteur++;
            } else {
                System.out.println("Le propriétaire a déjà le nombre maximum.");
            }
        }
        public void afficher() {
            System.out.println("Propriétaire : " + nom + ", Nombre de voitures : " + nbVoitures);
        }
    }
    static class Modele {
        public String marque;
        public int nbVoitures;
        public Voiture[] voitures;
        private int compteur = 0;
        public Modele(String marque, int nbVoitures) {
            this.marque = marque;
            this.nbVoitures = nbVoitures;
            voitures = new Voiture[nbVoitures];
        }
        public void ajouter(Voiture v) {
            if (compteur < nbVoitures) {
                voitures[compteur] = v;
                v.modele = this;
                compteur++;
            } else {
                System.out.println("Ce modèle a déjà le nombre maximum.");
            }
        }
        public void afficher() {
            System.out.println("Modèle : " + marque + ", Nombre de voitures : " + nbVoitures);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Entrez le nom du propriétaire : ");
        String nom = sc.nextLine();
        int nbVoituresProprio;
        do {
            System.out.print("Entrez le nombre de voitures : ");
            nbVoituresProprio = sc.nextInt();
        } while (nbVoituresProprio < 0);

        Proprietaire proprietaire = new Proprietaire(nom, nbVoituresProprio);
        proprietaire.afficher();

        sc.nextLine();
        System.out.print("Entrez la marque : ");
        String marque = sc.nextLine();
        int nbVoituresModele;
        do {
            System.out.print("Entrez le nombre de voitures : ");
            nbVoituresModele = sc.nextInt();
        } while (nbVoituresModele < 0);

        Modele modele = new Modele(marque, nbVoituresModele);
        modele.afficher();

        for (int i = 0; i < nbVoituresProprio; i++) {
            Voiture v = new Voiture();
            v.saisir();
            v.afficher();
            proprietaire.ajouter(v);
        }

        for (int i = 0; i < nbVoituresModele; i++) {
            Voiture v = new Voiture();
            v.saisir();
            modele.ajouter(v);
            proprietaire.ajouter(v);
        }

    }
}
