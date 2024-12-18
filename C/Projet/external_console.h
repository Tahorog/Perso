//
// Created by Picard on 20/11/2024.
//

#include "affichage_console.h"

#ifdef _WIN32
#else
#include <sys/ioctl.h>  // Si le programme est compilé sous Unix
#include <unistd.h>      // Si le programme est compilé sous Unix
#endif


#ifndef EXTERNAL_CONSOLE_H
#define EXTERNAL_CONSOLE_H

void affichageCentre(const char *text);
void affichageCentreTotal(const char *text);
int ouverture(void);

#endif //EXTERNAL_CONSOLE_H
