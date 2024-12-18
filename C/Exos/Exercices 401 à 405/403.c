#include <stdio.h>
int main() {
    char caractere;

    printf("Choisis un caractere: ");
    scanf("%c", &caractere);

    printf("%c", caractere);
    caractere = caractere-32;
    printf("%c", caractere);
    return 0;
}
