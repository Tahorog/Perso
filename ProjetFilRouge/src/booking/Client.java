package booking;

import java.util.*;

public class Client extends Personne {
    protected String dateInscription;
    protected List<Reservation> reservations;

    public Client(int id, String nom, String prenom, String email, String mdp, String dateInscription) {
        super(id, nom, prenom, email, mdp);
        this.dateInscription = dateInscription;
        this.reservations = new ArrayList<>();
    }

    public void reserverHebergement(Hebergement h, Date debut, Date fin) {
        Reservation r = new Reservation(reservations.size()+1, this, h, debut, fin);
        reservations.add(r);
        System.out.println(nom + " a réservé " + h.getNom());
    }

    public void annulerReservation(Hebergement h) {
        reservations.removeIf(r -> r.getHebergement().equals(h));
    }

    public float calculerFacture() {
        float total = 0;
        for (Reservation r : reservations)
            total += r.getPrixTotal();
        return total;
    }

    public void visualiserFacture() {
        System.out.println("Facture totale : " + calculerFacture() + "€");
    }

    public void naviguerDisponibilites() {
        System.out.println("Consultation des hébergements disponibles...");
    }

    @Override
    public String getTypePersonne() { return "Client"; }
}
