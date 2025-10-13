package booking;

import java.util.*;

public class Hebergement implements Reservable, Comparable<Hebergement> {
    private int identifiant;
    private String nom;
    private String adresse;
    private String type;
    private int capacite;
    private float tarifParNuit;
    private String description;
    private List<String> options;
    private float noteEtoiles;

    public Hebergement(int id, String nom, String adresse, String type, int capacite, float tarifParNuit, String description) {
        this.identifiant = id;
        this.nom = nom;
        this.adresse = adresse;
        this.type = type;
        this.capacite = capacite;
        this.tarifParNuit = tarifParNuit;
        this.description = description;
        this.options = new ArrayList<>();
    }

    public boolean verifierDisponibilite(Date date) { return true; }
    public float retournerPrixTotal(int nbNuit) { return nbNuit * tarifParNuit; }
    public Reservation reserver(Date debut, Date fin, Client client, int nbPers) {
        return new Reservation(new Random().nextInt(1000), client, this, debut, fin);
    }

    public String retournerInfos() {
        return nom + " - " + type + " (" + capacite + " pers)";
    }

    public boolean annulerReservation(Reservation r) { return true; }
    public boolean estReservee(Date date) { return false; }

    public int getIdentifiant() { return identifiant; }
    public String getNom() { return nom; }
    public String getType() { return type; }
    public int getCapacite() { return capacite; }
    public List<String> getOptions() { return options; }
    public float getTarifParNuit() { return tarifParNuit; }

    @Override
    public int compareTo(Hebergement h) {
        return Float.compare(this.tarifParNuit, h.tarifParNuit);
    }
}
