#include <stdio.h>
#include <time.h>
#include <string.h>

#define COTE 11
#define TAILLE (COTE+COTE-1)
#define TAILLE_PSEUDO 16
#define W_COLOR 12 //red

//#=========================================================#
#include <windows.h>
void color(int t,int f){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void clear(int n) {
    for(int i=0;i<n;i++)
        printf("\n");
}
//#=========================================================#
//PAUL

#ifdef _WIN32
#include <windows.h>
//si le programme n'est pas compilé sur windows on passe sur Unix
#else
//autorisation aux systèmes Unix d'intéragir avec le terminal
#include <sys/ioctl.h>
//fonctionnalités système Unix
#include <unistd.h>
#endif


int largeurConsole() {
    int largeur = 80; //largeur par défaut si impossible de determiner la taille
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi; //récupération largeur console spécifique à windows
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) { //information sur la console active
        largeur = csbi.srWindow.Right - csbi.srWindow.Left + 1; //calcul de la largeur de la console à partir des coordonnées du rectangle visible
    }
#else
    struct winsize w; //récupération largeur console spécifique à Unix
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) { //dimensions du terminal
        largeur = w.ws_col; //stocke la largeur du terminal
    }
#endif
    return largeur;
}

void affichageCentre(const char *text) {
    int largeur_de_la_console = largeurConsole();
    int taille_du_texte = strlen(text);
    int espacement_a_gauche = (largeur_de_la_console - taille_du_texte) / 2;

    //mettre des espaces avant le texte pour le centrer
    if (espacement_a_gauche > 0) {
        for (int i = 0; i < espacement_a_gauche; i++) {
            putchar(' '); // Ajout d'un espace pour le centrage
        }
    }
    printf("%s\n", text); // Modification : utilisation de printf sans '\n' car la nouvelle ligne sera gérée en dehors
}

int ouverture(void) {
    clear(10);
    affichageCentre("=====================================================================================================================");
    affichageCentre("BIENVENUE DANS LE JEU DU QUORRIDOR !");
    affichageCentre("=====================================================================================================================");

    getchar(); // Ajout d'une pause pour les utilisateurs Windows
    return 0;
}


//#=========================================================#
//RAPHAEL
int blind(char pseudo[TAILLE_PSEUDO]) {
    for (int i = 0; i<TAILLE_PSEUDO ; i++){
        if(pseudo[i]=='\0') {
            return 0;
        }
        if (!((47<pseudo[i] && pseudo[i]<58) || (64<pseudo[i]&&pseudo[i]<91) || (96<pseudo[i]&&pseudo[i]<123) || pseudo[i]==93 || pseudo[i]==124 || pseudo[i]==91 || pseudo[i]==45 || pseudo[i]==95 )) {
            return 1;
        }
    }
    return 0;
}


 void saisiePseudo(int n, char pseudo[TAILLE_PSEUDO]) {

     do {
         do {
             printf("Player [%d]\nEntrez votre pseudo (de 1 a 15 caracteres) : ", n);
             scanf("%s", pseudo);
             if (strlen(pseudo) > TAILLE_PSEUDO) {
                 color(4,0);
                 printf("Il faut choisir un pseudo qui respecte les regles annoncees.\n");
                 color(7,0);
             }
         } while (strlen(pseudo) > TAILLE_PSEUDO);

         fflush(stdin);
     }while(blind(pseudo));
 }


int check_win( int coo[8], int player_i){ //Fonctionne uniquement si le mouvement du joueur est blindé (par ex, joueur 2 ne peut aller en abscisse 0 et 20)
    return (coo[player_i * 2] == 0 || coo[player_i * 2] == 20 || coo[player_i * 2 +1] == 0 || coo[player_i * 2 +1] == 20);
    }

//#=========================================================#

int fct_nbjoueur (int nbjoueur) {
    clear(40);
    do {
        printf("Entrez le nombre de joueurs au total: ( 2 ou 4 )\n ==> ");
        scanf("%d", &nbjoueur);
        if (nbjoueur < 2 || nbjoueur > 4 || nbjoueur == 3) {
            clear(40);
            color(4,0);
            printf("Veuillez saisir un nombre de joueur valide.\n");
            color(7, 0);
        }
        else {
            clear(40);
            color(2,0);
            printf("Nombre de joueur valide, initialisation de la partie...\n");
            color(7, 0);
        }
    }while (nbjoueur != 4 && nbjoueur != 2);

    return nbjoueur;
}

//améliorer l'affichage dans le cas où une IA est utilisée
int fct_nbHumanjoueur (int nbplayers) {
    int nbHumanjoueur;
    do {
        clear(40);
        printf("Entrez le nombre de joueurs humains:\n==> ");
        scanf("%d", &nbHumanjoueur);
    }while (nbHumanjoueur > nbplayers || nbHumanjoueur < 1);

    return nbHumanjoueur;
}

void printPerso(int perso) {
    switch (perso) {
        case 0:
            color(8, 0);
        printf(" [_] ");
        color(7, 0);
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

void show(int tab[TAILLE][TAILLE],int mode) {
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
                    printPerso(tab[i][j]);
                }


            } else {
                printf("     ");
            }
        }
        printf("\n");
    }
    color(7,0);
}

void modif(int tab[TAILLE][TAILLE],int x,int y,int value) {
    tab[y*2][x*2]=value;
}



void placeWall(int tab[TAILLE][TAILLE],int x1,int y1,int x2,int y2) { // ATTENTION IL N'Y A PAS DE VERIF !
    tab[y1][x1]=1;
    tab[y2][x2]=1;

    if (x1==x2) { // vertical
        if (y1<y2)
            tab[y1+1][x1]=2;
        else
            tab[y2+1][x1]=2;
    } else { // horizontal
        if (x1<x2)
            tab[y1][x1+1]=1;
        else
            tab[y1][x2+1]=1;


    }
}

void deplace(int tab[TAILLE][TAILLE],int x1,int y1,int x2,int y2) {
    modif(tab,x2,y2,tab[y1*2][x1*2]);
    modif(tab,x1,y1,0);
}


void moveplayer(int tab[TAILLE][TAILLE],int coord[4][2],int player_i,int x,int y) {
    /*
    Coordonnées initialles :
    x = coord[player_i][0]   y = coord[player_i][1]
    */
    deplace(tab,coord[player_i][0],coord[player_i][1],x,y);
    coord[player_i][0]=x;
    coord[player_i][1]=y;

}

void play(int tab[TAILLE][TAILLE],int coord[4][2],int n_player,int *p_mode,int x,int y) {
    if (*p_mode) { // Deplace
        printf("deplace\n");
        moveplayer(tab,coord,n_player-1,x,y);
    } else { // place wall
        printf("placeW\n");

    }
}

void tour(int tab[TAILLE][TAILLE],int coord[4][2],int player_n,int * p_mode,char pseudo[50]) {
    int retour;
    int x,y,x1,y1;


    show(tab, *p_mode);
    printf("\n[%d] ",player_n);
    printPerso(player_n);

    printf(" %s\n",pseudo);

    if (*p_mode) {
        printf("    [Mode : Deplacement ]\n"); // 1 = deplacement, 0 = Place_wall
    } else {
        printf("    [Mode : Place a wall]\n");
    }

    printf("    [Change mode ? (0/1)]\n    ==> ");

    fflush(stdin);
    scanf("%d",&retour);

    clear(5);


    if (retour) {
        *p_mode=!(*p_mode);
    }


    show(tab,*p_mode);
    if (*p_mode) {
        printf("    [Mode : Deplacement ]\n");
    } else {
        printf("    [Mode : Place a wall ]\n");
    }

    if (*p_mode) {
        printf("    [Move to case: (x,y)]\n    ==>");
    } else {
        printf("    [Place a wall: (x,y)(x,y)]\n    ==>");
    }




    fflush(stdin);

    if (*p_mode) {
        scanf("%d%d",&x,&y);
        play(tab,coord, player_n,p_mode,x,y);
    } else {
        scanf("%d%d%d%d",&x,&y,&x1,&y1);
        placeWall(tab,x,y,x1,y1);
    }
    clear(5);
}

void initPlayer(int tab[TAILLE][TAILLE], int coord[4][2],int x,int y,int player_n) {
    modif(tab,x,y,player_n);
    coord[player_n-1][0]=x;
    coord[player_n-1][1]=y;
}

void initBoard(int tab[TAILLE][TAILLE],int coord[4][2],int nbplayers) { // initialise le plateau (4 joueurs-> a modif /nbjoueur)
    initPlayer(tab,coord,5,9,1); // J1
    initPlayer(tab,coord,5,1,3); // J3
    if (nbplayers==4) {
        initPlayer(tab,coord,1,5,2); // J2
        initPlayer(tab,coord,9,5,4); // J4
    }
}


void init(int tab[TAILLE][TAILLE],int coord[4][2],int mode[4],int nbplayers){
    initBoard(tab,coord,nbplayers);
    for(int i=0;i<4;i++) // initialise le mode de chaqun des joueurs
        if (!(nbplayers==2 && i%2==1))//skip le tour des joueurs i = 1 et i = 3 si le nb de joueurs == 4
            mode[i]=1;

}


void customizeGame(int *nbplayers, int pseudos[5][50], int nbjoueur) {

    *nbplayers = fct_nbjoueur(nbjoueur);

    for (int i = 0; i < *nbplayers; i++) {
        saisiePseudo(i + 1, pseudos[i]);
    }
    /* AFFICHER TOUS LES PSEUDOS
    for (int i = 0; i < 4; i++) {
        printf("Pseudo[%d]: %s\n", i + 1, pseudos[i]);
    }
    */
}


int main(void) {
    srand(time(NULL));
    int tab[TAILLE][TAILLE]={{0}};
    int coord[4][2]={{0}};
    int mode[4];
    int nbplayers;
    char pseudos[5][50];
    int nbjoueur;

    ouverture();

    customizeGame(&nbplayers,pseudos,nbjoueur);


    init(tab,coord,mode,nbplayers);

    int beginner=rand()%4;
    while (1) {
        for (int i=beginner;i<4;i++) {
            if (!(nbplayers==2 && i%2==1))//skip le tour des joueurs i = 1 et i = 3 si le nb de joueurs == 4
                tour(tab,coord,i+1,&mode[i],pseudos[i]);
            beginner=0;
        }
    }

    return 0;
}


// A FAIRE : modifier argument tableaux des fonction (tab)
