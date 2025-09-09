#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {
    double valeur;
    struct maillon *suivant;
} maillon;

maillon *creer_maillon() {
    maillon *nouveau = (maillon *)malloc(sizeof(maillon));
    if (nouveau == NULL) {
        printf("Erreur d'allocation.\n");
        exit(1);
    }
    printf("Saisir un reel : ");
    scanf("%lf", &nouveau->valeur);
    nouveau->suivant = NULL;
    return nouveau;
}

void afficher_maillon(maillon *m) {
    if (m != NULL) {
        printf("Reel : %.2f\n", m->valeur);
    }
}

void afficher_liste(maillon *liste) {
    maillon *courant = liste;
    while (courant != NULL) {
        printf("%.2f\n", courant->valeur);
        courant = courant->suivant;
    }
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
    maillon *liste = NULL, *nouveau, *dernier = NULL;
    for (int i = 0; i < 10; i++) {
        nouveau = creer_maillon();
        if (liste == NULL) {
            liste = nouveau;
        } else {
            dernier->suivant = nouveau;
        }
        dernier = nouveau;
    }

    printf("Tous les reels de la liste :\n");
    afficher_liste(liste);

    liberer_liste(liste);
    printf("Liste liberee.\n");

    return 0;
}
