#include "assets.h"
#include "ecran.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void print_empty(int x, int y){
    SDL_Rect tuileVide={x,y,27,27};
}

void print_candy(int x, int y){
    SDL_Rect candy={x,y,27, 27};
    SDL_Surface *candySprite=IMG_Load("candy.png");
    if(!candySprite)
        printf("Erreur chargement candy.png");
    SDL_Texture *candyTexture = SDL_CreateTextureFromSurface("Pacman", candySprite);
}