%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.tab.h"

%}

%%

"char"              { return CHAR; }
"int"               { return INT; }
"float"             { return FLOAT; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
"/"                 { return '/'; }
"="                 { return '='; }
","                 { return ','; }
"("                 { return '('; }
")"                 { return ')'; }
";"                 { return ';'; }
[ \t\n]+            { /* Ignore whitespace */ }
[0-9]+              { yylval.num_value = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.string_value = strdup(yytext); return IDENTIFIER; }
.                   { printf("Unexpected character: %s\n", yytext); }

%%
int yywrap() { return 1; }
