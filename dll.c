//
// Created by Parker Jones on 1/15/18.
//

#include "dll.h"

int debugDLL = 0;
//if(debugDLL) printf("_DLL - \n");

struct dll {
    NODE *head;
    NODE *tail;
    int size;
    void (*display)(void *, FILE *);
    void (*free)(void *);
};

DLL *newDLL(void (*d)(void *, FILE *), void (*f)(void *)) {
    DLL *items = malloc(sizeof(DLL));
    assert(items != 0);
    items->head = 0;
    items->tail = 0;
    items->size = 0;
    items->display = d;
    items->free = f;
    return items;
}


static NODE *getNodeBefore (DLL *items, int index) {
    NODE *n = items->head;
    for(int x = 1; x < index; x++) {
        n = getNODEnext(n);
    }
    return n;
}


void insertDLL(DLL *items, int index, void *value) {
    if(debugDLL) printf("_DLL - inserting into DLL\n");
    assert(index >= 0 && index <= items->size);
    NODE *n;
    if(items->size == 0) {
        n = newNODEdll(value, 0, 0);
        items->head = n;
        items->tail = n;
        if(debugDLL) printf("_DLL - - first element added to list\n");
    }
    else if(index == 0) {
        n = newNODEdll(value, items->head, 0);
        setNODElast(items->head, n);
        items->head = n;
        if(debugDLL) printf("_DLL - - element added to front\n");
    }
    else {
        NODE *b4 = getNodeBefore(items, index);
        NODE *next = getNODEnext(b4);
        n = newNODEdll(value, next, b4);
        if(next == 0) items->tail = n;
        else setNODElast(next, n);
        setNODEnext(b4, n);
        if(debugDLL) printf("_DLL - - element added to middle/end of list\n");
    }
    items->size++;
}

void *removeDLL(DLL *items,int index) {
    assert(items->size > 0 && index >= 0 && index < items->size);

    NODE *n = getNodeBefore(items, index + 1);
}

extern void displayDLL(DLL *items,FILE *fp) {
    //FIXME

    NODE *n = items->head;
    if(items->size == 0) {
        printf("/pick>");
    }
    else {
        for (int x = 0; x < items->size; x ++) {
            if (x > 0) printf(",");
            items->display(getNODEvalue(n), fp);
            n = getNODEnext(n);
        }
    }

}