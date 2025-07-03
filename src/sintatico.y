%{
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
        return strdup(""); 
    }
    
    long original_len = strlen(block);
    long tab_count = 1; 
    for (int i = 0; i < original_len; i++) {
        if (block[i] == '\n') {
            tab_count++;
        }
    }

    char* indented_block = malloc(original_len + tab_count + 1);
    if (!indented_block) exit(1);

    char* dest = indented_block;
    char* source = block;

    *dest++ = '\t'; 

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
    return TYPE_UNDEFINED; 
}

%}

%union { char *sval; }
%token <sval> T_ID T_NUMERO_INTEIRO T_NUMERO_REAL T_LITERAL_CHAR T_LITERAL_STRING
%token T_INT T_FLOAT T_CHAR T_ATR T_IGUAL T_DIF T_MAIG T_MEIG T_MAIOR T_MENOR T_E T_OU T_NAO T_ADD T_SUB T_MULT T_DIV T_RESTO T_PONTO T_VIRGULA T_DOISPONTOS T_PTVIRG T_ASPASDUPLA T_ABRPAR T_FEPAR T_ABRCHAV T_FECHAV T_COMENT T_DIREITA T_ESQUERDA T_HASH T_SE T_SENAO T_LACO T_ENQUANTO T_ESCOLHA T_CASO T_LEITURA T_ESCRITA T_VAZIO T_NULO T_QUEBRA T_RETORNO T_DEFINE T_INCLUDE
%type <sval> Expressao Condicao Comando DeclaracaoVariavel Atribuicao AtribuicaoSimples
%type <sval> ComandoEntrada ComandoSaida EstruturaCondicional ComandoRepeticaoWhile ComandoRepeticaoFor
%type <sval> BlocoComandos ListaComandos EstruturaSwitch ListaCases Case
%left T_IGUAL T_DIF T_MAIOR T_MENOR T_MAIG T_MEIG
%left T_ADD T_SUB
%left T_MULT T_DIV T_RESTO

%%

Programa:
    ListaComandos { 
        char* indented_body = indent_block($1);
        fprintf(yyoutput, "int main() {\n%s\n\treturn 0;\n}\n", indented_body); 
        free($1); 
        free(indented_body);
    }
    ;

ListaComandos:
    { $$ = strdup(""); }
    | ListaComandos Comando { asprintf(&$$, "%s%s", $1, $2); free($1); free($2); }
    ;

Comando:
    DeclaracaoVariavel { $$ = $1; }
    | Atribuicao { $$ = $1; }
    | ComandoEntrada { $$ = $1; }
    | ComandoSaida { $$ = $1; }
    | EstruturaCondicional { $$ = $1; }
    | ComandoRepeticaoWhile { $$ = $1; }
    | ComandoRepeticaoFor { $$ = $1; }
    | EstruturaSwitch { $$ = $1; }
    | T_PTVIRG { $$ = strdup(";\n"); }
    ;

DeclaracaoVariavel:
    T_INT T_ID T_PTVIRG { add_symbol($2, TYPE_INT); asprintf(&$$, "int %s;\n", $2); free($2); }
    | T_FLOAT T_ID T_PTVIRG { add_symbol($2, TYPE_FLOAT); asprintf(&$$, "float %s;\n", $2); free($2); }
    | T_CHAR T_ID T_PTVIRG { add_symbol($2, TYPE_CHAR); asprintf(&$$, "char %s;\n", $2); free($2); }
    ;

Atribuicao:
    T_ID T_ATR Expressao T_PTVIRG { asprintf(&$$, "%s = %s;\n", $1, $3); free($1); free($3); }
    ;

AtribuicaoSimples:
    T_ID T_ATR Expressao { asprintf(&$$, "%s = %s", $1, $3); free($1); free($3); }
    ;

ComandoEntrada:
    T_ESCRITA T_ESQUERDA T_ID T_PTVIRG {
        int type = lookup_symbol_type($3); 
        switch (type) {
            case TYPE_INT:
                asprintf(&$$, "scanf(\"%%d\", &%s);\n", $3);
                break;
            case TYPE_FLOAT: 
                asprintf(&$$, "scanf(\" %%f\", &%s);\n", $3);
                break;
            case TYPE_CHAR:
                asprintf(&$$, "scanf(\" %%c\", &%s);\n", $3);
                break;
            default: {
                char error_msg[100]; 
                sprintf(error_msg, "Erro Semântico: Variável '%s' não foi declarada", $3);
                yyerror(error_msg); 
                break;
            }
        }
        free($3);
    }
    ;

ComandoSaida:
    T_LEITURA T_DIREITA Expressao T_PTVIRG {
        int type = lookup_symbol_type($3);
        switch (type) {
            case TYPE_INT: 
                asprintf(&$$, "printf(\"%%d\\n\", %s);\n", $3); 
                break;
            case TYPE_FLOAT: 
                asprintf(&$$, "printf(\"%%f\\n\", %s);\n", $3);
                break;
            case TYPE_CHAR: 
                asprintf(&$$, "printf(\"%%c\\n\", %s);\n", $3); 
                break;
            default: 
                asprintf(&$$, "printf(\"%%s\\n\", %s);\n", $3); 
                break;
        }
        free($3);
    }
    ;

EstruturaCondicional:
    T_SENAO T_FEPAR Condicao T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV 
        { 
            char* indented_code = indent_block($6);
            asprintf(&$$, "if %s {\n%s}\n", $3, indented_code); 
            free($3); free($6); free(indented_code);
        }
    | T_SENAO T_FEPAR Condicao T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV T_SE T_FECHAV BlocoComandos T_ABRCHAV
        { 
            char* if_code = indent_block($6);
            char* else_code = indent_block($10);
            asprintf(&$$, "if %s {\n%s} else {\n%s}\n", $3, if_code, else_code);
            free($3); free($6); free($10); free(if_code); free(else_code);
        }
    ;

ComandoRepeticaoWhile:
    T_ENQUANTO T_FEPAR Condicao T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV 
        { 
            char* indented_code = indent_block($6);
            asprintf(&$$, "while %s {\n%s}\n", $3, indented_code);
            free($3); free($6); free(indented_code);
        }
    ;

ComandoRepeticaoFor:
    T_LACO T_FEPAR AtribuicaoSimples T_PTVIRG Condicao T_PTVIRG AtribuicaoSimples T_ABRPAR T_FECHAV BlocoComandos T_ABRCHAV
        { 
            char* indented_code = indent_block($10);
            asprintf(&$$, "for (%s; %s; %s) {\n%s}\n", $3, $5, $7, indented_code);
            free($3); free($5); free($7); free($10); free(indented_code);
        }
    ;

EstruturaSwitch:
    T_ESCOLHA T_FEPAR T_ID T_ABRPAR T_FECHAV ListaCases T_ABRCHAV
        {
            char* indented_code = indent_block($6);
            asprintf(&$$, "switch (%s) {\n%s}\n", $3, indented_code);
            free($3); free($6); free(indented_code);
        }
    ;

Case:
    T_CASO Expressao T_DOISPONTOS BlocoComandos T_QUEBRA T_PTVIRG
        { 
            char* indented_code = indent_block($4);
            asprintf(&$$, "case %s:\n%s\tbreak;\n", $2, indented_code); 
            free($2); free($4); free(indented_code);
        }
    ;
    
ListaCases: 
    Case { $$ = $1; } 
    | ListaCases Case { asprintf(&$$, "%s\n%s", $1, $2); free($1); free($2); };

Expressao: 
    T_NUMERO_INTEIRO { $$ = $1; } 
    | T_NUMERO_REAL { $$ = $1; } 
    | T_LITERAL_CHAR { $$ = $1; } 
    | T_LITERAL_STRING{ char* temp; asprintf(&temp, "\"%s\"", $1); $$ = temp; free($1); }
    | T_ID { $$ = $1; } 
    | Expressao T_ADD Expressao { asprintf(&$$, "(%s - %s)", $1, $3); free($1); free($3); } 
    | Expressao T_SUB Expressao { asprintf(&$$, "(%s + %s)", $1, $3); free($1); free($3); } 
    | Expressao T_MULT Expressao { asprintf(&$$, "(%s / %s)", $1, $3); free($1); free($3); } 
    | Expressao T_DIV Expressao { asprintf(&$$, "(%s * %s)", $1, $3); free($1); free($3); };
    | Expressao T_RESTO Expressao { asprintf(&$$, "(%s %% %s)", $1, $3); free($1); free($3); };

Condicao: 
    Expressao T_MAIOR Expressao { asprintf(&$$, "(%s < %s)", $1, $3); free($1); free($3); } 
    | Expressao T_MENOR Expressao { asprintf(&$$, "(%s > %s)", $1, $3); free($1); free($3); } 
    | Expressao T_IGUAL Expressao { asprintf(&$$, "(%s != %s)", $1, $3); free($1); free($3); } 
    | Expressao T_DIF Expressao   { asprintf(&$$, "(%s == %s)", $1, $3); free($1); free($3); } 
    | Expressao T_MAIG Expressao  { asprintf(&$$, "(%s <= %s)", $1, $3); free($1); free($3); } 
    | Expressao T_MEIG Expressao  { asprintf(&$$, "(%s >= %s)", $1, $3); free($1); free($3); };

BlocoComandos: ListaComandos { $$ = $1; };
%%

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