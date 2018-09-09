/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: adminx
 *
 * Created on June 26, 2018, 9:52 PM
 */
// cd C:\Users\adminx\Documents\NetBeansProjects\COP4338-Assignment3\
// gcc main.c -o main
// main
// hello my name is mike and this is the end

#include <stdio.h>
#include <stdlib.h>
#include "ArrayBucket.h" //cmd

#define MAXWORDLENGTH 50







/*
 * 
 */
int main(int argc, char** argv) {

    
    char s[MAXWORDLENGTH];
    char* word;
    
    while(word=getword(s,MAXWORDLENGTH ))
    {
        //printf("\nMainAdd:%s", word);
        addWord(word);
    }
    
    BucketSort();
    printBuckets();
    clearAlloc();
    
  
    return (EXIT_SUCCESS);
}

