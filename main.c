/*
 * Integer tester, by John C. Lusth
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "integer.h"

static void showItems(SLL *items)
{
   // printf("The items are ");
    displaySLL(items, stdout);
    printf("\n");
}

int main()
{


    SLL *items = newSLL(displayINTEGER, freeINTEGER);

    insertSLL(items,0,newINTEGER(2));
    insertSLL(items,0,newINTEGER(3));
    showItems(items);
    removeSLL(items, 1);
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



    return 0;

}
