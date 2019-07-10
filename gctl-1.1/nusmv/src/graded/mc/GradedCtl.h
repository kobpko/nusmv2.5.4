/**CHeaderFile*****************************************************************

  FileName    [GradedCtl.h]

  PackageName [graded/mc]

  Synopsis    [Fair graded-CTL model checking algorithms. External header file.]

  Description [Fair graded-CTL model checking algorithms. External header file.]

  Author      [Alessandro Ferrante]
******************************************************************************/

#ifndef __GRADEDMC_GRADEDCTL_H__
#define __GRADEDMC_GRADEDCTL_H__

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
#include "graded/utils/GradedUtils.h"

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

EXTERN BddStates GradedMc_ex ARGS((BddFsm_ptr, BddStates, int));

EXTERN BddStates GradedMc_eu ARGS((BddFsm_ptr, BddStates, BddStates, int));

EXTERN BddStates GradedMc_eg ARGS((BddFsm_ptr, BddStates, int));

EXTERN BddStates GradedMc_ef ARGS((BddFsm_ptr, BddStates, int));

EXTERN BddStates GradedMc_au ARGS((BddFsm_ptr, BddStates, BddStates, int));

EXTERN BddStates GradedMc_ag ARGS((BddFsm_ptr, BddStates, int));

EXTERN BddStates GradedMc_af ARGS((BddFsm_ptr, BddStates, int));

#endif /* __MC_H__ */
