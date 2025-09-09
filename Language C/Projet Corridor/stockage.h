//
// Created by Picard on 19/11/2024.
//

#include "macros.h"
#include "structures.h"

#ifndef STOCKAGE_H
#define STOCKAGE_H

void savePartie(int tab[TAILLE][TAILLE],int savePlayer_i,int nbplayers,Player liste[4]);
void loadPartie(int tab[TAILLE][TAILLE],int * beginner,int * nbplayers,Player liste[4]);
void saveScores(Player liste[4], Score save[MAX],int stop);
int loadScores(Player liste[4], Score save[MAX]);

#endif //STOCKAGE_H
