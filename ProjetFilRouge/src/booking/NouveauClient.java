package booking;

public class NouveauClient extends Client {
    public NouveauClient(int id, String nom, String prenom, String email, String mdp, String dateInscription) {
        super(id, nom, prenom, email, mdp, dateInscription);
    }

    public void sInscrire() {
        System.out.println(getNom() + " vient de s'inscrire.");
    }

    public boolean aucunTarif() { return false; }
}
