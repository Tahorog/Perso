package booking;

import java.util.ArrayList;
import java.util.List;

public class AncienClient extends Client {
    private List<Reservation> historiqueReservations;

    public AncienClient(int id, String nom, String prenom, String email, String mdp, String dateInscription) {
        super(id, nom, prenom, email, mdp, dateInscription);
        this.historiqueReservations = new ArrayList<>();
    }

    public boolean seConnecter(String email, String motDePasse) {
        return getEmail().equals(email) && getMotDePasse().equals(motDePasse);
    }

    public boolean tarifSpecial() { return true; }

    public List<Reservation> historique() { return historiqueReservations; }

    @Override
    public String getTypePersonne() { return "Ancien Client"; }
}
