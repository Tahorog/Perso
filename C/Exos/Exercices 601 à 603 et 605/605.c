#include <stdio.h>
int main() {
    int valeur;

    printf("Valeur: ");
    scanf("%d", &valeur);

    if (valeur >= 0) {
        printf("La valeur est positive.");
    }
    else {
        printf("La valeur est negative.");
    }
    return 0;
}
