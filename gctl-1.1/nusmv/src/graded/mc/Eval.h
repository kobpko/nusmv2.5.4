/**CHeaderFile*****************************************************************

  FileName    [Eval.h]

  PackageName [graded/mc]

  Synopsis    [Fair graded-CTL model checking algorithms. External header file.]

  Description [Fair graded-CTL model checking algorithms. External header file.]

  Author      [Alessandro Ferrante]
******************************************************************************/

#ifndef __GRADEDMC_EVAL_H__
#define __GRADEDMC_EVAL_H__

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

#include "graded/mc/Explain.h"
#include "graded/mc/GradedCtl.h"
#include "graded/mc/ModelChecking.h"
#include "graded/utils/GradedUtils.h"

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

EXTERN bdd_ptr GradedMc_evalGradedCtlSpec ARGS((BddFsm_ptr, BddEnc_ptr, node_ptr, node_ptr));

#endif
