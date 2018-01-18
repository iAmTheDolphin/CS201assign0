//
// Created by Parker Jones on 1/17/18.
//

#include "stack.h"

struct stack {


    void (*display) (void *, FILE *);
    void (*free) (void *);

};

STACK *newSTACK(void (*d)(void *,FILE *),void (*f)(void *)) {



}