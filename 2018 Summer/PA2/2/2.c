/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   2.c
 * This program was created as a coursework assignment by
 * Author: Miguel A. Ruelas Jacobo
 * Panther ID: 4808540
 * For:
 * Course    : COP 4338 Programming III
 * Professor : Kianoosh G. Boroojen
 * Assignment: Assignment 2
 * Due Date : 6/7/2018
 * Created on June 7, 2018, 1:07 PM
 *  */

#include <stdio.h>
#include <stdlib.h>
#define MAXVAL 100
int queueSize =0;
int sp1 = 0;
int sp2 = 0;
int stack1[MAXVAL];
int stack2[MAXVAL];
void enqueue(int entity);
int dequeue();
    
static void push(int i , int *stack , int *sp )
{
    //printf("sp= %d\n", *sp);
     if (*sp <MAXVAL)
        stack[(*sp)++]=i;
    else
        printf("Error: Queue full, can't queue %d\n", i);
    //printf("sp= %d\n", *sp);
}

static int pop(int *stack, int *sp )
{
    if (*sp >0)
        return stack[--(*sp)];
    else
    {
        printf("Error: Queue empty\n");
    }
}

void enqueue(int entity)
{
    
    //printf("Enter enqueue\n");
    push(entity, stack1, &sp1);
    queueSize++;
    //printf("Exit enqueue\n");

}

int dequeue()
{
    int result;
    
     //printf("Enter dequeue\n");
    
    if (queueSize==0)
    {
        printf("Error on Dequeue, queue is empty!\n");
        return -1;
    }
    
    if (sp2==0)
    {
           
        for (int i = 0; i < queueSize ; i++ )
        {
             push(pop(stack1, &sp1),stack2, &sp2);
        }  
    }
    
    result = pop(stack2,&sp2);
    
    queueSize--;
    
    return result;
   
}


    





