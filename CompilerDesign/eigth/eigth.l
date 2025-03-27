%{
#include "eigth.tab.h" 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
%}

%%

[\t ]+                      /* ignore blank spaces */ ;
\n                          /* ignore newline characters */;
";"                         { return SEMICOLON; }
[0-9]+                      { yylval.string_value = strdup(yytext); return INTEGER; }
[a-zA-Z][a-zA-Z0-9]*        { yylval.string_value = strdup(yytext); return ID; }
[-+*=/]                     { return *yytext; }

%%

