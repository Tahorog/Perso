//
// Created by Picard on 19/11/2024.
//
#include "macros.h"
#include "structures.h"
#ifndef DIALOGUE_H
#define DIALOGUE_H

void saisiePseudo(int n,char pseudo[TAILLE_PSEUDO],int nbjoueurs);
void choixAvatar(int n, int nbjoueurs, Player liste[4]);
int fct_nbjoueur (void);

#endif //DIALOGUE_H
