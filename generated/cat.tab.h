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
    TAIL = 268,                    /* TAIL  */
    ELLIPSES = 269,                /* ELLIPSES  */
    CONST_INT = 270,               /* CONST_INT  */
    CONST_FLOAT = 271,             /* CONST_FLOAT  */
    CONST_STRING = 272,            /* CONST_STRING  */
    CONST_CHAR = 273,              /* CONST_CHAR  */
    COMMENT_LINE = 274,            /* COMMENT_LINE  */
    COMMENT_BLOCK = 275,           /* COMMENT_BLOCK  */
    NAME = 276,                    /* NAME  */
    BIT = 277,                     /* BIT  */
    CHAR = 278,                    /* CHAR  */
    BYTE = 279,                    /* BYTE  */
    SHORT = 280,                   /* SHORT  */
    INT = 281,                     /* INT  */
    FLOAT = 282,                   /* FLOAT  */
    INCLUDE = 283,                 /* INCLUDE  */
    INLINE = 284,                  /* INLINE  */
    SIZEOF = 285,                  /* SIZEOF  */
    COUNTOF = 286,                 /* COUNTOF  */
    NAMEOF = 287,                  /* NAMEOF  */
    TYPEOF = 288,                  /* TYPEOF  */
    LOCAL = 289,                   /* LOCAL  */
    STATIC = 290,                  /* STATIC  */
    CONST = 291,                   /* CONST  */
    EXTERN = 292,                  /* EXTERN  */
    SIGNED = 293,                  /* SIGNED  */
    UNSIGNED = 294,                /* UNSIGNED  */
    COMPLEX = 295,                 /* COMPLEX  */
    IMAGINARY = 296,               /* IMAGINARY  */
    LONG = 297,                    /* LONG  */
    DOUBLE = 298,                  /* DOUBLE  */
    BREAK = 299,                   /* BREAK  */
    CONTINUE = 300,                /* CONTINUE  */
    RETURN = 301,                  /* RETURN  */
    GOTO = 302,                    /* GOTO  */
    STRUCT = 303,                  /* STRUCT  */
    UNION = 304,                   /* UNION  */
    MODULE = 305,                  /* MODULE  */
    ENUM = 306,                    /* ENUM  */
    WHILE = 307,                   /* WHILE  */
    DO = 308,                      /* DO  */
    FOR = 309,                     /* FOR  */
    IF = 310,                      /* IF  */
    ELSE = 311,                    /* ELSE  */
    SWITCH = 312,                  /* SWITCH  */
    CASE = 313,                    /* CASE  */
    DEFAULT = 314,                 /* DEFAULT  */
    END_FILE = 315                 /* END_FILE  */
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
