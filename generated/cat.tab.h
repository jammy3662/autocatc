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

#ifndef YY_CAT_CAT_TAB_H_INCLUDED
# define YY_CAT_CAT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef CATDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define CATDEBUG 1
#  else
#   define CATDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define CATDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined CATDEBUG */
#if CATDEBUG
extern int catdebug;
#endif

/* Token kinds.  */
#ifndef CATTOKENTYPE
# define CATTOKENTYPE
  enum cattokentype
  {
    CATEMPTY = -2,
    CATEOF = 0,                    /* "end of file"  */
    CATerror = 256,                /* error  */
    CATUNDEF = 257,                /* "invalid token"  */
    AND = 258,                     /* AND  */
    OR = 259,                      /* OR  */
    INCREMENT = 260,               /* INCREMENT  */
    DECREMENT = 261,               /* DECREMENT  */
    SHIFT_L = 262,                 /* SHIFT_L  */
    SHIFT_R = 263,                 /* SHIFT_R  */
    ROTATE_L = 264,                /* ROTATE_L  */
    ROTATE_R = 265,                /* ROTATE_R  */
    COMPARE = 266,                 /* COMPARE  */
    INEQUAL = 267,                 /* INEQUAL  */
    AT_MOST = 268,                 /* AT_MOST  */
    AT_LEAST = 269,                /* AT_LEAST  */
    TAIL = 270,                    /* TAIL  */
    ELLIPSES = 271,                /* ELLIPSES  */
    CONST_INT = 272,               /* CONST_INT  */
    CONST_FLOAT = 273,             /* CONST_FLOAT  */
    CONST_STRING = 274,            /* CONST_STRING  */
    CONST_CHAR = 275,              /* CONST_CHAR  */
    COMMENT_LINE = 276,            /* COMMENT_LINE  */
    COMMENT_BLOCK = 277,           /* COMMENT_BLOCK  */
    NAME = 278,                    /* NAME  */
    BIT = 279,                     /* BIT  */
    CHAR = 280,                    /* CHAR  */
    BYTE = 281,                    /* BYTE  */
    SHORT = 282,                   /* SHORT  */
    INT = 283,                     /* INT  */
    FLOAT = 284,                   /* FLOAT  */
    INCLUDE = 285,                 /* INCLUDE  */
    INLINE = 286,                  /* INLINE  */
    SIZEOF = 287,                  /* SIZEOF  */
    COUNTOF = 288,                 /* COUNTOF  */
    NAMEOF = 289,                  /* NAMEOF  */
    TYPEOF = 290,                  /* TYPEOF  */
    LOCAL = 291,                   /* LOCAL  */
    STATIC = 292,                  /* STATIC  */
    CONST = 293,                   /* CONST  */
    EXTERN = 294,                  /* EXTERN  */
    SIGNED = 295,                  /* SIGNED  */
    UNSIGNED = 296,                /* UNSIGNED  */
    COMPLEX = 297,                 /* COMPLEX  */
    IMAGINARY = 298,               /* IMAGINARY  */
    LONG = 299,                    /* LONG  */
    DOUBLE = 300,                  /* DOUBLE  */
    BREAK = 301,                   /* BREAK  */
    CONTINUE = 302,                /* CONTINUE  */
    RETURN = 303,                  /* RETURN  */
    GOTO = 304,                    /* GOTO  */
    STRUCT = 305,                  /* STRUCT  */
    UNION = 306,                   /* UNION  */
    MODULE = 307,                  /* MODULE  */
    ENUM = 308,                    /* ENUM  */
    WHILE = 309,                   /* WHILE  */
    DO = 310,                      /* DO  */
    FOR = 311,                     /* FOR  */
    IF = 312,                      /* IF  */
    ELSE = 313,                    /* ELSE  */
    SWITCH = 314,                  /* SWITCH  */
    CASE = 315,                    /* CASE  */
    DEFAULT = 316,                 /* DEFAULT  */
    EMPTY = 317,                   /* EMPTY  */
    VALUE = 318,                   /* VALUE  */
    INFIX = 319,                   /* INFIX  */
    PREFIX = 320,                  /* PREFIX  */
    POSTFIX = 321                  /* POSTFIX  */
  };
  typedef enum cattokentype cattoken_kind_t;
#endif

/* Value type.  */
#if ! defined CATSTYPE && ! defined CATSTYPE_IS_DECLARED
typedef int CATSTYPE;
# define CATSTYPE_IS_TRIVIAL 1
# define CATSTYPE_IS_DECLARED 1
#endif


extern CATSTYPE catlval;

int catparse (void);

#endif /* !YY_CAT_CAT_TAB_H_INCLUDED  */
