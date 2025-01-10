#include <stdio.h>
int main() {
    int valeur;

    printf("Valeur: ");
    scanf("%d", &valeur);

    if (valeur % 5 == 0) {
        printf("C'est un multiple de 5\n");
    }
    if (valeur >= -3) {
        printf("C'est superieur a -3\n");
    }
    return 0;
}
