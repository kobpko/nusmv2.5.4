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


/* Substitute the variable and function names.  */
#define yyparse         parser_ap_parse
#define yylex           parser_ap_lex
#define yyerror         parser_ap_error
#define yydebug         parser_ap_debug
#define yynerrs         parser_ap_nerrs

#define yylval          parser_ap_lval
#define yychar          parser_ap_char

/* Copy the first part of user declarations.  */
#line 1 "ap_grammar.y" /* yacc.c:339  */

/**CFile***********************************************************************

  FileName    [ap_grammar.y]

  PackageName [parser.ap]

  Synopsis    [Yacc for apability input file]

  SeeAlso     [ap_input.l]

  Author      [Marco Roveri]

  Copyright   [
  This file is part of the ``compass.parser.ap'' package of NuSMV version 2.
  Copyright (C) 2008 by FBK-irst.

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

#include "ParserAp.h"
#include "ParserAp_private.h"
#include "apInt.h"

#include "node/node.h"
#include "utils/error.h"
#include "utils/utils.h"

#include "parser/symbols.h"

static char rcsid[] UTIL_UNUSED = "$Id: ";

extern FILE* nusmv_stderr;


void parser_ap_error(char *s);

enum EXP_KIND {EXP_SIMPLE, EXP_NEXT, EXP_LTL, EXP_CTL};
static boolean isCorrectExp ARGS((node_ptr exp, enum EXP_KIND expectedKind));



#line 156 "ap_grammar.c" /* yacc.c:339  */

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
#ifndef YY_PARSER_AP_Y_TAB_H_INCLUDED
# define YY_PARSER_AP_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser_ap_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_ATOM = 258,
    TOK_FALSEEXP = 259,
    TOK_TRUEEXP = 260,
    TOK_NUMBER = 261,
    TOK_NUMBER_FRAC = 262,
    TOK_NUMBER_REAL = 263,
    TOK_NUMBER_EXP = 264,
    TOK_NUMBER_WORD = 265,
    TOK_CONS = 266,
    TOK_SEMI = 267,
    TOK_LP = 268,
    TOK_RP = 269,
    TOK_RB = 270,
    TOK_LCB = 271,
    TOK_RCB = 272,
    TOK_TWODOTS = 273,
    TOK_SELF = 274,
    TOK_CASE = 275,
    TOK_ESAC = 276,
    TOK_COLON = 277,
    TOK_COMMA = 278,
    TOK_IMPLIES = 279,
    TOK_IFF = 280,
    TOK_OR = 281,
    TOK_XOR = 282,
    TOK_XNOR = 283,
    TOK_AND = 284,
    TOK_NOT = 285,
    TOK_EX = 286,
    TOK_AX = 287,
    TOK_EF = 288,
    TOK_AF = 289,
    TOK_EG = 290,
    TOK_AG = 291,
    TOK_EE = 292,
    TOK_AA = 293,
    TOK_SINCE = 294,
    TOK_UNTIL = 295,
    TOK_TRIGGERED = 296,
    TOK_RELEASES = 297,
    TOK_EBF = 298,
    TOK_EBG = 299,
    TOK_ABF = 300,
    TOK_ABG = 301,
    TOK_BUNTIL = 302,
    TOK_MMIN = 303,
    TOK_MMAX = 304,
    TOK_OP_NEXT = 305,
    TOK_OP_GLOBAL = 306,
    TOK_OP_FUTURE = 307,
    TOK_OP_PREC = 308,
    TOK_OP_NOTPRECNOT = 309,
    TOK_OP_HISTORICAL = 310,
    TOK_OP_ONCE = 311,
    TOK_EQUAL = 312,
    TOK_NOTEQUAL = 313,
    TOK_LT = 314,
    TOK_GT = 315,
    TOK_LE = 316,
    TOK_GE = 317,
    TOK_UNION = 318,
    TOK_SETIN = 319,
    TOK_LSHIFT = 320,
    TOK_RSHIFT = 321,
    TOK_LROTATE = 322,
    TOK_RROTATE = 323,
    TOK_MOD = 324,
    TOK_PLUS = 325,
    TOK_MINUS = 326,
    TOK_TIMES = 327,
    TOK_DIVIDE = 328,
    TOK_NEXT = 329,
    TOK_SMALLINIT = 330,
    TOK_CONCATENATION = 331,
    TOK_LB = 332,
    TOK_DOT = 333,
    TOK_BIT = 334,
    TOK_SIGNED = 335,
    TOK_UNSIGNED = 336,
    TOK_EXTEND = 337,
    TOK_BOOL = 338,
    TOK_WORD1 = 339
  };
#endif
/* Tokens.  */
#define TOK_ATOM 258
#define TOK_FALSEEXP 259
#define TOK_TRUEEXP 260
#define TOK_NUMBER 261
#define TOK_NUMBER_FRAC 262
#define TOK_NUMBER_REAL 263
#define TOK_NUMBER_EXP 264
#define TOK_NUMBER_WORD 265
#define TOK_CONS 266
#define TOK_SEMI 267
#define TOK_LP 268
#define TOK_RP 269
#define TOK_RB 270
#define TOK_LCB 271
#define TOK_RCB 272
#define TOK_TWODOTS 273
#define TOK_SELF 274
#define TOK_CASE 275
#define TOK_ESAC 276
#define TOK_COLON 277
#define TOK_COMMA 278
#define TOK_IMPLIES 279
#define TOK_IFF 280
#define TOK_OR 281
#define TOK_XOR 282
#define TOK_XNOR 283
#define TOK_AND 284
#define TOK_NOT 285
#define TOK_EX 286
#define TOK_AX 287
#define TOK_EF 288
#define TOK_AF 289
#define TOK_EG 290
#define TOK_AG 291
#define TOK_EE 292
#define TOK_AA 293
#define TOK_SINCE 294
#define TOK_UNTIL 295
#define TOK_TRIGGERED 296
#define TOK_RELEASES 297
#define TOK_EBF 298
#define TOK_EBG 299
#define TOK_ABF 300
#define TOK_ABG 301
#define TOK_BUNTIL 302
#define TOK_MMIN 303
#define TOK_MMAX 304
#define TOK_OP_NEXT 305
#define TOK_OP_GLOBAL 306
#define TOK_OP_FUTURE 307
#define TOK_OP_PREC 308
#define TOK_OP_NOTPRECNOT 309
#define TOK_OP_HISTORICAL 310
#define TOK_OP_ONCE 311
#define TOK_EQUAL 312
#define TOK_NOTEQUAL 313
#define TOK_LT 314
#define TOK_GT 315
#define TOK_LE 316
#define TOK_GE 317
#define TOK_UNION 318
#define TOK_SETIN 319
#define TOK_LSHIFT 320
#define TOK_RSHIFT 321
#define TOK_LROTATE 322
#define TOK_RROTATE 323
#define TOK_MOD 324
#define TOK_PLUS 325
#define TOK_MINUS 326
#define TOK_TIMES 327
#define TOK_DIVIDE 328
#define TOK_NEXT 329
#define TOK_SMALLINIT 330
#define TOK_CONCATENATION 331
#define TOK_LB 332
#define TOK_DOT 333
#define TOK_BIT 334
#define TOK_SIGNED 335
#define TOK_UNSIGNED 336
#define TOK_EXTEND 337
#define TOK_BOOL 338
#define TOK_WORD1 339

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 83 "ap_grammar.y" /* yacc.c:355  */

  node_ptr node;

#line 368 "ap_grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_ap_lval;

int parser_ap_parse (void);

#endif /* !YY_PARSER_AP_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 385 "ap_grammar.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   549

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   143,   144,   150,   157,   157,   159,   160,
     163,   164,   165,   169,   171,   173,   175,   178,   182,   183,
     184,   185,   186,   190,   194,   207,   208,   209,   210,   211,
     222,   233,   244,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   260,   262,   266,   271,   272,   276,   277,   278,
     279,   283,   284,   285,   288,   289,   290,   296,   297,   298,
     301,   302,   306,   307,   310,   311,   315,   316,   317,   318,
     319,   320,   321,   324,   325,   329,   330,   331,   332,   333,
     334,   335,   337,   339,   341,   343,   344,   345,   346,   349,
     355,   356,   359,   360,   361,   362,   365,   366,   370,   371,
     374,   378,   379,   384,   385,   386,   387,   388,   389,   390,
     392,   397,   398,   400,   402,   408,   417,   418,   422,   423,
     424,   425,   429,   430,   434,   435,   438,   440
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ATOM", "TOK_FALSEEXP",
  "TOK_TRUEEXP", "TOK_NUMBER", "TOK_NUMBER_FRAC", "TOK_NUMBER_REAL",
  "TOK_NUMBER_EXP", "TOK_NUMBER_WORD", "TOK_CONS", "TOK_SEMI", "TOK_LP",
  "TOK_RP", "TOK_RB", "TOK_LCB", "TOK_RCB", "TOK_TWODOTS", "TOK_SELF",
  "TOK_CASE", "TOK_ESAC", "TOK_COLON", "TOK_COMMA", "TOK_IMPLIES",
  "TOK_IFF", "TOK_OR", "TOK_XOR", "TOK_XNOR", "TOK_AND", "TOK_NOT",
  "TOK_EX", "TOK_AX", "TOK_EF", "TOK_AF", "TOK_EG", "TOK_AG", "TOK_EE",
  "TOK_AA", "TOK_SINCE", "TOK_UNTIL", "TOK_TRIGGERED", "TOK_RELEASES",
  "TOK_EBF", "TOK_EBG", "TOK_ABF", "TOK_ABG", "TOK_BUNTIL", "TOK_MMIN",
  "TOK_MMAX", "TOK_OP_NEXT", "TOK_OP_GLOBAL", "TOK_OP_FUTURE",
  "TOK_OP_PREC", "TOK_OP_NOTPRECNOT", "TOK_OP_HISTORICAL", "TOK_OP_ONCE",
  "TOK_EQUAL", "TOK_NOTEQUAL", "TOK_LT", "TOK_GT", "TOK_LE", "TOK_GE",
  "TOK_UNION", "TOK_SETIN", "TOK_LSHIFT", "TOK_RSHIFT", "TOK_LROTATE",
  "TOK_RROTATE", "TOK_MOD", "TOK_PLUS", "TOK_MINUS", "TOK_TIMES",
  "TOK_DIVIDE", "TOK_NEXT", "TOK_SMALLINIT", "TOK_CONCATENATION", "TOK_LB",
  "TOK_DOT", "TOK_BIT", "TOK_SIGNED", "TOK_UNSIGNED", "TOK_EXTEND",
  "TOK_BOOL", "TOK_WORD1", "$accept", "begin", "ap_list", "ap_list_item",
  "optsemi", "number", "integer", "number_word", "number_frac",
  "number_real", "number_exp", "subrange", "constant", "primary_expr",
  "case_element_list_expr", "case_element_expr", "concatination_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "set_expr",
  "set_list_expr", "union_expr", "in_expr", "relational_expr", "ctl_expr",
  "pure_ctl_expr", "ctl_and_expr", "ctl_or_expr", "ctl_iff_expr",
  "ctl_implies_expr", "ctl_basic_expr", "ltl_unary_expr",
  "pure_ltl_unary_expr", "ltl_binary_expr", "and_expr", "or_expr",
  "iff_expr", "implies_expr", "basic_expr", "simple_expression", YY_NULLPTR
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
     335,   336,   337,   338,   339
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    35,    87,  -136,    26,   215,  -136,  -136,  -136,  -136,
    -136,    17,  -136,  -136,  -136,  -136,   215,   215,  -136,   215,
     271,   327,   327,   327,   327,   327,   327,    21,    24,    18,
      18,    18,    18,   215,   215,   215,   215,   215,   215,   215,
      96,   428,    90,    91,    98,    99,   100,   101,  -136,   102,
    -136,  -136,  -136,  -136,  -136,  -136,   -27,    40,   -17,    -2,
     -12,  -136,    54,    57,   -20,  -136,  -136,  -136,  -136,    19,
      89,    36,    68,  -136,  -136,   115,   117,    13,  -136,   108,
     215,   110,  -136,   127,   465,   -27,  -136,  -136,   383,  -136,
    -136,  -136,  -136,  -136,  -136,   327,   327,  -136,   128,   129,
     327,   327,   327,   327,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   118,   119,   465,   -27,   215,   215,   215,   215,   215,
     215,    18,   215,    25,   465,   465,   465,   465,   465,   465,
     465,   465,   156,   156,   156,   156,   156,   156,   156,   156,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
    -136,  -136,  -136,  -136,   215,  -136,  -136,   215,  -136,  -136,
     109,    39,    70,  -136,   -15,   -14,  -136,  -136,  -136,  -136,
    -136,  -136,   125,   126,   131,   120,   132,   135,  -136,    12,
    -136,  -136,   -27,    40,    40,    40,   -17,   -17,    -2,    -2,
    -136,    54,    57,    57,    57,    57,    57,    57,  -136,  -136,
    -136,  -136,    19,    89,    89,    89,  -136,    36,  -136,   130,
     327,   327,   327,   327,   327,   327,   327,    18,   327,    18,
    -136,  -136,  -136,   215,  -136,  -136,  -136,   215,  -136,  -136,
     109,   109,   109,  -136,    39,   136,   327,   137,   327,   139,
     140,  -136,   141,  -136,   142,  -136,  -136,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     0,     1,     4,    27,    18,
      19,     8,    14,    15,    16,    13,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
      21,    22,    24,    23,    58,    25,    45,    47,    51,    54,
      57,    62,    64,    66,    73,   101,    74,   111,   102,   116,
     118,   122,   124,   126,   127,     6,     0,     0,    60,     0,
      42,     0,     8,     0,     0,    34,    89,   110,     0,    75,
      76,    77,    78,    79,    80,     0,     0,    10,     0,     0,
       0,     0,     0,     0,   103,   106,   108,   104,   105,   107,
     109,     9,     8,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     5,    33,    59,     0,    41,    43,     0,     9,    90,
      92,    96,    98,   100,     0,     0,    11,    12,    85,    87,
      86,    88,     0,     0,     0,     0,     0,     0,    17,     0,
      29,    30,    46,    50,    48,    49,    52,    53,    55,    56,
      63,    65,    67,    68,    69,    70,    71,    72,   113,   112,
     115,   114,   117,   119,   120,   121,   125,   123,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    38,    39,     0,    35,    36,    31,     0,    44,    91,
      93,    94,    95,    99,    97,     0,     0,     0,     0,     0,
       0,    82,     0,    81,     0,    40,    32,    84,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   150,  -136,  -136,  -136,    20,  -136,  -136,  -136,
    -136,   -19,  -136,     2,    78,  -136,   -54,   -32,   -31,  -136,
      38,  -136,    34,   -90,  -136,   -21,     3,  -135,   -47,  -136,
     -43,   -88,   -18,   153,    30,   -62,    28,  -136,    31,   -10,
    -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,   151,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    79,    80,    57,    58,    59,    60,
      61,    77,    62,    63,    64,    65,    66,   160,   161,   162,
     163,   164,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    90,    91,    92,    93,    94,    76,    78,   165,    81,
     100,   101,   102,   103,   179,   104,   105,   106,   107,   108,
     109,   110,    85,    86,    97,   216,   218,   226,   180,     1,
     153,   181,   217,   219,   227,   -10,   154,   134,   135,   136,
     137,   138,   139,   114,   192,   193,   194,   195,   196,   197,
     122,   123,   125,   130,   131,   126,   127,     5,   140,   141,
     142,   143,   145,   146,   147,   211,   212,   213,   128,   129,
      81,   183,   184,   185,   159,   159,   230,   231,   232,   168,
     169,   170,   171,   203,   204,   205,   114,     6,    98,    99,
      85,    86,   148,   149,   214,   215,   186,   187,    95,   188,
     189,    96,   111,   115,   116,   172,   173,   174,   175,   176,
     177,   117,   118,   119,   120,    85,   124,   132,   144,   240,
     121,   133,   198,   199,   200,   201,   182,   150,   235,   155,
     237,   152,   157,   158,   166,   167,   -11,   -12,   210,   220,
     221,   178,   228,   223,   208,   222,   224,   209,   242,   225,
     244,   241,   243,   245,     7,   246,   247,   248,   156,     8,
       9,    10,    11,    12,    13,    14,    15,   191,   234,    16,
     190,   233,    17,    87,   202,    18,    19,   207,     0,   206,
       0,     0,     0,     0,     0,     0,   113,     0,     0,   229,
     159,   159,   159,   159,   159,   159,     0,   159,   236,     0,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,   159,     0,   159,     8,     9,
      10,    11,    12,    13,    14,    15,    40,    41,    16,     0,
      42,    17,     0,     0,    18,    19,    43,    44,    45,    46,
      47,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,    29,    30,
      31,    32,     0,     0,     0,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     8,     9,    10,    82,    12,    13,
      14,    15,     0,     0,    16,    40,    41,     0,     0,    42,
      18,    19,     0,     0,     0,    43,    44,    45,    46,    47,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,     0,    29,    30,    31,    32,     0,     0,
       0,    33,    34,    35,    36,    37,    38,    39,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
      16,    83,    84,    17,     0,    42,    18,    19,     0,     0,
       0,    43,    44,    45,    46,    47,     0,    88,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
      29,    30,    31,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    82,
      12,    13,    14,    15,     0,     0,    16,    40,    41,     0,
       0,    42,    18,    19,     0,     0,     0,    43,    44,    45,
      46,    47,     0,    88,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,     0,    29,    30,    31,    32,
       0,     8,     9,    10,   112,    12,    13,    14,    15,     0,
       0,    16,     0,     0,     0,     0,     0,    18,    19,     0,
       0,     0,     0,    83,    84,     0,     0,    42,   113,     0,
       0,     0,     0,    43,    44,    45,    46,    47,     8,     9,
      10,    82,    12,    13,    14,    15,     0,     0,    16,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,    83,    84,
       0,     0,    42,     0,     0,     0,     0,     0,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,     0,     0,    42,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47
};

static const yytype_int16 yycheck[] =
{
      21,    22,    23,    24,    25,    26,    16,    17,    96,    19,
      29,    30,    31,    32,   122,    33,    34,    35,    36,    37,
      38,    39,    20,    20,     6,    40,    40,    15,     3,     3,
      17,     6,    47,    47,    22,    18,    23,    57,    58,    59,
      60,    61,    62,    41,   134,   135,   136,   137,   138,   139,
      77,    78,    69,    65,    66,    72,    73,    22,    39,    40,
      41,    42,    26,    27,    28,    26,    27,    28,    70,    71,
      80,   125,   126,   127,    95,    96,   211,   212,   213,   100,
     101,   102,   103,   145,   146,   147,    84,     0,    70,    71,
      88,    88,    24,    25,    24,    25,   128,   129,    77,   130,
     131,    77,     6,    13,    13,   115,   116,   117,   118,   119,
     120,    13,    13,    13,    13,   113,    76,    63,    29,   227,
      18,    64,   140,   141,   142,   143,   124,    12,   216,    21,
     218,    14,    22,     6,     6,     6,    18,    18,    29,    14,
      14,   121,    12,    23,   154,    14,    14,   157,   236,    14,
     238,    15,    15,    14,     4,    15,    15,    15,    80,     3,
       4,     5,     6,     7,     8,     9,    10,   133,   215,    13,
     132,   214,    16,    20,   144,    19,    20,   149,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,   210,
     211,   212,   213,   214,   215,   216,    -1,   218,   217,    -1,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   223,    -1,   236,    -1,   238,     3,     4,
       5,     6,     7,     8,     9,    10,    70,    71,    13,    -1,
      74,    16,    -1,    -1,    19,    20,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    70,    71,    -1,    -1,    74,
      19,    20,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    70,    71,    16,    -1,    74,    19,    20,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    70,    71,    -1,
      -1,    74,    19,    20,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    74,    30,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    70,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    86,    87,    88,    22,     0,    87,     3,     4,
       5,     6,     7,     8,     9,    10,    13,    16,    19,    20,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    43,
      44,    45,    46,    50,    51,    52,    53,    54,    55,    56,
      70,    71,    74,    80,    81,    82,    83,    84,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   101,   102,   103,
     104,   105,   107,   108,   109,   110,   111,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   124,   106,   124,    99,
     100,   124,     6,    70,    71,    98,   111,   118,    30,   110,
     110,   110,   110,   110,   110,    77,    77,     6,    70,    71,
      96,    96,    96,    96,   117,   117,   117,   117,   117,   117,
     117,     6,     6,    30,    98,    13,    13,    13,    13,    13,
      13,    18,    77,    78,    76,    69,    72,    73,    70,    71,
      65,    66,    63,    64,    57,    58,    59,    60,    61,    62,
      39,    40,    41,    42,    29,    26,    27,    28,    24,    25,
      12,    89,    14,    17,    23,    21,    99,    22,     6,   110,
     112,   113,   114,   115,   116,   116,     6,     6,   110,   110,
     110,   110,   124,   124,   124,   124,   124,   124,    91,   125,
       3,     6,    98,   101,   101,   101,   102,   102,   103,   103,
     105,   107,   108,   108,   108,   108,   108,   108,   117,   117,
     117,   117,   119,   120,   120,   120,   123,   121,   124,   124,
      29,    26,    27,    28,    24,    25,    40,    47,    40,    47,
      14,    14,    14,    23,    14,    14,    15,    22,    12,   110,
     112,   112,   112,   115,   113,   116,    96,   116,    96,   124,
     125,    15,   116,    15,   116,    14,    15,    15,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    88,    89,    89,    90,    90,
      91,    91,    91,    92,    93,    94,    95,    96,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   101,   101,   102,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   114,   114,   115,   115,
     116,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   120,   120,   121,   121,
     121,   121,   122,   122,   123,   123,   124,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     4,     0,     1,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     3,
       3,     4,     6,     3,     2,     4,     4,     4,     4,     4,
       6,     3,     1,     2,     4,     1,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     2,     2,     2,     2,
       2,     6,     6,     7,     7,     3,     3,     3,     3,     2,
       1,     3,     1,     3,     3,     3,     1,     3,     1,     3,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     3,     1,     3,     1,     3,     1,     1
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
        case 2:
#line 139 "ap_grammar.y" /* yacc.c:1646  */
    { }
#line 1714 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 143 "ap_grammar.y" /* yacc.c:1646  */
    {}
#line 1720 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 145 "ap_grammar.y" /* yacc.c:1646  */
    {
               parser_ap_add(parser_ap_get_global_parser(), (yyvsp[-1].node));
             }
#line 1728 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 151 "ap_grammar.y" /* yacc.c:1646  */
    {
  (yyval.node) = parser_ap_mk_ap(parser_ap_get_global_parser(), (yyvsp[-3].node), (yyvsp[-1].node));
}
#line 1736 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 7:
#line 157 "ap_grammar.y" /* yacc.c:1646  */
    {}
#line 1742 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1748 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 164 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1754 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "ap_grammar.y" /* yacc.c:1646  */
    {node_int_setcar((yyvsp[0].node), -(node_get_int((yyvsp[0].node)))); (yyval.node) = (yyvsp[0].node);}
#line 1760 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(TWODOTS, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1766 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 187 "ap_grammar.y" /* yacc.c:1646  */
    {
                 (yyval.node) = (yyvsp[0].node);
               }
#line 1774 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 191 "ap_grammar.y" /* yacc.c:1646  */
    {
                 (yyval.node) = (yyvsp[0].node);
               }
#line 1782 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 195 "ap_grammar.y" /* yacc.c:1646  */
    {
                 (yyval.node) = (yyvsp[0].node);
               }
#line 1790 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 208 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(UMINUS, (yyvsp[0].node), Nil); }
#line 1796 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(SELF,Nil,Nil);}
#line 1802 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 212 "ap_grammar.y" /* yacc.c:1646  */
    {
                      if (ATOM != node_get_type((yyvsp[-2].node)) &&
                          DOT != node_get_type((yyvsp[-2].node)) &&
                          ARRAY != node_get_type((yyvsp[-2].node)) &&
                          SELF != node_get_type((yyvsp[-2].node))) {
                        yyerror("incorrect DOT expression");
                        YYABORT;
                      }
                      (yyval.node) = new_node(DOT, (yyvsp[-2].node), (yyvsp[0].node)) ;
                    }
#line 1817 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "ap_grammar.y" /* yacc.c:1646  */
    {
                      if (ATOM != node_get_type((yyvsp[-2].node)) &&
                          DOT != node_get_type((yyvsp[-2].node)) &&
                          ARRAY != node_get_type((yyvsp[-2].node)) &&
                          SELF != node_get_type((yyvsp[-2].node))) {
                        yyerror("incorrect DOT expression");
                        YYABORT;
                      }
                      (yyval.node) = new_node(DOT, (yyvsp[-2].node), (yyvsp[0].node)) ;
                    }
#line 1832 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 234 "ap_grammar.y" /* yacc.c:1646  */
    {
                       if (ATOM != node_get_type((yyvsp[-3].node)) &&
                           DOT != node_get_type((yyvsp[-3].node)) &&
                           ARRAY != node_get_type((yyvsp[-3].node)) &&
                           SELF != node_get_type((yyvsp[-3].node))) {
                        yyerror("incorrect ARRAY expression");
                        YYABORT;
                       }
                       (yyval.node) = new_node(ARRAY, (yyvsp[-3].node), (yyvsp[-1].node));
                     }
#line 1847 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 245 "ap_grammar.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_node(BIT_SELECTION, (yyvsp[-5].node), new_node(COLON, (yyvsp[-3].node), (yyvsp[-1].node)));
                       }
#line 1855 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 248 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1861 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 249 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(NOT, (yyvsp[0].node), Nil); }
#line 1867 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CAST_BOOL, (yyvsp[-1].node), Nil); }
#line 1873 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 251 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CAST_WORD1, (yyvsp[-1].node), Nil); }
#line 1879 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 252 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(NEXT, (yyvsp[-1].node), Nil); }
#line 1885 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 253 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CAST_SIGNED, (yyvsp[-1].node), Nil); }
#line 1891 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 254 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CAST_UNSIGNED, (yyvsp[-1].node), Nil); }
#line 1897 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EXTEND, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1903 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 256 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1909 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CASE, (yyvsp[0].node), failure_make("case conditions are not exhaustive", FAILURE_CASE_NOT_EXHAUSTIVE, parser_ap_lineno));}
#line 1915 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 262 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CASE, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1921 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(COLON, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1927 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 272 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(CONCATENATION, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1933 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 277 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(TIMES, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1939 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 278 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(DIVIDE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1945 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 279 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1951 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 284 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(PLUS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1957 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 285 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(MINUS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1963 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 55:
#line 289 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(LSHIFT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1969 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 290 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(RSHIFT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1975 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 298 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1981 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 302 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(UNION, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1987 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 307 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(UNION, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1993 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 311 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(SETIN, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1999 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 316 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2005 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 317 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(NOTEQUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2011 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 69:
#line 318 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2017 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 319 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2023 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 320 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(LE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2029 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 321 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(GE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2035 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 329 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EX, (yyvsp[0].node), Nil); }
#line 2041 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 330 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(AX, (yyvsp[0].node), Nil); }
#line 2047 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 331 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EF, (yyvsp[0].node), Nil); }
#line 2053 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 332 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(AF, (yyvsp[0].node), Nil); }
#line 2059 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 333 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EG, (yyvsp[0].node), Nil); }
#line 2065 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 334 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(AG, (yyvsp[0].node), Nil); }
#line 2071 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 336 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(AU, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2077 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 338 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EU, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2083 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 340 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(ABU, new_node(AU, (yyvsp[-4].node), (yyvsp[-1].node)), (yyvsp[-2].node)); }
#line 2089 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 342 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EBU, new_node(EU, (yyvsp[-4].node), (yyvsp[-1].node)), (yyvsp[-2].node)); }
#line 2095 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 343 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EBF, (yyvsp[0].node), (yyvsp[-1].node)); }
#line 2101 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 344 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(ABF, (yyvsp[0].node), (yyvsp[-1].node)); }
#line 2107 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 345 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(EBG, (yyvsp[0].node), (yyvsp[-1].node)); }
#line 2113 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 88:
#line 346 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(ABG, (yyvsp[0].node), (yyvsp[-1].node)); }
#line 2119 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 89:
#line 349 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(NOT, (yyvsp[0].node), Nil); }
#line 2125 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 356 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2131 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 360 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(OR,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2137 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 361 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(XOR,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2143 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 362 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(XNOR,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2149 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 366 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(IFF, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2155 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 371 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(IMPLIES, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2161 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 103:
#line 384 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(OP_NEXT, (yyvsp[0].node), Nil);}
#line 2167 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 104:
#line 385 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(OP_PREC, (yyvsp[0].node), Nil);}
#line 2173 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 105:
#line 386 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(OP_NOTPRECNOT, (yyvsp[0].node), Nil);}
#line 2179 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 106:
#line 387 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(OP_GLOBAL, (yyvsp[0].node), Nil);}
#line 2185 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 107:
#line 388 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(OP_HISTORICAL, (yyvsp[0].node), Nil);}
#line 2191 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 108:
#line 389 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(OP_FUTURE, (yyvsp[0].node), Nil);}
#line 2197 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 109:
#line 390 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(OP_ONCE, (yyvsp[0].node), Nil);}
#line 2203 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 110:
#line 392 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(NOT, (yyvsp[0].node), Nil); }
#line 2209 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 112:
#line 399 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(UNTIL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2215 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 113:
#line 401 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(SINCE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2221 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 114:
#line 403 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(NOT,
                           new_node(UNTIL,
                             new_node(NOT, (yyvsp[-2].node), Nil),
                             new_node(NOT, (yyvsp[0].node), Nil)), Nil);
                  }
#line 2231 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 115:
#line 409 "ap_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = new_node(NOT,
                          new_node(SINCE,
                              new_node(NOT, (yyvsp[-2].node), Nil),
                              new_node(NOT, (yyvsp[0].node), Nil)), Nil);
                  }
#line 2241 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 117:
#line 418 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2247 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 119:
#line 423 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(OR,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2253 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 120:
#line 424 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(XOR,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2259 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 121:
#line 425 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(XNOR,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2265 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 123:
#line 430 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(IFF, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2271 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 125:
#line 435 "ap_grammar.y" /* yacc.c:1646  */
    { (yyval.node) = new_node(IMPLIES, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2277 "ap_grammar.c" /* yacc.c:1646  */
    break;

  case 127:
#line 440 "ap_grammar.y" /* yacc.c:1646  */
    {if (!isCorrectExp((yyval.node), EXP_SIMPLE)) YYABORT;}
#line 2283 "ap_grammar.c" /* yacc.c:1646  */
    break;


#line 2287 "ap_grammar.c" /* yacc.c:1646  */
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
#line 454 "ap_grammar.y" /* yacc.c:1906  */



/* Additional source code */
void parser_ap_error(char *s)
{
    extern char parser_ap_text[];

    fprintf(nusmv_stderr,"\n");
    if (get_output_order_file(OptsHandler_get_instance())) {
      fprintf(nusmv_stderr, "file %s: ",
              get_output_order_file(OptsHandler_get_instance()));
    }
    else {
      fprintf(nusmv_stderr, "file stdin: ");
    }

    if (parser_ap_lineno) {
      fprintf(nusmv_stderr, "line %d: ", parser_ap_lineno);
    }

    fprintf(nusmv_stderr, "at token \"%s\": %s\n", parser_ap_text, s);
    if (opt_batch(OptsHandler_get_instance())) {
      /* exits the execution */
      fprintf(nusmv_stderr, "\n");
      print_io_atom_stack(nusmv_stderr);
      nusmv_exit(1);
    }
}

int parser_ap_wrap()  { return 1; }

extern void yyerror_lined(const char *s, int line);

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
    case TWODOTS:
    case DOT:
    case ATOM:
    case SELF:
    case ARRAY:
    case BIT_SELECTION:
      return true;

      /* unary operators incompatible with LTL and CTL operator */
    case CAST_BOOL:
    case CAST_WORD1:
    case CAST_SIGNED:
    case CAST_UNSIGNED:
    case EXTEND:
      if (EXP_LTL == expectedKind || EXP_CTL == expectedKind) {
        return isCorrectExp(car(exp), EXP_SIMPLE);
      }
      /* unary operators compatible with LTL and CTL operator */
    case NOT:
    case UMINUS:
      return isCorrectExp(car(exp), expectedKind);

      /* binary opertors incompatible with LTL and CTL operator */
    case CASE: case COLON:
    case CONCATENATION:
    case TIMES: case DIVIDE: case PLUS :case MINUS: case MOD:
    case LSHIFT: case RSHIFT: case LROTATE: case RROTATE:
    case WAREAD: case WAWRITE: /* AC ADDED THESE */
    case UNION: case SETIN:
    case EQUAL: case NOTEQUAL: case LT: case GT: case LE: case GE:
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
