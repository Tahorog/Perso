#include <stdio.h>

int main() {
    int tab[7][4];
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            printf("Valeur :");
            scanf("%d", &tab[i][j]);
        }
    }
    for(i = 0; i < 7; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }


    return 0;
}
