#include <stdio.h>
#define MAX 100
int main() {
    char chaine1[MAX], chaine2[MAX];
    int count1, count2;

    printf("Chaine1 :");
    fgets(chaine1, MAX, stdin);
    printf("Chaine2 :");
    fgets(chaine2, MAX, stdin);

    for (int i = 0; chaine1[i] != '\0'; i++) {
        if (chaine1[i] != '\n') {
            count1++;
        }
    }

    for (int i = 0; chaine2[i] != '\0'; i++) {
        if (chaine2[i] != '\n') {
            count2++;
        }
    }

    printf("Taille chaine1 : %d\n", count1);
    printf("Taille chaine2 : %d\n", count2);
    return 0;
}
