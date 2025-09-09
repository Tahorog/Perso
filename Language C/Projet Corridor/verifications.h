//
// Created by Picard on 19/11/2024.
//

#include "macros.h"
#include "structures.h"

#ifndef VERIFICATIONS_H
#define VERIFICATIONS_H

int blindMvt(int tab[TAILLE][TAILLE], int player_n,Player liste[4], int x,int y);
int blindWall(int tab[TAILLE][TAILLE],int x,int y,int x1,int y1);
void countPoints(Player liste[4], int player_i);
int check_win( Player liste[4], int player_i);

#endif //VERIFICATIONS_H
