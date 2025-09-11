/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0



/* Substitute the type names.  */
#define YYSTYPE CATSTYPE
/* Substitute the variable and function names.  */
#define yyparse catparse
#define yylex   catlex
#define yyerror caterror
#define yydebug catdebug
#define yylval  catlval
#define yychar  catchar
#define yynerrs catnerrs

/* First part of user prologue.  */
#line 1 "../src/cat.y"


/* Prologue */

#include "cat.h"
#include "symbol.hh"

#define new(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define newn(TYPE, CT) (TYPE*)malloc(sizeof(TYPE)*CT)

void caterror (const char*);

/* handle end of file */
int yywrap ();

using namespace CatLang;

std::vector <Symbol*> scopes;


#line 87 "cat.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cat.tab.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '('  */
  YYSYMBOL_4_ = 4,                         /* ')'  */
  YYSYMBOL_5_ = 5,                         /* '['  */
  YYSYMBOL_6_ = 6,                         /* ']'  */
  YYSYMBOL_7_ = 7,                         /* '{'  */
  YYSYMBOL_8_ = 8,                         /* '}'  */
  YYSYMBOL_9_ = 9,                         /* '!'  */
  YYSYMBOL_10_ = 10,                       /* '#'  */
  YYSYMBOL_11_ = 11,                       /* '$'  */
  YYSYMBOL_12_ = 12,                       /* '%'  */
  YYSYMBOL_13_ = 13,                       /* '&'  */
  YYSYMBOL_14_ = 14,                       /* '*'  */
  YYSYMBOL_15_ = 15,                       /* '+'  */
  YYSYMBOL_16_ = 16,                       /* ','  */
  YYSYMBOL_17_ = 17,                       /* '-'  */
  YYSYMBOL_18_ = 18,                       /* '.'  */
  YYSYMBOL_19_ = 19,                       /* '/'  */
  YYSYMBOL_20_ = 20,                       /* ':'  */
  YYSYMBOL_21_ = 21,                       /* ';'  */
  YYSYMBOL_22_ = 22,                       /* '<'  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_25_ = 25,                       /* '?'  */
  YYSYMBOL_26_ = 26,                       /* '@'  */
  YYSYMBOL_27_ = 27,                       /* '^'  */
  YYSYMBOL_28___ = 28,                     /* '_'  */
  YYSYMBOL_29_ = 29,                       /* '|'  */
  YYSYMBOL_30_ = 30,                       /* '~'  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_INCREMENT = 33,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 34,                 /* DECREMENT  */
  YYSYMBOL_SHIFT_L = 35,                   /* SHIFT_L  */
  YYSYMBOL_SHIFT_R = 36,                   /* SHIFT_R  */
  YYSYMBOL_ROTATE_L = 37,                  /* ROTATE_L  */
  YYSYMBOL_ROTATE_R = 38,                  /* ROTATE_R  */
  YYSYMBOL_COMPARE = 39,                   /* COMPARE  */
  YYSYMBOL_INEQUAL = 40,                   /* INEQUAL  */
  YYSYMBOL_AT_MOST = 41,                   /* AT_MOST  */
  YYSYMBOL_AT_LEAST = 42,                  /* AT_LEAST  */
  YYSYMBOL_TAIL = 43,                      /* TAIL  */
  YYSYMBOL_ELLIPSES = 44,                  /* ELLIPSES  */
  YYSYMBOL_CONST_INT = 45,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 46,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_STRING = 47,              /* CONST_STRING  */
  YYSYMBOL_CONST_CHAR = 48,                /* CONST_CHAR  */
  YYSYMBOL_COMMENT_LINE = 49,              /* COMMENT_LINE  */
  YYSYMBOL_COMMENT_BLOCK = 50,             /* COMMENT_BLOCK  */
  YYSYMBOL_NAME = 51,                      /* NAME  */
  YYSYMBOL_BIT = 52,                       /* BIT  */
  YYSYMBOL_CHAR = 53,                      /* CHAR  */
  YYSYMBOL_BYTE = 54,                      /* BYTE  */
  YYSYMBOL_SHORT = 55,                     /* SHORT  */
  YYSYMBOL_INT = 56,                       /* INT  */
  YYSYMBOL_FLOAT = 57,                     /* FLOAT  */
  YYSYMBOL_ALIAS = 58,                     /* ALIAS  */
  YYSYMBOL_INCLUDE = 59,                   /* INCLUDE  */
  YYSYMBOL_INLINE = 60,                    /* INLINE  */
  YYSYMBOL_SIZEOF = 61,                    /* SIZEOF  */
  YYSYMBOL_COUNTOF = 62,                   /* COUNTOF  */
  YYSYMBOL_NAMEOF = 63,                    /* NAMEOF  */
  YYSYMBOL_TYPEOF = 64,                    /* TYPEOF  */
  YYSYMBOL_LOCAL = 65,                     /* LOCAL  */
  YYSYMBOL_STATIC = 66,                    /* STATIC  */
  YYSYMBOL_CONST = 67,                     /* CONST  */
  YYSYMBOL_EXTERN = 68,                    /* EXTERN  */
  YYSYMBOL_SIGNED = 69,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 70,                  /* UNSIGNED  */
  YYSYMBOL_COMPLEX = 71,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 72,                 /* IMAGINARY  */
  YYSYMBOL_LONG = 73,                      /* LONG  */
  YYSYMBOL_DOUBLE = 74,                    /* DOUBLE  */
  YYSYMBOL_BREAK = 75,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 76,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 77,                    /* RETURN  */
  YYSYMBOL_GOTO = 78,                      /* GOTO  */
  YYSYMBOL_STRUCT = 79,                    /* STRUCT  */
  YYSYMBOL_UNION = 80,                     /* UNION  */
  YYSYMBOL_MODULE = 81,                    /* MODULE  */
  YYSYMBOL_ENUM = 82,                      /* ENUM  */
  YYSYMBOL_WHILE = 83,                     /* WHILE  */
  YYSYMBOL_DO = 84,                        /* DO  */
  YYSYMBOL_FOR = 85,                       /* FOR  */
  YYSYMBOL_IF = 86,                        /* IF  */
  YYSYMBOL_ELSE = 87,                      /* ELSE  */
  YYSYMBOL_SWITCH = 88,                    /* SWITCH  */
  YYSYMBOL_CASE = 89,                      /* CASE  */
  YYSYMBOL_DEFAULT = 90,                   /* DEFAULT  */
  YYSYMBOL_EMPTY = 91,                     /* EMPTY  */
  YYSYMBOL_INFIX = 92,                     /* INFIX  */
  YYSYMBOL_PREFIX = 93,                    /* PREFIX  */
  YYSYMBOL_POSTFIX = 94,                   /* POSTFIX  */
  YYSYMBOL_ATOMIC = 95,                    /* ATOMIC  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_block = 97,                     /* block  */
  YYSYMBOL_statement = 98,                 /* statement  */
  YYSYMBOL_semicolon = 99,                 /* semicolon  */
  YYSYMBOL_colon = 100,                    /* colon  */
  YYSYMBOL_label = 101,                    /* label  */
  YYSYMBOL_members = 102,                  /* members  */
  YYSYMBOL_103_case_expression = 103,      /* case-expression  */
  YYSYMBOL_range = 104,                    /* range  */
  YYSYMBOL_105_else_block = 105,           /* else-block  */
  YYSYMBOL_iterator = 106,                 /* iterator  */
  YYSYMBOL_line = 107,                     /* line  */
  YYSYMBOL_scope = 108,                    /* scope  */
  YYSYMBOL_109_braced_scope = 109,         /* braced-scope  */
  YYSYMBOL_110_enum_scope = 110,           /* enum-scope  */
  YYSYMBOL_optional_instances = 111,       /* optional_instances  */
  YYSYMBOL_module = 112,                   /* module  */
  YYSYMBOL_113_struct_module_union = 113,  /* struct-module-union  */
  YYSYMBOL_qualifiers = 114,               /* qualifiers  */
  YYSYMBOL_qualifier = 115,                /* qualifier  */
  YYSYMBOL_variable = 116,                 /* variable  */
  YYSYMBOL_variables = 117,                /* variables  */
  YYSYMBOL_instances = 118,                /* instances  */
  YYSYMBOL_instance = 119,                 /* instance  */
  YYSYMBOL_lengths = 120,                  /* lengths  */
  YYSYMBOL_length = 121,                   /* length  */
  YYSYMBOL_initializer = 122,              /* initializer  */
  YYSYMBOL_function = 123,                 /* function  */
  YYSYMBOL_tuple = 124,                    /* tuple  */
  YYSYMBOL_125_parameters_or_none = 125,   /* parameters-or-none  */
  YYSYMBOL_parameters = 126,               /* parameters  */
  YYSYMBOL_type = 127,                     /* type  */
  YYSYMBOL_128_type_qualifiers = 128,      /* type-qualifiers  */
  YYSYMBOL_129_type_qualifier = 129,       /* type-qualifier  */
  YYSYMBOL_indirection = 130,              /* indirection  */
  YYSYMBOL_pointer = 131,                  /* pointer  */
  YYSYMBOL_const = 132,                    /* const  */
  YYSYMBOL_datatype = 133,                 /* datatype  */
  YYSYMBOL_134_basic_type = 134,           /* basic-type  */
  YYSYMBOL_longs = 135,                    /* longs  */
  YYSYMBOL_long = 136,                     /* long  */
  YYSYMBOL_int = 137,                      /* int  */
  YYSYMBOL_expressions = 138,              /* expressions  */
  YYSYMBOL_139_list_expression = 139,      /* list-expression  */
  YYSYMBOL_expression = 140,               /* expression  */
  YYSYMBOL_value = 141,                    /* value  */
  YYSYMBOL_142_const_value = 142,          /* const-value  */
  YYSYMBOL_143_meta_value = 143,           /* meta-value  */
  YYSYMBOL_prefix_operator = 144,          /* prefix_operator  */
  YYSYMBOL_postfix_operator = 145,         /* postfix_operator  */
  YYSYMBOL_infix_operator = 146,           /* infix_operator  */
  YYSYMBOL_arithmetic = 147                /* arithmetic  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 5
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     9,     2,    10,    11,    12,    13,     2,
       3,     4,    14,    15,    16,    17,    18,    19,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    20,    21,
      22,    24,    23,    25,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     2,     6,    27,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     7,    29,     8,    30,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95
};

#if CATDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   170,   170,   174,   182,   190,   201,   211,   222,   233,
     243,   251,   259,   269,   279,   290,   303,   315,   327,   339,
     351,   365,   366,   369,   370,   373,   374,   378,   388,   389,
     393,   400,   401,   404,   405,   408,   409,   418,   428,   429,
     430,   440,   444,   445,   446,   449,   452,   453,   454,   457,
     458,   461,   475,   479,   480,   481,   484,   485,   488,   489,
     490,   491,   494,   497,   500,   501,   504,   505,   508,   509,
     512,   515,   516,   519,   522,   525,   526,   530,   531,   534,
     537,   538,   542,   543,   544,   545,   546,   549,   550,   553,
     554,   557,   558,   562,   563,   564,   565,   568,   569,   570,
     571,   572,   573,   574,   575,   578,   579,   582,   583,   586,
     587,   591,   592,   604,   613,   622,   623,   624,   625,   628,
     631,   634,   646,   654,   662,   666,   667,   668,   669,   673,
     682,   691,   702,   703,   704,   705,   706,   707,   708,   709,
     713,   714,   718,   718,   718,   718,   719,   719,   719,   719,
     720,   721,   722,   725,   725,   725,   725,   726,   726,   726,
     726,   727,   727,   728,   728
};
#endif

#define YYPACT_NINF (-152)
#define YYTABLE_NINF (-109)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -152,   195,  -152,   465,   648,   648,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
      -4,   -15,     9,   648,   648,   648,    48,    48,   626,    19,
     648,    17,   553,   648,   648,   648,     2,  -152,    20,  -152,
    -152,  -152,    27,    47,   861,  -152,  -152,  -152,   648,  -152,
    -152,    40,     5,   861,   285,  -152,    61,    59,    48,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   799,    48,   736,  -152,
    -152,   648,  -152,     8,  -152,   553,    32,    67,    -1,   736,
     736,     2,   767,  -152,    28,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,     9,     9,  -152,    48,  -152,     9,    99,   648,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,   648,    65,    28,  -152,  -152,
     648,  -152,    39,     9,  -152,  -152,  -152,  -152,   736,   375,
     648,    92,    11,  -152,   648,    10,  -152,  -152,   648,  -152,
      34,    32,  -152,    95,    83,  -152,    97,  -152,  -152,  -152,
      49,  -152,  -152,     9,  -152,  -152,  -152,  -152,  -152,    29,
    -152,  -152,  -152,  -152,  -152,   -39,    30,   861,    28,  -152,
     861,  -152,    48,  -152,  -152,   799,  -152,   830,    32,  -152,
     861,     9,  -152,     9,  -152,  -152,     7,    32,     9,  -152,
     106,    96,     9,  -152,  -152,  -152,    12,  -152,  -152,  -152,
    -152,  -152,   575,  -152,  -152,   103,    83,    69,   648,   648,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,    50,    50,
    -152,  -152,  -152,  -152,   700,   861,  -152,  -152,  -152,  -152,
    -152
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     2,   132,   139,   138,
     136,   137,    41,   133,   134,   135,   125,   126,   128,   127,
      28,     0,     0,     0,     0,     0,    23,    23,    23,     0,
       0,    25,    56,     0,     0,     0,    25,     3,   122,    22,
      37,    21,    80,    23,   111,   117,   123,   124,     0,     4,
      28,     0,     0,   113,     0,     6,    27,     0,    23,   129,
     130,   131,    24,    11,    10,    14,    23,    23,    25,    26,
      44,     0,     2,     0,    42,    56,    25,     0,    80,    25,
      25,    25,    31,     8,   121,    61,    58,    59,    60,    53,
      55,    54,     0,     0,    57,    23,    39,     0,   107,     0,
      40,   155,   156,   153,   157,   158,   154,   146,   148,   152,
     159,   160,   142,   143,   140,   141,   161,   162,   163,   164,
     144,   145,   147,   149,   120,     0,   150,   118,   115,   116,
       0,    45,     0,     0,     9,    13,    12,    17,    25,     0,
       0,     0,     0,    20,     0,    33,    16,     7,     0,    30,
      25,    25,    38,    68,    63,    64,    80,    97,    98,    99,
     109,   102,   103,     0,    82,    83,    84,    85,    86,   105,
      96,    94,    81,    87,    93,   109,     0,   112,   119,   151,
     114,    29,    23,    18,    43,    23,    35,     0,    25,    15,
      32,    49,    48,    49,    52,    51,    71,    25,     0,    77,
       0,    76,     0,   110,   100,    95,    79,   106,   101,   104,
       5,    19,    56,    34,    68,     0,    50,     0,     0,     0,
      67,    69,    66,    73,    65,    74,    80,    62,    91,    91,
      88,    36,    46,    47,     0,    72,    78,    92,    90,    89,
      70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,     1,   111,   -18,   -23,   -17,  -152,  -152,  -152,  -152,
      43,   -30,     6,     3,  -152,   -78,  -152,  -152,   -29,  -152,
    -107,  -152,    24,  -151,  -152,  -152,  -152,  -152,   -31,  -152,
    -152,  -142,  -152,  -152,  -152,  -152,  -106,  -152,  -152,  -152,
    -152,   -51,    -3,  -152,    -5,  -152,  -152,  -152,  -152,  -152,
    -152,  -152
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    37,   100,    72,    38,    56,    81,   149,   189,
      76,    39,    73,    74,   194,   215,    41,    93,    42,    94,
     199,    95,   216,   155,   196,   221,   222,    96,   171,   200,
     201,    97,    98,   172,   206,   230,   238,   173,   174,   175,
     176,   204,    43,    52,    44,    45,    46,    47,    48,   124,
     125,   126
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    51,    77,    78,    40,    58,    40,    54,    63,    64,
      65,   129,   218,    83,   202,   128,    55,   203,    59,    60,
      61,   130,    69,    66,     6,    68,   228,    99,    79,    80,
      82,   219,    62,    84,   207,    40,    57,    69,    70,     6,
     134,   191,   229,   127,   128,    77,    78,   224,   135,   136,
     220,   227,    69,    70,    69,   192,    99,    40,   147,    85,
      50,   114,   115,    99,    86,    87,   138,    88,    62,    62,
      67,  -109,   142,   139,   137,   150,   151,   152,    40,   132,
     153,   170,   143,   133,   202,   145,   146,    85,   144,   179,
     181,   140,    86,    87,   177,    88,   186,   188,   156,   198,
      71,   -75,   156,  -108,   209,   203,    89,    90,    91,    92,
     225,   232,   226,   233,    49,   217,   182,   237,   141,   236,
     178,   154,   197,   239,   208,   180,     0,   193,     0,     0,
       0,     0,     0,     0,     0,   185,     0,     0,     0,   187,
       0,     0,    40,   190,   183,     0,   205,     0,     0,     0,
      50,   157,   158,   159,   160,   161,   162,   195,     0,     0,
       0,     0,     0,   163,   210,     0,   164,   211,   165,   166,
     167,   168,   169,     0,   214,     0,   214,     0,     0,     0,
       0,   214,   231,    78,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     2,     3,     0,     4,     0,
       5,     0,     6,   223,     7,     0,     0,     0,     8,     9,
      10,     0,    11,   234,   235,    40,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,     0,     0,    20,   -56,   -56,   -56,
     -56,   -56,   -56,    21,    22,   -56,    23,    24,    25,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
      26,    27,    28,    29,   -56,   -56,   -56,   -56,    30,    31,
      32,    33,     0,    34,    35,    36,     3,     0,     4,     0,
       5,     0,     6,   131,     7,     0,     0,     0,     8,     9,
      10,     0,    11,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,     0,     0,    20,   -56,   -56,   -56,
     -56,   -56,   -56,    21,    22,   -56,    23,    24,    25,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
      26,    27,    28,    29,   -56,   -56,   -56,   -56,    30,    31,
      32,    33,     0,    34,    35,    36,     3,     0,     4,     0,
       5,     0,     6,     0,     7,     0,     0,     0,     8,     9,
      10,     0,    11,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
      16,    17,    18,    19,     0,     0,    20,   -56,   -56,   -56,
     -56,   -56,   -56,    21,    22,   -56,    23,    24,    25,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
      26,    27,    28,    29,   -56,   -56,   -56,   -56,    30,    31,
      32,    33,     0,    34,    35,    36,     3,     0,     4,     0,
       5,     0,     6,     0,     7,     0,     0,     0,     8,     9,
      10,     0,    11,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,     0,     0,    20,   -56,   -56,   -56,
     -56,   -56,   -56,    21,    22,   -56,    23,    24,    25,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
      26,    27,    28,    29,   -56,   -56,   -56,   -56,    30,    31,
      32,    33,     0,    34,    35,    36,    75,     0,     5,     0,
       6,     0,     7,     0,     0,     0,     8,     9,    10,     0,
      11,     0,     0,     0,    12,     0,     0,     0,     4,     0,
       5,     0,     6,    13,     7,     0,    14,    15,     8,     9,
      10,     0,    11,     0,     0,     0,    12,     0,    16,    17,
      18,    19,     0,     0,    50,    13,     0,     0,    14,    15,
       0,     0,     0,     0,    23,    24,    25,     0,     0,     0,
      16,    17,    18,    19,     0,     0,    50,     0,     0,     4,
       0,     5,     0,     0,     0,     7,    23,    24,    25,     8,
       9,    10,     0,    11,     0,     0,     0,    62,     0,     0,
       0,     4,     0,     5,     0,     0,    13,     7,     0,    14,
      15,     8,     9,    10,     0,    11,     0,     0,     0,     0,
       0,    16,    17,    18,    19,     0,     0,    50,    13,     0,
       0,    14,    15,     0,     0,     0,     0,    23,    24,    25,
       0,     0,     0,    16,    17,    18,    19,     0,     0,    50,
       0,     0,     0,     0,     0,     0,   240,     0,     0,    23,
      24,    25,   101,   102,   103,   104,     0,   105,     0,   106,
       0,     0,   107,   108,   109,     0,     0,   110,     0,   111,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     6,     0,     0,     0,     0,   101,   102,
     103,   104,     0,   105,     0,   106,    69,    70,   107,   108,
     109,     0,     0,   110,     0,   111,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   101,
     102,   103,   104,     0,   105,     0,   106,     0,     0,   107,
     108,   109,     0,     0,   110,     0,   111,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     148,   101,   102,   103,   104,     0,   105,     0,   106,     0,
      62,   107,   108,   109,     0,     0,   110,     0,   111,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   101,   102,   103,   104,     0,   105,     0,   106,
       0,   212,   107,   108,   109,     0,     0,   110,     0,   111,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   101,   102,   103,   104,     0,   105,     0,
     106,     0,     0,   107,   108,   109,     0,     0,   110,     0,
     111,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123
};

static const yytype_int16 yycheck[] =
{
       5,     4,    32,    32,     1,    22,     3,     6,    26,    27,
      28,     6,     5,    36,   156,     4,    20,    56,    23,    24,
      25,    16,    20,    28,     7,    30,    14,    16,    33,    34,
      35,    24,    21,    38,    73,    32,    51,    20,    21,     7,
      58,     7,    30,    48,     4,    75,    75,   198,    66,    67,
      43,   202,    20,    21,    20,    21,    16,    54,    81,    60,
      51,    33,    34,    16,    65,    66,    71,    68,    21,    21,
      51,    51,    75,    72,    68,    92,    93,    95,    75,    18,
      97,    98,    76,    24,   226,    79,    80,    60,    21,    24,
      51,    83,    65,    66,    99,    68,     4,    87,     3,    16,
      83,     4,     3,    74,    74,    56,    79,    80,    81,    82,
       4,     8,    16,    44,     3,   193,   133,    67,    75,   226,
     125,    97,   153,   229,   175,   130,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,
      -1,    -1,   139,   148,   138,    -1,   163,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,   151,    -1,    -1,
      -1,    -1,    -1,    64,   182,    -1,    67,   185,    69,    70,
      71,    72,    73,    -1,   191,    -1,   193,    -1,    -1,    -1,
      -1,   198,   212,   212,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,     0,     1,    -1,     3,    -1,
       5,    -1,     7,   197,     9,    -1,    -1,    -1,    13,    14,
      15,    -1,    17,   218,   219,   212,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,     1,    -1,     3,    -1,
       5,    -1,     7,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,     1,    -1,     3,    -1,
       5,    -1,     7,    -1,     9,    -1,    -1,    -1,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,     1,    -1,     3,    -1,
       5,    -1,     7,    -1,     9,    -1,    -1,    -1,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,     3,    -1,     5,    -1,
       7,    -1,     9,    -1,    -1,    -1,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    21,    -1,    -1,    -1,     3,    -1,
       5,    -1,     7,    30,     9,    -1,    33,    34,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    -1,    45,    46,
      47,    48,    -1,    -1,    51,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      45,    46,    47,    48,    -1,    -1,    51,    -1,    -1,     3,
      -1,     5,    -1,    -1,    -1,     9,    61,    62,    63,    13,
      14,    15,    -1,    17,    -1,    -1,    -1,    21,    -1,    -1,
      -1,     3,    -1,     5,    -1,    -1,    30,     9,    -1,    33,
      34,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    51,    30,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    45,    46,    47,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    61,
      62,    63,    12,    13,    14,    15,    -1,    17,    -1,    19,
      -1,    -1,    22,    23,    24,    -1,    -1,    27,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    12,
      13,    14,    15,    -1,    17,    -1,    19,    -1,    -1,    22,
      23,    24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    12,    13,    14,    15,    -1,    17,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    12,    13,    14,    15,    -1,    17,    -1,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    12,    13,    14,    15,    -1,    17,    -1,
      19,    -1,    -1,    22,    23,    24,    -1,    -1,    27,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,     0,     1,     3,     5,     7,     9,    13,    14,
      15,    17,    21,    30,    33,    34,    45,    46,    47,    48,
      51,    58,    59,    61,    62,    63,    75,    76,    77,    78,
      83,    84,    85,    86,    88,    89,    90,    98,   101,   107,
     109,   112,   114,   138,   140,   141,   142,   143,   144,    98,
      51,   138,   139,   140,    97,    20,   102,    51,   101,   140,
     140,   140,    21,    99,    99,    99,   140,    51,   140,    20,
      21,    83,   100,   108,   109,     3,   106,   107,   114,   140,
     140,   103,   140,   100,   140,    60,    65,    66,    68,    79,
      80,    81,    82,   113,   115,   117,   123,   127,   128,    16,
      99,    12,    13,    14,    15,    17,    19,    22,    23,    24,
      27,    29,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   145,   146,   147,   140,     4,     6,
      16,     8,    18,    24,    99,    99,    99,   108,   140,    97,
      83,   106,   138,   108,    21,   108,   108,   100,    43,   104,
     101,   101,    99,   101,   118,   119,     3,    52,    53,    54,
      55,    56,    57,    64,    67,    69,    70,    71,    72,    73,
     101,   124,   129,   133,   134,   135,   136,   140,   140,    24,
     140,    51,   101,   108,    44,   140,     4,   140,    87,   105,
     140,     7,    21,   100,   110,   108,   120,   124,    16,   116,
     125,   126,   127,    56,   137,   101,   130,    73,   137,    74,
      99,    99,    21,   108,   101,   111,   118,   111,     5,    24,
      43,   121,   122,   108,   119,     4,    16,   119,    14,    30,
     131,   107,     8,    44,   140,   140,   116,    67,   132,   132,
       6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   100,   101,   102,   102,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   108,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   113,   114,   114,   115,   115,
     115,   115,   116,   117,   118,   118,   119,   119,   120,   120,
     121,   122,   122,   123,   124,   125,   125,   126,   126,   127,
     128,   128,   129,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   133,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   140,   140,   140,
     140,   140,   141,   141,   141,   142,   142,   142,   142,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     5,     2,     3,     2,     3,
       2,     2,     3,     3,     2,     4,     3,     3,     4,     5,
       3,     1,     1,     0,     1,     0,     1,     2,     0,     3,
       2,     0,     2,     0,     2,     3,     5,     1,     3,     2,
       2,     1,     1,     3,     1,     3,     3,     3,     1,     0,
       1,     4,     4,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     2,     2,     1,     3,     3,     3,     0,     2,
       3,     0,     2,     4,     3,     0,     1,     1,     3,     3,
       0,     2,     1,     1,     1,     1,     1,     0,     2,     2,
       2,     0,     1,     1,     1,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     1,     2,     0,     1,     0,
       1,     1,     3,     1,     3,     3,     3,     1,     2,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != CATEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if CATDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'('", "')'", "'['",
  "']'", "'{'", "'}'", "'!'", "'#'", "'$'", "'%'", "'&'", "'*'", "'+'",
  "','", "'-'", "'.'", "'/'", "':'", "';'", "'<'", "'>'", "'='", "'?'",
  "'@'", "'^'", "'_'", "'|'", "'~'", "AND", "OR", "INCREMENT", "DECREMENT",
  "SHIFT_L", "SHIFT_R", "ROTATE_L", "ROTATE_R", "COMPARE", "INEQUAL",
  "AT_MOST", "AT_LEAST", "TAIL", "ELLIPSES", "CONST_INT", "CONST_FLOAT",
  "CONST_STRING", "CONST_CHAR", "COMMENT_LINE", "COMMENT_BLOCK", "NAME",
  "BIT", "CHAR", "BYTE", "SHORT", "INT", "FLOAT", "ALIAS", "INCLUDE",
  "INLINE", "SIZEOF", "COUNTOF", "NAMEOF", "TYPEOF", "LOCAL", "STATIC",
  "CONST", "EXTERN", "SIGNED", "UNSIGNED", "COMPLEX", "IMAGINARY", "LONG",
  "DOUBLE", "BREAK", "CONTINUE", "RETURN", "GOTO", "STRUCT", "UNION",
  "MODULE", "ENUM", "WHILE", "DO", "FOR", "IF", "ELSE", "SWITCH", "CASE",
  "DEFAULT", "EMPTY", "INFIX", "PREFIX", "POSTFIX", "ATOMIC", "$accept",
  "block", "statement", "semicolon", "colon", "label", "members",
  "case-expression", "range", "else-block", "iterator", "line", "scope",
  "braced-scope", "enum-scope", "optional_instances", "module",
  "struct-module-union", "qualifiers", "qualifier", "variable",
  "variables", "instances", "instance", "lengths", "length", "initializer",
  "function", "tuple", "parameters-or-none", "parameters", "type",
  "type-qualifiers", "type-qualifier", "indirection", "pointer", "const",
  "datatype", "basic-type", "longs", "long", "int", "expressions",
  "list-expression", "expression", "value", "const-value", "meta-value",
  "prefix_operator", "postfix_operator", "infix_operator", "arithmetic", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if CATDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)





/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !CATDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !CATDEBUG */



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if CATDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == CATEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= CATEOF)
    {
      *yycharp = CATEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = CATEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* block: %empty  */
#line 171 "../src/cat.y"
        {
		((*yyvalp).scope) = new (Scope);
	}
#line 1581 "cat.tab.c"
    break;

  case 3: /* block: block statement  */
#line 175 "../src/cat.y"
        {
		((*yyvalp).scope) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.scope);
		((*yyvalp).scope)->insert ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symbol));
	}
#line 1590 "cat.tab.c"
    break;

  case 4: /* statement: error statement  */
#line 183 "../src/cat.y"
        {
		// TODO: structured and intuitive error handling
		
		// [!] On error, abort and start a new statement
		((*yyvalp).symbol) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symbol);
	}
#line 1601 "cat.tab.c"
    break;

  case 5: /* statement: ALIAS NAME '=' label semicolon  */
#line 191 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::ALIAS;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->alias.name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token)->text;
		((*yyvalp).symbol)->alias.path = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label));
	}
#line 1615 "cat.tab.c"
    break;

  case 6: /* statement: NAME ':'  */
#line 202 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::MARKER;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->marker.name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->text;
	}
#line 1628 "cat.tab.c"
    break;

  case 7: /* statement: CASE case-expression colon  */
#line 212 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::CASE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->case_marker.expression = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.case_range) [0];
		((*yyvalp).symbol)->case_marker.fallthrough = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.case_range) [1];
	}
#line 1642 "cat.tab.c"
    break;

  case 8: /* statement: DEFAULT colon  */
#line 223 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::CASE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		
		// (should be zero already, but just in case)
		((*yyvalp).symbol)->case_marker.expression = 0;
	}
#line 1656 "cat.tab.c"
    break;

  case 9: /* statement: INCLUDE label semicolon  */
#line 234 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::INCLUDE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->include.path = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label));
	}
#line 1669 "cat.tab.c"
    break;

  case 10: /* statement: CONTINUE semicolon  */
#line 244 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::CONTINUE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
	}
#line 1680 "cat.tab.c"
    break;

  case 11: /* statement: BREAK semicolon  */
#line 252 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::BREAK;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
	}
#line 1691 "cat.tab.c"
    break;

  case 12: /* statement: GOTO NAME semicolon  */
#line 260 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::GOTO;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->go_to.marker = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->text;
	}
#line 1704 "cat.tab.c"
    break;

  case 13: /* statement: RETURN expression semicolon  */
#line 270 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::RETURN;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->return_marker.value = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
	}
#line 1717 "cat.tab.c"
    break;

  case 14: /* statement: RETURN semicolon  */
#line 280 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::RETURN;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		
		// (should already be 0, but just in case)
		((*yyvalp).symbol)->return_marker.value = 0;
	}
#line 1731 "cat.tab.c"
    break;

  case 15: /* statement: IF expression scope else-block  */
#line 291 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.scope));
		((*yyvalp).symbol)->scope.kind = Scope::IF;
		((*yyvalp).symbol)->scope.condition = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression);
		((*yyvalp).symbol)->scope.alternate = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope);
	}
#line 1747 "cat.tab.c"
    break;

  case 16: /* statement: SWITCH expression scope  */
#line 304 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope));
		((*yyvalp).symbol)->scope.kind = Scope::SWITCH;
		((*yyvalp).symbol)->scope.condition = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
	}
#line 1762 "cat.tab.c"
    break;

  case 17: /* statement: WHILE expression scope  */
#line 316 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope));
		((*yyvalp).symbol)->scope.kind = Scope::WHILE;
		((*yyvalp).symbol)->scope.condition = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
	}
#line 1777 "cat.tab.c"
    break;

  case 18: /* statement: DO WHILE expression scope  */
#line 328 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope));
		((*yyvalp).symbol)->scope.kind = Scope::DO_WHILE;
		((*yyvalp).symbol)->scope.condition = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
	}
#line 1792 "cat.tab.c"
    break;

  case 19: /* statement: DO scope WHILE expression semicolon  */
#line 340 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.scope));
		((*yyvalp).symbol)->scope.kind = Scope::DO_WHILE;
		((*yyvalp).symbol)->scope.condition = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
	}
#line 1807 "cat.tab.c"
    break;

  case 20: /* statement: FOR iterator scope  */
#line 352 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope));
		((*yyvalp).symbol)->scope.kind = Scope::FOR;
		((*yyvalp).symbol)->scope.condition = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.iterator)->condition;
		((*yyvalp).symbol)->scope.continue_action = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.iterator)->proceed;
		((*yyvalp).symbol)->scope.insert ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.iterator)->setup);
	}
#line 1824 "cat.tab.c"
    break;

  case 23: /* semicolon: %empty  */
#line 369 "../src/cat.y"
                           { ((*yyvalp).token) = & current.token; }
#line 1830 "cat.tab.c"
    break;

  case 25: /* colon: %empty  */
#line 373 "../src/cat.y"
                           { ((*yyvalp).token) = & current.token; }
#line 1836 "cat.tab.c"
    break;

  case 27: /* label: NAME members  */
#line 379 "../src/cat.y"
        {
		((*yyvalp).label) = new (Label);
		((*yyvalp).label)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		((*yyvalp).label)->names = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.members); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.members));
		((*yyvalp).label)->names.insert (((*yyvalp).label)->names.begin(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->text);
	}
#line 1847 "cat.tab.c"
    break;

  case 28: /* members: %empty  */
#line 388 "../src/cat.y"
               { ((*yyvalp).members) = new (std::vector<char*>); }
#line 1853 "cat.tab.c"
    break;

  case 29: /* members: members '.' NAME  */
#line 389 "../src/cat.y"
                         { ((*yyvalp).members) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.members); ((*yyvalp).members)->push_back ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)->text); }
#line 1859 "cat.tab.c"
    break;

  case 30: /* case-expression: expression range  */
#line 394 "../src/cat.y"
        {
		((*yyvalp).case_range) [0] = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
		((*yyvalp).case_range) [1] = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
	}
#line 1868 "cat.tab.c"
    break;

  case 31: /* range: %empty  */
#line 400 "../src/cat.y"
                           { ((*yyvalp).expression) = 0; }
#line 1874 "cat.tab.c"
    break;

  case 32: /* range: TAIL expression  */
#line 401 "../src/cat.y"
                        { ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression); }
#line 1880 "cat.tab.c"
    break;

  case 33: /* else-block: %empty  */
#line 404 "../src/cat.y"
               { ((*yyvalp).scope) = 0; }
#line 1886 "cat.tab.c"
    break;

  case 34: /* else-block: ELSE scope  */
#line 405 "../src/cat.y"
                   { ((*yyvalp).scope) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope); }
#line 1892 "cat.tab.c"
    break;

  case 35: /* iterator: '(' iterator ')'  */
#line 408 "../src/cat.y"
                         { ((*yyvalp).iterator) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.iterator); }
#line 1898 "cat.tab.c"
    break;

  case 36: /* iterator: line ';' expression ';' line  */
#line 410 "../src/cat.y"
        {
		((*yyvalp).iterator)->setup = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.symbol);
		((*yyvalp).iterator)->condition = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression);
		((*yyvalp).iterator)->proceed = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symbol);
	}
#line 1908 "cat.tab.c"
    break;

  case 37: /* line: braced-scope  */
#line 419 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope));
		((*yyvalp).symbol)->scope.kind = Scope::STACK;
	}
#line 1921 "cat.tab.c"
    break;

  case 40: /* line: expressions semicolon  */
#line 431 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		((*yyvalp).symbol)->kind = Symbol::EXPRESSION;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression)->location;
		
		memcpy (& ((*yyvalp).symbol)->expression, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression), sizeof (Expression));
		free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression));
	}
#line 1934 "cat.tab.c"
    break;

  case 41: /* line: ';'  */
#line 440 "../src/cat.y"
            { ((*yyvalp).symbol) = 0; }
#line 1940 "cat.tab.c"
    break;

  case 43: /* scope: colon block ELLIPSES  */
#line 445 "../src/cat.y"
                             { ((*yyvalp).scope) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.scope); ((*yyvalp).scope)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location; }
#line 1946 "cat.tab.c"
    break;

  case 44: /* scope: ';'  */
#line 446 "../src/cat.y"
                             { ((*yyvalp).scope) = new (Scope); ((*yyvalp).scope)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)->location; }
#line 1952 "cat.tab.c"
    break;

  case 45: /* braced-scope: '{' block '}'  */
#line 449 "../src/cat.y"
                      { ((*yyvalp).scope) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.scope); ((*yyvalp).scope)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location; }
#line 1958 "cat.tab.c"
    break;

  case 51: /* module: qualifiers struct-module-union label scope  */
#line 462 "../src/cat.y"
        {
		((*yyvalp).symbol) = new (Symbol);
		((*yyvalp).symbol)->kind = Symbol::SCOPE;
		((*yyvalp).symbol)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).symbol)->scope = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.scope));
		
		((*yyvalp).symbol)->scope.name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label)->names.back();
		((*yyvalp).symbol)->scope.kind = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.token)->integer;
		
		// TODO: find target scope using path label
	}
#line 1975 "cat.tab.c"
    break;

  case 53: /* struct-module-union: STRUCT  */
#line 479 "../src/cat.y"
               { ((*yyvalp).token)->integer = Scope::STRUCT; }
#line 1981 "cat.tab.c"
    break;

  case 54: /* struct-module-union: MODULE  */
#line 480 "../src/cat.y"
               { ((*yyvalp).token)->integer = Scope::MODULE; }
#line 1987 "cat.tab.c"
    break;

  case 55: /* struct-module-union: UNION  */
#line 481 "../src/cat.y"
              { ((*yyvalp).token)->integer = Scope::UNION; }
#line 1993 "cat.tab.c"
    break;

  case 112: /* expressions: expressions ',' expression  */
#line 593 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::COMMA;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		
		((*yyvalp).expression)->operands [0] = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression);
		((*yyvalp).expression)->operands [1] = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
	}
#line 2006 "cat.tab.c"
    break;

  case 113: /* list-expression: expression  */
#line 605 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::LIST;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression)->location;
		
		((*yyvalp).expression)->list.push_back ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression));
	}
#line 2018 "cat.tab.c"
    break;

  case 114: /* list-expression: list-expression ',' expression  */
#line 614 "../src/cat.y"
        {
		((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression);
		((*yyvalp).expression)->list.push_back ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression));
	}
#line 2027 "cat.tab.c"
    break;

  case 115: /* expression: '(' expressions ')'  */
#line 622 "../src/cat.y"
                            { ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression); }
#line 2033 "cat.tab.c"
    break;

  case 116: /* expression: '[' list-expression ']'  */
#line 623 "../src/cat.y"
                                { ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression); }
#line 2039 "cat.tab.c"
    break;

  case 118: /* expression: prefix_operator expression  */
#line 626 "../src/cat.y"
        {}
#line 2045 "cat.tab.c"
    break;

  case 119: /* expression: expression infix_operator expression  */
#line 629 "../src/cat.y"
        {}
#line 2051 "cat.tab.c"
    break;

  case 120: /* expression: expression postfix_operator  */
#line 632 "../src/cat.y"
        {}
#line 2057 "cat.tab.c"
    break;

  case 121: /* expression: label expression  */
#line 635 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::CALL;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label)->location;
		
		((*yyvalp).expression)->call.function.path = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.label));
		((*yyvalp).expression)->call.arguments = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
	}
#line 2070 "cat.tab.c"
    break;

  case 122: /* value: label  */
#line 647 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::VALUEOF;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.label)->location;
		((*yyvalp).expression)->variable.path = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.label); free ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.label));
	}
#line 2081 "cat.tab.c"
    break;

  case 123: /* value: const-value  */
#line 655 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::LITERAL;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)->location;
		((*yyvalp).expression)->constant = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.token)->text;
	}
#line 2092 "cat.tab.c"
    break;

  case 129: /* meta-value: SIZEOF expression  */
#line 674 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::META;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		((*yyvalp).expression)->meta.kind = ((*yyvalp).expression)->meta.SIZEOF;
		((*yyvalp).expression)->meta.value = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
	}
#line 2104 "cat.tab.c"
    break;

  case 130: /* meta-value: COUNTOF expression  */
#line 683 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::META;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		((*yyvalp).expression)->meta.kind = ((*yyvalp).expression)->meta.COUNTOF;
		((*yyvalp).expression)->meta.value = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
	}
#line 2116 "cat.tab.c"
    break;

  case 131: /* meta-value: NAMEOF expression  */
#line 692 "../src/cat.y"
        {
		((*yyvalp).expression) = new (Expression);
		((*yyvalp).expression)->opcode = Expression::META;
		((*yyvalp).expression)->location = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.token)->location;
		((*yyvalp).expression)->meta.kind = ((*yyvalp).expression)->meta.NAMEOF;
		((*yyvalp).expression)->meta.value = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
	}
#line 2128 "cat.tab.c"
    break;


#line 2132 "cat.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval);
  else
    {
#if CATDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = CATEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if CATDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if CATDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if CATDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}






static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  yyerror (YY_("syntax error"));
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == CATEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != CATEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = CATEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = CATEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = CATEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != CATerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != CATEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to CATEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = CATEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != CATEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if CATDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs

/* Substitute the variable and function names.  */
#define yyparse catparse
#define yylex   catlex
#define yyerror caterror
#define yylval  catlval
#define yychar  catchar
#define yydebug catdebug
#define yynerrs catnerrs


#line 730 "../src/cat.y"


/* Epilogue */

void caterror (const char* message)
{
	fprintf (stderr, "Parse error: %s\n", message);
}
