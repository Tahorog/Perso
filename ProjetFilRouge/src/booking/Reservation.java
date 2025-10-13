package booking;

import java.util.Date;

public class Reservation {
    private int numeroReservation;
    private Client client;
    private Hebergement hebergement;
    private Date dateArrive;
    private Date dateDepart;
    private float prixTotal;

    public Reservation(int num, Client client, Hebergement h, Date arrive, Date depart) {
        this.numeroReservation = num;
        this.client = client;
        this.hebergement = h;
        this.dateArrive = arrive;
        this.dateDepart = depart;
        this.prixTotal = h.retournerPrixTotal(3); // simplifié
    }

    public float getPrixTotal() { return prixTotal; }
    public Hebergement getHebergement() { return hebergement; }
}
