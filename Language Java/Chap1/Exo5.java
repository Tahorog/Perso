//exercice 5
public class Exo5 {
    public static void main(String[] args) {
        // Création d'un train
        Train t = new Train();

        // Affichage de l'état initial
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);

        // Stopper le train
        t.stopper();
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);

        // Ralentir le train (ne change rien ici car vitesse = 0)
        t.ralentir();
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);

        // Accélérer le train
        t.accelerer();
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);
    }
}
