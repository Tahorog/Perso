public class Exo5 {
    static class Point {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
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

        public int getX() { return x; }
        public int getY() { return y; }
    }

    static class Segment {
        private Point a;
        private Point b;

        public Segment(Point a, Point b) {
            this.a = a;
            this.b = b;
        }

        public void afficher() {
            System.out.println("(" + a.getX() + " ; " + a.getY() +
                    ") / (" + b.getX() + " ; " + b.getY() + ")");
        }

        public double longueur() {
            int dx = b.getX() - a.getX();
            int dy = b.getY() - a.getY();
            return Math.sqrt(dx * dx + dy * dy);
        }

        public void translate(Point c, Point d) {
            int dx = c.getX() + d.getX();
            int dy = c.getY() + d.getY();
            a.translate(dx, dy);
            b.translate(dx, dy);
        }
    }

    public static void main(String[] args) {
        Point a = new Point(1, 7);
        Point b = new Point(2, 13);
        Point c = new Point(19, 40);
        Point d = new Point(20, 12);

        Segment s1 = new Segment(a, b);

        System.out.println("Segment initial :");
        s1.afficher();

        a.translate(3);
        System.out.println("\nAprès translation de a avec 1 paramètre :");
        s1.afficher();

        b.translate(2, -4);
        System.out.println("\nAprès translation de b avec 2 paramètres :");
        s1.afficher();

        s1.translate(c, d);
        System.out.println("\nAprès translation du segment avec c et d :");
        s1.afficher();
        
    }
}
