//
// Created by Picard on 19/11/2024.
//
#include "affichage_console.h"
#include "external_console.h"
#include "modifications.h"
#include <string.h>


#define COTE 11
#define TAILLE (COTE+COTE-1)
#define W_COLOR 12 //red

//#=======================  COLOR  =========================#

// Fonction qui permet de définir la couleur et prend en paramètre la couleur du fond et celle du texte.

void color(int t,int f){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
//#=========================================================#

// Cette fonction permet de mettre du vide dans la console, elle prend en paramètre un certain nombre n.
// Pour le nombre de n choisis cette fonction va sauter le même nombre de lignes.
// Elle permet donc de faire du vide dans la console et de ne pas avoir plusieurs tableaux de jeu collés pendant la partie.

void clear(int n) {
    for(int i=0;i<n;i++)
        printf("\n");
}

// Cette fpnction permet d'afficher les personnages sur le plateau de jeu en console avec leurs couleurs.

void printAvatar(int i) {
    switch (i) {
        case 0:
            color(0,8);
        printf(" X_X ");
        color(7,0);
        break;
        break;
        case 1:
            color(4,6);
        printf("\"");
        color(0,6);
        printf(">_<");
        color(4,6);
        printf("\"");
        color(7,0);
        break;
        case 2:
            color(4,4);
        printf("'");
        color(0,4);
        printf("0_0");
        color(9,4);
        printf("'");
        color(7,0);
        break;
        case 3:
            color(4,5);
        printf("o");
        color(0,5);
        printf("^_^");
        color(4,5);
        printf("o");
        color(7,0);
        break;
        case 4:
            color(4,1);
        printf("#");
        color(0,1);
        printf("^o^");
        color(4,1);
        printf("#");
        color(7,0);
        break;
        case 5:
            color(4,2);
        printf("~");
        color(0,2);
        printf("^u^");
        color(4,2);
        printf("~");
        color(7,0);
        break;
        case 6:
            color(4,3);
        printf(">");
        color(0,3);
        printf("^.^");
        color(4,3);
        printf("<");
        color(7,0);
        break;
    }
}

void printPerso(int perso, Player liste[4]) {
    if (perso == 0) {
        color(8, 0);
        printf(" [_] ");
        color(7, 0);
        return;
    }
    printAvatar(liste[perso-1].avatar);
}



// Cette fonstion permet d'afficher le plateau de jeu.
// Le plateau est une grille de 10 cases sur 10 cases avec les 4 coins supprimés.
// Le plateau est affiché dans la console avec les numéros des lignes et colones à côté. 

void show(int tab[TAILLE][TAILLE],int mode,Player liste[4]) {
    color(15,0);
    printf("\n\n   ");
    if (mode) {
        for (int i = 0; i < COTE; i++) {
            if (i <10)
                printf(" ");
            printf("    %d", i);
        }
    } else {
        printf("   ");
        for (int i = 0; i < TAILLE; i++) {
            if (i <10)
                printf(" ");
            printf(" %d", i);
        }
    }
    printf("\n\n");
    for (int i = 0; i < TAILLE; i++) {
        if (mode) {
            if (i%2 == 0) {
                color(15,0);
                printf("%d    ", i/2);
            }else {
                printf("     ");
            }
            if (i<20)
                printf(" ");
        } else {
            color(15,0);
            printf("%d    ", i);
            if (i<10)
                printf(" ");
        }

        for (int j = 0; j < TAILLE; j++) { //LIGNE
            if (!(i == 0 && (j == 0 || j == TAILLE - 1) || i == TAILLE - 1 && (j == 0 || j == TAILLE - 1))) {
                if (i%2 == 1) {
                    if ((tab[i][j]!=0)&&(i>1 && j>1 && i<TAILLE-2 && j<TAILLE-2)) {
                        color(W_COLOR,0);
                        if (j%2 == 1) {
                            if (tab[i][j]==1 ) { //milieu 1 horizontal 2 vertical
                                printf("-");
                            } else {
                                printf("|");
                            }
                        }else {
                            printf(" --- ");
                        }
                    } else {
                        if (j%2 == 1) {
                            printf(" ");
                        }else {
                            printf("     ");
                        }
                    }
                }else if (j%2 == 1){
                    color(W_COLOR,0);
                    if (tab[i][j]==1 && (i>1 && j>1 && i<TAILLE-2 && j<TAILLE-2)){
                        printf("|");
                    }else {
                        printf(" ");
                    }
                }else {
                    printPerso(tab[i][j],liste);
                }


            } else {
                printf("     ");
            }
        }
        printf("\n");
    }
    color(7,0);
}


void show_victory(int player_i) {
    char gauche[1000] = " /*            ..*,#/(((((((((##########((((#%,,.             ,*                               Player : ";
    char droite[1000] = "                                         /*            ..*,#/(((((((((##########((((#%,,.          ,*   ";
    char liste[2];

    liste[0] = player_i + 49;
    liste[1] = '\0';

    strcat(gauche, liste);
    strcat(gauche, droite);
    clear(40);
    color(4,0);
    affichageCentre("    ((@&&&     ./.(..........*%&&&&&%%#/,,../#*.(.     &&&&%&                                                                                         ((@&&&     ./.(..........*%&&&&&%%#/,,../#*.(.     &&&&%&   ");
    affichageCentre(" #.      (/    ..,(,....,,***(%&&&&&%%%(/*,*(#***.    ,(      *#                                                                                   #.      (/    ..,(,....,,***(%&&&&&%%%(/*,*(#***. ,(      *#   ");
    affichageCentre("/          /&(.*/,,,,**//((#&&&&%%%%%#(///(%**.&&#&            ,(                                                                                 /           %/&(.*/,,,,**//((#&&&&%%%%%#(///(%**.&          ,(  ");
    affichageCentre("(*             ..**/,*//((((##%%%%%%%%%#((((#%,,..             /#                                                                                 (*             ..**/,*//((((##%%%%%%%%%#((((#%,,..          /#  ");
    affichageCentre(gauche);
    affichageCentre("   &            .*,%###(((////(((((((((((((###.,.           .&                                                                                       &            .*,%###(((////(((((((((((((###.,.         .&    ");
    affichageCentre("                ./.##((///*****////((((((((##(.,.                                                                                                                 ./.##((///*****////((((((((##(.,.               ");
    affichageCentre("                 %.....,,,,,,,*************,../&                                                                                                                   %.....,,,,,,,*************,../&                ");
    affichageCentre("                 % #..,,,,,,,,************,,.# *           ********    ********   **********          **   **     **    ********   **********   ********           % #..,,,,,,,,************,,.# *                ");
    affichageCentre("                    ..,,,,,,,,***********,,,.              **         **              **              **   **     **   **              **       **                    ..,,,,,,,,***********,,,.                   ");
    affichageCentre("                     .,,,,,,,,,*******,,,,,.               **         **              **              **   **     **   **              **       **                     .,,,,,,,,,*******,,,,,.                    ");
    affichageCentre("                      ..,,,,,,,*****,,,,,.                 *******    *********       **              **   **     **   *********       **       *******                 ..,,,,,,,*****,,,,,.                      ");
    affichageCentre("                         .,,,*/(#//*,,,,                   **                **       **              **   **     **          **       **       **                         .,,,*/(#//*,,,,                        ");
    affichageCentre("                           *%(((&%**#,                     **                **       **         **   **   **     **          **       **       **                           *%(((&%**#,                          ");
    affichageCentre("                            ,,,,,**,,                      ********   ********        **          *****     *******    ********        **       ********                      ,,,,,**,,                           ");
    affichageCentre("                              ####%                                                                                                                                             ####%                             ");
    affichageCentre("                              .,*/.                            ****     ****   ********   **   **         **         ********   **     **   *******                             .,*/.                             ");
    affichageCentre("                              *(#/.                            ** **   ** **   **         **   **         **         **         **     **   **    **                            *(#/.                             ");
    affichageCentre("                              ..% *                            **  ** **  **   **         **   **         **         **         **     **   **    **                            ..% *                             ");
    affichageCentre("                            ...(&%%..                          **   ***   **   *******    **   **         **         *******    **     **   *******                           ...(&%%..                           ");
    affichageCentre("                            ....(. *.                          **    *    **   **         **   **         **         **         **     **   **   **                           ....(. *.                           ");
    affichageCentre("                         ....,((#/(.....                       **         **   **         **   **         **         **         **     **   **    **                       ....,((#/(.....                        ");
    affichageCentre("                       /.#**,,.*%%*..,/(.,                     **         **   ********   **   ********   ********   ********    *******    **     **                    /.#**,,.*%%*..,/(.,                      ");
    affichageCentre("                      .#.,,*(##&&&%(/**,,%.                                                                                                                             .#.,,*(##&&&%(/**,,%.                     ");
    system("pause");
}
