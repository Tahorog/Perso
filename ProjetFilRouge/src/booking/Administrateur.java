package booking;

import java.util.List;

public class Administrateur extends Personne {
    private int idAdmin;

    public Administrateur(int id, String nom, String prenom, String email, String mdp, int idAdmin) {
        super(id, nom, prenom, email, mdp);
        this.idAdmin = idAdmin;
    }

    public void ajouterHebergement(CollectionHebergements c, Hebergement h) {
        c.ajouter(h);
    }

    public void supprimerHebergement(CollectionHebergements c, int id) {
        c.getHebergements().removeIf(h -> h.getIdentifiant() == id);
    }

    public void introduireReduction(float pourcentage) {
        System.out.println("Réduction de " + pourcentage + "% appliquée !");
    }

    public void maintenirDossiersClients() {
        System.out.println("Mise à jour des dossiers clients...");
    }

    @Override
    public String getTypePersonne() { return "Administrateur"; }
}
