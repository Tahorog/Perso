package booking;

import java.util.Date;

public class Appartement extends Hebergement {
    private float superficie;
    private int nbChambres;
    private boolean balcon;

    public Appartement(int id, String nom, String adresse, int capacite, float tarifParNuit,
                       String description, float superficie, int nbChambres, boolean balcon) {
        super(id, nom, adresse, "Appartement", capacite, tarifParNuit, description);
        this.superficie = superficie;
        this.nbChambres = nbChambres;
        this.balcon = balcon;
    }

    @Override
    public boolean verifierDisponibilite(Date date) {
        return true; // simplifié
    }

    @Override
    public float retournerPrixTotal(int nbNuit) {
        return nbNuit * getTarifParNuit();
    }

    @Override
    public String retournerInfos() {
        return "Appartement " + nbChambres + " chambres (" + superficie + " m², balcon: " + balcon + ")";
    }
}
