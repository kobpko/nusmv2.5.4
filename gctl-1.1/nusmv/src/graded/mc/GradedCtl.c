/**CFile***********************************************************************

    FileName    [GradedCtl.c]

    PackageName [graded/mc]

    Synopsis    [Fair Graded-CTL model checking routines.]

    Description [Fair Graded-CTL model checking routines.]

    SeeAlso     []

    Author      [Alessandro Ferrante]

******************************************************************************/

#include "GradedCtl.h"

static char rcsid[] UTIL_UNUSED = "$Id: GradedCtl.c,v 1.0.3 2008/12/05 08:55:58 nusmv Exp $";

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
    Name:
        GradedMc_and
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula \psi_1 AND \psi_2.
        
******************************************************************************/
BddStates GradedMc_and(BddFsm_ptr fsm, BddStates f, BddStates g) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result;
    
    result = bdd_and(dd, f, g);      // \psi_1 AND \psi_2
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_or
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula \psi_1 OR \psi_2.
        
******************************************************************************/
BddStates GradedMc_or(BddFsm_ptr fsm, BddStates f, BddStates g) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result;
    
    result = bdd_or(dd, f, g);      // \psi_1 AND \psi_2
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_not
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   g       The states where the subformula \psi_1 is true
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula !\psi_1.
        
******************************************************************************/
BddStates GradedMc_not(BddFsm_ptr fsm, BddStates g) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result;
    
    result = bdd_not(dd, g);      // !\psi_1
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_xor
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula \psi_1 XOR \psi_2.
        
******************************************************************************/
BddStates GradedMc_xor(BddFsm_ptr fsm, BddStates f, BddStates g) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result;
    
    result = bdd_xor(dd, f, g);      // \psi_1 AND \psi_2
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_xnor
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula \psi_1 XNOR \psi_2 = \psi_1 XOR !\psi_2.
        
******************************************************************************/
BddStates GradedMc_xnor(BddFsm_ptr fsm, BddStates f, BddStates g) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result, tmp1;
    
    tmp1 = bdd_not(dd, g);              // !\psi_2
    result = bdd_xor(dd, f, tmp1);      // \psi_1 XOR !\psi_2
    
    bdd_free(dd, tmp1);
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_implies
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula \psi_1 => \psi_2 = !\psi_1 OR \psi_2.
        
******************************************************************************/
BddStates GradedMc_implies(BddFsm_ptr fsm, BddStates f, BddStates g) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result, tmp1;
    
    tmp1 = bdd_not(dd, f);              // !\psi_1
    result = bdd_or(dd, tmp1, g);       // !\psi_1 OR \psi_2
    
    bdd_free(dd, tmp1);
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_iff
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula \psi_1 IFF \psi_2 = !(\psi_1 XOR \psi_2).
        
******************************************************************************/
BddStates GradedMc_iff(BddFsm_ptr fsm, BddStates f, BddStates g) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result, tmp1;
    
    tmp1 = bdd_xor(dd, f, g);           // \psi_1 XOR \psi_2
    result = bdd_not(dd, tmp1);         // !(\psi_1 XOR \psi_2)
    
    bdd_free(dd, tmp1);
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_ex
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   g       The states where the subformula \psi_1 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula E^{>k} X \psi_1
******************************************************************************/
BddStates GradedMc_ex(BddFsm_ptr fsm, BddStates g, int k) {
	
	if (!k)
	{
		BddStates states = ex(fsm, g);
		return states;
	}
	
	DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
	bdd_ptr result, states = bdd_dup(g);

	{
		/* The explicit restriction to fair states is required (it affects
		the result from a logical point of view.)*/
		bdd_ptr fair = BddFsm_get_fair_states(fsm);
		bdd_and_accumulate(dd, &states, fair);
		bdd_free(dd, fair);
	}

	if (opt_use_reachable_states(options)) {
		bdd_ptr reachable =  BddFsm_get_reachable_states(fsm);
		bdd_and_accumulate(dd, &states, reachable);
		bdd_free(dd, reachable);
	}

	result = GradedUtils_getKBackwardImage(fsm, states, k);
	//dd_printminterm(dd, result);
	//BddEnc_print_set_of_states(BddFsm_get_bdd_encoding(fsm), result, 0, stdout);

	bdd_free(dd, states);

	if (opt_use_reachable_states(options)) {
		bdd_ptr reachable =  BddFsm_get_reachable_states(fsm);
		bdd_and_accumulate(dd, &result, reachable);
		bdd_free(dd, reachable);
	}

	return(result);
}

/******************************************************************************
    Name:
        GradedMc_ax
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   g       The states where the subformula \psi_1 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula A^{\leq k} \psi_1 U \psi_2. This formula is
        verified by using the relation A^{\leq k} X \psi_1 = !E^{>k} X !\psi_1.
        
******************************************************************************/
BddStates GradedMc_ax(BddFsm_ptr fsm, BddStates g, int k) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result, tmp_1, tmp_2;
    
    tmp_1 = bdd_not(dd, g);               // !\psi_1
    tmp_2 = GradedMc_ex(fsm, tmp_1, k);   // E^{>k} X !\psi_1
    result = bdd_not(dd, tmp_2);          // !E^{>k} X !\psi_1
    
    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_eu
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula E^{>k} \psi_1 U \psi_2
*********************************************************************************/
BddStates GradedMc_eu(BddFsm_ptr fsm, BddStates f, BddStates g, int k) {
	if (k == 0) {
		BddStates states = eu(fsm, f, g);
		return states;
	}
	
	{
		BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
		DdManager* dd = BddEnc_get_dd_manager(enc);
			
		add_ptr count_paths, adding_paths, temp_count_paths;
		bdd_ptr contributors, contributors_tmp, pred;
		int i;

		count_paths = add_zero(dd);
		
		contributors_tmp = eu(fsm, f, g);
		contributors = BddEnc_apply_state_vars_mask_bdd(enc, contributors_tmp);
		bdd_free(dd, contributors_tmp);
		
		for (i=1; i<=k; i++) {
			adding_paths = GradedUtils_fsmCountSuccessors(fsm, contributors, k+1);
			bdd_free(dd, contributors);
			GradedUtils_addSum(dd, &count_paths, adding_paths, k+1);
			add_free(dd, adding_paths);
			contributors = add_to_bdd_strict_threshold(dd, count_paths, i);
			GradedUtils_applyReachableAndMask(fsm, &contributors);
			bdd_and_accumulate(dd, &contributors, f);
			GradedUtils_fixPoint(fsm, &contributors, f);
        	}
		
		add_free(dd, count_paths);
		
		return contributors;
	}
}

/******************************************************************************
    Name:
        GradedMc_au
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   f       The states where the subformula \psi_1 is true
        BddStates   g       The states where the subformula \psi_2 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula A^{\leq k} \psi_1 U \psi_2. Recall that a path
        not satisfying \psi_1 U \psi_2 is a path satisfying the formula
        [G (\psi_1 AND NOT \psi_2)] OR [(\psi_1 AND NOT \psi_2) U (NOT \psi_1 AND NOT \psi_2)]
*********************************************************************************/
BddStates GradedMc_au(BddFsm_ptr fsm, BddStates f, BddStates g, int k) {
    if (k == 0) {
		BddStates states = au(fsm, f, g);
		return states;
	}
	
	{
        BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);

        add_ptr count_paths, count_paths_1, count_paths_2, adding_paths, tmp;
	bdd_ptr f_and_not_g, not_f_and_not_g, contributors_1, contributors_2, pred;
		
        {
            bdd_ptr not_f = bdd_not(dd, f);
            bdd_ptr not_g = bdd_not(dd, g);
            
            f_and_not_g = bdd_and(dd, f, not_g);
            not_f_and_not_g = bdd_and(dd, not_f, not_g);
            
            bdd_free(dd, not_f);
            bdd_free(dd, not_g);
        }
 
 		
		int i;

		count_paths = add_zero(dd);
		count_paths_1 = add_zero(dd);
		count_paths_2 = add_zero(dd);
		
		{
            add_ptr tmp;
            
            contributors_1 = eg(fsm, f_and_not_g);
            GradedUtils_applyReachableAndMask(fsm, &contributors_1);
            tmp = bdd_to_add(dd, contributors_1);
            GradedUtils_addSum(dd, &count_paths, tmp, k+1);
            add_free(dd, tmp);
            
            contributors_2 = eu(fsm, f_and_not_g, not_f_and_not_g);
            GradedUtils_applyReachableAndMask(fsm, &contributors_2);
            tmp = bdd_to_add(dd, contributors_2);
            GradedUtils_addSum(dd, &count_paths, tmp, k+1);
            add_free(dd, tmp);
        }
		
		for (i=1; i<=k; i++) {
            {
                bdd_ptr adding_paths;
                
                adding_paths = GradedUtils_fsmCountSuccessors(fsm, contributors_1, k+1);
                bdd_free(dd, contributors_1);
                GradedUtils_addSum(dd, &count_paths_1, adding_paths, k+1);
                add_free(dd, adding_paths);
                
                adding_paths = GradedUtils_fsmCountSuccessors(fsm, contributors_2, k+1);
                bdd_free(dd, contributors_2);
                GradedUtils_addSum(dd, &count_paths_2, adding_paths, k+1);
                add_free(dd, adding_paths);
            }
            
            {
                add_ptr tmp;
                
                contributors_1 = add_to_bdd_strict_threshold(dd, count_paths_1, i);
                GradedUtils_applyReachableAndMask(fsm, &contributors_1);
                bdd_and_accumulate(dd, &contributors_1, f_and_not_g);
                GradedUtils_fixPoint(fsm, &contributors_1, f_and_not_g);
                tmp = bdd_to_add(dd, contributors_1);
                GradedUtils_addSum(dd, &count_paths, tmp, k+1);
                add_free(dd, tmp);
                
                contributors_2 = add_to_bdd_strict_threshold(dd, count_paths_2, i);
                GradedUtils_applyReachableAndMask(fsm, &contributors_2);
                bdd_and_accumulate(dd, &contributors_2, f_and_not_g);
                GradedUtils_fixPoint(fsm, &contributors_2, f_and_not_g);
                tmp = bdd_to_add(dd, contributors_2);
                GradedUtils_addSum(dd, &count_paths, tmp, k+1);
                add_free(dd, tmp);
            }
        }
        
        bdd_free(dd, contributors_1);
        bdd_free(dd, contributors_2);
        
        {
		bdd_ptr tmp = add_to_bdd_strict_threshold(dd, count_paths, k);
		BddStates states = bdd_not(dd, tmp);
		bdd_free(dd, tmp);
            return states;
        }
	}
}

/******************************************************************************
    Name:
        GradedMc_eg
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   g       The states where the subformula \psi_1 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula E^{>k} G \psi_1. This formula is verified by using
        the relation E^{>k} G \psi_1 = \neg A^{\leq k} \neg ( G \psi_1) =
        \neg A^{\leq k} [TRUE U \neg\psi_1]
******************************************************************************/
BddStates GradedMc_eg(BddFsm_ptr fsm, BddStates g, int k) {
	if (k == 0) {
		BddStates states = eg(fsm, g);
		return states;
	}
	
	{
		BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
		DdManager* dd = BddEnc_get_dd_manager(enc);
			
		add_ptr count_paths, adding_paths, temp_count_paths;
		bdd_ptr contributors, contributors_tmp, pred;
		int i;

		count_paths = add_zero(dd);
		
		contributors_tmp = eg(fsm, g);
		contributors = BddEnc_apply_state_vars_mask_bdd(enc, contributors_tmp);
		bdd_free(dd, contributors_tmp);
		
		for (i=1; i<=k; i++) {
			adding_paths = GradedUtils_fsmCountSuccessors(fsm, contributors, k+1);
			bdd_free(dd, contributors);
			GradedUtils_addSum(dd, &count_paths, adding_paths, k+1);
			add_free(dd, adding_paths);
			contributors = add_to_bdd_strict_threshold(dd, count_paths, i);
			GradedUtils_applyReachableAndMask(fsm, &contributors);
			bdd_and_accumulate(dd, &contributors, g);
			GradedUtils_fixPoint(fsm, &contributors, g);
        	}
		
		add_free(dd, count_paths);
		
		return contributors;
	}
}

/*BddStates GradedMc_eg(BddFsm_ptr fsm, BddStates g, int k) {
	BddEnc_ptr enc = BddFsm_get_bdd_encoding(fsm);
	DdManager* dd = BddEnc_get_dd_manager(enc);
	
	bdd_ptr one = bdd_one(dd);                     //TRUE
	bdd_ptr not_g = bdd_not(dd, g);                //\neg\psi_1
	bdd_ptr tmp = GradedMc_au(fsm, one, not_g, k); //A^{\leq k} [TRUE U \neg\psi_1]
	bdd_ptr result = bdd_not(dd, tmp);                 //\neg A^{\leq k} [TRUE U \neg\psi_1]
			
	bdd_free(dd, one);
	bdd_free(dd, not_g);
	bdd_free(dd, tmp);
	
	return result;
}*/

/******************************************************************************
    Name:
        GradedMc_ag
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   g       The states where the subformula \psi_1 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula A^{\leq k} \psi_1 U \psi_2. This formula is
        verified by using the relation A^{\leq k} \G \psi_1 = !E^{>k} F !\psi_1
        
******************************************************************************/
BddStates GradedMc_ag(BddFsm_ptr fsm, BddStates g, int k) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result, tmp_1, tmp_2;
    
    tmp_1 = bdd_not(dd, g);               // !\psi_1
    tmp_2 = GradedMc_ef(fsm, tmp_1, k);   // E^{>k} F !\psi_1
    result = bdd_not(dd, tmp_2);          // !E^{>k} F !\psi_1
    
    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_ef
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   g       The states where the subformula \psi_1 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula E^{>k} F \psi_1. This formula is verified by using
        the relation E^{>k} F \psi_1 = E^{>k} True U \psi_1.
******************************************************************************/
BddStates GradedMc_ef(BddFsm_ptr fsm, BddStates g, int k) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result, one;
    
    one = bdd_one(dd);                      // True
    result = GradedMc_eu(fsm, one, g, k);   // E^{>k} True U \psi_1
    
    bdd_free(dd, one);
    
    return(result);
}

/******************************************************************************
    Name:
        GradedMc_af
        
    Parameters:
        BddFsm_ptr  fsm     Kripke structure to verify
        BddStates   g       The states where the subformula \psi_1 is true
        int         k       The grading constant
        
    Result:
        BddStates           The states where \varphi is true
        
    Description:
        Check the formula A^{\leq k} F \psi_1. This formula is verified by using
        the relation A^{\leq k} F \psi_1 = !E^{>k} G !\psi_1
        
******************************************************************************/
BddStates GradedMc_af(BddFsm_ptr fsm, BddStates g, int k) {
    DdManager* dd = BddEnc_get_dd_manager(BddFsm_get_bdd_encoding(fsm));
    bdd_ptr result, tmp_1, tmp_2;
    
    tmp_1 = bdd_not(dd, g);               // !\psi_1
    tmp_2 = GradedMc_eg(fsm, tmp_1, k);   // E^{>k} G \psi_1
    result = bdd_not(dd, tmp_2);          // !E^{>k} G \psi_1
    
    bdd_free(dd, tmp_1);
    bdd_free(dd, tmp_2);
    
    return(result);
}

