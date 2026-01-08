#include "assets.h"
#include "ecran.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Fonction pour rentrer des cases vides dans le labyrinthe
void print_empty(int x, int y){
    SDL_Rect tuileVide={x,y,27,27};
}

//Fonction pour afficher les bonbons
void print_candy(int x, int y, SDL_Renderer *renderer){
    SDL_Rect candy={26*x,27.8*y,26.5, 26.5};
    SDL_Surface *candySprite = SDL_LoadBMP("assets/candy.bmp");
    if(!candySprite) printf("Erreur chargement candy.bmp");
    SDL_Texture *candyTexture = SDL_CreateTextureFromSurface(renderer, candySprite);
    SDL_FreeSurface(candySprite);
    if(!candyTexture) printf("Erreur texture");
    SDL_RenderCopy(renderer, candyTexture, NULL, &candy);
}

//Fonction pour afficher les pac-gum
void print_pacgum(int x, int y, SDL_Renderer* renderer){
    SDL_Rect pac_gum={26*x,28*y,26.5, 26.5};
    SDL_Surface *pac_gumSprite = SDL_LoadBMP("assets/pac_gum.bmp");
    if(!pac_gumSprite) printf("Erreur chargement pacgum.bmp");
    SDL_Texture *pac_gumTexture = SDL_CreateTextureFromSurface(renderer, pac_gumSprite);
    SDL_FreeSurface(pac_gumSprite);
    if(!pac_gumTexture) printf("Erreur texture");
    SDL_RenderCopy(renderer, pac_gumTexture, NULL, &pac_gum);
}

//Fonction pour afficher Pac-man
void print_pacman(int x, int y, SDL_Renderer* renderer){
    SDL_Rect pacman={26*x,28*y,26.5, 26.5};
    SDL_Surface *pacmanSprite = SDL_LoadBMP("assets/pacman.bmp");
    if(!pacmanSprite) printf("Erreur chargement pacman.bmp");
    SDL_Texture *pacmanTexture = SDL_CreateTextureFromSurface(renderer, pacmanSprite);
    SDL_FreeSurface(pacmanSprite);
    if(!pacmanTexture) printf("Erreur texture");
    SDL_RenderCopy(renderer, pacmanTexture, NULL, &pacman);
}

//Fonction pour afficher le fantôme vert
void print_ghost1(int x, int y, SDL_Renderer* renderer){
    SDL_Rect ghost1={26*x,28*y,26.5, 26.5};
    SDL_Surface *ghost1Sprite = SDL_LoadBMP("assets/ghost1.bmp");
    if(!ghost1Sprite) printf("Erreur chargement ghost1.bmp");
    SDL_Texture *ghost1Texture = SDL_CreateTextureFromSurface(renderer, ghost1Sprite);
    SDL_FreeSurface(ghost1Sprite);
    if(!ghost1Texture) printf("Erreur texture");
    SDL_RenderCopy(renderer, ghost1Texture, NULL, &ghost1);
}

//Fonction pour afficher le fantôme bleu
void print_ghost2(int x, int y, SDL_Renderer* renderer){
    SDL_Rect ghost2={26*x,28*y,26.5, 26.5};
    SDL_Surface *ghost2Sprite = SDL_LoadBMP("assets/ghost2.bmp");
    if(!ghost2Sprite) printf("Erreur chargement ghost2.bmp");
    SDL_Texture *ghost2Texture = SDL_CreateTextureFromSurface(renderer, ghost2Sprite);
    SDL_FreeSurface(ghost2Sprite);
    if(!ghost2Texture) printf("Erreur texture");
    SDL_RenderCopy(renderer, ghost2Texture, NULL, &ghost2);
}

//Fonction pour afficher le fantôme rose
void print_ghost3(int x, int y, SDL_Renderer* renderer){
    SDL_Rect ghost3={26*x,28*y,26.5, 26.5};
    SDL_Surface *ghost3Sprite = SDL_LoadBMP("assets/ghost3.bmp");
    if(!ghost3Sprite) printf("Erreur chargement ghost3.bmp");
    SDL_Texture *ghost3Texture = SDL_CreateTextureFromSurface(renderer, ghost3Sprite);
    SDL_FreeSurface(ghost3Sprite);
    if(!ghost3Texture) printf("Erreur texture");
    SDL_RenderCopy(renderer, ghost3Texture, NULL, &ghost3);
}