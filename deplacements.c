#include "deplacements.h"
#include "grille.h"
#include "objets.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void move_Pacman(int last_key,int *posY, int *posX){;
    switch(last_key){
        case 8: //Deplacement vers le haut
            if(grille_deplacement[*posY - 1][*posX]!=0 && grille_deplacement[*posY - 1][*posX]!=12){
                grille_deplacement[*posY][*posX]=1;
                (*posY)--;
            }
            break;
        case 4: //Deplacement vers la gauche
            //vérification d'un tunnel
            if(grille_deplacement[*posY][*posX - 1]==10){
                    grille_deplacement[*posY][*posX]=1;
                    (*posX) +=27;
            }else{
                //déplacement normal
                if(grille_deplacement[*posY][*posX - 1]!=0 && grille_deplacement[*posY][*posX - 1]!=12){
                grille_deplacement[*posY][*posX]=1;
                (*posX)--;
                }
            }
            break;
        case 5: //Deplacement vers le bas
            if(grille_deplacement[*posY + 1][*posX]!=0 && grille_deplacement[*posY + 1][*posX]!=12){
                grille_deplacement[*posY][*posX]=1;
                (*posY)++;
            }
            break;
        case 6: //Deplacement vers la droite
            if(grille_deplacement[*posY][*posX + 1]==11){
                    grille_deplacement[*posY][*posX]=1;
                    (*posX) -= 27;
            }else{
                if(grille_deplacement[*posY][*posX + 1]!=0 && grille_deplacement[*posY][*posX + 1]!=12){
                grille_deplacement[*posY][*posX]=1;
                (*posX)++;
                }
            }
            break;
        default:
            break;
    }
    //Place Pacman à la bonne position à la fin
    grille_deplacement[*posY][*posX]=5;
}