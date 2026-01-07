#include "deplacements.h"
#include "grille.h"
#include "objets.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void deplacement_Pacman(SDL_Event event){
    extern int grille[31][28];
    int posPacmanX=1;
    int posPacmanY=14;

    for(int i=0; i<31; i++){
        for(int j=0; j<28; j++){
            
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_q || SDLK_LEFT){
                    while((grille[posPacmanX-1][posPacmanY])!=0){
                        grille[posPacmanX][posPacmanY]=1;
                        posPacmanX--;
                    }
                }else if(event.key.keysym.sym == SDLK_d || SDLK_RIGHT){
                    while(grille[posPacmanX+1][posPacmanY]!=0){
                        grille[posPacmanX][posPacmanY]=1;
                        posPacmanX++;
                        }
                }else if(event.key.keysym.sym == SDLK_z || SDLK_UP){
                    while(grille[posPacmanX][posPacmanY-1]!=0){ 
                        grille[posPacmanX][posPacmanY]=1;
                        posPacmanY--;
                    }
                }else if (event.key.keysym.sym == SDLK_s || SDLK_DOWN){
                    while(grille[posPacmanX][posPacmanY+1]!=0){
                        grille[posPacmanX][posPacmanY]=1;
                        posPacmanY++;
                    }
                }
            }
        }
    }
}    