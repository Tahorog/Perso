package booking;

import java.util.Date;

public class Villa extends Hebergement {
    private float superficie;
    private int nbChambres;
    private boolean piscine;
    private boolean jardin;

    public Villa(int id, String nom, String adresse, int capacite, float tarifParNuit,
                 String description, float superficie, int nbChambres, boolean piscine, boolean jardin) {
        super(id, nom, adresse, "Villa", capacite, tarifParNuit, description);
        this.superficie = superficie;
        this.nbChambres = nbChambres;
        this.piscine = piscine;
        this.jardin = jardin;
    }

    @Override
    public boolean verifierDisponibilite(Date date) {
        return true;
    }

    @Override
    public float retournerPrixTotal(int nbNuit) {
        return nbNuit * getTarifParNuit();
    }

    @Override
    public String retournerInfos() {
        return "Villa " + nbChambres + " chambres (" + superficie + " m², piscine: " + piscine + ", jardin: " + jardin + ")";
    }
}
