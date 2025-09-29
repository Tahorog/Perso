import java.util.HashMap;
import java.util.Scanner;

public class Exo9 {
    static class Etudiant {
        public Integer numero;
        public String nom;

        public Etudiant(Integer numero, String nom) {
            this.numero = numero;
            this.nom = nom;
        }
    }
    static class MapEtudiants {
        public HashMap<Integer, String> etudiants;

        public MapEtudiants() {
            etudiants = new HashMap<>();
        }

        public void ajouter(Etudiant e) {
            etudiants.put(e.numero, e.nom);
        }
        public void afficherTous() {
            for (Integer num : etudiants.keySet()) {
                System.out.println("Numéro: " + num + ", Nom: " + etudiants.get(num));
            }
        }
    }
    public static void main(String[] args) {
        MapEtudiants mapEtu = new MapEtudiants();
        Etudiant e1 = new Etudiant(1, "PtiteFleur");
        Etudiant e2 = new Etudiant(2, "Le cousin de PtiteFleur");
        Etudiant e3 = new Etudiant(3, "Le Phacochère de compagnie de PtiteFleur");
        mapEtu.ajouter(e1);
        mapEtu.ajouter(e2);
        mapEtu.ajouter(e3);
        Scanner sc = new Scanner(System.in);
        System.out.print("Entrez le numéro d'un étudiant : ");
        int numRecherche = sc.nextInt();
        if (mapEtu.etudiants.containsKey(numRecherche)) {
            System.out.println("Nom de l'étudiant : " + mapEtu.etudiants.get(numRecherche));
        } else {
            System.out.println("Erreur.");
        }
        System.out.println("----- Liste complète des étudiants -----");
        mapEtu.afficherTous();
        sc.close();
    }
}
