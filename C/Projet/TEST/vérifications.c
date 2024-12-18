#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct { //permet que chaque instance se référent à coord utilise les variables x et y
    int x;
    int y;
} coord;

bool mouvement_valide(coord position_initiale, coord position_finale) {
    int distance_x = abs(position_finale.x - position_initiale.x); //prendre valeur absolue --> positive pour vérif
    int distance_y = abs(position_finale.y - position_initiale.y);


    if ((distance_x == 1 && distance_y == 0) || (distance_x == 0 && distance_y == 1)) { //on regarde si la valeur absolue est strictement égale à 1 pour vérif
        return true;
    }
    return false;
}
