
%{
#include <stdio.h>
%}

%%
"hello"     { printf("Pattern found: hello\n"); }
"world"     { printf("Pattern found: world\n"); }
"computer"  { printf("Pattern found: computer\n"); }
.|\n        ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    FILE *fp;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    yyin = fp;
    yylex();

    fclose(fp);
    return 0;
}
