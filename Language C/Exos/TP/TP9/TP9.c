#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    float moyenne;
} Moyenne;

typedef struct Cellule {
    char nom[50];
    float moyenne;
    struct Cellule *suivant;
} Cellule;

//======================================================================================== PREMIERE PARTIE

void ajoutEnFinDeTableau(Moyenne **promo, int *nbMoyennes, const char *nom, float moyenne)
{
    *promo = realloc(*promo, (*nbMoyennes + 1) * sizeof(Moyenne)); //taille ++
    strcpy((*promo)[*nbMoyennes].nom, nom); // nom dans nouvelle case
    (*promo)[*nbMoyennes].moyenne = moyenne; //enregistre moyenne
    (*nbMoyennes)++; //met en place le compteur
}

void ajoutEnDebutDeTableau(Moyenne **promo, int *nbMoyennes, const char *nom, float moyenne)
{
    *promo = realloc(*promo, (*nbMoyennes + 1) * sizeof(Moyenne)); //taille ++
    for (int i = *nbMoyennes; i > 0; i--)
    { //décale les éléments déjà présents vers la droite
        (*promo)[i] = (*promo)[i - 1];
    }
    strcpy((*promo)[0].nom, nom); //nouveau nom en tête
    (*promo)[0].moyenne = moyenne; //moyenne en tête
    (*nbMoyennes)++;
}

void afficherTableau(Moyenne *promo, int size)
{ //tout est dans le nom de la fonction
    for (int i = 0; i < size; i++)
    {
        printf("%s : %.2f\n", promo[i].nom, promo[i].moyenne);
    }
}

//======================================================================================== SECONDE PARTIE

Cellule* funcAjoutEnTeteDeListe(Cellule *liste, const char *nom, float moyenne)
{
    Cellule *nouvelleCellule = malloc(sizeof(Cellule));
    strcpy(nouvelleCellule->nom, nom);
    nouvelleCellule->moyenne = moyenne;
    nouvelleCellule->suivant = liste;
    return nouvelleCellule;
}

void procAjoutEnTeteDeListe(Cellule **liste, const char *nom, float moyenne)
{
    Cellule *nouvelleCellule = malloc(sizeof(Cellule)); //nouvelle cellule
    strcpy(nouvelleCellule->nom, nom); //copie le nom
    nouvelleCellule->moyenne = moyenne; //met en place la moyenne
    nouvelleCellule->suivant = *liste; //lien entre cellule et ancienne tête
    *liste = nouvelleCellule; //nouvelle tête
}

//===============================================================

Cellule* funcAjoutEnFinDeListe(Cellule *liste, const char *nom, float moyenne)
{
    Cellule *nouvelleCellule = malloc(sizeof(Cellule));
    strcpy(nouvelleCellule->nom, nom);
    nouvelleCellule->moyenne = moyenne;
    nouvelleCellule->suivant = NULL;
    if (!liste)
    { //en cas de liste vide cellule = tête
        return nouvelleCellule;
    }
    Cellule *temp = liste;
    while (temp->suivant)
    { //regarde jusqu'à la fin
        temp = temp->suivant;
        temp->suivant = nouvelleCellule; //nouvelle cellule à la fin
        return liste;
    }
}

void procAjoutEnFinDeListe(Cellule **liste, const char *nom, float moyenne)
{
    Cellule *nouvelleCellule = malloc(sizeof(Cellule));
    strcpy(nouvelleCellule->nom, nom);
    nouvelleCellule->moyenne = moyenne;
    nouvelleCellule->suivant = NULL;
    if (!*liste)
    {
        *liste = nouvelleCellule;
    }
    else
    {
        Cellule *temp = *liste;
        while (temp->suivant) temp = temp->suivant;
        temp->suivant = nouvelleCellule;
    }
}

//=====================================================================

void afficherListeAvecWhile(Cellule *liste)
{ //tout est dans le nom de la fonction
    Cellule *temp = liste;
    while (temp)
    {
        printf("%s : %.2f\n", temp->nom, temp->moyenne);
        temp = temp->suivant;
    }
}

void afficherListeAvecFor(Cellule *liste)
{ //tout est dans le nom de la fonction
    for (Cellule *temp = liste; temp; temp = temp->suivant)
    {
        printf("%s : %.2f\n", temp->nom, temp->moyenne);
    }
}

void libererListe(Cellule **pointeurSurListe)
{
    Cellule *temp;
    while (*pointeurSurListe)
    {
        temp = *pointeurSurListe;
        *pointeurSurListe = (*pointeurSurListe)->suivant;
        free(temp); //libere les cellules une a une
    }
}

int nombreElementsIteratif(Cellule *liste)
{
    int compteur = 0;
    while (liste != NULL) //parcourt toutes les cellules de la liste et les compte
    {
        compteur++;
        liste = liste->suivant;
    }
    return compteur; //renvoie le nombre de cellule
}

int main()
{
    printf("\n\n********* Tableau dynamique *********\n\n");
    Moyenne *promo = NULL;
    int nbMoyennes = 0;
    ajoutEnDebutDeTableau(&promo, &nbMoyennes, "Patrice", 12.4);
    ajoutEnDebutDeTableau(&promo, &nbMoyennes, "Micheline", 10.4);
    ajoutEnFinDeTableau(&promo, &nbMoyennes, "Bernadette", 15.32);
    ajoutEnFinDeTableau(&promo, &nbMoyennes, "Gontrand", 16.0);
    afficherTableau(promo, nbMoyennes);
    free(promo);
    printf("\n\n********* Liste simplement chainee *********\n\n");
    Cellule *liste = NULL;
    liste = funcAjoutEnTeteDeListe(liste, "Patrice", 12.4);
    procAjoutEnTeteDeListe(&liste, "Micheline", 10.4);
    liste = funcAjoutEnFinDeListe(liste, "Bernadette", 15.32);
    procAjoutEnFinDeListe(&liste, "Gontrand", 16.0);
    printf("Il y a %d cellules dans la liste chainee.\n", nombreElementsIteratif(liste));
    afficherListeAvecWhile(liste);
    afficherListeAvecFor(liste);
    libererListe(&liste);
    return 0;
}
