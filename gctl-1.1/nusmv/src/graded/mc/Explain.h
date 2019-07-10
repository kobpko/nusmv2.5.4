/**CHeaderFile*****************************************************************

  FileName    [Explain.h]

  PackageName [graded/mc]

  Synopsis    [Fair graded-CTL model checking algorithms. External header file.]

  Description [Fair graded-CTL model checking algorithms. External header file.]

  Author      [Alessandro Ferrante]
******************************************************************************/

#ifndef __GRADEDMC_EXPLAIN_H__
#define __GRADEDMC_EXPLAIN_H__

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
#include "utils/assoc.h"
#include "utils/error.h"
#include "utils/ustring.h"
#include "utils/utils.h"
#include "utils/utils_io.h"

#include "graded/mc/Eval.h"
#include "graded/mc/GradedCtl.h"
#include "graded/mc/ModelChecking.h"
#include "graded/utils/GradedUtils.h"

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

static treeNode_ptr GradedMc_explainRecurGraded ARGS((BddFsm_ptr, BddEnc_ptr, BddStates, node_ptr, node_ptr, boolean, boolean));


#endif
