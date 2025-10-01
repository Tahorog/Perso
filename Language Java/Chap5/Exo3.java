import java.io.*;
import java.util.*;

public class Exo3 {

    static class Personne implements Serializable {
        public String nom;
        public int age;

        public Personne(String nom, int age) {
            this.nom = nom;
            this.age = age;
        }

        public void serialiser(String nomFichier) throws IOException {
            try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(nomFichier))) {
                oos.writeObject(this);
            }
        }

        public static Personne deserialiser(String nomFichier) throws IOException, ClassNotFoundException {
            try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(nomFichier))) {
                return (Personne) ois.readObject();
            }
        }

        public void afficher() {
            System.out.println("Nom: " + nom + ", Âge: " + age);
        }
    }

    static class Etudiant extends Personne {
        private String matricule;

        public Etudiant(String nom, int age, String matricule) {
            super(nom, age);
            this.matricule = matricule;
        }

        public void afficher() {
            super.afficher();
            System.out.println("Matricule: " + matricule);
        }
    }

    static class MapEtudiants {
        private Map<String, Etudiant> etudiants = new HashMap<>();

        public void ajouterEtudiant(Etudiant e) {
            etudiants.put(e.nom, e);
        }

        public void afficherEtudiants() {
            for (Etudiant e : etudiants.values()) {
                e.afficher();
            }
        }
    }

    public static void main(String[] args) {
        Personne p1 = new Personne("Alice", 30);

        try {
            p1.serialiser("personne.ser");
            System.out.println("Objet Personne sérialisé !");
        } catch (IOException e) {
            System.err.println("Erreur : " + e.getMessage());
        }

        Personne p2 = null;
        try {
            p2 = Personne.deserialiser("personne.ser");
            System.out.println("Objet Personne désérialisé !");
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Erreur : " + e.getMessage());
        }

        if (p2 != null) {
            p2.afficher();
        }

        Etudiant etu = new Etudiant("Patrice", 22, "2265");
        etu.afficher();

        MapEtudiants map = new MapEtudiants();
        map.ajouterEtudiant(etu);
        map.afficherEtudiants();
    }
}
