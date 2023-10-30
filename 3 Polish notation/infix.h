#ifndef INFIX_H
#define INFIX_H

#include <stdio.h>
#include <string.h>

#include "stack.h"

#define WIDTH 80
#define HEIGHT 25

void dijkstra(char *infix_str, char *postfix_str);
void pop_to_str(char **postfix_str, struct stack **top);
int precendece(char const *str);
int is_binary_operation(char symbol, char **tmp);
int is_prefix(char *str, char **tmp);
int is_digit(char symbol);

#endif
