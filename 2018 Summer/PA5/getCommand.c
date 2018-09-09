/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
//#include "getch.c" //cmd

char * getCommand(char* word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    
    //printf("getWordBegin:");
    
    if((c=getch())== EOF)
    {
        //printf("getWord:END OF FILE");
        return NULL;
    }
    else 
        ungetch(c);
    
    while ((c=getch())!= '\n')
    {

        if (c!= EOF)
        {
            //printf("getWordWhile:%c\n", c);
            *w++ = c;
        }
        else
        {
            //printf("getWordWhile:END OF FILE");
            ungetch(c);
            break;
        }
            
    } 
    *w ='\0';
    //printf("getWordassigned:%s\n", word);
   
    
    //printf("getWordEnd:");
    return word;
}