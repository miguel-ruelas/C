/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsort.c" //cmd



void findBucket(struct node* fullNode);

void addWord(char* inputString )
{
    char* aWord = (char *)malloc(strlen(inputString)+1);
    strcpy(aWord, inputString);
    //printf("Original Address:%d", aWord); //test the address received
    struct node *temp = malloc (sizeof (struct node));
    temp->string = aWord;
    temp->next = NULL;
    //printf("MALLOC String Address:%p\n", temp->string); //point to same mem loc as aWord
    //printf("MALLOC NodeAddress:%p\n", temp); //address in malloc
    findBucket(temp);
    
}

void findBucket(struct node* fullNode)
{
    //printf("FindBucketNodeAddress:%p\n", fullNode); 
    
    
    char test = fullNode->string[0];
    //printf("findbucket%d\n", fullNode->string); //point to same mem loc as aWord
    //printf("Test:%c\n", test);
    switch (test)
    {
            case 'a':;
            case 'b':
                fullNode->next = list[0].chainHead;
                list[0].chainHead=fullNode;
                list[0].numWords++;
                break;
            case 'c':
                fullNode->next = list[1].chainHead;
                list[1].chainHead=fullNode;
                list[1].numWords++;
                break;
            case 'd':;
            case 'e':;
            case 'f':
                fullNode->next = list[2].chainHead;
                list[2].chainHead=fullNode;
                list[2].numWords++;
                break;
            case 'g':;
            case 'h':;
            case 'i':;
            case 'j':;
            case 'k':
                fullNode->next = list[3].chainHead;
                list[3].chainHead=fullNode;
                list[3].numWords++;
                break;
            case 'l':;
            case 'm':;
            case 'n':;
            case 'o':
                fullNode->next = list[4].chainHead;
                list[4].chainHead=fullNode;
                list[4].numWords++;
                break;
            case 'p':;
            case 'q':;
            case 'r':
                fullNode->next = list[5].chainHead;
                list[5].chainHead=fullNode;
                list[5].numWords++;
                break;
            case 's':
                fullNode->next = list[6].chainHead;
                list[6].chainHead=fullNode;
                list[6].numWords++;
                break;
            case 't':;
            case 'u':;
            case 'v':;
            case 'w':;
            case 'x':;
            case 'y':;
            case 'z':
                fullNode->next = list[7].chainHead;
                list[7].chainHead=fullNode;
                list[7].numWords++;
                break;
    }

}
 
void BucketSort(void)
{
    int i;
    
    //printf("\nBucketSort");
    for (i = 0; i < NUMBUCKS; i++ )
    {
        //printf("\nForLoop: i=%d", i);
        if (list[i].chainHead != NULL)
        {
            qksrt(list[i].chainHead, list[i].numWords);
        }
    }
    
}

void printBuckets(void)
{
    int i;
    
    //printf("\nPrintBuckets");
    for (i = 0; i < NUMBUCKS; i++ )
    {
       // printf("\nForLoop: i=%d", i);
         
        if (list[i].chainHead != NULL)
        {
            //printf("\nForLoopin If");
            struct node *test = list[i].chainHead;
            //printf("\nForLoopin Node:%d\n", test->string);
            printf("\n");
            while (test != NULL)
            {
                printf("%s, ", test->string);
                test = test->next;
            }
            //printf("\nForLoop in if after while");
            
        }
        
    }
}

/*Need to ask about how to check to make sure free() has worked 
 * and all memory allocated has been cleared.*/
void clearAlloc(void)
{
    int i;
    
    //printf("\nClear Memory Allocated");
    for (i = 0; i < NUMBUCKS; i++ )
    {
        //printf("\nForLoop: i=%d", i);
         
        if (list[i].chainHead != NULL)
        {
            //printf("\nForLoopin If");
            struct node *test = list[i].chainHead;
            struct node *freeNode;
            //printf("\nForLoopin Node:%d\n", test->string);
            while (test != NULL)
            {
                //printf("\n Clearing Node:%p\n", test);
                //printf("\n Clearing String:%p\n", test->string);
                freeNode = test;
                free(test->string);
                test = test->next;
                free(freeNode);
                freeNode = test;
            }
           //printf("\nForLoopin if after while");
            
        }
        
    }
}