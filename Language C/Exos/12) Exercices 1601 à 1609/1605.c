#include <stdio.h>


int calcul(int nombre, int produit, int puissance, int i, int n)
{
    if (i == puissance) return produit;

    if (i <= puissance)
    {
        produit = nombre * n;
    }
    calcul(nombre, produit, puissance, i + 1, n);
}


int main(void)
{
    int résultat;
    int puissance;
    int nombre;
    int produit;
    printf("Choisir un nombre ");
    scanf("%d", &nombre);
    printf("Insert the puissance : ");
    scanf("%d", &puissance);
    int n = nombre;

    résultat = calcul(nombre, produit, puissance, 0, n);

    printf("The result is %d", résultat);
    return 0;

}
