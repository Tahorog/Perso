//
// Created by Picard on 26/11/2024.
//
#include "background.h"
#include "getBlindedStr.h"


void init_background(int n,ALLEGRO_DISPLAY *ecran) {
    char file[100]="../ALLEGRO/images/background/X.jpg";
    file[29]=n+48;
    ALLEGRO_BITMAP *image = al_load_bitmap(file);
    if (!image) {
        printf("Error loading background : %d.jpg\n",n);
        al_destroy_display(ecran);
    }
    al_draw_bitmap(image, 0, 0, 0);

    // remplacer par graphisme
    switch (n) {
        case 3:
            selectBox_draw_pIcon();
            break;

    }
}
