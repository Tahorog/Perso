#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX 201
void sous_programme(int *nombre) {
    *nombre = rand() % RAND_MAX;
}
int main() {
    int nombre, secret, guess;
    srand(time(NULL));
    sous_programme(&nombre);

    while (1) {
        printf("Trouver le nombre :\n");
        scanf("%d", &guess);
        if (guess == nombre) {
            printf("Bravo");
            break;
        }
        else if (guess > nombre) {
            printf("C'est moins\n");
        }
        else if (guess < nombre) {
            printf("C'est plus\n");
        }
    }
    return 0;
}
