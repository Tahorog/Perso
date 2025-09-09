public class Exo10 {
    public static void main(String[] args) {
        int[][] tab1 = {{10, 20, 30, 40, 50}, {60, 70, 80, 90, 100}};
        int[][] tab2 = new int[10][];

        for (int i = 0; i < tab2.length; i++) {
            tab2[i] = new int[10];
            for (int j = 0; j < tab2[i].length; j++) {
                tab2[i][j] = j + 1;
            }
        }

        for (int i = 0; i < tab2.length; i++) {
            for (int j = 0; j < tab2[i].length; j++) {
                System.out.print(tab2[i][j] + " ");
            }
            System.out.println();
        }
    }
}
