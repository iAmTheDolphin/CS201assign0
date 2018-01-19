//
// Created by Parker Jones on 1/17/18.
//

#include "stack.h"

struct stack {
    void (*display) (void *, FILE *);
    void (*free) (void *);
    DLL *items;
};

STACK *newSTACK(void (*display)(void *,FILE *),void (*free)(void *)) {

    STACK *stack = malloc(sizeof(STACK));
    DLL *items = newDLL(display, free);

    assert(stack != 0);
    stack->display = display;
    stack->free = free;
    stack->items = items;
    return 0;
}

void push(STACK *stack,void *value) {
    insertDLL(stack->items, 0, value);
}

void *pop(STACK *stack) {
    void *value = removeDLL(stack->items, 0);
    assert(value != 0);
    return value;
}

void *peekSTACK(STACK *stack) {
    void *value = getDLL(stack->items, 0);
    assert(value != 0);
    return value;
}

int sizeSTACK(STACK *stack) {
    return sizeDLL(stack->items);
}

void displaySTACK(DLL *items,FILE *fp) {
    int size = sizeDLL(items);
    printf("|");
    for(int x = 0; x < size; x++) {
        if(x > 0) printf(",");
    }
    printf("|");
}