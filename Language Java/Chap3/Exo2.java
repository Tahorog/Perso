public class Exo2 {
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

        public int getX() {
            return x;
        }
        public int getY() { 
            return y;
        }
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

        System.out.print("a = "); a.afficher();
        System.out.print("b = "); b.afficher();
        System.out.print("c = "); c.afficher();
        System.out.print("d = "); d.afficher();

        System.out.println("Longueur initiale = " + s1.longueur());

        s1.translate(c, d);

        System.out.println("Après translation : ");
        s1.afficher();
        System.out.println("Nouvelle longueur = " + s1.longueur());

        System.out.println("----------------------------------------");

        if (a == b) {
            System.out.println("a et b sont le même objet.");
        } else {
            System.out.println("a et b sont des objets différents.");
        }

        if (a.getClass() == b.getClass()) {
            System.out.println("a et b sont de la même classe.");
        } else {
            System.out.println("a et b sont de classes différentes.");
        }
    }
}
