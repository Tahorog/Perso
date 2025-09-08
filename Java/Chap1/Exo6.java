import java.util.Scanner;
public class Exo6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Entrer votre nom : ");
        String texte = sc.nextLine();
        System.out.print("Bonjour : " + texte);

        System.out.print("Entrer un entier : ");
        int entier = sc.nextInt();
        System.out.print("Votre entier est : " + entier);

        sc.close();
    }
}
