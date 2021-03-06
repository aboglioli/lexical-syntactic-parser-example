/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "declare_list.y" /* yacc.c:339  */

	#include <stdio.h>
	int yylex();
	int yyparse();
	FILE *yyin;
	FILE *yyout;
	int lines;
	int token_num;

	// Se usan en el analisis lexico para almacenar los tokens y sus respectivos valores.
	char *stToken[1024];
	char *stValue[1024];
	int stID ;

	// Se usa en el analisis sintactico para almacenar los niveles y los simbolos encontrados
	struct s_treeLevel;
	struct s_token {
		char *name;
		int no_terminal;
		int level_ref;
	};
	struct s_treeLevel {
		int level;
		int cant_tokens;
		struct s_token token[128];
	} treeLevel[1024];
	int tLevel = 0;
	int tID = 0;
	int found_errors = 0;

	char *error[128];

#line 99 "declare_list.tab.c" /* yacc.c:339  */

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
   by #include "declare_list.tab.h".  */
#ifndef YY_YY_DECLARE_LIST_TAB_H_INCLUDED
# define YY_YY_DECLARE_LIST_TAB_H_INCLUDED
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
    T_STRING = 258,
    T_ARRAY = 259,
    T_CLASS = 260,
    T_FUNC = 261,
    T_METHOD = 262,
    T_LINE = 263,
    T_FILE = 264,
    T_LNUMBER = 265,
    T_DNUMBER = 266,
    T_CONSTANT_ENCAPSED_STRING = 267,
    T_DOUBLE_TWO_POINTS = 268,
    T_DOUBLE_ARROW = 269,
    T_END = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 34 "declare_list.y" /* yacc.c:355  */

	int val;
	float f;
	char *text;

#line 161 "declare_list.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DECLARE_LIST_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "declare_list.tab.c" /* yacc.c:358  */

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  61

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

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
      20,    21,     2,    18,    17,    19,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    16,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    66,    67,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    87,    88,
      89,    90,    91,    92,    93,    96,    97,    98,   103,   104,
     105,   106,   107,   108,   109,   110,   114,   115,   116,   119,
     120,   124,   127,   128,   132,   133,   136,   137
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_STRING", "T_ARRAY", "T_CLASS",
  "T_FUNC", "T_METHOD", "T_LINE", "T_FILE", "T_LNUMBER", "T_DNUMBER",
  "T_CONSTANT_ENCAPSED_STRING", "T_DOUBLE_TWO_POINTS", "T_DOUBLE_ARROW",
  "T_END", "'='", "','", "'+'", "'-'", "'('", "')'", "$accept",
  "declare_list", "static_scalar", "common_scalar",
  "static_array_pair_list", "static_class_constant", "static_array_pair", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    61,    44,    43,    45,
      40,    41
};
# endif

#define YYPACT_NINF -23

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-23)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     109,    -7,    74,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,     7,   160,   160,   160,     2,    -5,   -23,   -23,    12,
     160,     3,   160,   126,    92,     4,   -14,   -23,   -23,   -23,
     -23,   -23,   -23,     8,   -23,   143,   160,   -23,   -23,   -23,
     -23,   -13,   160,   126,   -23,   160,    10,   160,     9,   -23,
      55,   -23,   -23,   -23,   -23,   160,   -23,   160,   -23,   -23,
     -23
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,    25,    33,    35,    34,    31,    32,    28,    29,
      30,     0,     6,     0,     0,     0,     7,    18,    24,    43,
       9,    19,     0,     0,    36,    44,     0,    37,    42,     8,
      20,    21,     1,     0,     4,     0,     0,    41,     2,    46,
      39,    26,    47,    40,    27,     0,    11,    12,    13,    10,
      40,    22,    45,    38,    17,    15,    14,     0,    23,     3,
      16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,     0,   -23,     5,   -23,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    25,    17,    26,    18,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    40,    32,    43,    50,    33,    19,    44,    51,    20,
      28,    36,    29,    30,    31,    37,    19,    34,    42,    35,
      38,    53,    39,    19,    45,    57,    55,     0,    53,    41,
       0,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,    52,     0,     0,    54,     0,    56,     0,     0,
       0,     0,     0,     0,     0,    59,     0,    60,    21,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    22,
       0,     0,     0,    13,    14,     0,    58,    21,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    22,     0,
       0,    23,    13,    14,    24,    21,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    22,     0,     0,    23,
      13,    14,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,     0,    12,     0,    13,    14,    21,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      22,     0,     0,     0,    13,    14,    46,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,    47,
       0,    13,    14,    21,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,    13,    14
};

static const yytype_int8 yycheck[] =
{
       0,    23,     0,    17,    17,     3,    13,    21,    21,    16,
       3,    16,    12,    13,    14,     3,    13,    15,    14,    17,
      20,    43,    22,    13,    16,    16,    16,    -1,    50,    24,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    57,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    18,    19,    -1,    21,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    17,    18,    19,    20,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      18,    19,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    16,    -1,    18,    19,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    18,    19,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,    18,    19,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    16,    18,    19,    23,    24,    25,    27,    13,
      16,     3,    14,    17,    20,    24,    26,    28,     3,    24,
      24,    24,     0,     3,    15,    17,    16,     3,    24,    24,
      28,    26,    14,    17,    21,    16,     3,    16,    24,    24,
      17,    21,    24,    28,    24,    16,    24,    16,    21,    24,
      24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    22,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    25,    25,
      25,    25,    25,    25,    25,    25,    26,    26,    26,    26,
      26,    27,    27,    27,    28,    28,    28,    28
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     5,     2,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     4,     4,     5,     4,     1,     1,
       2,     2,     4,     5,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3,     2,
       2,     3,     2,     2,     1,     3,     2,     2
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
#line 65 "declare_list.y" /* yacc.c:1646  */
    { addT("T_STRING"); addT("="); addNT("static_scalar"); addLevel(); }
#line 1313 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 66 "declare_list.y" /* yacc.c:1646  */
    { addNT("declare_list"); addT(","); addT("T_STRING"); addT("="); addNT("static_scalar"); addLevel();}
#line 1319 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "declare_list.y" /* yacc.c:1646  */
    { addNT("declare_list");return 0; }
#line 1325 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "declare_list.y" /* yacc.c:1646  */
    { addE("Solo se encontro T_STRING"); }
#line 1331 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "declare_list.y" /* yacc.c:1646  */
    { addE("Solo se encontro '='"); }
#line 1337 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 72 "declare_list.y" /* yacc.c:1646  */
    { addE("Solo se encontro static_scalar"); }
#line 1343 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "declare_list.y" /* yacc.c:1646  */
    { addE("Falta T_STRING antes de '='"); }
#line 1349 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "declare_list.y" /* yacc.c:1646  */
    { addE("Falta static_scalar despues de '='"); }
#line 1355 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 75 "declare_list.y" /* yacc.c:1646  */
    { addE("Se esperaba T_STRING en lugar de static_scalar antes de '='"); }
#line 1361 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "declare_list.y" /* yacc.c:1646  */
    { addE("Solo se encontro T_STRING"); }
#line 1367 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 77 "declare_list.y" /* yacc.c:1646  */
    { addE("Solo se encontro '='"); }
#line 1373 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 78 "declare_list.y" /* yacc.c:1646  */
    { addE("Solo se encontro static_scalar"); }
#line 1379 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 79 "declare_list.y" /* yacc.c:1646  */
    { addE("Falta T_STRING antes de '='"); }
#line 1385 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 80 "declare_list.y" /* yacc.c:1646  */
    { addE("Falta static_scalar despues de '='"); }
#line 1391 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 81 "declare_list.y" /* yacc.c:1646  */
    { addE("Se esperaba T_STRING en lugar de static_scalar antes de '='"); }
#line 1397 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 82 "declare_list.y" /* yacc.c:1646  */
    { addE("Falta ',' como separador"); }
#line 1403 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 87 "declare_list.y" /* yacc.c:1646  */
    { addNT("common_scalar"); addLevel(); }
#line 1409 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 88 "declare_list.y" /* yacc.c:1646  */
    { addT("T_STRING"); addLevel(); }
#line 1415 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "declare_list.y" /* yacc.c:1646  */
    { addT("+"); addNT("static_scalar"); addLevel(); }
#line 1421 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 90 "declare_list.y" /* yacc.c:1646  */
    { addT("-"); addNT("static_scalar"); addLevel(); }
#line 1427 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 91 "declare_list.y" /* yacc.c:1646  */
    { addT("T_ARRAY"); addT("("); addNT("static_array_pair_list"); addT(")"); addLevel(); }
#line 1433 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 92 "declare_list.y" /* yacc.c:1646  */
    { addT("T_ARRAY"); addT("("); addNT("static_array_pair_list"); addT(","); addT(")"); addLevel(); }
#line 1439 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 93 "declare_list.y" /* yacc.c:1646  */
    { addNT("static_class_constant"); addLevel(); }
#line 1445 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 96 "declare_list.y" /* yacc.c:1646  */
    { addE("Falta argumento de array. Formato T_ARRAY (...)"); }
#line 1451 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 97 "declare_list.y" /* yacc.c:1646  */
    { addE("No se cerro T_ARRAY correctamente. Falta ')' al final."); }
#line 1457 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 98 "declare_list.y" /* yacc.c:1646  */
    { addE("No se abrio T_ARRAY correctamente. Falta '(' al inicio."); }
#line 1463 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 103 "declare_list.y" /* yacc.c:1646  */
    { addT("T_LNUMBER"); addLevel(); }
#line 1469 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 104 "declare_list.y" /* yacc.c:1646  */
    { addT("T_DNUMBER"); addLevel(); }
#line 1475 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 105 "declare_list.y" /* yacc.c:1646  */
    { addT("T_CONSTANT_ENCAPSED_STRING"); addLevel(); }
#line 1481 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 106 "declare_list.y" /* yacc.c:1646  */
    { addT("T_LINE"); addLevel(); }
#line 1487 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 107 "declare_list.y" /* yacc.c:1646  */
    { addT("T_FILE"); addLevel(); }
#line 1493 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 108 "declare_list.y" /* yacc.c:1646  */
    { addT("T_CLASS"); addLevel(); }
#line 1499 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 109 "declare_list.y" /* yacc.c:1646  */
    { addT("T_METHOD"); addLevel(); }
#line 1505 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 110 "declare_list.y" /* yacc.c:1646  */
    { addT("T_FUNC"); addLevel(); }
#line 1511 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "declare_list.y" /* yacc.c:1646  */
    { addT("T_EMPTY"); addLevel(); }
#line 1517 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 115 "declare_list.y" /* yacc.c:1646  */
    { addNT("static_array_pair"); addLevel(); }
#line 1523 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 116 "declare_list.y" /* yacc.c:1646  */
    { addNT("static_array_pair_list"); addT(","); addNT("static_array_pair"); addLevel(); }
#line 1529 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 119 "declare_list.y" /* yacc.c:1646  */
    { addE("La lista dentro de array no puede comenzar con ','"); }
#line 1535 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 120 "declare_list.y" /* yacc.c:1646  */
    { addE("La lista dentro de array tiene argumentos vacios"); }
#line 1541 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 124 "declare_list.y" /* yacc.c:1646  */
    { addT("T_STRING"); addT("T_DOUBLE_TWO_POINTS"); addT("T_STRING"); addLevel(); }
#line 1547 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 127 "declare_list.y" /* yacc.c:1646  */
    { addE("No se encontro T_STRING antes de T_DOUBLE_TWO_POINTS"); }
#line 1553 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 128 "declare_list.y" /* yacc.c:1646  */
    { addE("No se encontro T_STRING despues de T_DOUBLE_TWO_POINTS"); }
#line 1559 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 132 "declare_list.y" /* yacc.c:1646  */
    { addNT("static_scalar"); addLevel(); }
#line 1565 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 133 "declare_list.y" /* yacc.c:1646  */
    { addNT("static_scalar"); addT("T_DOUBLE_ARROW"); addNT("static_scalar"); addLevel(); }
#line 1571 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 136 "declare_list.y" /* yacc.c:1646  */
    { addE("No se encontro static_scalar antes de T_DOUBLE_ARROW"); }
#line 1577 "declare_list.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 137 "declare_list.y" /* yacc.c:1646  */
    { addE("No se encontro static_scalar despues de T_DOUBLE_ARROW"); }
#line 1583 "declare_list.tab.c" /* yacc.c:1646  */
    break;


#line 1587 "declare_list.tab.c" /* yacc.c:1646  */
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
#line 139 "declare_list.y" /* yacc.c:1906  */


int yyerror(char *s) {
	error[found_errors] = (char*) malloc(strlen("Error desconocido: ") + strlen(s) + 1);
	strcpy(error[found_errors], "Error desconocido: ");
	strcat(error[found_errors], s);
	found_errors++;
	return 0;
}

int yywrap() {
	return 1;
}

void addT(char *t) {
	treeLevel[tLevel].token[tID].name = (char*) malloc(strlen(t) + 1);
	strcpy(treeLevel[tLevel].token[tID].name, t);
	//printf("%s(%d) ", treeLevel[tLevel].token[tID].name, tID);

	treeLevel[tLevel].token[tID++].no_terminal = 0;
	treeLevel[tLevel].cant_tokens++;
}

void addNT(char *t) {
	treeLevel[tLevel].token[tID].name = (char*) malloc(strlen(t) + 1);
	strcpy(treeLevel[tLevel].token[tID].name, t);

	treeLevel[tLevel].token[tID++].no_terminal = 1;
	treeLevel[tLevel].cant_tokens++;
}

void addLevel() {
	//treeLevel[tLevel].cant_tokens = tID;
	//printf("\n<cant_token: %d>\n", treeLevel[tLevel].cant_tokens);
	tID = 0;
	tLevel++;
}

void addE(char *e) {
	error[found_errors] = (char*) malloc(strlen(e) + 1);
	strcpy(error[found_errors++], e);
}

/* Funciones mas importantes para imprimir arbol sintactico y la tabla de simbolos */
//Imprime errores por consola
void printErrors() {
	int i;
	for(i=0; i<found_errors; i++) {
		printf("%d: %s\n", i+1, error[i]);
	}
}

// Imprime la tabla de simbolos generada en el analisis lexico (archivo declare_list.l, de flex)
void printSymbolTable() {
	int i;
	for(i=0; i<stID; i++) {
		printf("[%s]: %s\n", stToken[i], stValue[i]);
	}
}

// Arma el arbol. Coloca en la variable "level_ref" de los no terminales el nivel, es decir, el conjunto de simbolos al que hacen referencia para luego reemplazarlos.
int makeTree(int i) {
	int j;
	int found_no_terminals=0;
	for(j=treeLevel[i].cant_tokens-1; j>=0; --j) {
		if(treeLevel[i].token[j].no_terminal == 1) {
			found_no_terminals++;
			treeLevel[i].token[j].level_ref = i-found_no_terminals; //La raiz del arbol es el ultimo nivel agregado a la estructura, por lo que no es 0, asi que hay que invertir el orden en que se lee la estructura.
			//printf("Asignado %d a %s(%d)\n", treeLevel[i].token[j].level_ref, treeLevel[i].token[j].name, i);
			found_no_terminals += makeTree(i-found_no_terminals);
		}
	}
	return found_no_terminals;
}

// Imprime cada nivel del arbol, desarrollando desde la raiz hacia abajo (ramas)
int printTreeLevel(int n, int i) {
	int j;
	int printed_no_terminals = 0;
	for(j=0; j<treeLevel[n].cant_tokens; j++) {
		if(treeLevel[n].token[j].no_terminal) {
			printed_no_terminals++;
			if(i>0) {
				if(i == 1) { // Resalta los simbolso que se agregaron en reemplazo del no terminal encontrado.
					printf("{ ");
					printed_no_terminals += printTreeLevel(treeLevel[n].token[j].level_ref, i-1);
					printf("} ");
				}
				else {
					printed_no_terminals += printTreeLevel(treeLevel[n].token[j].level_ref, i-1);
				}
			}
			else {
				// Imprime los no terminales entre < >
				printf("<%s> ", treeLevel[n].token[j].name);
			}
		}
		else {
			printf("%s ", treeLevel[n].token[j].name);
		}
	}
	return printed_no_terminals;
}


// Imprime el arbol sintactico. Empieza por la raiz o primer nivel y va reemplazando los no terminales por el conjunto de simbolos que hacen referencia, los cuales derivan de este.
void printTree() {
	if(found_errors > 0) {
		printf("No se puede imprimir el arbol sintactico debido a que se encontraron errores.\n");
	}
	else {
		int fnt = makeTree(tLevel);
		int i = 0;
		for(i=0; ; i++) {
			if(printTreeLevel(tLevel, i) == fnt) {
				printf("\n");
				printTreeLevel(tLevel, i+1);
				printf("\n");
				printTreeLevel(tLevel, i+2);
				break;
			}
			printf("\n");
		}
	}
}

/* Guardar en HTML*/
// Funciones para imprimir en archivo HTML.
void printErrorsToHTML(FILE *htmlFile) {
	fprintf(htmlFile, "<h4>Se encontraron %d errores en el análisis.</h4>", found_errors);
	fprintf(htmlFile, "<p style=\"color:orange;\">Formato: T_STRING = static_scalar</p>", found_errors);
	int i;
	fprintf(htmlFile, "<ul>");
	for(i=0; i<found_errors; i++) {
		fprintf(htmlFile, "<li>%s</li>", error[i]);
	}
	fprintf(htmlFile, "</ul>");
}

void printStatementToHTML(FILE *htmlFile) {
	int i;
	fprintf(htmlFile, "<ul><li>");
	for(i=0; i<stID; i++) {
		fprintf(htmlFile, "%s ", stValue[i]);
		if(strcmp(stValue[i], ",") == 0)  {
			fprintf(htmlFile, "</li><li>");
		}
	}
	fprintf(htmlFile, "</li></ul>");
}

void printSymbolTableToHTML(FILE *htmlFile) {
	int i;
	for(i=0; i<stID; i++) {
		fprintf(htmlFile, "<tr><td>%s</td><td>%s</td></tr>", stToken[i], stValue[i]);
	}
}

int printTreeLevelToHTML(int n, int i, FILE *htmlFile) {
	int j;
	int printed_no_terminals = 0;
	for(j=0; j<treeLevel[n].cant_tokens; j++) {
		if(treeLevel[n].token[j].no_terminal) {
			printed_no_terminals++;
			if(i>0) {
				if(i == 1) { // Resalta los simbolso que se agregaron en reemplazo del no terminal encontrado.
					fprintf(htmlFile, "<i>");
					printed_no_terminals += printTreeLevelToHTML(treeLevel[n].token[j].level_ref, i-1, htmlFile);
					fprintf(htmlFile, "</i>");
				}
				else {
					printed_no_terminals += printTreeLevelToHTML(treeLevel[n].token[j].level_ref, i-1, htmlFile);
				}
			}
			else {
				// Imprime los no terminales entre < >
				fprintf(htmlFile, "<b>&lt;%s&gt;</b> ", treeLevel[n].token[j].name);
			}
		}
		else {
			fprintf(htmlFile, "%s ", treeLevel[n].token[j].name);
		}
	}
	return printed_no_terminals;
}

void printTreeToHTML(FILE *htmlFile) {
	if(found_errors > 0) {
		printf("No se puede imprimir el arbol sintactico debido a que se encontraron errores.\n");
	}
	else {
		int fnt = makeTree(tLevel);
		int i = 0;
		fprintf(htmlFile, "<ol>");
		for(i=0; ; i++) {
			fprintf(htmlFile, "<li>");
			if(printTreeLevelToHTML(tLevel, i, htmlFile) == fnt) {
				fprintf(htmlFile, "</li><li>");
				printTreeLevelToHTML(tLevel, i+1, htmlFile);
				fprintf(htmlFile, "</li></ol>");
				fprintf(htmlFile, "<h3>Cadena analizada</h3>");
				fprintf(htmlFile, "<p>");
				printTreeLevelToHTML(tLevel, i+2, htmlFile);
				fprintf(htmlFile, "</p>");
				break;
			}
			fprintf(htmlFile, "</li>");
			printf("\n");
		}
	}
}
