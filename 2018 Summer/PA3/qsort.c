/*qsort: sort bucket list node - left ... node - right in increasing order*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "swp.c"




void qksrt(struct node* start, int numNodes)
{

    
    // if less than 2 items return
    if (numNodes<=1)
        return;
    //else sort partition
    
    struct node* partition = start;
    struct node* test = start->next;

    
    //intialize counts to keep track of locations partition and current node that is
    // being tested. numNodes is an int from 1 - n, partCount and testCount work
    // like array elements that begin at 0
    int partCount =0;  //set partition to first element in list
    int testCount =1;  //set test to next element after partition
    
    
    //printf("\nQKSRT ENTERED"); 
   
    while (testCount < numNodes)
    {
        //printf("\nQKSRT WHILE Test: %d < %d", testCount, numNodes ); 
        //printf("\nQKSRT WHILE ENTERED: %s , %s", partition->string, test->string  );
        int ret = strcmp(test->string, partition->string);

        //printf("\n Result strcmp: %d\n", ret);
        
        if(ret < 0)
        {
            //printf("test is less than part\n");
            if (testCount!= partCount + 1 )
            {
                swp(test,partition->next);
            }        
            swp(partition->next,partition);
            partition = partition->next;
            partCount++;
            test = test->next;
            testCount++;
        } 
        else if(ret > 0) 
        {
            //printf("part is less than test\n");
        
           if(testCount != numNodes-1)
           {
               test = test->next;
           }  
            testCount++;
            
        } 
        else
        {     
            //printf("test is equal to part\n");
            if (testCount!= partCount + 1 )
            {
                swp(test,partition->next);
            }        
            swp(partition->next,partition);
            partition = partition->next;
            partCount++;
            test = test->next;
            testCount++;
        }
        /* CODE IN THIS BLOCK IS TO SEE THE CHANGES DONE AFTER EACH TEST
        printf("\nQKSRT WHILE Printing Nodes" );
        int cnt = 0;
        struct node* printNode = start;
        while (cnt < numNodes)
        {
            printf("%d: %s ", cnt, printNode->string);
            printNode= printNode->next;
            cnt++;
        }
         
         */
        
    }
    // printf("\nQKSRT WHILE Exit partCount:%d numNodes:%d", partCount, numNodes );
    //partition left 
    qksrt(start,partCount );
    //partition right();
    if (partCount!= numNodes-1) // do not do partition->next if parition is last node
    {
        qksrt(partition->next,numNodes - (partCount +1)  );
    }
      
}
