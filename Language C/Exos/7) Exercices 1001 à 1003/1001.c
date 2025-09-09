#include <stdio.h>

int main() {
    int tab[13];

    for (int i = 0; i < 13; i++) {
        printf("Entrer un reel :");
        scanf("%d", &tab[i]);
    }
    for (int j = 0; j < 13; j++) {
        printf("%d\n ", tab[j]);
    }
    return 0;
}
