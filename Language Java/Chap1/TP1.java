import java.util.Scanner;

public class Etudiant {
    private String nom;
    private int age;
    private double[] notes;
    private int nombre;

    public Etudiant(String nom, int age, double[] notes, int nombre) {
        this.nom = nom;
        this.age = age;
        this.notes = notes;
        this.nombre = nombre;
    }

    public void affichage(){
        System.out.println("Nom :" + nom);
        System.out.println("Age :" + age);
        System.out.print("Notes :");
        for (int i = 0; i < notes.length; i++){
            System.out.print(" - " + notes[i]);
        }
        System.out.println();
    }

    public double calcul(){
        double somme_notes = 0;
        for (int i = 0; i < notes.length; i++){
            somme_notes += notes[i];
        }
        double moyenne = somme_notes/nombre;
        return moyenne;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Entrez le nom :");
        String nom = sc.nextLine();

        System.out.println("Entrez l'âge :");
        int age = sc.nextInt();

        while (age < 18 || age > 25){
            System.out.println("Age invalide, veuillez entrer un âge entre 18 et 25 :");
            age = sc.nextInt();
        }

        System.out.println("Entrez le nombre de notes :");
        int nombre = sc.nextInt();

        while (nombre < 2 || nombre > 5){
            System.out.println("Nombre invalide, veuillez choisir entre 1 et 5 :");
            nombre = sc.nextInt();
        }

        double[] notes = new double[nombre];
        for (int i = 0; i < nombre; i++){
            System.out.println("Choisir une note comprise entre 0.0 et 20.0");
            notes[i] = sc.nextDouble();
            while (notes[i] < 0.0 || notes[i] > 20.0) {
                System.out.println("Note invalide");
                notes[i] = sc.nextDouble();
            }
        }

        Etudiant et =  new Etudiant(nom, age, notes, nombre);
        System.out.println("---Information de l'Etudiant---");
        et.affichage();

        System.out.println();
        System.out.print("Moyenne :" + et.calcul());
    }
}
