#include <stdio.h>
#include "grille.h"
#include "tile_generation.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Fonction pour afficher tous les assets sur la map une fois qu'ils ont été généré par generate_tile
int generate_map(){
        for(int i=0; i<31; i++){
        for(int j=0; j<28; j++){
            int index = grille_init[i][j];
            generate_tile(i, j, index);
        }
    }
}

//Fonction pour afficher les assets de la map une fois qu'on a modifié la grille de départ.
int update_map(){
        for(int i=0; i<31; i++){
            for(int j=0; j<28; j++){
                int index = grille_deplacement[i][j];
                generate_tile(i, j, index);
            }
        }
}

//Fonction pour vérifier si la grille est finie
int check_if_empty(int *empty){
    int count = 0;
    for(int i=0; i<31; i++){
            for(int j=0; j<28; j++){
                if(grille_deplacement[i][j] == 2 || grille_deplacement[i][j] == 3) count++;
            }
        }
    if(count == 0) *empty = 1;
    else *empty = 0;
    return *empty;
}