#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

Stack* create_stack();
void push(Stack *stack, void *data);
void* pop(Stack *stack);
void* peek(Stack *stack);
void free_stack(Stack *stack);

#endif /* STACK_H */