public class Exo7 {
    static class Point {
        private int x;
        private int y;
        private int rgb;

        public Point() {
            this.x = 0;
            this.y = 0;
            this.rgb = 0;
        }

        public Point(int x, int y) {
            this();
            this.x = x;
            this.y = y;
        }

        public Point(int x, int y, int rgb) {
            this.x = x;
            this.y = y;
            this.rgb = rgb;
        }

        public Point(Point p){
            this(p.getX(),  p.getY(), p.getRgb());
        }

        public void afficher() {
            System.out.println(this.x + " ; " + this.y);
        }

        public void translate(int dx, int dy) {
            this.x += dx;
            this.y += dy;
        }

        public void translate(int dx) {
            x += dx*dx;
        }

        public void switchColor(int rgb){
            this.rgb=rgb*rgb;
        }

        public Point getPoint() {
            return this;
        }

        public int getX() { return x; }
        public int getY() { return y; }
        public int getRgb() { return rgb; }
    }

    public static void main(String[] args) {
        Point p1 = new Point();
        System.out.print("p1 : ");
        p1.afficher();


        Point p2 = new Point(5, 10);
        System.out.print("p2 : ");
        p2.afficher();

        Point p3 = new Point(3, 6, 255);
        System.out.print("p3 : ");
        p3.afficher();

        Point p4 = new Point(p3);
        System.out.print("p4 : ");
        p4.afficher();

        p2.switchColor(128);
        System.out.print("p2 après switchColor(128) : ");
        p2.afficher();

        p1.translate(2, 3);
        System.out.print("p1 après translate(2,3) : ");
        p1.afficher();

        p3.translate(4);
        System.out.print("p3 après translate(4) : ");
        p3.afficher();

        Point p5 = p3.getPoint();
        System.out.print("p5 : ");
        p5.afficher();
    }
}
