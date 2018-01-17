//
// Created by Parker Jones on 1/17/18.
//
#ifndef __STACK_INCLUDED__
#define __STACK_INCLUDED__

#include <stdio.h>
#include "sll.h"

typedef struct stack STACK;

extern STACK *newSTACK(void (*d)(void *,FILE *),void (*f)(void *));
extern void push(STACK *items,void *value);
extern void *pop(STACK *items);
extern void *peekSTACK(STACK *items);
extern int sizeSTACK(STACK *items);
extern void displaySTACK(SLL *items,FILE *);
extern void displaySTACKdebug(SLL *items,FILE *);
extern void freeSTACK(STACK *items);

#endif