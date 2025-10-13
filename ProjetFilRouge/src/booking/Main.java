package booking;

import booking.gui.*;

public class Main {
    public static void main(String[] args) {
        CollectionHebergements collection = new CollectionHebergements();
        collection.ajouter(new ChambreHotel(1, "Ibis Paris", "Paris", 2, 120, "Centre-ville", 101, 1, true));
        collection.ajouter(new Appartement(2, "Appartement Lyon", "Lyon", 4, 90, "Quartier calme", 60, 2, true));
        collection.ajouter(new Villa(3, "Villa Nice", "Nice", 6, 200, "Vue mer", 150, 3, true, true));

        Client client = new NouveauClient(1, "Dupont", "Jean", "jean@exemple.com", "1234", "2025-10-13");

        javax.swing.SwingUtilities.invokeLater(() -> {
            new booking.gui.FenetreConnexion();
            new booking.gui.FenetreReservation(collection, client);
        });
    }
}
