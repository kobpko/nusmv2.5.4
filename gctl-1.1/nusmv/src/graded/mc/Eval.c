/******************************************************************************
    File name:
        Eval.c

    Package name:
        graded/mc

    Synopsis:
        Functions for the valutation of a graded-CTL formula.

    Description:
        Function to traverse the parse tree of a graded-CTL formula and evaluate
        it.
        
    See also:
        
    Author:
        Alessandro Ferrante

******************************************************************************/

#include "Eval.h"

static char rcsid[] UTIL_UNUSED = "$Id: Eval.c,v 1.13.2.57.2.1.2.6.4.3 2008/12/05 08:55:58 nusmv Exp $";

/*---------------------------------------------------------------------------*/
/* Variable declarations                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/

//Operators for unary, binary, ternary and quaternary operations: the suffix
//NG defines non graded operators, G is for graded operator and M is for mod.
typedef bdd_ptr (*Operator1NG)(DdManager*, bdd_ptr);
typedef bdd_ptr (*Operator1G)(DdManager*, bdd_ptr, int);
typedef bdd_ptr (*Operator1NGM)(BddFsm_ptr, bdd_ptr);
typedef bdd_ptr (*Operator1GM)(BddFsm_ptr, bdd_ptr, int);
typedef bdd_ptr (*Operator2NG)(DdManager*, bdd_ptr, bdd_ptr);
typedef bdd_ptr (*Operator2G)(DdManager*, bdd_ptr, bdd_ptr, int);
typedef bdd_ptr (*Operator2NGM)(BddFsm_ptr, bdd_ptr, bdd_ptr);
typedef bdd_ptr (*Operator2GM)(BddFsm_ptr, bdd_ptr, bdd_ptr, int);
typedef bdd_ptr (*Operator3NG)(DdManager*, bdd_ptr, int, int);
typedef bdd_ptr (*Operator3G)(DdManager*, bdd_ptr, int, int, int);
typedef bdd_ptr (*Operator3NGM)(BddFsm_ptr, bdd_ptr, int, int);
typedef bdd_ptr (*Operator3GM)(BddFsm_ptr, bdd_ptr, int, int, int);
typedef bdd_ptr (*Operator4NG)(DdManager*, bdd_ptr, bdd_ptr, int, int, int);
typedef bdd_ptr (*Operator4G)(DdManager*, bdd_ptr, bdd_ptr, int, int, int, int);
typedef bdd_ptr (*Operator4NGM)(BddFsm_ptr, bdd_ptr, bdd_ptr, int, int);
typedef bdd_ptr (*Operator4GM)(BddFsm_ptr, bdd_ptr, bdd_ptr, int, int, int);

/*---------------------------------------------------------------------------*/
/* Static function prototypes                                                */
/*---------------------------------------------------------------------------*/
static bdd_ptr evalRecur ARGS((BddFsm_ptr, BddEnc_ptr enc, node_ptr, node_ptr));

static bdd_ptr operation1NG ARGS((BddFsm_ptr, BddEnc_ptr, Operator1NG, node_ptr, int, int, node_ptr));

static bdd_ptr operation1NGM ARGS((BddFsm_ptr, BddEnc_ptr, Operator1NGM, node_ptr, int, int, node_ptr));

static bdd_ptr operation2NG ARGS((BddFsm_ptr, BddEnc_ptr, Operator2NG, node_ptr, int, int, int, node_ptr));

static bdd_ptr operation2NGM ARGS((BddFsm_ptr, BddEnc_ptr, Operator2NGM, node_ptr, int, int, int, node_ptr));

static bdd_ptr operation1G ARGS((BddFsm_ptr, BddEnc_ptr, Operator1G, node_ptr, int, int, node_ptr));

static bdd_ptr operation1GM ARGS((BddFsm_ptr, BddEnc_ptr, Operator1GM, node_ptr, int, int, node_ptr));

static bdd_ptr operation2G ARGS((BddFsm_ptr, BddEnc_ptr, Operator2G, node_ptr, int, int, int, node_ptr));

static bdd_ptr operation2GM ARGS((BddFsm_ptr, BddEnc_ptr, Operator2GM, node_ptr, int, int, int, node_ptr));

/*---------------------------------------------------------------------------*/
/* Definition of exported functions                                          */
/*---------------------------------------------------------------------------*/


/******************************************************************************
    Name:
        GradedMc_evalGradedCtlSpec
        
    Parameters:
        BddFsm_ptr      fsm         The Kripke structure
        BddEnc_ptr      enc         The coding of the Kripke
        node_ptr        n           The node to evaluate in the parse tree
        node_ptr        context     The context

    Result:
        bdd_ptr                     The set of states where the formula holds
        
    Description:
        Compile a graded-CTL formula into BDD and performs Model Checking.

******************************************************************************/
bdd_ptr GradedMc_evalGradedCtlSpec(BddFsm_ptr fsm, BddEnc_ptr enc, node_ptr n, node_ptr context) {
	//BddFsm_ptr clean_fsm = BddFsm_copy(fsm);
	bdd_ptr res;
	int temp = yylineno;

	if (n == Nil) return(bdd_one(BddEnc_get_dd_manager(enc)));
		
	yylineno = node_get_lineno(n);
	res = evalRecur(fsm, enc, n, context);
	yylineno = temp;

	return(res);
}

/*---------------------------------------------------------------------------*/
/* Definition of static functions                                            */
/*---------------------------------------------------------------------------*/

/**Function********************************************************************

  Synopsis           [Recursive step of <code>eval_ctl_spec</code>.]

  Description [Performs the recursive step of
  <code>eval_ctl_spec</code>.]

  SideEffects        []

  SeeAlso            [eval_ctl_spec]

******************************************************************************/
static bdd_ptr evalRecur(BddFsm_ptr fsm, BddEnc_ptr enc, node_ptr n, node_ptr context) {
    if (n == Nil) {
	    return bdd_one(BddEnc_get_dd_manager(enc));
    }

    switch (node_get_type(n)) {
        case CONTEXT: return(GradedMc_evalGradedCtlSpec(fsm, enc, cdr(n), car(n)));
        case AND:     return(operation2NG(fsm, enc, bdd_and, n, 1, 1, 1, context));
        case OR:      return(operation2NG(fsm, enc, bdd_or,  n, 1, 1, 1, context));
        case XOR:     return(operation2NG(fsm, enc, bdd_xor, n, 1, 1, 1, context));
        case XNOR:    return(operation2NG(fsm, enc, bdd_xor, n, 1, 1, -1, context));
        case NOT:     return(operation1NG(fsm, enc, bdd_not, n, 1, 1, context));
        case IMPLIES: return(operation2NG(fsm, enc, bdd_or,  n, 1, -1, 1, context));
        case IFF:     return(operation2NG(fsm, enc, bdd_xor, n, -1, 1, 1, context));
        case EGX:     return(operation1GM(fsm, enc, GradedMc_ex, n,  1,  1, context));
        case EGU:     return(operation2GM(fsm, enc, GradedMc_eu, n, 1, 1, 1, context));	
        case EGG:     return(operation1GM(fsm, enc, GradedMc_eg, n,  1,  1, context));
        case EGF:     return(operation1GM(fsm, enc, GradedMc_ef, n,  1,  1, context));
        case AGX:     return(operation1GM(fsm, enc, GradedMc_ex, n, -1, -1, context));
        case AGG:     return(operation1GM(fsm, enc, GradedMc_ef, n, -1, -1, context));
        case AGU:     return(operation2GM(fsm, enc, GradedMc_au, n, 1, 1, 1, context));
        case AGF:     return(operation1GM(fsm, enc, GradedMc_eg, n, -1, -1, context));
        default: {
            bdd_ptr res_bdd = BddEnc_expr_to_bdd(enc, n, context);
            if (res_bdd == NULL) {
                rpterr("evalGradedCtlSpec: res = NULL after a call to \"eval\".");
                nusmv_exit(1);
            }
            return res_bdd;
        }
    } /* switch */
}

/**Function********************************************************************

  Synopsis           [Applies unary operation.]

  Description        [Takes in input the expression <code>n</code> and a
  unary operation <code>op</code>. Evaluates <code>n</n> and applies to this
  partial result the unary operator <code>op</code>. The sign of the
  partial result and of the result depends respectively from the flag
  <code>argflag</code> and <code>resflag</code>.]

  SideEffects        []

  SeeAlso            [binary_bdd_op, ternary_bdd_op, quaternary_bdd_op]

******************************************************************************/
static bdd_ptr operation1NG(BddFsm_ptr fsm, BddEnc_ptr enc, Operator1NG op,
                    node_ptr n, int resflag, int argflag, node_ptr context) {
    bdd_ptr tmp_1, tmp_2, res, arg;
    DdManager* dd = BddEnc_get_dd_manager(enc);

    arg = GradedMc_evalGradedCtlSpec(fsm, enc, car(n), context);
    set_the_node(n);

    /* compute and ref argument of operation according its sign */
    tmp_1 = BddEnc_eval_sign_bdd(enc, arg, argflag);

    /* apply and ref the result of the application of "op" to previous arg. */
    tmp_2 = op(dd, tmp_1);

    /* compute and ref the result according to sign of the result */
    res = BddEnc_eval_sign_bdd(enc, tmp_2, resflag);

    /* free temporary results */
    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, arg);

    return res;
}

static bdd_ptr operation1NGM(BddFsm_ptr fsm, BddEnc_ptr enc,Operator1NGM op, 
                    node_ptr n, int resflag, int argflag, node_ptr context) {
    bdd_ptr tmp_1, tmp_2, res, arg;
    DdManager* dd;

    BDD_FSM_CHECK_INSTANCE(fsm);

    arg = GradedMc_evalGradedCtlSpec(fsm, enc, car(n), context);
    dd = BddEnc_get_dd_manager(enc);
    set_the_node(n);

    /* compute and ref argument of operation according its sign */
    tmp_1 = BddEnc_eval_sign_bdd(enc, arg, argflag);

    /* apply and ref the result of the application of "op" to previous arg. */
    tmp_2 = op(fsm, tmp_1);

    /* compute and ref the result according to sign of the result */
    res = BddEnc_eval_sign_bdd(enc, tmp_2, resflag);

    /* free temporary results */
    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, arg);

    return res;
}

static bdd_ptr operation2NG(BddFsm_ptr fsm, BddEnc_ptr enc, Operator2NG op,
                    node_ptr n, int resflag, int argflag1, int argflag2, 
                    node_ptr context) {
    bdd_ptr tmp_1, tmp_2, tmp_3, res, arg1, arg2;
    DdManager* dd = BddEnc_get_dd_manager(enc);

    arg1 = GradedMc_evalGradedCtlSpec(fsm, enc, car(n), context);
    arg2 = GradedMc_evalGradedCtlSpec(fsm, enc, cdr(n), context);

    set_the_node(n);

    tmp_1 = BddEnc_eval_sign_bdd(enc, arg1, argflag1);
    tmp_2 = BddEnc_eval_sign_bdd(enc, arg2, argflag2);
    tmp_3 = op(dd, tmp_1, tmp_2);

    res = BddEnc_eval_sign_bdd(enc, tmp_3, resflag);

    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, tmp_3);
    bdd_free(dd, arg1);
    bdd_free(dd, arg2);

    return res;
}

static bdd_ptr operation2NGM(BddFsm_ptr fsm, BddEnc_ptr enc, Operator2NGM op, 
                    node_ptr n, int resflag, int argflag1, int argflag2, 
                    node_ptr context) {
    bdd_ptr tmp_1, tmp_2, tmp_3, res, arg1, arg2;
    DdManager* dd;

    BDD_FSM_CHECK_INSTANCE(fsm);

    arg1 = GradedMc_evalGradedCtlSpec(fsm, enc, car(n), context);
    arg2 = GradedMc_evalGradedCtlSpec(fsm, enc, cdr(n), context);
    dd = BddEnc_get_dd_manager(enc);

    set_the_node(n);

    tmp_1 = BddEnc_eval_sign_bdd(enc, arg1, argflag1);
    tmp_2 = BddEnc_eval_sign_bdd(enc, arg2, argflag2);
    tmp_3 = op(fsm, tmp_1, tmp_2);
    res = BddEnc_eval_sign_bdd(enc, tmp_3, resflag);

    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, tmp_3);
    bdd_free(dd, arg1);
    bdd_free(dd, arg2);

    return(res);
}

static bdd_ptr operation1G(BddFsm_ptr fsm, BddEnc_ptr enc, Operator1G op,
                    node_ptr n, int resflag, int argflag, node_ptr context) {
    bdd_ptr tmp_1, tmp_2, res, arg;
    int k = 0;
    DdManager* dd = BddEnc_get_dd_manager(enc);

    arg = GradedMc_evalGradedCtlSpec(fsm, enc, car(car(n)), context);
    k = BddEnc_eval_num(enc, cdr(n), context);
    set_the_node(n);

    /* compute and ref argument of operation according its sign */
    tmp_1 = BddEnc_eval_sign_bdd(enc, arg, argflag);

    /* apply and ref the result of the application of "op" to previous arg. */
    tmp_2 = op(dd, tmp_1, k);

    /* compute and ref the result according to sign of the result */
    res = BddEnc_eval_sign_bdd(enc, tmp_2, resflag);

    /* free temporary results */
    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, arg);

    return res;
}

static bdd_ptr operation1GM(BddFsm_ptr fsm, BddEnc_ptr enc, Operator1GM op,
		          node_ptr n, int resflag, int argflag, node_ptr context) {
    bdd_ptr tmp_1, tmp_2, res, arg;
    DdManager* dd;
    int k = 0;

    BDD_FSM_CHECK_INSTANCE(fsm);

    arg = GradedMc_evalGradedCtlSpec(fsm, enc, car(car(n)), context);
    k = BddEnc_eval_num(enc, cdr(n), context);
    dd = BddEnc_get_dd_manager(enc);
    set_the_node(n);

    /* compute and ref argument of operation according its sign */
    tmp_1 = BddEnc_eval_sign_bdd(enc, arg, argflag);

    /* apply and ref the result of the application of "op" to previous arg. */
    tmp_2 = op(fsm, tmp_1, k);

    /* compute and ref the result according to sign of the result */
    res = BddEnc_eval_sign_bdd(enc, tmp_2, resflag);

    /* free temporary results */
    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, arg);

    return res;
}

static bdd_ptr operation2G(BddFsm_ptr fsm, BddEnc_ptr enc, Operator2G op,
		          node_ptr n, int resflag, int argflag1, int argflag2, 
                  node_ptr context) {
    bdd_ptr tmp_1, tmp_2, tmp_3, res, arg1, arg2;
    int k = 0;
    DdManager* dd = BddEnc_get_dd_manager(enc);

    arg1 = GradedMc_evalGradedCtlSpec(fsm, enc, car(car(n)), context);
    arg2 = GradedMc_evalGradedCtlSpec(fsm, enc, cdr(car(n)), context);
    k = BddEnc_eval_num(enc, cdr(n), context);

    set_the_node(n);

    tmp_1 = BddEnc_eval_sign_bdd(enc, arg1, argflag1);
    tmp_2 = BddEnc_eval_sign_bdd(enc, arg2, argflag2);
    tmp_3 = op(dd, tmp_1, tmp_2, k);

    res = BddEnc_eval_sign_bdd(enc, tmp_3, resflag);

    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, tmp_3);
    bdd_free(dd, arg1);
    bdd_free(dd, arg2);

    return res;
}


static bdd_ptr operation2GM(BddFsm_ptr fsm, BddEnc_ptr enc, Operator2GM op,
                    node_ptr n, int resflag, int argflag1, int argflag2, 
                    node_ptr context) {
    bdd_ptr tmp_1, tmp_2, tmp_3, res, arg1, arg2;
    DdManager* dd;
    int k = 0;

    BDD_FSM_CHECK_INSTANCE(fsm);

    arg1 = GradedMc_evalGradedCtlSpec(fsm, enc, car(car(n)), context);
    arg2 = GradedMc_evalGradedCtlSpec(fsm, enc, cdr(car(n)), context);
    k = BddEnc_eval_num(enc, cdr(n), context);
    dd = BddEnc_get_dd_manager(enc);

    set_the_node(n);

    tmp_1 = BddEnc_eval_sign_bdd(enc, arg1, argflag1);
    tmp_2 = BddEnc_eval_sign_bdd(enc, arg2, argflag2);
    tmp_3 = op(fsm, tmp_1, tmp_2, k);
    res = BddEnc_eval_sign_bdd(enc, tmp_3, resflag);

    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    bdd_free(dd, tmp_3);
    bdd_free(dd, arg1);
    bdd_free(dd, arg2);

    return(res);
}

