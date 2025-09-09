#include <stdio.h>
#include <string.h>
#define MAX 100

void saisir_chaine(char *chaine) {
    printf("Entrez une chaine de caracteres : ");
    fgets(chaine, MAX, stdin);

    if (chaine[0] != '\0' && chaine[strlen(chaine) - 1] == '\n') {
        chaine[strlen(chaine) - 1] = '\0';
    }
}

void compter_caracteres(const char *chaine, int *nb_chiffres, int *nb_minuscules) {
    *nb_chiffres = 0;
    *nb_minuscules = 0;

    for (int i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] >= '0' && chaine[i] <= '9') {
            (*nb_chiffres)++;
        }
        else if (chaine[i] >= 'a' && chaine[i] <= 'z') {
            (*nb_minuscules)++;
        }
    }
}

void compter_mots(const char *chaine, int *nb_mots) {
    *nb_mots = 0;
    int i = 0;

    while (chaine[i] == ' ') {
        i++;
    }

    while (chaine[i] != '\0') {
        if (chaine[i] != ' ' && (i == 0 || chaine[i-1] == ' ')) {
            (*nb_mots)++;
        }
        i++;
    }
}

int main() {
    char chaine[MAX];
    int nb_chiffres, nb_minuscules, nb_mots;

    saisir_chaine(chaine);

    compter_caracteres(chaine, &nb_chiffres, &nb_minuscules);

    compter_mots(chaine, &nb_mots);

    printf("Chaine saisie : %s\n", chaine);
    printf("Nombre de chiffres : %d\n", nb_chiffres);
    printf("Nombre de lettres minuscules : %d\n", nb_minuscules);
    printf("Nombre de mots : %d\n", nb_mots);

    return 0;
}
