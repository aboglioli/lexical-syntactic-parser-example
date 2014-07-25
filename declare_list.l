%{
	#include <stdio.h>
	#include <string.h>
	#include <malloc.h>
	#include "test.tab.h"
	int linea=0;
%}

LNUM			[0-9]+
DNUM			([0-9]*"."[0-9]+)|([0-9]+"."[0-9]*)
EXPONENT_DNUM	(({LNUM}|{DNUM})[eE][+-]?{LNUM})
HNUM			"0x"[0-9a-fA-F]+
BNUM			"0b"[01]+
LABEL			[a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*
WHITESPACE		[ \n\r\t]+
TABS_AND_SPACES [ \t]*
TOKENS			[;:,.\[\]()|^&+-/*=%!~$<>?@]
ANY_CHAR		[^]
NEWLINE			("\r"|"\n"|"\r\n")

%%
{LABEL}					{ yylval.texto = (char*) malloc(strlen(yytext) + 1);
						strcpy(yylval.texto, yytext);
						return T_STRING; }

{CADENA}				{ yylval.texto = (char*) malloc(strlen(yytext) + 1);	
						strcpy(yylval.texto, yytext);
						return T_STRING; }

"="                     { yylval.caracter = yytext[0]; 
						return IGUAL; }

\n						{ linea++; 
						return RETORNO; }

[ \t]					;

<<EOF>>					{ printf("%d lineas escaneadas\n", linea); return 0; }

.						{ printf("Token no reconocido: %s\n", yytext); }

%%

