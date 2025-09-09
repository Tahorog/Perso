public class main {
    public static void main(String[] args) {
        //exercice 3
        if (args.length == 0) {
            args = new String[]{"Paul", "19"};
        }
        String nom = args[0];
        int age = 0;
        try {
            age = Integer.parseInt(args[1]);
        } catch (NumberFormatException number) {
            System.out.println("Arguments invalide");
            return;
        }
        System.out.println("Nom : " + nom);
        System.out.println("Âge : " + age);
    }
}
