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

static void showItemsSTACK(STACK *items)
{
    displaySTACK(items, stdout);
    printf("\n");
}

static void showItemsQUEUE(QUEUE *items) {
    displayQUEUE(items, stdout);
    printf("\n");
}

static void showItemsDLL(DLL *items) {
    displayDLL(items, stdout);
    printf("\n");
}

static void showItemsSLL (SLL *items) {
    displaySLL(items, stdout);
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

    QUEUE *queue = newQUEUE(displayINTEGER, freeINTEGER);

    for(int x = 0; x < 1000000; x ++ ) {
        enqueue(queue, newINTEGER(x));
    }


    printf("done queueing\n");

    for(int x = 0; x < 999999; x ++ ) {
        free(dequeue(queue));
    }
    showItemsQUEUE(queue);
    free(dequeue(queue));
    freeQUEUE(queue);

    STACK *stack1 = newSTACK(displayINTEGER, freeINTEGER);
    for(int x = 0; x < 1000000; x ++ ) {
        push(stack1, newINTEGER(x));
    }
    for(int x = 0; x < 999996; x ++ ) {
        free(pop(stack1));
    }
    displaySTACKdebug(stack1, stdout);
    showItemsSTACK(stack1);
    freeSTACK(stack1);


    printf("\n");
    printf("\n");

    DLL *list = newDLL(displayINTEGER, freeINTEGER);
    DLL *list2 = newDLL(displayINTEGER, freeINTEGER);

    for(int x = 0; x < 9; x ++ ) {
        insertDLL(list, x/2, newINTEGER(x));
    }
    unionDLL(list, list2);
    showItemsDLL(list2);
    showItemsDLL(list);
    displayDLLdebug(list, stdout);
    printf("\n");
    for(int x = 9; x > 0; x -- ) {
        free(removeDLL(list, 0));
        displayDLLdebug(list, stdout);
        printf("\n");
    }
    displayDLLdebug(list, stdout);
    printf("\n");
    free(list);
    free(list2);


    printf("\n");
    printf("\n");

    SLL *listSll =newSLL(displayINTEGER, freeINTEGER);
    for (int x = 0; x < 10; x ++) {
        insertSLL(listSll, x, newINTEGER(x));
    }
    displaySLLdebug(listSll, stdout);
    printf("\n");
    for (int x = 9; x > 0; x --) {
        free(removeSLL(listSll, x));
        displaySLLdebug(listSll, stdout);
        printf("\n");
    }
    free(removeSLL(listSll, 0));
    displaySLLdebug(listSll, stdout);
    freeSLL(listSll);

    return 0;


}
