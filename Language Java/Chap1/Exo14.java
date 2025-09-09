public class Exo14 {
    public static void main(String[] args) {
        String str1 = "15";
        String str2 = "poire";
        int entier = 99;
        String str3 = "18";
        String str4 = "pomme";
        String str5 = "ananas";

        try {
            int conv1 = Integer.parseInt(str1);
            System.out.println(str1 + "-->" + conv1);
        } catch (NumberFormatException erreur){
            System.out.println("Erreur1");
        }
        try {
            int conv2 = Integer.parseInt(str2);
            System.out.println(str2 + "-->" + conv2);
        } catch (NumberFormatException erreur){
            System.out.println("Erreur2");
        }
        try {
            String conv3 = String.valueOf(entier);
            System.out.println(entier + "-->" + conv3);
        }catch(NumberFormatException erreur){
            System.out.println("Erreur3");
        }
        try {
            Float conv4 = Float.parseFloat(str3);
            System.out.println(str3 + "-->" + conv4);
        } catch (NumberFormatException erreur){
            System.out.println("Erreur4");
        }
        try {
            Float conv5 = Float.parseFloat(str4);
            System.out.println(str4 + "-->" + conv5);
        }catch (NumberFormatException erreur){
            System.out.println("Erreur5");
        }
        try {
            Double conv6 = Double.parseDouble(str5);
            System.out.println(str5 + "-->" + conv6);
        }catch (NumberFormatException erreur){
            System.out.println("Erreur6");
        }
    }
}
