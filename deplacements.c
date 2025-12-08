#include "deplacements.h"
#include "grille.h"
#include "objets.h"
#include <stdio.h>
#include <SDL2/SDL.h>



void deplacement_Pacman(SDL_Event event){
    //initialisation des touches de deplacement
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_q || SDLK_LEFT){
            if(playerX-50>0) playerX = playerX-50;
        }else if(event.key.keysym.sym == SDLK_d || SDLK_RIGHT){
            if(playerX+50<1920) playerX = playerX+50;
        }else if(event.key.keysym.sym == SDLK_z || SDLK_UP){
            if(playerY-50>0) playerY = playerY -50;
        }else if (event.key.keysym.sym == SDLK_s || SDLK_DOWN){
            if(playerY-50<1080)playerY = playerY +50;
        }
    }
}