#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "constant.h"
#include "jeu.h"


int main (int argc , char *argv[]) {
    
   /* initialising SDL and create the window */ 
    SDL_Surface *background = NULL, *box = NULL;
    SDL_Event event;
    information spriteInformation[TOTAL_BOXES];
    information targetBoxes[6]; /* we will store boxes and target's informations */
    SDL_Rect position;
    
    box = IMG_Load("caisse.jpg");

    position.x = 612;
    position.y = 442;


    SDL_Init(SDL_INIT_VIDEO); 
    SDL_WM_SetIcon(IMG_Load("caisse.jpg"), NULL);

    background = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );

    if (background == NULL) 
    {
        fprintf(stderr , "Error while initliasing SDL %s\n", SDL_GetError());
        exit(EXIT_FAILURE); 
    }

    SDL_FillRect(background, NULL, SDL_MapRGB(background->format,255,255,255));
    initBoxes(targetBoxes);
    moveMario(background, spriteInformation,targetBoxes); 
  

    SDL_Quit();

return EXIT_SUCCESS;
}


