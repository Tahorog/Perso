#include <stdio.h>


int longueurChaine(char chaine[], int longueur)
{

    if (chaine[longueur] == '\0')
    {
        return longueur;
    }
    if (chaine[longueur] != '\0')
    {
        longueurChaine(chaine, longueur + 1);
    }

}


int main(void)
{
    int résultat;
    int taille;
    char chaine[200];
    printf("Insert chaine: ");
    scanf("%s", chaine);
    résultat = longueurChaine(chaine, taille);

    printf("La longeur de la chaine vaut %d", résultat);
    return 0;

}
