#include "assets.h"
#include "ecran.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Fonction pour rentrer des cases vides dans le labyrinthe
void print_empty(int x, int y){
    SDL_Rect tuileVide={x,y,27,27};
}

//Fonction pour afficher les bonbons sur les bonnes cases du labyrinthe
void print_candy(int x, int y, SDL_Renderer *renderer){
    SDL_Rect candy={27*x,27*y,27, 27};
    SDL_Surface *candySprite = SDL_LoadBMP("candy.bmp");
    if(!candySprite) printf("Erreur chargement candy.bmp");
    SDL_Texture *candyTexture = SDL_CreateTextureFromSurface(renderer, candySprite);
    SDL_FreeSurface(candySprite);
    if(!candyTexture) printf("Erreur texture");
    SDL_RenderCopy(renderer, candyTexture, NULL, &candy);
}

//Fonction pour afficher les pac-gum sur les bonnes cases du labyrinthe
void print_pacgum(int x, int y, SDL_Renderer* renderer){
    SDL_Rect pac_gum={27*x,27*y,27, 27};
    SDL_Surface *pac_gumSprite = SDL_LoadBMP("pac_gum.bmp");
    if(!pac_gumSprite) printf("Erreur chargement pacgum.bmp");
    SDL_Texture *pac_gumTexture = SDL_CreateTextureFromSurface(renderer, pac_gumSprite);
    SDL_FreeSurface(pac_gumSprite);
    if(!pac_gumTexture) printf("Erreur texture");
    SDL_RenderCopy(renderer, pac_gumTexture, NULL, &pac_gum);
}