/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_SINTATICO_TAB_H_INCLUDED
# define YY_YY_BUILD_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    T_ID = 258,                    /* T_ID  */
    T_NUMERO_INTEIRO = 259,        /* T_NUMERO_INTEIRO  */
    T_NUMERO_REAL = 260,           /* T_NUMERO_REAL  */
    T_LITERAL_CHAR = 261,          /* T_LITERAL_CHAR  */
    T_LITERAL_STRING = 262,        /* T_LITERAL_STRING  */
    T_INT = 263,                   /* T_INT  */
    T_FLOAT = 264,                 /* T_FLOAT  */
    T_CHAR = 265,                  /* T_CHAR  */
    T_ATR = 266,                   /* T_ATR  */
    T_IGUAL = 267,                 /* T_IGUAL  */
    T_DIF = 268,                   /* T_DIF  */
    T_MAIG = 269,                  /* T_MAIG  */
    T_MEIG = 270,                  /* T_MEIG  */
    T_MAIOR = 271,                 /* T_MAIOR  */
    T_MENOR = 272,                 /* T_MENOR  */
    T_E = 273,                     /* T_E  */
    T_OU = 274,                    /* T_OU  */
    T_NAO = 275,                   /* T_NAO  */
    T_ADD = 276,                   /* T_ADD  */
    T_SUB = 277,                   /* T_SUB  */
    T_MULT = 278,                  /* T_MULT  */
    T_DIV = 279,                   /* T_DIV  */
    T_RESTO = 280,                 /* T_RESTO  */
    T_PONTO = 281,                 /* T_PONTO  */
    T_VIRGULA = 282,               /* T_VIRGULA  */
    T_DOISPONTOS = 283,            /* T_DOISPONTOS  */
    T_PTVIRG = 284,                /* T_PTVIRG  */
    T_ASPASDUPLA = 285,            /* T_ASPASDUPLA  */
    T_ABRPAR = 286,                /* T_ABRPAR  */
    T_FEPAR = 287,                 /* T_FEPAR  */
    T_ABRCHAV = 288,               /* T_ABRCHAV  */
    T_FECHAV = 289,                /* T_FECHAV  */
    T_COMENT = 290,                /* T_COMENT  */
    T_DIREITA = 291,               /* T_DIREITA  */
    T_ESQUERDA = 292,              /* T_ESQUERDA  */
    T_HASH = 293,                  /* T_HASH  */
    T_SE = 294,                    /* T_SE  */
    T_SENAO = 295,                 /* T_SENAO  */
    T_LACO = 296,                  /* T_LACO  */
    T_ENQUANTO = 297,              /* T_ENQUANTO  */
    T_ESCOLHA = 298,               /* T_ESCOLHA  */
    T_CASO = 299,                  /* T_CASO  */
    T_LEITURA = 300,               /* T_LEITURA  */
    T_ESCRITA = 301,               /* T_ESCRITA  */
    T_VAZIO = 302,                 /* T_VAZIO  */
    T_NULO = 303,                  /* T_NULO  */
    T_QUEBRA = 304,                /* T_QUEBRA  */
    T_RETORNO = 305,               /* T_RETORNO  */
    T_DEFINE = 306,                /* T_DEFINE  */
    T_INCLUDE = 307                /* T_INCLUDE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 85 "src/sintatico.y"
 char *sval; 

#line 119 "build/sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_SINTATICO_TAB_H_INCLUDED  */
