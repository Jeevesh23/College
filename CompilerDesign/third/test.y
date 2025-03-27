 %{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
void yyerror(const char *s);
%}

%token FOR LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token ASSIGN NUMBER IDENTIFIER datatype WHILE
%token EQ NEQ LT LE GT GE
%token PLUS MINUS MUL DIV INCREMENT DECREMENT

%%

program:
    for_loop
    {
        printf("The for loop is valid.\n");
    }
    |while_loop
    {
        printf("The while loop is valid.\n");
    }
    ;

for_loop:
    FOR LPAREN init SEMICOLON condition SEMICOLON increment RPAREN LBRACE stmt_list RBRACE
    ;
while_loop:WHILE LPAREN condition RPAREN LBRACE stmt_list RBRACE
init:
    DATATYPE IDENTIFIER ASSIGN NUMBER
    ;
DATATYPE : datatype;
condition:
    IDENTIFIER LT NUMBER
    | IDENTIFIER LE NUMBER
    | IDENTIFIER GT NUMBER
    | IDENTIFIER GE NUMBER
    ;

increment:
    IDENTIFIER INCREMENT
    ;

stmt_list:
    | stmt_list stmt
    ;

stmt:
    DATATYPE IDENTIFIER ASSIGN NUMBER SEMICOLON
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed.\n");
    }
    return 0;
}

