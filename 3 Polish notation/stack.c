#include "stack.h"

struct stack* init(char* data) {
    struct stack* new_node = malloc(sizeof(struct stack));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct stack* push(struct stack** root, char* data) {
    struct stack* new_node = init(data);
    new_node->next = *root;
    *root = new_node;
    return *root;
}

char* pop(struct stack** root) {
    struct stack* tmp = *root;
    *root = (*root)->next;
    char* popped_value = tmp->data;
    free(tmp);

    return popped_value;
}
