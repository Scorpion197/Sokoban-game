#include "jeu.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "constant.h"

void fill(SDL_Surface *background,information *spriteInformation,information *targetBoxes)
{
    SDL_Surface *walls[NUMBER_USED_WALLS] = {NULL};
    SDL_Surface *mario = NULL;
    SDL_Surface *targets[3] = {NULL};
    SDL_Surface *boxes[3] = {NULL};
    SDL_Rect position; 
    int i,j,k;

    for ( i = 0; i < NUMBER_USED_WALLS; i++)
        walls[i] = IMG_Load("mur.jpg");

    position.x = 0; 
    position.y = 510;   /* 680 - ( 34 * 5 ) */
    k = 0;
    /* filling the last three lines */ 

    for (i = 0; i < 5; i++)
    {
        for ( j = 0; j < H_NUMBER_BOX; j++)
        {
            SDL_BlitSurface(walls[j], NULL, background, &position);
            spriteInformation[k].x = position.x; spriteInformation[k].y = position.y;
            spriteInformation[k].type = WALL;
            k++;
            position.x = position.x + 34;
        }

        position.y = position.y + 34;
        position.x = 0;
    }

    /* filling the first two lines */ 

    position.x = 0; 
    position.y = 0;
    k = k + 1; 

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10 ; j++)
        {
            SDL_BlitSurface(walls[j], NULL, background, &position);
            spriteInformation[k].x = position.x; spriteInformation[k].y = position.y;
            spriteInformation[k].type = WALL;
            k++;
            position.x = position.x + 34;
        }

        position.y = position.y + 34;
        position.x = 0; 
    } 

    /* filling two lines in the middle */ 

    position.x = 442; /* after 3 walls of the first three lines */ 
    position.y = 0;
    k = k + 1; 

    for ( i = 0 ; i < 2 ; i++ )
    {
        for (j = 0 ; j < 6; j++)
        {
            SDL_BlitSurface(walls[j], NULL, background, &position);
            spriteInformation[k].x = position.x; spriteInformation[k].y = position.y;
            spriteInformation[k].type = WALL;
            k++;
            position.y = position.y + 34;
        }

        position.x = position.x + 34;
        position.y = 0; 
    }

    /* filling 10 walls form the right to left */ 

    position.x = 986;
    position.y = 0; 
    k = k + 1;
    for (i = 0; i < 4 ; i++)
    {
        for ( j = 0; j < 12; j++)
        {
            SDL_BlitSurface(walls[j], NULL, background, &position);
            spriteInformation[k].x = position.x; spriteInformation[k].y = position.y;
            spriteInformation[k].type = WALL;
            k++;
            position.x = position.x - 34;
        }

        position.y = position.y + 34;
        position.x = 986;
    }

    position.x = 442;
    position.y = 510;
    k = k + 1;

    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 7; j++)
        {
            SDL_BlitSurface(walls[j], NULL, background,&position);
            spriteInformation[k].x = position.x; spriteInformation[k].y = position.y;
            spriteInformation[k].type = WALL;
            k++;
            position.y = position.y - 34;
        }

        position.x = position.x + 34;
        position.y = 510;
    }

    position.x = 850;
    position.y = 510;
    k = k + 1;

    for ( i = 0; i < 5; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            SDL_BlitSurface(walls[j], NULL, background,&position);
            spriteInformation[k].x = position.x; spriteInformation[k].y = position.y;
            spriteInformation[k].type = WALL;
            k++;
            position.y = position.y - 34;
        }

        position.x = position.x - 34;
        position.y = 510;
    }

    position.x = 34;
    position.y = 204;
    k = k + 1;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            SDL_BlitSurface(walls[j], NULL, background, &position);
            spriteInformation[k].x = position.x; spriteInformation[k].y = position.y;
            spriteInformation[k].type = WALL;
            k++;
            position.x = position.x + 34;
        }

        position.x = 34;
        position.y = position.y + 34;
    } 
    
    /* loading targets */

    targets[0] = IMG_Load("target.png"); 
    position.x = 0; 
    position.y = 136;
    targetBoxes[0].x = position.x; targetBoxes[0].y = position.y;
    targetBoxes[0].type = TARGET;
    SDL_BlitSurface(targets[0], NULL, background, &position);

    targets[1] = IMG_Load("target.png");
    position.x = 0;
    position.y = 442; 
    targetBoxes[1].x = position.x; spriteInformation[1].y = position.y;
    targetBoxes[1].type = TARGET;
    SDL_BlitSurface(targets[1], NULL, background, &position);

    targets[2] = IMG_Load("target.png");
    position.x = 578;
    position.y = 0;
    targetBoxes[2].x = position.x; targetBoxes[2].y = position.y;
    targetBoxes[2].type = TARGET;
    SDL_BlitSurface(targets[2], NULL, background, &position);

    

    
  


        
    

}


