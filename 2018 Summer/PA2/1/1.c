/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   1.c
 * This program was created as a coursework assignment by
 * Author: Miguel A. Ruelas Jacobo
 * Panther ID: 4808540
 * For:
 * Course    : COP 4338 Programming III
 * Professor : Kianoosh G. Boroojen
 * Assignment: Assignment 2
 * Due Date : 6/7/2018
 * Created on June 7, 2018, 1:07 PM
 */


#include <stdio.h>
#include <stdlib.h>
int nMOD3 (int n[ ], int size);
static int sum ;
static int result ;

int nMOD3 (int n[ ], int size)
{
    
    static int sum =0;
    static int result = 0;
     
    sum += n[0];

    if (size == 1)
    {
        result= sum % 3 ;
        sum =0;
    }
    if (size > 1)
    {
        nMOD3(n+1, size-1);
    }

    return result  ;
}
