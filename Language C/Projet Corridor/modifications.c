//
// Created by Picard on 19/11/2024.
//

#include "modifications.h"
#include "structures.h"

void modif(int tab[TAILLE][TAILLE],int x,int y,int value) {
    tab[y*2][x*2]=value;
}


void placeWall(int tab[TAILLE][TAILLE],int x1,int y1,int x2,int y2) { // ATTENTION IL N'Y A PAS DE VERIF !
    tab[y1][x1]=1;
    tab[y2][x2]=1;

    if (x1==x2) { // vertical
        if (y1<y2)
            tab[y1+1][x1]=2;
        else
            tab[y2+1][x1]=2;
    } else { // horizontal
        if (x1<x2)
            tab[y1][x1+1]=1;
        else
            tab[y1][x2+1]=1;


    }
}

void deplace(int tab[TAILLE][TAILLE],int x1,int y1,int x2,int y2) {
    modif(tab,x2,y2,tab[y1*2][x1*2]);
    modif(tab,x1,y1,0);
}

void play(int tab[TAILLE][TAILLE],int player_n, Player liste[4],int x,int y) {
    deplace(tab,liste[player_n-1].coord.x,liste[player_n-1].coord.y,x,y);
    liste[player_n-1].coord.x=x;
    liste[player_n-1].coord.y=y;
}
