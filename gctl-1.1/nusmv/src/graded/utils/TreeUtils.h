#ifndef _TREEDUTILS_

#define _TREEDUTILS_

#include "fsm/bdd/bdd.h"

typedef struct adjList *adjList_ptr;
typedef struct treeNode *treeNode_ptr;

typedef struct adjList{
       adjList_ptr next;
       treeNode_ptr nodo;
} adjList;

typedef struct treeNode{
       BddStates stato;
       BddInputs input;
       adjList_ptr lista;
} treeNode;


#endif




EXTERN treeNode_ptr TreeUtils_treeNodeCreate ARGS((BddStates, BddInputs));
EXTERN void TreeUtils_concat ARGS((treeNode_ptr, treeNode_ptr));

EXTERN BddStates TreeUtils_getStato ARGS((treeNode_ptr));
EXTERN BddInputs TreeUtils_getInput ARGS((treeNode_ptr));

EXTERN adjList_ptr TreeUtils_getListaFigli ARGS((treeNode_ptr));
EXTERN adjList_ptr TreeUtils_getNext ARGS((adjList_ptr));
EXTERN treeNode_ptr TreeUtils_getNodo ARGS((adjList_ptr));

EXTERN void TreeUtils_freeNodo ARGS((treeNode_ptr));