#include <stdio.h>
int main() {
    int entier, a, b, c;
    float reel;
    char caracter;

    a = sizeof(entier);
    b = sizeof(reel);
    c = sizeof(caracter);

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    return 0;
}
