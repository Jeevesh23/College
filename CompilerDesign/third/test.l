%{
#include "test.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%
[ \t\n]+          ;
"for"            { return FOR; }
"while"          {return WHILE;}	
"("              { return LPAREN; }
")"              { return RPAREN; }
"{"              { return LBRACE; }
"}"              { return RBRACE; }
"int"|"char"     {return datatype;}
";"              { return SEMICOLON; }
[0-9]+           { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }
"="              { return ASSIGN; }
"=="             { return EQ; }
"!="             { return NEQ; }
"<"              { return LT; }
"<="             { return LE; }
">"              { return GT; }
">="             { return GE; }
"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return MUL; }
"/"              { return DIV; }
"++"             { return INCREMENT; }
"--"             { return DECREMENT; }
.                { }
%%


int yywrap()
{
return 1;
}

