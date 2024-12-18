#include <stdio.h>
int main() {
    int choix, limite;

    printf("Choix :");
    scanf("%d", &choix);

    if (choix%3 == 0) {
        limite = choix - 2*choix;
        while (choix >= limite) {
            printf("%d\n", choix);
            choix = choix-3;
        }
    }
    if ((choix-1)%3 == 0) {
        choix = choix - 1;
        limite = choix - 2*choix;
        while (choix >= limite) {
            printf("%d\n", choix);
            choix = choix-3;
        }
    }
    if ((choix-2)%3 == 0) {
        choix = choix - 2;
        limite = choix - 2*choix;
        while (choix >= limite) {
            printf("%d\n", choix);
            choix = choix-3;
        }
    }
    return 0;
}
