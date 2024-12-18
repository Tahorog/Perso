//
// Created by Picard on 19/11/2024.
//

#include "tour.h"
#include "tout.h"




void tour(int tab[TAILLE][TAILLE],int player_n,Player liste[4],int * jeu) {
    char retour;
    int x,y,x1,y1;
    int player_i=player_n-1;


    clear(60);
    show(tab, liste[player_i].mode,liste);
    printf("\n[%d] ",player_n);
    printPerso(player_n,liste);

    printf(" %s\n",liste[player_i].pseudo);

    if (liste[player_i].mode) {
        printf("    [Mode : Deplacement ]\n"); // 1 = deplacement, 0 = Place_wall
    } else {
        printf("    [Mode : Place a wall]\n");
    }

    do {
        printf("    [Change mode ? (y/n)] [Passer: p] [Menu: m]\n    ==> ");

        fflush(stdin);
        scanf("%c",&retour);

    } while (!(retour=='n'||retour=='N'||retour=='m'||retour=='M'||retour=='y'||retour=='Y'||retour=='p'||retour=='P'));

    if (retour=='m'|| retour=='M') {
        printf("Sortie du jeu...");
        *jeu=0;
        return;
    }
    if (retour=='p'|| retour=='P') {
        return;
    }

    if (retour=='y'||retour=='Y') {
        liste[player_i].mode=!liste[player_i].mode;
    }

    if ( liste[player_i].mode==0 && liste[player_i].barrieres==0) {
        // si le joueur est en mode placewall, mais plus de barriere
        liste[player_i].mode=1;
        color(4,0);
        printf("Plus de barrieres");
        color(7,0);
    }

    fflush(stdin);

    if (liste[player_i].mode) {
        clear(60);
        do {
            show(tab, liste[player_i].mode,liste);
            printf("\n[%d] ",player_n);
            printPerso(player_n,liste);
            printf(" %s\n",liste[player_i].pseudo);
            printf("    [Mode : Deplacement ]\n");
            printf("    [Move to case: (x,y)]\n    ==>");
            scanf("%d%d",&x,&y);
            if (!blindMvt(tab, player_n,liste,x,y)) {
                clear(60);
                color(4,0);
                printf("Choisissez un deplacement valide");
                color(7,0);

            }
        } while (!blindMvt(tab, player_n,liste,x,y));
        play(tab, player_n,liste,x,y);
    } else {
        do {
            show(tab, liste[player_i].mode,liste);
            printf("\n[%d] ",player_n);
            printPerso(player_n,liste);
            printf(" %s\n",liste[player_i].pseudo);
            printf("    [Mode : Place a wall ] [Barrieres : %d]\n",liste[player_i].barrieres);
            printf("    [Place a wall: (x,y)(x,y)]\n    ==>");
            scanf("%d%d%d%d",&x,&y,&x1,&y1);
            if (!blindWall(tab,x,y,x1,y1)) {
                clear(60);
                color(4,0);
                printf("Choisissez un placement valide");
                color(7,0);
            }
        } while (!(blindWall(tab,x,y,x1,y1)));
        placeWall(tab,x,y,x1,y1);
        liste[player_i].barrieres-=1;
    }
}