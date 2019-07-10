#include "GradedUtils.h"

/******************************************************************************
    Utilities for bdd and add
******************************************************************************/

node_ptr GradedUtils_nodePlus(node_ptr n1, node_ptr n2, node_ptr k)
{ 
    nusmv_ptrint n1_int, n2_int, k_int;
         
    if (node_get_type(n1) == FAILURE) return n1; /* error in previous expr */
    if (node_get_type(n2) == FAILURE) return n2; /* error in previous expr */
    if (node_get_type(k) == FAILURE) return k; /* error in previous expr */
    
    n1_int = NODE_TO_INT(car(n1));
    n2_int = NODE_TO_INT(car(n2));
    k_int = NODE_TO_INT(car(k));
    
    if (n1_int > (k_int - n2_int))
	    return find_node(NUMBER, NODE_FROM_INT(k_int), Nil);

    return find_node(NUMBER, NODE_FROM_INT(n1_int + n2_int), Nil);

}

node_ptr GradedUtils_nodeTimes(node_ptr n1, node_ptr n2, node_ptr k)
{ 
    nusmv_ptrint n1_int, n2_int, k_int;
    
    if (node_get_type(n1) == FAILURE) return n1; /* error in previous expr */
    if (node_get_type(n2) == FAILURE) return n2; /* error in previous expr */
    if (node_get_type(k) == FAILURE) return k; /* error in previous expr */

    n1_int = NODE_TO_INT(car(n1));
    n2_int = NODE_TO_INT(car(n2));
    k_int = NODE_TO_INT(car(k));
    
    if ((n1_int>0 && n2_int>0) && (n1_int> k_int / n2_int ))
	    return find_node(NUMBER,  NODE_FROM_INT(k_int), Nil);

    return find_node(NUMBER, NODE_FROM_INT(n1_int * n2_int), Nil);
}


DdNode * GradedUtils_addApply(DdManager *dd, ptruint op, DdNode *f, DdNode *g, int k)
{
	DdNode *res;
	add_ptr add_k = add_leaf(dd, find_node(NUMBER, NODE_FROM_INT(k), Nil));
	do {
		dd->reordered = 0;
		res = GradedUtils_addApplyRecur(dd, op, f, g, add_k);
	} while (dd->reordered == 1);
	
		//common_error(res, "GradedUtils_addApply: result = NULL");
	Cudd_Ref(res);
	
	return(res);
} 


DdNode * GradedUtils_addApplyRecur(DdManager *dd, ptruint op, DdNode *f, DdNode *g, DdNode *k)
{
	DdNode *res,
	*fv, *fvn, *gv, *gvn,
	*T, *E;
	unsigned int ford, gord;
	unsigned int index;

    /*
	Check for terminals. If it's the case then "op" is applied to
	the operands f and gmay swap f and g.
    */
	if(cuddIsConstant(f) && cuddIsConstant(g)){
		CUDD_VALUE_TYPE res_n;

		if (op == DD_ADD_NODE_PLUS_TAG)
			res_n = GradedUtils_nodePlus(cuddV(f), cuddV(g), cuddV(k));
		else
			res_n = GradedUtils_nodeTimes(cuddV(f), cuddV(g), cuddV(k));
		if (res_n == NULL) return(NULL);
		
		return(cuddUniqueConst(dd,res_n));
	}

	/* Check cache */
	//res = cuddCacheLookup(dd,(ptruint)(op),f,g,k);
	res = GradedUtils_cacheLookup3(dd, (ptruint)(op), f, g, k);
	if (res != NULL) return(res);

	/* Recursive Step */
	
	ford = Cudd_ReadPerm(dd,f->index);
	gord = Cudd_ReadPerm(dd,g->index);
	if (ford <= gord) {
		index = f->index;
		fv = cuddT(f);
		fvn = cuddE(f);
	} else {
		index = g->index;
		fv = fvn = f;
	}
	if (gord <= ford) {
		gv = cuddT(g);
		gvn = cuddE(g);
	} else {
		gv = gvn = g;
	}

	T = GradedUtils_addApplyRecur(dd, op, fv, gv, k);
	if (T == NULL) return(NULL);
	cuddRef(T);

	E = GradedUtils_addApplyRecur(dd, op, fvn, gvn, k);
	if (E == NULL) {
		Cudd_RecursiveDeref(dd,T);
		return(NULL);
	}
	cuddRef(E);

	/* Necessary to have ROBDD */
	res = (T == E) ? T : cuddUniqueInter(dd,(int)index,T,E);
	if (res == NULL) {
		Cudd_RecursiveDeref(dd, T);
		Cudd_RecursiveDeref(dd, E);
		return(NULL);
	}
	cuddDeref(T);
	cuddDeref(E);

	/* Store result */
	//cuddCacheInsert(dd,(ptruint)(op),f,g,k,res);
	GradedUtils_cacheInsert3((ptruint)(op), f, g, k, res);


	return(res);

}



DdNode * GradedUtils_addAbstract(DdManager* dd, add_ptr a, bdd_ptr b, int k)
{
	DdNode * cube;
	DdNode *res;
	add_ptr add_k = add_leaf(dd, find_node(NUMBER, NODE_FROM_INT(k), Nil));
  
	cube = Cudd_BddToAdd(dd, (DdNode *)b);
	//common_error(cube, "add_exist_abstract: cube = NULL");
	Cudd_Ref(cube);
	/**********************************************************/
	

	do {
		dd->reordered = 0;
		res = GradedUtils_addAbstractRecur(dd, DD_ADD_NODE_PLUS_TAG, (DdNode *)a, cube, add_k);
	} while (dd->reordered == 1);
	
	//common_error(res, "add_exist_abstract: result = NULL");
	
	Cudd_Ref(res);
	
	return(res);
}

DdNode * GradedUtils_addAbstractRecur(DdManager * manager, ptruint op, DdNode * f, DdNode * cube, DdNode *k)
{
	DdNode	*T, *E, *res, *res1, *res2, *zero;

	statLine(manager);
	zero = DD_ZERO(manager);

	/* Cube is guaranteed to be a cube at this point. */	
	if (f == zero || cuddIsConstant(cube)) {  
		return(f);
	}

	/* Abstract a variable that does not appear in f */
	if (Cudd_ReadPerm(manager,f->index) > Cudd_ReadPerm(manager,cube->index)) {
		res1 = GradedUtils_addAbstractRecur(manager, op, f, cuddT(cube), k);
		if (res1 == NULL) return(NULL);
		cuddRef(res1);
	/* Use the "internal" procedure to be alerted in case of
		** dynamic reordering. If dynamic reordering occurs, we
		** have to abort the entire abstraction.
	*/
		res = GradedUtils_addApplyRecur(manager, op, res1, res1, k);
		if (res == NULL) {
			Cudd_RecursiveDeref(manager,res1);
			return(NULL);
		}
		cuddRef(res);
		Cudd_RecursiveDeref(manager,res1);
		cuddDeref(res);
		return(res);
	}

	if ((res = GradedUtils_cacheLookup3(manager, (ptruint)(op), f, cube, k)) != NULL) {
		return(res);
	}

	T = cuddT(f);
	E = cuddE(f);

	/* If the two indices are the same, so are their levels. */
	if (f->index == cube->index) {
		res1 = GradedUtils_addAbstractRecur(manager, op, T, cuddT(cube), k);
		if (res1 == NULL) return(NULL);
		cuddRef(res1);
		res2 = GradedUtils_addAbstractRecur(manager, op, E, cuddT(cube), k);
		if (res2 == NULL) {
			Cudd_RecursiveDeref(manager,res1);
			return(NULL);
		}
		cuddRef(res2);
		res = GradedUtils_addApplyRecur(manager, op, res1, res2, k);
		if (res == NULL) {
			Cudd_RecursiveDeref(manager,res1);
			Cudd_RecursiveDeref(manager,res2);
			return(NULL);
		}
		cuddRef(res);
		Cudd_RecursiveDeref(manager,res1);
		Cudd_RecursiveDeref(manager,res2);
		//cuddCacheInsert(manager, (ptruint)(op), f, cube, k, res);
		GradedUtils_cacheInsert3((ptruint)(op), f, cube, k, res);

		cuddDeref(res);
		return(res);
	} else { /* if (cuddI(manager,f->index) < cuddI(manager,cube->index)) */
		res1 = GradedUtils_addAbstractRecur(manager, op, T, cube, k);
		if (res1 == NULL) return(NULL);
		cuddRef(res1);
		res2 = GradedUtils_addAbstractRecur(manager, op, E, cube, k);
		if (res2 == NULL) {
			Cudd_RecursiveDeref(manager,res1);
			return(NULL);
		}
		cuddRef(res2);
		res = cuddUniqueInter(manager, (int) f->index, res1, res2);
		if (res == NULL) {
			Cudd_RecursiveDeref(manager,res1);
			Cudd_RecursiveDeref(manager,res2);
			return(NULL);
		}
		cuddDeref(res1);
		cuddDeref(res2);
		//cuddCacheInsert(manager, (ptruint)(op), f, cube, k, res);
		GradedUtils_cacheInsert3((ptruint)(op), f, cube, k, res);

		return(res);
	}	    

}

int GradedUtils_bddIsSubset(DdManager* dd, bdd_ptr a, bdd_ptr b) {
	bdd_ptr not_b = bdd_not(dd, b);
	bdd_ptr intersection = bdd_and(dd, a, not_b);
	int res = bdd_is_zero(dd, intersection);
	
	bdd_free(dd, not_b);
	bdd_free(dd, intersection);
	
	return res;
}

bdd_ptr GradedUtils_bddMinus(DdManager* dd, bdd_ptr a, bdd_ptr b) {
    bdd_ptr tmp1 = bdd_not(dd, b);
    bdd_ptr result = bdd_and(dd, a, tmp1);
    
    bdd_free(dd, tmp1);
    
    return result;
}


//non �pi utilizzata andrebbe eliminata
add_ptr GradedUtils_addComposition(DdManager* dd, add_ptr a, add_ptr b, int i) {
	add_ptr add_i = add_leaf(dd, find_node(NUMBER, NODE_FROM_INT(i), Nil));
	add_ptr tmp = add_apply(dd, node_times, a, add_i);
	add_ptr result = add_apply(dd, node_plus, tmp, b);
	
	add_free(dd, add_i);
	add_free(dd, tmp);
	
	return result;
}

void GradedUtils_addSum(DdManager* dd, add_ptr* a, add_ptr b, int k) {
	add_ptr tmp = GradedUtils_addApply(dd, DD_ADD_NODE_PLUS_TAG, *a, b, k);
	
    add_free(dd, *a);
			
    *a = add_dup(tmp);
    add_free(dd, tmp);
}

/**Function****************************************************************************
    Utilities for fsm transitions
******************************************************************************/

bdd_ptr GradedUtils_andTransition(BddFsm_ptr fsm, bdd_ptr states) {
	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);
	BddTrans_ptr transition = BddFsm_get_trans(fsm);
	ClusterList_ptr cluster_list = BddTrans_get_backward(transition);
	ClusterListIterator_ptr iterator = ClusterList_begin(cluster_list);
	
	bdd_ptr result = bdd_dup(states);
	
	while (!ClusterListIterator_is_end(iterator)) {
		Cluster_ptr cluster = ClusterList_get_cluster(cluster_list, iterator);
		bdd_ptr trans = Cluster_get_trans(cluster);		
		bdd_and_accumulate(dd, &result, trans);
		bdd_free(dd, trans);
		iterator = ClusterListIterator_next(iterator);
	}
	
	return result;
}

bdd_ptr GradedUtils_getCleanTransition(DdManager* dd, Cluster_ptr cluster) {
    bdd_ptr state_input_vars = Cluster_get_quantification_state_input(cluster);
    bdd_ptr state_vars = Cluster_get_quantification_state(cluster);
    bdd_ptr input_vars = bdd_forsome(dd, state_input_vars, state_vars);
    
    bdd_ptr transition = Cluster_get_trans(cluster);
    
    bdd_ptr result = bdd_forsome(dd, transition, input_vars);
    
    bdd_free(dd, state_input_vars);
    bdd_free(dd, state_vars);
    bdd_free(dd, input_vars);
    bdd_free(dd, transition);
    
    return result;
}


/**Function****************************************************************************
    Name:
        GradedUtils_euGetIntermediateSets
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        int         k       The grading constant
        
    Result:
        BddStates *          The list of the sets [E^{>j} \psi_1 U \psi_2] with 0<=j<=k
        
    Description:
        Given the sets f and g where \psi_1 and \psi_2 are true
        returns list of the sets [E^{>j} \psi_1 U \psi_2] with 0<=j<=k
        
*********************************************************************************/
BddStates * GradedUtils_euGetIntermediateSets(BddFsm_ptr fsm, BddStates f, BddStates g, int k) {
	BddStates *lista = ALLOC(BddStates, k+1);

	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);

	add_ptr count_paths, adding_paths;
	bdd_ptr contributors, contributors_tmp, old_contributors;
	int i;

	count_paths = add_zero(dd);
	
	contributors_tmp = (bdd_ptr) eu(fsm, f, g);
	contributors = BddEnc_apply_state_vars_mask_bdd(enc, contributors_tmp);
	bdd_free(dd, contributors_tmp);

	for (i=1; i<=k; i++) {
		old_contributors = bdd_dup(contributors);
		adding_paths = GradedUtils_fsmCountSuccessors(fsm, contributors, k+1);
		bdd_free(dd, contributors);
		GradedUtils_addSum(dd, &count_paths, adding_paths, k+1);
		add_free(dd, adding_paths);
		contributors = add_to_bdd_strict_threshold(dd, count_paths, i);
		GradedUtils_applyReachableAndMask(fsm, &contributors);
		bdd_and_accumulate(dd, &contributors, f);
		GradedUtils_fixPoint(fsm, &contributors, f);
		
		lista[i-1] = GradedUtils_bddMinus(dd, old_contributors, contributors);
		
		bdd_free(dd, old_contributors);
	}
	//if(k>0)
		lista[i-1] = contributors;
	/*else
		lista[0] = contributors;*/
	bdd_free(dd, contributors);
	add_free(dd, count_paths);
	
	return lista;

}

/**Function****************************************************************************
    Name:
        GradedUtils_egGetIntermediateSets
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi is true
        int         k       The grading constant
        
    Result:
        BddStates *         The list of the sets [E^{>j} G \psi] with 0<=j<=k
        
    Description:
        Given the set f where \psi is true
        returns list of the sets [E^{>j} G \psi] with 0<=j<=k
        
*********************************************************************************/
BddStates * GradedUtils_egGetIntermediateSets(BddFsm_ptr fsm, BddStates f, int k) {
	BddStates *lista = ALLOC(BddStates, k+1);

	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);

	add_ptr count_paths, adding_paths;
	bdd_ptr contributors, contributors_tmp, old_contributors;
	int i;

	count_paths = add_zero(dd);
	
	contributors_tmp = (bdd_ptr) eg(fsm, f);
	contributors = BddEnc_apply_state_vars_mask_bdd(enc, contributors_tmp);
	bdd_free(dd, contributors_tmp);

	for (i=1; i<=k; i++) {
		old_contributors = bdd_dup(contributors);
		adding_paths = GradedUtils_fsmCountSuccessors(fsm, contributors, k+1);
		bdd_free(dd, contributors);
		GradedUtils_addSum(dd, &count_paths, adding_paths, k+1);
		add_free(dd, adding_paths);
		contributors = add_to_bdd_strict_threshold(dd, count_paths, i);
		GradedUtils_applyReachableAndMask(fsm, &contributors);
		bdd_and_accumulate(dd, &contributors, f);
		GradedUtils_fixPoint(fsm, &contributors, f);
		
		lista[i-1] = GradedUtils_bddMinus(dd, old_contributors, contributors);
		
		bdd_free(dd, old_contributors);
	}
	//if(k>0)
	lista[i-1] = contributors;
	/*else
	lista[0] = contributors;*/
	bdd_free(dd, contributors);
	add_free(dd, count_paths);
	
	return lista;

}

/**Function****************************************************************************
    Name:
        GradedUtils_node_ptrToTreeNode_ptr
        
    Parameters:
        BddFsm_ptr  fsm     	Kripke structure to verify
        BddEnc_ptr  enc     	The coding of the Kripke
        node_ptr    path    	The path representing an execution trace
        BddInputs   inputRoot	The input for the path's root
        
    Result:
        treeNode_ptr        The Tree representing the same execution trace of path.
        
    Description:
        Given an execution trace "path" returns the same execution trace as a Tree.
        
*********************************************************************************/
treeNode_ptr GradedUtils_node_ptrToTreeNode_ptr(BddFsm_ptr fsm, BddEnc_ptr enc, node_ptr path, BddInputs inputRoot)
{
	DdManager* dd = BddEnc_get_dd_manager(enc);
	treeNode_ptr res, nodo;
	node_ptr exp = reverse(path);
	
	if (path == NODE_PTR(0)) {
		/* Trivially false */
		bdd_ptr one = bdd_one(dd);
		res = TreeUtils_treeNodeCreate(one, NIL(DdNode));
		bdd_free(dd, one);
	}
	else {
		res = TreeUtils_treeNodeCreate(BDD_STATES(car(exp)), inputRoot);
		nodo = res;
		exp = cdr(exp);
		while (exp != NODE_PTR(0)) {
			bdd_ptr input;
			bdd_ptr state;
			
			input = BDD_INPUTS(car(exp));
			exp = cdr(exp);
			state = BDD_STATES(car(exp)); 
                    
			TreeUtils_concat(nodo, TreeUtils_treeNodeCreate(state, input));
			adjList_ptr figli  = TreeUtils_getListaFigli(nodo);
			nodo = TreeUtils_getNodo(figli);
       
			exp = cdr(exp);
		}
	}
	return res;
}


void GradedUtils_stampaPathsRecur(BddFsm_ptr fsm, BddEnc_ptr enc, treeNode_ptr albero, int nStato, int* nTraccia, 
	      node_ptr nodo_stampa, node_ptr input_stampa, cycleInf_ptr cicli, node_ptr pathParziale)
{
	bdd_ptr stato, input;
	adjList_ptr figli;
	
	if (albero == NIL(treeNode))
	{
		printf("It's impossible to get the nex state\n");
		return ;
	}
	
	stato = TreeUtils_getStato(albero);
	input = TreeUtils_getInput(albero);
	figli = TreeUtils_getListaFigli(albero);
	
	node_ptr path;
	
	if(pathParziale != Nil)
	  path = cons((node_ptr) bdd_dup(stato),
			cons((node_ptr) bdd_dup(input), pathParziale));
	else
	  path = cons((node_ptr) bdd_dup(stato), Nil);
	//Stampa
	
	
	if (cicli[*nTraccia-1].stato == stato && cicli[*nTraccia-1].nStato > nStato)
	  printf("Loop starts here\n");
	else if (cicli[*nTraccia-1].nStato == nStato && !cicli[*nTraccia-1].sink)
	  printf("End loop\n");
	printf("-> Input: %d.%d <-\n", (*nTraccia), nStato);
	if(input != ((bdd_ptr) 0)) {
	  BddEnc_print_bdd_begin(enc, input_stampa, 1);
	  BddEnc_print_bdd(enc, input, nusmv_stdout);
	  BddEnc_print_bdd_end(enc);
	}

	printf("-> State: %d.%d <-\n", (*nTraccia), nStato);
	BddEnc_print_bdd(enc, stato, nusmv_stdout);
	
	nStato++;
	while  (figli != NIL(adjList))
	{
		treeNode_ptr figlio = TreeUtils_getNodo(figli);
		GradedUtils_stampaPathsRecur(fsm, enc, figlio, nStato, nTraccia, nodo_stampa, input_stampa, cicli, path);
		
		figli = TreeUtils_getNext(figli);
		if (figli != NIL(adjList))
		{
			//Quando si trova un non sink cycle occorre stampare una sola traccia. Tutte le altre sottotracce
			//differiscono solo per il numero di volte che si percorre il ciclo.
			if (cicli[*nTraccia-1].nStato != 0 && cicli[*nTraccia-1].nStato <=nStato && !cicli[*nTraccia-1].sink)
			  return;
		  
			(*nTraccia)++;
			
			printf("\n");
			BddEnc_print_bdd_end(enc);
			BddEnc_print_bdd_begin(enc, nodo_stampa, true);
			
			if (cicli[*nTraccia-1].nStato>0)
			{
			  node_ptr copiaPath = copy_list(path);
			  treeNode_ptr newRoot = (treeNode_ptr) GradedUtils_node_ptrToTreeNode_ptr(fsm, enc, copiaPath, NIL(DdNode));
			  
			  GradedUtils_stampaPathsRecur(fsm, enc, newRoot, 1, nTraccia, nodo_stampa, input_stampa, cicli, Nil);
			}
			
		}
	}
}

/**Function****************************************************************************
    Name:
        GradedUtils_stampaPaths
        
    Parameters:
        BddFsm_ptr  	fsm     Kripke structure to verify
        BddEnc_ptr  	enc     The coding of the Kripke
        treeNode_ptr    albero  The tree of the paths representing the execution traces to print
        
    Result:
        boolean		return 1 if the print operation is succesfully executed, 0 otherwise.
        
    Description:
        Given the tree of execution traces "albero" print it.
        
*********************************************************************************/
boolean GradedUtils_stampaPaths(BddFsm_ptr fsm, BddEnc_ptr enc, treeNode_ptr albero, cycleInf_ptr cicli)
{
	printf("Trace Type: Counterexample\n");
	if (albero == NIL(treeNode))
	{
		printf("Counterexample not computed\n");
		return 0;
	}
	
	int nTraccia = 1;
	array_t* layers = array_alloc(const char*, 1);
	int idx;
	SymbTable_ptr st = BaseEnc_get_symbol_table(BASE_ENC(enc));
	char* name;
	boolean found = false;
	
	arrayForEachItem(const char*, layers, idx, name){
		if (name == (const char*) NULL) {
			array_insert(const char*, layers, idx, util_strsav((char*) MODEL_LAYER_NAME));
			found = true;
			break;
		}
	}
	
	if(!found)
		array_insert_last(const char*, layers, util_strsav((char*) MODEL_LAYER_NAME));
	
	
	NodeList_ptr svars = SymbTable_get_layers_state_symbols(st, layers);
	NodeList_ptr i_symbs = SymbTable_get_layers_input_symbols(st, layers);
	
	node_ptr nodo_stampa = NodeList_to_node_ptr(svars);
	node_ptr input_stampa = NodeList_to_node_ptr(i_symbs);
	BddEnc_print_bdd_begin(enc, nodo_stampa, true);
	node_ptr pathParziale = Nil;
	GradedUtils_stampaPathsRecur(fsm, enc, albero, 1, &nTraccia, nodo_stampa, input_stampa, cicli, pathParziale);
	BddEnc_print_bdd_end(enc);
	
	NodeList_destroy(svars);
}



void GradedUtils_findCycleRecur(BddFsm_ptr fsm, BddEnc_ptr enc, DdManager *dd, treeNode_ptr albero, 
        bdd_ptr visitedStates, int* nTraccia, int nStato, cycleInf_ptr cicli)
{
	bdd_ptr stato;
	adjList_ptr figli;
	
	if (albero == NIL(treeNode))
	{
		printf("It's impossible to get the nex state\n");
		return ;
	}
	
	stato = TreeUtils_getStato(albero);
	figli = TreeUtils_getListaFigli(albero);
	
    bdd_ptr oldVisited = bdd_dup(visitedStates);

    bdd_or_accumulate(dd, &visitedStates, stato);
	
    if (bdd_is_one(dd, (bdd_ptr) GradedMc_iff(fsm, oldVisited, visitedStates)))
    {
       cicli[*nTraccia-1].nStato = nStato;
       cicli[*nTraccia-1].stato = stato;
       if (figli == NIL(adjList))
       {
          //sink cycle
          cicli[*nTraccia-1].sink = true;
       }
       else
       {
          //non sink cycle
	  
          cicli[*nTraccia-1].sink = false;
       }
    }
    //bdd_free(dd, oldVisited);
    
    nStato++;
	while  (figli != NIL(adjList))
	{
		treeNode_ptr figlio = TreeUtils_getNodo(figli);
		GradedUtils_findCycleRecur(fsm, enc, dd, figlio, visitedStates, nTraccia, nStato, cicli);
		
		figli = TreeUtils_getNext(figli);
		if (figli != NIL(adjList))
		{
			(*nTraccia)++;
		}
	}
}


/**Function****************************************************************************
    Name:
        GradedUtils_findCycles
        
    Parameters:
        BddFsm_ptr  	fsm     Kripke structure to verify
        BddEnc_ptr  	enc     The coding of the Kripke
        treeNode_ptr    albero  The tree of the paths representing the execution traces where 
        we need to search a cycle.
        
    Result:
        boolean		return 1 if it find a cycle, 0 otherwise.
        
    Description:
        Given the tree of execution traces "albero", search for a cycle in it.
        
*********************************************************************************/
void GradedUtils_findCycle(BddFsm_ptr fsm, BddEnc_ptr enc, treeNode_ptr albero, cycleInf_ptr cicli)
{
    DdManager *dd = BddEnc_get_dd_manager(enc);
	if (albero == NIL(treeNode))
	{
		printf("Counterexample not computed\n");
		return;
	}
	bdd_ptr visitedStates = bdd_zero(dd);
	int nTraccia = 1;
	
	GradedUtils_findCycleRecur(fsm, enc, dd, albero, visitedStates, &nTraccia, 1, cicli);
	//bdd_free(dd, visitedStates);
	return;
}



void GradedUtils_countTraces(BddFsm_ptr fsm, BddEnc_ptr enc, treeNode_ptr albero, int* nTraccia)
{
	adjList_ptr figli;
	
	if (albero == NIL(treeNode))
	{		
		return ;
	}
	
	figli = TreeUtils_getListaFigli(albero);
  
	while  (figli != NIL(adjList))
	{
		treeNode_ptr figlio = TreeUtils_getNodo(figli);
		GradedUtils_countTraces(fsm, enc, figlio, nTraccia);
		
		figli = TreeUtils_getNext(figli);
		if (figli != NIL(adjList))
		{
			(*nTraccia)++;
		}
	}
}



/**Function****************************************************************************
    Utilities for fsm states
******************************************************************************/

/*

Nome: GradedUtils_fsmCountSuccessors

Descrizione:
	Data una macchina a stati finiti con insieme di stati S e funzione di transizione T ed un sottoinsieme X di S, questa funzione calcola
	il numero di successori che ogni stato di S ha in X secondo la funzione di transizione T.

Lista dei parametri:
	BddFsm_ptr	fsm		Macchina a stati finiti di cui contare i successori
	bdd_ptr		states		L'insieme degli stati in cui contare i successori

Tipo di ritorno:
	add_ptr		Un add che rappresenta il numero di successori che ogni stato della fsm ha nell'insieme states
*/

add_ptr GradedUtils_fsmCountSuccessors(BddFsm_ptr fsm, bdd_ptr states, int k) {
	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);
	BddTrans_ptr trans = BddFsm_get_trans(fsm);	
	ClusterList_ptr cluster_list = BddTrans_get_backward(trans);
	
	bdd_ptr primed_states;
	add_ptr transition, result;
	ClusterListIterator_ptr iter;
	Cluster_ptr cluster;
	int i=0;
	
	primed_states = BddEnc_state_var_to_next_state_var(enc, states);
	result = bdd_to_add(dd, primed_states);
	bdd_free(dd, primed_states);
	
	bdd_ptr sum_variable = bdd_one(dd);
	iter = ClusterList_begin(cluster_list);
	while ( ! ClusterListIterator_is_end(iter) ) {
		cluster = ClusterList_get_cluster(cluster_list, iter);
		
		{
			bdd_ptr tmp1 = GradedUtils_getCleanTransition(dd, cluster);
			//GradedUtils_applyReachableAndMaskToBackTransitions(fsm, &tmp1);
			transition = bdd_to_add(dd, tmp1);						
			bdd_free(dd, tmp1);
		}
		
		{
			//add_ptr tmpb = GradedUtils_addApply(dd, DD_ADD_NODE_TIMES_TAG, result, transition, k);
						
			bdd_ptr cur_var = Cluster_get_quantification_state(cluster);
			bdd_ptr state_vars_primed = bdd_forsome(dd, cur_var, sum_variable);
			
			//add_ptr tmp_result = GradedUtils_addAbstract(dd, tmpb, state_vars_primed, k);
						
			add_ptr tmp_result = GradedUtils_AddAndAbstract(dd, result, transition, state_vars_primed, k);
			add_free(dd, result);
			result = add_dup(tmp_result);
			
			bdd_and_accumulate(dd, &sum_variable, state_vars_primed);
			
			add_free(dd, tmp_result);
			bdd_free(dd, cur_var);
			bdd_free(dd, state_vars_primed);
			add_free(dd, transition);
		}
		
		iter = ClusterListIterator_next(iter); 
	} /* iteration */
	
	/*bdd_ptr primed_vars = BddEnc_get_next_state_vars_cube(enc);
	result = GradedUtils_addAbstract(dd, result, primed_vars, k);*/
	
	bdd_free(dd, sum_variable);
	return result;
}


void GradedUtils_fixPoint(BddFsm_ptr fsm, bdd_ptr* states, bdd_ptr valid) {
	BddTrans_ptr transition = BddFsm_get_trans(fsm);
	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);
	
	BddStates backward_tmp,backward;
	bdd_ptr actual = bdd_dup(*states);
	
	while (1) {
		//backward_tmp = BddFsm_get_backward_image(fsm, actual);
		backward_tmp = (BddStates)ex(fsm, actual);
		backward = BddEnc_apply_state_vars_mask_bdd(enc,backward_tmp);
		bdd_free(dd, backward_tmp);
		bdd_and_accumulate(dd, &backward, valid);
		
		if (GradedUtils_bddIsSubset(dd, backward, actual)) {
			bdd_free(dd, backward);
			bdd_free(dd, *states);
			*states = bdd_dup(actual);
			bdd_free(dd, actual);
			return;
		} else {
			bdd_or_accumulate(dd, &actual, backward);
			bdd_free(dd, backward);
		}
	}
}

void GradedUtils_applyReachableAndMask(BddFsm_ptr fsm, bdd_ptr* states) {
	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);
	BddStates reachable;
	bdd_ptr tmp;
	
	tmp = BddFsm_get_reachable_states(fsm);
	reachable = BddEnc_apply_state_vars_mask_bdd(enc, tmp);
	bdd_free(dd, tmp);
	
	bdd_and_accumulate(dd, states, reachable);
	
	tmp = BddEnc_apply_state_vars_mask_bdd(enc, *states);
	
	/*Modifica effettuata da Maurizio Memoli*/
	
	bdd_free(dd, *states);
	
	/****************************************/
	*states = bdd_dup(tmp);
	
	bdd_free(dd, tmp);
	bdd_free(dd, reachable);
}

void GradedUtils_applyReachableAndMaskToBackTransitions(BddFsm_ptr fsm, bdd_ptr* transition) {
	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);
	
	{
		//bdd_ptr tmp = BddFsm_get_reachable_states(fsm);
		//bdd_ptr reachable = BddEnc_apply_state_vars_mask_bdd(enc, tmp);
		bdd_ptr reachable = BddFsm_get_reachable_states(fsm);
		//bdd_ptr primed_reachable = BddEnc_state_var_to_next_state_var(enc, reachable);
		//bdd_free(dd, tmp);

		bdd_and_accumulate(dd, transition, reachable);
		//bdd_and_accumulate(dd, transition, primed_reachable);
	
		bdd_free(dd, reachable);
		//bdd_free(dd, primed_reachable);
	}
	
	{
		bdd_ptr mask = BddEnc_get_state_vars_mask_bdd(enc);
		//bdd_ptr primed_mask = BddEnc_state_var_to_next_state_var(enc, mask);
		
		bdd_and_accumulate(dd, transition, mask);
		//bdd_and_accumulate(dd, transition, primed_mask);
		
		bdd_free(dd, mask);
		//bdd_free(dd, primed_mask);
	}
}

BddStates GradedUtils_getKBackwardImage(const BddFsm_ptr fsm, BddStates states, int k) {
	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager*  dd = BddEnc_get_dd_manager(enc);
   	BddStates invar = BddFsm_get_state_constraints(fsm);
	bdd_ptr result = bdd_zero(dd);
	
	BDD_FSM_CHECK_INSTANCE(fsm);
	
	//printf("Numero di stati in states: %f\n", BddEnc_count_states_of_bdd(enc, states));
	{
		/*bdd_ptr tmp1 = BddFsm_get_init(fsm);
		bdd_ptr tmp2 = BddFsm_get_forward_image(fsm, tmp1);
		bdd_ptr tmp3 = bdd_and(dd, tmp2, states);*/
		
		//printf("Numero di stati ininiziali: %f\n", BddEnc_count_states_of_bdd(enc, tmp1));
		//printf("Numero di stati successivi dello stato iniziale: %f\n", BddEnc_count_states_of_bdd(enc, tmp2));
		/*dd_printminterm(dd, tmp2);
		BddEnc_print_set_of_states(enc, tmp2, 1, stdout);*/
		//printf("Numero di stati in tmp3: %f\n", BddEnc_count_states_of_bdd(enc, tmp3));
		/*dd_printminterm(dd, tmp3);
		BddEnc_print_set_of_states(enc, tmp3, 1, stdout);*/
		/*bdd_free(dd, tmp1);
		bdd_free(dd, tmp2);
		bdd_free(dd, tmp3);*/
	}
	
	{
		bdd_ptr tmp1 = bdd_and(dd, states, invar);
		bdd_ptr tmp2 = BddEnc_apply_state_vars_mask_bdd(enc, tmp1);
		add_ptr tmp3 = GradedUtils_fsmCountSuccessors(fsm, tmp2, k+1);
	
        	result = add_to_bdd_strict_threshold(dd, tmp3, k);
        
		bdd_free(dd, tmp1);
		bdd_free(dd, tmp2);
		add_free(dd, tmp3);
	}
		
	bdd_and_accumulate(dd, &result, invar);
	bdd_free(dd, invar);
	
	return (result);
}


/**Function********************************************************************

  Synopsis [Picks one on-set minterm deterministically from the given DD.]

  Description [Picks one on-set minterm deterministically from the
  given DD. The minterm is in terms of vars. Builds a BDD for the
  minterm and returns a pointer to it if successful; NULL
  otherwise. There are two reasons why the procedure may fail: It may
  run out of memory; or the function f may be the constant 0.]

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
DdNode *
GradedUtils_bddPickOneMintermNR(
DdManager *dd,
DdNode *f,
DdNode **vars,
int n)
{
    char *string;
    int i, size;
    int *indices;
    int result;
    DdNode *zero, *old, *new;

    size = dd->size;
    string = ALLOC(char, size);
    if (string == NULL)
	return(NULL);
    indices = ALLOC(int,n);
    if (indices == NULL) {
	FREE(string);
	return(NULL);
    }

    for (i = 0; i < n; i++) {
        indices[i] = vars[i]->index;
    }

    result = Cudd_bddPickOneCubeNR(dd,f,string);
    if (result == 0) {
	FREE(string);
	FREE(indices);
	return(NULL);
    }

    /*
      Don't cares always set to 0.
      A cube is represented as an array of literals, which are integers in
      {0, 1, 2}; 0 represents a complemented literal, 1 represents an
      uncomplemented literal, and 2 stands for don't care.
    */
    for (i = 0; i < n; i++) {
      if (string[indices[i]] == 2) {
        /* For dont care we choose false */
        string[indices[i]] = 0;
      }
    }

    /* Build result BDD. */
    old = Cudd_ReadOne(dd);
    cuddRef(old);
    zero = Cudd_Not(Cudd_ReadOne(dd));

    for (i = 0; i < n; i++) {
	if (string[indices[i]] == 0) {
	    new = Cudd_bddIte(dd,old,Cudd_Not(vars[i]),zero);
	} else {
	    new = Cudd_bddIte(dd,old,vars[i],zero);
	}
	if (new == NULL) {
	    FREE(string);
	    FREE(indices);
	    Cudd_RecursiveDeref(dd,old);
	    return(NULL);
	}
	cuddRef(new);
	Cudd_RecursiveDeref(dd,old);
	old = new;
    }

    /* Test. */
    //if (Cudd_bddLeq(dd,old,f)) {
	cuddDeref(old);
    /*} else {
	Cudd_RecursiveDeref(dd,old);
	old = NULL;
    }*/

    FREE(string);
    FREE(indices);
    return(old);

}  /* end of GradedUtils_bddPickOneMintermNR */

/**Function********************************************************************

  Synopsis [Picks one on-set minterm deterministically from the given BDD.]

  Description [Picks one on-set minterm deterministically from the
  given DD. The minterm is in terms of vars. Builds a BDD for the
  minterm and returns a pointer to it if successful; a failure is
  generated otherwise. There are two reasons why the procedure may fail: It may
  run out of memory; or the function fn may be the constant 0. The
  result is referenced.]

  SideEffects []

******************************************************************************/
bdd_ptr GradedUtils_bddPickOneState(const BddEnc_ptr enc, bdd_ptr fn)
{
  DdNode * result;
  DdNode ** vars;
  DdManager*  dd = BddEnc_get_dd_manager(enc);


  if (bdd_is_zero(dd, fn)) {
    Cudd_Ref(fn);
    return(fn);
  }
  else {
    vars = array_fetch_p(bdd_ptr, enc->minterm_state_vars, 0);
    int n = enc->minterm_state_vars_dim;
    result = GradedUtils_bddPickOneMintermNR(dd, (DdNode *)fn, vars, n);
    //common_error(result, "GradedUtils_bddPickOneMintermNR: result = NULL");
    Cudd_Ref(result);
    return((bdd_ptr)result);
  }
}

/**Function********************************************************************

  Synopsis [Takes the * of two ADDs and simultaneously abstracts the
  variables in cube.]

  Description [Takes the * of two ADDs and simultaneously abstracts
  the variables in cube. The variables are existentially abstracted.
  Returns a pointer to the result is successful; NULL otherwise.]

  SideEffects [None]

  SeeAlso     [GradedUtils_AddAndAbstract]

******************************************************************************/

DdNode *
GradedUtils_AddAndAbstractRecur(
  DdManager * manager,
  DdNode * f,
  DdNode * g,
  DdNode * cube,
  DdNode * k)
{

    DdNode *ft, *fe,*gt, *ge;
    DdNode *r, *t, *e;
    unsigned int topf, topg, topcube, top, index;

    statLine(manager);
	
	
	
	
    topf = Cudd_ReadPerm(manager, f->index);
    topg = Cudd_ReadPerm(manager, g->index);
    top = ddMin(topf, topg);
    topcube = Cudd_ReadPerm(manager, cube->index);

    if (topcube < top) {

	/*cube = cuddT(cube);
	if (cuddIsConstant(cube)) {
	    return(GradedUtils_addApplyRecur(manager, DD_ADD_NODE_TIMES_TAG, f, g, k));
	}

	topcube = Cudd_ReadPerm(manager, cube->index);*/
	add_ptr res1 = GradedUtils_AddAndAbstractRecur(manager, f, g, cuddT(cube), k);
	if (res1 == NULL) return NULL;
	cuddRef(res1);
	
	r = GradedUtils_addApplyRecur(manager, DD_ADD_NODE_PLUS_TAG, res1, res1, k);
	if (r == NULL) {
	  Cudd_RecursiveDeref(manager, res1);
	  return NULL;
	}
	cuddRef(r);
	Cudd_RecursiveDeref(manager, res1);
	cuddDeref(r);
	return r;
    }
    
    /*
	Check for terminals. If it's the case then the TIMES operator is applied to
	the operands f and g.    
	*/
	if(cuddIsConstant(f) && cuddIsConstant(g)){
		CUDD_VALUE_TYPE res_n;
		res_n = GradedUtils_nodeTimes(cuddV(f), cuddV(g), cuddV(k));	
		if (res_n == NULL) return(NULL);
		
		return(cuddUniqueConst(manager,res_n));
	}
    
	/* Check cache */
	r = GradedUtils_cacheLookup4(manager, (ptruint)(DD_ADD_NODE_ANDABSTRACT_TAG),f,g,cube,k);
	//r = cuddCacheLookup(manager,(ptruint)(DD_ADD_NODE_ANDABSTRACT_TAG),f,g,cube);
	if (r != NULL) return(r);
    
    
    /* Now, topcube >= top. */


    if (topf == top) {
	index = f->index;
	ft = cuddT(f);
	fe = cuddE(f);
    } else {
	index = g->index;
	ft = fe = f;
    }

    if (topg == top) {
	gt = cuddT(g);
	ge = cuddE(g);
    } else {
	gt = ge = g;
    }
	


    if (topcube == top) {	/* quantify */
		DdNode *Cube = cuddT(cube);
	
		t = GradedUtils_AddAndAbstractRecur(manager, ft, gt, Cube, k);
		if (t==NULL) return NULL;
		cuddRef(t);
		
		e = GradedUtils_AddAndAbstractRecur(manager, fe, ge, Cube, k);
		if (e==NULL) {
			Cudd_RecursiveDeref(manager, t);
			return(NULL);
		}
		
		cuddRef(e);
		r = GradedUtils_addApplyRecur(manager, DD_ADD_NODE_PLUS_TAG, t, e, k);
		if (r == NULL) {
			Cudd_RecursiveDeref(manager,t);
			Cudd_RecursiveDeref(manager,e);
			return(NULL);
		}
		cuddRef(r);
		Cudd_RecursiveDeref(manager,t);
		Cudd_RecursiveDeref(manager,e);
		GradedUtils_cacheInsert4((ptruint)(DD_ADD_NODE_ANDABSTRACT_TAG), f, g, cube, k, r);
		//cuddCacheInsert(manager,(ptruint)(DD_ADD_NODE_ANDABSTRACT_TAG),f,g,cube,r);
		cuddDeref(r);
		return(r);
	
    } else {
	
		t = GradedUtils_AddAndAbstractRecur(manager, ft, gt, cube, k);
		if (t == NULL) return(NULL);
		cuddRef(t);
		e = GradedUtils_AddAndAbstractRecur(manager, fe, ge, cube, k);
		if (e == NULL) {
			Cudd_RecursiveDeref(manager,t);
			return(NULL);
		}
		cuddRef(e);
		r = cuddUniqueInter(manager, (int) index, t, e);
		if (r == NULL) {
			Cudd_RecursiveDeref(manager,t);
			Cudd_RecursiveDeref(manager,e);
			return(NULL);
		}
		cuddDeref(t);
		cuddDeref(e);
		GradedUtils_cacheInsert4((ptruint)(DD_ADD_NODE_ANDABSTRACT_TAG), f, g, cube, k, r);
		//cuddCacheInsert(manager,(ptruint)(DD_ADD_NODE_ANDABSTRACT_TAG),f,g,cube,r);
		return(r);
	
    }


}


/**Function********************************************************************

  Synopsis [Takes the * of two ADDs and simultaneously abstracts the
  variables in cube.]

  Description [Takes the * of two ADDs and simultaneously abstracts
  the variables in cube. The variables are existentially abstracted.
  Returns a pointer to the result is successful; NULL otherwise.]

  SideEffects [None]

  SeeAlso     [GradedUtils_AddAndAbstractRecur]

******************************************************************************/
DdNode * GradedUtils_AddAndAbstract(
  DdManager * manager,
  DdNode * f,
  DdNode * g,
  DdNode * cube,
  int k
)
{
    DdNode *res;
    add_ptr add_k = add_leaf(manager, find_node(NUMBER, NODE_FROM_INT(k), Nil));
    do {
	manager->reordered = 0;
	res = GradedUtils_AddAndAbstractRecur(manager, f, g, cube, add_k);
    } while (manager->reordered == 1);
    cuddRef(res);
    return(res);

} /* end of GradedUtils_AddAndAbstract */
