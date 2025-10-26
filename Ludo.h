#ifndef LUDO_H
#define LUDO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//color codes for terminal output
#define RED "\033[31m"
#define GRN "\033[32m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define RES "\033[0m"
#define MAJ "\033[35m"

//declarations for functions prototypes to be used
void printludo();
void select_player_order(int playersvalues[],char *players[],char *playerorder[]);
void print_player_order(char *playerorder[]);
void playnow2(int pos[4][4],int relpos_open[],char *playerorder[],int countt[],int addwinner[]);
void playnow(int x,int pos[4][4],int i,int relpos_open[],char *playerorder[]);
void playnow_3(int i,int pos[4][4],char *playerorder[],int relpos_open[],int die);
void adgest_pos_relpos(int p,int q,int pos[4][4],char *playerorder[],int relpos_open[],int die);
void play_ludo(int playersvalues[],char *players[],char *playerorder[],int pos[4][4],int relpos_open[],int countt[],int addwinner[]);
void before_game_begins();
void After_every_round(char *playerorder[],int pos[4][4],int relpos_open[]);
int relposgen(int n,int m,int pos[4][4],int relpos_open[]);
int n_dise(int n);
int for_the_base_or_to_the_board(int count,int count4);

//declaring the data structures
int playersvalues[4] = {0,0,0,0};   //to store openning dise values
int countt[4]={0,0,0,0};        // Count of pieces on board for each player
char *players[4]={YEL"Yellow"RES,BLU"Blue"RES,RED"Red"RES,GRN"Green"RES};
char *playerorder[4];       //storing player order
int addwinner[4];           // Array to keep track of winners
int relpos_open[4]={1,14,27,40};    // Opening Relative positions of pieces
int pos[4][4]={{1,1,1,1},
                {1,1,1,1},      // Position of each piece
                {1,1,1,1},
                {1,1,1,1}};

#endif