@echo off
cd src/
echo "Entrando a src/"

echo "### BISON ###"
bison -d declare_list.y
echo "[FINALIZADO]"

echo ""

echo "### FLEX ###"
flex declare_list.l
echo "[FINALIZADO]"

echo ""

echo "### GCC ###"
gcc -w -o declare_list main.c declare_list.tab.c lex.yy.c -LC:\MinGW\msys\1.0\lib -lfl
echo "[FINALIZADO]"

echo ""

echo "# Moviendo declare_list a bin/..."
move declare_list.exe ../analizadorP4.exe

cd ../

pause
