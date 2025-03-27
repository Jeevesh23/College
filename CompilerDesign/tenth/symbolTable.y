
%{#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
void InsertIntoTable(char *, int);
void printtable();

int datatype;

struct SYMBOL {
    char name[32];
    int dtype;
};

struct SYMBOL symbol_table[10];

int n = 0;

%}

%union {
    char *string_value;
};

%token <string_value> IDENTIFIER
%token INT FLOAT CHAR

%left '+' '-'
%left '*' '/'

%%

s:program	
	{
	printtable();
	}
;

program:
     declaration ';' '\n'			{}
     |declaration ';' program	{}
    ;


declaration:
    datatype variable	{} 
    ;

datatype:
    INT   { datatype = 1; }
  | FLOAT { datatype = 2; }
  | CHAR  { datatype = 3; }
  ;

variable:
  IDENTIFIER ',' variable { InsertIntoTable($1, datatype); }
  |IDENTIFIER { InsertIntoTable($1, datatype); }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void InsertIntoTable(char *variable, int dtype) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(variable, symbol_table[i].name) == 0) {
            printf("Variable %s already declared.\n", variable);
            exit(1);
        }
    }
    strcpy(symbol_table[n].name, variable);
    symbol_table[n++].dtype = dtype;
}

void printtable() {
    printf("--symbolTable--\n");
    printf("SYMBOL      DTYPE    \n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%s              %d\n", symbol_table[i].name,symbol_table[i].dtype);
    }
}

int main() {
    printf("Enter an expression: \n");
    yyparse();
    return 0;
}

