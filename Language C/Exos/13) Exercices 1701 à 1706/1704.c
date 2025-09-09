#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {
    int valeur;
    struct maillon *suivant;
} maillon;

maillon *creer_maillon(int valeur) {
    maillon *nouveau = (maillon *)malloc(sizeof(maillon));
    if (nouveau == NULL) {
        printf("Erreur d'allocation.\n");
        exit(1);
    }
    nouveau->valeur = valeur;
    nouveau->suivant = nouveau;
    return nouveau;
}

void afficher_liste_recursif(maillon *courant, maillon *tete) {
    if (courant == NULL) {
        return;
    }
    printf("%d ", courant->valeur);
    if (courant->suivant != tete) {
        afficher_liste_recursif(courant->suivant, tete);
    }
}

maillon *ajouter_maillon(maillon *tete, int valeur) {
    maillon *nouveau = creer_maillon(valeur);
    if (tete == NULL) {
        return nouveau;
    }

    maillon *courant = tete;
    while (courant->suivant != tete) {
        courant = courant->suivant;
    }
    courant->suivant = nouveau;
    nouveau->suivant = tete;
    return tete;
}

int compter_maillons(maillon *tete) {
    if (tete == NULL) {
        return 0;
    }

    int compteur = 1;
    maillon *courant = tete->suivant;
    while (courant != tete) {
        compteur++;
        courant = courant->suivant;
    }
    return compteur;
}

void liberer_liste(maillon *tete) {
    if (tete == NULL) {
        return;
    }

    maillon *courant = tete->suivant;
    maillon *temp;
    while (courant != tete) {
        temp = courant;
        courant = courant->suivant;
        free(temp);
    }
    free(tete);
}

int main() {
    maillon *tete = NULL;
    int choix, valeur;

    do {
        printf("1. Ajouter un maillon\n");
        printf("2. Afficher la liste\n");
        printf("3. Compter les maillons\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            printf("Saisir un entier : ");
            scanf("%d", &valeur);
            tete = ajouter_maillon(tete, valeur);
            break;
        case 2:
            if (tete != NULL) {
                afficher_liste_recursif(tete, tete);
                printf("\n");
            } else {
                printf("Liste vide.\n");
            }
            break;
        case 3:
            printf("Nombre de maillons : %d\n", compter_maillons(tete));
            break;
        case 4:
            liberer_liste(tete);
            printf("Programme termine.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}
