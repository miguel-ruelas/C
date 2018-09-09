/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "fcntl.h"
#include "../sys/file.h"
#define PERMS 0666
#define BUF_CHARCOUNT  200

int getSaved(int*);
int savePos(int value,int row, int col);
int BUF_SIZE =BUF_CHARCOUNT * sizeof(char);
static int fd;
char* read_buf ;
char* write_buf;
char number[2];
int getSaved(int* tableInit)
{
    read_buf = (char*)malloc (BUF_SIZE);
    write_buf = (char*)malloc (3*sizeof(char));
    
    int i,j, p,a;   //for loop variables
    fd = open ("board.csv", O_RDWR, 0);
    int* table = (int*)malloc (sizeof(int[8][8]));
   

    if (fd<0)
    {
        //create the file
        if(!(fd = creat("board.csv", PERMS)))
        {
            printf("Create File Failed");
            return 0;

        }
        //write the file with initial config
        char* tableCopyBuf =  (char*)malloc (200*sizeof(char));
        char* comma = ",";

          for (i = 0, p=0;i<8; i++)
          {
            for (j = 0; j < 8; j++)
            {
                
                //printf("Line:%d POS:%d\n",i, p);
                if(j !=7)
                {
                    sprintf(number, "%2d,", *(tableInit + i*8 + j), 3);
                    strncpy(tableCopyBuf+p,number, 3);
                    p+=3;
                }
                else
                {
                    sprintf(number, "%2d\r\n", *(tableInit + i*8 + j), 4);
                    strncpy(tableCopyBuf+p,number, 4);
                    p+= 4;
                }              
               
               
            }
            
          }
        sprintf(number, "\0");
        strncpy(tableCopyBuf+p,number, 1);
        p++;
        //printf("BuF:\n%s",tableCopyBuf );
        write(fd, tableCopyBuf,strlen(tableCopyBuf));
       
       

    }
    else  //file found
    {
        //printf("FD=%d\n",fd);
        //read file
        int n_read = read(fd, read_buf, BUF_SIZE);
        //printf("READ=%d\n",n_read);
        //printf("Reading Buffer:\n");
        //printf("%s", read_buf);
        //printf("|END\n\n");

        for (i= 0,p=0;i<8; i++)
        {
            for (j= 0 ;j<8; j++)
            {
                //printf("For:%d ,%d\n", i, j);
                a = atoi(strncpy (number, read_buf + p,2));
                //printf("%d\n", a);
                *(table + i * 8 + j) = a;
                p += 3;
                if (j==7)
                {
                    p+=1;
                }
            }

        }
        //printf("Exit Insert to table For Loop\n");
        //printf("Printing TABLE:\n");
        //for (i = 0; i <  8; i++)
         // for (j = 0; j < 8; j++)
          //   printf("%d", *(table + i*8 + j));
        //printf("\n\n");       
        //printf("COPY table to table in memory\n");
        for (i = 0; i <  8; i++)
          for (j = 0; j < 8; j++)
              *(tableInit + i*8 + j) = *(table + i*8 + j);
        printf("\n");

        //printf("Printing TABLE in Memory:\n");
        //for (i = 0; i <  8; i++)
         // for (j = 0; j < 8; j++)
           //  printf("%d", *(tableInit + i*8 + j));

        printf("\n");
    }       
        
    
    return 1;

}

 int savePos(int value,int row, int col)
 {
     //printf("SavePos-FD=%d\n",fd);
     int position = (col*3) + (row*25);
    // printf("SavePos-POS:%d\n", position);
     //printf("SavePos-Value:%d\n", value);
     sprintf(number, "%2d,", value, 2);
     int lseekstatus = lseek(fd, (long) position, 0);
    // printf("SavePos-Lseek:%d\n", lseekstatus);
     int result = write(fd, number,2);
     return result;
 }