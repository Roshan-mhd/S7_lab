running command :

yacc -d valid.y

lex valid.l

gcc lex.yy.c y.tab.c -o valid -ll

./valid
