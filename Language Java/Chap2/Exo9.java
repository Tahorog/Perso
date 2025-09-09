public class Exo9 {
    static class Configuration{
        public int num;
        public Configuration(int num){
            this.num = num;
        }

        public void assembler(Ecran ecran, Clavier clavier, Disque disque){
            this.num = num;
        }
    }
    static class Ecran{
        public int rafraichissement;
        public Ecran(int rafraichissement){
            this.rafraichissement = rafraichissement;
        }
    }
    static class Clavier{
        public int touches;
        public Clavier(int touches){
            this.touches = touches;
        }
    }

    static class Disque {
        public int stockage;
        public Disque(int stockage){
            this.stockage = stockage;
        }
    }
    public static void main(String[] args) {
        Disque d1 = new Disque(1000);
        Ecran e1 = new Ecran(144);
        Clavier c1 = new Clavier(5);
        Configuration config = new Configuration(5);

        config.assembler(e1,c1,d1);


    }
}
