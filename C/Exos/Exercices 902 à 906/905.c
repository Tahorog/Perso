#include <stdio.h>
int sous_programme(int *produit, float *prixHT,int *tauxTVA) {



    printf("Identifiant (numero): ");
    scanf("%d", produit);
    printf("Prix hors taxe :");
    scanf("%f", prixHT);
    printf("Taux de TVA (pourcentage):");
    scanf("%d", tauxTVA);

    float prixTTC  = *prixHT + (*prixHT * *tauxTVA/100);
    return prixTTC;
}

int main() {
    int produit, tauxTVA;
    float prixHT, prixTTC;

    prixTTC = sous_programme(&produit, &prixHT, &tauxTVA);
    printf("Identifiant : %d\n", produit);
    printf("Taux TVA : %d\n", tauxTVA);
    printf("Prix hors taxe : %.2f\n", prixHT);
    printf("Prix toute taxe comprise : %f\n", prixTTC);
    return 0;
}
