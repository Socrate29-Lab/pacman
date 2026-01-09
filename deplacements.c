#include "deplacements.h"
#include "grille.h"
#include "objets.h"
#include <stdio.h>
#include <SDL2/SDL.h>

//grille menée à être modifiée par les déplacements de pac-man et des fantômes
//grille_deplacement[31][28];

void move_Pacman(int last_key,int *posY, int *posX){;
    switch(last_key){
        case 8: //Deplacement vers le haut
            if(grille_deplacement[*posY - 1][*posX] != 0){
                grille_deplacement[*posY][*posX]=1;
                (*posY)--;
                grille_deplacement[*posY][*posX]=5;
            }
            break;
        case 4: //Deplacement vers la gauche
            if(grille_deplacement[*posY][*posX - 1] != 0){
                grille_deplacement[*posY][*posX]=1;
                (*posX)--;
                grille_deplacement[*posY][*posX]=5;
            }
            break;
        case 5: //Deplacement vers le bas
            if(grille_deplacement[*posY + 1][*posX] != 0){
                grille_deplacement[*posY][*posX]=1;
                (*posY)++;
                grille_deplacement[*posY][*posX]=5;
            }
            break;
        case 6: //Deplacement vers la droite
            if(grille_deplacement[*posY][*posX + 1] != 0){
                grille_deplacement[*posY][*posX]=1;
                (*posX)++;
                grille_deplacement[*posY][*posX]=5;
            }
            break;
        default:
            break;
    }
}