package Exo4.Conduite;

import Exo4.Transport.Train;
import Exo4.Individu.Passager;
import Exo4.Individu.Conducteur;

public class Main {
    public static void main(String[] args) {
        Train t1 = new Train(101, 120);

        Passager[] pass = new Passager[3];
        pass[0] = new Passager("Paul", 1, t1);
        pass[1] = new Passager("Dim", 2, t1);
        pass[2] = new Passager("Raph", 3, t1);

        Conducteur[] cond = new Conducteur[2];
        cond[0] = new Conducteur("Patrice", 200.0, t1);
        cond[1] = new Conducteur("Pascalette", 1630.0, t1);

        t1.afficher();

        System.out.println("\nPassagers:");
        for (Passager p : pass) {
            p.afficher();
        }

        System.out.println("\nConducteurs:");
        for (Conducteur c : cond) {
            c.afficher();
        }
    }
}
