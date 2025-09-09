#include <stdio.h>
#define TAILLE 20

typedef struct {
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct {
    int designation;
    int categorie;
    t_date peremption;
    int stock;
    float prix;
} t_article;

t_article remplir() {
    t_article article;

    printf("Designation de l'article : ");
    scanf("%d", &article.designation);
    printf("Categorie de l'article : ");
    scanf("%d", &article.categorie);

    printf("Peremption de l'article (jour mois annee) : ");
    scanf("%d %d %d", &article.peremption.jour, &article.peremption.mois, &article.peremption.annee);

    printf("Stock de l'article : ");
    scanf("%d", &article.stock);
    printf("Prix de l'article : ");
    scanf("%f", &article.prix);

    return article;
}

void tableau(t_article articles[]) {
    for (int i = 0; i < TAILLE; i++) {
        articles[i] = remplir();
    }
}

void afficherArticle(t_article article) {
    printf("Designation : %d\n", article.designation);
    printf("Categorie : %d\n", article.categorie);
    printf("  Peremption : %02d/%02d/%d\n", article.peremption.jour, article.peremption.mois, article.peremption.annee);
    printf("Stock : %d\n", article.stock);
    printf("Prix : %.2f\n", article.prix);
}

void afficherTableau(t_article articles[]) {
    for (int i = 0; i < TAILLE; i++) {
        afficherArticle(articles[i]);
    }
}

void afficherCategorie(t_article articles[], int categorie) {
    printf("Articles de la categorie %d :\n", categorie);
    for (int i = 0; i < TAILLE; i++) {
        if (articles[i].categorie == categorie) {
            afficherArticle(articles[i]);
        }
    }
}

int perimes(t_article articles[], t_date date_limite) {
    int count = 0;
    for (int i = 0; i < TAILLE; i++) {
        if (articles[i].peremption.annee < date_limite.annee ||
            (articles[i].peremption.annee == date_limite.annee && articles[i].peremption.mois < date_limite.mois) ||
            (articles[i].peremption.annee == date_limite.annee && articles[i].peremption.mois == date_limite.mois && articles[i].peremption.jour < date_limite.jour)) {
            count++;
        }
    }
    return count;
}

int main() {
    t_article articles[TAILLE];

    tableau(articles);

    afficherTableau(articles);

    int categorie;
    printf("Quelle categorie ? ");
    scanf("%d", &categorie);
    afficherCategorie(articles, categorie);

    t_date date_limite;
    printf("Date limite ? JJ/MM/AAAA : ");
    scanf("%d %d %d", &date_limite.jour, &date_limite.mois, &date_limite.annee);
    int articles_perimes_count = perimes(articles, date_limite);
    printf("Nombre de perime(s) : %d\n", articles_perimes_count);

    return 0;
}
