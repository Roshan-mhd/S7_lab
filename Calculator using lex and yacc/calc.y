
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *s);
%}

%union {
    double num;
}

%token <num> NUMBER
%token INVALID
%type <num> expr

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

expr:
      expr '+' expr  { $$ = $1 + $3; }
    | expr '-' expr  { $$ = $1 - $3; }
    | expr '*' expr  { $$ = $1 * $3; }
    | expr '/' expr  {
          if ($3 == 0) {
              printf("Division by zero!\n");
              YYERROR;
          }
          $$ = $1 / $3;
      }
    | '(' expr ')'   { $$ = $2; }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | NUMBER         { $$ = $1; }
    ;

%%

int main()
{
    printf("Enter an arithmetic expression: ");

    if (yyparse() == 0)
        printf("Result = %.2f\n", yylval.num);

    return 0;
}

int yyerror(char *s)
{
    printf("Invalid expression!\n");
    return 0;
}
