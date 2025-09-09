#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 300
#define MIN 20

struct t_film {
    char title[30];
    int year;
    char author[2];
    int duration;
    bool seen;
    int grade;
};

void remplir(struct t_film *film) {

    printf("Entrer un titre :");
    scanf("%49s", film -> title);

    srand(time(NULL));

    film -> year = 1930 + rand() % 94;
    film -> duration = MIN + rand() % (MIN - MAX + 1);
    film -> grade = 0 + rand() % 10;

    int temp;

    printf("Film deja vu ? 1/OUI 0/NON");
    scanf("%d", &temp);
    film -> seen = (temp == 1);
}

void afficher(const struct t_film *film) {

    printf("Info du film : \n");
    printf("Tire : %s\n", film -> title);
    printf("Duree : %d\n", film -> duration);
    printf("Deja vu ? %s\n", film -> seen ? "OUI" : "0/NON");
    printf("Note : %d\n", film -> grade);
    printf("Annee : %d\n", film -> year);
}

int main() {
    struct t_film film;

    remplir(&film);
    afficher(&film);
    return 0;
}
