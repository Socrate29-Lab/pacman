#include <stdio.h>
#include "jeu.h"
#include "ecran.h"
#include "map.h"
#include "move_pacman.h"
#include "move_ghosts.h"
#include "grille.h"
#include <SDL2/SDL_ttf.h>

//Initialisation du jeu
int jouer(int *score){
    //Données pour permettre au programme de savoir quelle étape il doit faire
    int running = 1;
    SDL_Event event;
    int map_init = 0;
    int last_key = 6;
    *score = 0;
    int empty = 0;

    //Quand pac-gum mangé
    int eat_ghosts = 0;
    int timer_super = 0;
    Uint32 super_start_time = 0;
    const int SUPER_DUREE = 5000; //(pour 5 secondes)
    char timer_super_text[64];
    sprintf(timer_super_text, "Super : %d", timer_super);

    //Mort et respawn des fantômes
    int life_ghost1 = 1;
    int timer_respawn1 = 0;
    int life_ghost2 = 1;
    int timer_respawn2 = 0;
    int life_ghost3 = 1;
    int timer_respawn3 = 0;

    //Données nécessaires au déplacement
    int posPacmanY=14; int posPacmanX=1;
    int ghost1Y=14; int ghost1X=13;
    int ghost2Y=14; int ghost2X=14;
    int ghost3Y=15; int ghost3X=14;

    //Initialisation de deux timers pour les déplacements de Pacman et des fantômes
    Uint32 lastMovePacman = 0;
    Uint32 lastMoveGhosts = 0;

    //Chargement de la police d'écriture
    TTF_Font *sixtyfour = TTF_OpenFont("assets/Sixtyfour.ttf",12);
    if (!sixtyfour) {
    printf("Erreur TTF_OpenFont : %s\n", TTF_GetError());
    }
    SDL_Color yellow = {255, 255, 0, 255};
    SDL_Color white = {0,0,0,255};
    //Surface de texte
    SDL_Surface *timer_surface = TTF_RenderUTF8_Blended(sixtyfour, timer_super_text, yellow);
    SDL_Texture *timer_texture = SDL_CreateTextureFromSurface(renderer, timer_surface);
    SDL_FreeSurface(timer_surface);
    //Rectangle pour afficher le texte
    SDL_Rect timer_rect;
    TTF_SizeUTF8(sixtyfour, timer_super_text, &timer_rect.w, &timer_rect.h);
    timer_rect.x = 26;
    timer_rect.y = 280;

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
            if (event.type == SDL_KEYDOWN) { if(event.key.keysym.sym == SDLK_ESCAPE) running = 0; }
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
            move_Pacman(last_key, &posPacmanY, &posPacmanX, &*score, &running, &eat_ghosts, &super_start_time, &life_ghost1, &life_ghost2, &life_ghost3);
            lastMovePacman=now;
        }

        //Check si le timer a été mis a jour pour l'afficher à l'ecran
        sprintf(timer_super_text, "Super : %d", timer_super);

        //Délai de déplacement des fantômes
        if(now-lastMoveGhosts>96){
            move_ghost1(&ghost1Y, &ghost1X, &running, &eat_ghosts, &life_ghost1, &timer_respawn1);
            move_ghost2(&ghost2Y, &ghost2X, &running, &eat_ghosts, &life_ghost2, &timer_respawn2);
            move_ghost3(&ghost3Y, &ghost3X, &running, &eat_ghosts, &life_ghost3, &timer_respawn3);
            lastMoveGhosts=now;
        }
        //Timer pour le mode super de Pacman
        if(eat_ghosts == 1){
            Uint32 tempsPassé = SDL_GetTicks() - super_start_time;
            int tempsRestant = (SUPER_DUREE - tempsPassé) / 1000;
            
            if(tempsRestant <= 0){
                eat_ghosts = 0;
                tempsRestant;
            }
            timer_super = tempsRestant;
        }
        
        //Check respawn fantome 1
        if(life_ghost1 == 0){
            timer_respawn1 --;
            if(timer_respawn1 <= 0){
                life_ghost1 = 1;
                timer_respawn1 = 0;
            }
        }
        //Check respawn fantome 2
        if(life_ghost2 == 0){
            timer_respawn2 --;
            if(timer_respawn2 <= 0){
                life_ghost2 = 1;
                timer_respawn2 = 0;
            }
        }
        //Check respawn fantome 3
        if(life_ghost3 == 0){
            timer_respawn3 --;
            if(timer_respawn3 <= 0){
                life_ghost3 = 1;
                timer_respawn3 = 0;
            }
        }
        update_map();
        check_if_empty(&empty);
        if(check_if_empty(&empty) == 1){
            for(int i=0; i<31; i++){
                for(int j=0; j<28; j++){
                    grille_deplacement[i][j] = grille_init[i][j];
                }
            }
            posPacmanY = 14; posPacmanX = 1;
            ghost1Y = 14; ghost1X = 13;
            ghost2Y = 14; ghost2X = 14;
            ghost3Y = 15; ghost3X = 14;
            generate_map();
        }
        SDL_RenderCopy(renderer, timer_texture, NULL, &timer_rect);
        SDL_RenderPresent(renderer);
    }
    return *score;
    SDL_DestroyTexture(timer_texture);
    TTF_CloseFont(sixtyfour);
}