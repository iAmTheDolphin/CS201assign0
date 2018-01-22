//
// Created by Parker Jones on 1/14/18.
//

#include "sll.h"

//given by Dr. Lusth on the beastie website
//--------------------------------------------------------
//region Node
typedef struct node NODE;

struct node {
    void *value;
    NODE *next;
    NODE *last;
};

static NODE *newNODE(void *value, NODE *n) {
    NODE *p = malloc(sizeof(NODE));
    if (p == 0) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    p->value = value;
    p->next = n;
    return p;
}

/* accessors */

static void *getNODEvalue(NODE *n) { return n->value; }

static NODE *getNODEnext(NODE *n) { return n->next; }

/* mutators */

static void setNODEvalue(NODE *n, void *v) { n->value = v; }

static void setNODEnext(NODE *n, NODE *p) { n->next = p; }

static void
freeNODE(NODE *n, void (*release)(void *)) {
    if (release != 0) release(n->value);
    free(n);
}
//--------------------------------------------------------
//endregion



int debugSLL = 0;
//if(debugSLL) printf("_SSL - \n");


struct sll {
    NODE *head;
    NODE *tail;
    int size;
    void (*display) (void *s, FILE *fp);
    void (*free)(void *);
};

SLL *newSLL(void (*d)(void *, FILE *), void (*f)(void *)) {
    if(debugSLL) printf("_SLL - creating new SLL\n");
    SLL *items = malloc(sizeof(SLL));
    assert(items != 0);
    items->head = 0;
    items->tail = 0;
    items->size = 0;
    items->display = d;
    items->free = f;
    if(debugSLL) printf("_SLL - new SLL created\n");
    return items;
}

//only call this after checking that it is in-bounds and not 0
static NODE *getNodeBefore(SLL *items, int index) {
    NODE *n = items->head;
    for (int x = 1; x < index; x++) {
        n = getNODEnext(n);
    }
    return n;
}

void insertSLL(SLL *items, int index, void *value) {

    if(debugSLL) printf("_SLL - inserting into SLL\n");

    assert (index >= 0 && index <= items->size);

    if (items->size == 0) {
        NODE *n = newNODE(value, 0);
        items->head = n;
        items->tail = n;
        items->size++;
        if(debugSLL) printf("_SLL - - first element added\n");
    }
    else if(index == 0) {
        if(debugSLL) printf("_SLL - - element added to front\n");
        NODE *n = newNODE(value, items->head);
        items->head = n;
        items->size++;
    }
    else {
        if(debugSLL) printf("_SLL - - element added to middle/end\n");
        NODE *b4 = getNodeBefore(items, index);
        NODE *next = getNODEnext(b4);
        NODE *n = newNODE(value, next);
        if(next == 0) items->tail = n;
        setNODEnext(b4, n);
        items->size++;
    }
}

void *removeSLL(SLL *items, int index) {

    if(debugSLL) printf("_SLL - removing from SLL\n");

    NODE *n;

    assert(items->size > 0 && index >= 0 && index < items->size);

    void *value = 0;

    if(index == 0) {
        if(debugSLL) printf("_SLL - - removing first node\n");
        n = items->head;
        value = getNODEvalue(n);
        NODE *next = getNODEnext(n);
        free(n);
        items->head = next;
        items->size--;
        if(items->size == 0)items->tail = 0;
    }
    else{
        if(debugSLL) printf("_SLL - - removing node in middle/end\n");
        NODE *b4 = getNodeBefore(items, index);
        n = getNODEnext(b4);
        value = getNODEvalue(n);
        setNODEnext(b4, getNODEnext(n));
        free(n);
        items->size--;
    }
    return value;
}

void unionSLL(SLL *recipient, SLL *donor) {
    if(debugSLL) printf("_SLL - starting a union\n");

    if(recipient->size == 0) {
        if(debugSLL) printf("_SLL - - recipient size is 0 linking head to head\n");
        recipient->head = donor->head;
        recipient->tail = donor->tail;
    }
    else {
        setNODEnext(recipient->tail, donor->head);
        recipient->tail = donor->tail;
    }
    recipient->size += donor->size;
    donor->head = donor->tail = 0;
    donor->size = 0;
}

void *getSLL (SLL *items, int index) {
    assert(index >= 0 && index < items->size);
    if(index == 0) {
        if(debugSLL) printf("_SLL - getting index 0\n");
        return getNODEvalue(items->head);
    }
    else if(index == items->size-1) {
        return getNODEvalue(items->tail);
    }
    else {
        //returns the value of the next node from the node before the index
        return getNODEvalue(getNODEnext(getNodeBefore(items, index)));
    }
}

void *setSLL (SLL *items, int index, void *value) {
    assert(index >= 0 && index <= items->size);
    void *data = 0;
    if(index == items->size) {
        insertSLL(items, index, value);
    }
    else if (index == 0){
        data = getNODEvalue(items->head);
        setNODEvalue(items->head, value);
    }
    else {
        NODE *n = getNODEnext(getNodeBefore(items, index));
        data = getNODEvalue(n);
        setNODEvalue(n, value);
    }
    return data;
}

int sizeSLL (SLL *items) {
    return items->size;
}

void displaySLL (SLL *items, FILE *fp) {
    printf("{");
    NODE *n = items->head;
    for (int x = 0; x < items->size; x ++){
        if (x > 0) printf(",");
        items->display(getNODEvalue(n), fp);
        n = getNODEnext(n);
    }
    printf("}");
}

void displaySLLdebug(SLL *items, FILE *fp){
    printf("head->");
    displaySLL(items, fp);
    printf(",tail->{");
    if(items->tail != 0)items->display(getNODEvalue(items->tail), fp);
    printf("}");
}

void freeSLL (SLL *items) {
    NODE *n = items->head;
    NODE *next = 0;
    if(items->size > 1) next = getNODEnext(n);
    while (n != 0) {
        freeNODE(n, items->free);
        n = next;
        if(n != 0)next = getNODEnext(n);
    }
    free(items);
}