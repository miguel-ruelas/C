/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: adminx
 *
 * Created on July 11, 2018, 11:23 AM
 */

#include "convert.h"


/*
 * 
 */
int main(int argc, char** argv) {
    FILE *f1;
    FILE *f2;
    char *read = "r";
    char *write = "w+";
    char *extF1;
    char *extF2;
    int n;
    
    char buf[BUFSIZ];
    

    if (argv[1] == NULL)
    {
        argv[1] = "read.csv";
    }
    if (argv[2] == NULL)
    {
        argv[2] = "write.tl5";
    }
    
    printf("Received: %s , %s\n",argv[1], argv[2] );
    
    printf("Argc: %d , \n",argc );
    
    if (argc != 3)
    {
        error("Usage: main from.xxx to.xxx");
    }
    
    //validate extenstions
    extF1 = getExtension(argv[1]);
    extF2 = getExtension(argv[2]);
    
    if (validExt(extF1,extF2)!= 1)
    {
        return -1;
    }
    
    printf("Ext1: %s , Ext2: %s \n",extF1, extF2 );
    
    if((f1 = fopen(argv[1], read)) == NULL)
    {
        error("READ: Can't open %s", argv[1]);
    }
    if((f2 = fopen(argv[2], write)) == NULL)
    {
        error("READ: Can't write to %s", argv[2]);
    }
    
    printf("Reading file %s", argv[1]);

    int result = changeFormat(f1,f2, extF1 ,extF2);
    /*
     int i;
    for(i = 0; i < 10;i++){
       fprintf (f2, "This is line %d\n",i + 1);
   }
     */
    
        
    fclose(f1);
    fclose(f2);
    
    printf("Result: %d \n", result );

    return (EXIT_SUCCESS);
}

