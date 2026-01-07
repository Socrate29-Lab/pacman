#include "deplacements.h"
#include "grille.h"
#include "objets.h"
#include <stdio.h>
#include <SDL2/SDL.h>

int deplacement_Pacman(){;
    int posPacmanX=1;
    int posPacmanY=14;
    SDL_Event event;
    grille_deplacement[31][28];
    for(int i=0; i<31; i++){
        for(int j=0; j<28; j++){
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_q || SDLK_LEFT){
                        while((grille_deplacement[posPacmanX-1][posPacmanY])!=0){
                            grille_deplacement[posPacmanX][posPacmanY]=1;
                            posPacmanX--;
                        }
                    }else if(event.key.keysym.sym == SDLK_d || SDLK_RIGHT){
                        while(grille_deplacement[posPacmanX+1][posPacmanY]!=0){
                            grille_deplacement[posPacmanX][posPacmanY]=1;
                            posPacmanX++;
                            }
                    }else if(event.key.keysym.sym == SDLK_z || SDLK_UP){
                        while(grille_deplacement[posPacmanX][posPacmanY-1]!=0){ 
                            grille_deplacement[posPacmanX][posPacmanY]=1;
                            posPacmanY--;
                        }
                    }else if (event.key.keysym.sym == SDLK_s || SDLK_DOWN){
                        while(grille_deplacement[posPacmanX][posPacmanY+1]!=0){
                            grille_deplacement[posPacmanX][posPacmanY]=1;
                            posPacmanY++;
                        }
                    }
                }
            }
        }
    }
}    