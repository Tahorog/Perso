package Exo4.Individu;
import Exo4.Transport.Train;

public class Passager extends Personne {
    private Train train;
    private int reservation;

    public Passager(String nom, int reservation, Train train) {
        super(nom);
        this.reservation = reservation;
        this.train = train;
    }

    public void afficher(){
        System.out.println("Nom: " + nom);
        System.out.println("Reservation: " + reservation);
        System.out.println("Train: " + train.numero);
    }
}
