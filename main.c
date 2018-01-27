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
#include "queue.h"

static void showItems(QUEUE *items)
{
   // printf("The items are ");
    displayQUEUE(items, stdout);
    printf("\n");
}

int main()
{

/*
    QUEUE *queue = newQUEUE(displayINTEGER, freeINTEGER);
    enqueue(queue, newINTEGER(3));
    enqueue(queue, newINTEGER(4));
    enqueue(queue, newINTEGER(2));
    showItems(queue);
    free(dequeue(queue));
    free(dequeue(queue));
    free(dequeue(queue));
    showItems(queue);
    freeQUEUE(queue);
*/

    STACK *stack = newSTACK(displayINTEGER, freeINTEGER);
    push(stack, newINTEGER(1));
    freeINTEGER(pop(stack));
    freeSTACK(stack);
/*
    SLL *items = newSLL(displayINTEGER, freeINTEGER);

    insertSLL(items,0,newINTEGER(2));
    insertSLL(items,0,newINTEGER(3));
    showItems(items);
    free(removeSLL(items, 1));
    showItems(items);
    free(removeSLL(items, 0));
    showItems(items);
    insertSLL(items,0,newINTEGER(6));
    insertSLL(items,0,newINTEGER(7));
    showItems(items);
    SLL *items2 = newSLL(displayINTEGER, freeINTEGER);
    insertSLL(items2,0,newINTEGER(4));
    insertSLL(items2,0,newINTEGER(5));
    showItems(items2);
    unionSLL(items, items2);
    displaySLL(items, stdout);
    displaySLL(items2, stdout);
    displaySLLdebug(items, stdout);
    free(removeSLL(items, 0));
    free(removeSLL(items, 0));
    free(removeSLL(items, 0));
    free(removeSLL(items, 0));
    displaySLLdebug(items, stdout);

    freeSLL(items);
    freeSLL(items2);
*/
    return 0;


}
