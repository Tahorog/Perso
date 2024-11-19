//permet l'utilisation de certaines fonctions déjà définies sur windows comme GetConsolScreenBufferInfo
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
            putchar(' ');
        }
    }
    printf("%s\n", text);
}

int main() {
    printf("\n\n\n\n\n\n\n\n\n\n");
    affichageCentre("========================================================================================================================");
    affichageCentre("BIENVENUE DANS LE JEU DU QUORRIDOR");
    affichageCentre("========================================================================================================================");
    system("pause");
    return 0;
}
