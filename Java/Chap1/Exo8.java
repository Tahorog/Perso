public class Exo8 {
    static int[] tabInt = new int[10];
    static String[] tabString = new String[10];
    public static void main(String[] args){
        for  (int i = 0; i < tabInt.length; i++){
            System.out.println("Case " + (i+1) + " : " + tabInt[i]);
        }
        for (int i = 0; i < tabString.length; i++){
            System.out.println("Case " + (i+1) + " : " + tabString[i]);
        }
    }
}
