#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES
    #define WIDTH_BOX 34
    #define SCREEN_WIDTH 986   /* 29 boxes in one line */    
    #define SCREEN_HEIGHT 680  /* 20 boxes vertically */ 

    #define V_NUMBER_BOX 20  /* number of boxes in a single column */ 
    #define H_NUMBER_BOX 29  /* number of boxes in a single line */
    #define NUMBER_USED_WALLS 29  /* the maximum number of walls created in a single loop */
    #define TOTAL_BOXES 362 /* totaly number of walls */

    /* We will define some types to store in our struct to know whether the box is mario,wall,normal box 
    or done_box */ 

    #define PLAYER 1 /* mario */ 
    #define WALL 2
    #define BOX 3
    #define BOX_DONE 4
    #define TARGET 5

    /* defining the values of up,down,left, right arrows following their int values defined in the 
        standard of the C language */ 

    #define RIGHT_ARROW 275
    #define LEFT_ARROW 276
    #define UP_ARROW 273
    #define DOWN_ARROW 274 

    /* defining the boxes . there are three boxes , each box has a number, and we test every time 
        which box mario is near to */

    #define BOX_ONE 3
    #define BOX_TWO 4
    #define BOX_THREE 5

    /* defining the struct where we gonna store all the sprites used with 
    their position and their type */ 

    typedef struct information information; 
    struct information
    {
        int x; /* position.x of the sprite */ 
        int y; /* position.y of the sprites */
        int type; /* type of the sprite whether its a player ,wall ...etc */ 
    };
#endif


