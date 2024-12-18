//
// Created by Picard on 19/11/2024.
//

#include "stockage.h"
#include "macros.h"
#include <stdio.h>
#include <string.h>

#include "modifications.h"


void savePartie(int tab[TAILLE][TAILLE],int savePlayer_i,int nbplayers,Player liste[4]) {
    FILE *pf = fopen("../SAVES/savePartie.txt","w");
    if (pf == NULL) {
        printf("File could not be opened\n");
    }

    fprintf(pf,"%d\n%d\n",savePlayer_i,nbplayers);
    for(int i=0;i<4;i++) {
        fprintf(pf,"%s\n%d\n%d\n%d\n%d\n%d\n%d\n",liste[i].pseudo,liste[i].coord.x,liste[i].coord.y,liste[i].mode,liste[i].barrieres,liste[i].avatar,liste[i].timer);
    }

    for (int i=0;i<TAILLE;i++) {
        for (int j=0;j<TAILLE;j++) {
            fprintf(pf,"%d\n",tab[i][j]);
        }
    }
    fclose(pf);
    pf=NULL;
    printf("File saved\n");
}

void loadPartie(int tab[TAILLE][TAILLE],int * beginner,int * nbplayers,Player liste[4]) {
    FILE *pf = fopen("../SAVES/savePartie.txt","r");
    if (pf == NULL) {
        printf("File savePartie could not be opened\n");
    }


    fscanf(pf,"%d",beginner);
    fscanf(pf,"%d",nbplayers);
    for(int i=0;i<4;i++) {
        fscanf(pf,"%s",&liste[i].pseudo);//fonctionne
        fscanf(pf,"%d",&liste[i].coord.x);
        fscanf(pf,"%d",&liste[i].coord.y);
        fscanf(pf,"%d",&liste[i].mode);
        fscanf(pf,"%d",&liste[i].barrieres);
        fscanf(pf,"%d",&liste[i].avatar);
        fscanf(pf,"%d",&liste[i].timer);
    }

    int value =0;
    for (int i=0;i<TAILLE;i++) {
        for (int j=0;j<TAILLE;j++) {
            fscanf(pf,"%d",&tab[i][j]);
        }
    }

    printf("partie loaded\n");
    fclose(pf);
    pf=NULL;
}

void saveScores(Player liste[4], Score save[MAX],int stop) {
    FILE *pf = fopen("../SAVES/saveScores.txt","w");
    if (pf == NULL) {
        printf("File saveScore could not be opened\n");
    }

    for(int i=0;i<4;i++) {
        fprintf(pf,"%s\n%d\n",liste[i].pseudo,liste[i].score);
    }

    for (int i=0;i<stop;i++) {
        fprintf(pf,"%s\n%d\n",save[i].pseudo,save[i].score);
    }

    fclose(pf);
    pf=NULL;
    printf("File saveScores saved\n");
}

void initScores(Player liste[4]) {
    for (int i=0;i<4;i++) {
        liste[i].score=0;
    }
}

int loadScores(Player liste[4], Score save[MAX]) {
    initScores(liste);
    FILE *pf = fopen("../SAVES/saveScores.txt","r");
    if (pf == NULL) {
        printf("File saveScore could not be opened\n");
    }
    char pseudo[TAILLE_PSEUDO];
    int i = 0;
    int save_i=0;
    int ignore=0;
    while (i<MAX && fscanf(pf,"%s",&pseudo)==1) {
        for (int j=0;j<4;j++) {
            if (strcmp(liste[j].pseudo,pseudo)==0) {
                fscanf(pf,"%d",&liste[j].score);
                ignore=1;
            }
        }
        if (ignore!=1) {
            strcpy(save[save_i].pseudo,pseudo);
            fscanf(pf,"%d",&save[save_i].score);
            save_i++;
        }
        ignore=0;
        i++;
    }
    printf("scores loaded\n");
    fclose(pf);
    pf=NULL;
    for (int i=0;i<4;i++) {
        printf("%s : %d\n",liste[i].pseudo,liste[i].score);
    }
    printf("\nsave :\n");
    for (int i=0;i<save_i;i++) {
        printf("%s : %d\n",save[i].pseudo,save[i].score);
    }
    return save_i;
}