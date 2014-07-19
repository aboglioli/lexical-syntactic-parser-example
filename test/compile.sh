#!/bin/sh
bison -d test.y
flex test.l
gcc -o test test.tab.c lex.yy.c -lfl
