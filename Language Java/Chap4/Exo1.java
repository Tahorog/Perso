public class Exo1 {
    static class Note {
        public static final int MIDDLE = 40;
        public static final int SHARP = 80;
    }

    static class Instrument {
        public void play(int note) {
            System.out.println("Instrument joue la note " + note);
        }
    }

    static class Wind extends Instrument {
        public void play(int note) {
            System.out.println("Instrument à vent joue la note " + note);
        }
    }

    static class Stringed extends Instrument {
        public void play(int note) {
            System.out.println("Instrument à cordes joue la note " + note);
        }
    }

    static class Brass extends Instrument {
        public void play(int note) {
            System.out.println("Instrument à cuivre joue la note " + note);
        }
    }

    static public class Test {
        public void tune(Wind w) {
            w.play(Note.MIDDLE);
        }

        public void tune(Stringed s) {
            s.play(Note.SHARP);
        }

        public void tune(Brass b) {
            b.play(Note.MIDDLE);
        }

        public static void main(String[] args) {
            Test test = new Test();

            Wind flute = new Wind();
            Stringed guitare = new Stringed();
            Brass trompette = new Brass();

            test.tune(flute);
            test.tune(guitare);
            test.tune(trompette);
        }
    }
}
