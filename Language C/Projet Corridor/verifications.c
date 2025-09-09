//
// Created by Picard on 19/11/2024.
//

#include "verifications.h"
#include "macros.h"
#include "tout.h"



int check_win( Player liste[4], int player_i){ //Fonctionne uniquement si le mouvement du joueur est blindé (par ex, joueur 2 ne peut aller en abscisse 0 et 20)
    return (liste[player_i].coord.x == 0 || liste[player_i].coord.x == 10 || liste[player_i].coord.y == 0 || liste[player_i].coord.y == 10);
}


void countPoints(Player liste[4], int player_i) {
    liste[player_i].score += 5;
}



int canMoveNormal(int tab[TAILLE][TAILLE], int x, int y, int xtransfert, int ytransfert) {
    // Déplacement à droite
    if (xtransfert == 1) {
        if (tab[y * 2][x * 2-1] == 0) {
            return 1; // pas de mur à droite
        }
    }
    // Déplacement à gauche
    else if (xtransfert == -1) {
        if (tab[y * 2][x * 2+1] == 0) {
            return 1; // pas de mur a gauche
        }
    }
    // Déplacement vers le bas
    else if (ytransfert == 1) {
        if (tab[y * 2-1][x * 2] == 0) {
            return 1; // pas de mur vers le bas
        }
    }
    // Déplacement vers le haut
    else if (ytransfert == -1) {
        if (tab[y * 2+1][x * 2] == 0) {
            return 1; // pas de mur vers le haut
        }
    }

    return 0; // Aucune case de destination libre
}

int canJump(int tab[TAILLE][TAILLE], Player liste[4], int player_i, int x, int y) {
    int xcurrent = liste[player_i].coord.x;
    int ycurrent = liste[player_i].coord.y;

    // Déplacements relatifs
    int dx = x - xcurrent;
    int dy = y - ycurrent;

    // Vérifie si le déplacement est strictement de 2 cases dans une direction (saut possible)
    if (abs(dx) == 2 && dy == 0) { // Saut horizontal
        int mid_x = xcurrent + dx / 2;
        int mid_y = ycurrent;
        for (int i = 0; i < 4; i++) {
            if (i != player_i && liste[i].coord.x == mid_x && liste[i].coord.y == mid_y) {
                // Vérifie que la case derrière le joueur est libre
                if (tab[y][x] == 0) {  // Vérifie la case de destination directement
                    return 1; // Saut valide
                }
            }
        }
    } else if (abs(dy) == 2 && dx == 0) { // Saut vertical
        int mid_x = xcurrent;
        int mid_y = ycurrent + dy / 2;
        for (int i = 0; i < 4; i++) {
            if (i != player_i && liste[i].coord.x == mid_x && liste[i].coord.y == mid_y) {
                // Vérifie que la case derrière le joueur est libre
                if (tab[y][x] == 0) {  // Vérifie la case de destination directement
                    return 1; // Saut valide
                }
            }
        }
    }

    return 0; // Aucun saut valide
}

// Vérifie dans quelle zone d'arrivee arrive le joueur
int isInArrivalZone(int player_i, int x, int y) {
    switch (player_i) {
        case 0:
            return y==0;
        case 1:
            return x==10;
        case 2:
            return y==10;
        case 3:
            return x==0;
    }
    return 0; // Mauvaise zone
}

int blindMvt(int tab[TAILLE][TAILLE], int player_n, Player liste[4], int x, int y) {
    int player_i = player_n - 1;

    // Vérifie si la case est libre
    if (tab[y * 2][x * 2] != 0) {
        return 0;
    }

    //    SI LE JOUEUR VA SUR UN BORD        Vérifie si il entre dans la mauvaise zone d'arrivee
    if (( x==0 || y==0 || x==10|| y==10 ) && !isInArrivalZone(player_i, x, y)) {
        return 0;
    }
    // Calcul des déplacements relatifs
    int xtransfert = x - liste[player_i].coord.x;
    int ytransfert = y - liste[player_i].coord.y;

    // Déplacement simple
    if (abs(xtransfert) + abs(ytransfert) == 1) {
        return canMoveNormal(tab, x, y, xtransfert, ytransfert);
    }

    // Saut
    if (abs(xtransfert) + abs(ytransfert) == 2) {
        return canJump(tab, liste, player_i, x, y);
    }

    return 0; // Déplacement non valide
}

int blindWall(int tab[TAILLE][TAILLE], int x, int y, int x1, int y1) {
    if (x < 0 || x >= TAILLE || y < 0 || y >= TAILLE ||
        x1 < 0 || x1 >= TAILLE || y1 < 0 || y1 >= TAILLE) {
        return 0; //hors limites
    }

    if (!((x == x1 && abs(y1 - y) == 2) || (y == y1 && abs(x1 - x) == 2))) {
        return 0; //taille barriere
    }

    if (x == x1) { // Barrière verticale
        if (tab[y][x] != 0 || tab[y + 1][x] != 0 || tab[y1][x] != 0) {
            return 0; // Occupée
        }
    } else if (y == y1) { // Barrière horizontale
        if (tab[y][x] != 0 || tab[y][x + 1] != 0 || tab[y][x1] != 0) {
            return 0; // Occupée
        }
    }

    if (x%2==1 && y%2==1 || x1%2==1 && y1%2 == 1) {
        return 0;
    }
    return 1; // Barrière valide
}
