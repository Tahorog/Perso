package Exo4.Individu;

public class Personne {
    protected String nom;

    public Personne(String nom){
        this.nom = nom;
    }

    public void afficher(){
        System.out.println("Nom: " + this.nom);
    }
}
