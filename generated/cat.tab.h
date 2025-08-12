/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_YY_CAT_TAB_H_INCLUDED
# define YY_YY_CAT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    UNUSED = 258,                  /* UNUSED  */
    AND = 259,                     /* AND  */
    OR = 260,                      /* OR  */
    INCREMENT = 261,               /* INCREMENT  */
    DECREMENT = 262,               /* DECREMENT  */
    SHIFT_L = 263,                 /* SHIFT_L  */
    SHIFT_R = 264,                 /* SHIFT_R  */
    ROTATE_L = 265,                /* ROTATE_L  */
    ROTATE_R = 266,                /* ROTATE_R  */
    COMPARE = 267,                 /* COMPARE  */
    INEQUAL = 268,                 /* INEQUAL  */
    AT_MOST = 269,                 /* AT_MOST  */
    AT_LEAST = 270,                /* AT_LEAST  */
    TAIL = 271,                    /* TAIL  */
    ELLIPSES = 272,                /* ELLIPSES  */
    CONST_INT = 273,               /* CONST_INT  */
    CONST_FLOAT = 274,             /* CONST_FLOAT  */
    CONST_STRING = 275,            /* CONST_STRING  */
    CONST_CHAR = 276,              /* CONST_CHAR  */
    COMMENT_LINE = 277,            /* COMMENT_LINE  */
    COMMENT_BLOCK = 278,           /* COMMENT_BLOCK  */
    NAME = 279,                    /* NAME  */
    BIT = 280,                     /* BIT  */
    CHAR = 281,                    /* CHAR  */
    BYTE = 282,                    /* BYTE  */
    SHORT = 283,                   /* SHORT  */
    INT = 284,                     /* INT  */
    FLOAT = 285,                   /* FLOAT  */
    INCLUDE = 286,                 /* INCLUDE  */
    INLINE = 287,                  /* INLINE  */
    SIZEOF = 288,                  /* SIZEOF  */
    COUNTOF = 289,                 /* COUNTOF  */
    NAMEOF = 290,                  /* NAMEOF  */
    TYPEOF = 291,                  /* TYPEOF  */
    LOCAL = 292,                   /* LOCAL  */
    STATIC = 293,                  /* STATIC  */
    CONST = 294,                   /* CONST  */
    EXTERN = 295,                  /* EXTERN  */
    SIGNED = 296,                  /* SIGNED  */
    UNSIGNED = 297,                /* UNSIGNED  */
    COMPLEX = 298,                 /* COMPLEX  */
    IMAGINARY = 299,               /* IMAGINARY  */
    LONG = 300,                    /* LONG  */
    DOUBLE = 301,                  /* DOUBLE  */
    BREAK = 302,                   /* BREAK  */
    CONTINUE = 303,                /* CONTINUE  */
    RETURN = 304,                  /* RETURN  */
    GOTO = 305,                    /* GOTO  */
    STRUCT = 306,                  /* STRUCT  */
    UNION = 307,                   /* UNION  */
    MODULE = 308,                  /* MODULE  */
    ENUM = 309,                    /* ENUM  */
    WHILE = 310,                   /* WHILE  */
    DO = 311,                      /* DO  */
    FOR = 312,                     /* FOR  */
    IF = 313,                      /* IF  */
    ELSE = 314,                    /* ELSE  */
    SWITCH = 315,                  /* SWITCH  */
    CASE = 316,                    /* CASE  */
    DEFAULT = 317,                 /* DEFAULT  */
    END_FILE = 318,                /* END_FILE  */
    PREFIX = 319,                  /* PREFIX  */
    GROUP = 320,                   /* GROUP  */
    LIST = 321,                    /* LIST  */
    INCREMENT_PRE = 322,           /* INCREMENT_PRE  */
    DECREMENT_PRE = 323,           /* DECREMENT_PRE  */
    POSITIVE = 324,                /* POSITIVE  */
    NEGATIVE = 325,                /* NEGATIVE  */
    COMPLEMENT = 326,              /* COMPLEMENT  */
    DEREFERENCE = 327,             /* DEREFERENCE  */
    ADDRESS = 328,                 /* ADDRESS  */
    META = 329,                    /* META  */
    POSTFIX = 330,                 /* POSTFIX  */
    INCREMENT_POST = 331,          /* INCREMENT_POST  */
    DECREMENT_POST = 332           /* DECREMENT_POST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAT_TAB_H_INCLUDED  */
