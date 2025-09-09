#include <stdio.h>
int main() {
    int annee, note1, note2, note3, oppose;
    float moyenne;

    printf("Bonjour\n");
    printf("===========\n");
    printf("Entrer annee :");
    scanf("%d", &annee);

    printf("%d\n", annee);

    if (annee == 2021)
        printf("L'annee en cours est 2021\n");

    oppose = -annee;
    printf("%d\n", oppose);

    printf("Choisir note1 : ");
    scanf("%d", &note1);
    printf("Choisir note2 : ");
    scanf("%d", &note2);
    printf("Choisir note3 : ");
    scanf("%d", &note3);

    moyenne = note1 + note2 + note3;
    moyenne = moyenne / 3;
    printf("%f\n", moyenne);
}
