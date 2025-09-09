#include <stdio.h>
int main() {
    int valeur;

    printf("Valeur: ");
    scanf("%d", &valeur);

    if (valeur %2 == 0) {
        printf("La valeur est paire.");
    }
    else {
        printf("La valeur est impaire.");
    }
    return 0;
}
