%{
#include <stdio.h>
#include <string.h>
#include "sintatico.tab.h"

FILE *saida_tokens;

void print_token(const char* type) {
    if (saida_tokens)
        fprintf(saida_tokens, "%s => %s\n", yytext, type);
    else
        fprintf(stdout, "%s -> %s\n", yytext, type);
}

%}

letra         [a-zA-Z]
numero        [0-9]
identificador ({letra}|_)({letra}|{numero}|_)*
num_inteiro   {numero}+
num_real      {numero}+\.{numero}+

%%

\"[^"]*\"     { 
                print_token("Literal String");
                yytext[strlen(yytext) - 1] = '\0'; 
                yylval.sval = strdup(yytext + 1); 
                return T_LITERAL_STRING;
              }

[ \t]+          { /* Ignorado */ }
\n              { yylineno++; }
"//".* { /* Ignora comentários */ }

"real"       { print_token("Palavra Reservada (Tipo)"); return T_INT; }
"inteiro"          { print_token("Palavra Reservada (Tipo)"); return T_FLOAT; }
"string"        { print_token("Palavra Reservada (Tipo)"); return T_CHAR; }
"senao"         { print_token("Palavra Reservada (Condicional)"); return T_SENAO; }
"se"            { print_token("Palavra Reservada (Condicional)"); return T_SE; }
"noh"           { print_token("Palavra Reservada (Laço)"); return T_LACO; }
"antesOuDepois" { print_token("Palavra Reservada (Laço)"); return T_ENQUANTO; }
"playstation"   { print_token("Palavra Reservada (Seleção)"); return T_ESCOLHA; }
"divorcie"      { print_token("Palavra Reservada (Seleção)"); return T_CASO; }
"conserto"      { print_token("Palavra Reservada (Quebra)"); return T_QUEBRA; }
"ficar"         { print_token("Palavra Reservada (Retorno)"); return T_RETORNO; }
"ler"           { print_token("Palavra Reservada (Entrada)"); return T_LEITURA; }
"escrever"      { print_token("Palavra Reservada (Saída)"); return T_ESCRITA; }
"cheio"         { print_token("Palavra Reservada (Tipo)"); return T_VAZIO; }
"tudo"          { print_token("Palavra Reservada (Nulo)"); return T_NULO; }
"indeterminar"  { print_token("Palavra Reservada (Define)"); return T_DEFINE; }
"excluir"       { print_token("Palavra Reservada (Include)"); return T_INCLUDE; }

"="             { print_token("Operador de Atribuicao"); return T_ATR; }
"=="            { print_token("Operador Relacional"); return T_IGUAL; }
"!="            { print_token("Operador Relacional"); return T_DIF; }
">="            { print_token("Operador Relacional"); return T_MAIG; }
"<="            { print_token("Operador Relacional"); return T_MEIG; }
">"             { print_token("Operador Relacional"); return T_MAIOR; }
"<"             { print_token("Operador Relacional"); return T_MENOR; }
"&"             { print_token("Operador Logico"); return T_E; }
"|"             { print_token("Operador Logico"); return T_OU; }
"~"             { print_token("Operador Logico"); return T_NAO; }
"+"             { print_token("Operador Aritmetico"); return T_ADD; }
"-"             { print_token("Operador Aritmetico"); return T_SUB; }
"*"             { print_token("Operador Aritmetico"); return T_MULT; }
"/"             { print_token("Operador Aritmetico"); return T_DIV; }
"%"             { print_token("Operador Aritmetico"); return T_RESTO; }

"."             { print_token("Delimitador"); return T_PONTO; }
","             { print_token("Delimitador"); return T_VIRGULA; }
":"             { print_token("Delimitador"); return T_DOISPONTOS; }
";"             { print_token("Delimitador"); return T_PTVIRG; }
"\""            { print_token("Delimitador"); return T_ASPASDUPLA; }
"("             { print_token("Delimitador"); return T_ABRPAR; }
")"             { print_token("Delimitador"); return T_FEPAR; }
"{"             { print_token("Delimitador"); return T_ABRCHAV; }
"}"             { print_token("Delimitador"); return T_FECHAV; }
"<<"            { print_token("Símbolo Especial (Saída)"); return T_ESQUERDA; }
">>"            { print_token("Símbolo Especial (Entrada)"); return T_DIREITA; }
"#"             { print_token("Símbolo Especial (Diretiva)"); return T_HASH; }

{num_real}      { print_token("Literal Real"); yylval.sval = strdup(yytext); return T_NUMERO_REAL; }
{num_inteiro}   { print_token("Literal Inteiro"); yylval.sval = strdup(yytext); return T_NUMERO_INTEIRO; }
\'[a-zA-Z0-9]\' { print_token("Literal Char"); yylval.sval = strdup(yytext); return T_LITERAL_CHAR; }
{identificador} { print_token("Identificador"); yylval.sval = strdup(yytext); return T_ID; }

.               { fprintf(stderr, "ERRO LEXICO: Caractere '%s' inesperado.\n", yytext); }

%%

int yywrap(void) {
    return 1;
}