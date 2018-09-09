/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//create chess table
#include <stdio.h>
#include <stdlib.h>
#include "fileOps.c"



   


void init(void);
void printTable(void);
int getSaved(int*);
static int validMove(int piece,int sRow,int sCol,int dRow,int dCol, int cFlag);
int savePos(int value,int row, int col);

 static int table[8][8] =
    {
        {-4,-2,-3,-5,-6,-3,-2,-4},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 1, 1, 1, 1, 1, 1, 1, 1},
        { 4, 2, 3, 5, 6, 3, 2, 4}
    };
 
 typedef enum {player1,player2} player;

 static player turn = player1;


void init(void)
{
    //read from file
 
    if (getSaved(*table) )
    {
        //printf("Read File!!!\n");
        //printf("Received Altered TABLE?:\n");
        //int i, j;
        //for (i = 0; i <  8; i++)
         // for (j = 0; j < 8; j++)
          //    printf("%d", table[i][j]);
    
     printf("\n");
    }
    else
    {
        printf("Read File Failed!!!\n");
    }
    turn = player1;
       
}

void printTable()
{
    printf("\n\t\tTurn:%s\n\n", (turn == player1 ? "Player 1":"Player 2"));
    int i;
    int j;
    for (i= 0; i<8;i++)
    {
       //print in tl5 left justified format
        for (j= 0; j<8;j++)
        {
            if (j != 0)
            {
                printf("|");
            }
            printf("%-5d", table[i][j]);
        }
         printf("\n");
    }
}

int move(int sRow, int sCol, int dRow, int dCol, int cFlag)
{
    printf("Move-Received:SR%d SC%d DR%d DC%d CF%d\n", sRow,sCol,dRow,dCol,cFlag);
    //check if source and dest are valid board areas
    int valid = 0; //must equal four to be valid
    int capturable = 0;
   
    if (sRow <= 7)
        valid++;
    if (sRow >= 0)
        valid++;
    if (sCol <= 7)
        valid++;
    if (sCol >= 0)
        valid++;
    if (valid!=4)
    {
        return -1;
    }
    
    //check if source is a chess piece
    int sPiece = table[sRow][sCol];
    int dPiece;
    if (sPiece == 0)
    {
        return -1;
    }
    //check if source belongs to player
    if (turn == player1)
    {
        if (sPiece >= 0)
        {
            printf("That is not your piece. Try again\n");
            return -1;
        }
            
    }
    if (turn == player2)
    {
        if (sPiece <= 0)
        {
            printf("That is not your piece. Try again\n");
            return -1;
        }
    }
    dPiece = table[dRow][dCol];
    //check if move is a capture
    if(!cFlag)
    {
        if(dPiece != 0)
        {
            printf("That space is occupied, try again!\n");
            return -1;
        }
    }
  
    if (cFlag)
    {
        if(dPiece == 0)
        {
            printf("No pieces to capture in that square!");
            return -1;
        }
        if (sPiece > 0)
        {
            if(dPiece > 0)
            {
                printf("Cannot capture own piece!");
                return -1;
            }
        }
        if (sPiece < 0)
        {
            if(dPiece < 0)
            {
                printf("Cannot capture own piece!");
                return -1;
            }
            
        }
        if (sPiece < 0)
        {
            if(dPiece > 0)
            {
                printf("Cannot capture own piece!");
                return -1;
            }
            
        }
        capturable =1;
    }
    printf("sPiece:%d dPiece:%d\n", sPiece, dPiece);
    
    //check if chess moving to dest is valid
    if(!validMove(sPiece,sRow,sCol,dRow,dCol,capturable))
    {
        return -1;
    }
    
    //save changes to disk
    //clear original
    int write = savePos( 0, sRow,  sCol);
    if(!write)
    {
        printf("Error writing to file!");
        return -1;
    }
    write = savePos( sPiece, dRow,  dCol);
    if(!write)
    {
        printf("Error writing to file!");
        return -1;
    }
    //save changes to table
    table[sRow][sCol] = 0;
    table[dRow][dCol] = sPiece;
    
    //switch player
    if (turn == player1)
    {
        turn= player2;
    }
    else
    {
        turn=player1;
    }
    printf("Move Successful returning 1\n");
    return 1;
    
}

static int validMove(int piece,int sRow,int sCol,int dRow,int dCol,int cFlag)
{
    int valid = 0;
    int result1;
    int result2;
    
    switch (abs(piece))
    {
            case 1:  
                if (!cFlag)
                {
                    result1 = (abs(sRow-dRow) == 1) && (abs(sCol-dCol) == 0);
                    printf("Pawn result1 -R1:%d \n",result1);     
                    return result1;
                }
                else 
                {
                    result1 = (abs(sRow-dRow) == 1) && (abs(sCol-dCol) == 1);
                    printf("Pawn result2 -R1:%d \n",result1);     
                    return result1;
                }                       
                break;
            case 2:
                result1 = (abs(sRow-dRow) == 2) && (abs(sCol-dCol) == 1);
                result2 = (abs(sRow-dRow) == 1) && (abs(sCol-dCol) == 2);
                printf("R1:%d R2:%d\n",result1, result2);             
                return result1 || result2;
                break;
    }
    
    return 0;
}
