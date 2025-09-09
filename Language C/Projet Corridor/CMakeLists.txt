cmake_minimum_required(VERSION 3.29)
project(projet_quoridor_2024_ing1_quoridor_2024_12_5 C)

set(CMAKE_C_STANDARD 11)

#chemins vers les dossiers include et lib d'Allegro
include_directories("C:/allegro/include")
link_directories("C:/allegro/lib")

add_executable(projet_quoridor_2024_ing1_quoridor_2024_12_5
    main.c
        affichage_console.c
        affichage_console.h
        dialogue.c
        dialogue.h
        initialisation.c
        initialisation.h
        modifications.c
        modifications.h
        macros.h
        tout.h
        verifications.c
        verifications.h
        menu.c
        menu.h
        tour.c
        tour.h
        structures.h
        stockage.c
        stockage.h
        external_console.c
        external_console.h
        ALLEGRO/main.c
        ALLEGRO/main.h
        ALLEGRO/al_pack.h
        ALLEGRO/background.c
        ALLEGRO/background.h
        ALLEGRO/getBlindedStr.c
        ALLEGRO/getBlindedStr.h)



target_link_libraries(projet_quoridor_2024_ing1_quoridor_2024_12_5 -lmingw32 -LC:/allegro/allegro-monolith-debug)

# Lier les bibliothèques Allegro
target_link_libraries(projet_quoridor_2024_ing1_quoridor_2024_12_5 allegro allegro_dialog allegro_image allegro_font allegro_ttf allegro_audio allegro_acodec allegro_main)

# POUR NE PAS OUVRIR DE TERMINAL :
set(CMAKE_EXE_LINKER_FLAGS "-mwindows")