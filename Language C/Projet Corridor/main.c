#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "tout.h"
#include "ALLEGRO/main.h"

#define DISPLAY_MODE 1

int main(void) {
    if (DISPLAY_MODE)
        return al_main();
    srand(time(NULL));
    int nbplayers;
    int tab[TAILLE][TAILLE]={{0}};


    Player liste[4];
    Score score[MAX];
    int stop=0;


    int beginner=0;
    int savePlayer_i=0;
    int jeu=0;
    int quit=0;

    ouverture();

    switch (menu()) {
        case 1:
            customizeGame(&nbplayers,liste);
            init(tab,liste,nbplayers);
            jeu=1;
            beginner=rand()%4;
            stop=loadScores(liste,score);
        break;
        case 2:
            loadPartie(tab,&beginner,&nbplayers,liste);
            stop=loadScores(liste,score);
            jeu=1;
        break;
        case 3:
            quit=2;
        break;
    }


    while (!quit) {
        while (jeu) {
            for (int i=beginner;i<4;i++) {
                if (!(nbplayers==2 && i%2==1))//skip le tour des joueurs i = 1 et i = 3 si le nb de joueurs == 4
                    tour(tab,i+1,liste,&jeu);
                beginner=0;
                savePlayer_i=i;
                if (!jeu) {
                    beginner=i;
                    break;
                }
                if ( check_win(liste,i)) {
                    countPoints(liste,i);
                    saveScores(liste,score,stop);
                    show_victory(i);
                    return 0;
                }
            }
        }
        switch (menu()) {
            case 1:
                jeu=1;
                break;
            case 2:
                //loadPartie(&beginner);
                break;
            case 3:
                quit=1;
                break;
        }
    }
    clear(40);
    if (quit==1) {
        savePartie(tab,savePlayer_i,nbplayers,liste);
        printf("\nSaved\n");
    }
    printf("Au revoir !");
    return 0;
}

//Netoyer les parties non alegro ?