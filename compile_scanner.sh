#!/bin/sh
cd src/
flex declare_list.l
gcc -o declare_list_scanner lex.yy.c -lfl
mv declare_list_scanner ../bin/
