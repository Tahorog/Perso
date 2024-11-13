#include <stdio.h>
int main() {
    char lettre1, lettre2, transfert;

    printf("Choisis une lettre : ");
    scanf(" %c", &lettre1);
    printf("Choisis une lettre : ");
    scanf(" %c", &lettre2);

    printf("Lettre1 : %c\n", lettre1);
    printf("Lettre2 : %c\n", lettre2);
    printf("=====================================\n");
    transfert = lettre1;
    lettre1 = lettre2;
    lettre2 = transfert;

    printf("lettre 1 : %c\n", lettre1);
    printf("lettre 2 : %c\n", lettre2);
    return 0;
}
