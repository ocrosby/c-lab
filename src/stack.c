#include <stdlib.h>
#include "stack.h"

Stack* create_stack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL; // Failed to allocate memory
    }
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, void *data) {
    if (stack == NULL) {
        return; // Invalid stack
    }
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) {
        return; // Failed to allocate memory
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

void* pop(Stack *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL; // Invalid stack or empty stack
    }
    StackNode *node_to_pop = stack->top;
    void *data = node_to_pop->data;
    stack->top = node_to_pop->next;
    free(node_to_pop);
    return data;
}

void* peek(Stack *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL; // Invalid stack or empty stack
    }
    return stack->top->data;
}

void free_stack(Stack *stack) {
    if (stack == NULL) {
        return; // Invalid stack
    }
    StackNode *current = stack->top;
    while (current != NULL) {
        StackNode *next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
