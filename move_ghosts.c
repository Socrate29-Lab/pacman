#include "move_ghosts.h"
#include "grille.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
void move_ghost1(int *posY, int *posX, int *pac_life, int *statut, int *ghost_life, int *timer){
    static int direction;
    if(*posY == 14 && *posX == 13) direction = 8;
    static int grid_memo = 1;
    int blocked = 0;
    //Si le fantôme a besoin de respawn
    if(*ghost_life == 0){
        *posY = 14;
        *posX = 13;
        grid_memo = 1;
        direction = 8;
        grille_deplacement[*posY][*posX] = 6;
        return;
    }
    int nextY = *posY;
    int nextX = *posX;
    //Deplacement vers le haut
    if(direction == 8) nextY--;
    //Deplacement vers la gauche
    else if(direction == 4) nextX--;
    //Deplacement vers le bas
    else if(direction == 5 && grille_deplacement[*posY + 1][*posX] != 12) nextY++;
    //Deplacement vers la droite
    else if(direction == 6) nextX++;
    int next = grille_deplacement[nextY][nextX];
    // Collision mur
    if(next == 0){
        blocked = 1;
    } else {
        // Collision Pac-Man
        if(next == 5){
            if(*statut == 0) *pac_life = 0;
            else{ 
                *ghost_life = 0;
                *timer = 200;
            }
        }
        // Déplacement normal
        if(*ghost_life == 1){
            grille_deplacement[*posY][*posX] = grid_memo;
            if(next != 6 && next != 7 && next != 8)
                grid_memo = next;
            *posY = nextY;
            *posX = nextX;
        }
    }
    if(blocked)random_direction(&direction);
    grille_deplacement[*posY][*posX] =6;
}
void move_ghost2(int *posY, int *posX, int *pac_life, int *statut, int *ghost_life, int *timer){
    static int direction;
    if(*posY == 14 && *posX == 14) direction = 8;
    static int grid_memo = 1;
    int blocked = 0;
    //Si le fantôme a besoin de respawn

    if(*ghost_life == 0){
        *posY = 14;
        *posX = 14;
        grid_memo = 1;
        direction = 8;
        grille_deplacement[*posY][*posX] = 7;
        return;
    }
    int nextY = *posY;
    int nextX = *posX;
    //Deplacement vers le haut
    if(direction == 8) nextY--;
    //Deplacement vers la gauche
    else if(direction == 4) nextX--;
    //Deplacement vers le bas
    else if(direction == 5 && grille_deplacement[*posY + 1][*posX] != 12) nextY++;
    //Deplacement vers la droite
    else if(direction == 6) nextX++;
    int next = grille_deplacement[nextY][nextX];
    // Collision mur
    if(next == 0){
        blocked = 1;
    } else {
        // Collision Pac-Man
        if(next == 5){
            if(*statut == 0) *pac_life = 0;
            else{ 
                *ghost_life = 0;
                *timer = 200;
            }
        }
        // Déplacement normal
        if(*ghost_life == 1){
            grille_deplacement[*posY][*posX] = grid_memo;
            if(next != 6 && next != 7 && next != 8)
                grid_memo = next;
            *posY = nextY;
            *posX = nextX;
        }
    }
    if(blocked)random_direction(&direction);
    grille_deplacement[*posY][*posX] = 7;
}
void move_ghost3(int *posY, int *posX, int *pac_life, int *statut, int *ghost_life, int *timer){
    static int direction;
    if(*posY == 15 && *posX == 14) direction = 8;
    static int grid_memo = 1;
    int blocked = 0;
    //Si le fantôme a besoin de respawn
    if(*ghost_life == 0){
        *posY = 15;
        *posX = 14;
        grid_memo = 1;
        direction = 8;
        grille_deplacement[*posY][*posX] = 8;
        return;
    }
    int nextY = *posY;
    int nextX = *posX;

    //Deplacement vers le haut
    if(direction == 8) nextY--;
    //Deplacement vers la gauche
    else if(direction == 4) nextX--;
    //Deplacement vers le bas
    else if(direction == 5 && grille_deplacement[*posY + 1][*posX] != 12) nextY++;
    //Deplacement vers la droite
    else if(direction == 6) nextX++;
    int next = grille_deplacement[nextY][nextX];
    // Collision mur
    if(next == 0){
        blocked = 1;
    } else {
        // Collision Pac-Man
        if(next == 5){
            if(*statut == 0) *pac_life = 0;
            else{ 
                *ghost_life = 0;
                *timer = 200;
            }
        }
        // Déplacement normal
        if(*ghost_life == 1){
            grille_deplacement[*posY][*posX] = grid_memo;
            if(next != 6 && next != 7 && next != 8)
                grid_memo = next;
            *posY = nextY;
            *posX = nextX;
        }
    }
    if(blocked)random_direction(&direction);
    grille_deplacement[*posY][*posX] = 8;
}
void random_direction(int *direct){
    int d4 = rand()%4;
    switch(d4){
        case 0: *direct = 8; break;
        case 1: *direct = 4; break;
        case 2: *direct = 5; break;
        case 3: *direct = 6; break;
    }
}