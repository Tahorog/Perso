#include <stdio.h>
int entierNegatif(int *max, int *min) {
    int entier;
    int somme;
    float moyenne;
    int i;
    *max = -2147483648;
    *min = 2147483647;
    i = 0;
    while(1) {
        printf("Choisir un entier: ");
        scanf("%d", &entier);
        if (entier < 0 ) {
            somme += entier;

            if (entier > *max) {
                *max = entier;
            }
            if (entier < *min) {
                *min = entier;
            }
        }
        else {
            break;
        }
        i++;

    }
    return moyenne = somme/i;
}

int main() {
    int max, min;
    float moyenne;

    moyenne = entierNegatif(&max, &min);

    printf("%f\n", moyenne);
    printf("%d\n", max);
    printf("%d\n", min);
    return 0;
}
