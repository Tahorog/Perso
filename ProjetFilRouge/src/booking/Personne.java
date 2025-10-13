package booking;

public abstract class Personne {
    protected int identifiant;
    protected String nom;
    protected String prenom;
    protected String email;
    protected String motDePasse;

    public Personne(int id, String nom, String prenom, String email, String motDePasse) {
        this.identifiant = id;
        this.nom = nom;
        this.prenom = prenom;
        this.email = email;
        this.motDePasse = motDePasse;
    }

    public String getNom() { return nom; }
    public String getPrenom() { return prenom; }
    public String getEmail() { return email; }
    public String getMotDePasse() { return motDePasse; }

    public abstract String getTypePersonne();

    @Override
    public String toString() {
        return nom + " " + prenom + " (" + getTypePersonne() + ")";
    }
}
