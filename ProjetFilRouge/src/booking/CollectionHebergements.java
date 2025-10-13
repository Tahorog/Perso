package booking;

import java.util.*;

public class CollectionHebergements {
    private ArrayList<Hebergement> hebergements = new ArrayList<>();

    public void ajouter(Hebergement h) { hebergements.add(h); }

    public void trierParPrix() { Collections.sort(hebergements); }

    public void afficherTous() {
        for (Hebergement h : hebergements)
            System.out.println(h.retournerInfos());
    }

    public ArrayList<Hebergement> getHebergements() { return hebergements; }
}
