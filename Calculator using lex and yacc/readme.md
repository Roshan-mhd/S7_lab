running command:

yacc -d calc.y
lex calc.l
gcc y.tab.c lex.yy.c -o calc -ll
./calc
