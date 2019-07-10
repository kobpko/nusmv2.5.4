/*
 *  GradedUtilsCache.c
 *  
 *
 *  Created by Gabriele Bavota on 15/06/09.
 *
 */

#define graded_tableNull ((GradedCache *) 0)
#define GRADED_CACHE_SIZE 262144

#include "util.h"
#include "cuddInt.h"

static GradedCache * cacheTable;

static int cacheShift;


/**Function********************************************************************

  Synopsis    [Initializes the computed table.]

  Description [Initializes the computed table. It is called by
  Cudd_Init. Returns 1 in case of success; 0 otherwise.]

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
int
GradedUtils_cacheInit()
{
    int i;
    ptruint logSize;
    /* Round cacheSize to largest power of 2 not greater than the requested
    ** initial cache size. */
    
    logSize = cuddComputeFloorLog2(GRADED_CACHE_SIZE);
    cacheShift = sizeof(int)*8 - logSize;

    cacheTable = ALLOC(GradedCache,GRADED_CACHE_SIZE+1);
    if (cacheTable == graded_tableNull){
	printf("ERROR: MEMORY OUT\n");
	return(0);
    }

    /* Initialize the cache */
    for (i = 0; (unsigned) i < GRADED_CACHE_SIZE; i++) {
	cacheTable[i].h = NULL; /* unused slots */
	cacheTable[i].i = NULL; /* unused slots */
	cacheTable[i].data = NULL; /* invalid entry */
	cacheTable[i].f = NULL; /* invalid entry */
	cacheTable[i].g = NULL; /* invalid entry */
    }

    return(1);

} /* end of GradedUtils_cacheInit */


/**Function********************************************************************

  Synopsis    [Flushes the cache.]

  Description []

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
void
GradedUtils_cacheFlush()
{
    FREE(cacheTable);
}


/**Function********************************************************************

  Synopsis    [Frees the cache from dead nodes.]

  Description []

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
void
GradedUtils_cacheFreeDeadNodes()
{
    int i;
    GradedCache *entry;

    for (i = 0; i < GRADED_CACHE_SIZE; i++) {
	entry = &cacheTable[i];
	if (entry->data != NULL) {
	    if (cuddClean(entry->f)->ref == 0 ||
	    cuddClean(entry->g)->ref == 0 ||
	    Cudd_Regular(entry->h)->ref == 0 ||
	    (entry->i != NULL && Cudd_Regular(entry->i)->ref == 0) ||
	    Cudd_Regular(entry->data)->ref == 0) {
		entry->data = NULL;
	    }
	}
    }
}



/**Function********************************************************************

  Synopsis    [Inserts a result in the cache.]

  Description []

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
void
GradedUtils_cacheInsert4(
  ptruint op,
  DdNode * f,
  DdNode * g,
  DdNode * h,
  DdNode * i,
  DdNode * data)
{
    int posn;
    register GradedCache *entry;
    ptruint uf, ug, uh, ui;

    uf = (ptruint) f | (op & 0xe);
    ug = (ptruint) g | (op >> 4);
    uh = (ptruint) h;
    ui = (ptruint) i;

    posn = Graded_CHash(uh,uf,ug,ui);
    entry = &cacheTable[posn];

    entry->f    = (DdNode *) uf;
    entry->g    = (DdNode *) ug;
    entry->h    = h;
    entry->i    = i;
    entry->data = data;

} /* end of GradedUtilsCache_cacheInsert4 */

/**Function********************************************************************

  Synopsis    [Inserts a result in the cache.]

  Description []

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
void
GradedUtils_cacheInsert3(
  ptruint op,
  DdNode * f,
  DdNode * g,
  DdNode * h,
  DdNode * data)
{
    int posn;
    register GradedCache *entry;
    ptruint uf, ug, uh;

    uf = (ptruint) f | (op & 0xe);
    ug = (ptruint) g | (op >> 4);
    uh = (ptruint) h;

    posn = Graded_CHash3(uh,uf,ug);
    entry = &cacheTable[posn];

    entry->f    = (DdNode *) uf;
    entry->g    = (DdNode *) ug;
    entry->h    = h;
    entry->i    = NULL;
    entry->data = data;

} /* end of GradedUtilsCache_cacheInsert3 */


/**Function********************************************************************

  Synopsis    [Looks up in the cache for the result of op applied to f,
  g, and h.]

  Description [Returns the result if found; it returns NULL if no
  result is found.]

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
DdNode *
GradedUtils_cacheLookup4(
  DdManager * dd,
  ptruint op,
  DdNode * f,
  DdNode * g,
  DdNode * h,
  DdNode * i)
{
    
    int posn;
    GradedCache *en;
    DdNode *data;
    ptruint uf, ug, uh, ui;

    uf = (ptruint) f | (op & 0xe);
    ug = (ptruint) g | (op >> 4);
    uh = (ptruint) h;
    ui = (ptruint) i;

    posn = Graded_CHash(uh,uf,ug,ui);
    en = &cacheTable[posn];

    if (en->data != NULL && en->f==(DdNodePtr)uf && en->g==(DdNodePtr)ug &&
	en->h==h && en->i==i) {
	data = Cudd_Regular(en->data);
	if (data->ref == 0) {
	    cuddReclaim(dd,data);
	}
	return(en->data);
    }

    return(NULL);

} /* end of cuddCacheLookup */

/**Function********************************************************************

  Synopsis    [Looks up in the cache for the result of op applied to f,
  g, and h.]

  Description [Returns the result if found; it returns NULL if no
  result is found.]

  SideEffects [None]

  SeeAlso     []

******************************************************************************/
DdNode *
GradedUtils_cacheLookup3(
  DdManager * dd,
  ptruint op,
  DdNode * f,
  DdNode * g,
  DdNode * h)
{
    
    int posn;
    GradedCache *en;
    DdNode *data;
    ptruint uf, ug, uh;

    uf = (ptruint) f | (op & 0xe);
    ug = (ptruint) g | (op >> 4);
    uh = (ptruint) h;

    posn = Graded_CHash3(uh,uf,ug);
    en = &cacheTable[posn];

    if (en->data != NULL && en->f==(DdNodePtr)uf && en->g==(DdNodePtr)ug &&
	en->h==h) {
	data = Cudd_Regular(en->data);
	if (data->ref == 0) {
	    cuddReclaim(dd,data);
	}
	return(en->data);
    }

    return(NULL);

} /* end of cuddCacheLookup */