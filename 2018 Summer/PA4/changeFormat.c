/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 4096

int getLine (char*line,FILE *ifp );
void printLine (char*line,FILE *ifp );
int changeFormat(FILE *ifp, FILE *ofp, char* ext1, char* ext2);
char* convertLine(char *line, char* ext1, char* ext2);
char* getExtension (char *fileName) ;


int changeFormat(FILE *ifp, FILE *ofp, char* ext1, char* ext2)
{
    char *fext1 = (char *)malloc(strlen(ext1)+1);
    strcpy(fext1, ext1);
    char *fext2 = (char *)malloc(strlen(ext2)+1);
    strcpy(fext2, ext2);
    printf("changeFormatEntered\n" );
    char* line;
    char* converted;
   
    while (getLine(line, ifp) > 0)
    {
         printf("getLineReturned: %s\n", line );
         converted = convertLine(line, fext1, fext2);
        printf("Converted: %s\n", converted );
        int i ;
        for(i = 0; i < 1;i++)
        {
            fprintf (ofp, "%s\n",converted);
            i++;
        }
        

    }
   

    return 0;
}

int getLine (char*line,FILE *ifp )
{
    printf("getLineEntered\n" );
    if (fgets(line, MAX ,ifp) == NULL)
         return 0;
    else
        return strlen(line);
}

char* convertLine(char *line, char* ext1, char* ext2)
{
    int maxFieldLength = 100;
    int outType =0; //0-tl5, 1-tr9, 2-tc9, 3-csv
    printf("ConvertLineEntered\n" );
    char* result = (char *)malloc(strlen(line)+1); 
    char* delimiterIn ="|";
    char* delimiterOut ="|";
    printf("ConvertLine DelimIn:%s\n", delimiterIn );
    
    if (strcmp(ext1, ".csv")== 0)
    {
         delimiterIn = ",";
         printf("ConvertLine DelimIN:%s\n", delimiterIn );
    }

    if (strcmp(ext2, ".csv")== 0)
    {
         delimiterOut = ",";
         outType=3;
         printf("ConvertLine DelimOut:%s\n", delimiterOut );
    }
    else if (strcmp(ext2, ".tl5")== 0)
    {
         maxFieldLength = 5;
         outType=0;
    }
    else 
    {
         maxFieldLength = 9;
    }
     
    
    int tokenCount = 0;
    char *token= strtok(line, delimiterIn);
    while (token)
    {
        //add space to token if needed
        int dif = maxFieldLength - strlen(token);
            
        if (dif > 0)
        {
            while (dif != 0)
            {
                strncat(token, " " , maxFieldLength);
                dif--;
            }
        }
        if (tokenCount == 0)
        {           
        strncat(result, token, maxFieldLength);
        
        tokenCount++;
        }
        else
        {
            strncat(result, delimiterOut, maxFieldLength);
            strncat(result, token, maxFieldLength);
            tokenCount++;
        }
        
            
            
      
             
            
    
        
        ("%s\n", token);
        token = strtok( NULL, delimiterIn);
    }
   
     

     printf("ConvertLineExit\n" );
    return result;
    
    
}

