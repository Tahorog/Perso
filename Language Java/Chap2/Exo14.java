public class Exo14 {
    static class Maman{
        private int age;
        public Maman(int age) {
            this.age = age;
        }
        public Maman() {
            this.age = 0;
        }

        public void afficher() {
            System.out.println("Maman : " + age);
        }

        public int getAge() {
            return age;
        }

        public void setAge(int age) {
            this.age = age;
        }
    }
    static class Fifille extends Maman{
        private int furoncles;
        public Fifille(int age, int furoncles) {
            super(age);
            this.furoncles = furoncles;
        }
        public Fifille() {
            super();
            this.furoncles = 0;
        }
        public void afficher() {
            System.out.println("Fifille : " + furoncles);
        }
        public void modif(int nouvelAge){
            setAge(nouvelAge);
        }
    }

    static public void main (String args[]){
        Fifille f = new Fifille(10,3);
        f.afficher();
        System.out.println("____________________");
        System.out.println(f.getAge());
        System.out.println("____________________");
        f.modif(20);
        System.out.println(f.getAge());

    }
}
