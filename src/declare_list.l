%{
	#include <stdio.h>
	#include <string.h>
	#include <malloc.h>
	#include "declare_list.tab.h"
	extern int lines=0;

	extern char *stToken[1024];
	extern char *stValue[1024];
	extern int stID = 0;
	extern addE(char *e);
%}

letter							[a-zA-Z]
digit							[0-9]
LABEL							({letter}|"_")({letter}|{digit}|"_")*
octal							"0"[0-7]*
decimal 						[1-9]{digit}*
hexdigit						{digit}|[a-f]|[A-F]
hexadecimal						"0x"{hexdigit}+
LNUM 							{octal}|{decimal}|{hexadecimal}
DNUM							{digit}*"."{digit}+|{digit}+"."{digit}*
EXPONENT_DNUM					({LNUM}|{DNUM})[eE][+-]?{LNUM}
SIMPLE_QUOTED_STRING 			\'([^\\\"]|\\.)*\'
DOUBLE_QUOTED_STRING 			\"([^\\\"]|\\.)*\"
WHITESPACE 						[ \r\t]+
TABS_AND_SPACES 				[ \t]*
NEWLINE 						("\r"|"\n"|"\r\n")

%%

"=>" {
	addSymbol("T_DOUBLE_ARROW");
	
	return T_DOUBLE_ARROW;
}

"," {
	addSymbol("T_CHAR");
	return yytext[0];
}

"="|"("|")" {
	addSymbol("T_CHAR");
	
	return yytext[0];
}

"+"|"-" {
	addSymbol("T_CHAR");
	
	return yytext[0];
}

{WHITESPACE} {
	addSymbol("WHITESPACE");
	
}

{NEWLINE} {
	if(yyin == stdin) {
		return T_END;
	}
	else {
		++lines;
	}
}

"array" {
	addSymbol("T_ARRAY");
	
	return T_ARRAY;
}

"__CLASS__" {
	addSymbol("T_CLASS_C");
	
	return T_CLASS;
}

"__FUNCTION__" {
	addSymbol("T_FUNC");
	
	return T_FUNC;
}

"__METHOD__" {
	addSymbol("T_METHOD");
	
	return T_METHOD;
}

"__LINE__" {
	addSymbol("T_LINE");
	
	return T_LINE;
}

"__FILE__" {
	addSymbol("T_FILE");
	
	return T_FILE;
}

"::" {
	addSymbol("T_DOUBLE_TWO_POINTS");
	
	return T_DOUBLE_TWO_POINTS;
}

{SIMPLE_QUOTED_STRING}|{DOUBLE_QUOTED_STRING} {
	addSymbol("T_CONSTANT_ENCAPSED_STRING");
	
	return T_CONSTANT_ENCAPSED_STRING;
}

{LNUM} {
	addSymbol("T_LNUMBER");
	
	return T_LNUMBER;
}

{DNUM}|{EXPONENT_DNUM} {
	addSymbol("T_DNUMBER");
	
	return T_DNUMBER;
}

{LABEL} {
	addSymbol("T_STRING");
	
	return T_STRING; 
}

. {
	char *lexical_error;
	lexical_error = (char *) malloc(strlen("Error lexico. Simbolo no reconocido: ") + strlen(yytext) + 1);
	strcpy(lexical_error, "Error lexico. Simbolo no reconocido: ");
	strcat(lexical_error, yytext);
	addE(lexical_error);
	addSymbol("¡ERROR!");
}

<<EOF>> {
	return T_END;
}

%%

void addSymbol(char *tok) {
	stToken[stID] = (char*) malloc(strlen(tok) + 1);
	stValue[stID] = (char*) malloc(strlen(yytext) + 1);
	strcpy(stToken[stID], tok);
	strcpy(stValue[stID], yytext);
	stID++;
}

