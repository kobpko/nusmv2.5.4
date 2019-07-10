/******************************************************************************

    File name:
        ModelChecking.h
        
    Package name:
        graded/mc
    
    Synopsis:
        Main graded-CTL model checking algorithm. External header file.
        
    Description:
        Main function for model checking of graded-CTL formulas.

    Author:
        Alessandro Ferrante

******************************************************************************/

#ifndef __GRADEDMC_MODELCHECKING_H__
#define __GRADEDMC_MODELCHECKING_H__

/*****************************************************************************/
/* Libraries                                                                 */
/*****************************************************************************/

#include "dd/dd.h"
#include "enc/enc.h"
#include "enc/operators.h"
#include "fsm/bdd/BddFsm.h"
#include "fsm/bdd/FairnessList.h"
#include "mc/mc.h"
#include "mc/mcInt.h"
#include "parser/symbols.h"
#include "prop/prop.h"
#include "trace/Trace.h"
#include "trace/TraceManager.h"
#include "utils/error.h"
#include "utils/utils.h"
#include "utils/utils_io.h"

#include "graded/mc/Eval.h"
#include "graded/mc/Explain.h"
#include "graded/mc/GradedCtl.h"
#include "graded/utils/GradedUtils.h"

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

EXTERN void GradedMc_checkGradedCtlSpec ARGS((Prop_ptr));

#endif
