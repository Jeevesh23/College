%{
#include <stdio.h>
%}

%%

[0-9]+          			{ printf("Integer: %s\n", yytext); }
\".*\"          			{ printf("String: %s\n", yytext); }
\'[A-Za-z]\'          		{ printf("Charecter : %s\n", yytext); }
[0-9]*\.[0-9]+  			{ printf("Float: %s\n", yytext); }

char|int|float|double|void|boolean   	{ printf("Datatype: %s\n", yytext); }

if|else|switch|"else if"    { printf("Conditional Statement : %s\n",yytext);}
for|while|do    			{ printf("Loops: %s\n", yytext); }

\*|\+|\-|\/					{ printf("Arithmetic Operator: %s\n", yytext);}
==|<=|>=|<|>    			{ printf("Comparison Operator: %s\n", yytext); }
=               			{ printf("Assignment Operator: %s\n", yytext); }
	
case				        { printf("Case Statement : %s\n", yytext);}
return						{ printf("Return Statement : %s\n", yytext);}
break						{ printf("Break Statement : %s\n", yytext);}
exit						{ printf("Exit Statement : %s\n", yytext);}

[_a-zA-Z][_a-zA-Z0-9]* 		{ printf("Identifier : %s\n", yytext); }

\(|\{|\[           			{ printf("Opening Bracket : %s\n", yytext);}  
\)|\}|\]           			{ printf("Closing Bracket : %s\n", yytext);}  

;							{ printf("Statemetn Terminator : %s\n", yytext);}
\\n 						{ printf("Newline : %s\n", yytext);}
\\t 						{ printf("Horizontal End : %s\n", yytext);}

&|\|						{ printf("Bitwise Operator : %s\n", yytext);}
&&|\|\|						{ printf("Logical Operator : %s\n", yytext);}

.							{ printf("Invalid Token\n");}


%%
int main() {
	printf("Enter the expression - \n");
    yylex();
    return 0;
}

int yywrap(){return 1;}
