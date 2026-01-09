#include <stdio.h>
#include "jeu.h"
#include "ecran.h"
#include "map.h"
#include "deplacements.h"
#include "grille.h"


//Initialisation du jeu
void jouer(){
    //Données pour permettre au programme de savoir quelle étape il doit faire
    int running = 1;
    SDL_Event event;
    int map_init=0;
    int last_key=0;
    //Données nécessaires au déplacement
    int posPacmanY=14;
    int posPacmanX=1;

    //Affichage du labyrinthe
    SDL_Rect labyrinth={0,0,728,852};
    SDL_Surface *labyrinth_surface = SDL_LoadBMP("assets/pacmap.bmp");
    if (!labyrinth_surface) printf("Erreur chargement labyrinth");
    SDL_Texture *labyrinth_texture = SDL_CreateTextureFromSurface(renderer, labyrinth_surface);
    SDL_FreeSurface(labyrinth_surface);
    if(!labyrinth_texture) printf("Erreur texture");

    //Conditions pour quitter la fenêtre de jeu
    while(running){
        while(SDL_PollEvent(&event)){
            //Conditions de sortie de l'app
            if (event.type == SDL_QUIT) running = 0;
            if (event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE)
                running = 0;
            }
            //Check des boutons de direction -> "zqsd" du pavé numérique donc "8456"
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP))last_key=8;
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT))last_key=4;
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN))last_key=5;
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT))last_key=6;
        }
        //Rafraîchissement du Labyrinth
        SDL_RenderCopy(renderer, labyrinth_texture, NULL, &labyrinth);

        //Affichage des objets sur la map
        if (map_init == 0){
            generate_map();
            map_init = 1;
        }

        move_Pacman(last_key, &posPacmanY, &posPacmanX);
        update_map();
        SDL_RenderPresent(renderer);
        SDL_Delay(64);
    }
}