/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "grammar.y" /* yacc.c:339  */

/**CFile***********************************************************************

  FileName    [grammar.y]

  PackageName [parser]

  Synopsis    [Grammar (for Yacc and Bison) of NuSMV input language]

  SeeAlso     [input.l]

  Author      [Andrei Tchaltsev, Marco Roveri]

  Copyright   [
  This file is part of the ``parser'' package of NuSMV version 2.
  Copyright (C) 1998-2005 by CMU and FBK-irst.

  NuSMV version 2 is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  NuSMV version 2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA.

  For more information on NuSMV see <http://nusmv.fbk.eu>
  or email to <nusmv-users@fbk.eu>.
  Please report bugs to <nusmv-users@fbk.eu>.

  To contact the NuSMV development board, email to <nusmv@fbk.eu>. ]

******************************************************************************/

#if HAVE_CONFIG_H
# include "nusmv-config.h"
#endif

#include <setjmp.h>

#if NUSMV_HAVE_MALLOC_H
# if NUSMV_HAVE_SYS_TYPES_H
#  include <sys/types.h>
# endif
# include <malloc.h>
#elif NUSMV_HAVE_SYS_MALLOC_H
# if NUSMV_HAVE_SYS_TYPES_H
#  include <sys/types.h>
# endif
# include <sys/malloc.h>
#elif NUSMV_HAVE_STDLIB_H
# include <stdlib.h>
#endif

#include <limits.h>

#include "parser/parserInt.h"
#include "utils/utils.h"
#include "utils/ustring.h"
#include "node/node.h"
#include "opt/opt.h"
#include "prop/propPkg.h"
#include "utils/error.h"

#include "parser/symbols.h"

static char rcsid[] UTIL_UNUSED = "$Id: grammar.y,v 1.19.4.10.4.46.4.45 2010-02-17 15:13:41 nusmv Exp $";

#define YYMAXDEPTH INT_MAX

#define SYNTAX_ERROR_HANDLING(dest, src) \
  {                                      \
    if (OptsHandler_get_bool_option_value(OptsHandler_get_instance(), \
                                          OPT_PARSER_IS_LAX)) {       \
      dest = src;                                                     \
    }                                                                 \
    else {                                                            \
      YYABORT;                                                        \
    }                                                                 \
 }


node_ptr parsed_tree; /* the returned value of parsing */

enum PARSE_MODE parse_mode_flag; /* the flag what should be parsed */

extern FILE * nusmv_stderr;

void yyerror ARGS((char *s));
void yyerror_lined ARGS((const char *s, int line));
static node_ptr node2maincontext ARGS((node_ptr node));

/* this enum is used to distinguish
   different kinds of expressions: SIMPLE, NEXT, CTL and LTL.
   Since syntactically only one global kind of expressions exists,
   we have to invoke a special function which checks that an expression
   complies to the additional syntactic constrains.
   So, if an ltl-expression is expected then occurrences of NEXT or EBF
   operators will cause the termination of parsing.

   NB: An alternative to invoking a checking function would be to write quite
   intricate syntactic rules to distinguish all the cases.

   NB: This checking function could also be a part of the type checker,
   but it is more straightforward to write a separate function.
*/
  enum EXP_KIND {EXP_SIMPLE, EXP_NEXT, EXP_LTL, EXP_CTL};

  static boolean isCorrectExp ARGS((node_ptr exp, enum EXP_KIND expectedKind));

  static node_ptr build_case_colon_node ARGS((node_ptr l,
                                              node_ptr r,
                                              int linum));

  static int nusmv_parse_psl ARGS((void));

#line 188 "grammar.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_CONSTRAINT = 258,
    TOK_MODULE = 259,
    TOK_PROCESS = 260,
    TOK_CONTEXT = 261,
    TOK_EU = 262,
    TOK_AU = 263,
    TOK_EBU = 264,
    TOK_ABU = 265,
    TOK_MINU = 266,
    TOK_MAXU = 267,
    TOK_VAR = 268,
    TOK_FROZENVAR = 269,
    TOK_IVAR = 270,
    TOK_DEFINE = 271,
    TOK_ARRAY_DEFINE = 272,
    TOK_INIT = 273,
    TOK_TRANS = 274,
    TOK_INVAR = 275,
    TOK_SPEC = 276,
    TOK_CTLSPEC = 277,
    TOK_LTLSPEC = 278,
    TOK_COMPUTE = 279,
    TOK_NAME = 280,
    TOK_PSLSPEC = 281,
    TOK_CONSTANTS = 282,
    TOK_INVARSPEC = 283,
    TOK_FAIRNESS = 284,
    TOK_COMPASSION = 285,
    TOK_JUSTICE = 286,
    TOK_ISA = 287,
    TOK_ASSIGN = 288,
    TOK_OF = 289,
    TOK_CONS = 290,
    TOK_SEMI = 291,
    TOK_LP = 292,
    TOK_RP = 293,
    TOK_RB = 294,
    TOK_LCB = 295,
    TOK_RCB = 296,
    TOK_EQDEF = 297,
    TOK_TWODOTS = 298,
    TOK_SELF = 299,
    TOK_CASE = 300,
    TOK_ESAC = 301,
    TOK_COLON = 302,
    TOK_INCONTEXT = 303,
    TOK_SIMPWFF = 304,
    TOK_NEXTWFF = 305,
    TOK_LTLWFF = 306,
    TOK_LTLPSL = 307,
    TOK_CTLWFF = 308,
    TOK_COMPWFF = 309,
    TOK_COMPID = 310,
    TOK_ARRAY = 311,
    TOK_BOOLEAN = 312,
    TOK_INTEGER = 313,
    TOK_REAL = 314,
    TOK_WORD = 315,
    TOK_BOOL = 316,
    TOK_WORD1 = 317,
    TOK_WAREAD = 318,
    TOK_WAWRITE = 319,
    TOK_SIGNED = 320,
    TOK_UNSIGNED = 321,
    TOK_EXTEND = 322,
    TOK_UWCONST = 323,
    TOK_SWCONST = 324,
    TOK_WRESIZE = 325,
    TOK_WSIZEOF = 326,
    TOK_WTOINT = 327,
    TOK_COUNT = 328,
    TOK_ATOM = 329,
    TOK_FALSEEXP = 330,
    TOK_TRUEEXP = 331,
    TOK_NUMBER = 332,
    TOK_NUMBER_FRAC = 333,
    TOK_NUMBER_REAL = 334,
    TOK_NUMBER_EXP = 335,
    TOK_NUMBER_WORD = 336,
    TOK_COMMA = 337,
    TOK_IMPLIES = 338,
    TOK_IFF = 339,
    TOK_OR = 340,
    TOK_XOR = 341,
    TOK_XNOR = 342,
    TOK_AND = 343,
    TOK_NOT = 344,
    TOK_QUESTIONMARK = 345,
    TOK_EX = 346,
    TOK_AX = 347,
    TOK_EF = 348,
    TOK_AF = 349,
    TOK_EG = 350,
    TOK_AG = 351,
    TOK_EE = 352,
    TOK_AA = 353,
    TOK_SINCE = 354,
    TOK_UNTIL = 355,
    TOK_TRIGGERED = 356,
    TOK_RELEASES = 357,
    TOK_EBF = 358,
    TOK_EBG = 359,
    TOK_ABF = 360,
    TOK_ABG = 361,
    TOK_BUNTIL = 362,
    TOK_MMIN = 363,
    TOK_MMAX = 364,
    TOK_OP_NEXT = 365,
    TOK_OP_GLOBAL = 366,
    TOK_OP_FUTURE = 367,
    TOK_OP_PREC = 368,
    TOK_OP_NOTPRECNOT = 369,
    TOK_OP_HISTORICAL = 370,
    TOK_OP_ONCE = 371,
    TOK_EQUAL = 372,
    TOK_NOTEQUAL = 373,
    TOK_LT = 374,
    TOK_GT = 375,
    TOK_LE = 376,
    TOK_GE = 377,
    TOK_UNION = 378,
    TOK_SETIN = 379,
    TOK_LSHIFT = 380,
    TOK_RSHIFT = 381,
    TOK_LROTATE = 382,
    TOK_RROTATE = 383,
    TOK_MOD = 384,
    TOK_PLUS = 385,
    TOK_MINUS = 386,
    TOK_TIMES = 387,
    TOK_DIVIDE = 388,
    TOK_NEXT = 389,
    TOK_SMALLINIT = 390,
    TOK_CONCATENATION = 391,
    TOK_LB = 392,
    TOK_DOT = 393,
    TOK_BIT = 394,
    TOK_PRED = 395,
    TOK_PREDSLIST = 396,
    TOK_MIRROR = 397
  };
#endif
/* Tokens.  */
#define TOK_CONSTRAINT 258
#define TOK_MODULE 259
#define TOK_PROCESS 260
#define TOK_CONTEXT 261
#define TOK_EU 262
#define TOK_AU 263
#define TOK_EBU 264
#define TOK_ABU 265
#define TOK_MINU 266
#define TOK_MAXU 267
#define TOK_VAR 268
#define TOK_FROZENVAR 269
#define TOK_IVAR 270
#define TOK_DEFINE 271
#define TOK_ARRAY_DEFINE 272
#define TOK_INIT 273
#define TOK_TRANS 274
#define TOK_INVAR 275
#define TOK_SPEC 276
#define TOK_CTLSPEC 277
#define TOK_LTLSPEC 278
#define TOK_COMPUTE 279
#define TOK_NAME 280
#define TOK_PSLSPEC 281
#define TOK_CONSTANTS 282
#define TOK_INVARSPEC 283
#define TOK_FAIRNESS 284
#define TOK_COMPASSION 285
#define TOK_JUSTICE 286
#define TOK_ISA 287
#define TOK_ASSIGN 288
#define TOK_OF 289
#define TOK_CONS 290
#define TOK_SEMI 291
#define TOK_LP 292
#define TOK_RP 293
#define TOK_RB 294
#define TOK_LCB 295
#define TOK_RCB 296
#define TOK_EQDEF 297
#define TOK_TWODOTS 298
#define TOK_SELF 299
#define TOK_CASE 300
#define TOK_ESAC 301
#define TOK_COLON 302
#define TOK_INCONTEXT 303
#define TOK_SIMPWFF 304
#define TOK_NEXTWFF 305
#define TOK_LTLWFF 306
#define TOK_LTLPSL 307
#define TOK_CTLWFF 308
#define TOK_COMPWFF 309
#define TOK_COMPID 310
#define TOK_ARRAY 311
#define TOK_BOOLEAN 312
#define TOK_INTEGER 313
#define TOK_REAL 314
#define TOK_WORD 315
#define TOK_BOOL 316
#define TOK_WORD1 317
#define TOK_WAREAD 318
#define TOK_WAWRITE 319
#define TOK_SIGNED 320
#define TOK_UNSIGNED 321
#define TOK_EXTEND 322
#define TOK_UWCONST 323
#define TOK_SWCONST 324
#define TOK_WRESIZE 325
#define TOK_WSIZEOF 326
#define TOK_WTOINT 327
#define TOK_COUNT 328
#define TOK_ATOM 329
#define TOK_FALSEEXP 330
#define TOK_TRUEEXP 331
#define TOK_NUMBER 332
#define TOK_NUMBER_FRAC 333
#define TOK_NUMBER_REAL 334
#define TOK_NUMBER_EXP 335
#define TOK_NUMBER_WORD 336
#define TOK_COMMA 337
#define TOK_IMPLIES 338
#define TOK_IFF 339
#define TOK_OR 340
#define TOK_XOR 341
#define TOK_XNOR 342
#define TOK_AND 343
#define TOK_NOT 344
#define TOK_QUESTIONMARK 345
#define TOK_EX 346
#define TOK_AX 347
#define TOK_EF 348
#define TOK_AF 349
#define TOK_EG 350
#define TOK_AG 351
#define TOK_EE 352
#define TOK_AA 353
#define TOK_SINCE 354
#define TOK_UNTIL 355
#define TOK_TRIGGERED 356
#define TOK_RELEASES 357
#define TOK_EBF 358
#define TOK_EBG 359
#define TOK_ABF 360
#define TOK_ABG 361
#define TOK_BUNTIL 362
#define TOK_MMIN 363
#define TOK_MMAX 364
#define TOK_OP_NEXT 365
#define TOK_OP_GLOBAL 366
#define TOK_OP_FUTURE 367
#define TOK_OP_PREC 368
#define TOK_OP_NOTPRECNOT 369
#define TOK_OP_HISTORICAL 370
#define TOK_OP_ONCE 371
#define TOK_EQUAL 372
#define TOK_NOTEQUAL 373
#define TOK_LT 374
#define TOK_GT 375
#define TOK_LE 376
#define TOK_GE 377
#define TOK_UNION 378
#define TOK_SETIN 379
#define TOK_LSHIFT 380
#define TOK_RSHIFT 381
#define TOK_LROTATE 382
#define TOK_RROTATE 383
#define TOK_MOD 384
#define TOK_PLUS 385
#define TOK_MINUS 386
#define TOK_TIMES 387
#define TOK_DIVIDE 388
#define TOK_NEXT 389
#define TOK_SMALLINIT 390
#define TOK_CONCATENATION 391
#define TOK_LB 392
#define TOK_DOT 393
#define TOK_BIT 394
#define TOK_PRED 395
#define TOK_PREDSLIST 396
#define TOK_MIRROR 397

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 125 "grammar.y" /* yacc.c:355  */

  node_ptr node;
  int lineno;

#line 517 "grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 534 "grammar.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  313
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  662

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   397

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   233,   233,   234,   237,   238,   239,   243,   245,   247,
     249,   252,   256,   260,   261,   262,   264,   266,   268,   270,
     271,   272,   277,   282,   296,   297,   298,   299,   300,   309,
     318,   324,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   340,   343,   346,   351,   352,   356,   358,   362,
     367,   368,   372,   373,   374,   375,   379,   380,   381,   384,
     385,   386,   392,   393,   394,   397,   398,   402,   403,   406,
     407,   411,   412,   413,   414,   415,   416,   417,   420,   421,
     425,   426,   427,   428,   429,   430,   431,   433,   435,   437,
     439,   440,   441,   442,   445,   451,   452,   455,   456,   457,
     458,   461,   462,   466,   467,   470,   474,   475,   480,   481,
     482,   483,   484,   485,   486,   488,   495,   496,   498,   500,
     507,   517,   518,   522,   523,   524,   525,   529,   530,   534,
     535,   539,   540,   544,   551,   554,   557,   560,   564,   566,
     575,   576,   580,   584,   586,   588,   590,   591,   593,   595,
     599,   600,   601,   605,   606,   609,   610,   611,   612,   615,
     616,   619,   620,   621,   623,   635,   636,   648,   649,   652,
     655,   656,   657,   660,   661,   666,   667,   668,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   700,
     701,   704,   705,   708,   709,   712,   713,   714,   716,   717,
     718,   720,   721,   722,   725,   727,   729,   733,   736,   737,
     738,   741,   743,   756,   760,   761,   762,   766,   767,   771,
     772,   776,   777,   781,   783,   784,   785,   787,   789,   794,
     802,   804,   806,   810,   813,   816,   822,   823,   825,   826,
     829,   830,   832,   833,   834,   835,   838,   839,   842,   843,
     846,   847,   849,   850,   854,   864,   869,   870,   871,   875,
     876,   880,   885,   891,   897,   905,   913,   917,   917,   925,
     926,   927,   928,   929,   938,   939,   940,   941,   942,   949,
     950,   951,   954,   956,   958,   960,   964,   965,   966,   967,
     968,   969,   970,   978,   979,   980,   983,   984,   990,   990,
    1000,  1000,  1007,  1007
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_CONSTRAINT", "TOK_MODULE",
  "TOK_PROCESS", "TOK_CONTEXT", "TOK_EU", "TOK_AU", "TOK_EBU", "TOK_ABU",
  "TOK_MINU", "TOK_MAXU", "TOK_VAR", "TOK_FROZENVAR", "TOK_IVAR",
  "TOK_DEFINE", "TOK_ARRAY_DEFINE", "TOK_INIT", "TOK_TRANS", "TOK_INVAR",
  "TOK_SPEC", "TOK_CTLSPEC", "TOK_LTLSPEC", "TOK_COMPUTE", "TOK_NAME",
  "TOK_PSLSPEC", "TOK_CONSTANTS", "TOK_INVARSPEC", "TOK_FAIRNESS",
  "TOK_COMPASSION", "TOK_JUSTICE", "TOK_ISA", "TOK_ASSIGN", "TOK_OF",
  "TOK_CONS", "TOK_SEMI", "TOK_LP", "TOK_RP", "TOK_RB", "TOK_LCB",
  "TOK_RCB", "TOK_EQDEF", "TOK_TWODOTS", "TOK_SELF", "TOK_CASE",
  "TOK_ESAC", "TOK_COLON", "TOK_INCONTEXT", "TOK_SIMPWFF", "TOK_NEXTWFF",
  "TOK_LTLWFF", "TOK_LTLPSL", "TOK_CTLWFF", "TOK_COMPWFF", "TOK_COMPID",
  "TOK_ARRAY", "TOK_BOOLEAN", "TOK_INTEGER", "TOK_REAL", "TOK_WORD",
  "TOK_BOOL", "TOK_WORD1", "TOK_WAREAD", "TOK_WAWRITE", "TOK_SIGNED",
  "TOK_UNSIGNED", "TOK_EXTEND", "TOK_UWCONST", "TOK_SWCONST",
  "TOK_WRESIZE", "TOK_WSIZEOF", "TOK_WTOINT", "TOK_COUNT", "TOK_ATOM",
  "TOK_FALSEEXP", "TOK_TRUEEXP", "TOK_NUMBER", "TOK_NUMBER_FRAC",
  "TOK_NUMBER_REAL", "TOK_NUMBER_EXP", "TOK_NUMBER_WORD", "TOK_COMMA",
  "TOK_IMPLIES", "TOK_IFF", "TOK_OR", "TOK_XOR", "TOK_XNOR", "TOK_AND",
  "TOK_NOT", "TOK_QUESTIONMARK", "TOK_EX", "TOK_AX", "TOK_EF", "TOK_AF",
  "TOK_EG", "TOK_AG", "TOK_EE", "TOK_AA", "TOK_SINCE", "TOK_UNTIL",
  "TOK_TRIGGERED", "TOK_RELEASES", "TOK_EBF", "TOK_EBG", "TOK_ABF",
  "TOK_ABG", "TOK_BUNTIL", "TOK_MMIN", "TOK_MMAX", "TOK_OP_NEXT",
  "TOK_OP_GLOBAL", "TOK_OP_FUTURE", "TOK_OP_PREC", "TOK_OP_NOTPRECNOT",
  "TOK_OP_HISTORICAL", "TOK_OP_ONCE", "TOK_EQUAL", "TOK_NOTEQUAL",
  "TOK_LT", "TOK_GT", "TOK_LE", "TOK_GE", "TOK_UNION", "TOK_SETIN",
  "TOK_LSHIFT", "TOK_RSHIFT", "TOK_LROTATE", "TOK_RROTATE", "TOK_MOD",
  "TOK_PLUS", "TOK_MINUS", "TOK_TIMES", "TOK_DIVIDE", "TOK_NEXT",
  "TOK_SMALLINIT", "TOK_CONCATENATION", "TOK_LB", "TOK_DOT", "TOK_BIT",
  "TOK_PRED", "TOK_PREDSLIST", "TOK_MIRROR", "$accept", "number",
  "integer", "number_word", "number_frac", "number_real", "number_exp",
  "subrange", "subrangetype", "constant", "primary_expr",
  "count_param_list", "case_element_list_expr", "case_element_expr",
  "concatination_expr", "multiplicative_expr", "additive_expr",
  "shift_expr", "set_expr", "set_list_expr", "union_expr", "in_expr",
  "relational_expr", "ctl_expr", "pure_ctl_expr", "ctl_and_expr",
  "ctl_or_expr", "ctl_iff_expr", "ctl_implies_expr", "ctl_basic_expr",
  "ltl_unary_expr", "pure_ltl_unary_expr", "ltl_binary_expr", "and_expr",
  "or_expr", "ite_expr", "iff_expr", "implies_expr", "basic_expr",
  "simple_expression", "next_expression", "ctl_expression",
  "ltl_expression", "compute_expression", "itype", "type",
  "type_value_list", "type_value", "complex_atom", "module_type",
  "next_list_expression", "module_list", "module", "module_sign",
  "atom_list", "declarations", "declaration", "var", "frozen_var",
  "input_var", "var_decl_list", "fvar_decl_list", "ivar_decl_list",
  "var_decl", "fvar_decl", "ivar_decl", "define_decls", "define_list",
  "define", "array_define", "array_define_list", "array_expression",
  "array_expression_list", "array_contents", "assign", "assign_list",
  "one_assign", "init", "invar", "trans", "fairness", "justice",
  "compassion", "_invarspec", "invarspec", "_ctlspec", "ctlspec",
  "_ltlspec", "ltlspec", "_compute", "compute", "pslspec", "constants",
  "constants_expression", "predicate_list", "predicate", "mirror", "isa",
  "optsemi", "decl_var_id", "var_id", "command", "command_case", "context",
  "_simpwff", "begin", "$@1", "$@2", "$@3", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397
};
# endif

#define YYPACT_NINF -428

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-428)))

#define YYTABLE_NINF -311

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,    30,    36,   344,  1573,  -428,     9,    36,  -428,   119,
    1573,  1573,  1573,  1573,  1573,  1573,  1573,  1573,   147,    25,
     -70,  -428,  -428,  1573,  1573,  -428,  1573,   154,   163,   228,
     260,   276,   280,   282,   290,   302,   309,   311,   313,   315,
    -428,  -428,  -428,   232,  -428,  -428,  -428,  -428,  1653,  1733,
    1733,  1733,  1733,  1733,  1733,   151,   259,   -40,   -40,   -40,
     -40,  1573,  1573,  1573,  1573,  1573,  1573,  1573,   299,  2070,
     367,  -428,   362,  -428,  -428,  -428,  -428,  -428,  -428,   164,
     270,   167,   239,   242,  -428,   284,   285,   173,  -428,  -428,
    -428,  -428,   257,   320,   251,  -428,   288,  -428,  -428,  -428,
     373,  -428,  -428,  -428,  -428,   375,   376,  -428,   377,   378,
     172,  -428,   195,  -428,   204,  -428,  -428,   236,  -428,   278,
     279,   237,  -428,  -428,  -428,    -9,  1253,   -70,  -428,   380,
      22,  -428,   374,  1573,   372,  1573,  1573,  1573,  1573,  1573,
    1573,  1573,  1573,  1573,  1573,  1573,  1573,  2116,  -428,   347,
    2116,   164,  -428,  -428,  1807,  -428,  -428,  -428,  -428,  -428,
    -428,  1733,  1733,  -428,   348,   349,  1733,  1733,  1733,  1733,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,   384,   385,  2116,
     164,  1573,   -40,  1573,    34,  2116,  2116,  2116,  2116,  2116,
    2116,  2116,  2116,  1978,  1978,  1978,  1978,  1978,  1978,  1978,
    1978,  1573,  1573,  1573,  1573,  1573,  1573,  1573,  1573,  1573,
    1573,  1573,    -3,   842,  -428,  -428,  -428,  -428,  -428,   355,
    -428,   355,  -428,   355,  -428,   355,  -428,  1573,  1573,   355,
    -428,  -428,  1573,    48,    25,   354,   396,  -428,  -428,  -428,
    1573,  -428,  -428,  1573,   383,   397,   352,   356,   398,   399,
     357,   358,   361,   363,   406,   408,   -49,   409,  -428,  -428,
     360,   238,   291,  -428,   174,   180,  -428,  -428,  -428,  -428,
    -428,  -428,   411,  -428,   412,   403,   413,  -428,  -428,   164,
     270,   270,   270,   167,   167,   239,   239,  -428,   284,   285,
     285,   285,   285,   285,   285,  -428,  -428,  -428,  -428,   257,
     320,   320,   320,   407,  -428,  -428,  -428,  -428,    23,  -428,
     379,   379,   379,  -428,  -428,  1573,  1573,  1573,   927,  1009,
    1091,    31,  -428,   381,  1173,  1573,   419,  1573,   386,  -428,
     379,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,    -4,    -4,    -4,    -4,   382,   387,
      -4,   418,  -428,  -428,   121,   420,  -428,  -428,   422,  -428,
    -428,  1573,  1573,  -428,  -428,  1573,  2116,  2116,  1573,  -428,
    -428,  2116,  -428,  1733,  1733,  1733,  1733,  1733,  1733,  1733,
     -40,  1733,   -40,  -428,  1573,  -428,  1573,  -428,   388,  -428,
     643,  -428,    37,   677,  -428,    39,   712,  -428,    72,   746,
     808,   396,   396,   396,    25,  -428,    25,  -428,    25,  -428,
      25,  -428,  -428,   327,    13,    25,  -428,   396,  1573,   396,
    -428,   487,    12,  1573,   392,  -428,  -428,  -428,  -428,  1573,
    1573,  -428,  -428,   425,  1413,  -428,   430,   389,   432,    98,
     123,   434,  -428,  -428,   360,   360,   360,  -428,   238,   435,
    1733,   436,  1733,   437,  -428,  -428,  -428,  -428,   839,   -46,
     104,  -428,  -428,  1886,  -428,  -428,  1886,  -428,  -428,    15,
    -428,    61,  -428,  -428,  -428,    65,    79,    81,    88,   404,
    -428,   381,   129,  -428,   391,  -428,  -428,   440,   442,  -428,
     131,  -428,   443,  -428,   444,   445,  1573,    25,   396,  -428,
    1573,  -428,  -428,  -428,  -428,  -428,   447,  -428,   450,  -428,
     132,   -30,  2024,  -428,  -428,  -428,   353,     5,    60,   342,
    -428,   111,  -428,   456,  -428,   454,   417,  -428,  -428,  2024,
     460,   461,  1333,   390,  1573,  1573,  1573,   147,  -428,   327,
    1573,  1573,    25,    25,  1573,  -428,  -428,  -428,   396,   133,
    -428,   474,  -428,  -428,  2116,   484,  -428,  -428,  -428,  -428,
      27,  -428,   327,   393,   464,  1573,   395,   400,  1493,  2116,
    -428,  -428,   483,   489,  -428,  -428,  1333,   488,   490,   492,
    -428,  -428,  -428,  -428,  -428,   491,    42,    49,   497,  -428,
     439,  -428,   500,  -428,   -30,  1573,  1932,   486,  1573,  1573,
    -428,  -428,    24,   242,  -428,  1886,   453,   457,   499,   503,
    -428,  -428,  -428,   396,   494,   507,  -428,  1573,   132,  -428,
     511,  -428,  -428,  -428,   512,   514,  -428,  1573,  1573,   390,
    -428,  -428,  -428,  1573,  1573,   396,   520,  -428,  -428,  -428,
    -428,  -428,   519,   521,  -428,   496,  -428,  -428,   421,  1573,
     523,  -428
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     312,     0,     0,     0,     0,     1,     0,   309,   167,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   311,   289,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    13,    14,     2,     8,     9,    10,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,    20,    21,    23,    22,    63,    24,    50,
      52,    56,    59,    62,    67,    69,    71,    78,   106,    79,
     116,   107,   121,   123,   127,   129,   131,   133,   137,   313,
     170,   175,   168,   290,   134,     0,     0,   135,     0,     0,
     277,   296,   277,   297,   277,   299,   136,   277,   298,     0,
       0,   277,   300,   285,   284,     0,     0,   302,   269,     0,
       0,    65,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,    33,    94,   115,     0,    80,    81,    82,    83,    84,
      85,     0,     0,     4,     0,     0,     0,     0,     0,     0,
     108,   111,   113,   109,   110,   112,   114,     3,     2,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   292,   294,   293,   278,     0,
     306,     0,   246,     0,   256,     0,   250,     0,     0,     0,
     260,   301,     0,     0,     0,     0,   277,   270,    32,    64,
       0,    41,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     3,    95,
      97,   101,   103,   105,     0,     0,     5,     6,    90,    92,
      91,    93,     0,    11,   134,     0,     0,    28,    29,    51,
      55,    53,    54,    57,    58,    60,    61,    68,    70,    72,
      73,    74,    75,    76,    77,   118,   117,   120,   119,   122,
     124,   125,   126,     0,   132,   130,   171,   173,     0,   177,
     199,   201,   203,   218,   224,     0,     0,     0,     0,     0,
       0,     0,   264,   266,     0,     0,     0,     0,     0,   234,
       0,   176,   179,   180,   181,   186,   187,   182,   183,   184,
     185,   188,   189,   190,   191,   192,   193,   195,   194,   196,
     197,   198,   178,   303,   277,   277,   277,   277,     0,     0,
     277,     0,   286,   287,     0,     0,   271,    66,     0,    34,
      35,     0,     0,    37,    38,     0,     0,     0,     0,    17,
      18,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    30,     0,   172,     0,   279,
       0,   205,     0,     0,   208,     0,     0,   211,     0,     0,
       0,   277,   277,   277,     0,   252,     0,   253,     0,   258,
       0,   262,   159,   267,     0,     0,   248,   277,     0,   277,
     276,     0,   277,     0,     0,   307,   247,   257,   251,     0,
       0,   261,   288,     0,     0,    49,     0,     0,     0,     0,
       0,     0,    46,    96,    98,    99,   100,   104,   102,     0,
       0,     0,     0,     0,   128,   174,   207,   206,     0,     0,
       0,   210,   209,     0,   213,   212,     0,   220,   219,     0,
     226,     0,   240,   242,   241,     0,     0,     0,     0,     0,
     265,     0,     0,   243,     0,   244,   236,     0,     0,   235,
       0,   275,     0,   304,     0,     0,     0,     0,   277,    42,
       0,    39,    15,    16,    40,    87,     0,    86,     0,    31,
       0,     0,     0,   140,   141,   142,     0,     0,     0,    26,
     146,     0,   150,     0,   151,     0,     0,   280,   281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   268,
       0,     0,     0,     0,     0,   305,   138,   139,   277,     0,
     272,     0,    89,    88,     0,   161,   152,   157,   158,   156,
       0,   153,   155,     0,     0,     0,     0,     0,     0,     0,
     214,   282,     0,     0,   215,   216,     0,     0,     0,     0,
     254,   255,   259,   263,   249,     0,     0,     0,     0,   273,
       0,    43,     0,   147,     0,     0,     0,     0,     0,     0,
     162,   165,     0,    12,   283,     0,   232,   229,     0,     0,
     221,   222,   225,   277,     0,     0,   237,     0,     0,   154,
       0,   149,   164,   143,     0,     0,   163,     0,     0,     0,
     228,   227,   245,     0,     0,   277,     0,   145,   144,   166,
     231,   230,     0,     0,   274,     0,   239,   238,     0,     0,
       0,   148
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -428,  -428,  -181,  -428,  -428,  -428,  -428,   -37,  -278,  -428,
      10,   178,   427,  -428,   144,   192,   209,  -317,   370,  -428,
     371,   112,  -428,     1,   -44,   -42,   181,  -428,   179,  -157,
      11,   522,   366,   158,  -428,  -203,  -428,   364,     2,   -11,
      -1,  -212,   564,  -428,  -222,  -428,  -428,   -32,  -294,  -427,
    -428,  -428,   566,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,   175,   176,   170,  -428,  -428,  -428,  -428,
    -428,  -140,   -61,   -57,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -315,  -428,  -306,  -428,  -313,  -428,  -297,
    -428,  -428,  -428,  -428,  -428,   -89,  -428,  -428,   -78,  -146,
    -224,  -428,  -428,  -127,  -428,  -428,  -428,  -428,  -428
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    71,    72,    73,    74,    75,    76,    77,   530,    78,
      79,   257,   132,   133,    80,    81,    82,    83,    84,   130,
      85,    86,    87,    88,    89,   260,   261,   262,   263,   264,
      90,    91,    92,    93,    94,    95,    96,    97,   104,   105,
     112,   117,   114,   121,   631,   533,   570,   571,   572,   632,
     612,     7,     8,   101,   308,   213,   331,   332,   333,   334,
     400,   403,   406,   401,   404,   407,   335,   409,   478,   336,
     410,   617,   618,   619,   337,   431,   499,   338,   339,   340,
     341,   342,   343,   113,   344,   118,   345,   115,   346,   122,
     347,   348,   349,   424,   127,   128,   351,   352,   220,   402,
     125,    21,    22,   354,   111,     1,     2,     3,     4
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   273,   109,   110,   152,   265,    98,   419,   305,   426,
     364,   108,   415,   417,   107,   358,   359,   107,    98,   116,
     166,   167,   168,   169,   421,   129,   131,   231,   134,   423,
       5,   535,   218,   381,   222,   306,   224,   163,   237,   226,
       6,   534,   139,   230,   422,   567,   568,   163,   218,   490,
     155,   156,   157,   158,   159,   160,   420,   542,   151,   449,
     450,   397,   636,   239,  -310,   576,  -310,  -308,   603,   123,
     126,   307,   170,   171,   172,   173,   174,   175,   176,   180,
     624,  -310,  -310,   100,   468,   536,   473,   625,   183,   184,
     164,   165,  -310,   566,   355,   491,   356,   140,   357,   124,
     164,   165,   360,   543,   240,   398,   637,   544,   277,   604,
     152,   278,  -310,  -310,  -310,   236,  -310,  -310,  -310,   476,
     577,   545,   362,   546,   350,   363,   246,   247,   232,   233,
     547,   251,   252,   433,   434,   134,   512,   244,   245,   119,
     120,   248,   249,   250,   254,   255,   253,   107,   107,   469,
     470,   531,   469,   470,   579,   103,   531,   256,   366,   531,
     180,   513,   259,   259,   151,   405,   408,   268,   269,   270,
     271,   550,   275,   554,   469,   470,   469,   470,   537,   232,
     233,   538,   276,   272,   432,   274,   232,   233,   564,   151,
     485,   135,   486,   464,   487,   279,   488,   549,   469,   470,
     136,   492,   232,   233,  -310,   531,   565,   500,   218,   469,
     470,   303,   295,   296,   297,   298,   232,   233,   232,   233,
     219,   361,   531,   191,   192,   232,   233,   504,   505,   116,
     116,   218,   459,   592,   461,   594,   191,   192,   590,   591,
     218,   443,   367,   221,   574,   368,   532,   531,   191,   192,
     593,   540,   223,   600,   541,   119,   120,   405,   232,   233,
     408,   583,   613,   479,   481,   137,   232,   233,   232,   233,
     232,   233,   218,   218,   389,    -4,   435,   436,   437,   438,
     391,   390,   441,   559,   225,   229,   602,   392,   161,   531,
     195,   196,   197,   198,   199,   200,   186,   138,   531,   187,
     188,   183,   184,   516,   411,   518,   413,   289,   290,   291,
     292,   293,   294,   139,   427,   412,   429,   140,   107,   141,
     116,   116,    98,   384,   385,   386,   107,   142,   596,   597,
     280,   281,   282,   482,   483,   484,   206,   207,   208,   143,
     569,   209,   454,   455,   456,     9,   144,    10,   145,   493,
     146,   495,   147,   460,   501,   462,   201,   202,   203,   204,
     446,   447,    11,    12,   300,   301,   302,   191,   192,   189,
     190,   210,   211,    13,   387,   388,   177,   448,  -161,   578,
     451,   283,   284,   463,   453,   259,   259,   259,   259,   259,
     259,   256,   259,    14,    15,    16,   162,    17,    18,    19,
     285,   286,   588,   589,   181,   182,   185,   193,   205,   194,
     212,   214,   215,   216,   217,   227,   228,   494,   238,   243,
     241,   369,   502,   569,   258,   266,   267,    -5,    -6,   353,
     560,   365,   218,   508,   371,   370,   373,   374,   372,   375,
     376,   116,   116,   377,   379,   378,   380,   382,   383,   393,
     394,  -135,   395,   399,   396,   422,   428,   442,   445,   444,
     430,   259,   465,   259,   439,   489,   503,   506,   509,   440,
     511,   510,   514,   551,   515,   517,   519,   552,   548,   553,
     599,   627,   555,   556,   557,    20,   562,  -233,   496,   563,
     575,  -233,   580,   581,   582,   558,   584,   585,   606,   561,
    -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,  -233,   601,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,   578,   614,   615,   620,   633,   621,   586,   622,   623,
     605,   123,   608,   626,   628,   638,   643,   609,   640,   639,
     595,   587,   641,   598,   107,   642,   116,   116,    98,   644,
     646,   647,   107,   648,   655,   656,   658,   657,   659,   452,
     242,   124,   661,   287,   607,   288,   457,   654,    99,   458,
     153,   299,   629,   102,   304,   467,   475,   611,   651,   472,
     107,   650,     0,     0,     0,   616,     0,     0,   107,     0,
       0,     0,     0,     0,   630,     0,     0,   634,   635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   645,     0,     0,     0,
       0,   497,   498,     0,     0,     0,     0,  -233,     0,  -233,
       0,     0,     0,   653,     0,     0,   649,   616,     0,   107,
     107,     0,   652,  -200,   466,   107,     0,  -200,   660,     0,
       0,     0,     0,     0,     0,     0,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,     0,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -202,   471,     0,
       0,  -202,     0,     0,     0,     0,     0,     0,     0,     0,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,     0,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,     0,  -204,   474,     0,     0,  -204,   399,     0,     0,
       0,     0,     0,     0,     0,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,     0,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -217,   477,     0,     0,
    -217,   399,     0,     0,     0,     0,     0,     0,     0,  -217,
    -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
    -217,     0,  -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
       0,     0,     0,  -200,     0,  -200,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -223,   480,
       0,     0,  -223,     0,     0,     0,     0,  -202,     0,  -202,
     399,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,     0,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -169,   309,   520,     0,  -169,     0,     0,     0,
       0,     0,  -204,     0,  -204,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,     0,   322,   323,
     324,   325,   326,   327,   328,   329,    23,     0,     0,   521,
       0,     0,   399,    25,    26,     0,  -217,     0,  -217,     0,
       0,     0,     0,     0,     0,   522,   523,   524,   525,   526,
      27,    28,    29,    30,   527,   528,    33,    34,    35,    36,
      37,    38,    39,   529,    41,    42,   148,    44,    45,    46,
      47,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -223,     0,
    -223,     0,   414,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,    24,     0,   149,
     150,    25,    26,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   330,     0,     0,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,     0,    48,     0,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,    60,   416,     0,     0,    61,    62,    63,
      64,    65,    66,    67,     0,     0,    23,     0,     0,    24,
       0,     0,     0,    25,    26,     0,     0,    68,    69,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,     0,     0,     0,     0,    48,     0,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,    57,    58,    59,    60,   418,     0,     0,    61,
      62,    63,    64,    65,    66,    67,     0,     0,    23,     0,
       0,    24,     0,     0,     0,    25,    26,     0,     0,    68,
      69,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
      48,     0,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,    57,    58,    59,    60,   425,     0,
       0,    61,    62,    63,    64,    65,    66,    67,     0,     0,
      23,     0,     0,    24,     0,     0,     0,    25,    26,     0,
       0,    68,    69,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      23,     0,     0,    24,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    68,    69,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      23,     0,   234,    24,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    68,    69,     0,     0,    70,     0,     0,
     235,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      23,     0,     0,    24,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    68,    69,     0,     0,    70,     0,     0,
     586,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      23,   610,   507,    24,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    68,    69,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      23,     0,     0,    24,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    68,    69,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      23,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    68,    69,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     148,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      23,     0,     0,    24,     0,     0,     0,    25,    26,     0,
       0,     0,     0,   149,   150,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,   154,     0,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,     0,     0,    70,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   148,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,     0,   154,     0,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,     0,     0,   521,     0,     0,     0,
      25,    26,     0,     0,     0,     0,     0,   149,   150,     0,
       0,    70,   539,   523,   524,   525,   526,    27,    28,    29,
      30,   527,   528,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   148,    44,    45,    46,    47,     0,    23,
       0,     0,   521,     0,     0,   179,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,   523,
     524,   525,   526,    27,    28,    29,    30,   527,   528,    33,
      34,    35,    36,    37,    38,    39,   529,    41,    42,   148,
      44,    45,    46,    47,     0,    23,   149,   150,    24,     0,
      70,   179,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    23,   149,   150,     0,     0,    70,   179,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   573,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   148,    44,    45,    46,    47,     0,    23,    68,    69,
       0,     0,    70,   179,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   178,    44,    45,
      46,    47,     0,    23,   149,   150,     0,     0,    70,   179,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   148,    44,    45,    46,    47,     0,     0,
     149,   150,     0,     0,    70,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   150,     0,     0,
      70
};

static const yytype_int16 yycheck[] =
{
      11,   182,    13,    14,    48,   162,     4,   320,   211,   324,
     234,    12,   318,   319,    12,   227,   228,    15,    16,    17,
      57,    58,    59,    60,   321,    23,    24,    36,    26,   323,
       0,    77,    36,    82,   112,    38,   114,    77,   127,   117,
       4,   468,    37,   121,    74,    75,    76,    77,    36,    36,
      49,    50,    51,    52,    53,    54,    25,    42,    48,   376,
     377,    38,    38,    41,     1,    60,     3,     4,    41,    44,
     140,    74,    61,    62,    63,    64,    65,    66,    67,    69,
      38,    18,    19,    74,    47,   131,    47,    38,   137,   138,
     130,   131,    29,   520,   221,    82,   223,    37,   225,    74,
     130,   131,   229,    42,    82,    82,    82,    42,    74,    82,
     154,    77,    49,    50,    51,   126,    53,    54,    55,    47,
      60,    42,    74,    42,   213,    77,   137,   138,   137,   138,
      42,   142,   143,   137,   138,   133,    38,   135,   136,   108,
     109,   139,   140,   141,   145,   146,   144,   145,   146,   137,
     138,   468,   137,   138,    43,    36,   473,   147,   236,   476,
     150,    38,   161,   162,   154,   311,   312,   166,   167,   168,
     169,    42,   183,    42,   137,   138,   137,   138,    74,   137,
     138,    77,   183,   181,   330,   183,   137,   138,    56,   179,
     414,    37,   416,   396,   418,   185,   420,   491,   137,   138,
      37,   425,   137,   138,   141,   522,    74,   431,    36,   137,
     138,   209,   201,   202,   203,   204,   137,   138,   137,   138,
      48,   232,   539,   125,   126,   137,   138,   439,   440,   227,
     228,    36,   389,   546,   391,   550,   125,   126,   544,   545,
      36,   120,   240,    48,   522,   243,   468,   564,   125,   126,
     547,   473,    48,   120,   476,   108,   109,   403,   137,   138,
     406,   539,   579,   409,   410,    37,   137,   138,   137,   138,
     137,   138,    36,    36,   100,    43,   354,   355,   356,   357,
     100,   107,   360,   507,    48,    48,   564,   107,   137,   606,
     117,   118,   119,   120,   121,   122,   129,    37,   615,   132,
     133,   137,   138,   460,   315,   462,   317,   195,   196,   197,
     198,   199,   200,    37,   325,   316,   327,    37,   316,    37,
     318,   319,   320,    85,    86,    87,   324,    37,   552,   553,
     186,   187,   188,   411,   412,   413,    85,    86,    87,    37,
     521,    90,   384,   385,   386,     1,    37,     3,    37,   427,
      37,   429,    37,   390,   432,   392,    99,   100,   101,   102,
     371,   372,    18,    19,   206,   207,   208,   125,   126,   130,
     131,    83,    84,    29,    83,    84,    77,   375,    36,    37,
     378,   189,   190,   394,   383,   384,   385,   386,   387,   388,
     389,   381,   391,    49,    50,    51,   137,    53,    54,    55,
     191,   192,   542,   543,    37,    43,   136,   123,    88,   124,
      37,    36,    36,    36,    36,   137,   137,   428,    38,    47,
      46,    38,   433,   604,    77,    77,    77,    43,    43,    74,
     508,    77,    36,   444,    82,    38,    38,    38,    82,    82,
      82,   439,   440,    82,    38,    82,    38,    38,    88,    38,
      47,    39,    39,    74,    47,    74,    37,    39,    36,    39,
      74,   460,    74,   462,    82,   138,    74,    42,    38,    82,
      38,    82,    38,    82,    39,    39,    39,    37,    74,    37,
     558,    42,    39,    39,    39,   141,    39,     0,     1,    39,
     137,     4,    36,    39,    77,   506,    36,    36,    34,   510,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    38,    26,    27,    28,    29,    30,    31,    32,
      33,    37,    39,    34,    36,    39,    36,   137,    36,    38,
     137,    44,   137,    36,    34,    82,    42,   137,    39,    82,
     551,   542,    39,   554,   542,   623,   544,   545,   546,    42,
      39,    39,   550,    39,    34,    36,    60,    36,   137,   381,
     133,    74,    39,   193,   575,   194,   387,   645,     4,   388,
      48,   205,   604,     7,   210,   400,   406,   578,   639,   403,
     578,   638,    -1,    -1,    -1,   586,    -1,    -1,   586,    -1,
      -1,    -1,    -1,    -1,   605,    -1,    -1,   608,   609,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,
      -1,   134,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,
      -1,    -1,    -1,   644,    -1,    -1,   637,   638,    -1,   637,
     638,    -1,   643,     0,     1,   643,    -1,     4,   659,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,     0,     1,    -1,    -1,     4,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     1,    -1,    -1,
       4,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,   140,    -1,   142,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,   140,    -1,   142,
      74,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     1,     5,    -1,     4,    -1,    -1,    -1,
      -1,    -1,   140,    -1,   142,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    37,    -1,    -1,    40,
      -1,    -1,    74,    44,    45,    -1,   140,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
     142,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    -1,   130,
     131,    44,    45,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,   142,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,    25,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    37,    -1,    -1,    40,
      -1,    -1,    -1,    44,    45,    -1,    -1,   130,   131,    -1,
      -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,    25,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    37,    -1,
      -1,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,   130,
     131,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,    25,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
      37,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,   130,   131,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      37,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      37,    -1,   119,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,
     137,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      37,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,
     137,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      37,    38,   119,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      37,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      37,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
      -1,   134,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    37,
      -1,    -1,    40,    -1,    -1,    89,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    37,   130,   131,    40,    -1,
     134,    89,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    37,   130,   131,    -1,    -1,   134,    89,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    37,   130,   131,
      -1,    -1,   134,    89,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    37,   130,   131,    -1,    -1,   134,    89,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
     130,   131,    -1,    -1,   134,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,    -1,
     134
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   248,   249,   250,   251,     0,     4,   194,   195,     1,
       3,    18,    19,    29,    49,    50,    51,    53,    54,    55,
     141,   244,   245,    37,    40,    44,    45,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    89,    91,
      92,    93,    94,    95,    96,    97,    98,   103,   104,   105,
     106,   110,   111,   112,   113,   114,   115,   116,   130,   131,
     134,   144,   145,   146,   147,   148,   149,   150,   152,   153,
     157,   158,   159,   160,   161,   163,   164,   165,   166,   167,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   185,
      74,   196,   195,    36,   181,   182,   182,   181,   183,   182,
     182,   247,   183,   226,   185,   230,   181,   184,   228,   108,
     109,   186,   232,    44,    74,   243,   140,   237,   238,   181,
     162,   181,   155,   156,   181,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    77,   130,
     131,   153,   167,   174,    89,   166,   166,   166,   166,   166,
     166,   137,   137,    77,   130,   131,   150,   150,   150,   150,
     173,   173,   173,   173,   173,   173,   173,    77,    77,    89,
     153,    37,    43,   137,   138,   136,   129,   132,   133,   130,
     131,   125,   126,   123,   124,   117,   118,   119,   120,   121,
     122,    99,   100,   101,   102,    88,    85,    86,    87,    90,
      83,    84,    37,   198,    36,    36,    36,    36,    36,    48,
     241,    48,   241,    48,   241,    48,   241,   137,   137,    48,
     241,    36,   137,   138,   119,   137,   182,   238,    38,    41,
      82,    46,   155,    47,   181,   181,   182,   182,   181,   181,
     181,   182,   182,   181,   183,   183,   153,   154,    77,   166,
     168,   169,   170,   171,   172,   172,    77,    77,   166,   166,
     166,   166,   181,   145,   181,   182,   183,    74,    77,   153,
     157,   157,   157,   158,   158,   159,   159,   161,   163,   164,
     164,   164,   164,   164,   164,   173,   173,   173,   173,   175,
     176,   176,   176,   181,   180,   178,    38,    74,   197,     1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    26,    27,    28,    29,    30,    31,    32,    33,
     142,   199,   200,   201,   202,   209,   212,   217,   220,   221,
     222,   223,   224,   225,   227,   229,   231,   233,   234,   235,
     238,   239,   240,    74,   246,   246,   246,   246,   184,   184,
     246,   182,    74,    77,   243,    77,   241,   181,   181,    38,
      38,    82,    82,    38,    38,    82,    82,    82,    82,    38,
      38,    82,    38,    88,    85,    86,    87,    83,    84,   100,
     107,   100,   107,    38,    47,    39,    47,    38,    82,    74,
     203,   206,   242,   204,   207,   242,   205,   208,   242,   210,
     213,   182,   183,   182,    25,   228,    25,   228,    25,   230,
      25,   232,    74,   191,   236,    25,   226,   182,    37,   182,
      74,   218,   242,   137,   138,   241,   241,   241,   241,    82,
      82,   241,    39,   120,    39,    36,   182,   182,   181,   160,
     160,   181,   154,   166,   168,   168,   168,   171,   169,   172,
     150,   172,   150,   182,   178,    74,     1,   206,    47,   137,
     138,     1,   207,    47,     1,   208,    47,     1,   211,   242,
       1,   242,   241,   241,   241,   243,   243,   243,   243,   138,
      36,    82,   243,   241,   182,   241,     1,   134,   135,   219,
     243,   241,   182,    74,   184,   184,    42,   119,   182,    38,
      82,    38,    38,    38,    38,    39,   172,    39,   172,    39,
       5,    40,    56,    57,    58,    59,    60,    65,    66,    74,
     151,   160,   187,   188,   192,    77,   131,    74,    77,    56,
     187,   187,    42,    42,    42,    42,    42,    42,    74,   191,
      42,    82,    37,    37,    42,    39,    39,    39,   182,   243,
     241,   182,    39,    39,    56,    74,   192,    75,    76,   145,
     189,   190,   191,    60,   151,   137,    60,    60,    37,    43,
      36,    39,    77,   151,    36,    36,   137,   183,   214,   214,
     228,   228,   230,   232,   226,   182,   243,   243,   182,   241,
     120,    38,   151,    41,    82,   137,    34,   182,   137,   137,
      38,   183,   193,   160,    39,    34,   183,   214,   215,   216,
      36,    36,    36,    38,    38,    38,    36,    42,    34,   190,
     182,   187,   192,    39,   182,   182,    38,    82,    82,    82,
      39,    39,   241,    42,    42,   182,    39,    39,    39,   183,
     216,   215,   183,   182,   241,    34,    36,    36,    60,   137,
     182,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   143,   144,   144,   145,   145,   145,   146,   147,   148,
     149,   150,   151,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     157,   157,   158,   158,   158,   158,   159,   159,   159,   160,
     160,   160,   161,   161,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   165,   165,   165,   165,   165,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   168,   168,   169,   169,   169,
     169,   170,   170,   171,   171,   172,   173,   173,   174,   174,
     174,   174,   174,   174,   174,   174,   175,   175,   175,   175,
     175,   176,   176,   177,   177,   177,   177,   178,   178,   179,
     179,   180,   180,   181,   182,   183,   184,   185,   186,   186,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     188,   188,   188,   189,   189,   190,   190,   190,   190,   191,
     191,   192,   192,   192,   192,   193,   193,   194,   194,   195,
     196,   196,   196,   197,   197,   198,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   200,
     200,   201,   201,   202,   202,   203,   203,   203,   204,   204,
     204,   205,   205,   205,   206,   207,   208,   209,   210,   210,
     210,   211,   211,   212,   213,   213,   213,   214,   214,   215,
     215,   216,   216,   217,   218,   218,   218,   219,   219,   219,
     220,   221,   222,   223,   224,   225,   226,   226,   227,   227,
     228,   228,   229,   229,   229,   229,   230,   230,   231,   231,
     232,   232,   233,   233,   234,   235,   236,   236,   236,   237,
     237,   238,   238,   238,   238,   239,   240,   241,   241,   242,
     242,   242,   242,   242,   243,   243,   243,   243,   243,   244,
     244,   244,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   246,   246,   246,   247,   247,   249,   248,
     250,   248,   251,   248
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     3,     3,     1,     1,     6,     6,     4,     4,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     3,     3,
       4,     6,     3,     2,     4,     4,     4,     4,     4,     6,
       6,     3,     6,     8,     4,     1,     3,     1,     2,     4,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       2,     2,     2,     2,     2,     2,     6,     6,     7,     7,
       3,     3,     3,     3,     2,     1,     3,     1,     3,     3,
       3,     1,     3,     1,     3,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     3,     3,
       3,     1,     3,     1,     3,     3,     3,     1,     5,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     6,     6,
       1,     1,     1,     4,     5,     5,     1,     3,    10,     4,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     3,     4,     4,     1,     3,     1,     2,     3,
       1,     3,     4,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     2,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     4,     4,     4,     2,     0,     2,
       2,     4,     4,     2,     0,     5,     2,     3,     3,     1,
       3,     3,     1,     2,     0,     2,     2,     4,     7,     7,
       3,     3,     3,     3,     3,     7,     2,     4,     2,     5,
       2,     4,     2,     2,     5,     5,     2,     4,     2,     5,
       2,     4,     2,     5,     1,     3,     0,     1,     3,     1,
       2,     3,     6,     7,    10,     3,     2,     0,     1,     1,
       3,     3,     4,     5,     1,     1,     3,     3,     4,     1,
       2,     1,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     3,     2,     1,     3,     4,     2,     4,     0,     2,
       0,     2,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 234 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2439 "grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 238 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2445 "grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 240 "grammar.y" /* yacc.c:1646  */
    {node_int_setcar((yyvsp[0].node), -(node_get_int((yyvsp[0].node)))); (yyval.node) = (yyvsp[0].node);}
#line 2451 "grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 253 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(TWODOTS, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno));}
#line 2457 "grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 257 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(TWODOTS, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno));}
#line 2463 "grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 263 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(UWCONST, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 2469 "grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 265 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SWCONST, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 2475 "grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 267 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(WSIZEOF, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno)); }
#line 2481 "grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 269 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(CAST_TOINT, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno)); }
#line 2487 "grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 273 "grammar.y" /* yacc.c:1646  */
    {
                 yyerror("fractional constants are not supported.");
                 YYABORT;
               }
#line 2496 "grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 278 "grammar.y" /* yacc.c:1646  */
    {
                 yyerror("exponential constants are not supported.");
                 YYABORT;
               }
#line 2505 "grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 283 "grammar.y" /* yacc.c:1646  */
    {
                 yyerror("real constants are not supported.");
                 YYABORT;
               }
#line 2514 "grammar.c" /* yacc.c:1646  */
    break;

  case 25:
#line 297 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(UMINUS, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2520 "grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 299 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(SELF,Nil,Nil);}
#line 2526 "grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 301 "grammar.y" /* yacc.c:1646  */
    {
                    int ntype = node_get_type((yyvsp[-2].node));
                    if (ATOM != ntype && DOT != ntype && ARRAY != ntype && SELF != ntype) {
                      yyerror_lined("incorrect DOT expression", (yyvsp[-1].lineno));
                      YYABORT;
                    }
                    (yyval.node) = new_lined_node(DOT, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)) ;
                  }
#line 2539 "grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 310 "grammar.y" /* yacc.c:1646  */
    {
                   int ntype = node_get_type((yyvsp[-2].node));
                   if (ATOM != ntype && DOT != ntype && ARRAY != ntype && SELF != ntype) {
                     yyerror_lined("incorrect DOT expression", (yyvsp[-1].lineno));
                     YYABORT;
                   }
                   (yyval.node) = new_lined_node(DOT, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)) ;
                  }
#line 2552 "grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 319 "grammar.y" /* yacc.c:1646  */
    {
                   /* array may have any expression on the left.
                      The type check will detect any problems */
                   (yyval.node) = new_lined_node(ARRAY, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno));
                  }
#line 2562 "grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 325 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.node) = new_lined_node(BIT_SELECTION, (yyvsp[-5].node),
                                        new_lined_node(COLON, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno)), (yyvsp[-4].lineno));
                  }
#line 2571 "grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 329 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2577 "grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 330 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(NOT, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2583 "grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 331 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(CAST_BOOL, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno)); }
#line 2589 "grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 332 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(CAST_WORD1, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno)); }
#line 2595 "grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 333 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(NEXT, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno)); }
#line 2601 "grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 334 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(CAST_SIGNED, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno)); }
#line 2607 "grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 335 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(CAST_UNSIGNED, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno)); }
#line 2613 "grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 336 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EXTEND, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 2619 "grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 337 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(WRESIZE, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 2625 "grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 338 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2631 "grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 342 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(WAREAD, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 2637 "grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 345 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(WAWRITE, (yyvsp[-5].node), new_node(WAWRITE, (yyvsp[-3].node), (yyvsp[-1].node)), (yyvsp[-6].lineno)); }
#line 2643 "grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 347 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(COUNT, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno)); }
#line 2649 "grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 351 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = cons((yyvsp[0].node), Nil); }
#line 2655 "grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 352 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = cons((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2661 "grammar.c" /* yacc.c:1646  */
    break;

  case 47:
#line 357 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CASE, (yyvsp[0].node), failure_make("case conditions are not exhaustive", FAILURE_CASE_NOT_EXHAUSTIVE, yylineno));}
#line 2667 "grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 358 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CASE, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2673 "grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 363 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = build_case_colon_node((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno)); }
#line 2679 "grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 368 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(CONCATENATION, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2685 "grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 373 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(TIMES, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2691 "grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 374 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(DIVIDE, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2697 "grammar.c" /* yacc.c:1646  */
    break;

  case 55:
#line 375 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(MOD, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2703 "grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 380 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(PLUS, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2709 "grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 381 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(MINUS, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2715 "grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 385 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(LSHIFT, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2721 "grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 386 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(RSHIFT, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2727 "grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 394 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2733 "grammar.c" /* yacc.c:1646  */
    break;

  case 66:
#line 398 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(UNION, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno));}
#line 2739 "grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 403 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(UNION, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2745 "grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 407 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(SETIN, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2751 "grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 412 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EQUAL, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2757 "grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 413 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(NOTEQUAL, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2763 "grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 414 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(LT, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2769 "grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 415 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(GT, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2775 "grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 416 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(LE, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2781 "grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 417 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(GE, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2787 "grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 425 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EX, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2793 "grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 426 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(AX, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2799 "grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 427 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EF, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2805 "grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 428 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(AF, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2811 "grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 429 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EG, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2817 "grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 430 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(AG, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2823 "grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 432 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(AU, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 2829 "grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 434 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EU, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 2835 "grammar.c" /* yacc.c:1646  */
    break;

  case 88:
#line 436 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(ABU, new_lined_node(AU, (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-6].lineno)), (yyvsp[-2].node), (yyvsp[-6].lineno)); }
#line 2841 "grammar.c" /* yacc.c:1646  */
    break;

  case 89:
#line 438 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EBU, new_lined_node(EU, (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-6].lineno)), (yyvsp[-2].node), (yyvsp[-6].lineno)); }
#line 2847 "grammar.c" /* yacc.c:1646  */
    break;

  case 90:
#line 439 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EBF, (yyvsp[0].node), (yyvsp[-1].node), (yyvsp[-2].lineno)); }
#line 2853 "grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 440 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(ABF, (yyvsp[0].node), (yyvsp[-1].node), (yyvsp[-2].lineno)); }
#line 2859 "grammar.c" /* yacc.c:1646  */
    break;

  case 92:
#line 441 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EBG, (yyvsp[0].node), (yyvsp[-1].node), (yyvsp[-2].lineno)); }
#line 2865 "grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 442 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(ABG, (yyvsp[0].node), (yyvsp[-1].node), (yyvsp[-2].lineno)); }
#line 2871 "grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 445 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(NOT, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2877 "grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 452 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(AND, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2883 "grammar.c" /* yacc.c:1646  */
    break;

  case 98:
#line 456 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(OR,(yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2889 "grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 457 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(XOR,(yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2895 "grammar.c" /* yacc.c:1646  */
    break;

  case 100:
#line 458 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(XNOR,(yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2901 "grammar.c" /* yacc.c:1646  */
    break;

  case 102:
#line 462 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(IFF, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2907 "grammar.c" /* yacc.c:1646  */
    break;

  case 104:
#line 467 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(IMPLIES, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 2913 "grammar.c" /* yacc.c:1646  */
    break;

  case 108:
#line 480 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(OP_NEXT, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 2919 "grammar.c" /* yacc.c:1646  */
    break;

  case 109:
#line 481 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(OP_PREC, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 2925 "grammar.c" /* yacc.c:1646  */
    break;

  case 110:
#line 482 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(OP_NOTPRECNOT, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 2931 "grammar.c" /* yacc.c:1646  */
    break;

  case 111:
#line 483 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(OP_GLOBAL, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 2937 "grammar.c" /* yacc.c:1646  */
    break;

  case 112:
#line 484 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(OP_HISTORICAL, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 2943 "grammar.c" /* yacc.c:1646  */
    break;

  case 113:
#line 485 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(OP_FUTURE, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 2949 "grammar.c" /* yacc.c:1646  */
    break;

  case 114:
#line 486 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(OP_ONCE, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 2955 "grammar.c" /* yacc.c:1646  */
    break;

  case 115:
#line 488 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(NOT, (yyvsp[0].node), Nil, (yyvsp[-1].lineno)); }
#line 2961 "grammar.c" /* yacc.c:1646  */
    break;

  case 117:
#line 497 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(UNTIL, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno));}
#line 2967 "grammar.c" /* yacc.c:1646  */
    break;

  case 118:
#line 499 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SINCE, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno));}
#line 2973 "grammar.c" /* yacc.c:1646  */
    break;

  case 119:
#line 501 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(NOT,
                           new_lined_node(UNTIL,
                             new_lined_node(NOT, (yyvsp[-2].node), Nil, node_get_lineno((yyvsp[-2].node))),
                             new_lined_node(NOT, (yyvsp[0].node), Nil, node_get_lineno((yyvsp[0].node))),
                             (yyvsp[-1].lineno)), Nil, (yyvsp[-1].lineno));
                  }
#line 2984 "grammar.c" /* yacc.c:1646  */
    break;

  case 120:
#line 508 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(NOT,
                          new_lined_node(SINCE,
                              new_lined_node(NOT, (yyvsp[-2].node), Nil, node_get_lineno((yyvsp[-2].node))),
                              new_lined_node(NOT, (yyvsp[0].node), Nil, node_get_lineno((yyvsp[0].node))),
                              (yyvsp[-1].lineno)), Nil, (yyvsp[-1].lineno));
                  }
#line 2995 "grammar.c" /* yacc.c:1646  */
    break;

  case 122:
#line 518 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(AND, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 3001 "grammar.c" /* yacc.c:1646  */
    break;

  case 124:
#line 523 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(OR,(yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 3007 "grammar.c" /* yacc.c:1646  */
    break;

  case 125:
#line 524 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(XOR,(yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 3013 "grammar.c" /* yacc.c:1646  */
    break;

  case 126:
#line 525 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(XNOR,(yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 3019 "grammar.c" /* yacc.c:1646  */
    break;

  case 128:
#line 530 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(IFTHENELSE, new_lined_node(COLON, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-3].lineno)), (yyvsp[0].node), (yyvsp[-3].lineno)); }
#line 3025 "grammar.c" /* yacc.c:1646  */
    break;

  case 130:
#line 535 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(IFF, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 3031 "grammar.c" /* yacc.c:1646  */
    break;

  case 132:
#line 540 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(IMPLIES, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno)); }
#line 3037 "grammar.c" /* yacc.c:1646  */
    break;

  case 134:
#line 551 "grammar.y" /* yacc.c:1646  */
    {if (!isCorrectExp((yyval.node), EXP_SIMPLE)) YYABORT;}
#line 3043 "grammar.c" /* yacc.c:1646  */
    break;

  case 135:
#line 554 "grammar.y" /* yacc.c:1646  */
    {if (!isCorrectExp((yyval.node), EXP_NEXT)) YYABORT;}
#line 3049 "grammar.c" /* yacc.c:1646  */
    break;

  case 136:
#line 557 "grammar.y" /* yacc.c:1646  */
    {if (!isCorrectExp((yyval.node), EXP_CTL)) YYABORT;}
#line 3055 "grammar.c" /* yacc.c:1646  */
    break;

  case 137:
#line 560 "grammar.y" /* yacc.c:1646  */
    {if (!isCorrectExp((yyval.node), EXP_LTL)) YYABORT;}
#line 3061 "grammar.c" /* yacc.c:1646  */
    break;

  case 138:
#line 565 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(MINU, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 3067 "grammar.c" /* yacc.c:1646  */
    break;

  case 139:
#line 567 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(MAXU, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-5].lineno)); }
#line 3073 "grammar.c" /* yacc.c:1646  */
    break;

  case 140:
#line 575 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(BOOLEAN, Nil, Nil);}
#line 3079 "grammar.c" /* yacc.c:1646  */
    break;

  case 141:
#line 576 "grammar.y" /* yacc.c:1646  */
    {
                yyerror("given token is not supported.");
                YYABORT;
              }
#line 3088 "grammar.c" /* yacc.c:1646  */
    break;

  case 142:
#line 580 "grammar.y" /* yacc.c:1646  */
    {
                yyerror("given token is not supported.");
                YYABORT;
              }
#line 3097 "grammar.c" /* yacc.c:1646  */
    break;

  case 143:
#line 585 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(UNSIGNED_WORD, (yyvsp[-1].node), Nil, (yyvsp[-3].lineno));}
#line 3103 "grammar.c" /* yacc.c:1646  */
    break;

  case 144:
#line 587 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(UNSIGNED_WORD, (yyvsp[-1].node), Nil, (yyvsp[-4].lineno));}
#line 3109 "grammar.c" /* yacc.c:1646  */
    break;

  case 145:
#line 589 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SIGNED_WORD, (yyvsp[-1].node), Nil, (yyvsp[-4].lineno));}
#line 3115 "grammar.c" /* yacc.c:1646  */
    break;

  case 147:
#line 592 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SCALAR, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3121 "grammar.c" /* yacc.c:1646  */
    break;

  case 148:
#line 594 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(WORDARRAY, (yyvsp[-6].node), (yyvsp[-1].node), (yyvsp[-9].lineno));}
#line 3127 "grammar.c" /* yacc.c:1646  */
    break;

  case 149:
#line 596 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(ARRAY_TYPE, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-3].lineno));}
#line 3133 "grammar.c" /* yacc.c:1646  */
    break;

  case 152:
#line 602 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(PROCESS, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3139 "grammar.c" /* yacc.c:1646  */
    break;

  case 153:
#line 605 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons(find_atom((yyvsp[0].node)), Nil); free_node((yyvsp[0].node));}
#line 3145 "grammar.c" /* yacc.c:1646  */
    break;

  case 154:
#line 606 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons(find_atom((yyvsp[0].node)), (yyvsp[-2].node)); free_node((yyvsp[0].node));}
#line 3151 "grammar.c" /* yacc.c:1646  */
    break;

  case 160:
#line 616 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(DOT, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].lineno));}
#line 3157 "grammar.c" /* yacc.c:1646  */
    break;

  case 161:
#line 619 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(MODTYPE, (yyvsp[0].node), Nil);}
#line 3163 "grammar.c" /* yacc.c:1646  */
    break;

  case 162:
#line 620 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(MODTYPE, (yyvsp[-2].node), Nil);}
#line 3169 "grammar.c" /* yacc.c:1646  */
    break;

  case 163:
#line 622 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(MODTYPE, (yyvsp[-3].node), (yyvsp[-1].node), node_get_lineno((yyvsp[-3].node)));}
#line 3175 "grammar.c" /* yacc.c:1646  */
    break;

  case 164:
#line 624 "grammar.y" /* yacc.c:1646  */
    {
                    /* $$ = new_lined_node(ARRAY, $2, $4, $1); */
                    /* array of modules is not supported any more.
                       NOTE: In future if there are some syntact conflicts
                       this case can be removed */
                    yyerror_lined("array of modules is no supported", (yyvsp[-3].lineno));
                    YYABORT;
                  }
#line 3188 "grammar.c" /* yacc.c:1646  */
    break;

  case 165:
#line 635 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node),Nil);}
#line 3194 "grammar.c" /* yacc.c:1646  */
    break;

  case 166:
#line 636 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-2].node));}
#line 3200 "grammar.c" /* yacc.c:1646  */
    break;

  case 167:
#line 648 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), Nil);}
#line 3206 "grammar.c" /* yacc.c:1646  */
    break;

  case 168:
#line 649 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-1].node));}
#line 3212 "grammar.c" /* yacc.c:1646  */
    break;

  case 169:
#line 653 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(MODULE, (yyvsp[-1].node), (yyvsp[0].node), (yyvsp[-2].lineno));}
#line 3218 "grammar.c" /* yacc.c:1646  */
    break;

  case 170:
#line 655 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(MODTYPE, (yyvsp[0].node), Nil);}
#line 3224 "grammar.c" /* yacc.c:1646  */
    break;

  case 171:
#line 656 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(MODTYPE, (yyvsp[-2].node), Nil);}
#line 3230 "grammar.c" /* yacc.c:1646  */
    break;

  case 172:
#line 658 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(MODTYPE, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 3236 "grammar.c" /* yacc.c:1646  */
    break;

  case 173:
#line 660 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons(find_atom((yyvsp[0].node)), Nil); free_node((yyvsp[0].node));}
#line 3242 "grammar.c" /* yacc.c:1646  */
    break;

  case 174:
#line 661 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons(find_atom((yyvsp[0].node)), (yyvsp[-2].node)); free_node((yyvsp[0].node));}
#line 3248 "grammar.c" /* yacc.c:1646  */
    break;

  case 175:
#line 666 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = Nil;}
#line 3254 "grammar.c" /* yacc.c:1646  */
    break;

  case 176:
#line 667 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-1].node));}
#line 3260 "grammar.c" /* yacc.c:1646  */
    break;

  case 177:
#line 668 "grammar.y" /* yacc.c:1646  */
    { SYNTAX_ERROR_HANDLING((yyval.node), (yyvsp[-1].node)); }
#line 3266 "grammar.c" /* yacc.c:1646  */
    break;

  case 199:
#line 700 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(VAR, Nil, Nil, (yyvsp[0].lineno));}
#line 3272 "grammar.c" /* yacc.c:1646  */
    break;

  case 200:
#line 701 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(VAR, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3278 "grammar.c" /* yacc.c:1646  */
    break;

  case 201:
#line 704 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(FROZENVAR, Nil, Nil, (yyvsp[0].lineno));}
#line 3284 "grammar.c" /* yacc.c:1646  */
    break;

  case 202:
#line 705 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(FROZENVAR, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3290 "grammar.c" /* yacc.c:1646  */
    break;

  case 203:
#line 708 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(IVAR, Nil, Nil, (yyvsp[0].lineno));}
#line 3296 "grammar.c" /* yacc.c:1646  */
    break;

  case 204:
#line 709 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(IVAR, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3302 "grammar.c" /* yacc.c:1646  */
    break;

  case 205:
#line 712 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), Nil);}
#line 3308 "grammar.c" /* yacc.c:1646  */
    break;

  case 206:
#line 713 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-1].node));}
#line 3314 "grammar.c" /* yacc.c:1646  */
    break;

  case 207:
#line 714 "grammar.y" /* yacc.c:1646  */
    { SYNTAX_ERROR_HANDLING((yyval.node), (yyvsp[-1].node)); }
#line 3320 "grammar.c" /* yacc.c:1646  */
    break;

  case 208:
#line 716 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), Nil);}
#line 3326 "grammar.c" /* yacc.c:1646  */
    break;

  case 209:
#line 717 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-1].node));}
#line 3332 "grammar.c" /* yacc.c:1646  */
    break;

  case 210:
#line 718 "grammar.y" /* yacc.c:1646  */
    { SYNTAX_ERROR_HANDLING((yyval.node), (yyvsp[-1].node)); }
#line 3338 "grammar.c" /* yacc.c:1646  */
    break;

  case 211:
#line 720 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), Nil);}
#line 3344 "grammar.c" /* yacc.c:1646  */
    break;

  case 212:
#line 721 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-1].node));}
#line 3350 "grammar.c" /* yacc.c:1646  */
    break;

  case 213:
#line 722 "grammar.y" /* yacc.c:1646  */
    { SYNTAX_ERROR_HANDLING((yyval.node), (yyvsp[-1].node)); }
#line 3356 "grammar.c" /* yacc.c:1646  */
    break;

  case 214:
#line 725 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COLON, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno));}
#line 3362 "grammar.c" /* yacc.c:1646  */
    break;

  case 215:
#line 727 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COLON, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno));}
#line 3368 "grammar.c" /* yacc.c:1646  */
    break;

  case 216:
#line 729 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COLON, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno));}
#line 3374 "grammar.c" /* yacc.c:1646  */
    break;

  case 217:
#line 734 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(DEFINE, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3380 "grammar.c" /* yacc.c:1646  */
    break;

  case 218:
#line 736 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = Nil;}
#line 3386 "grammar.c" /* yacc.c:1646  */
    break;

  case 219:
#line 737 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-1].node));}
#line 3392 "grammar.c" /* yacc.c:1646  */
    break;

  case 220:
#line 738 "grammar.y" /* yacc.c:1646  */
    { SYNTAX_ERROR_HANDLING((yyval.node), (yyvsp[-1].node)); }
#line 3398 "grammar.c" /* yacc.c:1646  */
    break;

  case 221:
#line 742 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(EQDEF, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno));}
#line 3404 "grammar.c" /* yacc.c:1646  */
    break;

  case 222:
#line 744 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(EQDEF, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno));
                                 /* Note that array-define is declared
                                    as normal define.
                                    Then compile_instantiate in compileFlatten.c
                                    distinguish them by detecting
                                    ARRAY_DEF on right hand side.
                                   */
                                 }
#line 3417 "grammar.c" /* yacc.c:1646  */
    break;

  case 223:
#line 756 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(DEFINE, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3423 "grammar.c" /* yacc.c:1646  */
    break;

  case 224:
#line 760 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = Nil;}
#line 3429 "grammar.c" /* yacc.c:1646  */
    break;

  case 225:
#line 761 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons(new_lined_node(EQDEF, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno)), (yyvsp[-4].node));}
#line 3435 "grammar.c" /* yacc.c:1646  */
    break;

  case 226:
#line 762 "grammar.y" /* yacc.c:1646  */
    { SYNTAX_ERROR_HANDLING((yyval.node), (yyvsp[-1].node)); }
#line 3441 "grammar.c" /* yacc.c:1646  */
    break;

  case 227:
#line 766 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) =  new_lined_node(ARRAY_DEF, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3447 "grammar.c" /* yacc.c:1646  */
    break;

  case 228:
#line 767 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) =  new_lined_node(ARRAY_DEF, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3453 "grammar.c" /* yacc.c:1646  */
    break;

  case 229:
#line 771 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), Nil);}
#line 3459 "grammar.c" /* yacc.c:1646  */
    break;

  case 230:
#line 772 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[-2].node), (yyvsp[0].node));}
#line 3465 "grammar.c" /* yacc.c:1646  */
    break;

  case 231:
#line 776 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[-2].node), (yyvsp[0].node));}
#line 3471 "grammar.c" /* yacc.c:1646  */
    break;

  case 232:
#line 777 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node),Nil);}
#line 3477 "grammar.c" /* yacc.c:1646  */
    break;

  case 233:
#line 781 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(ASSIGN, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3483 "grammar.c" /* yacc.c:1646  */
    break;

  case 234:
#line 783 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = Nil;}
#line 3489 "grammar.c" /* yacc.c:1646  */
    break;

  case 235:
#line 784 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(AND, (yyvsp[-1].node), (yyvsp[0].node));}
#line 3495 "grammar.c" /* yacc.c:1646  */
    break;

  case 236:
#line 785 "grammar.y" /* yacc.c:1646  */
    { SYNTAX_ERROR_HANDLING((yyval.node), (yyvsp[-1].node)); }
#line 3501 "grammar.c" /* yacc.c:1646  */
    break;

  case 237:
#line 788 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(EQDEF, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].lineno));}
#line 3507 "grammar.c" /* yacc.c:1646  */
    break;

  case 238:
#line 790 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EQDEF,
                                        new_lined_node(SMALLINIT, (yyvsp[-4].node), Nil, (yyvsp[-6].lineno)),
                                        (yyvsp[-1].node), (yyvsp[-2].lineno));
                  }
#line 3516 "grammar.c" /* yacc.c:1646  */
    break;

  case 239:
#line 795 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_lined_node(EQDEF,
                                        new_lined_node(NEXT, (yyvsp[-4].node), Nil, (yyvsp[-6].lineno)),
                                        (yyvsp[-1].node), (yyvsp[-2].lineno));
                  }
#line 3525 "grammar.c" /* yacc.c:1646  */
    break;

  case 240:
#line 802 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(INIT, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3531 "grammar.c" /* yacc.c:1646  */
    break;

  case 241:
#line 804 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(INVAR, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3537 "grammar.c" /* yacc.c:1646  */
    break;

  case 242:
#line 806 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(TRANS, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3543 "grammar.c" /* yacc.c:1646  */
    break;

  case 243:
#line 810 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(JUSTICE, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3549 "grammar.c" /* yacc.c:1646  */
    break;

  case 244:
#line 813 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(JUSTICE, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3555 "grammar.c" /* yacc.c:1646  */
    break;

  case 245:
#line 818 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COMPASSION, cons((yyvsp[-4].node),(yyvsp[-2].node)), Nil, (yyvsp[-6].lineno));}
#line 3561 "grammar.c" /* yacc.c:1646  */
    break;

  case 246:
#line 822 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3567 "grammar.c" /* yacc.c:1646  */
    break;

  case 247:
#line 823 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(CONTEXT, (yyvsp[-1].node), (yyvsp[-3].node));}
#line 3573 "grammar.c" /* yacc.c:1646  */
    break;

  case 248:
#line 825 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(INVARSPEC, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3579 "grammar.c" /* yacc.c:1646  */
    break;

  case 249:
#line 826 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(INVARSPEC, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].lineno));}
#line 3585 "grammar.c" /* yacc.c:1646  */
    break;

  case 250:
#line 829 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3591 "grammar.c" /* yacc.c:1646  */
    break;

  case 251:
#line 830 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(CONTEXT, (yyvsp[-1].node), (yyvsp[-3].node));}
#line 3597 "grammar.c" /* yacc.c:1646  */
    break;

  case 252:
#line 832 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SPEC, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3603 "grammar.c" /* yacc.c:1646  */
    break;

  case 253:
#line 833 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SPEC, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3609 "grammar.c" /* yacc.c:1646  */
    break;

  case 254:
#line 834 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SPEC, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].lineno));}
#line 3615 "grammar.c" /* yacc.c:1646  */
    break;

  case 255:
#line 835 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SPEC, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].lineno));}
#line 3621 "grammar.c" /* yacc.c:1646  */
    break;

  case 256:
#line 838 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3627 "grammar.c" /* yacc.c:1646  */
    break;

  case 257:
#line 839 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(CONTEXT, (yyvsp[-1].node), (yyvsp[-3].node));}
#line 3633 "grammar.c" /* yacc.c:1646  */
    break;

  case 258:
#line 842 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(LTLSPEC, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3639 "grammar.c" /* yacc.c:1646  */
    break;

  case 259:
#line 843 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(LTLSPEC, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].lineno));}
#line 3645 "grammar.c" /* yacc.c:1646  */
    break;

  case 260:
#line 846 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3651 "grammar.c" /* yacc.c:1646  */
    break;

  case 261:
#line 847 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(CONTEXT, (yyvsp[-1].node), (yyvsp[-3].node));}
#line 3657 "grammar.c" /* yacc.c:1646  */
    break;

  case 262:
#line 849 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COMPUTE, (yyvsp[0].node), Nil, (yyvsp[-1].lineno));}
#line 3663 "grammar.c" /* yacc.c:1646  */
    break;

  case 263:
#line 850 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COMPUTE, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].lineno));}
#line 3669 "grammar.c" /* yacc.c:1646  */
    break;

  case 264:
#line 855 "grammar.y" /* yacc.c:1646  */
    {
  if (nusmv_parse_psl() != 0) {
    YYABORT;
  }
  (yyval.node) = new_lined_node(PSLSPEC, psl_parsed_tree, psl_property_name, (yyvsp[0].lineno));
  psl_property_name = Nil;
}
#line 3681 "grammar.c" /* yacc.c:1646  */
    break;

  case 265:
#line 865 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(CONSTANTS, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3687 "grammar.c" /* yacc.c:1646  */
    break;

  case 266:
#line 869 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = Nil;}
#line 3693 "grammar.c" /* yacc.c:1646  */
    break;

  case 267:
#line 870 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = cons((yyvsp[0].node), Nil);}
#line 3699 "grammar.c" /* yacc.c:1646  */
    break;

  case 268:
#line 871 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = cons((yyvsp[0].node), (yyvsp[-2].node));}
#line 3705 "grammar.c" /* yacc.c:1646  */
    break;

  case 269:
#line 875 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = cons((yyvsp[0].node), Nil);}
#line 3711 "grammar.c" /* yacc.c:1646  */
    break;

  case 270:
#line 876 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = cons((yyvsp[0].node), (yyvsp[-1].node));}
#line 3717 "grammar.c" /* yacc.c:1646  */
    break;

  case 271:
#line 881 "grammar.y" /* yacc.c:1646  */
    {
                   yyerror("given token is not supported.");
                   YYABORT;
                 }
#line 3726 "grammar.c" /* yacc.c:1646  */
    break;

  case 272:
#line 886 "grammar.y" /* yacc.c:1646  */
    {
                   yyerror("given token is not supported.");
                   YYABORT;
                 }
#line 3735 "grammar.c" /* yacc.c:1646  */
    break;

  case 273:
#line 892 "grammar.y" /* yacc.c:1646  */
    {
                   yyerror("given token is not supported.");
                   YYABORT;
                 }
#line 3744 "grammar.c" /* yacc.c:1646  */
    break;

  case 274:
#line 899 "grammar.y" /* yacc.c:1646  */
    {
                   yyerror("given token is not supported.");
                   YYABORT;
                 }
#line 3753 "grammar.c" /* yacc.c:1646  */
    break;

  case 275:
#line 906 "grammar.y" /* yacc.c:1646  */
    {
                    yyerror("given token is not supported.");
                    YYABORT;
                  }
#line 3762 "grammar.c" /* yacc.c:1646  */
    break;

  case 276:
#line 913 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(ISA, (yyvsp[0].node), Nil);}
#line 3768 "grammar.c" /* yacc.c:1646  */
    break;

  case 278:
#line 917 "grammar.y" /* yacc.c:1646  */
    {}
#line 3774 "grammar.c" /* yacc.c:1646  */
    break;

  case 280:
#line 926 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(DOT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3780 "grammar.c" /* yacc.c:1646  */
    break;

  case 281:
#line 927 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(DOT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3786 "grammar.c" /* yacc.c:1646  */
    break;

  case 282:
#line 928 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(ARRAY, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 3792 "grammar.c" /* yacc.c:1646  */
    break;

  case 283:
#line 930 "grammar.y" /* yacc.c:1646  */
    { node_ptr tmp = new_lined_node(NUMBER,
                                                      PTR_FROM_INT(node_ptr, -node_get_int((yyvsp[-1].node))),
                                                      Nil,
                                                      (yyvsp[-2].lineno));
                        (yyval.node) = new_node(ARRAY, (yyvsp[-4].node), tmp);
                      }
#line 3803 "grammar.c" /* yacc.c:1646  */
    break;

  case 285:
#line 939 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(SELF,Nil,Nil);}
#line 3809 "grammar.c" /* yacc.c:1646  */
    break;

  case 286:
#line 940 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(DOT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3815 "grammar.c" /* yacc.c:1646  */
    break;

  case 287:
#line 941 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(DOT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3821 "grammar.c" /* yacc.c:1646  */
    break;

  case 288:
#line 942 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(ARRAY, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 3827 "grammar.c" /* yacc.c:1646  */
    break;

  case 289:
#line 949 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 3833 "grammar.c" /* yacc.c:1646  */
    break;

  case 290:
#line 950 "grammar.y" /* yacc.c:1646  */
    {return(1);}
#line 3839 "grammar.c" /* yacc.c:1646  */
    break;

  case 291:
#line 951 "grammar.y" /* yacc.c:1646  */
    {return(1);}
#line 3845 "grammar.c" /* yacc.c:1646  */
    break;

  case 292:
#line 955 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(INIT, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3851 "grammar.c" /* yacc.c:1646  */
    break;

  case 293:
#line 957 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(JUSTICE, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3857 "grammar.c" /* yacc.c:1646  */
    break;

  case 294:
#line 959 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(TRANS, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3863 "grammar.c" /* yacc.c:1646  */
    break;

  case 295:
#line 961 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(CONSTRAINT, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3869 "grammar.c" /* yacc.c:1646  */
    break;

  case 296:
#line 964 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(SIMPWFF, node2maincontext((yyvsp[0].node)), Nil, (yyvsp[-1].lineno));}
#line 3875 "grammar.c" /* yacc.c:1646  */
    break;

  case 297:
#line 965 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(NEXTWFF, node2maincontext((yyvsp[0].node)), Nil, (yyvsp[-1].lineno));}
#line 3881 "grammar.c" /* yacc.c:1646  */
    break;

  case 298:
#line 966 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(CTLWFF, node2maincontext((yyvsp[0].node)), Nil, (yyvsp[-1].lineno));}
#line 3887 "grammar.c" /* yacc.c:1646  */
    break;

  case 299:
#line 967 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(LTLWFF, node2maincontext((yyvsp[0].node)), Nil, (yyvsp[-1].lineno));}
#line 3893 "grammar.c" /* yacc.c:1646  */
    break;

  case 300:
#line 968 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COMPWFF, node2maincontext((yyvsp[0].node)), Nil, (yyvsp[-1].lineno));}
#line 3899 "grammar.c" /* yacc.c:1646  */
    break;

  case 301:
#line 969 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_lined_node(COMPID, (yyvsp[-1].node), Nil, (yyvsp[-2].lineno));}
#line 3905 "grammar.c" /* yacc.c:1646  */
    break;

  case 302:
#line 971 "grammar.y" /* yacc.c:1646  */
    {
                  yyerror("given token is not supported.");
                  YYABORT;
                }
#line 3914 "grammar.c" /* yacc.c:1646  */
    break;

  case 303:
#line 978 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = find_atom((yyvsp[0].node)); free_node((yyvsp[0].node)); }
#line 3920 "grammar.c" /* yacc.c:1646  */
    break;

  case 304:
#line 979 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = find_node(DOT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3926 "grammar.c" /* yacc.c:1646  */
    break;

  case 305:
#line 980 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = find_node(ARRAY, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 3932 "grammar.c" /* yacc.c:1646  */
    break;

  case 306:
#line 983 "grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3938 "grammar.c" /* yacc.c:1646  */
    break;

  case 307:
#line 984 "grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(CONTEXT, (yyvsp[-1].node), (yyvsp[-3].node));}
#line 3944 "grammar.c" /* yacc.c:1646  */
    break;

  case 308:
#line 990 "grammar.y" /* yacc.c:1646  */
    {
  if (PARSE_MODULES != parse_mode_flag) {
    yyerror("unexpected MODULE definition encountered during parsing");
    YYABORT;
  }
}
#line 3955 "grammar.c" /* yacc.c:1646  */
    break;

  case 309:
#line 997 "grammar.y" /* yacc.c:1646  */
    {
                  parsed_tree = (yyvsp[0].node);
                }
#line 3963 "grammar.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1000 "grammar.y" /* yacc.c:1646  */
    {
                  if (PARSE_COMMAND != parse_mode_flag) {
                    yyerror("unexpected command encountered during parsing");
                    YYABORT;
                  }
                }
#line 3974 "grammar.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1006 "grammar.y" /* yacc.c:1646  */
    {parsed_tree = (yyvsp[0].node);}
#line 3980 "grammar.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1007 "grammar.y" /* yacc.c:1646  */
    {
                  if (PARSE_LTL_EXPR != parse_mode_flag){
                    yyerror("unexpected expression encountered during parsing");
                    YYABORT;
                  }
                }
#line 3991 "grammar.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1013 "grammar.y" /* yacc.c:1646  */
    {parsed_tree = (yyvsp[0].node);}
#line 3997 "grammar.c" /* yacc.c:1646  */
    break;


#line 4001 "grammar.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1016 "grammar.y" /* yacc.c:1906  */

  /* BEGINS: grammar.y.3.50 */
/***************************************************************  -*-C-*-  ***/

/* Additional source code */

/* outputs the current token with the provided string and then may terminate */
void yyerror(char *s)
{
  /* In the input.l file we explicity tell flex that we want a pointer
     (see man flex -> %pointer). So we don't need to check if yytext
     is declared as pointer or as array  */
  extern char* yytext;
  extern int yylineno;
  OptsHandler_ptr opmgr = OptsHandler_get_instance();
  
  if (OptsHandler_get_bool_option_value(opmgr, OPT_PARSER_IS_LAX)) {
    parser_add_syntax_error(get_input_file(opmgr), yylineno, yytext, s);
  }
  else {
    start_parsing_err();
    fprintf(nusmv_stderr, "at token \"%s\": %s\n", yytext, s);
    if (opt_batch(opmgr)) { finish_parsing_err(); }
  }
}

/* the same as yyerror, except at first it sets the line number and does
 not output the current token
*/
void yyerror_lined(const char *s, int line)
{
  extern char* yytext;
  extern int yylineno;
  OptsHandler_ptr opmgr = OptsHandler_get_instance();

  /*set the line number */
  yylineno = line;

  if (OptsHandler_get_bool_option_value(opmgr, OPT_PARSER_IS_LAX)) {
    parser_add_syntax_error(get_input_file(opmgr), line, yytext, s);
  }
  else {
    start_parsing_err();
    fprintf(nusmv_stderr, ": %s\n", s);
    if (opt_batch(opmgr)) { finish_parsing_err(); }
  }
}

int yywrap()
{
  return(1);
}


/* Given a node (possibly a relative or absolute context)
   constructs a node that is contextualized absolutely
   (i.e. relatively to main module). This is used to construct
   context of properties that have to be instatiated in main
   module */
static node_ptr node2maincontext(node_ptr node)
{
  node_ptr ctx;

  if (node_get_type(node) == CONTEXT) {
    /* already a context */
    ctx = CompileFlatten_concat_contexts(Nil, car(node));
    return find_node(CONTEXT, ctx, cdr(node));
  }

  /* an atom, array or dot */
  return find_node(CONTEXT, Nil, node);
}

/* This functions build the COLON node for case expressions.  If
   backward compatibility is enabled, and the condition expression is
   found to be the constant "1", then a warning is printed and the
   condition is replaced with TRUE. */
static node_ptr build_case_colon_node(node_ptr l,
                                      node_ptr r,
                                      int linum)
{
  node_ptr res;

  static int user_warned = 0;

  if (opt_backward_comp(OptsHandler_get_instance()) &&
      (NUMBER == node_get_type(l)) && (1 == NODE_TO_INT(car(l)))) {

    /* Print this warning only once. */
    if (!user_warned) {
      fprintf(nusmv_stderr,
              "\nWARNING *** Option backward_compatibility (-old) is deprecate ***\n");
      fprintf(nusmv_stderr,
              "WARNING *** and will no longer be supported in future NuSMV versions. ***\n\n");
      user_warned = 1;
    }

    fprintf(nusmv_stderr, "WARNING (");

    if (get_input_file(OptsHandler_get_instance())) {
      fprintf(nusmv_stderr, "file %s", get_input_file(OptsHandler_get_instance()));
    }
    else fprintf(nusmv_stderr, "file stdin");

    fprintf(nusmv_stderr,
            ", line %d) : Deprecated use of \"1\" for case condition\n", linum);

    res = new_lined_node(COLON, new_node(TRUEEXP, Nil, Nil), r, linum);
  }
  else {
    res = new_lined_node(COLON, l, r, linum);
  }

  return res;
}

/* this functions checks that the expression is formed syntactically correct.
   Takes the expression to be checked, the expected kind of the
   expression. Returns true if the expression is formed correctly, and
   false otherwise.
   See enum EXP_KIND for more info about syntactic well-formedness.
*/
static boolean isCorrectExp(node_ptr exp, enum EXP_KIND expectedKind)
{
  switch(node_get_type(exp))
    {
      /* atomic expression (or thier operands have been checked earlier) */
    case FAILURE:
    case FALSEEXP:
    case TRUEEXP:
    case NUMBER:
    case NUMBER_UNSIGNED_WORD:
    case NUMBER_SIGNED_WORD:
    case NUMBER_FRAC:
    case NUMBER_REAL:
    case NUMBER_EXP:
    case UWCONST:
    case SWCONST:
    case TWODOTS:
    case DOT:
    case ATOM:
    case SELF:
    case ARRAY:
    case COUNT:
      return true;

      /* unary operators incompatible with LTL and CTL operator */
    case CAST_BOOL:
    case CAST_WORD1:
    case CAST_SIGNED:
    case CAST_UNSIGNED:
    case WSIZEOF:
    case CAST_TOINT:
      if (EXP_LTL == expectedKind || EXP_CTL == expectedKind) {
        return isCorrectExp(car(exp), EXP_SIMPLE);
      }
      /* unary operators compatible with LTL and CTL operator */
    case NOT:
    case UMINUS:
      return isCorrectExp(car(exp), expectedKind);

      /* binary opertors incompatible with LTL and CTL operator */
    case BIT_SELECTION:
    case CASE: case COLON:
    case CONCATENATION:
    case TIMES: case DIVIDE: case PLUS :case MINUS: case MOD:
    case LSHIFT: case RSHIFT: case LROTATE: case RROTATE:
    case WAREAD: case WAWRITE: /* AC ADDED THESE */
    case UNION: case SETIN:
    case EQUAL: case NOTEQUAL: case LT: case GT: case LE: case GE:
    case IFTHENELSE:
    case EXTEND:
    case WRESIZE:
      if (EXP_LTL == expectedKind || EXP_CTL == expectedKind) {
        return isCorrectExp(car(exp), EXP_SIMPLE)
          && isCorrectExp(cdr(exp), EXP_SIMPLE);
      }
      /* binary opertors compatible LTL and CTL operator */
    case AND: case OR: case XOR: case XNOR: case IFF: case IMPLIES:
      return isCorrectExp(car(exp), expectedKind)
        && isCorrectExp(cdr(exp), expectedKind);

      /* next expression */
    case NEXT:
      if (EXP_NEXT != expectedKind) {
        yyerror_lined("unexpected 'next' operator", node_get_lineno(exp));
        return false;
      }
      return isCorrectExp(car(exp), EXP_SIMPLE); /* NEXT cannot contain NEXT */

      /* CTL unary expressions */
    case EX: case AX: case EF: case AF: case EG: case AG:
    case ABU: case EBU:
    case EBF: case ABF: case EBG: case ABG:
      if (EXP_CTL != expectedKind) {
        yyerror_lined("unexpected CTL operator", node_get_lineno(exp));
        return false;
      }
      return isCorrectExp(car(exp), EXP_CTL); /* continue to check CTL */

      /* CTL binary expressions */
    case AU: case EU:
      if (EXP_CTL != expectedKind) {
        yyerror_lined("unexpected CTL operator", node_get_lineno(exp));
        return false;
      }
      return isCorrectExp(car(exp), EXP_CTL)
        && isCorrectExp(cdr(exp), EXP_CTL); /* continue to check CTL */


      /* LTL unary expressions */
    case OP_NEXT: case OP_PREC: case OP_NOTPRECNOT: case OP_GLOBAL:
    case OP_HISTORICAL: case OP_FUTURE: case OP_ONCE:
      if (EXP_LTL != expectedKind) {
        yyerror_lined("unexpected LTL operator", node_get_lineno(exp));
        return false;
      }
      return isCorrectExp(car(exp), EXP_LTL); /* continue to check LTL */


      /* LTL binary expressions */
    case UNTIL: case SINCE:
      if (EXP_LTL != expectedKind) {
        yyerror_lined("unexpected LTL operator", node_get_lineno(exp));
        return false;
      }
      return isCorrectExp(car(exp), EXP_LTL)
        && isCorrectExp(cdr(exp), EXP_LTL); /* continue to check LTL */

    default: nusmv_assert(false); /* unknown expression */
    }
  return false; /* should never be invoked */
}


static int nusmv_parse_psl()
{
  int res;
  res = psl_yyparse();
  return res;
}

  /* ENDS:   grammar.y.3.50 */
