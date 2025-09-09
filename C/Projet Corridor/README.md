# Projet quoridor ing1 g12 
## /!\ Requiert la librairie Allegro5 (installation statique : C:/allegro), et le chemin vers C:/allegro/bin dans le path
## PowerPoint compte rendu mi parcours :
[Powerpoint](https://poce-my.sharepoint.com/:p:/g/personal/paul_chopin_edu_ece_fr/EbpbRAeeCaBHgNqeX35dS1YBZQGa2EvP7X1y8rxdIhKfDA?e=TJggOC)
## PowerPoint soutenance orale projet :
[PowerPoint Soutenance](https://poce-my.sharepoint.com/:p:/g/personal/paul_chopin_edu_ece_fr/EUWt3gRl-GpJjJDs8-EdX2sBiPmdYdlYXwu5wdFZBiZBww?e=f0Whfv)
## Lien Trello :
[Trello](https://trello.com/b/soYsZOCO/soutenance-orale)
## Sources :
+ Graphismes 3D : Blender 
+ Graphismes 2D : Pixelmator Pro
+ Remerciement à Enzo Valeur pour nous avoir donné des précisions sur la librairie Allegro.
+ Le forum C_Programming sur Reddit : affichage centré dans la console
+ Github ... : l'utilisation d'ALLEGRO_USTR permettant de gérer des chaînes avec Allegro ainsi que l'utilisation clavier avec Allegro.
+ La musique provient du site ... proposant des bandes sons libres de droit
+ Police utilisée dans la version Allegro : Arial Black (ariblk.ttf)

# Explicitation des fonctions :
## - a -
### [affichageCentre](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/676c93e3083e8009c948ed5c9582674c13d5a135/external_console.c#L44)
#### void affichageCentre(const char *text)
Fonction pour afficher un texte centré dans la console
#### Argument :
+ Un texte à afficher
#### Retour :
+ Ne retourne rien
### [affichageCentreTotal](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/676c93e3083e8009c948ed5c9582674c13d5a135/external_console.c#L59)
#### void affichageCentreTotal(const char *text)
Fonction pour centrer le texte verticalement et horizontalement
#### Argument : 
+ Un texte à afficher
#### Retour :
+ Ne retourne rien

## - b -
### [blindMvt](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c403a19fcb9ad673e3813d8e68c250f9d337c273/verifications.c#L102)
#### int blindMvt(int tab[TAILLE][TAILLE], int player_n, Player liste[4], int x, int y)
Sert à blinder les mouvements d'un joueur (vérifier  que les mouvements sont conformes aux règles)
#### Argument : 
+ Le plateau
+ Le nombre de joueurs
+ La liste des joueurs
+ Les coordonnées x et y 
#### Retour :
+ Le mouvement est-il valide?
### [blindPseudo](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/06da33311ec1aba451a31833e22c6bb2ad911832/dialogue.c#L9)
#### int blindPseudo(char pseudo[TAILLE_PSEUDO])
Sert a blinder le pseudo d'un joueur
#### Arguments :
+ Pseudo du joueur
#### Retour :
+ Le pseudo est il valide ?
### [blindWall](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c403a19fcb9ad673e3813d8e68c250f9d337c273/verifications.c#L131)
#### int blindWall(int tab[TAILLE][TAILLE], int x, int y, int x1, int y1)
Sert à blinder la pose d'un mur (vérifier que la pose d'un mur est conforme aux règles)
#### Argument : 
+ Le plateau
+ Les coordonnées de chaque extrémité de la barrière (x,y et x1,y1)
#### Retour :
+ Le positionnement du mûr est-il valide ?

## - c -
### [check_win](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/e7d61a99bcabc0aad19a493fbaf7e534c2b18423/verifications.c#L12)
int check_win()
### [clear](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/fea7359c24a46fbb0c64139ce199846928e164e1/affichage_console.c#L27)
#### void clear(int n)
Sert à faire du vide dans la console et ne pas avoir plusieurs tableaux de jeu qui collés au cours de la partie
#### Arguments :
+ Un entier n
#### Retour :
+ Ne renvoie rien
### [color](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/fea7359c24a46fbb0c64139ce199846928e164e1/affichage_console.c#L17C1-L17C24)
#### void color(int t,int f)
Sert à définir la couleur du texte et du fond (fait partie de la bibliothèque windows.h).
#### Arguments : 
+ Un entier t qui représente le texte
+ Un entier f qui représente le fond
#### Retour :
+ Ne renvoie rien, change juste la couleur du texte et du fond
### [customizeGame](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/fea7359c24a46fbb0c64139ce199846928e164e1/menu.c#L14)
#### void customizeGame(int *nbplayers,Player liste[4])
Permet de définir le type de partie, changer son pseudo et son avatar.
#### Arguments : 
+ Un pointeur sur l'entier nbplayers qui représente le nombre de joueurs.
+ Un tableau de taille 4 avec dedans les informations de la structure Player
#### Retour :
+ Ne renvoie rien 

## - d -
### [deplace](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/e012fefd738425f2df036a14125700e14816b93d/modifications.c#L32)
#### void deplace(int tab[TAILLE][TAILLE],int x1,int y1,int x2,int y2)
Permet aux personnages dans la partie de se déplacer sur le tableau.
#### Arguments :
+ Un tableau à deux dimentions
+ Deux entiers x1 et y1 qui représentent les coordonnées où est le personnage avant de se déplacer
+ Deux entiers x2 et y2 qui représentent les coordonnées où est le personnage après s'être déplacé
#### Retour : 
+ Ne renvoie rien

## - f -
### [fct_nbjoueur](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/e012fefd738425f2df036a14125700e14816b93d/dialogue.c#L62)
#### int fct_nbjoueur ()
Demande dans la console le nombre de joueurs dans la partie(soit 2 soit 4 joueurs).
#### Arguments :
+ Ne prend rien en paramètre
#### Retour :
+ Un entier, plus précisément le nombre de joueurs choisis pour la partie

## - i -
### [init](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/e012fefd738425f2df036a14125700e14816b93d/initialisation.c#L25)
#### void init(int tab[TAILLE][TAILLE],Player liste[4],int nbplayers)
Permet d'initialiser la partie.
#### Arguemnts :
+ Un tableau à deux dimensions
+ Un tableau de taille 4 avec dedans les informations de la structure Player
+ Un entier avec le nombre de joueurs
#### Retour :
+ Ne renvoie rien
### [initBoard](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/e012fefd738425f2df036a14125700e14816b93d/initialisation.c#L16)
#### void initBoard(int tab[TAILLE][TAILLE],Player liste[4],int nbplayers)
Permet d'initialiser le plateau de jeu.
#### Arguments :
+ Un tableau à deux dimensions
+ Un tableau de taille 4 avec dedans les informations de la structure Player
+ Un entier avec le nombre de joueurs
#### Retour :
+ Ne renvoie rien
### [initPlayer](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/e012fefd738425f2df036a14125700e14816b93d/initialisation.c#L10)
#### void initPlayer(int tab[TAILLE][TAILLE],Player liste[4],int x,int y,int player_n)
Permet d'initialiser les joueurs.
#### Arguments 
+ Un tableau à deux dimensions
+ Un tableau de taille 4 avec dedans les informations de la structure Player
+ Deux entiers x et y qui représentent les coordonnées du joueur
+ Un entier qui représente le numéro du joueur
#### Retour :
+ Ne renvoie rien

## - l -
### [loadPartie](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c83bd232407beca135b99617a334deaec0e76e97/stockage.c#L34)
#### void loadPartie(int tab[TAILLE][TAILLE],int * beginner,int * nbplayers,Player liste[4]
Permet de charger une partie dans la console.
#### Arguments :
+ Un tableau à deux dimensions
+ Un pointeur sur l'entier beginner
+ Un pointeur sur l'entier nbplayers
+ Un tableau de taille 4 avec dedans les informations de la structure Player
#### Retour :
+ Ne renvoie rien
### [loadScores](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/f3b70c98969f5de002088db0ff28b4567ae2141b/stockage.c#L90)
#### int loadScores(Player liste[4], Score save[MAX])
Permet de charger les scores d'un joueur déjà connu
#### Arguments :
+ La liste des joueurs
+ Le tableau des scores à remplir avec l'extraction du fichier de sauvegarde
#### Retour :
+ L'indice d'écriture au sein de la structure (équivalent à la taille de la structure)

## - m -
### [main](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c83bd232407beca135b99617a334deaec0e76e97/main.c#L9)
#### int main()
Permet de regrouper toutes les autres fonctions, c'est le programme principal du projet.
#### Arguments :
+ Ne prend rien en paramètre
#### Retour :
+ Renvoie un code, un 0 si le programme se lance bien ou un -1 si il y a un problème
### [menu](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c83bd232407beca135b99617a334deaec0e76e97/menu.c#L45)
#### int menu()
Permet d'afficher un menu dans la console avec plusieurs choix possibles, celui de jouer, de charger une sauvegarde, de quitter le jeu et d'aller dans les paramètres du jeu.
#### Arguments :
+ Ne prend rien en paramètre
#### Retour :
+ Renvoie la suite du programme en fonctiond du choix qui à été fait
### [modif](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c83bd232407beca135b99617a334deaec0e76e97/modifications.c#L8)
#### void modif(int tab[TAILLE][TAILLE],int x,int y,int value)
Permet de modifier les coordonnées d'une case.
#### Arguments :
+ Un tableau à deux dimensions
+ Deux entiers x et y qui représentent des coordonnées
+ Un entier qui représente la valeur de la modification des coordonnées
#### Retour :
+ Ne renvoie rien

## - o -
### [ouverture](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/e71037de5e76b385a57869a488cbc7060dabb92d/external_console.c#L76)
#### int ouverture(void)
Affiche l'écran d'ouverture du jeu
#### Argument :
+ Aucun argument
#### Retour : 
+ Ne retourne rien

## - p -
### [placeWall](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c83bd232407beca135b99617a334deaec0e76e97/modifications.c#L13)
#### void placeWall(int tab[TAILLE][TAILLE],int x1,int y1,int x2,int y2)
Permet de placer un mur sur deux cases adjacentes sur la plateau dans la console.
#### Arguments :
+ Un tableau à deux dimentions
+ Deux entiers x1 et y1 qui représentent les coordonnées du mur placé sur la première case
+ Deux entiers x2 et y2 qui représentent les coordonnées du mur placé sur la deuxième case
#### Retour :
+ Ne renvoie rien
### [play](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/c83bd232407beca135b99617a334deaec0e76e97/modifications.c#L37)
#### void play(int tab[TAILLE][TAILLE],int player_n, Player liste[4],int x,int y)
Permet de jouer un coup.
#### Arguments :
+ Un tableau à deux dimentions
+ Un entier qui représente le numéro du joueur
+ Un tableau de taille 4 avec dedans les informations de la structure Player
+ Deux entier qui représentent les coordonnées de la prochaine case du personnage dans la console
#### Retour : 
+ Ne renvoie rien
### [printPerso](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/f99ddc01b8807ecdb750c43767b0fb49a0ea8ee3/affichage_console.c#L34)
#### void printPerso(int perso, Player liste[4])
Permet d'afficher un personnage sur le plateau dans la console.
#### Arguments :
+ Un entier qui représente une case lorsqu'il est égal à 0 et un personnage lorsqu'il est supérieur à 0
+ Un tableau de taille 4 avec dedans les informations de la structure Player
#### Retour : 
+ Ne renvoie rien

## - s -
### [saisiePseudo](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/2121be725c34cb021a4d41dacb951f60f806d536/dialogue.c#L22)
#### void saisiePseudo(int n, char pseudo[TAILLE_PSEUDO+1],int nbjoueurs)
Permet de saisir un pseudo.
#### Arguments :
+ Un entier n
+ Un tableau avec le pseudo du personnage avec une taille maximale
+ Un entier du nombre des joueurs
#### Retour : 
+ Ne renvoie rien
### [savePartie](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/a2aa51f367778ad9458fe30f06c37b114af8c31b/stockage.c#L13)
#### void savePartie(int tab[TAILLE][TAILLE],int savePlayer_i,int nbplayers,Player liste[4])
Permet de sauvgarder une partie.
#### Arguments :
+ Un tableau à deux dimentions
+ Un entier qui va permettre de sauvgarder les numéros de joueur
+ Un entier du nombre des joueurs
+ Un tableau de taille 4 avec dedans les informations de la structure Player
#### Retour : 
+ Ne renvoie rien
### [saveScores](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/a2aa51f367778ad9458fe30f06c37b114af8c31b/stockage.c#L65)
#### void saveScores(Player liste[4], Score save[MAX],int stop)
Permet de sauvgarder les scores.
#### Arguments :
+ Un tableau de taille 4 avec dedans les informations de la structure Player
+ Un tableau de taille 100 avec dedans les informations de la structure Score
+ Un entier stop
#### Retour : 
+ Ne renvoie rien
### [show](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/f3b70c98969f5de002088db0ff28b4567ae2141b/affichage_console.c#L109)
#### void show(int tab[TAILLE][TAILLE],int mode,Player liste[4])
Permet d'afficher le tableau dans la console.
#### Arguments :
+ Un tableau à deux dimentions
+ Un entier qui permet de choisir le mode (barrière ou déplacement)
+ Un tableau de taille 4 avec dedans les informations de la structure Player
#### Retour : 
+ Ne renvoie rien

## - t -
### [tour](https://github.com/ING1-Paris/projet-quoridor-2024-ing1-quoridor-2024-12-5/blob/f3bdb3aac2263697cec26cc47af7609d38b4461c/tour.c#L11)
#### void tour(int tab[TAILLE][TAILLE],int player_n,Player liste[4],int * jeu)
Permet au joueur de jouer un tour
#### Arguments :
+ Un tableau à deux dimentions
+ Un entier du numéro du joueur
+ Un tableau de taille 4 avec dedans les informations de la structure Player
+ Un pointeur sur l'entier jeu
#### Retour : 
+ Ne renvoie rien



























































































































































































































































































































































