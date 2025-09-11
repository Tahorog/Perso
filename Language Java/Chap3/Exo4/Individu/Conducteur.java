package Exo4.Individu;
import Exo4.Transport.Train;

public class Conducteur extends Personne{
    public Train train;
    private float salaire;
    public int numero;

    public Conducteur(String nom, Train train, float salaire) {
        super(nom);
        this.train = train;
        this.salaire = salaire;
    }

    public void afficher(){
        System.out.println("Nom: " + this.nom);
        System.out.println("Numero: " + this.numero);
        System.out.println("Train: " + this.train);
    }
}
