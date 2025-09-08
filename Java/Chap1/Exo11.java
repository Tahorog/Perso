public class Exo11 {
    public static void main(String[] args){
        int tabInt[] = {10,20,30,40,50};
        int tabRef[] = tabInt;

        for (int i = 0; i < tabInt.length; i++) {
            System.out.println("TabInt : " + tabInt[i]);
            System.out.println("TabRef : " + tabRef[i]);
        }

        int tabCopy[] = new int[tabInt.length];
        for (int i = 0; i < tabInt.length; i++) {
            tabCopy[i] = tabInt[i];
        }
        tabInt = new int[]{20, 30, 40, 50, 60};

        for (int i = 0; i < tabInt.length; i++) {
            System.out.println("TabInt : " + tabInt[i]);
            System.out.println("TabCopy : " + tabRef[i]);
        }
    }

}
