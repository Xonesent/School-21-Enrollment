#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct stack {
    char* data;
    struct stack* next;
};

struct stack* init(char* data);
struct stack* push(struct stack** root, char* data);
char* pop(struct stack** root);

#endif
