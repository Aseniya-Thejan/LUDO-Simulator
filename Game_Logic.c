#include "Ludo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to print ludo(just an artistic representation)
//from definers YEL,BLU,RED,GRN I gave colors to *'s.And from RES I reset the colors.
void printludo()
{
    printf("\n");
    printf(YEL"********************************"RES BLU"***************************************"RES RED"**********************************"RES GRN"*******************************************\n"RES);
    printf(YEL"********************************"RES BLU"***************************************"RES RED"**********************************"RES GRN"*******************************************\n"RES);
    printf(YEL"********        ****************"RES BLU"****        **************        *****"RES RED"*****           ******************"RES GRN"*****************   ***********************\n"RES);
    printf(YEL"********        ****************"RES BLU"****        **************        *****"RES RED"*****                 ************"RES GRN"************              *****************\n"RES);
    printf(YEL"********        ****************"RES BLU"****        **************        *****"RES RED"*****       ******       *********"RES GRN"*********       ******       **************\n"RES);
    printf(YEL"********        ****************"RES BLU"****        **************        *****"RES RED"*****       *********      *******"RES GRN"*******       ***********       ***********\n"RES);
    printf(YEL"********        ****************"RES BLU"****        **************        *****"RES RED"*****       ***********      *****"RES GRN"*****      ****************      **********\n"RES);
    printf(YEL"********        ****************"RES BLU"****        **************        *****"RES RED"*****       ************      ****"RES GRN"****      *******************     *********\n"RES);
    printf(YEL"********        ****************"RES BLU"****        **************        *****"RES RED"*****       ************      ****"RES GRN"****      *******************     *********\n"RES);
    printf(YEL"********        ****************"RES BLU"****         ************        ******"RES RED"*****       ************      ****"RES GRN"****      *******************     *********\n"RES);
    printf(YEL"********        ****************"RES BLU"****          **********        *******"RES RED"*****       ***********      *****"RES GRN"*****      ****************      **********\n"RES);
    printf(YEL"********        ****************"RES BLU"*****           ******         ********"RES RED"*****       *********       ******"RES GRN"*******      ************       ***********\n"RES);
    printf(YEL"********                    ****"RES BLU"*******            *         **********"RES RED"*****       *****        *********"RES GRN"*********      ********       *************\n"RES);
    printf(YEL"********                    ****"RES BLU"***********                 ***********"RES RED"*****                *************"RES GRN"************               ****************\n"RES);
    printf(YEL"********************************"RES BLU"******************   ******************"RES RED"**********************************"RES GRN"*****************    **********************\n"RES);
    printf(YEL"********************************"RES BLU"***************************************"RES RED"**********************************"RES GRN"*******************************************\n"RES);
    printf("\n");
}

//The function to generate a random number between 1 to 6.
int n_dise(int n)
{                                       //From rand()%n they generate a random number between 0 to n-1
    return (rand() % n) + 1;            //by adding 1 to it we can get a random number between  1 to n
}

//Function using to select the player order according to the highest dise value in select player order rounds.
void select_player_order(int playersvalues[],char *players[],char *playerorder[])
{
    for (int i=0;i<4;i++)
    {
        playersvalues[i]=n_dise(6);        //generating a random value between 1 to 6 for every player.
    }
    for (int i=0;i<4;i++)
    {
        printf("%s Rolls %d.\n", players[i] ,playersvalues[i]);     //printing the values got by the players in select player order rounds.
    }
    int max=playersvalues[0];       //assigning max value to the dise value of yellow
    int maxindex=0;                 //assigning maxindex to the index of yellow
    for (int i=1;i<4;i++)
    {
        if (max<playersvalues[i])           //selecting the maximum value and index of the player who got the maximum value.
        {
            max=playersvalues[i];
            maxindex=i;
        }
    }
    int maxcount=0;
    for (int i=0;i<4;i++)
    {
        if(max==playersvalues[i])           //after identifying the max value counting the no of players who got the same max value.
        {
            maxcount++;
        }
    }
    if (maxcount>1)
    {
        printf("There are more than 1 max value. So Rolling again....\n\n");    //if there are any ties infrom it to players and .
        select_player_order(playersvalues, players, playerorder);               //calling to select_player_order function again to determine the player order.
    }
    else
    {
        for (int i=0;i<4;i++)
        {                                                       //if there are no ties,
            playerorder[i] = players[(maxindex + i) % 4];       //Appending the player order to a array named Playerorder[]
        }
    }     
}

//The function that include the logic to run the program until every piece reachs to Home and finishing touchs.
void playnow2(int pos[4][4],int relpos_open[],char *playerorder[],int countt[],int addwinner[])
{
    int wincount=0;     //defining a variable to count the players who finishing the game.
    int ii=0;           //defining a variable to count the round numbers.
    while(1)            //infinity loop
    {
        int count1 = 0;
        for(int o=0;o<4;o++)
        {
            for(int k=0;k<4;k++)            //counting the number of pieces who finished the game.
            {                               //in 2d array pos first index reprecents the color of the piece and. 
                if(pos[o][k]==101)          //the second index reprecents the index of the piece.
                {                           //pos means possition
                    count1++;               //if the position of a piece=101 that means that piece is in its Home. 
                }
            }
        }
        if (count1==16)
        {
            break;                          //breaking the infinity loop when every piece reaches home
        }
        printf(MAJ"\nRound No :- %d\n\n"RES,ii+1);      //printing the round number
        for(int i=0;i<4;i++)
        {
            if (countt[i]==4)
            {                                       
                continue;                //if all the pieces are reached to Home in color i skip that index and continue the loop 
            }
            playnow(0,pos,i,relpos_open,playerorder);       //calling to playnow function
            for(int o=0;o<4;o++)
            {
                int count2=0;
                for(int k=0;k<4;k++)
                {
                    if(pos[o][k]==101)
                    {
                        count2++;          //counting the no of pieces who reached to home in a specific color. 
                    }
                    countt[o]=count2;       //Entering that count to the array named countt
                }
            }
            if (countt[i]==4)
            {
                printf("%s player finished the game and got the %d place.\n",playerorder[i],wincount+1);    //if all pieces of color i reaches home.print that player finished the game.
                addwinner[wincount]=i;      //Add that winners index to the array addwinner                                                                  
                wincount++;                 //increment the variable wincount
            }
            printf("\n");      
        }
        After_every_round(playerorder,pos,relpos_open);     //calling function after_every_round to print the player stats
        printf("\n");
        ii++;       //increment the variable used to count the round number
    }
    printludo();        //print ludo art
    printf("\n\nThe Summery\n\n");
    printf("Player %s Won the game!!!!!!\n",playerorder[addwinner[0]]);
    printf("Player %s Won the Second Place........\n",playerorder[addwinner[1]]);       //printing  the winning order at the end of the game
    printf("Player %s Won the Third Place..........\n",playerorder[addwinner[2]]);      //from array addwinner im taking the index of the 1,2,3 and forth places.
    printf("Player %s Won the Fourth Place.........\n",playerorder[addwinner[3]]);      //im using it to print the player name.
    printf("\n");
    printf("\n");
}

//Function using to print the player stats
void After_every_round(char *playerorder[],int pos[4][4],int relpos_open[])
{
    printf(MAJ"Player Stats\n\n"RES);
    for(int i=0;i<4;i++)
    {
        printf("For Player %s\n",playerorder[i]);       //printing player color
        int count=0;
        int count5=0;
        for(int j=0;j<4;j++)
        {
            if(pos[i][j]==1)
            {
                count++;            //counting the no of pieces in the base
            }
            if(pos[i][j]==101)
            {
                count5++;              //counting the no of pieces in Home
            }
        } 
        printf("\n");
        printf("%s Player now has %d/4 pieces on the board and %d/4 pieces on the base.\n\n",playerorder[i],4-count,count);
        printf("=======================================================================\n\n");
        for(int j=0;j<4;j++)
        {
            if(pos[i][j]>1 && pos[i][j]<53)     //if the piece is in specific cells
            {
                printf("Location of %s-%d is L-%d\n",playerorder[i],j+1,relposgen(i,j,pos,relpos_open)); 
            }
            else if(pos[i][j]>52 && pos[i][j]<70)   //if the piece is in the home straight
            {
                printf("Location of %s-%d is H-%d\n",playerorder[i],j+1,pos[i][j]-52);
            }
        }
            if(count5==4)          //if all pieces for that color are in home
            {
                printf("Player %s had finished the game.\n",playerorder[i]);
            }
            else if(count+count5==4)        //if all pieces are in either base or Home
            {
                printf("There are no active players for %s\n",playerorder[i]);
            }
           
        printf("\n=======================================================================\n\n");
        for(int j=0;j<4;j++)
        {
            if(pos[i][j]==1)        //if the piece is in base
            {
                printf("Piece %s-%d is in the Base\n",playerorder[i],j+1);
            }
            if(pos[i][j]==101)        //it the piece is in Home
            {
                printf("Piece %s-%d is in the Home\n",playerorder[i],j+1);
            }
        }
        printf("\n");
    }
}

 //function using to get the dise values                                               
void playnow(int x,int pos[4][4],int i,int relpos_open[],char *playerorder[])
{
    int die=n_dise(6);          //generating a random value between 1 to 6
    int count;
    int count4;
    if (die == 6 && x < 2)      //if the geneted value = 6 and the repeating dise trow <=2
    {
        count=0;
        count4=0;
        for(int j=0;j<4;j++)
        {
            if(pos[i][j]>1 && pos[i][j]<53)         
            {
                count++;        //counting the no. of pieces who can move 6 spaces
            }
            if(pos[i][j]==1)
            {
                count4++;       //counting the no. of pieces who are in the Base.
            }
        }
        int choice=for_the_base_or_to_the_board(count,count4);      //asking the choice from functin for_the_base_or_to_the_board
        if (choice==1)      //If the choice is to take a piece from the base
        {
            int j;
            while(1)         //start a infint loop and run it until you find a piece in the base.
            {
                j=(rand() % 4);
                if(pos[i][j]==1) //if the piece is in the base(if a piece is in the base possition is=1)
                {
                    pos[i][j]=2;//taking the random piece to the starting point(if the possition is = 2 it is in its start) and braeking the infinit loop.
                    break;  
                }
            } 
            int count=0;
            for(int k=0;k<4;k++)
            {                           //count the no. of players in the base
                if(pos[i][k]==1)
                {
                    count++;
                }
            }       //displaying player is taking a piece from base
            printf("%s Player rolled %d.\n",playerorder[i] ,die);
            printf("%s Player moves peice %s-%d to the starting point.\n",playerorder[i],playerorder[i],j+1);
            printf("%s Player now has %d/4 pieces on the board and %d/4 pieces on the base.\n",playerorder[i],4-count,count);
            printf("%s Player Rolled 6. So he will get an another roll.\n\n",playerorder[i]);
            x=x+1;      //increment the repeating dise trow
            playnow(x,pos,i,relpos_open,playerorder);       //call playnow function again because player rolled 6 and he will get an another trow
        }
        else            //If the choice is to take the value to board
        {
            x=x+1;      //increment the repeating dise trow
            printf("%s Player rolled %d\n",playerorder[i] ,die);
            playnow_3(i,pos,playerorder,relpos_open,die);       //calling function playnow_3 to continue the game
            printf("%s Player Rolled 6. So he will get an another roll.\n\n",playerorder[i]);
            playnow(x,pos,i,relpos_open,playerorder);       //call playnow function again because player rolled 6 and he will get an another trow
        }
    }
     else   //else the geneted value = 6 and the repeating dise trow <=2
    {
        if (die == 6) 
        {
            printf("%s Player rolled %d\n",playerorder[i] ,die);
            die = 0;            //the dise value will be terminated because he rolled 6 three times in a row.
            printf("%s rolled value 6,three Times in a Row.So The Last Trow Will Be Terminated.....\n",playerorder[i]);
        }
        else        //if dise value is not equal to 6
        {
            printf("%s Player rolled %d\n",playerorder[i] ,die);
            playnow_3(i,pos,playerorder,relpos_open,die);       //calling function playnow_3 to continue the game
        } 
    }
}

//function to countinue the game
void playnow_3(int i,int pos[4][4],char *playerorder[],int relpos_open[],int die)
{
    while(1)
    {
        int count2=0;
        for(int j=0;j<4;j++)
        { 
            if(pos[i][j]==1)
            {
                count2++;           //counting the no of pieces in the base
            }
        }
        if(count2==4)
        {
            printf("There are no active pieces in the board for %s player. So the trow will be terminated.....\n",playerorder[i]);
            break;      //if all pieces are in the base that player cant play in this round.
        }
        int count3=0;
        for(int j=0;j<4;j++)
        {
            if(pos[i][j]>100)
            {
                count3++;           //counting the no of pieces in Home
            }
        }
        if(count3+count2==4)
        {
            printf("There are no active pieces in the board for %s player. So the trow will be terminated.....\n",playerorder[i]);
            break;      //if all pieces are in either the base or the Home that player cant play in this round.
        }
        int x1=(rand() % 4);
        if(pos[i][x1]>=2 && pos[i][x1]<100)        //find a random active player 
        {
            adgest_pos_relpos(i,x1,pos,playerorder,relpos_open,die);    //calling a function to add dise value to possition 
            for(int i=0;i<4;i++)
            {
                int count=0;
                for(int j=0;j<4;j++)
                {
                    if(pos[i][j]==58)       //if the possition = 58 for a piese that means that piece is reached home.
                    {
                        printf("%s's %dth peice completed the game......\n",playerorder[i],j+1);
                        pos[i][j]=101;      //taking the possition of the player who is home to 101 to make calculations easy
                    }
                }
            }
            break;      //after checking the possition of every piece break the infinit loop
        }
    }
}

//function to calculate the relative possition
void adgest_pos_relpos(int p,int q,int pos[4][4],char *playerorder[],int relpos_open[],int die)
{
    pos[p][q]=pos[p][q]+die;        //add the dise value to possition
    if(pos[p][q]>58 && pos[p][q]<85)        //when we add dise value to possition, if the piese passes the home, such moves are not permited
    {
        pos[p][q]=pos[p][q]-die;    //so decrease that dise value
        int ccount=0;
        for(int j=0;j<4;j++)
        {
            if((pos[p][j]>1) && (pos[p][j]+die<=58))
            {
                ccount++;       //count the no of moveable pieces with that dise value 
            }
        }
        if(ccount==0)           //if there are no active moveable pieces to move, display it
        {
            printf("%s player moves %s-%d by %d places from %d.\n",playerorder[p] ,playerorder[p],q+1,die,pos[p][q]-1);
            printf("To reach home player should roll the exact value. So the trow will be terminated and peice %s-%d will return to %d\n",playerorder[p],q+1,pos[p][q]-1);    
        }
        else        //if there are no active moveable pieces
        {
            while(1)        //create an infiity loop, find that piece and move it.
            {
                int x=(rand()%4);
                if((pos[p][x]>1) && (pos[p][x]+die<=58))
                {
                    pos[p][x]=pos[p][x]+die;
                    printf("%s player moves Piece %s-%d from %d to %d by %d units in clockwise direction\n",playerorder[p] ,playerorder[p],x+1,pos[p][x]-die-1,pos[p][x]-1,die);
                    break;
                }
            }
        }    
    }
    else //even the piece is not passing the Home,
    {     //you cant move the piece to a cell where an another same color piece sits.
        int cccount=0;
        for(int j=0;j<4;j++)
        {
            if(q==j)
            {
                continue;       //preventing counting the same possition of the active player
            }
            if(pos[p][q]==pos[p][j])
            {
                cccount++;      //counting the no of other same type piece in that possition
            }
        }
        if(cccount==0)  //if there are non nothing to worry
        {
            printf("%s player moves %s-%d from %d to %d by %d units in clockwise direction\n",playerorder[p] ,playerorder[p],q+1,pos[p][q]-die-1,pos[p][q]-1,die);
        }
    }
    for(int j=0;j<4;j++)
    {
        if(q==j)
        {
            continue;       //preventing counting the same possition of the active player
        }
        if(pos[p][q]>52)
        {
            continue;       //preventing counting the players in the homestraight
        }
        if(relposgen(p,q,pos,relpos_open)==relpos_open[p])
        {
            continue;       //preventing counting the players in their starting points
        }
        if (pos[p][q]==pos[p][j])   //if there is more than 1 same color player in a cell exept abow conditions
        {
            pos[p][q]=pos[p][q]-die;    //decreament the dise value
            int ccount=0;
            for(int t=0;t<4;t++)
            {
                if(t==q)
                {                           //preventing counting the same possition of the active player
                    continue;
                }
                if((pos[p][t]>1) && (pos[p][t]+die<=58))
                {
                    ccount++;               //countng the number of moveable players
                }
            }
            if(ccount==0)   //if there are no moveable players
            {
                if(pos[p][j]<53)
                {
                    printf("%s-%d piece is blocked from moving from L%d to L%d by piece %s-%d",playerorder[p],q+1,relposgen(p,q,pos,relpos_open),relposgen(p,j,pos,relpos_open),playerorder[p],j+1);
                    printf("player %s does not have other pieces in the board to move instead of the blocked piece.\nIgnoring the trow and moving on to the next player\n",playerorder[p]);   
                }
                if(pos[p][j]>52)
                {
                    printf("%s-%d piece is blocked from moving to H%d by piece %s-%d",playerorder[p],q+1,pos[p][j]-52,playerorder[p],j+1);
                    printf("player %s does not have other pieces in the board to move instead of the blocked piece.\nIgnoring the trow and moving on to the next player\n",playerorder[p]);
                }
            }
            else        //if there are moveable players
            {
                while(1)    //runs until find a random piece who can move
                {
                    int x=(rand()%4);
                    if (x==q)
                    {
                        continue;   //preventing moving the same piece
                    }
                    if((pos[p][x]>1) && (pos[p][x]+die<=58))
                    {
                        pos[p][x]=pos[p][x]+die;
                        printf("%s player moves %s-%d from %d to %d by %d units in clockwise direction.\n",playerorder[p] ,playerorder[p],x+1,pos[p][x]-die-1,pos[p][x]-1,die);
                        break;
                    }
                }
            }
        }  
    }
    for(int j=0;j<4;j++)    //for capturing pieces
    {
        if(p==j)
        {
            continue;       //preventing capturing same color pieces
        }
        for(int k=0;k<4;k++)
        {
            if(relposgen(j,k,pos,relpos_open)==101) 
            {
                continue;       //if the relative possition=101 that piece is in home or home straight so skip that
            }
            if(relposgen(j,k,pos,relpos_open)==0) 
            {
                continue;       //if the relative possition=101 that piece is in base so skip that
            }
            if(relposgen(j,k,pos,relpos_open)==relpos_open[j])
            {       //if the relative possition=relpos_open of that color you can skip that because you cant capture a piece in its starting point.     
                continue;   
            }       //if you want to capture pieces in there starting points you can remove this part.
            if(relposgen(p,q,pos,relpos_open)==relposgen(j,k,pos,relpos_open))
            {   //capturing a piece
                printf("Piece %s-%d lands on square L%d, captures %s-%d, and returns it to the base.....\n",playerorder[p],q+1,relposgen(p,q,pos,relpos_open),playerorder[j],k+1);
                pos[j][k]=1;    //sent back to base
            }
        }
    }
}

//function to generate the relative possition of a piece
int relposgen(int n,int m,int pos[4][4],int relpos_open[])
{
    int relpos;     //relative possiton of a piece is the possition of a piece in the board
    if(pos[n][m]==1)
    {
        relpos=0;   //if the piece is in the base relpos=0
    }
    else if(pos[n][m]>52)
    {
        relpos=101;     //if the piece is in the home straight
    }
    else
    {
        relpos=pos[n][m]-2+relpos_open[n];  //generating relpos
        if(relpos>52)
        {
            relpos=relpos-52;   //if relpose>52 (after completing a round) you can decriment 52 to get the board possition
        }
    }
    return relpos;      //return the valu of relpos
}

//function using to take the disition about to the board or to the Base
int for_the_base_or_to_the_board(int count,int count4)      //count-playable pieces  count4-no of pieces in the base
{
    if(count4==0)       //if there are no pieces in the base your value should go to board
    {
        return 2;
    }                       //2-to board
    else if(count4==4)      //1-to base
    {
        return 1;       //if all pieces are in the base your value should go to base
    }
    else if(count==0 && count4>0)
    {
        return 1;       //if there are no playable pieces and there are pieces in the base your value should go to base 
    }
    else if(count==0 && count4==0)
    {
        return 2;       //if there are no playable pieces and there are no pieces in the base, your value should go to board 
    }
    else
    {
        return n_dise(2);        //else random choice between base or board
    }
}

//fuction to print the player order
void print_player_order(char *playerorder[])
{
    printf("\n%s player has the heighest roll and will begin the game.\n",playerorder[0]);
    printf("The order of a single round is %s",playerorder[0]);
    for(int i=1;i<4;i++)
    {
        printf(" --> %s",playerorder[i]);
    }
    printf("\n");
    printf("\nL1 is the starting point of player %s.\n",playerorder[0]);
    printf("\n");
}

//function to print requirement prints before game begins
void before_game_begins()
{
    printf("\n\nThe Red player has four(04) pieces named R1,R2,R3 and R4.\n");
    printf("The Green player has four(04) pieces named G1,G2,G3 and G4.\n");
    printf("The Yellow player has four(04) pieces named Y1,Y2,Y3 and Y4.\n");
    printf("The Blue player has four(04) pieces named B1,B2,B3 and B4.\n\n\n");
}

//The function connecting every other functions
void play_ludo(int playersvalues[],char *players[],char *playerorder[],int pos[4][4],int relpos_open[],int countt[],int addwinner[])
{
    printludo(); 
    before_game_begins();
    select_player_order(playersvalues, players, playerorder);
    print_player_order(playerorder); 
    playnow2(pos,relpos_open,playerorder,countt,addwinner);
}