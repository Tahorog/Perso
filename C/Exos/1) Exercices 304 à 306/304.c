#include <stdio.h>
int main() {
    int ent1;
    float nbReel;
    char initiale;

    ent1 = 10;
    nbReel = 5.5;
    nbReel = nbReel * 3;
    ent1 = ent1 + nbReel;

    initiale = 'F';
    initiale = initiale + 2;
    printf("%d\n",initiale);

    ent1 = ent1 + initiale;
    nbReel = nbReel + initiale;
    printf("%d\n",nbReel);
    printf("%d\n",ent1);

    ent1 = 1000;
    initiale = ent1;
    printf("%d\n",initiale);

    return 0;
}
