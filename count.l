
%{
#include <stdio.h>

int lines = 0, words = 0, characters = 0;
%}

%%
\n              { lines++; characters++; }
[ \t]+          { characters += yyleng; }
[^ \t\n]+       { words++; characters += yyleng; }
%%

int main()
{
    printf("Enter the text (Ctrl+D to stop):\n");
    yylex();

    printf("\nNumber of lines      = %d", lines);
    printf("\nNumber of words      = %d", words);
    printf("\nNumber of characters = %d\n", characters);

    return 0;
}

int yywrap()
{
    return 1;
}
