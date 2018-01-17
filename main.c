/*
 * Integer tester, by John C. Lusth
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "integer.h"

static void showItems(DLL *items)
{
    printf("The items are ");
    displayDLL(items, stdout);
    printf(".\n");
}

int main()
{

    DLL *items = newDLL(displayINTEGER, freeINTEGER);
    DLL *items2 = newDLL(displayINTEGER, freeINTEGER);
    showItems(items);
    unionDLL(items, items2);
    insertDLL(items, 0, newINTEGER(3));
    insertDLL(items, 1, newINTEGER(4));
    unionDLL(items, items2);
    showItems(items);
    freeINTEGER(removeDLL(items, 0));
    showItems(items);
    insertDLL(items, 0, newINTEGER(3));
    showItems(items);
    freeDLL(items);
    freeDLL(items2);

    /*
    SLL *items = newSLL(displayINTEGER,freeINTEGER);
    showItems(items);
    insertSLL(items,0,newINTEGER(3));                   //insert at front
    insertSLL(items,sizeSLL(items),newINTEGER(2));      //insert at back
    insertSLL(items,1,newINTEGER(1));                   //insert at middle
    showItems(items);
    printf("The value ");
    INTEGER *i = removeSLL(items,0);                   //remove from front
    displayINTEGER(i,stdout);
    printf(" was removed.\n");
    freeINTEGER(i);
    showItems(items);
    int x = getINTEGER((INTEGER *) getSLL(items,0));    //get the first item
    printf("The first item is %d.\n",x);
    printf("Freeing the list.\n");
    freeSLL(items);
     */
    return 0;

}
