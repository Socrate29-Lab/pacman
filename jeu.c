#include <stdio.h>
#include "jeu.h"
#include "ecran.h"
#include "map.h"


//Initialisation du jeu
void jouer(){
    int running = 1;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                running = 0;
            if (event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE)
                running = 0;
            }
        }
        //Affichage du labyrinthe en labyrinth
        SDL_Rect labyrinth={0,0,728,852};
        SDL_Surface *labyrinth_surface = SDL_LoadBMP("pacmap.bmp");
        if (!labyrinth_surface) printf("Erreur chargement labyrinth");
        SDL_Texture *labyrinth_texture = SDL_CreateTextureFromSurface(renderer, labyrinth_surface);
        SDL_FreeSurface(labyrinth_surface);
        if(!labyrinth_texture) printf("Erreur texture");
        SDL_RenderCopy(renderer, labyrinth_texture, NULL, &labyrinth);

        //Affichage des objets sur la map
        generate_map();
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }
}