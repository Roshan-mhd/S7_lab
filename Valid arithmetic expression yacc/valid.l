
%{
#include "y.tab.h"
%}

%%
[0-9]+      { return NUMBER; }
[+\-*/]     { return yytext[0]; }
[(]         { return '('; }
[)]         { return ')'; }
[ \t\n]     ;
.           { return INVALID; }
%%

int yywrap()
{
    return 1;
}

