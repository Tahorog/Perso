#include <stdio.h>
int main() {
    int Nlv, Nf, Nm, Np;
    float moyenneG, moyenneL, moyenneS;

    do {
        printf("Choisir une note de langue vivante :");
        scanf("%d", &Nlv);
    } while (Nlv < 0 || Nlv > 20);

    do {
        printf("Choisir une note de francais :");
        scanf("%d", &Nf);
    } while (Nf < 0 || Nf > 20);

    do {
        printf("Choisir une note de mathematiques :");
        scanf("%d", &Nm);
    } while (Nm < 0 || Nm > 20);

    do {
        printf("Choisir une note de physique :");
        scanf("%d", &Np);
    } while (Np < 0 || Np > 20);

    moyenneG = Nlv + Nf + Nm + Np;
    moyenneG = moyenneG / 4;

    moyenneL = Nlv + Nf;
    moyenneL = moyenneL / 2;

    moyenneS = Nm + Np;
    moyenneS = moyenneS / 2;
    if (moyenneG > 10) {
        printf("La moyenne des notes est superieure a 10.\n");
    }
    if (Nm > moyenneG && Nf > moyenneG) {
        printf("Les notes de maths et de francais sont superieures a la moyenne des 4 notes.\n");
    }
    if (Nlv > 10 || Nm > 10 || Nf > 10 || Np > 10) {
        printf("Il y a au moins une note superieure a 10.\n");
    }
    if (Nlv > 10 && Nm > 10 && Nf > 10 && Np > 10) {
        printf("Toutes les notes sont supérieures a 10.\n");
    }
    if (moyenneL > 10 || moyenneS > 10) {
        printf("Le moyenne d'un des deux types est superieure a 10.\n");
    }
    return 0;
}
