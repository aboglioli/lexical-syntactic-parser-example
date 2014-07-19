%{
	#include <stdio.h>
	#include <string.h>
	#include <malloc.h>
	#include "test.tab.h"
	int linea=0;
%}

DIGITO		[0-9]
NUMERO		{DIGITO}+("."{DIGITO}+)?
CARACTER	[a-zA-Z]
CADENA		({CARACTER}|{NUMERO}|"_")+

%%
{NUMERO}				{
						printf("numero");
						return T_STRING; }

{CADENA}				{
						printf("cadena");
						return T_STRING; }

"="						{
						return yytext[0];
}

\n						{ linea++; 
						printf("retorno");
						return RETORNO; }

[ \t]					;

<<EOF>>					{ printf("%d lineas escaneadas\n", linea); return 0; }

%%

