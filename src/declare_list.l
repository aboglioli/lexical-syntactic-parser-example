%{
	#include <stdio.h>
	#include <string.h>
	#include <malloc.h>
	#include "declare_list.tab.h"
	extern int lines=0;
%}

LNUM	[0-9]+
DNUM	([0-9]*"."[0-9]+)|([0-9]+"."[0-9]*)
EXPONENT_DNUM	(({LNUM}|{DNUM})[eE][+-]?{LNUM})
HNUM	"0x"[0-9a-fA-F]+
BNUM	"0b"[01]+
LABEL	[a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*
WHITESPACE [ \r\t]+
TABS_AND_SPACES [ \t]*
NEWLINE ("\r"|"\n"|"\r\n")

%%

"=>" {
	//printf("T_DOUBLE_ARROW ");
	return T_DOUBLE_ARROW;
}

"="|","|"("|")"|"?"|":" {
	//printf("%c ", yytext[0]);
	return yytext[0];
}

"+"|"-"|"\*"|"\/"|"\["|"\]"|"\&"|"\|"|"\^"|"\."|"\<"|"\>" {
	//printf("%c ", yytext[0]);
	return yytext[0];
}

{WHITESPACE} {
	////printf("WHITESPACE ");
}

{NEWLINE} {
	++lines;
	////printf("\nLinea %d: ", lines);
	////printf("\n");
	//return '\n';
}

"namespace" {
	//printf("T_NAMESPACE ");
	return T_NAMESPACE;
}

"\\" {
	//printf("T_NS_SEPARATOR ");
	return T_NS_SEPARATOR;
}

"array" {
	//printf("T_ARRAY");
	return T_ARRAY;
}

"class" {
	//printf("T_CLASS ");
	return T_CLASS;
}

"static" {
	//printf("T_STATIC ");
	return T_STATIC;
}

"__CLASS__" {
	return T_CLASS_C;
}

"__TRAIT__" {
	return T_TRAIT_C;
}

"__FUNCTION__" {
	return T_FUNC_C;
}

"__METHOD__" {
	return T_METHOD_C;
}

"__LINE__" {
	return T_LINE;
}

"__FILE__" {
	return T_FILE;
}

"__DIR__" {
	return T_DIR;
}

"__NAMESPACE__" {
	return T_NS_C;
}

"::" {
	return T_DTWO_POINTS;
}

#FIXME
"end_heredoc" {
	
	return T_END_HEREDOC;
}

"||" {
	//printf("T_BOOLEAN_OR ");
	return T_BOOLEAN_OR;
}

"&&" {
	//printf("T_BOOLEAN_AND ");
	return T_BOOLEAN_AND;
}

"OR" {
	//printf("T_LOGICAL_OR ");
	return T_LOGICAL_OR;
}

"AND" {
	//printf("T_LOCAL_AND ");
	return T_LOGICAL_AND;
}

"XOR" {
	//printf("XOR ");
	return T_LOGICAL_XOR;
}

"<<" {
	return T_SL;
}

">>" {
	return T_SR;
}

"===" {
	return T_IS_IDENTICAL;
}

"!==" {
	return T_IS_NOT_IDENTICAL;
}

"==" {
	return T_IS_EQUAL;
}

"!="|"<>" {
	return T_IS_NOT_EQUAL;
}

"<=" {
	return T_IS_SMALLER_OR_EQUAL;
}

">=" {
	return T_IS_GREATER_OR_EQUAL;
}

"*\*" {
	return T_POW;
}

b?['] {
	//printf("T_CONSTANT_ENCAPSED_STRING ");
	return T_CONSTANT_ENCAPSED_STRING;
}


b?["\""] {
	//printf("T_CONSTANT_ENCAPSED_STRING ");
	return T_CONSTANT_ENCAPSED_STRING;
}

b?"<<<"{TABS_AND_SPACES}({LABEL}|([']{LABEL}['])|(["]{LABEL}["])){NEWLINE} {
	return T_START_HEREDOC;
}

{LNUM} {
	//printf("T_LNUMBER ");
	yylval.text = (char*) malloc(strlen(yytext) + 1);
	strcpy(yylval.text, yytext);
	return T_LNUMBER;
}

{DNUM}|{EXPONENT_DNUM} {
	//printf("T_DNUMBER ");
	return T_DNUMBER;
}

{LABEL} {	
	//printf("T_STRING ");
	yylval.text = (char*) malloc(strlen(yytext) + 1);
	strcpy(yylval.text, yytext);
	return T_STRING; 
}

<<EOF>> {
	return 0;
}

%%

