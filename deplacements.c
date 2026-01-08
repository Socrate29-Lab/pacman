#include "deplacements.h"
#include "grille.h"
#include "objets.h"
#include <stdio.h>
#include <SDL2/SDL.h>

//grille menée à être modifiée par les déplacements de pac-man et des fantômes
//grille_deplacement[31][28];

void move_Pacman(int last_key){;
    //Données nécessaires au déplacement
    int posPacmanY=14;
    int posPacmanX=1;
    //boucle pour check
    for(int i=0; i<31; i++){
        for(int j=0; j<28; j++){
            switch(last_key){
                case 8: //Deplacement vers le haut
                    if((grille_deplacement[posPacmanY]-1)!=0){
                        grille_deplacement[posPacmanY][posPacmanX]=1;
                        posPacmanY--;
                        grille_deplacement[posPacmanY][posPacmanX]=5;
                        printf("haut");
                    }
                    break;
                case 4: //Deplacement vers la gauche
                    if((grille_deplacement[posPacmanX]-1)!=0){
                        grille_deplacement[posPacmanY][posPacmanX]=1;
                        posPacmanX--;
                        grille_deplacement[posPacmanY][posPacmanX]=5;
                        printf("gauche");
                    }
                    break;
                case 5: //Deplacement vers le bas
                    if((grille_deplacement[posPacmanY]+1)!=0){
                        grille_deplacement[posPacmanY][posPacmanX]=1;
                        posPacmanY++;
                        grille_deplacement[posPacmanY][posPacmanX]=5;
                        printf("bas");
                    }
                    break;
                case 6: //Deplacement vers la droite
                    if((grille_deplacement[posPacmanX]+1)!=0){
                        grille_deplacement[posPacmanY][posPacmanX]=1;
                        posPacmanX++;
                        grille_deplacement[posPacmanY][posPacmanX]=5;
                        printf("droite");
                    }
                    break;
            }
        }
    }
}