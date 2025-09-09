//
// Created by Picard on 19/11/2024.
//

#include "initialisation.h"
#include "modifications.h"

#include <stdio.h>

void initPlayer(int tab[TAILLE][TAILLE],Player liste[4],int x,int y,int player_n) {
    modif(tab,x,y,player_n);
    liste[player_n-1].coord.x=x;
    liste[player_n-1].coord.y=y;
}

void initBoard(int tab[TAILLE][TAILLE],Player liste[4],int nbplayers) { // initialise le plateau (4 joueurs-> a modif /nbjoueur)
    //DANS TOUT LES CAS
    initPlayer(tab,liste,5,9,1); // J1
    initPlayer(tab,liste,5,1,3); // J3
    if (nbplayers==4) { // DANS LE CAS OU IL Y A 4 JOUEURS
        initPlayer(tab,liste,1,5,2); // J2
        initPlayer(tab,liste,9,5,4); // J4
        for (int i = 0; i<4; i++) {
            liste[i].barrieres=5;
        }
    } else { // DANS LE CAS OU IL Y A DEUX JOUEURS SEULEMENT :
        for (int i=0; i<2; i++) {
            liste[i*2].barrieres=10;//met les barrières des joueurs 0 et 2 à 10
            liste[i*2+1].coord.x=5;
            liste[i*2+1].coord.y=5;//met les coordonées des joueurs 1 et 3 à 5 5
        }
    }
    for (int i=0; i<4; i++) {
        printf("%s : %d,%d\n",liste[i].pseudo,liste[i].coord.x,liste[i].coord.y);
    }

}


void init(int tab[TAILLE][TAILLE],Player liste[4],int nbplayers){
    initBoard(tab,liste,nbplayers);
    for(int i=0;i<4;i++) {
        // initialise le mode de chaqun des joueurs
        if (!(nbplayers==2 && i%2==1)){//skip le tour des joueurs i = 1 et i = 3 si le nb de joueurs == 4
            liste[i].mode=1;
        }
    }
}