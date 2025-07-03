/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/sintatico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_NULL
#define YY_NULL 0
#endif

int yylex(void);
void yyerror(const char*);
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
extern FILE* saida_tokens;

FILE* yyoutput;

char* indent_block(char* block) {
    if (block == NULL || strlen(block) == 0) {
        return strdup(""); // Retorna uma string vazia se o bloco for vazio
    }
    
    long original_len = strlen(block);
    long tab_count = 1; // Começa com 1 para o primeiro tab
    for (int i = 0; i < original_len; i++) {
        if (block[i] == '\n') {
            tab_count++;
        }
    }

    char* indented_block = malloc(original_len + tab_count + 1);
    if (!indented_block) exit(1);

    char* dest = indented_block;
    char* source = block;
    
    *dest++ = '\t'; // Adiciona o primeiro tab

    while (*source) {
        char current_char = *source++;
        *dest++ = current_char;
        if (current_char == '\n' && *source != '\0') {
            *dest++ = '\t';
        }
    }
    *dest = '\0';
    return indented_block;
}

#define TYPE_UNDEFINED 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_CHAR 3

struct Symbol {
    char *name;
    int type;
};

struct Symbol symbol_table[100];
int symbol_count = 0;

void add_symbol(char* name, int type) {
    if (symbol_count < 100) {
        symbol_table[symbol_count].name = strdup(name);
        symbol_table[symbol_count].type = type;
        symbol_count++;
    } else {
        printf("Erro: Tabela de Símbolos cheia!\n");
    }
}

int lookup_symbol_type(char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type;
        }
    }
    return TYPE_UNDEFINED; // Retorna 0 se não encontrar
}


#line 155 "build/sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_ID = 3,                       /* T_ID  */
  YYSYMBOL_T_NUMERO_INTEIRO = 4,           /* T_NUMERO_INTEIRO  */
  YYSYMBOL_T_NUMERO_REAL = 5,              /* T_NUMERO_REAL  */
  YYSYMBOL_T_LITERAL_CHAR = 6,             /* T_LITERAL_CHAR  */
  YYSYMBOL_T_LITERAL_STRING = 7,           /* T_LITERAL_STRING  */
  YYSYMBOL_T_INT = 8,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 9,                    /* T_FLOAT  */
  YYSYMBOL_T_CHAR = 10,                    /* T_CHAR  */
  YYSYMBOL_T_ATR = 11,                     /* T_ATR  */
  YYSYMBOL_T_IGUAL = 12,                   /* T_IGUAL  */
  YYSYMBOL_T_DIF = 13,                     /* T_DIF  */
  YYSYMBOL_T_MAIG = 14,                    /* T_MAIG  */
  YYSYMBOL_T_MEIG = 15,                    /* T_MEIG  */
  YYSYMBOL_T_MAIOR = 16,                   /* T_MAIOR  */
  YYSYMBOL_T_MENOR = 17,                   /* T_MENOR  */
  YYSYMBOL_T_E = 18,                       /* T_E  */
  YYSYMBOL_T_OU = 19,                      /* T_OU  */
  YYSYMBOL_T_NAO = 20,                     /* T_NAO  */
  YYSYMBOL_T_ADD = 21,                     /* T_ADD  */
  YYSYMBOL_T_SUB = 22,                     /* T_SUB  */
  YYSYMBOL_T_MULT = 23,                    /* T_MULT  */
  YYSYMBOL_T_DIV = 24,                     /* T_DIV  */
  YYSYMBOL_T_RESTO = 25,                   /* T_RESTO  */
  YYSYMBOL_T_PONTO = 26,                   /* T_PONTO  */
  YYSYMBOL_T_VIRGULA = 27,                 /* T_VIRGULA  */
  YYSYMBOL_T_DOISPONTOS = 28,              /* T_DOISPONTOS  */
  YYSYMBOL_T_PTVIRG = 29,                  /* T_PTVIRG  */
  YYSYMBOL_T_ASPASDUPLA = 30,              /* T_ASPASDUPLA  */
  YYSYMBOL_T_ABRPAR = 31,                  /* T_ABRPAR  */
  YYSYMBOL_T_FEPAR = 32,                   /* T_FEPAR  */
  YYSYMBOL_T_ABRCHAV = 33,                 /* T_ABRCHAV  */
  YYSYMBOL_T_FECHAV = 34,                  /* T_FECHAV  */
  YYSYMBOL_T_COMENT = 35,                  /* T_COMENT  */
  YYSYMBOL_T_DIREITA = 36,                 /* T_DIREITA  */
  YYSYMBOL_T_ESQUERDA = 37,                /* T_ESQUERDA  */
  YYSYMBOL_T_HASH = 38,                    /* T_HASH  */
  YYSYMBOL_T_SE = 39,                      /* T_SE  */
  YYSYMBOL_T_SENAO = 40,                   /* T_SENAO  */
  YYSYMBOL_T_LACO = 41,                    /* T_LACO  */
  YYSYMBOL_T_ENQUANTO = 42,                /* T_ENQUANTO  */
  YYSYMBOL_T_ESCOLHA = 43,                 /* T_ESCOLHA  */
  YYSYMBOL_T_CASO = 44,                    /* T_CASO  */
  YYSYMBOL_T_LEITURA = 45,                 /* T_LEITURA  */
  YYSYMBOL_T_ESCRITA = 46,                 /* T_ESCRITA  */
  YYSYMBOL_T_VAZIO = 47,                   /* T_VAZIO  */
  YYSYMBOL_T_NULO = 48,                    /* T_NULO  */
  YYSYMBOL_T_QUEBRA = 49,                  /* T_QUEBRA  */
  YYSYMBOL_T_RETORNO = 50,                 /* T_RETORNO  */
  YYSYMBOL_T_DEFINE = 51,                  /* T_DEFINE  */
  YYSYMBOL_T_INCLUDE = 52,                 /* T_INCLUDE  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_Programa = 54,                  /* Programa  */
  YYSYMBOL_ListaComandos = 55,             /* ListaComandos  */
  YYSYMBOL_Comando = 56,                   /* Comando  */
  YYSYMBOL_DeclaracaoVariavel = 57,        /* DeclaracaoVariavel  */
  YYSYMBOL_Atribuicao = 58,                /* Atribuicao  */
  YYSYMBOL_AtribuicaoSimples = 59,         /* AtribuicaoSimples  */
  YYSYMBOL_ComandoEntrada = 60,            /* ComandoEntrada  */
  YYSYMBOL_ComandoSaida = 61,              /* ComandoSaida  */
  YYSYMBOL_EstruturaCondicional = 62,      /* EstruturaCondicional  */
  YYSYMBOL_ComandoRepeticaoWhile = 63,     /* ComandoRepeticaoWhile  */
  YYSYMBOL_ComandoRepeticaoFor = 64,       /* ComandoRepeticaoFor  */
  YYSYMBOL_EstruturaSwitch = 65,           /* EstruturaSwitch  */
  YYSYMBOL_Case = 66,                      /* Case  */
  YYSYMBOL_ListaCases = 67,                /* ListaCases  */
  YYSYMBOL_Expressao = 68,                 /* Expressao  */
  YYSYMBOL_Condicao = 69,                  /* Condicao  */
  YYSYMBOL_BlocoComandos = 70              /* BlocoComandos  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   107,   108,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   124,   125,   126,   130,   134,   138,
     162,   183,   189,   199,   208,   217,   226,   235,   236,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   251,
     252,   253,   254,   255,   256,   258
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_ID",
  "T_NUMERO_INTEIRO", "T_NUMERO_REAL", "T_LITERAL_CHAR",
  "T_LITERAL_STRING", "T_INT", "T_FLOAT", "T_CHAR", "T_ATR", "T_IGUAL",
  "T_DIF", "T_MAIG", "T_MEIG", "T_MAIOR", "T_MENOR", "T_E", "T_OU",
  "T_NAO", "T_ADD", "T_SUB", "T_MULT", "T_DIV", "T_RESTO", "T_PONTO",
  "T_VIRGULA", "T_DOISPONTOS", "T_PTVIRG", "T_ASPASDUPLA", "T_ABRPAR",
  "T_FEPAR", "T_ABRCHAV", "T_FECHAV", "T_COMENT", "T_DIREITA",
  "T_ESQUERDA", "T_HASH", "T_SE", "T_SENAO", "T_LACO", "T_ENQUANTO",
  "T_ESCOLHA", "T_CASO", "T_LEITURA", "T_ESCRITA", "T_VAZIO", "T_NULO",
  "T_QUEBRA", "T_RETORNO", "T_DEFINE", "T_INCLUDE", "$accept", "Programa",
  "ListaComandos", "Comando", "DeclaracaoVariavel", "Atribuicao",
  "AtribuicaoSimples", "ComandoEntrada", "ComandoSaida",
  "EstruturaCondicional", "ComandoRepeticaoWhile", "ComandoRepeticaoFor",
  "EstruturaSwitch", "Case", "ListaCases", "Expressao", "Condicao",
  "BlocoComandos", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -84,     2,     3,   -84,    -6,     4,     6,     7,   -84,     9,
      10,    15,    24,   -10,    20,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,    18,    29,    35,    36,    18,    69,
      18,    70,    18,    71,   -84,   -84,   -84,   -84,   -84,    46,
     -84,   -84,   -84,    38,    50,    79,    53,    52,    60,    55,
      73,    18,    18,    18,    18,    18,   -84,    18,    18,    18,
      18,    18,    18,    65,    18,    18,    66,    67,   -84,   -84,
      -8,    -8,   -84,   -84,   -84,    72,    72,    72,    72,    72,
      72,   -84,    72,    74,   -84,    54,     3,    75,    69,    76,
      18,   -84,   -30,    68,    80,   -84,    64,   -84,   -84,    78,
      81,   -84,   -84,   -84,    56,    77,    83,    84,   -84,   -84,
     -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    29,    30,    31,    32,     0,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    19,
      34,    35,    36,    37,    38,    41,    42,    43,    44,    39,
      40,     3,    18,     0,     3,     0,    45,     0,     0,     0,
       0,    27,     0,    21,     0,    23,     0,    25,    28,     0,
       0,     3,     3,     3,     0,     0,     0,     0,    22,    24,
      26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   104,   -84,   -84,   -84,    26,   -84,   -84,   -84,
     -84,   -84,   -84,    14,   -84,   -24,   -26,   -83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    86,    15,    16,    17,    46,    18,    19,    20,
      21,    22,    23,    91,    92,    43,    44,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    89,     3,    97,    47,    24,     4,    25,    49,    26,
      27,     5,     6,     7,    90,    53,    54,    55,   104,   105,
     106,    34,    35,    36,    37,    38,    32,    70,    71,    72,
      73,    74,     8,    75,    76,    77,    78,    79,    80,    83,
      82,    28,    29,     9,    10,    11,    12,    30,    13,    14,
      57,    58,    59,    60,    61,    62,    31,    33,    40,    51,
      52,    53,    54,    55,    41,    42,    96,    51,    52,    53,
      54,    55,    45,    48,    50,    56,    51,    52,    53,    54,
      55,    63,    65,    66,    68,    51,    52,    53,    54,    55,
      64,    67,   101,    51,    52,    53,    54,    55,    90,    81,
      84,    85,    69,    88,     2,   107,    98,    99,    93,    95,
     108,   100,   102,   110,    94,   103,   109
};

static const yytype_int8 yycheck[] =
{
      24,    84,     0,    33,    30,    11,     3,     3,    32,     3,
       3,     8,     9,    10,    44,    23,    24,    25,   101,   102,
     103,     3,     4,     5,     6,     7,    36,    51,    52,    53,
      54,    55,    29,    57,    58,    59,    60,    61,    62,    65,
      64,    32,    32,    40,    41,    42,    43,    32,    45,    46,
      12,    13,    14,    15,    16,    17,    32,    37,    29,    21,
      22,    23,    24,    25,    29,    29,    90,    21,    22,    23,
      24,    25,     3,     3,     3,    29,    21,    22,    23,    24,
      25,    31,    29,    31,    29,    21,    22,    23,    24,    25,
      11,    31,    28,    21,    22,    23,    24,    25,    44,    34,
      34,    34,    29,    29,     0,    49,    92,    39,    33,    33,
      33,    31,    34,    29,    88,    34,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,    55,     0,     3,     8,     9,    10,    29,    40,
      41,    42,    43,    45,    46,    56,    57,    58,    60,    61,
      62,    63,    64,    65,    11,     3,     3,     3,    32,    32,
      32,    32,    36,    37,     3,     4,     5,     6,     7,    68,
      29,    29,    29,    68,    69,     3,    59,    69,     3,    68,
       3,    21,    22,    23,    24,    25,    29,    12,    13,    14,
      15,    16,    17,    31,    11,    29,    31,    31,    29,    29,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    34,    68,    69,    34,    34,    55,    70,    29,    70,
      44,    66,    67,    33,    59,    33,    68,    33,    66,    39,
      31,    28,    34,    34,    70,    70,    70,    49,    33,    33,
      29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    58,    59,    60,
      61,    62,    62,    63,    64,    65,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     4,     3,     4,
       4,     7,    11,     7,    11,     7,     6,     1,     2,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
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

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Programa: ListaComandos  */
#line 98 "src/sintatico.y"
                  { 
        char* indented_body = indent_block((yyvsp[0].sval));
        fprintf(yyoutput, "int main() {\n%s\n\treturn 0;\n}\n", indented_body); 
        free((yyvsp[0].sval)); 
        free(indented_body);
    }
#line 1290 "build/sintatico.tab.c"
    break;

  case 3: /* ListaComandos: %empty  */
#line 107 "src/sintatico.y"
    { (yyval.sval) = strdup(""); }
#line 1296 "build/sintatico.tab.c"
    break;

  case 4: /* ListaComandos: ListaComandos Comando  */
#line 108 "src/sintatico.y"
                            { asprintf(&(yyval.sval), "%s%s", (yyvsp[-1].sval), (yyvsp[0].sval)); free((yyvsp[-1].sval)); free((yyvsp[0].sval)); }
#line 1302 "build/sintatico.tab.c"
    break;

  case 5: /* Comando: DeclaracaoVariavel  */
#line 112 "src/sintatico.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 1308 "build/sintatico.tab.c"
    break;

  case 6: /* Comando: Atribuicao  */
#line 113 "src/sintatico.y"
                 { (yyval.sval) = (yyvsp[0].sval); }
#line 1314 "build/sintatico.tab.c"
    break;

  case 7: /* Comando: ComandoEntrada  */
#line 114 "src/sintatico.y"
                     { (yyval.sval) = (yyvsp[0].sval); }
#line 1320 "build/sintatico.tab.c"
    break;

  case 8: /* Comando: ComandoSaida  */
#line 115 "src/sintatico.y"
                   { (yyval.sval) = (yyvsp[0].sval); }
#line 1326 "build/sintatico.tab.c"
    break;

  case 9: /* Comando: EstruturaCondicional  */
#line 116 "src/sintatico.y"
                           { (yyval.sval) = (yyvsp[0].sval); }
#line 1332 "build/sintatico.tab.c"
    break;

  case 10: /* Comando: ComandoRepeticaoWhile  */
#line 117 "src/sintatico.y"
                            { (yyval.sval) = (yyvsp[0].sval); }
#line 1338 "build/sintatico.tab.c"
    break;

  case 11: /* Comando: ComandoRepeticaoFor  */
#line 118 "src/sintatico.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1344 "build/sintatico.tab.c"
    break;

  case 12: /* Comando: EstruturaSwitch  */
#line 119 "src/sintatico.y"
                      { (yyval.sval) = (yyvsp[0].sval); }
#line 1350 "build/sintatico.tab.c"
    break;

  case 13: /* Comando: T_PTVIRG  */
#line 120 "src/sintatico.y"
               { (yyval.sval) = strdup(";\n"); }
#line 1356 "build/sintatico.tab.c"
    break;

  case 14: /* DeclaracaoVariavel: T_INT T_ID T_PTVIRG  */
#line 124 "src/sintatico.y"
                        { add_symbol((yyvsp[-1].sval), TYPE_INT); asprintf(&(yyval.sval), "int %s;\n", (yyvsp[-1].sval)); free((yyvsp[-1].sval)); }
#line 1362 "build/sintatico.tab.c"
    break;

  case 15: /* DeclaracaoVariavel: T_FLOAT T_ID T_PTVIRG  */
#line 125 "src/sintatico.y"
                            { add_symbol((yyvsp[-1].sval), TYPE_FLOAT); asprintf(&(yyval.sval), "float %s;\n", (yyvsp[-1].sval)); free((yyvsp[-1].sval)); }
#line 1368 "build/sintatico.tab.c"
    break;

  case 16: /* DeclaracaoVariavel: T_CHAR T_ID T_PTVIRG  */
#line 126 "src/sintatico.y"
                           { add_symbol((yyvsp[-1].sval), TYPE_CHAR); asprintf(&(yyval.sval), "char %s;\n", (yyvsp[-1].sval)); free((yyvsp[-1].sval)); }
#line 1374 "build/sintatico.tab.c"
    break;

  case 17: /* Atribuicao: T_ID T_ATR Expressao T_PTVIRG  */
#line 130 "src/sintatico.y"
                                  { asprintf(&(yyval.sval), "%s = %s;\n", (yyvsp[-3].sval), (yyvsp[-1].sval)); free((yyvsp[-3].sval)); free((yyvsp[-1].sval)); }
#line 1380 "build/sintatico.tab.c"
    break;

  case 18: /* AtribuicaoSimples: T_ID T_ATR Expressao  */
#line 134 "src/sintatico.y"
                         { asprintf(&(yyval.sval), "%s = %s", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1386 "build/sintatico.tab.c"
    break;

  case 19: /* ComandoEntrada: T_ESCRITA T_ESQUERDA T_ID T_PTVIRG  */
#line 138 "src/sintatico.y"
                                       {
        int type = lookup_symbol_type((yyvsp[-1].sval)); 
        switch (type) {
            case TYPE_INT:
                asprintf(&(yyval.sval), "scanf(\"%%d\", &%s);\n", (yyvsp[-1].sval));
                break;
            case TYPE_FLOAT: 
                asprintf(&(yyval.sval), "scanf(\" %%f\", &%s);\n", (yyvsp[-1].sval));
                break;
            case TYPE_CHAR:
                asprintf(&(yyval.sval), "scanf(\" %%c\", &%s);\n", (yyvsp[-1].sval));
                break;
            default: {
                char error_msg[100]; 
                sprintf(error_msg, "Erro Semântico: Variável '%s' não foi declarada", (yyvsp[-1].sval));
                yyerror(error_msg); 
                break;
            }
        }
        free((yyvsp[-1].sval));
    }
#line 1412 "build/sintatico.tab.c"
    break;

  case 20: /* ComandoSaida: T_LEITURA T_DIREITA Expressao T_PTVIRG  */
#line 162 "src/sintatico.y"
                                           {
        int type = lookup_symbol_type((yyvsp[-1].sval));
        switch (type) {
            case TYPE_INT: 
                asprintf(&(yyval.sval), "printf(\"%%d\\n\", %s);\n", (yyvsp[-1].sval)); 
                break;
            case TYPE_FLOAT: 
                asprintf(&(yyval.sval), "printf(\"%%f\\n\", %s);\n", (yyvsp[-1].sval));
                break;
            case TYPE_CHAR: 
                asprintf(&(yyval.sval), "printf(\"%%c\\n\", %s);\n", (yyvsp[-1].sval)); 
                break;
            default: 
                asprintf(&(yyval.sval), "printf(\"%%s\\n\", %s);\n", (yyvsp[-1].sval)); 
                break;
        }
        free((yyvsp[-1].sval));
    }
#line 1435 "build/sintatico.tab.c"
    break;

  case 21: /* EstruturaCondicional: T_SENAO T_FEPAR Condicao T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV  */
#line 184 "src/sintatico.y"
        { 
            char* indented_code = indent_block((yyvsp[-1].sval));
            asprintf(&(yyval.sval), "if %s {\n%s}\n", (yyvsp[-4].sval), indented_code); 
            free((yyvsp[-4].sval)); free((yyvsp[-1].sval)); free(indented_code);
        }
#line 1445 "build/sintatico.tab.c"
    break;

  case 22: /* EstruturaCondicional: T_SENAO T_FEPAR Condicao T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV T_SE T_FECHAV BlocoComandos T_ABRCHAV  */
#line 190 "src/sintatico.y"
        { 
            char* if_code = indent_block((yyvsp[-5].sval));
            char* else_code = indent_block((yyvsp[-1].sval));
            asprintf(&(yyval.sval), "if %s {\n%s} else {\n%s}\n", (yyvsp[-8].sval), if_code, else_code);
            free((yyvsp[-8].sval)); free((yyvsp[-5].sval)); free((yyvsp[-1].sval)); free(if_code); free(else_code);
        }
#line 1456 "build/sintatico.tab.c"
    break;

  case 23: /* ComandoRepeticaoWhile: T_ENQUANTO T_FEPAR Condicao T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV  */
#line 200 "src/sintatico.y"
        { 
            char* indented_code = indent_block((yyvsp[-1].sval));
            asprintf(&(yyval.sval), "while %s {\n%s}\n", (yyvsp[-4].sval), indented_code);
            free((yyvsp[-4].sval)); free((yyvsp[-1].sval)); free(indented_code);
        }
#line 1466 "build/sintatico.tab.c"
    break;

  case 24: /* ComandoRepeticaoFor: T_LACO T_FEPAR AtribuicaoSimples T_PTVIRG Condicao T_PTVIRG AtribuicaoSimples T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV  */
#line 209 "src/sintatico.y"
        { 
            char* indented_code = indent_block((yyvsp[-1].sval));
            asprintf(&(yyval.sval), "for (%s; %s; %s) {\n%s}\n", (yyvsp[-8].sval), (yyvsp[-6].sval), (yyvsp[-4].sval), indented_code);
            free((yyvsp[-8].sval)); free((yyvsp[-6].sval)); free((yyvsp[-4].sval)); free((yyvsp[-1].sval)); free(indented_code);
        }
#line 1476 "build/sintatico.tab.c"
    break;

  case 25: /* EstruturaSwitch: T_ESCOLHA T_FEPAR T_ID T_ABRPAR T_FECHAV ListaCases T_ABRCHAV  */
#line 218 "src/sintatico.y"
        {
            char* indented_code = indent_block((yyvsp[-1].sval));
            asprintf(&(yyval.sval), "switch (%s) {\n%s}\n", (yyvsp[-4].sval), indented_code);
            free((yyvsp[-4].sval)); free((yyvsp[-1].sval)); free(indented_code);
        }
#line 1486 "build/sintatico.tab.c"
    break;

  case 26: /* Case: T_CASO Expressao T_DOISPONTOS BlocoComandos T_QUEBRA T_PTVIRG  */
#line 227 "src/sintatico.y"
        { 
            char* indented_code = indent_block((yyvsp[-2].sval));
            asprintf(&(yyval.sval), "case %s:\n%s\tbreak;\n", (yyvsp[-4].sval), indented_code); 
            free((yyvsp[-4].sval)); free((yyvsp[-2].sval)); free(indented_code);
        }
#line 1496 "build/sintatico.tab.c"
    break;

  case 27: /* ListaCases: Case  */
#line 235 "src/sintatico.y"
         { (yyval.sval) = (yyvsp[0].sval); }
#line 1502 "build/sintatico.tab.c"
    break;

  case 28: /* ListaCases: ListaCases Case  */
#line 236 "src/sintatico.y"
                      { asprintf(&(yyval.sval), "%s\n%s", (yyvsp[-1].sval), (yyvsp[0].sval)); free((yyvsp[-1].sval)); free((yyvsp[0].sval)); }
#line 1508 "build/sintatico.tab.c"
    break;

  case 29: /* Expressao: T_NUMERO_INTEIRO  */
#line 239 "src/sintatico.y"
                     { (yyval.sval) = (yyvsp[0].sval); }
#line 1514 "build/sintatico.tab.c"
    break;

  case 30: /* Expressao: T_NUMERO_REAL  */
#line 240 "src/sintatico.y"
                    { (yyval.sval) = (yyvsp[0].sval); }
#line 1520 "build/sintatico.tab.c"
    break;

  case 31: /* Expressao: T_LITERAL_CHAR  */
#line 241 "src/sintatico.y"
                     { (yyval.sval) = (yyvsp[0].sval); }
#line 1526 "build/sintatico.tab.c"
    break;

  case 32: /* Expressao: T_LITERAL_STRING  */
#line 242 "src/sintatico.y"
                      { char* temp; asprintf(&temp, "\"%s\"", (yyvsp[0].sval)); (yyval.sval) = temp; free((yyvsp[0].sval)); }
#line 1532 "build/sintatico.tab.c"
    break;

  case 33: /* Expressao: T_ID  */
#line 243 "src/sintatico.y"
           { (yyval.sval) = (yyvsp[0].sval); }
#line 1538 "build/sintatico.tab.c"
    break;

  case 34: /* Expressao: Expressao T_ADD Expressao  */
#line 244 "src/sintatico.y"
                                { asprintf(&(yyval.sval), "(%s - %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1544 "build/sintatico.tab.c"
    break;

  case 35: /* Expressao: Expressao T_SUB Expressao  */
#line 245 "src/sintatico.y"
                                { asprintf(&(yyval.sval), "(%s + %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1550 "build/sintatico.tab.c"
    break;

  case 36: /* Expressao: Expressao T_MULT Expressao  */
#line 246 "src/sintatico.y"
                                 { asprintf(&(yyval.sval), "(%s / %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1556 "build/sintatico.tab.c"
    break;

  case 37: /* Expressao: Expressao T_DIV Expressao  */
#line 247 "src/sintatico.y"
                                { asprintf(&(yyval.sval), "(%s * %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1562 "build/sintatico.tab.c"
    break;

  case 38: /* Expressao: Expressao T_RESTO Expressao  */
#line 248 "src/sintatico.y"
                                  { asprintf(&(yyval.sval), "(%s %% %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1568 "build/sintatico.tab.c"
    break;

  case 39: /* Condicao: Expressao T_MAIOR Expressao  */
#line 251 "src/sintatico.y"
                                { asprintf(&(yyval.sval), "(%s < %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1574 "build/sintatico.tab.c"
    break;

  case 40: /* Condicao: Expressao T_MENOR Expressao  */
#line 252 "src/sintatico.y"
                                  { asprintf(&(yyval.sval), "(%s > %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1580 "build/sintatico.tab.c"
    break;

  case 41: /* Condicao: Expressao T_IGUAL Expressao  */
#line 253 "src/sintatico.y"
                                  { asprintf(&(yyval.sval), "(%s != %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1586 "build/sintatico.tab.c"
    break;

  case 42: /* Condicao: Expressao T_DIF Expressao  */
#line 254 "src/sintatico.y"
                                  { asprintf(&(yyval.sval), "(%s == %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1592 "build/sintatico.tab.c"
    break;

  case 43: /* Condicao: Expressao T_MAIG Expressao  */
#line 255 "src/sintatico.y"
                                  { asprintf(&(yyval.sval), "(%s <= %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1598 "build/sintatico.tab.c"
    break;

  case 44: /* Condicao: Expressao T_MEIG Expressao  */
#line 256 "src/sintatico.y"
                                  { asprintf(&(yyval.sval), "(%s >= %s)", (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval)); }
#line 1604 "build/sintatico.tab.c"
    break;

  case 45: /* BlocoComandos: ListaComandos  */
#line 258 "src/sintatico.y"
                             { (yyval.sval) = (yyvsp[0].sval); }
#line 1610 "build/sintatico.tab.c"
    break;


#line 1614 "build/sintatico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 259 "src/sintatico.y"


void yyerror(const char *s) { fprintf(stderr, "\nERRO SINTÁTICO: %s na linha %d, perto do texto '%s'\n", s, yylineno, yytext); exit(1); }

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "ERRO: Argumentos insuficientes.\nUso: %s <arquivo_entrada> <arquivo_saida.c> <arquivo_saida_tokens.txt>\n", argv[0]);
        return 1;
    }
    printf("Arquivo: %s", argv[1]);
    yyin = fopen(argv[1], "r");

    printf("Saida: %s", argv[2]);

    yyoutput = fopen(argv[2], "w");
    fprintf(yyoutput, "#include <stdio.h>\n\n");
    
    printf("Saida tokens: %s", argv[3]);
    saida_tokens = fopen(argv[3], "w");
    
    yyparse();
    
    printf("--- Tradução Finalizada! ---\n");
    
    if(yyin) fclose(yyin);
    if(yyoutput) fclose(yyoutput);
    if(saida_tokens) fclose(saida_tokens);

    return 0;
}
