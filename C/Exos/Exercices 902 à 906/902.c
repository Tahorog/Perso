#include <stdio.h>
int main() {
    int val1, *pt1, **ppt1;
    unsigned char val2, *pt2, **ppt2;
    char lettre, *pt3, **ppt3;

    pt1 = &val1;
    pt2 = &val2;
    pt3 = &lettre;

    ppt1 = &pt1;
    ppt2 = &pt2;
    ppt3 = &pt3;

    val1 = 2;
    val2 = 'R';
    lettre = 'F';

    printf("Val1 : %d\n", val1);
    printf("Val2 : %c\n", val2);
    printf("Lettre : %c\n", lettre);

    *pt1 = 4;
    *pt2 = 'P';
    *pt3 = 'C';

    printf("Val1 : %d\n", val1);
    printf("Val2 : %c\n", val2);
    printf("Lettre : %c\n", lettre);

    **ppt1 = 8;
    **ppt2 = 'O';
    **ppt3 = 'E';

    printf("Val1 : %d\n", val1);
    printf("Val2 : %c\n", val2);
    printf("Lettre : %c\n", lettre);

    return 0;
}
