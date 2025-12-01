#include "deplacements.h"
#include "grille.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include "perso.h"

void deplacements(){
    //initialisation des touches de deplacement
    SDL_Event event;
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