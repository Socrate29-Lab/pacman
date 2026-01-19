#include "move_ghosts.h"
#include "grille.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>

void move_ghost1(int *posY, int *posX, int *pac_life, int *statut){
    //Données de départ pour le déplacement (statics pour les int qu'on a besoin de garder modifiés à chaque boucle)
    static int direction = 8;
    static int grid_memo = 1;  
    int blocked = 0;

    switch (direction){
        case 8: //Deplacement vers le haut
            if(grille_deplacement[*posY - 1][*posX] != 0){
                //Vérifie une rencontre avec Pac-Man et son statut
                if(*statut == 0 && grille_deplacement[*posY - 1][*posX] == 5) *pac_life = 0;
                //Récupère la case actuelle en mémoire
                grille_deplacement[*posY][*posX] = grid_memo;
                //Ne prend pas les autres fantomes en mémoire pour ne pas en placer une copie sur la map
                if(grille_deplacement[*posY - 1][*posX] != 7 && grille_deplacement[*posY - 1][*posX] != 8){
                grid_memo = grille_deplacement[*posY - 1][*posX];
                }
                //Deplacement
                (*posY)--;
                //Vérifie si le fantome bloque contre un mur pour activer l'aléatoire
            } else blocked = 1;
            break;

        case 4: //Deplacement vers la gauche
            //Vérifie si tunnel
            if(grille_deplacement[*posY][*posX - 1] == 10){
                //Vérifie une rencontre avec Pac-Man et son statut
                if(*statut == 0 && grille_deplacement[*posY][*posX - 1] == 5) *pac_life = 0;
                //Récupère la case actuelle en mémoire
                grille_deplacement[*posY][*posX] = grid_memo;
                //Ne prend pas les autres fantômes en mémoire pour ne pas en placer une copie sur la map
                if(grille_deplacement[*posY][*posX - 1] != 7 && grille_deplacement[*posY][*posX - 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX - 1];
                }
                //Deplacement
                (*posX) = 26;
            //Deplacement classique
            } else if(grille_deplacement[*posY][*posX - 1] != 0){
                if(*statut == 0 && grille_deplacement[*posY][*posX - 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX - 1] != 7 && grille_deplacement[*posY][*posX - 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX - 1];
                }
                (*posX)--;
            } else blocked = 1;
            break;

        case 5: //Deplacement vers le bas
            if(grille_deplacement[*posY + 1][*posX] != 0 &&
               grille_deplacement[*posY + 1][*posX] != 12){
                if(*statut == 0 && grille_deplacement[*posY + 1][*posX] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY + 1][*posX] != 7 && grille_deplacement[*posY + 1][*posX] != 8){
                grid_memo = grille_deplacement[*posY + 1][*posX];
                }
                (*posY)++;
            } else blocked = 1;
            break;

        case 6: //Deplacement vers la droite
            //Verifie si tunnel
            if(grille_deplacement[*posY][*posX + 1] == 11){
                if(*statut == 0 && grille_deplacement[*posY][*posX + 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX + 1] != 7 && grille_deplacement[*posY][*posX + 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX + 1];
                }
                (*posX) = 1;
            //Deplacement classique
            } else if(grille_deplacement[*posY][*posX + 1] != 0){
                if(*statut == 0 && grille_deplacement[*posY][*posX + 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX + 1] != 7 && grille_deplacement[*posY][*posX + 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX + 1];
                }
                (*posX)++;
            } else blocked = 1;
            break;
    }
    //Si détecte le blocage du fantome, lance la fonction aléatoire pour définir nouvelle direction
    if(blocked){
        random_direction(&direction);
        blocked = 0;
    }
    //Affiche le fantome sur la case actuelle
    grille_deplacement[*posY][*posX] = 6;
}

void move_ghost2(int *posY, int *posX, int *pac_life, int *statut){
    //Données de départ pour le déplacement (statics pour les int qu'on a besoin de garder modifiés à chaque boucle)
    static int direction = 8;
    static int grid_memo = 1;  
    int blocked = 0;

    switch (direction){
        case 8: //Deplacement vers le haut
            if(grille_deplacement[*posY - 1][*posX] != 0){
                if(*statut == 0 && grille_deplacement[*posY - 1][*posX] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY - 1][*posX] != 6 && grille_deplacement[*posY - 1][*posX] != 8){
                grid_memo = grille_deplacement[*posY - 1][*posX];
                }
                (*posY)--;
            } else blocked = 1;
            break;

        case 4: //Deplacement vers la gauche
            //Vérifie si tunnel
            if(grille_deplacement[*posY][*posX - 1] == 10){
                if(*statut == 0 && grille_deplacement[*posY][*posX - 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX - 1] != 6 && grille_deplacement[*posY][*posX - 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX - 1];
                }
                (*posX) = 26;
            //Deplacement classique
            } else if(grille_deplacement[*posY][*posX - 1] != 0){
                if(*statut == 0 && grille_deplacement[*posY][*posX - 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX - 1] != 6 && grille_deplacement[*posY][*posX - 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX - 1];
                }
                (*posX)--;
            } else blocked = 1;
            break;

        case 5: //Deplacement vers le bas
            if(grille_deplacement[*posY + 1][*posX] != 0 &&
               grille_deplacement[*posY + 1][*posX] != 12){
                if(*statut == 0 && grille_deplacement[*posY + 1][*posX] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY + 1][*posX] != 6 && grille_deplacement[*posY + 1][*posX] != 8){
                grid_memo = grille_deplacement[*posY + 1][*posX];
                }
                (*posY)++;
            } else blocked = 1;
            break;

        case 6: //Deplacement vers la droite
            //Verifie si tunnel
            if(grille_deplacement[*posY][*posX + 1] == 11){
                if(*statut == 0 && grille_deplacement[*posY][*posX + 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX + 1] != 6 && grille_deplacement[*posY][*posX + 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX + 1];
                }
                (*posX) = 1;
            //Deplacement classique
            } else if(grille_deplacement[*posY][*posX + 1] != 0){
                if(*statut == 0 && grille_deplacement[*posY][*posX + 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX + 1] != 6 && grille_deplacement[*posY][*posX + 1] != 8){
                grid_memo = grille_deplacement[*posY][*posX + 1];
                }
                (*posX)++;
            } else blocked = 1;
            break;
    }

    if(blocked){
        random_direction(&direction);
        blocked = 0;
    }
    grille_deplacement[*posY][*posX] = 7;
}

void move_ghost3(int *posY, int *posX, int *pac_life, int *statut){
    //Données de départ pour le déplacement (statics pour les int qu'on a besoin de garder modifiés à chaque boucle)
    static int direction = 8;
    static int grid_memo = 1;  
    int blocked = 0;

    switch (direction){
        case 8: //Deplacement vers le haut
            if(grille_deplacement[*posY - 1][*posX] != 0){
                if(*statut == 0 && grille_deplacement[*posY - 1][*posX] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY - 1][*posX] != 6 && grille_deplacement[*posY - 1][*posX] != 7){
                grid_memo = grille_deplacement[*posY - 1][*posX];
                }
                (*posY)--;
            } else blocked = 1;
            break;

        case 4: //Deplacement vers la gauche
            //Vérifie si tunnel
            if(grille_deplacement[*posY][*posX - 1] == 10){
                if(*statut == 0 && grille_deplacement[*posY][*posX - 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX - 1] != 6 && grille_deplacement[*posY][*posX - 1] != 7){
                grid_memo = grille_deplacement[*posY][*posX - 1];
                }
                (*posX) = 26;
            //Deplacement classique
            } else if(grille_deplacement[*posY][*posX - 1] != 0){
                if(*statut == 0 && grille_deplacement[*posY][*posX - 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX - 1] != 6 && grille_deplacement[*posY][*posX - 1] != 7){
                grid_memo = grille_deplacement[*posY][*posX - 1];
                }
                (*posX)--;
            } else blocked = 1;
            break;

        case 5: //Deplacement vers le bas
            if(grille_deplacement[*posY + 1][*posX] != 0 &&
               grille_deplacement[*posY + 1][*posX] != 12){
                if(*statut == 0 && grille_deplacement[*posY + 1][*posX] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY + 1][*posX] != 6 && grille_deplacement[*posY + 1][*posX] != 7){
                grid_memo = grille_deplacement[*posY + 1][*posX];
                }
                (*posY)++;
            } else blocked = 1;
            break;

        case 6: //Deplacement vers la droite
            //Verifie si tunnel
            if(grille_deplacement[*posY][*posX + 1] == 11){
                if(*statut == 0 && grille_deplacement[*posY][*posX + 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX + 1] != 6 && grille_deplacement[*posY][*posX + 1] != 7){
                grid_memo = grille_deplacement[*posY][*posX + 1];
                }
                (*posX) = 1;
            //Deplacement classique
            } else if(grille_deplacement[*posY][*posX + 1] != 0){
                if(*statut == 0 && grille_deplacement[*posY][*posX + 1] == 5) *pac_life = 0;
                grille_deplacement[*posY][*posX] = grid_memo;
                if(grille_deplacement[*posY][*posX + 1] != 6 && grille_deplacement[*posY][*posX + 1] != 7){
                grid_memo = grille_deplacement[*posY][*posX + 1];
                }
                (*posX)++;
            } else blocked = 1;
            break;
    }

    if(blocked){
        random_direction(&direction);
        blocked = 0;
    }
    grille_deplacement[*posY][*posX] = 8;
}

void random_direction(int *direct){
    int d4 = rand()%4;
    switch(d4){
        case 0: *direct = 8; break;
        case 1: *direct = 4; break;
        case 2: *direct = 5; break;
        case 3: *direct = 6; break;
    }
}