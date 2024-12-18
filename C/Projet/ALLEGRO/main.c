#include "background.h"
#include "getBlindedStr.h"
#include "main.h"

ALLEGRO_DISPLAY *ecran;
ALLEGRO_BITMAP *image;
ALLEGRO_MOUSE_STATE mouse;
ALLEGRO_KEYBOARD_STATE key;

ALLEGRO_SAMPLE *sample;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;

ALLEGRO_EVENT_QUEUE* queue;

ALLEGRO_FONT* font;
ALLEGRO_FONT* font2;
ALLEGRO_FONT* walls_font;
ALLEGRO_FONT* pseudo_font;

void printPerso_with_allegro(int player_n,int x,int y,Player liste[4]) {
    char chemin[30]="../ALLEGRO/images/persos/_.png";
    chemin[25]=liste[player_n-1].avatar+48;
    chemin[30]='\0';
    image = al_load_bitmap(chemin);

    if (!image) {
        printf("%s\n",chemin);
        printf("Error loading 1.png\n");
        al_destroy_display(ecran);
    }
    al_draw_bitmap(image, 376+60*(x-1), 216+60*(y-1), 0);
}

void printWall_with_allegro(int x,int y,int n) {
    switch (n) {
        case 0:
            image = al_load_bitmap("../ALLEGRO/images/Walls/dot.png");
        x=375+60*(x/2) -10;
        y=215+60*(y/2) -10;
        break;
        case 1:
            image = al_load_bitmap("../ALLEGRO/images/Walls/H_wall.png");
        x=375+60*((x+1)/2-1);
        y=215+60*(y/2) -10;
        break;
        case 2:
            image = al_load_bitmap("../ALLEGRO/images/Walls/V_wall.png");
        x=375+60*(x/2) -10;
        y=215+60*((y+1)/2-1);
        break;
    }

    if (!image) {
        printf("Error loading wall\n");
        al_destroy_display(ecran);
    }

    al_draw_bitmap(image, x, y, 0);
}

void show_big_icon(int avatar) {
    char chemin[30]="../ALLEGRO/images/bigIcn/_.png";
    chemin[25]=avatar+48;
    chemin[30]='\0';
    image = al_load_bitmap(chemin);

    if (!image) {
        printf("%s\n",chemin);
        printf("Error loading 1.png\n");
        al_destroy_display(ecran);
    }
    al_draw_bitmap(image, 60,50, 0);
}

void show_nb_walls(int walls) {
    char murs[2];
    int x;
    if (walls==10) {
        strcpy(murs,"10");
        x=125;

    } else {
        murs[0]=(walls+'0');
        murs[1]='\0';
        x=130;
    }
    printf("%s\n",murs);
    al_draw_text(walls_font,al_map_rgb_f(0.33333333333333333, 0.0392156862745098, 0.0392156862745098),x,400,ALLEGRO_ALIGN_CENTER,murs);
}

void show_pseudo(int player_n,Player liste[4]) {
    al_draw_text(pseudo_font,al_map_rgb_f(0.5647058823529412, 0.44313725490196076, 0.08235294117647059),640,0,ALLEGRO_ALIGN_CENTER,liste[player_n-1].pseudo);
}

void show_player_id(int player_n,int nbplayers) {
    char id[1];
    id[0]=player_n+'0'-(player_n==3&&nbplayers==2);
    id[1]='\0';
    al_draw_text(walls_font,al_map_rgb_f(0.5647058823529412, 0.44313725490196076, 0.08235294117647059),1120,0,ALLEGRO_ALIGN_CENTER,id);
}

void show_with_allegro(int tab[TAILLE][TAILLE],Player liste[4],int player_n,int nbplayers) {
    init_background(4,ecran);
    show_big_icon(liste[player_n-1].avatar);
    show_nb_walls(liste[player_n-1].barrieres);
    show_pseudo(player_n,liste);
    show_player_id(player_n,nbplayers);


    for (int i = 0; i < TAILLE; i++) {
        // colones
        for (int j = 0; j < TAILLE; j++) {
            //LIGNE
            if (tab[i][j]!=0 ) { // SOMETHING ON THE POSITION ?
                if (i%2 == 0 && j%2 == 0) {// CASE
                    printPerso_with_allegro(tab[i][j],j/2,i/2,liste);
                } else if (i%2 == 1) { // INTER-LIGNE
                    if (j%2 == 1) { // INTER-COLONNES
                        printWall_with_allegro(j,i,0); // dot
                    }else { // COLONNES
                        printWall_with_allegro(j,i,1); // horizontal
                    }
                } else {// LIGNE
                    if (j%2 == 1) {
                        printWall_with_allegro(j,i,2);
                    }
                }
            }
        }
    }
    //ALLEGRO :
    al_flip_display();
    //=======
}


int play_with_allegro(int tab[TAILLE][TAILLE],Player liste[4],int player_n,int x,int y) {
    int player_i=player_n-1;
    if (x>938&&y>856&&x<1246&&y<920) { // PASSER LE TOUR
        return 1;
    }
    if ((x-315)%60<51 && (y-155)%60<51) {
        if (blindMvt(tab,player_n,liste,(x-315)/60,(y-155)/60)) {
            play(tab,player_n,liste,(x-315)/60,(y-155)/60);
            return 1;
        }
    } else if (liste[player_i].barrieres>0){
        if ((y-155)%60>50){// INTERLIGNES
            if ((x-315)%60>50) {
                //INTERCOLONES
                printf("NOP");//dot
            }else {
                printf("mur : %d %d",(x-315)/30,(y-155)/30);
                if ((x-315)%60<25) {
                    if (blindWall(tab,(x-315)/30,(y-155)/30,(x-315)/30-2,(y-155)/30)) {
                        placeWall(tab,(x-315)/30,(y-155)/30,(x-315)/30-2,(y-155)/30);
                        liste[player_i].barrieres-=1;
                        return 1;
                    }
                } else {
                    if (blindWall(tab,(x-315)/30-1,(y-155)/30,(x-315)/30+1,(y-155)/30)) {
                        placeWall(tab,(x-315)/30-1,(y-155)/30,(x-315)/30+1,(y-155)/30);
                        liste[player_i].barrieres-=1;
                        return 1;
                    }
                }
            }
        } else { // INTERCOLLONES
            if ((y-155)%60<25) {
                if (blindWall(tab,(x-315)/30,(y-155)/30,(x-315)/30,(y-155)/30-2)) {
                    placeWall(tab,(x-315)/30,(y-155)/30,(x-315)/30,(y-155)/30-2);
                    liste[player_i].barrieres-=1;
                    return 1;
                }
            } else {
                if (blindWall(tab,(x-315)/30,(y-155)/30-1,(x-315)/30,(y-155)/30+1)){
                    placeWall(tab,(x-315)/30,(y-155)/30-1,(x-315)/30,(y-155)/30+1);
                    liste[player_i].barrieres-=1;
                    return 1;
                }
            }

        }
    }
    return 0;
}

int update(int tab[TAILLE][TAILLE],Player liste[4],int player_n,int *jeu) {
    int x,y;
    al_get_mouse_state(&mouse);
    x=mouse.x;
    y=mouse.y;

    al_get_keyboard_state(&key);

    if (al_key_down(&key,ALLEGRO_KEY_ESCAPE)) {
        while ( al_key_down(&key,ALLEGRO_KEY_ESCAPE) ) {
            al_get_keyboard_state(&key);
        }
        *jeu=0;
        return 1;
    }

    if ( al_mouse_button_down(&mouse,1) ) {
        while ( al_mouse_button_down(&mouse,1) ) {
            al_get_mouse_state(&mouse);
        }
        printf("%d,%d\n",x,y);
        if (x>30&&y>830&&x<133&&y<933) { //RETOUR MENU
            *jeu=0;
            return 1;
        }
        if (play_with_allegro(tab,liste,player_n,x,y)){
            return 1;
        }
    }
    return 0;
}

void tour_with_allegro(int tab[TAILLE][TAILLE],Player liste[4],int player_n,int *jeu,int nbplayers) {
    int retour=0;
    printf("[%d] ",player_n);
    show_with_allegro(tab,liste,player_n,nbplayers);
    while (!retour) {
        retour=update(tab,liste,player_n,jeu);
    }
}


int execute_nbjoueurs(int x,int y,int *jeu,int *nbplayers) {
    if (0) // mettre un bouton retour ?
        *jeu=1;
    if (y>=290 && y<=415) {
        printf("2 players set\n");
        *nbplayers=2;
        return 1;
    }
    if (y>=560 && y<=685) {
        printf("4 players set\n");
        *nbplayers=4;
        return 1;
    }
    return 0;
}


int update_nbjoueurs(int *jeu,int *nbplayers) {
    int x,y;
    al_get_mouse_state(&mouse);
    x=mouse.x;
    y=mouse.y;

    al_get_keyboard_state(&key);

    if (al_key_down(&key,ALLEGRO_KEY_ESCAPE)) {
        while ( al_key_down(&key,ALLEGRO_KEY_ESCAPE) ) {
            al_get_keyboard_state(&key);
        }
        *jeu=0;
        return 1;
    }
    if ( al_mouse_button_down(&mouse,1) ) {
        while ( al_mouse_button_down(&mouse,1) ) {
            al_get_mouse_state(&mouse);
        }
        printf("nbjoueurs menu : %d,%d\n",x,y);
        if (x>=345 && x<=930) {
            return execute_nbjoueurs(x,y,jeu,nbplayers);
        }
    }
    return 0;
}


void nbjoueurs_with_allegro(int* jeu, int *nbplayers) {
    int retour=0;
    init_background(2,ecran);
    al_flip_display();
    while (!retour) {
        retour=update_nbjoueurs(jeu,nbplayers);
    }
}


int execute_menu(int x,int y,int *quit,int *jeu,int *nbplayers) {
    if (x>=345 && y>=660 && x<=930 && y<=785) {
        return 3;
    }
    if (x>=345 && y>=444 && x<=930 && y<=573) {
        return 2;
    }
    if (x>=345 && y>=230 && x<=930 && y<=355) {
        return 1;
    }
    return 0;
}

int update_menu(int *quit,int *jeu, int* nbplayers) {
    int x,y;
    al_get_mouse_state(&mouse);
    x=mouse.x;
    y=mouse.y;

    al_get_keyboard_state(&key);

    if (al_key_down(&key,ALLEGRO_KEY_ESCAPE)) {
        while ( al_key_down(&key,ALLEGRO_KEY_ESCAPE) ) {
            al_get_keyboard_state(&key);
        }
        return 3;
    }

    if ( al_mouse_button_down(&mouse,1) ) {
        while ( al_mouse_button_down(&mouse,1) ) {
            al_get_mouse_state(&mouse);
        }
        printf("Allegro Menu : %d,%d\n",x,y);
        return execute_menu(x,y, quit,jeu,nbplayers);
    }
    return 0;
}

int menu_with_allegro(int *quit,int*jeu,int*nbplayers) {
    int retour=0;
    init_background(1,ecran);
    al_flip_display();
    while (!retour) {
        retour=update_menu(quit,jeu,nbplayers);
    }
    return retour;
}

void wait_for_something() {
    queue=al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    while (1) {
        ALLEGRO_EVENT event;
        while (al_get_next_event(queue, &event)) {
            switch (event.type) {
                case ALLEGRO_EVENT_KEY_CHAR:
                    return;
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                    while (1) {
                        while ( al_get_next_event(queue, &event) ) {
                            if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                                return;
                            }
                        }
                    }

            }
        }
    }
}


void al_ouverture() {
    init_background(0,ecran);
    al_flip_display();
    wait_for_something();
}

void al_init_all(void) {
    al_init();
    al_init_font_addon();
    al_install_keyboard();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_mouse();
    queue= al_create_event_queue();

    font  = al_load_font("../ALLEGRO/polices/ariblk.ttf", 46, 0);//police arial black
    if (!font) {
        printf("Error loading font\n");
    }
    font2 = al_load_font("../ALLEGRO/polices/ariblk.ttf", 211, 0);
    if (!font2) {
        printf("Error loading font2\n");
    }
    walls_font=al_load_font("../ALLEGRO/polices/ariblk.ttf", 130, 0);
    if (!walls_font) {
        printf("Error loading walls font\n");
    }
    pseudo_font=al_load_font("../ALLEGRO/polices/ariblk.ttf", 63, 0);
    if (!pseudo_font) {
        printf("Error loading pseudo font\n");
    }


    // LE SON
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(2);

    //========================================== MUSIC ===================================================
    sample = al_load_sample("../ALLEGRO/song.ogg");
    if (!sample) {
        printf("Failed to load song.ogg\n");
        return;
    }

    sample_instance = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());

    al_play_sample_instance(sample_instance);
    //=====================================================================================================*/

    ecran = al_create_display(1280,960);

    if (!ecran) {
        printf("Error creating display\n");
    }


    al_set_window_title(ecran, "Projet Quoridor");
}

void al_free_all(void) {
    al_destroy_font(font);
    al_destroy_display(ecran);
    al_destroy_event_queue(queue);
    al_destroy_bitmap(image);
    al_uninstall_mouse();
    al_uninstall_keyboard();

    al_destroy_sample(sample);
    al_destroy_sample_instance(sample_instance);
    al_uninstall_audio();
}

void avatar_with_allegro(Player liste[4],int nbplayers) {
    init_background(3,ecran);
    for (int i=0;i<4;i++) {
        liste[i].avatar=0;
        if (!(nbplayers==2 && i%2==1)) {
            strcpy(liste[i].pseudo,getstr(font,liste,i,513,34+i*228));
        } else {
            strcpy(liste[i].pseudo,"NULL");
        }
    }
}

void show_player_victory(int i, Player liste[4]) {
    al_draw_text(font2,al_map_rgb_f(0.5647058823529412, 0.44313725490196076, 0.08235294117647059),640,210,ALLEGRO_ALIGN_CENTER,liste[i].pseudo);
    al_flip_display();
}

void show_victory_with_allegro(int player_i,Player liste[4]) {
    init_background(5,ecran);
    show_player_victory(player_i,liste);
    wait_for_something();
}

int al_main() {
    int tab[TAILLE][TAILLE]={{0}};
    int coord[4][2]={{0}};
    int mode[4];
    int quit=0;
    int jeu=0;
    int nbplayers=0;

    al_init_all();

    al_ouverture();


    Player liste[4];
    Score score[MAX];
    int stop=0;


    int beginner=0;
    int savePlayer_i=0;


    switch(menu_with_allegro(&quit,&jeu,&nbplayers)) {
        case 1:
            jeu =1;
            nbjoueurs_with_allegro(&jeu,&nbplayers);
            if (jeu) {
                avatar_with_allegro(liste,nbplayers);
                init(tab,liste,nbplayers);
                beginner=rand()%4;
                stop=loadScores(liste,score);
            }
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
            for (int i=0;i<4;i++) {
                if (!(nbplayers==2 && i%2==1) && jeu) {
                    //skip le tour des joueurs i = 1 et i = 3 si le nb de joueurs == 4
                    tour_with_allegro(tab,liste,i+1,&jeu,nbplayers);
                }
                beginner=0;
                savePlayer_i=i;
                if (!jeu) {
                    beginner=i;
                    break;
                }
                if ( check_win(liste,i)) {
                    countPoints(liste,i);
                    saveScores(liste,score,stop);
                    show_victory_with_allegro(i,liste);
                    return 0;
                }
            }
        }
        switch(menu_with_allegro(&quit,&jeu,&nbplayers)) {
            case 1:
            jeu=1;
            break;
            case 2:
                //loadPartie(tab,&beginner,&nbplayers,liste);
            break;
            case 3:
                quit=1;
            break;
        }
    }

    clear(40);
    if (quit==1) {
        savePartie(tab,savePlayer_i,nbplayers,liste);
    }
    al_free_all();
    printf("\nFIN\n");
    return 0;
}

