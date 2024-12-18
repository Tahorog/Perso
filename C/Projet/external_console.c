//
// Created by Picard on 20/11/2024.
//

#include "external_console.h"



// Fonction pour récupérer la largeur de la console
int largeurConsole() {
    int largeur = 80; // Largeur par défaut si impossible de déterminer la taille
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Récupération largeur console spécifique à Windows
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        largeur = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Calcul de la largeur de la console
    }
#else
    struct winsize w; // Récupération largeur console spécifique à Unix
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        largeur = w.ws_col; // Stocke la largeur du terminal
    }
#endif
    return largeur;
}

// Fonction pour récupérer la hauteur de la console
int hauteurConsole() {
    int hauteur = 25; // Hauteur par défaut si impossible de déterminer la taille
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Récupération hauteur console spécifique à Windows
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        hauteur = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Calcul de la hauteur de la console
    }
#else
    struct winsize w; // Récupération hauteur console spécifique à Unix
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        hauteur = w.ws_row; // Stocke la hauteur du terminal
    }
#endif
    return hauteur;
}

// Fonction pour afficher un texte centré dans la console
void affichageCentre(const char *text) {
    int largeur_de_la_console = largeurConsole();
    int taille_du_texte = strlen(text);
    int espacement_a_gauche = (largeur_de_la_console - taille_du_texte) / 2;

    // Mettre des espaces avant le texte pour le centrer
    if (espacement_a_gauche > 0) {
        for (int i = 0; i < espacement_a_gauche; i++) {
            putchar(' '); // Ajout d'un espace pour le centrage
        }
    }
    printf("%s\n", text);
}

// Fonction pour centrer le texte verticalement et horizontalement
void affichageCentreTotal(const char *text) {
    int hauteur_de_la_console = hauteurConsole();
    int taille_du_texte = 1; // Le texte occupe au moins une ligne

    // Calculer l'espace nécessaire pour centrer verticalement
    int espacement_haut = (hauteur_de_la_console - taille_du_texte) / 2;

    // Ajouter des sauts de ligne pour centrer verticalement
    for (int i = 0; i < espacement_haut; i++) {
        printf("\n");
    }

    // Centrer horizontalement le texte
    affichageCentre(text);
}

// Fonction d'ouverture du jeu avec le titre et le menu centré
int ouverture(void) {
    affichageCentre("Veuillez mettre le jeu en plein ecran pour une experience optimale.");

    getchar();
    clear(30);  // Nettoyage de l'écran avec votre fonction existante

    int largeur_de_la_console = largeurConsole();
    for (int i = 0; i < largeur_de_la_console; i++) {
        putchar('=');  // Affichage de la ligne décorative
    }
    printf("\n");

    affichageCentre(" *******                           **               **        ****     ****     ****       ** ");
    affichageCentre(" **    **                                           **       *    *   *   **   *    *     * * ");
    affichageCentre(" **    **   ******    ******       **    *****    ******          *   *  * *        *    *  * ");
    affichageCentre(" *******     **  *   **    **      **   **   **     **         ***    * *  *     ***    ******");
    affichageCentre(" **          **      **    **      **   *******     **        *       **   *    *           * ");
    affichageCentre(" **          **      **    **   ** **   **          **       *        *    *   *            * ");
    affichageCentre(" **         ***       ******     ***     ******      **      ******    ****    ******       * ");
    affichageCentre("                                                                                              ");

    // Affichage de la ligne décorative avant le texte centré

    clear(2);

    // Centrer le message "Bienvenue" sans affecter la ligne décorative
    affichageCentre("   *******     **      **    *******    *******    **  *******      *******    *******  ");
    affichageCentre("  **     **    **      **   **     **   **    **   **  **    **    **     **   **    ** ");
    affichageCentre(" **       **   **      **  **       **  **    **   **  **     **  **       **  **    ** ");
    affichageCentre(" **       **   **      **  **       **  *******    **  **     **  **       **  *******  ");
    affichageCentre(" **    ** **   **      **  **       **  **   **    **  **     **  **       **  **   **  ");
    affichageCentre("  **     **    **      **   **     **   **    **   **  **    **    **     **   **    ** ");
    affichageCentre("   ******* **   *******      *******    **     **  **  *******      *******    **     **");
    affichageCentre("                                                                                        ");


    clear(2);


    affichageCentre("   _______     ________    _______    _______      _______    ");
    affichageCentre(",'_____ ,'|  /______ /|  /_______\\  |\\ ______\\   |`. _____`.");
    affichageCentre("|       |  | |       | |  |       |  | |       |  |  |       |");
    affichageCentre("|> ^.^ <|  | |  0_0\" | |  |o ^_^ o|  | | \">_<\" |  |  |~ ^u^ ~|");
    affichageCentre("|       |  | |       | |  |       |  | |       |  |  |       |");
    affichageCentre("|_______|,'  |_______|/   |_______|  \\ |_______|   `.|_______|");

    // Affichage de la ligne décorative après le texte centré
    for (int i = 0; i < largeur_de_la_console; i++) {
        putchar('=');  // Affichage de la ligne décorative
    }
    printf("\n");

    getchar(); // Ajout d'une pause pour les utilisateurs Windows
}
