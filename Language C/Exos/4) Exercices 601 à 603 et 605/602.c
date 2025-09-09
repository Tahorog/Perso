#include <stdio.h>
int main() {
    int val1, val2, val3;

    printf("Val1 :");
    scanf("%d", &val1);
    printf("Val2 :");
    scanf("%d", &val2);
    printf("Val3 :");
    scanf("%d", &val3);

    if (val1 == val2 && val2 == val3) {
        printf("Il n'y a qu'une seule valeur.");
    }
    else if (val1 == val2 && val3 != val2) {
        printf("Il y a 2 valeurs.");
    }
    else {
        printf("Il y a 3 valeurs.");
    }
    return 0;
}
