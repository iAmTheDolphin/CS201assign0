/*
 * Integer tester, by John C. Lusth
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "integer.h"
#include "stack.h"

static void showItems(SLL *items)
{
   // printf("The items are ");
    displaySLL(items, stdout);
    printf("\n");
}

int main()
{




    STACK *stack = newSTACK(displayINTEGER, freeINTEGER);
    freeSTACK(stack);

    return 0;


}
