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
#line 1 "parser.y" /* yacc.c:339  */

#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "Biblioteki/library.h"
#include "Biblioteki/MyStack.h"

#define STORE(X) code.push_back(concatStringInt("STORE ", X));
#define LOAD(X) code.push_back(concatStringInt("LOAD ", X));
#define ADD(X) code.push_back(concatStringInt("ADD ", X));
#define SUB(X) code.push_back(concatStringInt("SUB ", X));
#define PUT(X) code.push_back(concatStringInt("PUT ", X));
#define GET(X) code.push_back(concatStringInt("GET ", X));
#define ZERO(X) code.push_back(concatStringInt("ZERO ", X));
#define COPY(X) code.push_back(concatStringInt("COPY ", X));
#define JZERO(X, Y) code.push_back(concatStringInt("JZERO ", X)+string(" ")+Y);
#define JUMP(X) code.push_back("JUMP " + X);
#define JODD(X, Y) code.push_back(concatStringInt("JODD ", X)+string(" ")+Y);
#define SHL(X) code.push_back(concatStringInt("SHL ", X));
#define SHR(X) code.push_back(concatStringInt("SHR ", X));
#define INC(X) code.push_back(concatStringInt("INC ", X));
#define DEC(X) code.push_back(concatStringInt("DEC ", X));

#define PUSH_ETYK(X) etykiety.push(concatStringInt("E", X));
#define POP_AND_WRITE_ETYK code.push_back(etykiety.pop());

#define EQ_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=3;
#define EQ_2 JZERO(1, etykiety.pop())\
	create_number(code, 0, 1);\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define EQ_3 JZERO(1, etykiety.pop())\
	create_number(code, 0, 1);\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK\
	create_number(code, 1, 1);\
	POP_AND_WRITE_ETYK

#define NEQ_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=2;
#define NEQ_2 JZERO(1, etykiety.pop())\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define NEQ_3 POP_AND_WRITE_ETYK

#define MULT_MEM_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1) PUSH_ETYK(ety) ety+=2;\
	JZERO(1, etykiety.pop())
#define MULT_MEM_2 JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define MULT_MEM_3 POP_AND_WRITE_ETYK\
	ZERO(1)\
	ZERO(0)\
	STORE(3)

#define XOET PUSH_ETYK(ety+1) PUSH_ETYK(ety)\
	PUSH_ETYK(ety+1) PUSH_ETYK(ety) ety+=2;\
	JZERO(1,etykiety.pop())\
	create_number(code,0,1);\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK\
	create_number(code,1,1);\
	POP_AND_WRITE_ETYK

using namespace std;

void yyerror(const char *s);
void check_identifier(string name, int isArray);
void check_double_declaration(string name);
void load_memory_to_register(int memory, int reg);
void save_register_to_memory(int reg, int memory);
void save_number_to_memory(int number, int memory);

void odejmowanie_number_number(int a, int b);
void odejmowanie_identifier_number(int num);
void odejmowanie_number_identifier(int num);
void odejmowanie_identifier_identifier(int a, int b);
void rowne_number_number(int a, int b);
void rowne_identifier_number(int num);
void rowne_identifier_identifier();


void wykonaj_mnozenie();
void mnozenie_przygotuj_rejesty_i_pamiec_identifier_number(int numb);
void mnozenie_przygotuj_rejesty_i_pamiec_identifier_identifier();
void mnozenie_number_number(int num1, int num2);
void mnozenie_identifier_number(int numb);
void mnozenie_number_identifier(int numb);
void mnozenie_identifier_identifier();

void dzielenie_number_number(int a, int b);
void dzielenie_identifier_number(int num);
void dzielenie_number_identifier(int num);
void dzielenie_identifier_identifier();

void modulo_identifier_identifier();
void modulo_number_number(int a, int b);
void modulo_identifier_number(int num);
void modulo_number_identifier(int num);

extern "C" int yylex();
extern int yylineno;

struct var_data{
	int store;
	int isArray;
};

vector<string> code;
map<string, struct var_data> zmienne;
MyStack etykiety;
int i = 4;
int mem_to_save_id = 1;
int ety = 1;


#line 188 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    VAR = 259,
    _BEGIN = 260,
    END = 261,
    READ = 262,
    WRITE = 263,
    SKIP = 264,
    IF = 265,
    THEN = 266,
    ELSE = 267,
    ENDIF = 268,
    WHILE = 269,
    DO = 270,
    ENDWHILE = 271,
    GT = 272,
    LT = 273,
    EQ = 274,
    NEQ = 275,
    GOET = 276,
    LOET = 277,
    LB = 278,
    RB = 279,
    SREDNIK = 280,
    PRZYPISANIE = 281,
    PLUS = 282,
    MINUS = 283,
    MULT = 284,
    DIV = 285,
    MOD = 286,
    NUMBER = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 122 "parser.y" /* yacc.c:355  */

	int	ival;
        char*	sval;

#line 266 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 283 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   144,   145,   148,   154,   155,   157,   160,
     162,   166,   166,   175,   177,   179,   175,   184,   187,   184,
     191,   193,   194,   201,   202,   205,   208,   215,   216,   217,
     218,   222,   223,   224,   225,   229,   230,   231,   232,   236,
     237,   238,   239,   250,   251,   252,   253,   258,   259,   260,
     261,   266,   267,   268,   269,   274,   276,   278,   280,   286,
     288,   290,   292,   301,   306,   311,   316,   323,   328,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "VAR", "_BEGIN", "END",
  "READ", "WRITE", "SKIP", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "GT", "LT", "EQ", "NEQ", "GOET", "LOET", "LB", "RB",
  "SREDNIK", "PRZYPISANIE", "PLUS", "MINUS", "MULT", "DIV", "MOD",
  "NUMBER", "$accept", "program", "vdeclarations", "commands", "command",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "exp", "condition",
  "identifier", YY_NULLPTR
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
     285,   286,   287
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,   -67,    19,    15,   -67,   -21,   129,    -8,    38,    60,
      -2,    39,   -67,   -67,   113,   -67,   -67,    53,     0,    54,
      55,    82,   -67,     2,     2,   -67,   -67,    52,   -67,    72,
      88,   -67,   -67,   -67,    -6,   -67,   127,    98,     3,   -67,
     -67,     4,     7,    22,    23,    24,    25,   103,    26,    28,
      30,    35,    43,    56,   -67,   123,    93,   128,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     129,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   129,    62,    63,    65,    66,    67,   -67,
      68,    69,    70,    71,    73,   129,   101,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   114,   -67,   129,
     121,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     4,     0,     0,    67,     0,
       0,     0,    13,    17,     0,     7,    11,     0,     0,     0,
       0,     0,    20,     0,     0,     2,     6,     0,     5,     0,
       0,     8,     9,    10,     0,    14,     0,     0,     0,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    21,     0,    22,    43,    45,
      47,    49,    51,    53,    63,    65,    55,    57,    59,    61,
       0,    44,    46,    48,    50,    52,    54,    64,    66,    56,
      58,    60,    62,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,    15,     0,    23,    25,    27,
      29,    31,    33,    35,    37,    39,    41,    24,    26,    28,
      30,    32,    34,    36,    38,    40,    42,     0,    19,     0,
       0,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -66,   -14,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   109,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    14,    15,    27,    23,    47,   117,    24,
      83,    56,    35,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,     8,     7,    29,    95,     8,     8,     8,    19,    21,
       8,    41,    42,    43,    44,    45,    46,    96,     5,     4,
       6,     1,    36,    36,    17,     8,     8,     8,     8,     8,
      20,     8,    30,     8,    34,    55,    58,    57,     8,    60,
      59,    61,    63,    65,    67,    69,     8,    72,    74,    76,
      78,    80,    82,   120,    62,    64,    66,    68,    71,     8,
      73,    18,    75,     8,    22,     8,     8,    77,     8,     8,
       8,     8,     8,     8,     8,    79,     8,    28,    38,    31,
      32,    26,    26,    98,   100,   102,   104,   106,    81,   108,
     110,   112,   114,   116,    97,    99,    39,   101,   103,   105,
     107,   109,   111,   113,     8,   115,    26,    33,     9,    10,
      11,    12,    40,    54,    70,    13,     8,   118,    89,    25,
       9,    10,    11,    12,     8,     0,   119,    13,     9,    10,
      11,    12,     8,    37,   121,    13,     9,    10,    11,    12,
       0,     0,     0,    13,    48,    49,    50,    51,    52,    53,
      84,    85,    86,    87,    88,    90,    91,    92,    93,    94
};

static const yytype_int8 yycheck[] =
{
      14,     3,    23,     3,    70,     3,     3,     3,     9,    10,
       3,    17,    18,    19,    20,    21,    22,    83,     3,     0,
       5,     4,    23,    24,    32,     3,     3,     3,     3,     3,
      32,     3,    32,     3,    32,    32,    32,    38,     3,    32,
      41,    42,    43,    44,    45,    46,     3,    48,    49,    50,
      51,    52,    53,   119,    32,    32,    32,    32,    32,     3,
      32,    23,    32,     3,    25,     3,     3,    32,     3,     3,
       3,     3,     3,     3,     3,    32,     3,    24,    26,    25,
      25,    95,    96,    84,    85,    86,    87,    88,    32,    90,
      91,    92,    93,    94,    32,    32,    24,    32,    32,    32,
      32,    32,    32,    32,     3,    32,   120,    25,     7,     8,
       9,    10,    24,    15,    11,    14,     3,    16,    25,     6,
       7,     8,     9,    10,     3,    -1,    12,    14,     7,     8,
       9,    10,     3,    24,    13,    14,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    17,    18,    19,    20,    21,    22,
      27,    28,    29,    30,    31,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    34,    35,     0,     3,     5,    23,     3,     7,
       8,     9,    10,    14,    36,    37,    46,    32,    23,    46,
      32,    46,    25,    39,    42,     6,    37,    38,    24,     3,
      32,    25,    25,    25,    32,    45,    46,    45,    26,    24,
      24,    17,    18,    19,    20,    21,    22,    40,    17,    18,
      19,    20,    21,    22,    15,    32,    44,    46,    32,    46,
      32,    46,    32,    46,    32,    46,    32,    46,    32,    46,
      11,    32,    46,    32,    46,    32,    46,    32,    46,    32,
      46,    32,    46,    43,    27,    28,    29,    30,    31,    25,
      27,    28,    29,    30,    31,    36,    36,    32,    46,    32,
      46,    32,    46,    32,    46,    32,    46,    32,    46,    32,
      46,    32,    46,    32,    46,    32,    46,    41,    16,    12,
      36,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    36,    36,    37,    37,
      37,    38,    37,    39,    40,    41,    37,    42,    43,    37,
      37,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    46
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     5,     2,     1,     3,     3,
       3,     0,     5,     0,     0,     0,    10,     0,     0,     7,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     4
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
        case 4:
#line 145 "parser.y" /* yacc.c:1646  */
    {	check_double_declaration((yyvsp[0].sval));
							struct var_data v = { i++, 0 };
							zmienne[(yyvsp[0].sval)] = v;				}
#line 1447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "parser.y" /* yacc.c:1646  */
    {	check_double_declaration((yyvsp[-3].sval));
							struct var_data v = { i, 1 };
							zmienne[(yyvsp[-3].sval)] = v;
							i += (yyvsp[-1].ival);					}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1,0); mem_to_save_id = 1;
							GET(1) 
							STORE(1)				}
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "parser.y" /* yacc.c:1646  */
    {	create_number(code, (yyvsp[-1].ival), 1);
							PUT(1)						}
#line 1471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "parser.y" /* yacc.c:1646  */
    {	mem_to_save_id = 1;
							load_memory_to_register(1,0);
							LOAD(1)
							PUT(1)						}
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 166 "parser.y" /* yacc.c:1646  */
    {	mem_to_save_id = 1;
							load_memory_to_register(1, 1);
							save_register_to_memory(1, 3);			}
#line 1488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 169 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(3, 0);
							STORE(1)
							mem_to_save_id = 1;				}
#line 1496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 175 "parser.y" /* yacc.c:1646  */
    {       PUSH_ETYK(ety+1) PUSH_ETYK(ety)
                                                        PUSH_ETYK(ety+1) PUSH_ETYK(ety) ety+=2;         }
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 177 "parser.y" /* yacc.c:1646  */
    {       JZERO(1, etykiety.pop()) mem_to_save_id=1;	}
#line 1509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 179 "parser.y" /* yacc.c:1646  */
    {       JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK				}
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 183 "parser.y" /* yacc.c:1646  */
    {       POP_AND_WRITE_ETYK				}
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "parser.y" /* yacc.c:1646  */
    {	PUSH_ETYK(ety) PUSH_ETYK(ety+1) PUSH_ETYK(ety)
							PUSH_ETYK(ety+1) ety+=2;
							POP_AND_WRITE_ETYK				}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 187 "parser.y" /* yacc.c:1646  */
    {	mem_to_save_id=1;
							JZERO(1, etykiety.pop())			}
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "parser.y" /* yacc.c:1646  */
    {	JUMP(etykiety.pop())
							POP_AND_WRITE_ETYK				}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 191 "parser.y" /* yacc.c:1646  */
    { }
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 193 "parser.y" /* yacc.c:1646  */
    {       create_number(code, (yyvsp[0].ival), 1);                     }
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 194 "parser.y" /* yacc.c:1646  */
    {       create_number(code, 1, 0);
                                                        LOAD(1)
                                                        COPY(1)
                                                        LOAD(1)                                         }
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 201 "parser.y" /* yacc.c:1646  */
    {	create_number(code, (yyvsp[-2].ival)+(yyvsp[0].ival), 1);			}
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 202 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1, 0);
							create_number(code, (yyvsp[0].ival), 1);
							ADD(1)						}
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 205 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1,0);
							create_number(code, (yyvsp[-2].ival), 1);
							ADD(1)						}
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 208 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1,0);
							LOAD(1)						
							load_memory_to_register(2,0);						
							ADD(1)						}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 215 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 216 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_number((yyvsp[0].ival));		}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 217 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_identifier((yyvsp[-2].ival));		}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 218 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_identifier(1,2);		}
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "parser.y" /* yacc.c:1646  */
    {	mnozenie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));			}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "parser.y" /* yacc.c:1646  */
    {	mnozenie_identifier_number((yyvsp[0].ival));			}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "parser.y" /* yacc.c:1646  */
    {	mnozenie_number_identifier((yyvsp[-2].ival));			}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "parser.y" /* yacc.c:1646  */
    {	mnozenie_identifier_identifier();		}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 229 "parser.y" /* yacc.c:1646  */
    {	dzielenie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 230 "parser.y" /* yacc.c:1646  */
    {	dzielenie_identifier_number((yyvsp[0].ival));		}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 231 "parser.y" /* yacc.c:1646  */
    {	dzielenie_number_identifier((yyvsp[-2].ival));		}
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 232 "parser.y" /* yacc.c:1646  */
    {	dzielenie_identifier_identifier();		}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 236 "parser.y" /* yacc.c:1646  */
    {	modulo_number_number((yyvsp[-2].ival), (yyvsp[0].ival));			}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 237 "parser.y" /* yacc.c:1646  */
    {	modulo_identifier_number((yyvsp[0].ival));			}
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "parser.y" /* yacc.c:1646  */
    {	modulo_number_identifier((yyvsp[-2].ival));			}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 239 "parser.y" /* yacc.c:1646  */
    {	modulo_identifier_identifier();			}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 250 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		}
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 251 "parser.y" /* yacc.c:1646  */
    {       odejmowanie_identifier_number((yyvsp[0].ival));		}
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 252 "parser.y" /* yacc.c:1646  */
    {       odejmowanie_number_identifier((yyvsp[-2].ival));		}
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 253 "parser.y" /* yacc.c:1646  */
    {       odejmowanie_identifier_identifier(1,2);		}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 258 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[0].ival), (yyvsp[-2].ival));	}
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 259 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_identifier((yyvsp[0].ival));	}
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 260 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_number((yyvsp[-2].ival));	}
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 261 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_identifier(2,1);	}
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 266 "parser.y" /* yacc.c:1646  */
    {	rowne_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		}
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 267 "parser.y" /* yacc.c:1646  */
    {	rowne_identifier_number((yyvsp[0].ival));		}
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 268 "parser.y" /* yacc.c:1646  */
    {	rowne_identifier_number((yyvsp[-2].ival));		}
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 269 "parser.y" /* yacc.c:1646  */
    {	rowne_identifier_identifier();		}
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 274 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[0].ival), (yyvsp[-2].ival));
                                                       	XOET				}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 276 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_identifier((yyvsp[0].ival));	//wieksze
							XOET				}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 278 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_number((yyvsp[-2].ival));	//wieksze
							XOET				}
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 280 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_identifier(2,1);
							XOET				}
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 286 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival)); 	//mniejsze
							XOET				}
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 288 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_number((yyvsp[0].ival));
							XOET				}
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 290 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_identifier((yyvsp[-2].ival));
							XOET				}
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 292 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_identifier(1,2);
							XOET				}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 301 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));
							NEQ_2
							odejmowanie_number_number((yyvsp[0].ival), (yyvsp[-2].ival));
							NEQ_3				}
#line 1830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 306 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_identifier_number((yyvsp[0].ival));
							NEQ_2
							odejmowanie_number_identifier((yyvsp[0].ival));
							NEQ_3				}
#line 1840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 311 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_number_identifier((yyvsp[-2].ival));
							NEQ_2
							odejmowanie_identifier_number((yyvsp[-2].ival));
							NEQ_3				}
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 316 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_identifier_identifier(1,2);
							NEQ_2
							odejmowanie_identifier_identifier(2,1);
							NEQ_3				}
#line 1860 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 323 "parser.y" /* yacc.c:1646  */
    {	check_identifier((yyvsp[0].sval), 0);
							create_number(code, mem_to_save_id, 0);
							create_number(code, zmienne[(yyvsp[0].sval)].store, 1);
							STORE(1)
							mem_to_save_id++;				}
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 328 "parser.y" /* yacc.c:1646  */
    {	check_identifier((yyvsp[-3].sval), 1);
							check_identifier((yyvsp[-1].sval), 0);
							create_number(code, zmienne[(yyvsp[-1].sval)].store, 0);
							create_number(code, zmienne[(yyvsp[-3].sval)].store, 1);
							ADD(1)
							create_number(code, mem_to_save_id, 0);
							STORE(1)
							mem_to_save_id++;				}
#line 1883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 336 "parser.y" /* yacc.c:1646  */
    {	check_identifier((yyvsp[-3].sval), 1);
							create_number(code, (yyvsp[-1].ival), 1);
							ZERO(0)
							STORE(1)
							create_number(code, zmienne[(yyvsp[-3].sval)].store, 1);
							ADD(1)
							create_number(code, mem_to_save_id, 0);
							STORE(1)
							mem_to_save_id++;				}
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1901 "parser.tab.c" /* yacc.c:1646  */
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
#line 347 "parser.y" /* yacc.c:1906  */


/****** CHECK *******************************************************************************************/
/********************************************************************************************************/
/*
Sprawdzenie czy zmienna o nazwie 'name' nie zostala zadeklarowana kolejny raz
Jezeli tak sie stalo, zakoncz program z odpowiednia wiadomoscia					
*/
void check_double_declaration(string name){
	if( zmienne.find(name) != zmienne.end() ){
                string err = string("Deklaracja istniejacej zmiennej \"") + string(name) + string("\"");
                yyerror(err.c_str());
        }
}

/* 
Sprawdzamy czy przeczytany identyfikator o nazwie 'name' zostal wczesniej zadeklarowany, oraz
czy jest on tablica (wtedy isArray = 1), czy jest zmienna (isArray = 0).
Jezeli ktorys z tych warunkow zawiedzie konczymy program z odpowiednim komunikatem.		
*/ 
void check_identifier(string name, int isArray){
	if( zmienne.find(name) == zmienne.end() ){
		string err = string("Niezadeklarowana zmienna \"") + string(name) + string("\"");
		yyerror(err.c_str());
	}
	else if( zmienne[name].isArray != isArray ){
		string err = string("Niewlasciwe uzycie identyfikatora \"") + string(name) +string("\"");
		yyerror(err.c_str());
	}
}

/*
Funkcja generujaca asembler ktory dziala na rejestrze 0. Wczytuje on dana z komorki pamieci
'memory' do rejestru 'reg'.
*/
void load_memory_to_register(int memory, int reg){
	create_number(code, memory, 0);
	LOAD(reg)
}

void save_register_to_memory(int reg, int memory){
	create_number(code, memory, 0);
	STORE(reg)
}

void save_number_to_memory(int number, int memory){
	create_number(code, number, 1);
	create_number(code, memory, 0);
	STORE(1)
}

/************************************************************************/
/***** OPERACJE *********************************************************/
/************************************************************************/

void odejmowanie_number_number(int a, int b){
	create_number(code, numbSub(a, b), 1);
}

void odejmowanie_identifier_number(int num){
	save_number_to_memory(num, 0);
	load_memory_to_register(1, 0);		
	LOAD(1)
	ZERO(0)
	SUB(1)
}

void odejmowanie_number_identifier(int num){
	load_memory_to_register(1, 0);
	create_number(code, num, 1);
	SUB(1)
}

/*zmienne a b oznaczaja ktory identifier jest odejmowany od ktorego, czyli:
	a=1, b=2 -> odejmujemy id1 - id2
	a=2, b=1 -> odejmujemy id2 - id1	*/
void odejmowanie_identifier_identifier(int a, int b){
	load_memory_to_register(a,0);
	LOAD(1)
	load_memory_to_register(b,0);
	SUB(1)
}

/****** MNOZENIE ********************************************************/

void mnozenie_przygotuj_rejesty_i_pamiec_identifier_number(int numb){
	MULT_MEM_1
	create_number(code, numb, 2);	//A>B
	create_number(code, 1, 0);	//A>B
	LOAD(0)				//A>B
	LOAD(3)				//A>B
	MULT_MEM_2
	create_number(code, 1, 0);	//A<=B
	LOAD(0)				//A<=B
	LOAD(2)				//A<=B
	create_number(code, numb, 3);	//A<=B
	MULT_MEM_3
}

void mnozenie_przygotuj_rejesty_i_pamiec_number_identifier(int numb){
	MULT_MEM_1
	create_number(code, numb, 3);	//A>B
	create_number(code, 1, 0);	//A>B
	LOAD(0)				//A>B
	LOAD(2)				//A>B
	MULT_MEM_2
	create_number(code, 1, 0);	//A<=B
	LOAD(0)				//A<=B
	LOAD(3)				//A<=B
	create_number(code, numb, 2);	//A<=B
	MULT_MEM_3
}

void mnozenie_przygotuj_rejesty_i_pamiec_identifier_identifier(){
	MULT_MEM_1
	create_number(code, 2, 0);	//A>B
	LOAD(0)				//A>B
	LOAD(2)				//A>B
	create_number(code, 1, 0);	//A>B
	LOAD(0)				//A>B
	LOAD(3)				//A>B
	MULT_MEM_2
	create_number(code, 1, 0);	//A<=B
	LOAD(0)				//A<=B
	LOAD(2)				//A<=B
	create_number(code, 2, 0);	//A<=B
	LOAD(0)				//A<=B
	LOAD(3)				//A<=B
	MULT_MEM_3
}

void wykonaj_mnozenie(){
	PUSH_ETYK(ety+3) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1) PUSH_ETYK(ety)
	PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+3) PUSH_ETYK(ety+2) ety+=4;
	POP_AND_WRITE_ETYK
	JZERO(2, etykiety.pop())
	JODD(2, etykiety.pop())
	JUMP(etykiety.pop())
	POP_AND_WRITE_ETYK
	ADD(1)
	POP_AND_WRITE_ETYK
	SHR(2)
	SHL(3)
	STORE(3)
	JUMP(etykiety.pop())
	POP_AND_WRITE_ETYK
}

void mnozenie_number_number(int num1, int num2){
	create_number(code, num1*num2, 1);
}

void mnozenie_identifier_number(int numb){
	odejmowanie_identifier_number(numb);
	mnozenie_przygotuj_rejesty_i_pamiec_identifier_number(numb);
	wykonaj_mnozenie();
}

void mnozenie_number_identifier(int numb){
	odejmowanie_number_identifier(numb);
	mnozenie_przygotuj_rejesty_i_pamiec_number_identifier(numb);
	wykonaj_mnozenie();
}

void mnozenie_identifier_identifier(){
	odejmowanie_identifier_identifier(1,2);
	mnozenie_przygotuj_rejesty_i_pamiec_identifier_identifier();
	wykonaj_mnozenie();
}

/****** DZIELENIE *******************************************************/


void dzielenie_przygotuj_rejesty_i_pamiec_identifier_number(int num){
	PUSH_ETYK(ety) ety+=1; //etykieta, majaca za zadanie wyskoczyc z dzielenia jezeli tylko bedziemy chcieli dzielic przez 0
	create_number(code, num, 1); //w r1 jest mianownik
	JZERO(1, etykiety.pop()) //sprawdz czy mianownik rowny 0, jesli tak wyskocz z calego dzielenia i zwroc 0, oraz reszte 0
	create_number(code, 1, 0); //bedziemy pobierac wartosc z store 1
	LOAD(0) //pobierz adres do rejestru 0
	LOAD(2) //w r2 jest licznik
	ZERO(0) 
	STORE(1) //w memory 0 jest mianownik
}

void dzielenie_przygotuj_rejesty_i_pamiec_number_identifier(int num){
	PUSH_ETYK(ety) ety+=1; //etykieta, majaca za zadanie wyskoczyc z dzielenia jezeli tylko bedziemy chcieli dzielic przez 0
	create_number(code, 1, 0); //bedziemy pobierac wartosc z store 1
	LOAD(0) //pobierz adres do rejestru 0
	LOAD(1) //w r1 jest mianownik
	JZERO(1, etykiety.pop()) //sprawdz czy mianownik rowny 0, jesli tak wyskocz z calego dzielenia i zwroc 0, oraz reszte 0
	create_number(code, num, 2); //w r2 jest licznik
	ZERO(0) 
	STORE(1) //w memory 0 jest mianownik
}

void dzielenie_przygotuj_rejesty_i_pamiec_identifier_identifier(){
	PUSH_ETYK(ety) ety+=1; //etykieta, majaca za zadanie wyskoczyc z dzielenia jezeli tylko bedziemy chcieli dzielic przez 0
	create_number(code, 2, 0); //bedziemy pobierac wartosc z store 2
	LOAD(0) //pobierz adres do rejestru 0
	LOAD(1) //w r1 jest mianownik
	JZERO(1, etykiety.pop()) //sprawdz czy mianownik rowny 0, jesli tak wyskocz z calego dzielenia i zwroc 0, oraz reszte 0
	create_number(code, 1, 0); //bedziemy pobierac wartosc z store 1
	LOAD(0) //pobierz adres do rejestru 0
	LOAD(2) //w r2 jest licznik
	ZERO(0) 
	STORE(1) //w memory 0 jest mianownik
}

/* otrzymujemy w rejestrze 2 licznik ktory odwracamy i zapisujemy w rejestrze 3
   ustawiamy rowniez straznika na pierwszej pozycji od lewej, abysmy mogli przy
   dzieleniu identyfikowac koniec naszego licznika */
void dzielenie_odwroc_licznik(){
	create_number(code, 1, 3); //tworzymy straznika
	PUSH_ETYK(ety+2) PUSH_ETYK(ety+1) PUSH_ETYK(ety)
	PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1) ety+=3;
	POP_AND_WRITE_ETYK
	JZERO(2, etykiety.pop()) //warunek konca
	SHL(3) //juz przesowamy w lewno r3, moze dodamy 1
	JODD(2, etykiety.pop()) 
	SHR(2)			//w r2 przeczytalismy 0 na koncu, czyli
	JUMP(etykiety.pop())	//nic nie dodajemy
	POP_AND_WRITE_ETYK
	INC(3)			//w r2 przeczytalismy 1 na koncu
	SHR(2)			//czyli dodajemy 1 do r3
	JUMP(etykiety.pop())
	POP_AND_WRITE_ETYK
}

void wykonaj_dzielenie(){
	dzielenie_odwroc_licznik(); //odwracamy licznik, czyli r3 <= 1 + r3^R i dodajemy straznika
	PUSH_ETYK(ety+3) PUSH_ETYK(ety-4) PUSH_ETYK(ety+4) PUSH_ETYK(ety+2) PUSH_ETYK(ety+4) //druga etykieta odnosi sie do jumpa w przypadku mianownik=0 
	PUSH_ETYK(ety+2) PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1) PUSH_ETYK(ety)
	PUSH_ETYK(ety+3) PUSH_ETYK(ety+4) ety+=5;
	ZERO(1) //zerujemy rejestr pierwszy
	POP_AND_WRITE_ETYK
	DEC(3)				//odejmij 1 od r3
	JZERO(3, etykiety.pop())	//sprawdz czy rowne 0
	INC(3)				//jezeli tak koniec dzielenia, jezeli nie dzielimy dalej
	SHL(1) //przesun wynij w lewo
	SHL(2)	//przesun r2 w lewo
	JODD(3, etykiety.pop())	//jezeli na koncu r3 jest 1
	JUMP(etykiety.pop())	//to dodaj 1 do r2, jezeli
	POP_AND_WRITE_ETYK	//nie to nic nie dodamy
	INC(2)			//i zostanie 0
	POP_AND_WRITE_ETYK	//
	SHR(3) //przesowanie odwroconego licznika w prawo, nie bedzie juz potrzebny
	INC(0)		//zapisanie r2
	STORE(2)	//do miejsca w pamieci nr 1
	ZERO(0)	//
	LOAD(2) //odejmij r2 <- mianownik - r2
	INC(0)  //dzieki temu gdy wyjdzie nam 0 wiemy ze mianownik byl <= od r2
	SUB(2)	//wtedy, dodamy 1 do wyniku, jesli wyjdzie cos != 0, to nie dodajemy
	JZERO(2,etykiety.pop()) 	//sprawdzenie wyniku odejmowania
	LOAD(2)			//zaladuj spowrotem
	ZERO(0)			//r2 do rejestru 2	MIANOWNIK > r2
	JUMP(etykiety.pop())	//
	POP_AND_WRITE_ETYK
	LOAD(2)			//odejmij r2-mianownik
	ZERO(0)			//i zwieksz wynik o 1	MIANOWNIK <= r2
	SUB(2)			//
	INC(1)			//
	JUMP(etykiety.pop())
	POP_AND_WRITE_ETYK 	//etykieta odpowiedzialna za przypadek X/0
	ZERO(1)			//ustawiamy wynik na 0
	ZERO(2)			//oraz modulo na 0
	POP_AND_WRITE_ETYK
}

void dzielenie_number_number(int a, int b){
	if(b == 0){
		ZERO(1)
		ZERO(2)
		return;
	}
	create_number(code, a/b, 1);
}

void dzielenie_identifier_number(int num){
	dzielenie_przygotuj_rejesty_i_pamiec_identifier_number(num);
	wykonaj_dzielenie();
}

void dzielenie_number_identifier(int num){
	dzielenie_przygotuj_rejesty_i_pamiec_number_identifier(num);
	wykonaj_dzielenie();
}

void dzielenie_identifier_identifier(){
	dzielenie_przygotuj_rejesty_i_pamiec_identifier_identifier();
	wykonaj_dzielenie();
}

/******* MODULO *******************************************************************/
/*Wykonujemy dzielenie, kopiujemy rejestr 2 do rejestru 1*/
void modulo_number_number(int a, int b){
	if(b == 0){
		ZERO(1)
		ZERO(2)
		return;
	}
	create_number(code, a%b, 1);
}

void modulo_identifier_number(int num){
	dzielenie_identifier_number(num);
	ZERO(0)
	STORE(2)
	LOAD(1)
}

void modulo_number_identifier(int num){
	dzielenie_number_identifier(num);
	ZERO(0)
	STORE(2)
	LOAD(1)
}

void modulo_identifier_identifier(){
	dzielenie_identifier_identifier();
	ZERO(0)
	STORE(2)
	LOAD(1)
}

/************************************************************************/
/***** WARUNKI **********************************************************/
/************************************************************************/
void rowne_number_number(int a, int b){
	EQ_1
	odejmowanie_number_number(a, b);	//odejmowanie
	EQ_2
	odejmowanie_number_number(b, a);	//odejmowanie
	EQ_3
}

void rowne_identifier_number(int num){
	EQ_1
	odejmowanie_identifier_number(num);	//odejmowanie
	EQ_2
	odejmowanie_number_identifier(num);	//odejmowanie
	EQ_3
}

void rowne_identifier_identifier(){
	EQ_1
	odejmowanie_identifier_identifier(1,2);	//odejmowanie
	EQ_2
	odejmowanie_identifier_identifier(2,1);	//odejmowanie
	EQ_3
}


/************************************************************************/
/***** PRZEBIEGI ********************************************************/
/************************************************************************/

void zapamietajPozycjeEtykiet(map<string, string> &ety_pos){
        for(int j=0 ; j<code.size(); j++){
                if(isPrefix("E", code[j])){
                        ostringstream ss;
                        ss << j;
                        ety_pos[code[j]] = ss.str();
                        code.erase(code.begin()+j);
                        j--;
                }
        }
}

void podmienEtykiety(map<string, string> &ety_pos){
       for(int j=0 ; j<code.size() ; j++)
                if(isPrefix("JUMP", code[j]) || isPrefix("JZERO", code[j]) || isPrefix("JODD", code[j]))
                        code[j] = replaceLastWord( code[j], ety_pos[ getLastWord(code[j]) ] );
}

void wypiszAssembler(){
	for(int j=0; j<code.size(); j++)
		cout << code[j] << endl;
	cout << "HALT" << endl;
}

/************************************************************************/
/******** MAIN **********************************************************/
/************************************************************************/

int main()
{
	yyparse();
	map<string, string> ety_pos;
	zapamietajPozycjeEtykiet(ety_pos);
	podmienEtykiety(ety_pos);
	wypiszAssembler();
}


void yyerror(const char *s){
        cout << "Blad. " << s << " w linii " << yylineno << endl;
        exit(0);
}
