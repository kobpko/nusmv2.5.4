#ifndef _GRADEDUTILS_

#define _GRADEDUTILS_

#include "dd/dd.h"
#include "enc/operators.h"
#include "fsm/bdd/BddFsm.h"
#include "parser/symbols.h"
#include "cuddInt.h"
#include "TreeUtils.h"
#include "be/beInt.h"
#include "compile/compile.h"
#include "compile/symb_table/SymbTable.h"
#include "enc/bdd/BddEnc_private.h"

typedef struct cycleInf *cycleInf_ptr;

typedef struct cycleInf{
       int nStato;
       bdd_ptr stato;
       boolean sink;
} cycleInf;


EXTERN FILE* nusm_stdout;

EXTERN add_ptr GradedUtils_addComposition ARGS((DdManager*, add_ptr, add_ptr, int));

EXTERN add_ptr GradedUtils_fsmCountSuccessors ARGS((BddFsm_ptr, bdd_ptr, int));

EXTERN void GradedUtils_fixPoint ARGS((BddFsm_ptr, bdd_ptr*, bdd_ptr));

EXTERN int GradedUtils_isSubset ARGS((DdManager*, bdd_ptr, bdd_ptr));

EXTERN void GradedUtils_applyReachableAndMask ARGS((BddFsm_ptr, bdd_ptr *));

EXTERN void  GradedUtils_applyReachableAndMaskToTransitions ARGS((BddFsm_ptr, bdd_ptr*));

EXTERN bdd_ptr GradedUtils_andTransition ARGS((BddFsm_ptr, bdd_ptr));

EXTERN void GradedUtils_addSum ARGS((DdManager*, add_ptr*, add_ptr, int));

EXTERN BddStates GradedUtils_getKBackwardImage ARGS((const BddFsm_ptr, BddStates, int));

EXTERN treeNode_ptr GradedUtils_node_ptrToTreeNode_ptr ARGS((BddFsm_ptr, BddEnc_ptr, node_ptr, BddInputs));

DdNode * GradedUtils_addApplyRecur ARGS((DdManager *, ptruint, DdNode *, DdNode *, DdNode * ));

DdNode * GradedUtils_addApply ARGS((DdManager *, ptruint, DdNode *, DdNode *, int));

DdNode * GradedUtils_addAbstract ARGS((DdManager*, add_ptr, bdd_ptr, int));

DdNode * GradedUtils_addAbstractRecur ARGS((DdManager *, ptruint, DdNode *, DdNode *, DdNode *));

DdNode * GradedUtils_AddAndAbstract ARGS((DdManager *,  DdNode *, DdNode *, DdNode *, int));

#endif
