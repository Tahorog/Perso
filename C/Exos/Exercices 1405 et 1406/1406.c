#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 10
#define MAX_AUTEURS 5
#define MAX_THEMES 5

typedef struct {
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct {
    int identifiant;
    char titre[30];
    char auteurs[MAX_AUTEURS][100];
    char theme[MAX_THEMES][100];
    float prixHT;
    t_date parution;
} t_livre;

void saisirLivre(t_livre *livre) {
    printf("Identifiant du livre : ");
    scanf("%d", &livre->identifiant);
    getchar(); // Consomme le '\n'

    printf("Titre du livre : ");
    fgets(livre->titre, sizeof(livre->titre), stdin);
    strtok(livre->titre, "\n");

    for (int i = 0; i < MAX_AUTEURS; i++) {
        printf("Nom de l'auteur :");
        fgets(livre->auteurs[i], sizeof(livre->auteurs[i]), stdin);
        strtok(livre->auteurs[i], "\n");
        if (strlen(livre->auteurs[i]) == 0) break;
    }

    for (int i = 0; i < MAX_THEMES; i++) {
        printf("Theme du livre :");
        fgets(livre->theme[i], sizeof(livre->theme[i]), stdin);
        strtok(livre->theme[i], "\n");
        if (strlen(livre->theme[i]) == 0) break;
    }

    printf("Prix HT du livre :");
    scanf("%f", &livre->prixHT);
    scanf("%f", &livre->prixHT);

    printf("Date de parution :");
    scanf("%d %d %d", &livre->parution.jour, &livre->parution.mois, &livre->parution.annee);
    getchar();
}

void remplirLivres(t_livre livres[], int *nbLivres) {
    while (*nbLivres < MAX_LIVRES) {
        printf("Saisie du livre :");
        saisirLivre(&livres[*nbLivres]);
        (*nbLivres)++;
        printf("Ajouter un livre : ");
        char choix;
        scanf(" %c", &choix);
        getchar();
        if (choix != 'o' && choix != 'O') break;
    }
}

void afficherLivre(const t_livre *livre) {
    printf("\nIdentifiant : %d\n", livre->identifiant);
    printf("Titre : %s\n", livre->titre);

    printf("Auteur : ");
    for (int i = 0; i < MAX_AUTEURS && strlen(livre->auteurs[i]) > 0; i++) {
        printf("%s", livre->auteurs[i]);
        if (i < MAX_AUTEURS - 1 && strlen(livre->auteurs[i + 1]) > 0) printf(", ");
    }
    printf("\n");

    printf("Theme : ");
    for (int i = 0; i < MAX_THEMES && strlen(livre->theme[i]) > 0; i++) {
        printf("%s", livre->theme[i]);
        if (i < MAX_THEMES - 1 && strlen(livre->theme[i + 1]) > 0) printf(", ");
    }
    printf("\n");

    printf("Prix HT : %.2f\n", livre->prixHT);
    printf("Date de parution : %02d/%02d/%04d\n", livre->parution.jour, livre->parution.mois, livre->parution.annee);
}

void afficherLivres(const t_livre livres[], int nbLivres) {
    for (int i = 0; i < nbLivres; i++) {
        printf("Livre \n", i + 1);
        afficherLivre(&livres[i]);
    }
}

void sauvegarderLivres(const t_livre livres[], int nbLivres, const char *fichierBinaire, const char *fichierTexte) {
    FILE *fb = fopen(fichierBinaire, "wb");
    FILE *ft = fopen(fichierTexte, "w");

    if (fb == NULL || ft == NULL) {
        perror("Erreur.");
        return;
    }

    fwrite(livres, sizeof(t_livre), nbLivres, fb);

    for (int i = 0; i < nbLivres; i++) {
        fprintf(ft, "Identifiant : %d\n", livres[i].identifiant);
        fprintf(ft, "Titre : %s\n", livres[i].titre);

        fprintf(ft, "Auteur : ");
        for (int j = 0; j < MAX_AUTEURS && strlen(livres[i].auteurs[j]) > 0; j++) {
            fprintf(ft, "%s", livres[i].auteurs[j]);
            if (j < MAX_AUTEURS - 1 && strlen(livres[i].auteurs[j + 1]) > 0) fprintf(ft, ", ");
        }
        fprintf(ft, "\n");

        fprintf(ft, "Theme : ");
        for (int j = 0; j < MAX_THEMES && strlen(livres[i].theme[j]) > 0; j++) {
            fprintf(ft, "%s", livres[i].theme[j]);
            if (j < MAX_THEMES - 1 && strlen(livres[i].theme[j + 1]) > 0) fprintf(ft, ", ");
        }
        fprintf(ft, "\n");

        fprintf(ft, "Prix HT : %.2f\n", livres[i].prixHT);
        fprintf(ft, "Date de parution : %02d/%02d/%04d\n\n", livres[i].parution.jour, livres[i].parution.mois, livres[i].parution.annee);
    }

    fclose(fb);
    fclose(ft);
}

void chargerLivres(t_livre livres[], int *nbLivres, const char *fichierBinaire) {
    FILE *fb = fopen(fichierBinaire, "rb");

    if (fb == NULL) {
        perror("Erreur.");
        return;
    }

    *nbLivres = fread(livres, sizeof(t_livre), MAX_LIVRES, fb);
    fclose(fb);
}

void menu() {
    printf("Menu\n");
    printf("1) Saisir un livre\n");
    printf("2) Remplir le tableau de livres\n");
    printf("3) Afficher un livre\n");
    printf("4) Afficher tous les livres\n");
    printf("5) Sauvegarder les livres\n");
    printf("6) Charger les livres\n");
    printf("7) Quitter\n");
    printf("Choix : ");
}

int main() {
    t_livre livres[MAX_LIVRES];
    int nbLivres = 0;
    char fichierBinaire[] = "livres.bin";
    char fichierTexte[] = "livres.txt";

    int choix;
    do {
        menu();
        scanf("%d", &choix);
        getchar(); // Consomme le '\n'

        switch (choix) {
            case 1:
                if (nbLivres < MAX_LIVRES) {
                    printf("Nouveau livre :\n");
                    saisirLivre(&livres[nbLivres]);
                    nbLivres++;
                } else {
                    printf("Erreur.");
                }
                break;

            case 2:
                remplirLivres(livres, &nbLivres);
                break;

            case 3: {
                int index;
                printf("Entrer le numéro :");
                scanf("%d", &index);
                if (index >= 1 && index <= nbLivres) {
                    afficherLivre(&livres[index - 1]);
                } else {
                    printf("Erreur.\n");
                }
                break;
            }

            case 4:
                afficherLivres(livres, nbLivres);
                break;

            case 5:
                sauvegarderLivres(livres, nbLivres, fichierBinaire, fichierTexte);
                break;

            case 6:
                chargerLivres(livres, &nbLivres, fichierBinaire);
                break;

            case 7:
                printf("Sortie.\n");
                break;

            default:
                printf("Erreur.\n");
                break;
        }
    } while (choix != 7);

    return 0;
}
