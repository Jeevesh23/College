%{
    #include "exp5.tab.h"
    void yyerror(char*);

%}

alpha [a-zA-Z_]
digit [0-9]

%%

"for"                          {return FOR;}
"while"                        {return WHILE;}
"if"                           {return IF;}
{alpha}({alpha}|{digit})*      {return ID;}
{digit}+                       {return NUM;}
">="|"<="|"<"|">"              {return RELOP;}
[\;(){}+-=]                    {return yytext[0];}
[ \t\n]                        ;
.                              {yyerror(yytext);}

%% 

int yywrap(void)
{
    return 1;
}

/*    for(i=0 ; i<=2 ; i++){if(i>=2) i = i + 3;while(y>=10); y = y+4;}  */