#include "infix.h"

void dijkstra(char *infix_str, char *postfix_str) {
    struct stack *top = NULL;
    char *tmp;
    if (*infix_str == '-') {
        push(&top, "~");
        infix_str++;
    }
    while (*infix_str != '\0') {
        if (is_digit(*infix_str)) {
            while (is_digit(*infix_str) || *infix_str == '.') {
                *postfix_str = *infix_str;
                infix_str++;
                postfix_str++;
            }
            *postfix_str = ' ';
            postfix_str++;
        } else if (is_prefix(infix_str, &tmp)) {
            push(&top, tmp);
            infix_str += strlen(tmp);
        } else if (*infix_str == '(') {
            push(&top, "(");
            infix_str++;
        } else if (*infix_str == ')') {
            while (*(top->data) != '(') {
                pop_to_str(&postfix_str, &top);
            }
            infix_str++;
        } else if (is_binary_operation(*infix_str, &tmp)) {
            while (top != NULL &&
                   (is_prefix(top->data, &tmp) || precendece(infix_str) <= precendece(top->data))) {
                pop_to_str(&postfix_str, &top);
            }
            push(&top, tmp);
            infix_str++;
        } else
            infix_str++;
    }
    while (top != NULL) {
        strcat(postfix_str, pop(&top));
        strcat(postfix_str, " ");
    }
}
void pop_to_str(char **postfix_str, struct stack **top) {
    char *tmp = pop(top);
    strcat(*postfix_str, tmp);
    strcat(*postfix_str, " ");
    *postfix_str += strlen(tmp) + 1;
}

int precendece(char const *str) {
    int result = 0;
    if (*str == '+' || *str == 0)
        result = 1;
    else if (*str == '*' || *str == '/')
        result = 2;
    else if (*str == 's' || *str == 'l' || *str == 'c')
        result = 3;
    else if (*str == '~')
        result = 4;
    return result;
}

int is_binary_operation(char symbol, char **tmp) {
    int result = 0;
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
        result = 1;
        if (symbol == '+')
            *tmp = "+";
        else if (symbol == '-' || symbol == '~')
            *tmp = "-";
        else if (symbol == '*')
            *tmp = "*";
        else
            *tmp = "/";
    }
    return result;
}

int is_prefix(char *str, char **tmp) {
    int result = 1;
    if (*str == 's' && *(str + 1) == 'i' && *(str + 2) == 'n')
        *tmp = "sin";
    else if (*str == 'c' && *(str + 1) == 'o' && *(str + 2) == 's')
        *tmp = "cos";
    else if (*str == 'c' && *(str + 1) == 't' && *(str + 2) == 'g')
        *tmp = "ctg";
    else if (*str == 't' && *(str + 1) == 'a' && *(str + 2) == 'n')
        *tmp = "tan";
    else if (*str == 's' && *(str + 1) == 'q' && *(str + 2) == 'r' && *(str + 3) == 't')
        *tmp = "sqrt";
    else if (*str == 'l' && *(str + 1) == 'n')
        *tmp = "ln";
    else
        result = 0;
    return result;
}

int is_digit(char symbol) {
    const char digits[11] = "0123456789x";
    int result = 0;
    for (int i = 0; i < 11 && result != 1; i++) {
        if (symbol == digits[i]) {
            result = 1;
        }
    }
    return result;
}
