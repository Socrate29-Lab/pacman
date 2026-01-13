#include "move_ghosts.h"
#include "grille.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>

void move_ghost1(int *posY, int *posX){
    //Les fantômes commencent en allant vers le haut.
    static int direction = 8;
    //Condition pour check si le fantôme est en vie.
    int alive = 1;
    //Les fantômes ne changent pas ce qu'il y a sur leur passage
    int grid_memo;
    //Pour check s'il doit changer de direction
    int blocked = 0;

    //Boucle de mouvement aléatoire
    switch (direction){
        case 8: //Deplacement vers le haut
            if(grille_deplacement[*posY - 1][*posX]!=0){
                (*posY)--;
            }else blocked = 1;
            break;
        case 4: //Deplacement vers la gauche
            //Check le tunnel
            if(grille_deplacement[*posY][*posX - 1]==10){
                (*posX)=26;
            }else{
            //déplacement normal
                if(grille_deplacement[*posY][*posX - 1]!=0){
                (*posX)--;
                }else blocked =1;
            break;
        case 5: //Deplacement vers le bas
            if(grille_deplacement[*posY + 1][*posX]!=0 && grille_deplacement[*posY + 1][*posX]!=12){
                (*posY)++;
            }else blocked = 1;
            break;
        case 6: //Deplacement vers la droite
            if(grille_deplacement[*posY][*posX + 1]==11){
                (*posX)=1;
            }else{
                if(grille_deplacement[*posY][*posX + 1]!=0){
                (*posX)++;
                }else blocked = 1;
            break;
            }
        }
        if(blocked)random_direction(&direction);
    }
    //Place ghost1 à la bonne position à la fin
    grille_deplacement[*posY][*posX]=6;
}


void random_direction(int *direct){
    int d4 = rand()%4;
    if(d4 == 0){
        *direct = 8;
    }else if(d4 == 1){
        *direct = 4;
    }else if(d4 == 2){
        *direct = 5;
    }else if(d4 == 3){
        *direct = 6;
    }
}