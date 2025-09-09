#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct article {
    int numero;
    char nom[50];
    char categorie[50];
    char fournisseur[50];
    float prix_achat;
    float prix_vente;
    int quantite_stock;
    struct article *suivant;
} article;

article *creer_article() {
    article *nouveau = (article *)malloc(sizeof(article));
    if (nouveau == NULL) {
        printf("Erreur d'allocation.\n");
        exit(1);
    }

    printf("Saisir le numero : ");
    scanf("%d", &nouveau->numero);
    printf("Saisir le nom : ");
    scanf("%s", nouveau->nom);
    printf("Saisir la categorie : ");
    scanf("%s", nouveau->categorie);
    printf("Saisir le fournisseur : ");
    scanf("%s", nouveau->fournisseur);
    printf("Saisir le prix d'achat : ");
    scanf("%f", &nouveau->prix_achat);
    printf("Saisir le prix de vente : ");
    scanf("%f", &nouveau->prix_vente);
    printf("Saisir la quantite en stock : ");
    scanf("%d", &nouveau->quantite_stock);

    nouveau->suivant = NULL;
    return nouveau;
}

void ranger_article(article *tableau[], article *nouveau) {
    int index;

    if (strcmp(nouveau->categorie, "cat1") == 0) {
        index = 0;
    } else if (strcmp(nouveau->categorie, "cat2") == 0) {
        index = 1;
    } else if (strcmp(nouveau->categorie, "cat3") == 0) {
        index = 2;
    } else if (strcmp(nouveau->categorie, "cat4") == 0) {
        index = 3;
    } else {
        index = 4;
    }

    nouveau->suivant = tableau[index];
    tableau[index] = nouveau;
}

void afficher_tableau(article *tableau[]) {
    for (int i = 0; i < 5; i++) {
        printf("Liste de la categorie %d :\n", i + 1);
        article *courant = tableau[i];
        while (courant != NULL) {
            printf("Numero: %d, Nom: %s, Fournisseur: %s, Prix Achat: %.2f, Prix Vente: %.2f, Quantite: %d\n",
                   courant->numero, courant->nom, courant->fournisseur, courant->prix_achat, courant->prix_vente, courant->quantite_stock);
            courant = courant->suivant;
        }
        printf("-----------------------------\n");
    }
}

void liberer_tableau(article *tableau[]) {
    for (int i = 0; i < 5; i++) {
        article *courant = tableau[i];
        while (courant != NULL) {
            article *a_supprimer = courant;
            courant = courant->suivant;
            free(a_supprimer);
        }
        tableau[i] = NULL;
    }
}

int main() {
    article *tableau[5] = {NULL, NULL, NULL, NULL, NULL};
    int choix;

    do {
        printf("1. Ajouter un article\n");
        printf("2. Afficher les articles\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1: {
            article *nouveau = creer_article();
            ranger_article(tableau, nouveau);
            break;
        }
        case 2:
            afficher_tableau(tableau);
            break;
        case 3:
            liberer_tableau(tableau);
            printf("Programme termine.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 3);

    return 0;
}
