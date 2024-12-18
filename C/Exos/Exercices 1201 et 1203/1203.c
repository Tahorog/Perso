#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void nombreAleatoire(int *nombre1) {
    *nombre1 = rand() % RAND_MAX;
}

void nombreAleatoireSeuilHaut(int *nombre1) {
    int seuilHaut;
    printf("Choisis un max :");
    scanf("%d",&seuilHaut);
    *nombre1 = rand() % seuilHaut + 1;
}

void nombreAleatoireSeuilHautSeuilBas(int *nombre1) {
    int seuilBas;
    int seuilHaut;
    printf("Choisis un max :");
    scanf("%d",&seuilHaut);
    printf("Choisis un min :");
    scanf("%d",&seuilBas);
    *nombre1 = seuilBas + rand() % (seuilHaut - seuilBas + 1);
}

void nombreAleatoireSeuilHautSeuilBasSeuiln(int *nombre1) {
    int seuilBas;
    int seuilHaut;
    int n;
    printf("Choisis un max :");
    scanf("%d",&seuilHaut);
    printf("Choisis un min :");
    scanf("%d",&seuilBas);
    printf("Choisis un nombre d'aleatoire :");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++) {
        *nombre1 = seuilBas + rand() % (seuilHaut - seuilBas + 1);
        printf("%d ",*nombre1);
    }
}

void nombreAleatoire2decimales(float *nombre2) {
    int n;
    printf("Choisis un nombre d'aleatoire :");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++) {
        *nombre2 = 0 + (float)rand() / RAND_MAX;
        printf("%.2f ",*nombre2);
    }
}

void nombreAleatoire3decimales(float *nombre2) {
    int n;
    printf("Choisis un nombre d'aleatoire :");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++) {
        *nombre2 = 0 + (float)rand() / RAND_MAX * 140 - 50;
        printf("%.3f ",*nombre2);
    }
}
int main() {
    int nombre1, seuilBas, n, choix;
    float nombre2;

    printf("Menu\n");
    printf("1) Nombre aleatoire sans condition\n");
    printf("2) Nombre aleatoire avec seuilHaut\n");
    printf("3) Nombre aleatoire avec seuilBas et seuilHaut\n");
    printf("4) n nombres aleatoires avec seuilBas et seuilHaut\n");
    printf("5) n nombres aleatoires 2 decimales flottants entre 0 et 1\n");
    printf("6) n nombres aleatoires 3 decimales flottants entre -50 et 90\n");
    printf("Choix :\n");
    scanf("%d", &choix);

    srand(time(NULL));

    switch(choix) {
        case 1:
            nombreAleatoire(&nombre1);
            printf("Nombre : %d\n", nombre1);
            break;
        case 2:
            nombreAleatoireSeuilHaut(&nombre1);
            printf("Nombre aleatoire : %d\n", nombre1);
            break;
        case 3:
            nombreAleatoireSeuilHautSeuilBas(&nombre1);
            printf("Nombre aleatoire : %d\n", nombre1);
            break;
        case 4:
            nombreAleatoireSeuilHautSeuilBasSeuiln(&nombre1);
            break;
        case 5:
            nombreAleatoire2decimales(&nombre2);
            break;
        case 6:
            nombreAleatoire3decimales(&nombre2);
            break;
        default:
            break;
    }
    return 0;
}
