package booking;

import java.util.Date;
import java.util.List;

public interface Reservable {
    boolean verifierDisponibilite(Date date);
    float retournerPrixTotal(int nbNuit);
    Reservation reserver(Date debut, Date fin, Client client, int nbPers);
    String retournerInfos();
    boolean annulerReservation(Reservation r);
    boolean estReservee(Date date);

    int getIdentifiant();
    String getType();
    int getCapacite();
    List<String> getOptions();
}
