#ifndef __NODE_INCLUDED__
#define __NODE_INCLUDED__

#include <stdio.h>

typedef struct node NODE; /* forward declaration of our structure */

extern NODE  *newNODE(void *value,NODE *next);     /* constructor */
extern NODE *newNODEdll (void *v, NODE *n, NODE *l); /*constructor*/
extern void  *getNODEvalue(NODE *n);
extern NODE  *getNODEnext(NODE *n);
extern NODE *getNODElast(NODE *n);
extern void  setNODEvalue(NODE *n,void *);
extern void  setNODEnext(NODE *n,NODE *);
extern void setNODElast(NODE *n, NODE *p);
extern void  displayNODE(NODE *n,FILE *fp,void (*display)(FILE *,void *));
extern void  displayNODEdebug(NODE *n,FILE *fp,void (*display)(FILE *,void *));
extern void  freeNODE(NODE *n,void (*release)(void *));

#endif
