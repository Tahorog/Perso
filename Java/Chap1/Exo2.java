public class Exo2 {
    public String concatener(String a, String b) {
        return a + b;
    }

    public void afficherMessage(Train t, String texte) {
        System.out.println("Résultat de la concaténation : " + concatener(String.valueOf(t.vitesse), texte));
    }
    public static void main(String[] args) {Train t2 = new Train();
        Exo2 e = new Exo2();
        e.afficherMessage(t2, " est la vitesse actuelle du train !");
    }

}
