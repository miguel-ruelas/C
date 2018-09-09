/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "node.c" //cmd

void swp(struct node* node1, struct node* node2)
{
    char* temp = node1->string;
    node1->string = node2-> string;
    node2->string = temp;
}
    

