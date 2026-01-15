#include "move_pacman.h"
#include "grille.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void move_Pacman(int last_key,int *posY, int *posX, int *score, int *life){;
    switch(last_key){
        case 8: //Deplacement vers le haut
            if(grille_deplacement[*posY - 1][*posX]!=0){
                //Ramassage des bonbons normaux
                if(grille_deplacement[*posY - 1][*posX] == 2) score += 100;
                //Recontre fantôme
                if(grille_deplacement[*posY - 1][*posX] == 6 ||
                    grille_deplacement[*posY - 1][*posX] == 7 ||
                    grille_deplacement[*posY - 1][*posX] == 8) *life = 0;
                grille_deplacement[*posY][*posX]=1;
                (*posY)--;
            }
            break;
        case 4: //Deplacement vers la gauche
            //vérification d'un tunnel
            if(grille_deplacement[*posY][*posX - 1]==10){
                if(grille_deplacement[*posY][*posX - 1] == 2) *score += 100;
                //Recontre fantôme
                if(grille_deplacement[*posY][*posX - 1] == 6 ||
                    grille_deplacement[*posY][*posX - 1] == 7 ||
                    grille_deplacement[*posY][*posX - 1] == 8) *life = 0;
                grille_deplacement[*posY][*posX]=1;
                (*posX)=26;
            }else{
                //déplacement normal
                if(grille_deplacement[*posY][*posX - 1]!=0){
                if(grille_deplacement[*posY][*posX - 1] == 2) *score += 100;
                //Recontre fantôme
                if(grille_deplacement[*posY][*posX - 1] == 6 ||
                    grille_deplacement[*posY][*posX - 1] == 7 ||
                    grille_deplacement[*posY][*posX - 1] == 8) *life = 0;
                grille_deplacement[*posY][*posX]=1;
                (*posX)--;
                }
            }
            break;
        case 5: //Deplacement vers le bas
            if(grille_deplacement[*posY + 1][*posX]!=0 && grille_deplacement[*posY + 1][*posX]!=12){
                if(grille_deplacement[*posY + 1][*posX] == 2) *score += 100;
                //Recontre fantôme
                if(grille_deplacement[*posY + 1][*posX] == 6 ||
                    grille_deplacement[*posY + 1][*posX] == 7 ||
                    grille_deplacement[*posY + 1][*posX] == 8) *life = 0;
                grille_deplacement[*posY][*posX]=1;
                (*posY)++;
            }
            break;
        case 6: //Deplacement vers la droite
            //Verification d'un tunnel
            if(grille_deplacement[*posY][*posX + 1]==11){
                if(grille_deplacement[*posY][*posX + 1] == 2) *score += 100;
                //Recontre fantôme
                if(grille_deplacement[*posY][*posX + 1] == 6 ||
                    grille_deplacement[*posY][*posX + 1] == 7 ||
                    grille_deplacement[*posY][*posX + 1] == 8) *life = 0;
                grille_deplacement[*posY][*posX]=1;
                (*posX)=1;
            }else{
                if(grille_deplacement[*posY][*posX + 1]!=0){
                if(grille_deplacement[*posY][*posX + 1] == 2) *score += 100;
                //Recontre fantôme
                if(grille_deplacement[*posY][*posX + 1] == 6 ||
                    grille_deplacement[*posY][*posX + 1] == 7 ||
                    grille_deplacement[*posY][*posX + 1] == 8) *life = 0;
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