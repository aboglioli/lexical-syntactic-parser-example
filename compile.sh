#!/bin/sh
cd src/

echo "### BISON COMPILE ###"
bison -d declare_list.y
echo "[FINISHED]"

echo ""

echo "### FLEX COMPILE ###"
flex declare_list.l
echo "[FINISHED]"

echo ""

echo "### declare_list COMPILE ###"
gcc -o declare_list declare_list.tab.c lex.yy.c -lfl
echo "[FINISHED]"

echo ""

echo "# Moving declare_list to bin/..."
mv declare_list ../bin/
