%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
void InsertIntoTable(char *, int);
void CHECK(char *);

typedef struct {
    char *string_value;
    int num_value;
} YYSTYPE;

#define YYSTYPE_IS_DECLARED 1

int datatype;

struct SYMBOL {
    char name[32];
    int dtype;
};
struct SYMBOL symbol_table[10];
int n = 0;

%}

%union {
    int num_value;
    char *string_value;
}

%token <num_value> NUMBER
%token <string_value> IDENTIFIER
%token INT FLOAT CHAR

%left '+' '-'
%left '*' '/'

%%

program:
    declaration assignment		{printf("valid expression")}
	;

declaration:
    datatype variable ';';

datatype:
      INT   { datatype = 1; }
    | FLOAT { datatype = 2; }
    | CHAR  { datatype = 3; };

variable:
      IDENTIFIER ',' variable { InsertIntoTable($1, datatype); }
    | IDENTIFIER             { InsertIntoTable($1, datatype); };

assignment:
    IDENTIFIER '=' expr ';';

expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUMBER
    | IDENTIFIER { CHECK($1); };

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void InsertIntoTable(char *variable, int dtype) {
    for (int i = 0; i < n; i++) {
        if (strcmp(variable, symbol_table[i].name) == 0) {
            printf("Variable already declared\n");
            exit(0);
        }
    }
    strcpy(symbol_table[n].name, variable);
    symbol_table[n++].dtype = dtype;
}

void CHECK(char *variable) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(symbol_table[i].name, variable) == 0) {
            if (symbol_table[i].dtype == 3) {
                printf("Non-numeric datatype\n");
                exit(0);
            }
            break;
        }
    }
    if (i < n) {
        printf("Valid Expression\n");
    } else {
        printf("Variable not declared\n");
        exit(0);
    }
}

int main() {
    printf("Enter an expression: \n");
    yyparse();
    return 0;
}
