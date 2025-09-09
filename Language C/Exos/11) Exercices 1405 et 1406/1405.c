//problème d'encodage sur le fichier précedemment utilisé
//le texte ne s'affichait pas correctement

#include <stdio.h>
#include <string.h>

typedef struct {
    int identifiant;
    char titre[31];
    char realisateur[101];
    int annee;
    char genre[101];
} t_film;

void fichier(t_film film[], int TAILLE) {
    FILE* dossier = fopen("ADRESSE DU FICHIER", "w");
    if (!dossier) {
        perror("Erreur.");
        return;
    }
    for (int i = 0; i < TAILLE; i++) {
        fprintf(dossier, "%d\n%s\n%s\n%d\n%s\n", film[i].identifiant, film[i].titre, film[i].realisateur, film[i].annee, film[i].genre);
    }
    fclose(dossier);
}

void lecture(t_film film[], int TAILLE) {
    FILE* dossier = fopen("ADRESSE DU FICHIER", "r");
    if (!dossier) {
        perror("Erreur.");
        return;
    }
    int i = 0;
    while (i < TAILLE && !feof(dossier)) {
        t_film film_temp;

        if (fscanf(dossier, "%d", &film_temp.identifiant) != 1) break;

        fgets(film_temp.titre, sizeof(film_temp.titre), dossier);
        film_temp.titre[strcspn(film_temp.titre, "\n")] = '\0';

        fgets(film_temp.realisateur, sizeof(film_temp.realisateur), dossier);
        film_temp.realisateur[strcspn(film_temp.realisateur, "\n")] = '\0';

        if (fscanf(dossier, "%d", &film_temp.annee) != 1) break;

        fgets(film_temp.genre, sizeof(film_temp.genre), dossier);
        film_temp.genre[strcspn(film_temp.genre, "\n")] = '\0';

        film[i++] = film_temp;
    }
    fclose(dossier);
}

void afficher(t_film film[], int TAILLE) {
    for (int i = 0; i < TAILLE; i++) {
        printf("Identifiant : %d\n", film[i].identifiant);
        printf("Titre : %s\n", film[i].titre);
        printf("Realisateur : %s\n", film[i].realisateur);
        printf("Annee : %d\n", film[i].annee);
        printf("Genre : %s\n", film[i].genre);
    }
}

int main() {
    const int TAILLE = 10;

    t_film film[TAILLE];

    for (int i = 0; i < TAILLE; i++) {
        film[i].identifiant = -1;
    }

    lecture(film, TAILLE);

    afficher(film, TAILLE);

    t_film film1 = {11, "Il y a du Chocolat dans la friteuse", "Michel PetitPain", 2024, "Comedie"};
    t_film film2 = {12, "Un meurtre dans la Boulangerie", "Patricia Baguette", 2023, "Drama"};

    film[TAILLE - 2] = film1;
    film[TAILLE - 1] = film2;

    fichier(film, TAILLE);
    return 0;
}
