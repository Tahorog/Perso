#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_date {
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct voiture {
    char immatriculation[20];
    char marque[50];
    char modele[50];
    int vitesse_max;
    char carburant;
    t_date date_mise_service;
    struct voiture *suivant;
} voiture;

voiture *creer_maillon() {
    voiture *nouveau = (voiture *)malloc(sizeof(voiture));
    if (nouveau == NULL) {
        printf("Erreur d'allocation.\n");
        exit(1);
    }

    printf("Saisir l'immatriculation : ");
    scanf("%s", nouveau->immatriculation);

    printf("Saisir la marque : ");
    scanf("%s", nouveau->marque);

    printf("Saisir le modele : ");
    scanf("%s", nouveau->modele);

    printf("Saisir la vitesse maximale : ");
    scanf("%d", &nouveau->vitesse_max);

    printf("Saisir le type de carburant (un caractere) : ");
    scanf(" %c", &nouveau->carburant);

    printf("Saisir la date de mise en service (jour mois annee) : ");
    scanf("%d %d %d", &nouveau->date_mise_service.jour, &nouveau->date_mise_service.mois, &nouveau->date_mise_service.annee);

    nouveau->suivant = NULL;
    return nouveau;
}

void afficher_voitures(voiture *liste) {
    voiture *courant = liste;
    while (courant != NULL) {
        printf("Immatriculation: %s\n", courant->immatriculation);
        printf("Marque: %s\n", courant->marque);
        printf("Modele: %s\n", courant->modele);
        printf("Vitesse Max: %d\n", courant->vitesse_max);
        printf("Carburant: %c\n", courant->carburant);
        printf("Date de mise en service: %02d/%02d/%d\n", courant->date_mise_service.jour, courant->date_mise_service.mois, courant->date_mise_service.annee);
        printf("-------------------------\n");
        courant = courant->suivant;
    }
}

void afficher_par_marque(voiture *liste, char *marque) {
    voiture *courant = liste;
    while (courant != NULL) {
        if (strcmp(courant->marque, marque) == 0) {
            printf("Immatriculation: %s\n", courant->immatriculation);
        }
        courant = courant->suivant;
    }
}

voiture *supprimer_par_immatriculation(voiture *liste, char *immatriculation) {
    voiture *courant = liste;
    voiture *precedent = NULL;

    while (courant != NULL) {
        if (strcmp(courant->immatriculation, immatriculation) == 0) {
            if (precedent == NULL) {
                liste = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            free(courant);
            printf("Suppression effectuee.\n");
            return liste;
        }
        precedent = courant;
        courant = courant->suivant;
    }

    printf("Suppression impossible car voiture inconnue.\n");
    return liste;
}

void liberer_liste(voiture *liste) {
    voiture *courant;
    while (liste != NULL) {
        courant = liste;
        liste = liste->suivant;
        free(courant);
    }
}

int main() {
    voiture *liste = NULL;
    voiture *nouveau;
    char marque[50];
    char immatriculation[20];
    int choix;

    do {
        printf("1. Ajouter une voiture\n");
        printf("2. Afficher toutes les voitures\n");
        printf("3. Afficher les immatriculations par marque\n");
        printf("4. Supprimer une voiture par immatriculation\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            nouveau = creer_maillon();
            nouveau->suivant = liste;
            liste = nouveau;
            break;
        case 2:
            afficher_voitures(liste);
            break;
        case 3:
            printf("Saisir la marque : ");
            scanf("%s", marque);
            afficher_par_marque(liste, marque);
            break;
        case 4:
            printf("Saisir l'immatriculation : ");
            scanf("%s", immatriculation);
            liste = supprimer_par_immatriculation(liste, immatriculation);
            break;
        case 5:
            liberer_liste(liste);
            printf("Programme termine.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 5);

    return 0;
}
