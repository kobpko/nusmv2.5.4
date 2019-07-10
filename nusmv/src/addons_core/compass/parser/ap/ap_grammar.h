/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_PARSER_AP_AP_GRAMMAR_H_INCLUDED
# define YY_PARSER_AP_AP_GRAMMAR_H_INCLUDED
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
#line 83 "ap_grammar.y" /* yacc.c:1909  */

  node_ptr node;

#line 226 "ap_grammar.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_ap_lval;

int parser_ap_parse (void);

#endif /* !YY_PARSER_AP_AP_GRAMMAR_H_INCLUDED  */
