#include <stdio.h>
#include "jeu.h"
#include "ecran.h"
#include "map.h"
#include "move_pacman.h"
#include "move_ghosts.h"
#include "grille.h"


//Initialisation du jeu
void jouer(){
    //Données pour permettre au programme de savoir quelle étape il doit faire
    int running = 1;
    SDL_Event event;
    int map_init=0;
    int last_key=0;
    int score = 0;

    //Données nécessaires au déplacement
    int posPacmanY=14; int posPacmanX=1;
    int ghost1Y=14; int ghost1X=13;
    int ghost2Y=14; int ghost2X=14;
    int ghost3Y=15; int ghost3X=14;

    //Initialisation de deux timers pour les déplacements de Pacman et des fantômes
    Uint32 lastMovePacman = 0;
    Uint32 lastMoveGhosts = 0;

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
            //Check des boutons de direction -> les flèches ou "zqsd" correspondent à "8456" sur le pavé numérique
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP))last_key=8;
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT))last_key=4;
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN))last_key=5;
            if(event.type ==SDL_KEYDOWN && (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT))last_key=6;
        }
        //Initialisation d'un chrono pour les différents déplacements
        Uint32 now = SDL_GetTicks();

        //Rafraîchissement du Labyrinth
        SDL_RenderCopy(renderer, labyrinth_texture, NULL, &labyrinth);

        //Affichage des objets sur la map
        if (map_init == 0){
            generate_map();
            map_init = 1;
        }

        //Délai de déplacement de Pacman
        if(now-lastMovePacman>128){
            move_Pacman(last_key, &posPacmanY, &posPacmanX, &score, &running);
            lastMovePacman=now;
        }
        if(now-lastMoveGhosts>96){
            move_ghost1(&ghost1Y, &ghost1X);
            move_ghost2(&ghost2Y, &ghost2X);
            move_ghost3(&ghost3Y, &ghost3X);
            lastMoveGhosts=now;
        }
        
        update_map();
        SDL_RenderPresent(renderer);
    }
    printf("Score final : %d", score);
}