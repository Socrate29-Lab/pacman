#include "game_over.h"
#include "ecran.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "assets.h"
#include <SDL2/SDL_ttf.h>
#include "jeu.h"

int game_over_screen(int *score){
    int running = 1;
    SDL_Event event;
    int last_key = 0;
    char score_text[64];
    sprintf(score_text, "Score : %d", *score);

    //Fond de l'écran Game Over - Labyrinthe
    SDL_Rect labyrinth={0,0,728,852};
    SDL_Surface *labyrinth_surface = SDL_LoadBMP("assets/pacmap.bmp");
    if (!labyrinth_surface) printf("Erreur chargement labyrinth");
    SDL_Texture *labyrinth_texture = SDL_CreateTextureFromSurface(renderer, labyrinth_surface);
    SDL_FreeSurface(labyrinth_surface);
    if(!labyrinth_texture) printf("Erreur texture");
    
    //Rectangle d'affichage du texte
    SDL_Rect game_over = {0,0,728,852};

    //Ecriture du game over et du score
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color yellow = {255, 255, 0, 255};

    //Chargement de la police d'écriture
    TTF_Font *sixtyfour = TTF_OpenFont("assets/Sixtyfour.ttf", 48);
    if (!sixtyfour) {
    printf("Erreur TTF_OpenFont : %s\n", TTF_GetError());
    }
    
    //Creation de la surface de texte GAME OVER
    SDL_Surface *game_over_surface = TTF_RenderUTF8_Blended(sixtyfour, "GAME OVER", yellow);
    if (!game_over_surface) {
    printf("Erreur render texte : %s\n", TTF_GetError());
    }

    //Transformation en texture
    SDL_Texture *game_over_texture = SDL_CreateTextureFromSurface(renderer, game_over_surface);
    SDL_FreeSurface(game_over_surface);
    if (!game_over_texture) {
        printf("Erreur texture texte\n");
    }

    //Rectangle pour afficher le texte GAME OVER
    SDL_Rect game_over_rect;
    TTF_SizeUTF8(sixtyfour, "GAME OVER", &game_over_rect.w, &game_over_rect.h); //Calcule la taille du texte pour l'intégrer au rectangle
    game_over_rect.x = (728 - game_over_rect.w) / 2;
    game_over_rect.y = 200;

    //Meme chose pour l'affichage du score
    SDL_Surface *score_surface = TTF_RenderUTF8_Blended(sixtyfour, score_text, white);
    SDL_Texture *score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);
    SDL_FreeSurface(score_surface);

    SDL_Rect score_rect;
    TTF_SizeUTF8(sixtyfour, score_text, &score_rect.w, &score_rect.h);
    score_rect.x = (728 - score_rect.w) / 2;
    score_rect.y = game_over_rect.y + game_over_rect.h + 30;

    while(running){
        while(SDL_PollEvent(&event)){
            //Conditions de sortie de l'app
            if (event.type == SDL_QUIT) running = 0;
            if (event.type == SDL_KEYDOWN) { if(event.key.keysym.sym == SDLK_ESCAPE) running = 0; }
            //Check des boutons de direction -> les flèches ou "zqsd" correspondent à "8456" sur le pavé numérique
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP))last_key=8;
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN))last_key=5;
        }

        // Activer le blending alpha (pour l'opacité de la couleur)
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        //affiche le labyrinthe
        SDL_RenderCopy(renderer, labyrinth_texture, NULL, &labyrinth);

        // Dessiner le fondu noir semi-transparent
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
        SDL_RenderFillRect(renderer,&game_over);
        
        //Affichage du texte
        SDL_RenderCopy(renderer, game_over_texture, NULL, &game_over_rect);
        SDL_RenderCopy(renderer, score_texture, NULL, &score_rect);
        
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(game_over_texture);
}