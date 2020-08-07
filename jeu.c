#include "jeu.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "constant.h"

SDL_Surface *loadMario(int pressedKey)
{
    SDL_Surface *mario = NULL;

    switch(pressedKey)
    {
        case RIGHT_ARROW:
            mario = IMG_Load("mario_droite.gif");
            break;
        case LEFT_ARROW:
            mario = IMG_Load("mario_gauche.gif");
            break;
        case UP_ARROW:
            mario = IMG_Load("mario_haut.gif");
            break;
        case DOWN_ARROW:
            mario = IMG_Load("mario_bas.gif");
            break;
        default:
            mario = IMG_Load("mario_bas.gif");
            break;
    }
return mario;
             
}
void initBoxes(information *targetBoxes)
{
    targetBoxes[3].x = 374; targetBoxes[3].y = 34; targetBoxes[3].type = BOX;
    targetBoxes[4].x = 612; targetBoxes[4].y = 442; targetBoxes[4].type = BOX;
    targetBoxes[5].x = 918; targetBoxes[5].y = 442; targetBoxes[5].type = BOX;
}


void blitBoxes(SDL_Rect position,SDL_Surface *background,int indice,information *targetBoxes,int pressedKey)
{
    SDL_Rect box1,box2,box3;
    SDL_Surface *caisse;

    caisse = IMG_Load("caisse.jpg");


    box1.x = targetBoxes[3].x;
    box1.y = targetBoxes[3].y;

    box2.x = targetBoxes[4].x;
    box2.y = targetBoxes[4].y;

    box3.x = targetBoxes[5].x;
    box3.y = targetBoxes[5].y;
    switch(pressedKey)
    {
        case RIGHT_ARROW:

            if (indice == BOX_ONE)
            {
                box1.x = position.x + 34 ;
                box1.y = position.y;
                targetBoxes[indice].x = position.x+34;
                targetBoxes[indice].y = position.y;
            }
            else if (indice == BOX_TWO)
            {
                box2.x = position.x + 34 ;
                box2.y = position.y;
                targetBoxes[indice].x = position.x +34;
                targetBoxes[indice].y = position.y;

            }
            else if (indice == BOX_THREE)
            {
                box3.x = position.x + 34;
                box3.y = position.y;
                targetBoxes[indice].x = position.x +34;
                targetBoxes[indice].y = position.y;
            }
            break;
        case LEFT_ARROW:
            if (indice == BOX_ONE)
            {
                box1.x = position.x - 34 ;
                box1.y = position.y;
                targetBoxes[indice].x = position.x -34;
                targetBoxes[indice].y = position.y;
            }
            else if (indice == BOX_TWO)
            {
                box2.x = position.x - 34 ;
                box2.y = position.y;
                targetBoxes[indice].x = position.x - 34 ;
                targetBoxes[indice].y = position.y;

            }
            else if (indice == BOX_THREE)
            {
                box3.x = position.x- 34;
                box3.y = position.y;
                targetBoxes[indice].x = position.x -34 ;
                targetBoxes[indice].y = position.y;
            }
        break;
        case UP_ARROW:
            if (indice == BOX_ONE)
            {
                box1.x = position.x ;
                box1.y = position.y -34;
                targetBoxes[indice].x = position.x;
                targetBoxes[indice].y = position.y-34;
            }
            else if (indice == BOX_TWO)
            {
                box2.x = position.x;
                box2.y = position.y-34;
                targetBoxes[indice].x = position.x ;
                targetBoxes[indice].y = position.y - 34;
            }
            else if (indice == BOX_THREE)
            {
                box3.x = position.x;
                box3.y = position.y -34;
                targetBoxes[indice].x = position.x;
                targetBoxes[indice].y = position.y -34 ;
            }
            break;

        case DOWN_ARROW:
            if (indice == BOX_ONE)
            {
                box1.x = position.x ;
                box1.y = position.y + 34;
                targetBoxes[indice].x = position.x;
                targetBoxes[indice].y = position.y + 34;
            }
            else if (indice == BOX_TWO)
            {
                box2.x = position.x ;
                box2.y = position.y + 34;
                targetBoxes[indice].x = position.x ;
                targetBoxes[indice].y = position.y + 34;

            }
            else if (indice == BOX_THREE)
            {
                box3.x = position.x;
                box3.y = position.y + 34;
                targetBoxes[indice].x = position.x;
                targetBoxes[indice].y = position.y + 34;
            }
            
    }
    SDL_BlitSurface(caisse, NULL, background, &box2);
    SDL_BlitSurface(caisse, NULL, background, &box3);
    SDL_BlitSurface(caisse, NULL, background, &box1); 


}



int isWall(information *spriteInformation, int pressedKey, SDL_Rect position)
{
    int i, continuer; 

    continuer = 1;
    i = 0; 
    switch(pressedKey)
    {
        case RIGHT_ARROW:
            while (( i < 370) &&( continuer))
            {
                if ((position.x + 34 == spriteInformation[i].x)&&(position.y == spriteInformation[i].y)&&(spriteInformation[i].type == WALL))
                    continuer = 0; 
                i++;
            }
            if ( i == 370 )
                return 0; 
            else 
                return 1;
            break; 
        case LEFT_ARROW:
            while (( i < 370) &&( continuer))
            {
                if ((position.x - 34 == spriteInformation[i].x)&&(position.y == spriteInformation[i].y)&&(spriteInformation[i].type == WALL))
                    continuer = 0; 
                i++;
            }
            if ( i == 370 )
                return 0; 
            else 
                return 1;
            break;
        case UP_ARROW:
            while (( i < 370) &&( continuer))
            {
                if ((position.y - 34 == spriteInformation[i].y)&&(position.x == spriteInformation[i].x)&&(spriteInformation[i].type == WALL))
                    continuer = 0; 
                i++;
            }
            if ( i == 370 )
                return 0; 
            else 
                return 1;
            break;
        case DOWN_ARROW:
            while (( i < 370) &&( continuer))
            {
                if ((position.y + 34 == spriteInformation[i].y)&&(position.x == spriteInformation[i].x)&&(spriteInformation[i].type == WALL))
                    continuer = 0; 
                i++;
            }
            if ( i == 370 )
                return 0; 
            else 
                return 1;
            break;
    }

}

int isBox(information *targetBoxes,SDL_Rect marioPosition, int pressedKey)
{
    int i, continuer;

    i = 0; 
    continuer = 1;
   
    switch(pressedKey)
    {
            case RIGHT_ARROW:
            while (( i < 6) &&( continuer ))
            {
                if ((marioPosition.x + 34 == targetBoxes[i].x) && (marioPosition.y == targetBoxes[i].y))
                {
                    return i;
                    continuer = 0; 
                }
                else 
                    i++;
            }
            if ( i == 5)
                return 0;
                break;
             case LEFT_ARROW:
             while((i < 6) && ( continuer))
            {
                if ((marioPosition.x - 34 == targetBoxes[i].x) && (marioPosition.y == targetBoxes[i].y))
                {
                    return i;
                    continuer = 0;
                }
                else 
                    i++;
            }
            if (i == 5)
                return 0;

            break;
        case UP_ARROW:
             while((i < 6) && ( continuer))
            {
                if ((marioPosition.y - 34 == targetBoxes[i].y) && (marioPosition.x == targetBoxes[i].x))
                {
                    return i;
                    continuer = 0; 
                }
                else 
                    i++;
            }
            if (i  == 5)
                return 0;

            break;
        case DOWN_ARROW:
             while((i < 6) && ( continuer))
            {
                if ((marioPosition.y + 34 == targetBoxes[i].y) && (marioPosition.x == targetBoxes[i].x))
                {
                    return i;
                    continuer = 0; 
                }
                else 
                    i++;
            }
            if (i == 5)
                return 0;

            break;
    }
}


void moveMario(SDL_Surface *background, information *spriteInformation,information *targetBoxes)
{
    SDL_Rect positionMario; 
    SDL_Event event;
    SDL_Rect position;
    int continuer = 1;
    int key = 0;


    /* starting position initialised before in loadMario procedure */

    positionMario.x = 476; 
    positionMario.y = 238;

    SDL_EnableKeyRepeat(80, 80);
    while (continuer) 
    {   
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0; 
                break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE: 
                    continuer = 0; 
                    break;
                case SDLK_RIGHT:
                    if (isWall(spriteInformation,RIGHT_ARROW,positionMario) == 0)
                    {   
                        if (isBox(targetBoxes,positionMario,RIGHT_ARROW) != 0)
                        {
                            key = isBox(targetBoxes,positionMario,RIGHT_ARROW);
                            positionMario.x = positionMario.x + 34;
                        }
                        else 
                            positionMario.x = positionMario.x + 34;
                    
                    }

                    break;                
                case SDLK_LEFT:
                    if (isWall(spriteInformation,LEFT_ARROW,positionMario) == 0)
                    {   
                        if (isBox(targetBoxes,positionMario,LEFT_ARROW) != 0)
                        {
                            key = isBox(targetBoxes,positionMario,LEFT_ARROW);
                            positionMario.x = positionMario.x - 34;
                        }
                        else 
                            positionMario.x = positionMario.x - 34;
                    
                    }

                    break;
                case SDLK_UP:
                    if (isWall(spriteInformation,UP_ARROW,positionMario) == 0)
                    {   
                        if (isBox(targetBoxes,positionMario,UP_ARROW) != 0)
                        {
                            key = isBox(targetBoxes,positionMario,UP_ARROW);
                            positionMario.y = positionMario.y - 34;
                        }
                        else 
                            positionMario.y = positionMario.y - 34;
                    }
                    break; 
                case SDLK_DOWN:
                    if (isWall(spriteInformation,DOWN_ARROW,positionMario) == 0)
                    {   
                        if (isBox(targetBoxes,positionMario,DOWN_ARROW) != 0)
                        {
                            key = isBox(targetBoxes,positionMario,DOWN_ARROW);
                            positionMario.y = positionMario.y +  34;
                        }
                        else 
                            positionMario.y = positionMario.y + 34;
                    
                    }
                    break;
            }

            break;
        }

        SDL_FillRect(background, NULL, SDL_MapRGB(background->format,255,255,255));
        fill(background,spriteInformation,targetBoxes);
        SDL_BlitSurface(loadMario(event.key.keysym.sym), NULL, background, &positionMario);
        blitBoxes(positionMario,background,key,targetBoxes,event.key.keysym.sym);
        SDL_Flip(background);
    }
}