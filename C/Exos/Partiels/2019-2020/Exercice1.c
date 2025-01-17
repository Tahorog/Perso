#include <stdio.h>
#include <string.h>

typedef struct voyage{
    char VilleDepart[30] ;
    char VilleArrivee[30] ;
    int HeureDepart ;
    int MinuteDepart ;
    int HeureArrivee ;
    int MinuteArrivee ;
}t_voyage ;

void remplir(t_voyage *V)
{
    printf("VilleDepart :   \n");
    fgets(V->VilleDepart,30,stdin);
    printf("VilleArrivee : \n");
    fgets(V->VilleArrivee,30,stdin);

    do
    {
        printf("HeureDepart : \n");
        scanf("%d",&V->HeureDepart);
    }
    while (V->HeureDepart < 0 || V->HeureDepart > 23);

    do
    {
        printf("MinuteDepart : \n");
        scanf("%d",&V->MinuteDepart);
    }
    while (V->MinuteDepart < 0 || V->MinuteDepart > 59);

    do
    {
        printf("HeureArrivee : \n");
        scanf("%d",&V->HeureArrivee);
    }
    while (V->HeureArrivee < 0 || V->HeureArrivee > 23);

    do
    {
        printf("MinuteArrivee : \n");
        scanf("%d",&V->MinuteArrivee);
    }
    while (V->MinuteArrivee < 0 || V->MinuteArrivee > 59);

}

int compter(t_voyage tab[100], int nombreVoyage)
{
    int choixHeure, choixMinute;
    char choixVilleDepart[30], choixVilleArrivee[30];
    int nombreVoyage = 0;

    printf("VilleDepart :   \n");
    fgets(choixVilleDepart,30,stdin);
    printf("VilleArrivee : \n");
    fgets(choixVilleArrivee,30,stdin);

    do
    {
        printf("Choisir l'heure (h) de depart : \n");
        scanf("%d",&choixHeure);
    }
    while (choixHeure < 0 || choixHeure > 23);

    do
    {
        printf("Choisir les minutes (min) de depart : \n");
        scanf("%d",&choixMinute);
    }
    while (choixMinute < 0 || choixMinute > 59);

    for (int i = 0 ; i < 100 ; i++)
    {
        if (choixHeure < tab[i].HeureDepart)
        {
            if (strcmp(choixVilleDepart, tab[i].VilleDepart) == 0)
            {
                if (strcmp(choixVilleArrivee, tab[i].VilleArrivee) ==0)
                {
                    nombreVoyage++;
                }
            }
        }
        else if (choixHeure == tab[i].HeureDepart)
        {
            if (choixMinute <= tab[i].MinuteDepart)
            {
                if (strcmp(choixVilleDepart, tab[i].VilleDepart) == 0)
                {
                    if (strcmp(choixVilleArrivee, tab[i].VilleArrivee) ==0)
                    {
                        nombreVoyage++;
                    }
                }
            }
        }
    }
    return nombreVoyage;
}

int main()
{
    t_voyage tab[100] ;
    int nombreVoyage = 0;
    int comptage;

    comptage = compter(tab, nombreVoyage);

    printf("Nombre de voyage correspondant : %d", comptage);
    return 0 ;
}
