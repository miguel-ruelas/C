/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* getExtension (char *fileName) 
{
    char *ext = strrchr (fileName, '.');
    if (ext == NULL)
        ext = ""; // fast method, could also use &(fspec[strlen(fspec)]).
    printf("Ext: %s found\n",ext );
    char* result = (char *)malloc(strlen(ext)+1);
    strcpy(result, ext);
    return result;
}