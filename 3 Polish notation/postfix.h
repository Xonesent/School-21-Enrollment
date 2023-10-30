#ifndef POSTFIX_H
#define POSTFIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000

void choice(const char* expression, int* top, int* i, double stack[MAX_STACK_SIZE]);
void digit(const char* expression, int* top, int* i, double stack[MAX_STACK_SIZE]);
void operand(const char* expression, int* top, int* const i, double stack[MAX_STACK_SIZE]);
void hard_operand(const char* expression, int* const top, int* i, double stack[MAX_STACK_SIZE]);
double evaluate_rpn(const char* expression, double x);

#endif
