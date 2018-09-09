/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validExt(char *ext1, char *ext2)
{
    printf("ValidExt Received:  %s, %s\n", ext1, ext2);
    const char* validList[] = {".csv", ".tl5", ".tr9", ".tc9"};
    if (strcmp(ext1, ext2)== 0)
        return 0;
    int n = 0;
    int found = 0;
    printf("ValidExt Before ForLoop N:  %d, %d\n", n, found);
    for ( n = 0; n < 4 ; ++n ) 
    {
        //printf("ValidExt ForLoop N:  %d, %s\n", n, ext2);
        if ( strcmp(validList[n], ext1) ==0 )
        { 
         found++;
         printf("ValidExt Validated:  %s\n", ext1);
        } 
        if ( strcmp(validList[n], ext2) == 0 )
        { 
         found++;
         printf("ValidExt Validated:  %s\n", ext2);
        } 
    } 
    if (found !=2)
    {
        printf("Error: Could not validate filename extensions %s, %s\n", ext1, ext2);
        exit(1);
    }
     printf("ValidExt After ForLoop N:  %d, %d\n", n, found);
    return 1;
}