#include <stdio.h>
int main() {
    int entier;

    printf("Choisis un entier\n");
    scanf("%d", &entier);
    printf("%d\n", entier);
    entier = entier*entier;
    printf("%d", entier);
    return 0;
}
