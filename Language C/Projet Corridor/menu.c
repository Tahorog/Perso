//
// Created by Picard on 19/11/2024.
//

#include "menu.h"

#include <stdio.h>

#include "dialogue.h"
#include "affichage_console.h"
#include "external_console.h"
#include "structures.h"

void customizeGame(int *nbplayers,Player liste[4]) {
    *nbplayers=fct_nbjoueur();

    for(int i=0;i<4;i++) {
        if (!(*nbplayers==2 && i%2==1)) {
            saisiePseudo(i+1,liste[i].pseudo,*nbplayers);
            choixAvatar(i+1,*nbplayers,liste);
        }
        else {
            strcpy(liste[i].pseudo,"NULL");
            liste[i].avatar=0;
        }

    }
    /* AFFICHER TOUS LES PSEUDOS
    for(int i=0;i<4;i++) {
        printf("Pseudo[%d]: %s\n",i+1,liste[i].pseudo);
    }
    */
}

int blind_menu(int choix) {
    if (!(choix > 0 && choix < 5)) {
        color(4,0);
        printf("Choisissez une valeur correcte !\n");
        color(7,0);
    }
    return (choix > 0 && choix < 5);
}


int menu() {
    int choix=1;

    do {
        clear(30); // Nettoie l'écran avant d'afficher le menu
        affichageCentreTotal("---Menu de Jeu---");
        affichageCentre("1) Jouer");
        affichageCentre("2) Charger");
        affichageCentre("3) Quitter");
        affichageCentre("4) Parametres");
        clear(12);

        blind_menu(choix);

        printf("Veuillez SVP entrer votre choix (1-4) : ");

        scanf( "%d", &choix);
    } while (!blind_menu(choix));
    
    return choix;
}
