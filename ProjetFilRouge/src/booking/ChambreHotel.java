package booking;

import java.util.Date;

public class ChambreHotel extends Hebergement {
    private int numChambre;
    private int nbLits;
    private boolean balcon;

    public ChambreHotel(int id, String nom, String adresse, int capacite, float tarifParNuit,
                        String description, int numChambre, int nbLits, boolean balcon) {
        super(id, nom, adresse, "Chambre d'hôtel", capacite, tarifParNuit, description);
        this.numChambre = numChambre;
        this.nbLits = nbLits;
        this.balcon = balcon;
    }

    @Override
    public boolean verifierDisponibilite(Date date) {
        return true; // logique simplifiée
    }

    @Override
    public float retournerPrixTotal(int nbNuit) {
        return nbNuit * getTarifParNuit();
    }

    @Override
    public String retournerInfos() {
        return "Chambre " + numChambre + " (" + nbLits + " lits, balcon: " + balcon + ")";
    }
}
