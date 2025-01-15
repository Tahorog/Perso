#include <stdio.h>


float récurrence(float u, int i, int taille)
{
    if (i == taille) return u;

    if (i <= taille)
    {
        u = 3*u +2.5;
    }
    récurrence(u, i + 1, taille);
}


int main(void)
{
    float résultat;
    int taille;
    float u = 7;
    printf("Insert the taille : ");
    scanf("%d", &taille);

    résultat = récurrence(u, 0, taille);

    printf("The result is %0.2f", résultat);
    return 0;

}
