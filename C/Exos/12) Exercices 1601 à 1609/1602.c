#include <stdio.h>
#include <stdlib.h>

int sommeTableau(int tabdyn[], int i, int somme, int taille)
{

    if (i == taille)
    {
        return somme;
    }
    if (i <= taille)
    {
        somme += tabdyn[i];
        sommeTableau(tabdyn, i+1, somme, taille);
    }
}


int main(void)
{
    int *tabdyn;
    int taille, somme = 0;
    int resultat = 0;
    printf("Choisir la taille");
    scanf("%d", &taille);
    tabdyn = (int*)malloc(taille * sizeof(int));

    for (int i = 0; i < taille; i++)
    {
        printf("Choisir un entier");
        scanf("%d", &tabdyn[i]);
    }

    resultat = sommeTableau(tabdyn, 0, somme, taille);

    printf("La somme de tabdyn est %d", resultat);

    free(tabdyn);
    return 0;

}
