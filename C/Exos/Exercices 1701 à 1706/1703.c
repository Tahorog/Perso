#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {
    char valeur;
    struct maillon *precedent;
    struct maillon *suivant;
} maillon;

maillon *creer_maillon(char valeur) {
    maillon *nouveau = (maillon *)malloc(sizeof(maillon));
    if (nouveau == NULL) {
        printf("Erreur d'allocation.\n");
        exit(1);
    }
    nouveau->valeur = valeur;
    nouveau->precedent = NULL;
    nouveau->suivant = NULL;
    return nouveau;
}

void afficher_liste(maillon *liste) {
    while (liste != NULL) {
        printf("%c ", liste->valeur);
        liste = liste->suivant;
    }
    printf("\n");
}

maillon *ajouter_maillon(maillon *liste, char valeur) {
    maillon *nouveau = creer_maillon(valeur);
    if (liste == NULL) {
        return nouveau;
    }

    maillon *courant = liste;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    courant->suivant = nouveau;
    nouveau->precedent = courant;
    return liste;
}

maillon *supprimer_maillons(maillon *liste, char valeur) {
    maillon *courant = liste;

    while (courant != NULL) {
        if (courant->valeur == valeur) {
            maillon *a_supprimer = courant;

            if (courant->precedent != NULL) {
                courant->precedent->suivant = courant->suivant;
            } else {
                liste = courant->suivant;
            }

            if (courant->suivant != NULL) {
                courant->suivant->precedent = courant->precedent;
            }

            courant = courant->suivant;
            free(a_supprimer);
        } else {
            courant = courant->suivant;
        }
    }

    return liste;
}

void liberer_liste(maillon *liste) {
    maillon *courant;
    while (liste != NULL) {
        courant = liste;
        liste = liste->suivant;
        free(courant);
    }
}

int main() {
    maillon *liste = NULL;
    char valeur;
    int choix;

    do {
        printf("1. Ajouter un maillon\n");
        printf("2. Afficher la liste\n");
        printf("3. Supprimer des maillons\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            printf("Saisir un caractere : ");
            scanf(" %c", &valeur);
            liste = ajouter_maillon(liste, valeur);
            break;
        case 2:
            afficher_liste(liste);
            break;
        case 3:
            printf("Saisir le caractere a supprimer : ");
            scanf(" %c", &valeur);
            liste = supprimer_maillons(liste, valeur);
            break;
        case 4:
            liberer_liste(liste);
            printf("Programme termine.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
