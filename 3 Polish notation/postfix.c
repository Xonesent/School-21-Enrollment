#include "postfix.h"

void choice(const char* expression, int* top, int* i, double stack[MAX_STACK_SIZE]) {
    if ((expression[*i] >= '0' && expression[*i] <= '9') ||
        (expression[*i] == '-' && expression[*i + 1] >= '0' && expression[*i + 1] <= '9')) {
        digit(expression, top, i, stack);
    } else if (expression[*i] == '+' || expression[*i] == '-' || expression[*i] == '*' ||
               expression[*i] == '/' || expression[*i] == '^' || expression[*i] == '~') {
        operand(expression, top, i, stack);
    } else if (expression[*i] == 's' || expression[*i] == 'c' || expression[*i] == 't' ||
               expression[*i] == 'l') {
        hard_operand(expression, top, i, stack);
    }
}

void digit(const char* expression, int* top, int* i, double stack[MAX_STACK_SIZE]) {
    char* endptr;
    double num = strtod(&expression[*i], &endptr);
    stack[*top + 1] = num;
    *top += 1;
    *i = endptr - expression - 1;
}

void operand(const char* expression, int* top, int* const i, double stack[MAX_STACK_SIZE]) {
    if (expression[*i] == '+') {
        stack[*top - 1] += stack[*top];
        *top -= 1;
    } else if (expression[*i] == '-') {
        stack[*top - 1] -= stack[*top];
        *top -= 1;
    } else if (expression[*i] == '~') {
        stack[*top] *= -1;
    } else if (expression[*i] == '*') {
        stack[*top - 1] *= stack[*top];
        *top -= 1;
    } else if (expression[*i] == '/') {
        stack[*top - 1] /= stack[*top];
        *top -= 1;
    } else if (expression[*i] == '^') {
        stack[*top - 1] = pow(stack[*top - 1], stack[*top]);
        *top -= 1;
    }
}

void hard_operand(const char* expression, int* const top, int* i, double stack[MAX_STACK_SIZE]) {
    if (expression[*i] == 's' && expression[*i + 1] == 'i' && expression[*i + 2] == 'n') {
        stack[*top] = sin(stack[*top]);
        *i += 2;
    } else if (expression[*i] == 'c' && expression[*i + 1] == 'o' && expression[*i + 2] == 's') {
        stack[*top] = cos(stack[*top]);
        *i += 2;
    } else if (expression[*i] == 't' && expression[*i + 1] == 'a' && expression[*i + 2] == 'n') {
        stack[*top] = tan(stack[*top]);
        *i += 2;
    } else if (expression[*i] == 'c' && expression[*i + 1] == 't' && expression[*i + 2] == 'g') {
        stack[*top] = 1.0 / tan(stack[*top]);
        *i += 2;
    } else if (expression[*i] == 's' && expression[*i + 1] == 'q' && expression[*i + 2] == 'r' &&
               expression[*i + 3] == 't') {
        stack[*top] = sqrt(stack[*top]);
        *i += 3;
    } else if (expression[*i] == 'l' && expression[*i + 1] == 'n') {
        stack[*top] = log(stack[*top] + 0.00000000001);
        *i += 1;
    }
}

double evaluate_rpn(const char* expression, double x) {
    double stack[MAX_STACK_SIZE];
    int top = -1;
    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] == 'x') {
            stack[++top] = x;
        } else {
            choice(expression, &top, &i, stack);
        }
    }
    return stack[top];
}
