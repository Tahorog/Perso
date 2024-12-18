//
// Created by Picard on 19/11/2024.
//

#include "structures.h"


#ifndef AFFICHAGE_CONSOLE_H
#define AFFICHAGE_CONSOLE_H

#define COTE 11
#define TAILLE (COTE+COTE-1)
#include <windows.h>
#include <stdio.h>
#include <string.h>

void color(int t,int f);
void show(int tab[TAILLE][TAILLE],int mode,Player liste[4]);
void printPerso(int perso, Player liste[4]);
void clear(int n);
void show_victory(int player_i);
void printAvatar(int i);

#endif //AFFICHAGE_CONSOLE_H
