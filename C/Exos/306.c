#include <stdio.h>
int main() {
    float mesure1, mesure2, transfert;

    printf("Choisis une lettre : ");
    scanf(" %f", &mesure1);
    printf("Choisis une lettre : ");
    scanf(" %f", &mesure2);

    printf("Lettre1 : %f\n", mesure1);
    printf("Lettre2 : %f\n", mesure2);
    printf("=====================================\n");
    mesure1 = mesure1 * 3;
    transfert = mesure1;
    mesure1 = mesure2;
    mesure2 = transfert;

    printf("lettre 1 : %f\n", mesure1);
    printf("lettre 2 : %f\n", mesure2);
    return 0;
}
