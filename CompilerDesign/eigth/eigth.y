%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEMP_VARS 100
int yylex(void);
void yyerror(char*);
void Gen(char*);
int labelCounter = 100;
int tempCounter = 1;

typedef struct {
    char expression[50];
    char temp[10];
} TempVar;

// Array to store intermediate expressions and their associated temporary variables
TempVar tempVars[MAX_TEMP_VARS];
int tempVarCount = 0;

int findTemp(char* expr);
int addTemp(char* expr);

%}

%union {
   char *string_value;
}

%token <string_value> ID INTEGER SEMICOLON
%type <string_value> expr stmt_list stmt 

%%

s : stmt_list 

stmt_list : stmt stmt_list { }
          | stmt { }
          ;

stmt : ID '=' expr SEMICOLON
      { 
          // Dead code elimination: Avoid redundant assignments like `x = x`.
          if (strcmp($1, $3) != 0) {
              char tempCode[100];
              sprintf(tempCode, "%s = %s\n", $1, $3);
              Gen(tempCode);
          }
      }
    ;

expr : expr '+' expr
      { 
          char expr[50];
          sprintf(expr, "%s + %s", $1, $3);

          int tempIdx = findTemp(expr);
          if (tempIdx == -1) {
              // If not found, create a new temp variable
              tempIdx = addTemp(expr);
              sprintf(tempVars[tempIdx].temp, "t%d", tempCounter++);
              sprintf(tempVars[tempIdx].expression, "%s", expr);
              
              char tempCode[100];
              sprintf(tempCode, "%s = %s + %s\n", tempVars[tempIdx].temp, $1, $3);
              Gen(tempCode);
          }

          $$ = tempVars[tempIdx].temp;
      }
    | expr '*' expr
      {
          char expr[50];
          sprintf(expr, "%s * %s", $1, $3);

          int tempIdx = findTemp(expr);
          if (tempIdx == -1) {
              // If not found, create a new temp variable
              tempIdx = addTemp(expr);
              sprintf(tempVars[tempIdx].temp, "t%d", tempCounter++);
              sprintf(tempVars[tempIdx].expression, "%s", expr);
              
              char tempCode[100];
              sprintf(tempCode, "%s = %s * %s\n", tempVars[tempIdx].temp, $1, $3);
              Gen(tempCode);
          }

          $$ = tempVars[tempIdx].temp;
      }
    | INTEGER
      {
          $$ = $1;
      }
    | ID
      {
          $$ = $1;
      }
    ;

%%

// Check if expression already exists in tempVars array
int findTemp(char* expr) {
    for (int i = 0; i < tempVarCount; i++) {
        if (strcmp(tempVars[i].expression, expr) == 0) {
            return i;
        }
    }
    return -1;
}

// Add a new temporary variable for a new expression
int addTemp(char* expr) {
    if (tempVarCount < MAX_TEMP_VARS) {
        strcpy(tempVars[tempVarCount].expression, expr);
        return tempVarCount++;
    } else {
        yyerror("Temporary variable limit exceeded.");
        exit(1);
    }
}

void Gen(char *val) {
    FILE *f = fopen("optimized_output.txt", "a");
    fputs(val, f);
    fclose(f);
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char **argv) {
    yyparse();
    return 1;
}
int yywrap() { return 1; }
