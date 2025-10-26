#include "Ludo.h"
#include "Game_Logic.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//main function to run the game
int main()
{
    srand(time(0));         // Seeding the random number generators
    play_ludo(playersvalues,players,playerorder,pos,relpos_open,countt,addwinner);      // Running the game
    return 0;
}