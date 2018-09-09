/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: adminx
 *
 * Created on July 23, 2018, 10:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chessTable.c"
#include "getch.c"
#include "getCommand.c"
#define MAXWORDLENGTH 8


void init(void);
void printTable(void);
char * getCommand(char* word, int lim);
int move(int sRow, int sCol, int dRow, int dCol, int cFlag);


/*
 * 
 */
int main(int argc, char** argv) {
    int active =1;
    printf("CHESS\n");
    init();
    printTable();
    printf("Enter command:");
    while(active)
    {
        //get move from user
        char s[MAXWORDLENGTH];
        char* word;
        char* command[2];
        int capture = 0;
    
        while( word = getCommand(s,MAXWORDLENGTH ))
        {
            printf("Recived command:%s\n", word);
            strncpy(*command,word,2);
            if(strcmp(*command, "mv")== 0)
            {
                
            }
            else if(strcmp(*command, "cp")== 0)
            {
                capture = 1;
            }
            else
            {
                printf("invalid command\n");
                printf("Enter new command:\n");
                continue;
            }
            //mv 12 12    
            printf("CharCheck:%c, %c, %c, %c\n", word[3], word[4], word[6], word[7]);        
            int sRow = 8 -(*(word+4) -'0');
            int sCol = *(word+3)- 'a';
            int dRow = 8- (*(word+7)- '0');
            int dCol = *(word+6)- 'a';
            printf("Atoi:%d, %d, %d, %d\n", sRow, sCol, dRow, dCol);
             //execute move
            int moveResult = move(sRow,sCol,dRow,dCol,capture);
            printf("MoveResult:%d\n", moveResult);
            printf("Move:%s\n", moveResult == 1 ? "Successful": "Failed");
            //print results
            printTable();
             printf("Enter command:");
        }
        
       
        
    }
    
   
    //printf("Move:%d\n",move(1,1,2,1,0));
    printf("Printing Table in MEM\n");
    printTable();

    return (EXIT_SUCCESS);
}

