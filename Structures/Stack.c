#include <stdio.h>
#include <stdlib.h>
#include "../Interfaces/Stack.h"

Stack *CreateStack() {
    Stack *stack;
    stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

unsigned StackIsEmpty(Stack *stack) {
    return (stack->head == NULL);
}

void Push(Stack *stack, int key) {
    StackNode *node;
    node = malloc(sizeof(StackNode));
    node->key = key;

    node->prev = stack->head;
    stack->head = node;
}

int Pop(Stack *stack) {
    if (StackIsEmpty(stack)) {
        return INT_MIN;
    }

    StackNode *result_node = stack->head;

    if (stack->head->prev) {
        stack->head = stack->head->prev;
    }

    int result = result_node->key;
    free(result_node);

    return result;
}

void PrintStack(Stack *stack) {
    if (stack == NULL || StackIsEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    StackNode *tempNode = stack->head;
    int count;
    count = 0;
    printf("\nElements of stack: ");
    while (tempNode != NULL) {
        printf("%d->", tempNode->key);
        count++;
        tempNode = tempNode->prev;
    }
    printf("\n");
}