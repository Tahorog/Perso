#include <stdio.h>
int main() {
    int choix;

    do {
        printf("Choix (positif) :");
        scanf("%d", &choix);

        if (choix< 0) {
            printf("Choix invalide.");
        }
    } while (choix < 0);
    
    for (int i = 1;i <= choix;i++) {
        printf("Bienvenu en TP %d\n", i);
    }
    return 0;
}
