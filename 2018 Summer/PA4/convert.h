/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   convert.h
 * Author: adminx
 *
 * Created on July 11, 2018, 2:46 PM
 */

#ifndef CONVERT_H
#define CONVERT_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "sys/unistd.h"
#include <string.h>
#include <errno.h>

#include "getExtension.c"
#include "validExtensions.c"
#include "changeFormat.c"
 
char* getExtension (char *fileName);
int validExt(char *ext1, char *ext2);
void error(char*, ...);
int changeFormat(FILE *ifp, FILE *ofp, char* ext1, char* ext2);
 
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* CONVERT_H */

