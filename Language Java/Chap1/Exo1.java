//exercice 1
public class Train {
    public int vitesse = 0;
    public boolean enmarche = true;

    public Train() {
        this.vitesse = 150;
        this.enmarche = true;
    }

    public void stopper () {
        this.vitesse = 0;
        this.enmarche = false;
    }
    public void ralentir () {
        if (vitesse > 0) {
            vitesse--;
            if (vitesse == 0) {
                this.enmarche = false;
            }
        }
    }
    public void accelerer () {
        this.enmarche = true;
        while (vitesse < 350) {
            vitesse++;
        }
    }
    public static void main(String[] args) {
        Train t = new Train();
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);
        t.stopper();
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);
        t.ralentir();
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);
        t.accelerer();
        System.out.println("vitesse = " + t.vitesse + " / en marche = " + t.enmarche);
    }
}

