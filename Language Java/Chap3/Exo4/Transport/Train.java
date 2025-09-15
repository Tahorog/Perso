package Exo4.Transport;

public class Train {
    public int numero;
    public int vitesse;

    public Train(int numero, int vitesse) {
        this.numero = numero;
        this.vitesse = vitesse;
    }

    public void augmenter(int v){
        this.vitesse += v;
    }

    public void afficher(){
        System.out.println("Vitesse: " + this.vitesse);
    }
}
