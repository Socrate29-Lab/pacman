#include "move_pacman.h"
#include "grille.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void move_Pacman(int last_key,int *posY, int *posX, int *score, int *life, int *statut, int *timer_super, int *ghost1, int *ghost2, int *ghost3){

//On prend en mémoire posY et posX pour le prochain mouvement
int nextY = *posY;
int nextX = *posX;

//Prise en compte de la dernière touche appuyée pour savoir quel mouvement faire
//Haut
if(last_key == 8 && grille_deplacement[*posY - 1][*posX] != 0) nextY--;
//Bas
if(last_key == 5 && grille_deplacement[*posY + 1][*posX] != 0 && grille_deplacement[*posY + 1][*posX] != 12) nextY++;
//Gauche
if(last_key == 4 && grille_deplacement[*posY][*posX - 1] != 0) nextX--;
//Droite
if(last_key == 6 && grille_deplacement[*posY][*posX + 1] != 0) nextX++;

//Raccourcit les différents grille_deplacement[*posY][*posX + 1] etc
int next_move = grille_deplacement[nextY][nextX];

//Check si rencontre de pac-gum
if(next_move == 3){
    *statut = 1;
    *timer_super = 350;
}

//Check les deux cas de rencontre de fantôme : pac-gum actif ou non
if(next_move >= 6 && next_move <= 8){
    if(*statut == 0){
        *life = 0;
    } else {
        if(next_move == 6) *ghost1 = 0;
        if(next_move == 7) *ghost2 = 0;
        if(next_move == 8) *ghost3 = 0;
        *score += 200;
    }
}
//Check les tunnels
if(next_move == 10) nextX = 26;
if(next_move == 11) nextX = 1;

//Check la rencontre de bonbons classiques
if(next_move == 2) *score += 100;

//Ramasse l'objet
grille_deplacement[*posY][*posX] = 1;

//Effectue le déplacement sur la grille
*posY = nextY;
*posX = nextX;

//Place le visuel de Pac-Man
grille_deplacement[*posY][*posX] = 5;
}