%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.tab.h"

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
[\n]				{return '\n';}
[ \t]				{}
[a-zA-Z_][a-zA-Z0-9_]* { yylval.string_value = strdup(yytext); return IDENTIFIER; }
.                   { printf("Unexpected character: %s\n", yytext); }
%%
int yywrap() { return 1; }
