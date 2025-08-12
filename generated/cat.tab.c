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






/* First part of user prologue.  */
#line 1 "../cat.y"


/* Prologue */

#define YYDEBUG 1

#include "lex.yy.h"

void yyerror (const char*);

/* handle end of file */
int yywrap ();


#line 73 "cat.tab.c"

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
  YYSYMBOL_UNUSED = 3,                     /* UNUSED  */
  YYSYMBOL_4_ = 4,                         /* '('  */
  YYSYMBOL_5_ = 5,                         /* ')'  */
  YYSYMBOL_6_ = 6,                         /* '['  */
  YYSYMBOL_7_ = 7,                         /* ']'  */
  YYSYMBOL_8_ = 8,                         /* '{'  */
  YYSYMBOL_9_ = 9,                         /* '}'  */
  YYSYMBOL_10_ = 10,                       /* '!'  */
  YYSYMBOL_11_ = 11,                       /* '#'  */
  YYSYMBOL_12_ = 12,                       /* '$'  */
  YYSYMBOL_13_ = 13,                       /* '%'  */
  YYSYMBOL_14_ = 14,                       /* '&'  */
  YYSYMBOL_15_ = 15,                       /* '*'  */
  YYSYMBOL_16_ = 16,                       /* '+'  */
  YYSYMBOL_17_ = 17,                       /* ','  */
  YYSYMBOL_18_ = 18,                       /* '-'  */
  YYSYMBOL_19_ = 19,                       /* '.'  */
  YYSYMBOL_20_ = 20,                       /* '/'  */
  YYSYMBOL_21_ = 21,                       /* ':'  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_24_ = 24,                       /* '>'  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_26_ = 26,                       /* '?'  */
  YYSYMBOL_27_ = 27,                       /* '@'  */
  YYSYMBOL_28_ = 28,                       /* '^'  */
  YYSYMBOL_29___ = 29,                     /* '_'  */
  YYSYMBOL_30_ = 30,                       /* '|'  */
  YYSYMBOL_31_ = 31,                       /* '~'  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_INCREMENT = 34,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 35,                 /* DECREMENT  */
  YYSYMBOL_SHIFT_L = 36,                   /* SHIFT_L  */
  YYSYMBOL_SHIFT_R = 37,                   /* SHIFT_R  */
  YYSYMBOL_ROTATE_L = 38,                  /* ROTATE_L  */
  YYSYMBOL_ROTATE_R = 39,                  /* ROTATE_R  */
  YYSYMBOL_COMPARE = 40,                   /* COMPARE  */
  YYSYMBOL_INEQUAL = 41,                   /* INEQUAL  */
  YYSYMBOL_AT_MOST = 42,                   /* AT_MOST  */
  YYSYMBOL_AT_LEAST = 43,                  /* AT_LEAST  */
  YYSYMBOL_TAIL = 44,                      /* TAIL  */
  YYSYMBOL_ELLIPSES = 45,                  /* ELLIPSES  */
  YYSYMBOL_CONST_INT = 46,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 47,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_STRING = 48,              /* CONST_STRING  */
  YYSYMBOL_CONST_CHAR = 49,                /* CONST_CHAR  */
  YYSYMBOL_COMMENT_LINE = 50,              /* COMMENT_LINE  */
  YYSYMBOL_COMMENT_BLOCK = 51,             /* COMMENT_BLOCK  */
  YYSYMBOL_NAME = 52,                      /* NAME  */
  YYSYMBOL_BIT = 53,                       /* BIT  */
  YYSYMBOL_CHAR = 54,                      /* CHAR  */
  YYSYMBOL_BYTE = 55,                      /* BYTE  */
  YYSYMBOL_SHORT = 56,                     /* SHORT  */
  YYSYMBOL_INT = 57,                       /* INT  */
  YYSYMBOL_FLOAT = 58,                     /* FLOAT  */
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
  YYSYMBOL_END_FILE = 91,                  /* END_FILE  */
  YYSYMBOL_PREFIX = 92,                    /* PREFIX  */
  YYSYMBOL_GROUP = 93,                     /* GROUP  */
  YYSYMBOL_LIST = 94,                      /* LIST  */
  YYSYMBOL_INCREMENT_PRE = 95,             /* INCREMENT_PRE  */
  YYSYMBOL_DECREMENT_PRE = 96,             /* DECREMENT_PRE  */
  YYSYMBOL_POSITIVE = 97,                  /* POSITIVE  */
  YYSYMBOL_NEGATIVE = 98,                  /* NEGATIVE  */
  YYSYMBOL_COMPLEMENT = 99,                /* COMPLEMENT  */
  YYSYMBOL_DEREFERENCE = 100,              /* DEREFERENCE  */
  YYSYMBOL_ADDRESS = 101,                  /* ADDRESS  */
  YYSYMBOL_META = 102,                     /* META  */
  YYSYMBOL_POSTFIX = 103,                  /* POSTFIX  */
  YYSYMBOL_INCREMENT_POST = 104,           /* INCREMENT_POST  */
  YYSYMBOL_DECREMENT_POST = 105,           /* DECREMENT_POST  */
  YYSYMBOL_YYACCEPT = 106,                 /* $accept  */
  YYSYMBOL_optional_semicolon = 107,       /* optional_semicolon  */
  YYSYMBOL_optional_colon = 108,           /* optional_colon  */
  YYSYMBOL_unit = 109,                     /* unit  */
  YYSYMBOL_statements = 110,               /* statements  */
  YYSYMBOL_statement = 111,                /* statement  */
  YYSYMBOL_scope = 112,                    /* scope  */
  YYSYMBOL_braced_scope = 113,             /* braced_scope  */
  YYSYMBOL_implicit_scope = 114,           /* implicit_scope  */
  YYSYMBOL_enum_scope = 115,               /* enum_scope  */
  YYSYMBOL_include = 116,                  /* include  */
  YYSYMBOL_declaration = 117,              /* declaration  */
  YYSYMBOL_qualified_declaration = 118,    /* qualified_declaration  */
  YYSYMBOL_structure_declaration = 119,    /* structure_declaration  */
  YYSYMBOL_enum_declaration = 120,         /* enum_declaration  */
  YYSYMBOL_control = 121,                  /* control  */
  YYSYMBOL_switch = 122,                   /* switch  */
  YYSYMBOL_if_else = 123,                  /* if_else  */
  YYSYMBOL_do_while = 124,                 /* do_while  */
  YYSYMBOL_for = 125,                      /* for  */
  YYSYMBOL_jump = 126,                     /* jump  */
  YYSYMBOL_loop = 127,                     /* loop  */
  YYSYMBOL_goto = 128,                     /* goto  */
  YYSYMBOL_return = 129,                   /* return  */
  YYSYMBOL_case = 130,                     /* case  */
  YYSYMBOL_named_marker = 131,             /* named_marker  */
  YYSYMBOL_marker = 132,                   /* marker  */
  YYSYMBOL_qualifiers = 133,               /* qualifiers  */
  YYSYMBOL_qualifier = 134,                /* qualifier  */
  YYSYMBOL_math_qualifier = 135,           /* math_qualifier  */
  YYSYMBOL_builtin_type = 136,             /* builtin_type  */
  YYSYMBOL_short = 137,                    /* short  */
  YYSYMBOL_type_qualifiers = 138,          /* type_qualifiers  */
  YYSYMBOL_type_qualifier = 139,           /* type_qualifier  */
  YYSYMBOL_type = 140,                     /* type  */
  YYSYMBOL_underlying_type = 141,          /* underlying_type  */
  YYSYMBOL_indirection = 142,              /* indirection  */
  YYSYMBOL_cat_ptrs = 143,                 /* cat_ptrs  */
  YYSYMBOL_cat_ptr = 144,                  /* cat_ptr  */
  YYSYMBOL_c_ptrs = 145,                   /* c_ptrs  */
  YYSYMBOL_c_ptr = 146,                    /* c_ptr  */
  YYSYMBOL_datatype = 147,                 /* datatype  */
  YYSYMBOL_label = 148,                    /* label  */
  YYSYMBOL_name = 149,                     /* name  */
  YYSYMBOL_instances = 150,                /* instances  */
  YYSYMBOL_instance = 151,                 /* instance  */
  YYSYMBOL_counted_instance = 152,         /* counted_instance  */
  YYSYMBOL_object_declaration = 153,       /* object_declaration  */
  YYSYMBOL_variable_declarations = 154,    /* variable_declarations  */
  YYSYMBOL_variable_declaration = 155,     /* variable_declaration  */
  YYSYMBOL_function_declaration = 156,     /* function_declaration  */
  YYSYMBOL_tuple = 157,                    /* tuple  */
  YYSYMBOL_expression = 158,               /* expression  */
  YYSYMBOL_single_expression = 159,        /* single_expression  */
  YYSYMBOL_const_value = 160,              /* const_value  */
  YYSYMBOL_object_value = 161,             /* object_value  */
  YYSYMBOL_operation = 162,                /* operation  */
  YYSYMBOL_prefix_operation = 163,         /* prefix_operation  */
  YYSYMBOL_prefix_operator = 164,          /* prefix_operator  */
  YYSYMBOL_postfix_operation = 165,        /* postfix_operation  */
  YYSYMBOL_postfix_operator = 166,         /* postfix_operator  */
  YYSYMBOL_infix_operation = 167,          /* infix_operation  */
  YYSYMBOL_infix_operator = 168,           /* infix_operator  */
  YYSYMBOL_infix_assignable_operator = 169, /* infix_assignable_operator  */
  YYSYMBOL_assign_operator = 170           /* assign_operator  */
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
#define YYFINAL  130
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 6
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332

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
       2,     2,     2,    10,     2,    11,    12,    13,    14,     2,
       4,     5,    15,    16,    17,    18,    19,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    21,    22,
      23,    25,    24,    26,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     6,     2,     7,    28,    29,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     8,    30,     9,    31,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,    99,   102,   103,   107,   108,   112,   113,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   129,
     130,   134,   138,   142,   143,   147,   151,   152,   153,   154,
     155,   159,   163,   164,   165,   166,   170,   171,   175,   176,
     177,   178,   182,   186,   187,   188,   192,   193,   197,   200,
     201,   202,   206,   207,   211,   215,   216,   220,   225,   229,
     230,   234,   235,   239,   240,   241,   242,   246,   247,   248,
     249,   250,   251,   255,   256,   257,   258,   259,   260,   264,
     265,   269,   270,   274,   275,   279,   280,   284,   285,   289,
     290,   291,   295,   296,   300,   301,   305,   306,   310,   311,
     315,   316,   320,   321,   325,   326,   330,   331,   335,   336,
     337,   338,   342,   343,   347,   348,   352,   353,   357,   361,
     362,   366,   367,   371,   372,   376,   377,   378,   379,   380,
     384,   385,   386,   387,   391,   395,   396,   397,   401,   402,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   422,   426,   427,   428,   429,   433,   438,
     439,   439,   440,   440,   440,   440,   441,   441,   445,   445,
     445,   446,   446,   447,   447,   448,   448,   449,   449,   449,
     453,   454
};
#endif

#define YYPACT_NINF (-183)
#define YYTABLE_NINF (-150)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     918,  1076,  1126,   918,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  1148,  -183,  -183,  -183,  -183,  -183,  -183,    32,  -183,
    -183,  -183,   -28,  -183,  -183,   -14,  -183,  -183,  -183,  -183,
     -14,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,    36,    61,  1054,    38,    -8,    -8,    -8,    -8,  1198,
      33,   918,  1198,  1198,  1198,    97,   918,  -183,  -183,  -183,
    -183,  -183,  -183,   400,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,   487,  -183,  -183,  2209,  -183,  -183,  -183,
    -183,  1455,  -183,    -8,    15,  -183,    80,    74,  -183,    83,
     574,  1897,  -183,  -183,  -183,  -183,  -183,  1198,  -183,  -183,
    -183,    87,  1657,  1697,   746,  1937,  -183,    17,    87,  -183,
    -183,  -183,  -183,  1737,    85,    49,    87,    54,    70,    71,
    1537,  -183,   918,    27,  -183,  -183,  1198,  1577,  1617,  1777,
    -183,  -183,  -183,  -183,  2240,  -183,    15,   313,    92,  -183,
      89,    45,    48,  -183,    86,  -183,   101,  -183,  -183,    67,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  1198,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  1198,  -183,  1977,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,    -8,
    2271,    -8,  -183,  -183,   832,  1198,   660,    34,  -183,    30,
    -183,   108,  1198,  1198,    51,    -8,  1198,  -183,  -183,  -183,
    -183,  -183,  2017,  2057,  1004,   226,    23,    73,   -12,  -183,
    2097,  1220,  1270,  1292,  1342,  1364,  1414,  1436,  1486,    77,
      -6,   102,  -183,    -8,    26,  -183,  1817,  2137,  -183,  -183,
    -183,  2177,  1857,  -183,  -183,  -183,  -183,    78,  -183,  -183,
    -183,  1455,  -183,  -183,   104,  1198,  -183,  -183,  -183,  2217
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     0,   146,   149,   148,   144,   145,    18,
     103,     0,   142,   143,   130,   131,   133,   132,   105,    73,
      74,    75,    79,    77,    78,     0,    66,   150,   151,   152,
       0,    63,    64,    83,    65,    67,    68,    69,    70,    71,
      72,     3,     3,     3,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     6,     9,    12,    11,
      10,    26,    29,    30,    14,    38,    39,    40,    41,    15,
      49,    50,    51,    16,    59,    17,     0,    62,    84,   100,
      76,     0,    82,     0,    91,    87,     0,   134,    27,     3,
      28,    13,   124,   126,   125,   127,   135,     0,   137,   136,
     105,   134,     0,     0,     0,   139,    80,     3,    88,     2,
      53,    52,    56,     3,     3,     5,   102,     5,     5,     5,
       5,     4,     0,     0,    19,    20,     0,     5,     5,     5,
       1,     8,   101,    31,    61,    81,    91,   108,   118,   107,
     110,    99,    95,    86,    89,    93,    90,    97,    58,     0,
     114,   156,   157,   170,   177,   168,   171,     0,   172,   169,
     162,   164,   178,   179,   160,   161,   154,   155,   173,   174,
     175,   176,   166,   167,   163,   165,   153,     0,   159,   138,
     128,   129,    21,    25,    55,    54,    32,    33,    34,     0,
       4,     0,    36,    46,     0,     0,     0,    43,    42,     0,
      85,     0,     0,     0,     5,     0,     0,    98,    94,    92,
      96,   104,     0,   123,     0,   108,     0,     5,     0,    22,
      47,   156,   157,   149,   148,   144,   145,   154,   155,     5,
       5,     5,   122,     0,     0,   117,     0,   109,   119,   120,
     106,   111,     0,    23,    37,    24,    48,     5,    44,    57,
     121,     0,   113,   180,   159,     0,    45,   116,   181,   158
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,   -25,  -113,  -183,     6,   -48,   -93,     4,  -183,   -95,
    -183,    55,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,    56,  -183,
    -183,  -183,  -183,    46,  -164,    52,    -2,  -183,    -9,  -183,
     -16,  -183,   -34,    20,   -89,   -67,  -183,  -183,  -183,  -182,
    -183,  -183,    -1,  -129,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -103,  -183
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   110,   122,    55,    56,    57,   123,   124,   125,   192,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   143,   144,   145,   146,
     147,    85,    86,   101,   138,   139,   140,    88,   234,    89,
      90,   204,    91,    92,    93,    94,    95,    96,    97,    98,
     176,    99,   177,   178,   255
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     102,   103,     3,   126,    58,   205,   191,    58,   131,   104,
     105,   115,   117,   118,   119,   121,   199,   111,   112,   235,
      87,    10,   186,    87,   187,   188,   217,   193,   213,   106,
     141,   250,   243,   245,   197,   198,   149,   233,   100,   109,
     205,     3,   113,   251,   100,   107,   142,  -101,   120,   137,
     108,   127,   128,   129,   121,    58,   131,     3,   109,     3,
      58,  -101,     3,  -101,   150,   116,   116,   116,   116,   257,
     121,    87,   121,   238,   237,   121,    87,   241,     3,   189,
     247,   189,   183,   109,  -101,     3,     3,   233,   184,   185,
     114,   121,   190,   149,   121,  -102,   179,   130,   121,   121,
     216,   148,   218,   116,   191,   109,   149,   109,    58,   205,
     195,   239,   207,   232,   206,   208,   141,   142,   249,   211,
     231,   230,   244,   121,    87,   196,    58,   135,   194,   258,
     210,   133,   134,   136,   200,   209,   246,   248,   240,   254,
       0,     0,    87,     0,     0,     0,   131,     0,   229,     0,
       0,     0,     0,     0,   256,   215,   212,   215,     0,     0,
     132,    19,    20,    21,    22,    23,    24,     0,     0,     0,
       0,   215,    30,     0,     0,    33,   214,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,    58,   215,
      58,   236,   212,     0,     0,   212,     0,     0,     0,   116,
       0,   116,     0,   242,    87,     0,    87,     0,     0,     0,
     102,   103,     0,     0,     0,   116,  -108,     0,     0,     0,
    -108,  -108,   202,     0,  -108,  -108,  -108,     0,     0,     0,
    -108,  -108,  -108,  -108,  -108,     0,     0,  -108,  -108,     0,
       0,   203,     0,   116,   259,  -108,     0,  -108,     0,     0,
    -108,  -108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -108,  -108,  -108,  -108,  -108,     0,     0,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,     0,   201,     0,   202,
       0,  -108,  -108,  -108,     0,     0,     0,  -108,  -108,  -108,
    -108,  -108,     0,     0,  -108,  -108,     0,     0,   203,     0,
       0,     0,  -108,     0,  -108,     0,     0,  -108,  -108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -108,  -108,
    -108,  -108,  -108,     0,     0,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
     -30,  -108,  -108,     0,   -30,     0,   -30,     0,   -30,   -30,
     -30,     0,     0,     0,   -30,   -30,   -30,     0,   -30,     0,
       0,   -30,   -30,     0,     0,     0,     0,     0,     0,   -30,
       0,   -30,     0,     0,   -30,   -30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -30,   -30,   -30,   -30,   -30,
       0,     0,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -16,   -30,   -30,
       0,   -16,     0,   -16,     0,   -16,   -16,   -16,     0,     0,
       0,   -16,   -16,   -16,     0,   -16,     0,     0,   -16,   -16,
       0,     0,     0,     0,     0,     0,   -16,     0,   -16,     0,
       0,   -16,   -16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -16,   -16,   -16,   -16,   -16,     0,     0,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -28,   -16,   -16,     0,   -28,     0,
     -28,     0,   -28,   -28,   -28,     0,     0,     0,   -28,   -28,
     -28,     0,   -28,     0,     0,   -28,   -28,     0,     0,     0,
       0,     0,     0,   -28,     0,   -28,     0,     0,   -28,   -28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -28,
     -28,   -28,   -28,   -28,     0,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,     0,   -28,   -28,   221,     0,   222,     0,     3,     0,
       4,     0,     0,   153,   223,   224,   225,   157,   226,     0,
     159,     0,     9,   160,   161,     0,     0,     0,   162,    10,
     163,    11,   164,   165,   227,   228,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     0,    14,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,    53,    54,
       1,     0,     2,     0,     3,   182,     4,     0,     0,     0,
       5,     6,     7,     0,     8,     0,     0,     0,     9,     0,
       0,     0,     0,     0,     0,    10,     0,    11,     0,     0,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,    53,    54,     1,     0,     2,     0,
       3,     0,     4,     0,     0,     0,     5,     6,     7,     0,
       8,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,    10,     0,    11,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,    14,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
      53,    54,     1,     0,     2,     0,     3,     0,     4,     0,
       0,     0,     5,     6,     7,     0,     8,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,    10,     0,    11,
       0,     0,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,    53,    54,   221,     0,
     222,     0,     0,     0,     4,     0,     0,   153,   223,   224,
     225,   157,   226,     0,   159,     0,     0,   160,   161,     0,
       0,     0,   162,     0,   163,    11,   164,   165,   227,   228,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     0,
      14,    15,    16,    17,     0,     0,   100,     0,     1,     0,
       2,     0,     0,     0,     4,    27,    28,    29,     5,     6,
       7,     0,     8,     0,     0,     0,   109,     0,     0,     0,
       1,     0,     2,     0,     0,    11,     4,     0,    12,    13,
       5,     6,     7,     0,     8,     0,     0,     0,     0,     0,
      14,    15,    16,    17,     0,     0,   100,    11,     0,     0,
      12,    13,     0,     0,     0,    27,    28,    29,     0,     0,
       0,     0,    14,    15,    16,    17,     0,     0,   100,     0,
       1,     0,     2,     0,     0,     0,     4,    27,    28,    29,
       5,     6,     7,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     0,     0,    11,     4,     0,
      12,    13,     5,     6,     7,     0,     8,     0,     0,     0,
       0,     0,    14,    15,    16,    17,     0,     0,   100,    11,
       0,     0,    12,    13,     0,     0,     0,    27,    28,    29,
       0,     0,     0,     0,    14,    15,    16,    17,     0,     0,
     100,     0,     1,     0,     2,     0,     0,     0,     4,    27,
      28,    29,     5,     6,     7,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,     0,     0,    11,
       4,     0,    12,    13,     5,     6,     7,     0,     8,     0,
       0,     0,     0,     0,    14,    15,    16,    17,     0,     0,
     100,    11,     0,     0,    12,    13,     0,     0,     0,    27,
      28,    29,     0,     0,     0,     0,    14,    15,    16,    17,
       0,     0,   100,     0,     1,     0,     2,     0,     0,     0,
       4,    27,    28,    29,     5,     6,     7,     0,     8,     0,
       0,     0,     0,     0,     0,     0,  -149,     0,  -149,     0,
       0,    11,  -149,     0,    12,    13,  -149,  -149,  -149,     0,
    -149,     0,     0,     0,     0,     0,    14,    15,    16,    17,
       0,     0,   100,  -149,     0,     0,  -149,  -149,     0,     0,
       0,    27,    28,    29,     0,     0,     0,     0,  -149,  -149,
    -149,  -149,     0,     0,  -149,     0,  -148,     0,  -148,     0,
       0,     0,  -148,  -149,  -149,  -149,  -148,  -148,  -148,     0,
    -148,     0,     0,     0,     0,     0,     0,     0,  -144,     0,
    -144,     0,     0,  -148,  -144,     0,  -148,  -148,  -144,  -144,
    -144,     0,  -144,     0,     0,     0,     0,     0,  -148,  -148,
    -148,  -148,     0,     0,  -148,  -144,     0,     0,  -144,  -144,
       0,     0,     0,  -148,  -148,  -148,     0,     0,     0,     0,
    -144,  -144,  -144,  -144,     0,     0,  -144,     0,  -145,     0,
    -145,     0,     0,     0,  -145,  -144,  -144,  -144,  -145,  -145,
    -145,     0,  -145,     0,     0,     0,     0,     0,     0,     0,
    -142,     0,  -142,     0,     0,  -145,  -142,     0,  -145,  -145,
    -142,  -142,  -142,     0,  -142,     0,     0,     0,     0,     0,
    -145,  -145,  -145,  -145,     0,     0,  -145,  -142,     0,     0,
    -142,  -142,     0,     0,     0,  -145,  -145,  -145,     0,     0,
       0,     0,  -142,  -142,  -142,  -142,     0,     0,  -142,     0,
    -143,     0,  -143,     0,     0,     0,  -143,  -142,  -142,  -142,
    -143,  -143,  -143,     0,  -143,     0,     0,   132,    19,    20,
      21,    22,    23,    24,     0,     0,     0,  -143,     0,    30,
    -143,  -143,    33,     0,    35,    36,    37,    38,    39,    40,
       0,     0,  -143,  -143,  -143,  -143,     0,     0,  -143,     0,
       0,   151,     0,   152,     0,     3,     0,  -143,  -143,  -143,
     153,   154,   155,   156,   157,   158,     0,   159,   121,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     3,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,   121,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     3,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,   121,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,   180,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,   181,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,   109,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,   121,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,   252,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,   253,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,  -123,     0,  -123,     0,     0,     0,     0,     0,     0,
    -123,  -123,  -123,  -123,  -123,  -123,     0,  -123,     0,     0,
    -123,  -123,     0,     0,     0,  -123,     0,  -123,     0,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,  -109,     0,  -109,     0,     0,     0,     0,     0,     0,
    -124,  -109,  -109,  -109,  -109,  -109,     0,  -124,     0,     0,
    -124,  -124,     0,     0,     0,  -124,     0,  -124,     0,  -124,
    -124,  -109,  -109,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -111,     0,  -111,     0,     0,     0,     0,     0,     0,
    -124,  -111,  -111,  -111,  -111,  -111,     0,  -124,     0,     0,
    -124,  -124,     0,     0,     0,  -124,     0,  -124,     0,  -124,
    -124,  -111,  -111,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,   151,     0,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,     0,   159,     0,     0,
     160,   161,     0,     0,     0,   162,     0,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   132,    19,    20,    21,    22,    23,    24,     0,    26,
       0,     0,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,     0,    45,    46,
      47,    48,   -61,   -61,   -61,   -61,   -61,   -61,   -61,     0,
     -61,     0,     0,     0,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,     0,     0,     0,     0,   -61,
     -61,   -61,   -61,   132,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,     0,    30,     0,     0,    33,     0,
      35,    36,    37,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
       1,     2,     8,    51,     0,    17,   119,     3,    56,     3,
      11,    45,    46,    47,    48,    21,   129,    42,    43,   201,
       0,    29,   115,     3,   117,   118,   190,   120,   157,    57,
      15,     5,     9,    45,   127,   128,    19,   201,    52,    22,
      17,     8,    43,    17,    52,    25,    31,    15,    49,    83,
      30,    52,    53,    54,    21,    51,   104,     8,    22,     8,
      56,    29,     8,    31,    89,    45,    46,    47,    48,   251,
      21,    51,    21,    22,   203,    21,    56,   206,     8,     8,
      86,     8,   107,    22,    52,     8,     8,   251,   113,   114,
      52,    21,    21,    19,    21,    21,    97,     0,    21,    21,
     189,    21,   191,    83,   217,    22,    19,    22,   104,    17,
      83,   204,    67,     5,    25,    67,    15,    31,   231,    52,
      90,    87,   217,    21,   104,   126,   122,    81,   122,    25,
     146,    76,    76,    81,   136,   144,   229,   230,   205,   242,
      -1,    -1,   122,    -1,    -1,    -1,   194,    -1,   196,    -1,
      -1,    -1,    -1,    -1,   247,   189,   157,   191,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,   205,    64,    -1,    -1,    67,   177,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   194,   233,
     196,   202,   203,    -1,    -1,   206,    -1,    -1,    -1,   189,
      -1,   191,    -1,   214,   194,    -1,   196,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,   205,     0,    -1,    -1,    -1,
       4,     5,     6,    -1,     8,     9,    10,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    -1,   233,   255,    29,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,    88,    89,    -1,     4,    -1,     6,
      -1,     8,     9,    10,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,    88,    89,    -1,     4,    -1,     6,    -1,     8,     9,
      10,    -1,    -1,    -1,    14,    15,    16,    -1,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,    88,    89,
      -1,     4,    -1,     6,    -1,     8,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,    88,    89,    -1,     4,    -1,
       6,    -1,     8,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    -1,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,     4,    -1,     6,    -1,     8,    -1,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    -1,
      20,    -1,    22,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    89,
       4,    -1,     6,    -1,     8,     9,    10,    -1,    -1,    -1,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,     4,    -1,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,     4,    -1,
       6,    -1,    -1,    -1,    10,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    20,    -1,    -1,    23,    24,    -1,
      -1,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    52,    -1,     4,    -1,
       6,    -1,    -1,    -1,    10,    61,    62,    63,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
       4,    -1,     6,    -1,    -1,    31,    10,    -1,    34,    35,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    52,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,    -1,
       4,    -1,     6,    -1,    -1,    -1,    10,    61,    62,    63,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,     6,    -1,    -1,    31,    10,    -1,
      34,    35,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      52,    -1,     4,    -1,     6,    -1,    -1,    -1,    10,    61,
      62,    63,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,     6,    -1,    -1,    31,
      10,    -1,    34,    35,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,
      52,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    52,    -1,     4,    -1,     6,    -1,    -1,    -1,
      10,    61,    62,    63,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,    -1,
      -1,    31,    10,    -1,    34,    35,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    52,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    52,    -1,     4,    -1,     6,    -1,
      -1,    -1,    10,    61,    62,    63,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
       6,    -1,    -1,    31,    10,    -1,    34,    35,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    52,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    52,    -1,     4,    -1,
       6,    -1,    -1,    -1,    10,    61,    62,    63,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,    -1,     6,    -1,    -1,    31,    10,    -1,    34,    35,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,    52,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,    -1,
       4,    -1,     6,    -1,    -1,    -1,    10,    61,    62,    63,
      14,    15,    16,    -1,    18,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    31,    -1,    64,
      34,    35,    67,    -1,    69,    70,    71,    72,    73,    74,
      -1,    -1,    46,    47,    48,    49,    -1,    -1,    52,    -1,
      -1,     4,    -1,     6,    -1,     8,    -1,    61,    62,    63,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,     8,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,     8,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    79,    80,
      81,    82,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    79,
      80,    81,    82,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    67,    -1,
      69,    70,    71,    72,    73,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,     8,    10,    14,    15,    16,    18,    22,
      29,    31,    34,    35,    46,    47,    48,    49,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    88,    89,   109,   110,   111,   113,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   147,   148,   149,   153,   155,
     156,   158,   159,   160,   161,   162,   163,   164,   165,   167,
      52,   149,   158,   158,   110,   158,    57,   149,   149,    22,
     107,   107,   107,   158,    52,   148,   149,   148,   148,   148,
     158,    21,   108,   112,   113,   114,   111,   158,   158,   158,
       0,   111,    52,   117,   134,   139,   141,   148,   150,   151,
     152,    15,    31,   142,   143,   144,   145,   146,    21,    19,
     107,     4,     6,    13,    14,    15,    16,    17,    18,    20,
      23,    24,    28,    30,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   166,   168,   169,   158,
       5,     7,     9,   107,   107,   107,   112,   112,   112,     8,
      21,   108,   115,   112,   110,    83,   158,   112,   112,   108,
     142,     4,     6,    25,   157,    17,    25,    67,    67,   144,
     146,    52,   158,   159,   158,   148,   150,   140,   150,    45,
     158,     4,     6,    14,    15,    16,    18,    34,    35,   111,
      87,    90,     5,   140,   154,   155,   158,   159,    22,   112,
     151,   159,   158,     9,   115,    45,   112,    86,   112,   108,
       5,    17,     7,    25,   169,   170,   112,   155,    25,   158
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   113,   114,   115,   115,   116,   117,   117,   117,   117,
     117,   118,   119,   119,   119,   119,   120,   120,   121,   121,
     121,   121,   122,   123,   123,   123,   124,   124,   125,   126,
     126,   126,   127,   127,   128,   129,   129,   130,   131,   132,
     132,   133,   133,   134,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   136,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   148,   148,   149,   149,   150,   150,   151,   151,
     151,   151,   152,   152,   153,   153,   154,   154,   155,   156,
     156,   157,   157,   158,   158,   159,   159,   159,   159,   159,
     160,   160,   160,   160,   161,   162,   162,   162,   163,   163,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   165,   166,   166,   166,   166,   167,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     170,   170
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     0,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     1,     3,     5,     1,     1,
       1,     1,     3,     3,     5,     6,     3,     4,     5,     1,
       1,     1,     2,     2,     3,     3,     2,     5,     2,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     3,     2,     1,     2,     1,
       1,     0,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     3,
       1,     3,     1,     4,     2,     1,     3,     1,     2,     4,
       4,     3,     2,     3,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int16 yyconflp[] =
{
       0,     0,  1342,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   549,
       0,   129,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   571,    87,   853,
       0,    81,   573,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   855,     0,     0,     0,     0,   575,     0,
    1344,     0,     0,    89,    85,  1340,  1384,     0,     0,     0,
       0,     0,     0,     0,     0,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     0,   569,     0,   799,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1346,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   907,     0,     0,     0,
     909,   911,   913,     0,   916,   918,   920,     0,     0,     0,
     922,   924,   926,   928,   930,     0,     0,   932,   934,     0,
       0,   936,     0,     0,     0,   938,     0,   940,     0,     0,
     942,   944,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   946,   948,   950,   952,   954,     0,     0,   956,   958,
     960,   962,   964,   966,   968,   970,   972,   974,   976,   978,
     980,   982,   984,   986,   988,   990,   992,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1018,
    1020,  1022,  1024,   677,  1026,  1028,     0,   679,     0,   682,
       0,   685,   687,   689,     0,     0,     0,   691,   693,   695,
     697,   699,     0,     0,   701,   703,     0,     0,   705,     0,
       0,     0,   707,     0,   709,     0,     0,   711,   713,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   715,   717,
     719,   721,   723,     0,     0,   725,   727,   729,   731,   733,
     735,   737,   739,   741,   743,   745,   747,   749,   751,   753,
     755,   757,   759,   761,   763,   765,   767,   769,   771,   773,
     775,   777,   779,   781,   783,   785,   787,   789,   791,   793,
     131,   795,   797,     0,   133,     0,   135,     0,   137,   139,
     141,     0,     0,     0,   143,   145,   147,     0,   149,     0,
       0,   151,   153,     0,     0,     0,     0,     0,     0,   155,
       0,   157,     0,     0,   159,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   165,   167,   169,   171,
       0,     0,   173,   175,   177,   179,   181,   183,   185,   187,
     189,   191,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   223,   225,   227,
     229,   231,   233,   235,   237,   239,   241,   247,   243,   245,
       0,   249,     0,   251,     0,   253,   255,   257,     0,     0,
       0,   259,   261,   263,     0,   265,     0,     0,   267,   269,
       0,     0,     0,     0,     0,     0,   271,     0,   273,     0,
       0,   275,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,   281,   283,   285,   287,     0,     0,   289,
     291,   293,   295,   297,   299,   301,   303,   305,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   353,   355,   357,   367,   359,   361,     0,   369,     0,
     371,     0,   373,   375,   377,     0,     0,     0,   379,   381,
     383,     0,   385,     0,     0,   387,   389,     0,     0,     0,
       0,     0,     0,   391,     0,   393,     0,     0,   395,   397,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   399,
     401,   403,   405,   407,     0,     0,   409,   411,   413,   415,
     417,   419,   421,   423,   425,   427,   429,   431,   433,   435,
     437,   439,   441,   443,   445,   447,   449,   451,   453,   455,
     457,   459,   461,   463,   465,   467,   469,   471,   473,   475,
     477,     0,   479,   481,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
      93,     0,     0,     0,    95,     0,     0,     0,    97,    99,
     101,     0,   103,     0,     0,     0,   105,     0,     0,     0,
       1,     0,     3,     0,     0,   107,     0,     0,   109,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,   115,   117,   119,     0,     0,   121,     5,     0,     0,
       7,     9,     0,     0,     0,   123,   125,   127,     0,     0,
       0,     0,    11,    13,    15,    17,     0,     0,    19,     0,
      27,     0,    29,     0,     0,     0,     0,    21,    23,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,    55,     0,     0,    31,     0,     0,
      33,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    39,    41,    43,     0,     0,    45,    57,
       0,     0,    59,    61,     0,     0,     0,    47,    49,    51,
       0,     0,     0,     0,    63,    65,    67,    69,     0,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      75,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1046,     0,  1049,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1052,     0,     0,  1055,  1058,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1061,  1064,  1067,  1070,
       0,     0,  1073,     0,  1085,     0,  1088,     0,     0,     0,
       0,  1076,  1079,  1082,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1124,     0,  1126,     0,
       0,  1091,  1128,     0,  1094,  1097,  1130,  1132,  1134,     0,
    1136,     0,     0,     0,     0,     0,  1100,  1103,  1106,  1109,
       0,     0,  1112,  1138,     0,     0,  1140,  1142,     0,     0,
       0,  1115,  1118,  1121,     0,     0,     0,     0,  1144,  1146,
    1148,  1150,     0,     0,  1152,     0,  1160,     0,  1162,     0,
       0,     0,  1164,  1154,  1156,  1158,  1166,  1168,  1170,     0,
    1172,     0,     0,     0,     0,     0,     0,     0,  1196,     0,
    1198,     0,     0,  1174,  1200,     0,  1176,  1178,  1202,  1204,
    1206,     0,  1208,     0,     0,     0,     0,     0,  1180,  1182,
    1184,  1186,     0,     0,  1188,  1210,     0,     0,  1212,  1214,
       0,     0,     0,  1190,  1192,  1194,     0,     0,     0,     0,
    1216,  1218,  1220,  1222,     0,     0,  1224,     0,  1232,     0,
    1234,     0,     0,     0,  1236,  1226,  1228,  1230,  1238,  1240,
    1242,     0,  1244,     0,     0,     0,     0,     0,     0,     0,
    1268,     0,  1270,     0,     0,  1246,  1272,     0,  1248,  1250,
    1274,  1276,  1278,     0,  1280,     0,     0,     0,     0,     0,
    1252,  1254,  1256,  1258,     0,     0,  1260,  1282,     0,     0,
    1284,  1286,     0,     0,     0,  1262,  1264,  1266,     0,     0,
       0,     0,  1288,  1290,  1292,  1294,     0,     0,  1296,     0,
    1304,     0,  1306,     0,     0,     0,  1308,  1298,  1300,  1302,
    1310,  1312,  1314,     0,  1316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1318,     0,     0,
    1320,  1322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1324,  1326,  1328,  1330,     0,     0,  1332,     0,
       0,   577,     0,   579,     0,   581,     0,  1334,  1336,  1338,
       0,   583,   585,   587,     0,   589,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   591,   593,     0,     0,     0,     0,     0,     0,     0,
       0,   595,     0,   597,     0,   599,     0,     0,     0,     0,
       0,   601,   603,   605,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   609,   611,     0,     0,     0,     0,     0,     0,     0,
       0,   613,     0,   615,     0,   617,     0,     0,     0,     0,
       0,   619,   621,   623,     0,   625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   627,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   551,     0,   553,     0,     0,     0,     0,     0,     0,
       0,   555,   557,   559,     0,   561,     0,     0,     0,   563,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   565,   567,     0,     0,     0,     0,     0,     0,     0,
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
       0,   483,     0,   485,     0,     0,     0,     0,     0,     0,
       0,   487,   489,   491,     0,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   497,     0,     0,     0,     0,     0,     0,     0,
       0,   499,     0,   501,     0,     0,     0,     0,     0,     0,
     503,   505,   507,   509,   511,   513,     0,   515,     0,     0,
     517,   519,     0,     0,     0,   521,     0,   523,     0,   525,
     527,   529,   531,   533,   535,   537,   539,   541,   543,   545,
     547,   801,     0,   803,     0,     0,     0,     0,     0,     0,
     805,   807,   809,   811,   813,   815,     0,   817,     0,     0,
     819,   821,     0,     0,     0,   823,     0,   825,     0,   827,
     829,   831,   833,   835,   837,   839,   841,   843,   845,   847,
     849,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   857,     0,   859,     0,     0,     0,     0,     0,     0,
     861,   863,   865,   867,   869,   871,     0,   873,     0,     0,
     875,   877,     0,     0,     0,   879,     0,   881,     0,   883,
     885,   887,   889,   891,   893,   895,   897,   899,   901,   903,
     905,  1030,     0,  1032,     0,     0,     0,     0,     0,     0,
       0,  1034,  1036,  1038,     0,  1040,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1042,  1044,     0,     0,     0,     0,     0,     0,     0,
       0,  1348,     0,  1350,     0,     0,     0,     0,     0,     0,
       0,  1352,  1354,  1356,  1358,  1360,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1362,  1364,     0,     0,     0,     0,     0,     0,     0,
       0,  1366,     0,  1368,     0,     0,     0,     0,     0,     0,
       0,  1370,  1372,  1374,  1376,  1378,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1380,  1382,     0,     0,     0,     0,     0,     0,     0,
       0,  1386,     0,  1388,     0,     0,     0,     0,     0,     0,
    1390,  1392,  1394,  1396,  1398,  1400,     0,  1402,     0,     0,
    1404,  1406,     0,     0,     0,  1408,     0,  1410,     0,  1412,
    1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,  1430,  1432,
    1434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   631,   633,   635,   637,   639,   641,   643,     0,
     645,     0,     0,     0,   647,   649,   651,   653,   655,   657,
     659,   661,   663,   665,   667,     0,     0,     0,     0,   669,
     671,   673,   675,   851,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   140,     0,   140,     0,   140,     0,   140,     0,   140,
       0,   140,     0,   140,     0,   140,     0,   140,     0,   140,
       0,   140,     0,   140,     0,   140,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   147,     0,   147,     0,   147,     0,   147,
       0,   147,     0,   147,     0,   147,     0,   147,     0,   147,
       0,   147,     0,   147,     0,   147,     0,   147,     0,   105,
       0,   105,     0,   105,     0,   105,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     5,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,    60,     0,    60,     0,    60,     0,    60,
       0,    60,     0,   134,     0,     3,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,    13,     0,    13,     0,    13,     0,    13,
       0,    13,     0,    13,     0,    13,     0,    13,     0,   139,
       0,   139,     0,   139,     0,   139,     0,   139,     0,   139,
       0,   139,     0,   139,     0,   139,     0,   139,     0,   139,
       0,   139,     0,   139,     0,   139,     0,   139,     0,   139,
       0,   139,     0,   139,     0,   139,     0,   139,     0,   139,
       0,   139,     0,   139,     0,   139,     0,   139,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     5,     0,     5,     0,     5,     0,     5,     0,     5,
       0,    62,     0,    62,     0,    62,     0,    62,     0,    62,
       0,    62,     0,    62,     0,    62,     0,    62,     0,    62,
       0,    62,     0,    62,     0,    62,     0,    62,     0,    62,
       0,    62,     0,    62,     0,    62,     0,    62,     0,    62,
       0,    62,     0,    62,     0,    62,     0,   112,     0,   108,
     112,     0,   108,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   118,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,     4,     0,     5,     0,     5,     0,   124,     0,   124,
       0,   124,     0,   124,     0,   124,     0,   124,     0,   124,
       0,   124,     0,   124,     0,   124,     0,   124,     0,   124,
       0,   124,     0,   124,     0,   124,     0,   124,     0,   124,
       0,   124,     0,   124,     0,   124,     0,   124,     0,   124,
       0,   124,     0,   124,     0,   124,     0,   112,     0,   112,
       0,   112,     0,   108,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
     112,     0,   112,     0,   112,     0,   112,     0,   112,     0,
      47,     0,    47,     0,    47,     0,    47,     0,    47,     0,
      47,     0,    47,     0,    47,     0,   140,   156,     0,   140,
     156,     0,   140,   156,     0,   140,   156,     0,   140,   156,
       0,   140,   156,     0,   140,   156,     0,   140,   156,     0,
     140,   156,     0,   140,   156,     0,   140,   156,     0,   140,
     156,     0,   140,   156,     0,   141,   157,     0,   141,   157,
       0,   141,   157,     0,   141,   157,     0,   141,   157,     0,
     141,   157,     0,   141,   157,     0,   141,   157,     0,   141,
     157,     0,   141,   157,     0,   141,   157,     0,   141,   157,
       0,   141,   157,     0,   177,     0,   177,     0,   177,     0,
     177,     0,   177,     0,   177,     0,   177,     0,   177,     0,
     177,     0,   177,     0,   177,     0,   177,     0,   177,     0,
     177,     0,   177,     0,   177,     0,   177,     0,   177,     0,
     168,     0,   168,     0,   168,     0,   168,     0,   168,     0,
     168,     0,   168,     0,   168,     0,   168,     0,   168,     0,
     168,     0,   168,     0,   168,     0,   168,     0,   168,     0,
     168,     0,   168,     0,   168,     0,   171,     0,   171,     0,
     171,     0,   171,     0,   171,     0,   171,     0,   171,     0,
     171,     0,   171,     0,   171,     0,   171,     0,   171,     0,
     171,     0,   171,     0,   171,     0,   171,     0,   171,     0,
     171,     0,   172,     0,   172,     0,   172,     0,   172,     0,
     172,     0,   172,     0,   172,     0,   172,     0,   172,     0,
     172,     0,   172,     0,   172,     0,   172,     0,   172,     0,
     172,     0,   172,     0,   172,     0,   172,     0,   154,     0,
     154,     0,   154,     0,   154,     0,   154,     0,   154,     0,
     154,     0,   154,     0,   154,     0,   154,     0,   154,     0,
     154,     0,   154,     0,   154,     0,   154,     0,   154,     0,
     154,     0,   154,     0,   155,     0,   155,     0,   155,     0,
     155,     0,   155,     0,   155,     0,   155,     0,   155,     0,
     155,     0,   155,     0,   155,     0,   155,     0,   155,     0,
     155,     0,   155,     0,   155,     0,   155,     0,   155,     0,
       5,     0,     5,     0,     5,     0,     5,     0,   124,     0,
     124,     0,   124,     0,   124,     0,   124,     0,   124,     0,
     124,     0,   124,     0,   124,     0,   124,     0,   124,     0,
     124,     0,   124,     0,   124,     0,   124,     0,   124,     0,
     124,     0,   124,     0,     5,     0,   158,     0,   158,     0,
     158,     0,   158,     0,   158,     0,   158,     0,   158,     0,
     158,     0,   158,     0,   158,     0,   158,     0,   158,     0,
     158,     0,   158,     0,   158,     0,   158,     0,   158,     0,
     158,     0,   158,     0,   158,     0,   158,     0,   158,     0,
     158,     0,   158,     0,   158,     0
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
   *  duplicate yychar != YYEMPTY.  */
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

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "UNUSED", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'!'", "'#'", "'$'", "'%'", "'&'", "'*'",
  "'+'", "','", "'-'", "'.'", "'/'", "':'", "';'", "'<'", "'>'", "'='",
  "'?'", "'@'", "'^'", "'_'", "'|'", "'~'", "AND", "OR", "INCREMENT",
  "DECREMENT", "SHIFT_L", "SHIFT_R", "ROTATE_L", "ROTATE_R", "COMPARE",
  "INEQUAL", "AT_MOST", "AT_LEAST", "TAIL", "ELLIPSES", "CONST_INT",
  "CONST_FLOAT", "CONST_STRING", "CONST_CHAR", "COMMENT_LINE",
  "COMMENT_BLOCK", "NAME", "BIT", "CHAR", "BYTE", "SHORT", "INT", "FLOAT",
  "INCLUDE", "INLINE", "SIZEOF", "COUNTOF", "NAMEOF", "TYPEOF", "LOCAL",
  "STATIC", "CONST", "EXTERN", "SIGNED", "UNSIGNED", "COMPLEX",
  "IMAGINARY", "LONG", "DOUBLE", "BREAK", "CONTINUE", "RETURN", "GOTO",
  "STRUCT", "UNION", "MODULE", "ENUM", "WHILE", "DO", "FOR", "IF", "ELSE",
  "SWITCH", "CASE", "DEFAULT", "END_FILE", "PREFIX", "GROUP", "LIST",
  "INCREMENT_PRE", "DECREMENT_PRE", "POSITIVE", "NEGATIVE", "COMPLEMENT",
  "DEREFERENCE", "ADDRESS", "META", "POSTFIX", "INCREMENT_POST",
  "DECREMENT_POST", "$accept", "optional_semicolon", "optional_colon",
  "unit", "statements", "statement", "scope", "braced_scope",
  "implicit_scope", "enum_scope", "include", "declaration",
  "qualified_declaration", "structure_declaration", "enum_declaration",
  "control", "switch", "if_else", "do_while", "for", "jump", "loop",
  "goto", "return", "case", "named_marker", "marker", "qualifiers",
  "qualifier", "math_qualifier", "builtin_type", "short",
  "type_qualifiers", "type_qualifier", "type", "underlying_type",
  "indirection", "cat_ptrs", "cat_ptr", "c_ptrs", "c_ptr", "datatype",
  "label", "name", "instances", "instance", "counted_instance",
  "object_declaration", "variable_declarations", "variable_declaration",
  "function_declaration", "tuple", "expression", "single_expression",
  "const_value", "object_value", "operation", "prefix_operation",
  "prefix_operator", "postfix_operation", "postfix_operator",
  "infix_operation", "infix_operator", "infix_assignable_operator",
  "assign_operator", YY_NULLPTR
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

#if YYDEBUG

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

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */



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
#if YYDEBUG
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
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
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
# define yyclearin (yychar = YYEMPTY)
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

#line 2187 "cat.tab.c"

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
#if YYDEBUG
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
  0

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
    yynewOption->yyrawchar = YYEMPTY;
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

#if YYDEBUG

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

#if YYDEBUG
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

#if YYDEBUG
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
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
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

  yychar = YYEMPTY;
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
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
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
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

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
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
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
  if (yychar != YYEMPTY)
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
#if YYDEBUG
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




#line 456 "../cat.y"


/* Epilogue */

void yyerror (const char* message)
{
	fprintf (stderr, "Parse error: %s\n", message);
}

int yywrap ()
{
	return END_FILE;
}
