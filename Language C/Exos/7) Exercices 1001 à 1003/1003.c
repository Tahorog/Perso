#include <stdio.h>
void insertion(float notes[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Note %d: ", i);
        scanf("%f", &notes[i]);
    }
}

void print(float notes[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%f\n", notes[i]);
    }
}

float sous_programme(float notes[10]) {
    float somme = 0.0;
    int i;
    float moyenne;

    insertion(notes);
    print(notes);

    for (i = 0; i < 10; i++) {
        somme += notes[i];
    }
    moyenne = somme / 10;
    return moyenne;
}

void maxmin(float notes[10], float *max, float *min) {
    *max = notes[0];
    *min = notes[0];
    for (int i = 1; i < 10; i++) {
        if (notes[i] > *max) {
            *max = notes[i];
        }
        if (notes[i] < *min) {
            *min = notes[i];
        }

    }
}

int main() {
    float notes[10], moyenne, max, min;
    moyenne = sous_programme(notes);
    printf("============\n");
    printf("%f\n", moyenne);

    maxmin(notes, &max, &min);
    printf("==============\n");
    printf("%f\n", max);
    printf("%f\n", min);
    return 0;
}
