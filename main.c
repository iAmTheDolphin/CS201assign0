#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "integer.h"
#include <time.h>

extern void srandom(unsigned int);
extern long int random(void);


int main () {

    DLL *items = newDLL(displayINTEGER, freeINTEGER);

    for (int x = 0; x < 10000000; x ++ ) {
        insertDLL(items, x, newINTEGER(1));
    }
}