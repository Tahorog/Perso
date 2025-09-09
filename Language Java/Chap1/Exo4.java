public class Exo4 {
    static public int attribut_s = 0;
    public int attribut_ns = 0;
    static public final String attribut_constante = "";

    public static void main(String[] args) {
        System.out.println("Entier static :" +  Exo4.attribut_s);
        //System.out.println("Entier non static :" +  Exo4.attribut_ns); pas possible car main est static

        attribut_s = 6;
        System.out.println("Attribut_s :" +  Exo4.attribut_s);

        System.out.println("Constante :" + attribut_constante);
        //attribut_constante = "test"; pas possible car final
    }
}
