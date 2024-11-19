#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

// Fonction pour obtenir la largeur de la console
int getConsoleWidth() {
    int width = 80; // Valeur par défaut si la taille ne peut pas être récupérée
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
#else
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        width = w.ws_col;
    }
#endif
    return width;
}

void printCentered(const char *text) {
    int consoleWidth = getConsoleWidth();
    int textLength = strlen(text);
    int padding = (consoleWidth - textLength) / 2;

    // Imprimer les espaces avant le texte pour le centrer
    if (padding > 0) {
        for (int i = 0; i < padding; i++) {
            putchar(' ');
        }
    }
    printf("%s\n", text);
}
