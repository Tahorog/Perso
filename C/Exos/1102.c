#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
    char chaine1[MAX], chaine2[MAX];
    int comp;

    printf("Entrer chaine1 :");
    fgets(chaine1, MAX, stdin);
    printf("Entrer chaine2 :");
    fgets(chaine2, MAX, stdin);

    comp = strcmp(chaine1, chaine2);

    if (comp < 0) {
        printf("Chaine1 est avant dans l'alphabet vis a vis de chaine2");
    }
    if (comp > 0) {
        printf("Chaine2 est avant dans l'alphabet vis a vis de chaine1");
    }
    if (comp == 0) {
        printf("Chaine1 est identique à chaine2");
    }
    return 0;
}
