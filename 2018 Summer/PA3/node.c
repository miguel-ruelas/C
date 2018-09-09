#include <stdlib.h>
#define NUMBUCKS 8
struct node
{
    char* string;
    struct node* next;
} node;

struct bucket
{
    int minInitial;
    int maxInitial;
    int numWords;
    struct node* chainHead;
} bucket;

struct bucket list[NUMBUCKS] = 
{
    'a', 'b', 0, NULL,
    'c', 'c', 0, NULL,
    'd', 'f', 0, NULL,
    'g', 'k', 0, NULL,
    'l', 'o', 0, NULL,
    'p', 'r', 0, NULL,
    's', 's', 0, NULL,
    't', 'z', 0, NULL
};
 
