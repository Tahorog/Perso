//
// Created by Picard on 26/11/2024.
//
#include "al_pack.h"
#include "getBlindedStr.h"

void draw_box(int x, int y) {

    ALLEGRO_BITMAP *image = al_load_bitmap("../ALLEGRO/images/case.png");
    if (image == NULL) {
        printf("Error loading image\n");
    }
    al_draw_bitmap(image, x, y, 0);

}

int blindChar(int n) {
    return ((n>96 && n<123)||(n>47 && n<58)||(n>64 && n<91)||n==93||n==124||n==91||n==45||n==95);
}

void init_shadow(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../ALLEGRO/images/shadow.png");

    if (!image) {
        printf("Error loading shadow.png\n");
    }
    al_draw_bitmap(image, x, y, 0);
}

void box_draw_pIcon(int n, int x, int y) {
    char file[100]="../ALLEGRO/images/box_player/pIconX.png";
    file[34]=n+48;
    ALLEGRO_BITMAP *image = al_load_bitmap(file);
    if (!image) {
        printf("Error loading player icon : %d\n",n);
    }
    al_draw_bitmap(image, x, y, 0);
}

char * getstr(ALLEGRO_FONT* font,Player liste[4],int player_i,int x,int y) {
    init_shadow(x, y);
    ALLEGRO_EVENT_QUEUE* queue=al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_USTR* str = al_ustr_new("");

    int quit = 0;
    while(quit==0){
        //Affiche la case
        draw_box(x,y);
        // desine le texte
        al_draw_ustr(font, al_map_rgb_f(0.5647058823529412, 0.44313725490196076, 0.08235294117647059), x+435, y+75, ALLEGRO_ALIGN_CENTRE, str);
        //affiche l'icon du joueur
        box_draw_pIcon(liste[player_i].avatar,x,y);
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        switch (event.type){
            case ALLEGRO_EVENT_KEY_CHAR:
            //printf("event.type=%d\n", event.type);
            if(al_ustr_size(str) <TAILLE_PSEUDO && blindChar(event.keyboard.unichar)) {
                al_ustr_append_chr(str, event.keyboard.unichar);
            }

            else if(event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE){ //touche delete
                if(al_ustr_size(str) && event.keyboard.unichar!='\0') {//1si ya caractere 2ne prend qu'une touche delete sur trois captées
                    al_ustr_truncate(str, (al_ustr_size(str)-1));
                }
            }
            if(event.keyboard.unichar == 13){ // retour a la ligne
                if (al_ustr_size(str) > 0 && liste[player_i].avatar) {
                    quit=1;
                }
            }
            break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                for(int i=0;i<3;i++) {
                    for(int j=0;j<2;j++) {
                        if (event.mouse.x > 123+j*164 && event.mouse.y > 273+i*161 && event.mouse.x < 123+122+j*164 && event.mouse.y < 750+122+i*161) {
                            //printf("button clicked\n");
                            liste[player_i].avatar=i*2+j+1;
                            break;
                        }
                    }
                }
            break;
            case ALLEGRO_EVENT_MOUSE_AXES:
                al_flush_event_queue(queue);
            break;
        }
    }
    return al_cstr(str);
}

void selectBox_draw_pIcon() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<2;j++) {
            box_draw_pIcon(i*2+j+1,65+j*164,218+i*161);
        }
    }
}
