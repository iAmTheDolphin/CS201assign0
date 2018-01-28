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

    for(int x = 0; x < 10; x ++ ) {
        enqueue(queue, newINTEGER(x));
    }

    printf("done queueing\n");

    for(int x = 0; x < 9; x ++ ) {
        free(dequeue(queue));
    }
    showItemsQUEUE(queue);

    free(dequeue(queue));

    freeQUEUE(queue);



    return 0;


}
