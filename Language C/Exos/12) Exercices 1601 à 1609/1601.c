#include <stdio.h>

#define taille 20

void saisirTab(float tab[], int i)
{
    if (i >= taille) return;

    scanf("%f", &tab[i]);
    saisirTab(tab, i+1);
}

void afficherTab(float tab[], int i)
{
    if (i >= taille) return;
    printf("%f", &tab[i]);
    afficherTab(tab, i+1);
}


int main(void)
{
    float t[taille];
    saisirTab(t, 0);
    afficherTab(t, 0);
    return 0;
    
}
