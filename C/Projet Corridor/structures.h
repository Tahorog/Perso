//
// Created by Picard on 19/11/2024.
//

#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "macros.h"

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    Coord coord;
    int avatar; 
    int barrieres; 
    int mode;
    int score;
    long int timer;
    char pseudo[TAILLE_PSEUDO+1];
} Player;

typedef struct {
    char pseudo[TAILLE_PSEUDO+1];
    int score;
} Score;


#endif //STRUCTURES_H
