/**CFile***********************************************************************

  FileName    [Explain.c]

  PackageName [graded/mc]

  Synopsis    [Fair Graded-CTL model checking routines.]

  Description [Routines for the model checking of graded-CTL formulas.]

  SeeAlso     []

  Author      [Alessandro Ferrante, Maurizio Memoli]

 ******************************************************************************/

#include "Explain.h"

static char rcsid[] UTIL_UNUSED = "$Id: Explain.c,v 1.0 2008/12/05 07:46:01 nusmv Exp $";

/* Define this to enable trace explain debug */
/* #define EXPLAIN_TRACE_DEBUG */

/*---------------------------------------------------------------------------*/
/* Variable declarations                                                     */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Static function prototypes                                                */
/*---------------------------------------------------------------------------*/
/*static void GradedMc_explainRecurGraded ARGS((BddFsm_ptr, BddEnc_ptr enc, 
				    node_ptr, node_ptr, node_ptr, node_ptr**));*/

static node_ptr* GradedMc_extendTraceWithStateInputPairGraded ARGS((BddFsm_ptr fsm, 
                    BddEnc_ptr enc, node_ptr path, bdd_ptr starting_state,
                    bdd_ptr next_states, const char * comment));

static void GradedMc_checkTraceListSanity ARGS((BddEnc_ptr enc, node_ptr path,
                    const char * varname));

/*---------------------------------------------------------------------------*/
/* Definition of exported functions                                          */
/*---------------------------------------------------------------------------*/

/**Function********************************************************************

  Synopsis           [Counterexamples and witnesses generator.]

  Description        [This function takes as input a CTL formula and
  returns a witness showing how the given formula does not hold. The
  result consists of a list of states (i.e. an execution trace) that
  leads to a state in which the given formula does not hold.]

  SideEffects        []

  SeeAlso            [explain_recur ex_explain eu_explain eg_explain
  ebg_explain ebu_explain]

******************************************************************************/
/*node_ptr* GradedMc_explainGraded(BddFsm_ptr fsm, BddEnc_ptr enc, node_ptr path, 
                    node_ptr spec_formula, node_ptr context) {
    node_ptr** new_path = ALLOC(node_ptr*,1);
    GradedMc_explainRecurGraded(fsm, enc, path, spec_formula, context, new_path);
    return *new_path;
}*/


treeNode_ptr GradedMc_explainGraded(BddFsm_ptr fsm, BddEnc_ptr enc, BddStates radice,
                    node_ptr spec_formula, node_ptr context) {
    //treeNode_ptr radice = treeNodeCreate(path, NIL(DdNode));
    treeNode_ptr new_path = GradedMc_explainRecurGraded(fsm, enc, radice, spec_formula, context, false, false);

    return new_path;
}

/*---------------------------------------------------------------------------*/
/* Definition of internal functions                                          */
/*---------------------------------------------------------------------------*/

/**Function********************************************************************

  Synopsis           [This function computes a path that is a witness
                      for <i>EX(f)</i>.]

  Description        [This function finds a path that is a witness for
  <i>EX(f)</i>. <code>path<code> is a BDD which represents the first
  state of the path. It essentially is an initial state from which the
  example can be found.  The formula <i>EX(f)</i> holds under
  fairness constraints in a state <i>s_i</i> iff there is a
  successor state <i>s_{i+1}</i> such that <i>s_{i+1}</i>
  satisfies <i>f</i> and </i>s_{i+1}</i> is the beginning of some
  fair computation path. We look for states that can be reached from
  the state stored as first element in <code>path</code>, which are fair and
  in which <i>f</i> is satisfied. The algorithm computes more than
  one state, in order to have only one state we apply
  <code>bdd_pick_one_state</code>. The result of this application is
  then put in AND with <code>path</code> to form the witness.]

  SideEffects        []

  SeeAlso            [explain]

******************************************************************************/

treeNode_ptr GradedMc_exExplainGraded(BddFsm_ptr fsm, BddEnc_ptr enc, int k,
				      BddStates starting_state, BddInputs sInput, bdd_ptr f)
{
	if (! k){
	  node_ptr path = ex_explain(fsm, enc, cons((node_ptr) bdd_dup(starting_state), NODE_PTR(0)), f);
	  treeNode_ptr sottoAlbero = (treeNode_ptr) GradedUtils_node_ptrToTreeNode_ptr(fsm, enc, path, sInput);
	  
	  return sottoAlbero;
	}
	
	treeNode_ptr res = TreeUtils_treeNodeCreate(starting_state, sInput);
	bdd_ptr acc, image, mask;
	
	nusmv_assert( BddFsm_is_fair_states(fsm, starting_state) );
	image = BddFsm_get_forward_image(fsm, starting_state);

	GradedUtils_applyReachableAndMask(fsm, &image);
	
	acc = bdd_dup(f);
	
	if (opt_use_fair_states(options)) {
		bdd_ptr fair_states_bdd = BddFsm_get_fair_states(fsm);
		bdd_and_accumulate(dd_manager, &acc, fair_states_bdd);
		bdd_free(dd_manager, fair_states_bdd);
	}
	
	bdd_and_accumulate(dd_manager, &acc, image);
	bdd_free(dd_manager, image);
	
	if (! bdd_is_zero(dd_manager, acc)) {
		
		BddInputs inputs, input;
		int array_size = BddEnc_count_states_of_bdd(enc, acc);
		
		bdd_ptr* array = ALLOC(bdd_ptr, array_size);
		BddEnc_pick_all_terms_states(enc, acc, array, array_size);
		
		if (array_size> k+1)
			array_size = k + 1;
		
		int j=0;
		
		for (j=0; j < array_size; ++j) {			
			inputs = BddFsm_states_to_states_get_inputs(fsm, starting_state, array[j]);
			input = BddEnc_pick_one_input(enc, inputs);
			
			TreeUtils_concat(res, TreeUtils_treeNodeCreate(array[j], input));
		}
	}
	
	bdd_free(dd_manager, starting_state);
	bdd_free(dd_manager, acc);
	
	return res;
}


/**Function********************************************************************

  Synopsis           [This function finds a path that is a witness
                      for <i>E\[f U g\]</i>]

  Description [This function finds a path that is a witness for
  <i>E\[f U g\]</i>.  The first element of <code>path</code> is a BDD
  <code>p</code> that represents the first state of the witness
  path. It is an initial state from which the example can be
  found. The procedure is to try to execute <code>eu(f,g)</code>
  again, looking for a path from <code>p</code> to a state where
  <i>g</i> is valid. At each step we generate a set of states
  <i>s_i</i> that can be reached in one step from <i>s_{i-1}</i>. We
  extract one minterm form each <i>s_i</i> and we store it in a list.]

  SideEffects        []

  SeeAlso            [explain]

 ******************************************************************************/
treeNode_ptr GradedMc_euExplainGraded(BddFsm_ptr fsm, BddEnc_ptr enc, int nTraces,
				      BddStates s, BddInputs sInput, bdd_ptr f, bdd_ptr g, bdd_ptr * intermediateSets, int k)
{
	DdManager* dd = BddEnc_get_dd_manager(enc);
       
	if (! k){
	  node_ptr path = eu_explain(fsm, enc, cons((node_ptr) bdd_dup(s), NODE_PTR(0)), f, g);
	  treeNode_ptr sottoAlbero = (treeNode_ptr) GradedUtils_node_ptrToTreeNode_ptr(fsm, enc, path, sInput);
	  
	  return sottoAlbero;
	}
	
	
	treeNode_ptr res = TreeUtils_treeNodeCreate(s, sInput);
	int count = 0;
	int i = 0;
       
	if (intermediateSets == NIL(bdd_ptr))
		intermediateSets = (bdd_ptr *)GradedUtils_euGetIntermediateSets(fsm, f, g, nTraces);
       
	BddStates postImage = BddFsm_get_forward_image(fsm, s);
	GradedUtils_applyReachableAndMask(fsm, &postImage);
       
	while (count < nTraces + 1 && i < k + 1 )
	{
		BddInputs inputs, input;
		int j = 0;
		BddStates POST = bdd_dup(postImage);
		bdd_and_accumulate(dd, &POST, intermediateSets[i]);
		int array_size = BddEnc_count_states_of_bdd(enc, POST);
		int contribuzione, resto;
		
		if ((i+1) * array_size <= nTraces+1-count){
			contribuzione = i + 1;
			resto = 0;
		}
		else{
			int necessari = nTraces + 1 - count;
			contribuzione = floor(necessari/array_size);
			resto = necessari % array_size;
		}
		count = count + (i+1) * array_size;
		
		if (array_size != 0)
		{
			bdd_ptr* array = ALLOC(bdd_ptr, array_size);
			BddEnc_pick_all_terms_states(enc, POST, array, array_size);
			
			for (j=0; j < array_size; ++j) {
				if (contribuzione == 0 && resto <= 0)
					break;
				
				inputs = BddFsm_states_to_states_get_inputs(fsm, s, array[j]);
				input = BddEnc_pick_one_input(enc, inputs);
				int nPaths = contribuzione + (resto>0) - 1;
				resto--;
				
				if(nPaths>0){
					TreeUtils_concat(res, GradedMc_euExplainGraded(fsm, enc, nPaths, array[j], input, f, g, intermediateSets, k));
				}
				else{
					node_ptr path = eu_explain(fsm, enc, cons((node_ptr) bdd_dup(array[j]), NODE_PTR(0)), f, g);

					treeNode_ptr sottoAlbero = (treeNode_ptr) GradedUtils_node_ptrToTreeNode_ptr(fsm, enc, path, input);
					
					/*walk_dd(dd,bdd_free, path);
					free_list(path);*/
					
					if (s!= array[j] || sottoAlbero == NIL(treeNode))
					  TreeUtils_concat(res, sottoAlbero);
					else{
					  adjList_ptr l1 = TreeUtils_getListaFigli(sottoAlbero);
					  if (l1 != NIL(adjList)){
					    treeNode_ptr m1 = TreeUtils_getNodo(l1);
					    TreeUtils_concat(res, m1);
					  }
					}
				}
			}
		}
		i++;
		bdd_free(dd, POST);
	}
       
	bdd_free(dd, postImage);
	return res;
}


/**Function********************************************************************

  Synopsis           [This function finds a path that is a witness
                      for <i>EG f</i>]

  Description [This function finds a path that is a witness for
  <i>EG f</i>.  The first element of <code>path</code> is a BDD
  <code>s</code> that represents the first state of the witness
  path. It is an initial state from which the example can be
  found. The procedure is to try to execute <code>eg(f,g)</code>
  again, looking for a path from <code>p</code> to a state where
  <i>g</i> is valid. At each step we generate a set of states
  <i>s_i</i> that can be reached in one step from <i>s_{i-1}</i>. We
  extract one minterm form each <i>s_i</i> and we store it in a list.]

  SideEffects        []

  SeeAlso            [explain]

 ******************************************************************************/
treeNode_ptr GradedMc_egExplainGraded(BddFsm_ptr fsm, BddEnc_ptr enc, int nTraces,
				      BddStates s, BddInputs sInput, bdd_ptr f, bdd_ptr * intermediateSets, int k)
{
	DdManager* dd = BddEnc_get_dd_manager(enc);
       
	if (! k){
	  node_ptr path = eg_explain(fsm, enc, cons((node_ptr) bdd_dup(s), NODE_PTR(0)), f);
	  treeNode_ptr sottoAlbero = (treeNode_ptr) GradedUtils_node_ptrToTreeNode_ptr(fsm, enc, path, sInput);
	  
	  return sottoAlbero;
	}
	
	treeNode_ptr res = TreeUtils_treeNodeCreate(s, sInput);
	int count = 0;
	int i = 0;
	
	if (intermediateSets == NIL(bdd_ptr))
		intermediateSets = (bdd_ptr *)GradedUtils_egGetIntermediateSets(fsm, f, nTraces);
       
	BddStates postImage = BddFsm_get_forward_image(fsm, s);
	GradedUtils_applyReachableAndMask(fsm, &postImage);
       
	while (count < nTraces + 1 && i < k + 1)
	{
		BddInputs inputs, input;
		int j = 0;
		BddStates POST = bdd_dup(postImage);
		bdd_and_accumulate(dd, &POST, intermediateSets[i]);
		int array_size = BddEnc_count_states_of_bdd(enc, POST);
		int contribuzione, resto;
		
		if ((i+1) * array_size <= nTraces + 1 - count){
			contribuzione = i + 1;
			resto = 0;
		}
		else{
			int necessari = nTraces + 1 - count;
			contribuzione = floor(necessari/array_size);
			resto = necessari % array_size;
		}
		count = count + (i+1) * array_size;
		
		if (array_size != 0)
		{
			bdd_ptr* array = ALLOC(bdd_ptr, array_size);
			BddEnc_pick_all_terms_states(enc, POST, array, array_size);
			
			for (j=0; j < array_size; ++j) {
				if (contribuzione == 0 && resto <= 0)
					break;
				
				inputs = BddFsm_states_to_states_get_inputs(fsm, s, array[j]);
				input = BddEnc_pick_one_input(enc, inputs);
				int nPaths = contribuzione + (resto>0) - 1;
				resto--;
				if(nPaths>0){
					TreeUtils_concat(res, GradedMc_egExplainGraded(fsm, enc, nPaths, array[j], input, f, intermediateSets, k));
				}
				else{
					node_ptr path = eg_explain(fsm, enc, cons((node_ptr) bdd_dup(array[j]), NODE_PTR(0)), f);
					treeNode_ptr sottoAlbero = (treeNode_ptr) GradedUtils_node_ptrToTreeNode_ptr(fsm, enc, path, input);
					
					/*walk_dd(dd,bdd_free, path);
					free_list(path);*/
					
					if (s!= array[j] || sottoAlbero == NIL(treeNode))
					  TreeUtils_concat(res, sottoAlbero);
					else{
					  adjList_ptr l1 = TreeUtils_getListaFigli(sottoAlbero);
					  if (l1 != NIL(adjList)){
					    treeNode_ptr m1 = TreeUtils_getNodo(l1);
					    TreeUtils_concat(res, m1);
					  }
					}
				}
			}
		}
		i++;
		bdd_free(dd, POST);
	}
       
	bdd_free(dd, postImage);
	return res;
}

/*---------------------------------------------------------------------------*/
/* Definition of static functions                                            */
/*---------------------------------------------------------------------------*/

void EstendiPaths(BddFsm_ptr fsm, BddEnc_ptr enc, treeNode_ptr albero,
                    node_ptr formula_expr, node_ptr contex, boolean negata)
{
	bdd_ptr stato;
	adjList_ptr figli;
	
	/*if (albero == NIL(treeNode))
	{
		printf("It's impossible to get the nex state\n");
		return ;
	}*/
	
	stato = TreeUtils_getStato(albero);
	figli = TreeUtils_getListaFigli(albero);	
	
	
	/*raggiunta una foglia*/
	if (figli == NIL(adjList))
	{
	  treeNode_ptr estensione = GradedMc_explainRecurGraded(fsm, enc, stato,
                    formula_expr, contex, negata, true);
	  if (estensione == NIL(treeNode)) return;
	  adjList_ptr figliE = TreeUtils_getListaFigli(estensione);
	  while  (figliE != NIL(adjList))
	  {
	    treeNode_ptr figlioE = TreeUtils_getNodo(figliE);
	    TreeUtils_concat(albero, figlioE);
	    figliE = TreeUtils_getNext(figliE);
	  }
	  TreeUtils_freeNodo(estensione);
	}
	
	while  (figli != NIL(adjList))
	{
		treeNode_ptr figlio = TreeUtils_getNodo(figli);
		EstendiPaths(fsm, enc, figlio, formula_expr, contex, negata);
		
		figli = TreeUtils_getNext(figli);
	}
}

/**Function********************************************************************

  Synopsis           [Recursively traverse the formula CTL and rewrite
                      it in order to use the base witnesses generator functions.]

  Description        [Recursively traverse the formula CTL and rewrite
  it in order to use the base witnesses generator functions.<br>
  The rewritings performed use the equivalence between CTL formulas,
  i.e. <i>A\[f U g\]</i> is equivalent to <i>!(E\[!g U (!g & !f)\] | EG !g)</i>.]

  SideEffects        []

  SeeAlso            [explain]

******************************************************************************/
static treeNode_ptr GradedMc_explainRecurGraded(BddFsm_ptr fsm, BddEnc_ptr enc, BddStates radice,
                    node_ptr formula_expr, node_ptr context, boolean negata, boolean annidata) {

    DdManager* dd = BddEnc_get_dd_manager(enc);
    bdd_ptr a1, a2;
    int k;
    treeNode_ptr new_path;
    node_ptr kNode;
    int valEGG = EGG;
    int valEGU = EGU;
    int valEGX = EGX;
	
	if (formula_expr == Nil)  return NIL(treeNode);
	
	yylineno = node_get_lineno(formula_expr);
	
	switch (node_get_type(formula_expr)) {
		case CONTEXT:
			return GradedMc_explainRecurGraded(fsm, enc, radice, cdr(formula_expr), car(formula_expr), negata, annidata);
		case AND:
		case OR:
		case NOT:
		  if (node_get_type(formula_expr) == NOT)
		    negata = !negata;
		case IMPLIES:
		case IFF:
			new_path = GradedMc_explainRecurGraded(fsm, enc, radice, car(formula_expr), context, negata, annidata);
			if (new_path!= NIL(treeNode)) return new_path;
			else{return GradedMc_explainRecurGraded(fsm, enc, radice, cdr(formula_expr), context, negata, annidata);}
			
			
		case EGX:
			if (!annidata && !negata) return TreeUtils_treeNodeCreate(radice, NIL(DdNode));
			a1 = GradedMc_evalGradedCtlSpec(fsm, enc, car(car(formula_expr)), context);
			k = BddEnc_eval_num(enc, cdr(formula_expr), context);
			set_the_node(formula_expr);
			new_path = GradedMc_exExplainGraded(fsm, enc, k, radice, NIL(DdNode), a1);
			bdd_free(dd_manager, a1);
			
			if (new_path != NIL(treeNode)) {
				EstendiPaths(fsm, enc, new_path, car(car(formula_expr)), context, false);
			}
			return new_path;
		case AGX:
			kNode = cdr(formula_expr);
			return GradedMc_explainRecurGraded(fsm, enc, radice, 
					     find_node(NOT,  find_node(EGX,
							     find_node(EX, 
									     find_node(NOT, car(car(formula_expr)), Nil), 
									     Nil), kNode), 
							     Nil), 
					     context, negata, annidata);
		case EGG:
			if (!annidata && !negata) return TreeUtils_treeNodeCreate(radice, NIL(DdNode));
			a1 = GradedMc_evalGradedCtlSpec(fsm, enc, car(car(formula_expr)), context);
			k = BddEnc_eval_num(enc, cdr(formula_expr), context);
			set_the_node(formula_expr);
			new_path = GradedMc_egExplainGraded(fsm, enc, k, radice, NIL(DdNode), a1, NIL(bdd_ptr), k);
			bdd_free(dd_manager, a1);
			return new_path;
		case AGG:
			kNode = cdr(formula_expr);
			
			return GradedMc_explainRecurGraded(fsm, enc, radice,
					find_node(NOT, find_node(valEGU,
							find_node(EU, one_number, find_node(NOT, car(car(formula_expr)), Nil)), kNode),
							Nil), 
					context, negata, annidata);
		case EGU:
			if (!annidata && !negata) return TreeUtils_treeNodeCreate(radice, NIL(DdNode));
			a1 = GradedMc_evalGradedCtlSpec(fsm, enc, car(car(formula_expr)), context);
			a2 = GradedMc_evalGradedCtlSpec(fsm, enc, cdr(car(formula_expr)), context);
			k = BddEnc_eval_num(enc, cdr(formula_expr), context);
			set_the_node(formula_expr);
			new_path = GradedMc_euExplainGraded(fsm, enc, k, radice, NIL(DdNode), a1, a2, NIL(bdd_ptr), k);
			bdd_free(dd_manager, a2);
			bdd_free(dd_manager, a1);
			if (new_path != NIL(treeNode)) {
				EstendiPaths(fsm, enc, new_path, cdr(car(formula_expr)), context, false);
			}
			return new_path;
		case AGU:			
			kNode = cdr(formula_expr);
			
			
			node_ptr f = car(car(formula_expr));
			node_ptr g = cdr(car(formula_expr));
			node_ptr notf_and_notg = find_node(AND, find_node(NOT, f, Nil), find_node(NOT, g, Nil));
			node_ptr f_and_notg = find_node(AND, f, find_node(NOT, g, Nil));
			
			node_ptr EGG = find_node(valEGG, find_node(EG, f_and_notg, Nil), kNode);
			node_ptr EGU = find_node(valEGU, find_node(EU, f_and_notg, notf_and_notg), kNode);
			node_ptr AGU = find_node(NOT, find_node(OR, EGU, EGG), Nil);
			
			/* A[f U g] and !(E[(f and!g) U (!g & !f)] | EG (f and !g)) are equivalent. */
			return GradedMc_explainRecurGraded(fsm, enc, radice, AGU, context, negata, annidata);

		case EGF:
			kNode = cdr(formula_expr);
			return GradedMc_explainRecurGraded(fsm, enc, radice, find_node(valEGU,
							find_node(EU, one_number, car(car(formula_expr))),kNode), context, negata, annidata);

		case AGF:
			kNode = cdr(formula_expr);
			
			return GradedMc_explainRecurGraded(fsm, enc, radice, find_node(NOT,
					find_node(valEGG, find_node(EG,
							find_node(NOT, car(car(formula_expr)), Nil),Nil), kNode),
						Nil),
					context, negata, annidata);

        default:
		return NIL(treeNode);
    }
}






/**Function********************************************************************

  Synopsis           []

  Description        []

  SideEffects        []

  SeeAlso            []

******************************************************************************/
static node_ptr* GradedMc_extendTraceWithStateInputPairGraded(BddFsm_ptr fsm,
                    BddEnc_ptr enc, node_ptr path, bdd_ptr starting_state,
                    bdd_ptr next_states, const char * comment) {
    int i = 0;
    node_ptr res;
    
    bdd_ptr next_state, inputs, input;
    size_t size = strlen(comment) + 10;
    char* com = ALLOC(char, size);
    node_ptr* array_res;
    
    snprintf(com, size, "%s: (%d)", com, 1);

#ifdef EXPLAIN_TRACE_DEBUG
    GradedMc_checkTraceListSanity(enc, path, com);
#endif

    bdd_ptr* minterms;
    int array_size = (int) BddEnc_count_states_of_bdd(enc, next_states);
    minterms = ALLOC(bdd_ptr, array_size);
    BddEnc_pick_all_terms_states(enc, next_states, minterms, array_size);
    array_res = ALLOC(node_ptr, array_size + 1);
    for(i = 0; i < array_size; i++) {
        next_state = minterms[i];
        inputs = BddFsm_states_to_states_get_inputs(fsm, starting_state, next_state);
        input = BddEnc_pick_one_input(enc, inputs);
        res = cons((node_ptr) bdd_dup(next_state), cons((node_ptr) bdd_dup(input), path));
        
        snprintf(com, size, "%s: (%d)", com, 2);

#ifdef EXPLAIN_TRACE_DEBUG
        GradedMc_checkTraceListSanity(enc, res, com);
#endif

        array_res[i] = res;
    }

    array_res[array_size] = Nil;

    bdd_free(dd_manager, input);
    bdd_free(dd_manager, inputs);
    bdd_free(dd_manager, next_state);

    return array_res;
}

/**Function********************************************************************

  Synopsis           []

  Description        []

  SideEffects        []

  SeeAlso            []

******************************************************************************/
static void GradedMc_checkTraceListSanity(BddEnc_ptr enc, node_ptr path, const char * varname) {
    int i, l;
    node_ptr scan;
    DdManager* dd = BddEnc_get_dd_manager(enc);
    boolean must_abort = 0;

    l = llength(path);
    scan = path;

    fprintf(nusmv_stderr, "Checking TraceList Sanity: %s\n", varname);
    fprintf(nusmv_stderr, "Length of list: %d\n", l);

    for (i = 0; i < l; i++) {
        bdd_ptr elem = (bdd_ptr)car(scan);

        if ( (i % 2) == 0 ) {
            fprintf(nusmv_stderr,  "STATE(%d):\n", i);
        } else {
            fprintf(nusmv_stderr,  "INPUT(%d):\n", i);
        }
        nusmv_assert( elem != (bdd_ptr) NULL );
        must_abort = (must_abort || bdd_is_zero(dd, elem));
        if ( must_abort ) {
            fprintf(nusmv_stderr,  "**** DOOMED TO ABORT, STEP %d\n", i);
        }
        dd_printminterm(dd, elem);

        scan = cdr(scan);
    }
  
    if ( must_abort ) nusmv_assert( 0 );
}
