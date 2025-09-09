#include <stdio.h>
void analyse(int ent1, int ent2, int *somme) {

    *somme = ent1 + ent2;
}

int main() {
    int *somme, e1, e2;
    printf("Entrer e1 :");
    scanf("%d", &e1);
    printf("Entrer e2 :");
    scanf("%d", &e2);

    analyse(e1, e2, &somme);

    printf("Somme = %d", somme);
    return 0;
}
