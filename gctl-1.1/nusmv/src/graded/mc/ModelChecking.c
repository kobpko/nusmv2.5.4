/******************************************************************************

    File name:
        ModelChecking.c

    Package name:
        graded/mc

    Synopsis:
        Main graded-CTL model checking algorithm.

    Description:
        Main function for the model checking of graded-CTL formulas.
        
    Author:
        Alessandro Ferrante

******************************************************************************/

#include "ModelChecking.h"

static char rcsid[] UTIL_UNUSED = "$Id: ModelChecking.c,v 1.0.3 2008/12/05 08:55:58 nusmv Exp $";

/*---------------------------------------------------------------------------*/
/* Variable declarations                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Static function prototypes                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Definition of exported functions                                          */
/*---------------------------------------------------------------------------*/

/******************************************************************************

    Function name:
        GradedMc_checkGradedCtlSpec
        
    Parameters:
        Prop_ptr    property        The formula to be verified
        
    Result:
        void
        
    Description:
        The main function to make the model checking.
*******************************************************************************/
void GradedMc_checkGradedCtlSpec(Prop_ptr prop) {
	bdd_ptr constraints, fair, initial, states;
	node_ptr exp;
	bdd_ptr tmp1, tmp2;
	BddFsm_ptr fsm;
	BddEnc_ptr enc;
	DdManager* dd;
	Expr_ptr spec = Prop_get_expr_core(prop);

	if (opt_verbose_level_gt(options, 0)) {
		fprintf(nusmv_stderr, "evaluating ");
		print_spec(nusmv_stderr, prop);
		fprintf(nusmv_stderr, "\n");
	}
	
	if (opt_cone_of_influence(options) == true) {
		Prop_apply_coi_for_bdd(prop, global_fsm_builder);
	}

    /*Recruits the properties of the fsm*/	
	fsm = Prop_get_bdd_fsm(prop);
	if (fsm == BDD_FSM(NULL)) {
		Prop_set_fsm_to_master(prop);
		fsm = Prop_get_bdd_fsm(prop);
		BDD_FSM_CHECK_INSTANCE(fsm);
	}
	enc = BddFsm_get_bdd_encoding(fsm);
	dd = BddEnc_get_dd_manager(enc);
	constraints = BddFsm_get_state_constraints(fsm);
	fair = BddFsm_get_fair_states(fsm);
	initial = BddFsm_get_init(fsm);
	
	if (bdd_is_zero(dd, fair))
		warning_fsm_fairness_empty();
	
	/* Evaluates the spec */
	tmp1 = GradedMc_evalGradedCtlSpec(fsm, enc, spec, Nil);
	tmp2 = bdd_not(dd, tmp1);
	bdd_free(dd, tmp1);
    
    	bdd_and_accumulate(dd, &tmp2, constraints);
	bdd_and_accumulate(dd, &tmp2, fair);
	bdd_and_accumulate(dd, &tmp2, initial);
	
    states = BddEnc_apply_state_vars_mask_bdd(enc, tmp2);
    bdd_free(dd, tmp2);
		
	/* Prints out the result, if not true explain. */
	fprintf(nusmv_stdout, "-- ");
	print_spec(nusmv_stdout, prop);
	
	if (bdd_is_zero(dd, states)) {
		fprintf(nusmv_stdout, "is true\n");
		Prop_set_status(prop, Prop_True);
	} else {
		int tr = 0;
		int i = 0;
		
		fprintf(nusmv_stdout, "is false\n");
		Prop_set_status(prop, Prop_False);
		//return;
		/*printf("mau prima\n");
		dd_printminterm(dd_manager, states);*/
		tmp1 = GradedUtils_bddPickOneState(enc, states);
		/*printf("stato selezionato\n");
		dd_printminterm(dd_manager, tmp1);
		printf("mau dopo\n");*/
		
		int nTracce = 1;
		treeNode_ptr albero = GradedMc_explainGraded(fsm, enc, tmp1, spec, Nil);
		
		
		GradedUtils_countTraces(fsm, enc, albero, &nTracce);
		
		cycleInf_ptr cicli = ALLOC(cycleInf, nTracce);
		int j;
		for(j=0; j<nTracce; j++){
		  cicli[j].nStato = 0;
		}
		GradedUtils_findCycle(fsm, enc, albero, cicli);
		
		GradedUtils_stampaPaths(fsm, enc, albero, cicli);
		return;
		
		if (opt_counter_examples(options)) {
			Trace_ptr trace;
			node_ptr* counter;
			char* trace_title = NULL;
			char* trace_title_postfix = " Counterexample";
			bool nullRes = false;
			
			tmp1 = BddEnc_pick_one_state(enc, states);
			
			counter = (node_ptr*)GradedMc_explainGraded(fsm, enc, 
                                cons((node_ptr)bdd_dup(tmp1), Nil), spec, Nil);
			
			if (counter[0] == Nil) {
				counter = ALLOC(node_ptr, 1);
				counter[0] = cons((node_ptr)bdd_dup(tmp1), Nil);
				counter[1] = Nil;
				nullRes = true;
			}
			
			while(counter[i] != Nil) {
				if (nullRes)
					exp =  counter[i];
				else
					exp =  reverse(counter[i]);
					
				if (exp == Nil) {
					/* The counterexample consists of one initial state */
					exp = cons((node_ptr)bdd_dup(tmp1), Nil);
					nullRes = true;
				}
				
				trace_title = ALLOC(char, Prop_get_type_as_string(prop) + 
						strlen(trace_title_postfix) + 1);
				nusmv_assert(trace_title != (char*) NULL);
				strcpy(trace_title, Prop_get_type_as_string(prop));
				strcat(trace_title, trace_title_postfix);
	
				trace = Trace_create_from_state_input_list(enc, trace_title,
						TRACE_TYPE_CNTEXAMPLE, exp);
				FREE(trace_title);
	
				tr = TraceManager_register_trace(global_trace_manager, trace);  
				Prop_set_trace(prop, Trace_get_id(trace));
	
				fprintf(nusmv_stdout, "-- as demonstrated by the following execution sequence\n");
	
				TraceManager_execute_plugin(global_trace_manager, 
						TraceManager_get_default_plugin(global_trace_manager), tr);
	
				if (!nullRes){
					exp =  reverse(exp);
					nullRes = false;
				}

				/*walk_dd(dd_manager, bdd_free, explanation);
				free_list(explanation);*/
				i++;
			}
			bdd_free(dd, tmp1);
			i = 0;
			while (counter[i] != Nil)
				walk_dd(dd, bdd_free, counter[i++]);
		}
	}
	
	bdd_free(dd, states);
	//bdd_free(dd, tmp1);
	bdd_free(dd, initial);
	bdd_free(dd, constraints);
	bdd_free(dd, fair);
}
