#include "TreeUtils.h"

treeNode_ptr TreeUtils_treeNodeCreate(BddStates stato, BddInputs input){
	treeNode_ptr nodo = (treeNode_ptr)malloc(sizeof(treeNode));
	if (stato != NIL(DdNode))
		Cudd_Ref(stato);
	if (input != NIL(DdNode))
		Cudd_Ref(input);
	nodo->stato = stato;
	nodo->input = input;
	nodo->lista = NIL(adjList);
	return nodo;
}


void TreeUtils_concat(treeNode_ptr radice, treeNode_ptr figlio){
	adjList_ptr lista = (adjList_ptr)malloc(sizeof(adjList));
	if (radice->lista == NIL(adjList))
		radice->lista = lista;
	else{
		adjList_ptr oldLista = radice->lista;
		
		while (oldLista->next != NIL(adjList))
		{
			oldLista = oldLista->next;
		}
		
		oldLista->next = lista;
	}
	
	lista->nodo = figlio;
	lista->next = NIL(adjList);
}


BddStates TreeUtils_getStato (treeNode_ptr nodo)
{
	return nodo->stato;
}


BddInputs TreeUtils_getInput (treeNode_ptr nodo)
{
	return nodo->input;
}


adjList_ptr TreeUtils_getListaFigli (treeNode_ptr nodo)
{
	return nodo->lista;
}


adjList_ptr TreeUtils_getNext (adjList_ptr lista)
{
	return lista->next;
}


treeNode_ptr TreeUtils_getNodo (adjList_ptr lista)
{
	return lista->nodo;
}


void TreeUtils_freeNodo (treeNode_ptr nodo)
{
	if (nodo->stato != NIL(DdNode))
		Cudd_Deref(nodo->stato);
	if (nodo->input != NIL(DdNode))
		Cudd_Deref(nodo->input);
	
	free(nodo->lista);
	free(nodo);	
}

