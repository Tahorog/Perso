//
// Created by Picard on 19/11/2024.
//

#include "dialogue.h"
#include "affichage_console.h"
#include <stdio.h>

int blindPseudo(char pseudo[TAILLE_PSEUDO]) {
    for (int i = 0; i<TAILLE_PSEUDO ; i++){
        if(pseudo[i]=='\0') {
            return 0;
        }
        if (!((47<pseudo[i] && pseudo[i]<58) || (64<pseudo[i]&&pseudo[i]<91) || (96<pseudo[i]&&pseudo[i]<123) || pseudo[i]==93 || pseudo[i]==124 || pseudo[i]==91 || pseudo[i]==45 || pseudo[i]==95 )) {
            return 1;
        }
    }
    return 0;
}


void saisiePseudo(int n, char pseudo[TAILLE_PSEUDO+1],int nbjoueurs) {
    do {
        printf("Player [%d]\nEntrez votre pseudo (de 1 a %d caracteres) : ", n-(nbjoueurs==2&&n==3), TAILLE_PSEUDO);
        scanf("%s", pseudo);

        if (strlen(pseudo) > TAILLE_PSEUDO) {
            clear(40);
            color(4, 0);
            printf("Il faut choisir un pseudo qui respecte les regles annoncees.\n");
            color(7, 0);
        }

        if (blindPseudo(pseudo)) {
            clear(40);
            color(4, 0);
            printf("Le pseudo contient des caracteres invalides.\n");
            color(7, 0);
        }

    } while (strlen(pseudo) > TAILLE_PSEUDO || blindPseudo(pseudo));
    clear(40);
}

void choixAvatar(int n, int nbjoueurs, Player liste[4]) {
    int i=n-1;
    do {
        for (int j=0; j<6; j++) {
            printf(" %d) ", j+1);
            printAvatar(j+1);
            printf(" |");
        }
        printf("\n");
        printf("Player [%d]\nChoisissez votre Avatar (1-6) : ", n-(nbjoueurs==2&&n==3));
        scanf("%d", &liste[i].avatar);

        if (liste[i].avatar<1 || liste[i].avatar>6) {
            clear(40);
            color(4, 0);
            printf("Choisir un nombre entre 1 et 6\n");
            color(7, 0);
        }

    } while (!(liste[i].avatar>0 && liste[i].avatar<7));
    clear(40);
}

int fct_nbjoueur () {
    int nbjoueur;
    clear(40);
    do {
        printf("Entrez le nombre de joueurs au total: ( 2 ou 4 )\n ==> ");
        scanf("%d", &nbjoueur);
        if (nbjoueur < 2 || nbjoueur > 4 || nbjoueur == 3) {
            clear(40);
            color(4,0);
            printf("Veuillez saisir un nombre de joueur valide.\n");
            color(7, 0);
        }
        else {
            clear(40);
            color(2,0);
            printf("Nombre de joueur valide, initialisation de la partie...\n");
            color(7, 0);
        }
    }while (nbjoueur != 4 && nbjoueur != 2);

    return nbjoueur;
}
