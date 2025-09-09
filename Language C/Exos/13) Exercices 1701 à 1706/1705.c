#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct etudiant {
    int numero;
    char nom[50];
    char prenom[50];
    char adresse[100];
    int promotion;
    int groupe;
} etudiant;

typedef struct maillon {
    etudiant data;
    struct maillon *suivant;
} maillon;

int compter_maillons(maillon *liste) {
    int compteur = 0;
    while (liste != NULL) {
        compteur++;
        liste = liste->suivant;
    }
    return compteur;
}

maillon *ajouter_maillon(maillon *liste, etudiant data) {
    maillon *nouveau = (maillon *)malloc(sizeof(maillon));
    if (nouveau == NULL) {
        printf("Erreur d'allocation.\n");
        exit(1);
    }
    nouveau->data = data;
    nouveau->suivant = NULL;

    if (liste == NULL || data.numero < liste->data.numero) {
        nouveau->suivant = liste;
        return nouveau;
    }

    maillon *courant = liste;
    while (courant->suivant != NULL && courant->suivant->data.numero < data.numero) {
        courant = courant->suivant;
    }
    nouveau->suivant = courant->suivant;
    courant->suivant = nouveau;

    return liste;
}

maillon *supprimer_maillon(maillon *liste, int numero) {
    maillon *courant = liste;
    maillon *precedent = NULL;

    while (courant != NULL) {
        if (courant->data.numero == numero) {
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

    printf("Etudiant non trouve.\n");
    return liste;
}

maillon *rechercher_maillon(maillon *liste, int numero) {
    while (liste != NULL) {
        if (liste->data.numero == numero) {
            return liste;
        }
        liste = liste->suivant;
    }
    return NULL;
}

void modifier_maillon(maillon *liste, int numero, char *nouvelle_adresse) {
    maillon *trouve = rechercher_maillon(liste, numero);
    if (trouve != NULL) {
        strcpy(trouve->data.adresse, nouvelle_adresse);
        printf("Modification effectuee.\n");
    } else {
        printf("Etudiant non trouve.\n");
    }
}

void afficher_liste(maillon *liste) {
    while (liste != NULL) {
        printf("Numero: %d\n", liste->data.numero);
        printf("Nom: %s\n", liste->data.nom);
        printf("Prenom: %s\n", liste->data.prenom);
        printf("Adresse: %s\n", liste->data.adresse);
        printf("Promotion: %d\n", liste->data.promotion);
        printf("Groupe: %d\n", liste->data.groupe);
        printf("-------------------------\n");
        liste = liste->suivant;
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
    maillon *liste = NULL;
    etudiant e;
    int choix;
    int numero;
    char nouvelle_adresse[100];

    do {
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher tous les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Modifier l'adresse d'un etudiant\n");
        printf("5. Supprimer un etudiant\n");
        printf("6. Compter les etudiants\n");
        printf("7. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            printf("Saisir le numero : ");
            scanf("%d", &e.numero);
            printf("Saisir le nom : ");
            scanf("%s", e.nom);
            printf("Saisir le prenom : ");
            scanf("%s", e.prenom);
            printf("Saisir l'adresse : ");
            scanf("%s", e.adresse);
            printf("Saisir la promotion : ");
            scanf("%d", &e.promotion);
            printf("Saisir le groupe : ");
            scanf("%d", &e.groupe);
            liste = ajouter_maillon(liste, e);
            break;
        case 2:
            afficher_liste(liste);
            break;
        case 3:
            printf("Saisir le numero : ");
            scanf("%d", &numero);
            maillon *resultat = rechercher_maillon(liste, numero);
            if (resultat != NULL) {
                printf("Etudiant trouve :\n");
                printf("Numero: %d\n", resultat->data.numero);
                printf("Nom: %s\n", resultat->data.nom);
                printf("Prenom: %s\n", resultat->data.prenom);
                printf("Adresse: %s\n", resultat->data.adresse);
                printf("Promotion: %d\n", resultat->data.promotion);
                printf("Groupe: %d\n", resultat->data.groupe);
            } else {
                printf("Etudiant non trouve.\n");
            }
            break;
        case 4:
            printf("Saisir le numero : ");
            scanf("%d", &numero);
            printf("Saisir la nouvelle adresse : ");
            scanf("%s", nouvelle_adresse);
            modifier_maillon(liste, numero, nouvelle_adresse);
            break;
        case 5:
            printf("Saisir le numero : ");
            scanf("%d", &numero);
            liste = supprimer_maillon(liste, numero);
            break;
        case 6:
            printf("Nombre d'etudiants : %d\n", compter_maillons(liste));
            break;
        case 7:
            liberer_liste(liste);
            printf("Programme termine.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 7);

    return 0;
}
