%{
	#include <stdio.h>
	#include <string.h>
	#include <malloc.h>
	#include "declare_list.tab.h"
	extern int lines=0;

	extern char *stToken[1024];
	extern char *stValue[1024];
	extern int stID = 0;
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
	addSymbol("T_DOUBLE_ARROW");
	return T_DOUBLE_ARROW;
}

"="|","|"("|")"|"?"|":" {
	addSymbol("T_CHAR");
	return yytext[0];
}

"+"|"-"|"\*"|"\/"|"\["|"\]"|"\&"|"\|"|"\^"|"\."|"\<"|"\>" {
	addSymbol("T_CHAR");
	return yytext[0];
}

{WHITESPACE} {
	addSymbol("WHITESPACE");
}

{NEWLINE} {
	++lines;
}

";" {
	addSymbol("T_END");
	return T_END;
}

"namespace" {
	addSymbol("T_NAMESPACE");
	return T_NAMESPACE;
}

"\\" {
	addSymbol("T_NS_SEPARATOR");
	return T_NS_SEPARATOR;
}

"array" {
	addSymbol("T_ARRAY");
	return T_ARRAY;
}

"class" {
	addSymbol("T_CLASS");
	return T_CLASS;
}

"static" {
	addSymbol("T_STATIC");
	return T_STATIC;
}

"__CLASS__" {
	addSymbol("T_CLASS_C");
	return T_CLASS_C;
}

"__TRAIT__" {
	addSymbol("T_TRAIT_C");
	return T_TRAIT_C;
}

"__FUNCTION__" {
	addSymbol("T_FUNC_C");
	return T_FUNC_C;
}

"__METHOD__" {
	addSymbol("T_METHOD_C");
	return T_METHOD_C;
}

"__LINE__" {
	addSymbol("T_LINE");
	return T_LINE;
}

"__FILE__" {
	addSymbol("T_FILE");
	return T_FILE;
}

"__DIR__" {
	addSymbol("T_DIR");
	return T_DIR;
}

"__NAMESPACE__" {
	addSymbol("T_NS_C");
	return T_NS_C;
}

"::" {
	addSymbol("T_DTWO_POINTS");
	return T_DTWO_POINTS;
}

"||" {
	addSymbol("T_BOOLEAN_OR ");
	
	return T_BOOLEAN_OR;
}

"&&" {
	addSymbol("T_BOOLEAN_AND ");
	
	return T_BOOLEAN_AND;
}

"OR" {
	addSymbol("T_LOGICAL_OR ");
	
	return T_LOGICAL_OR;
}

"AND" {
	addSymbol("T_LOGICAL_AND ");
	
	return T_LOGICAL_AND;
}

"XOR" {
	addSymbol("T_LOGICAL_XOR");
	
	return T_LOGICAL_XOR;
}

"<<" {
	addSymbol("T_SL");
	return T_SL;
}

">>" {
	addSymbol("T_SR");
	return T_SR;
}

"===" {
	addSymbol("T_IS_IDENTICAL");
	return T_IS_IDENTICAL;
}

"!==" {
	addSymbol("T_IS_NOT_IDENTICAL");
	return T_IS_NOT_IDENTICAL;
}

"==" {
	addSymbol("T_IS_EQUAL");
	return T_IS_EQUAL;
}

"!="|"<>" {
	addSymbol("T_IS_NOT_EQUAL");
	return T_IS_NOT_EQUAL;
}

"<=" {
	addSymbol("T_IS_SMALLER_OR_EQUAL");
	return T_IS_SMALLER_OR_EQUAL;
}

">=" {
	addSymbol("T_IS_GREATER_OR_EQUAL");
	return T_IS_GREATER_OR_EQUAL;
}

"*\*" {
	addSymbol("T_POW");
	return T_POW;
}

b?['] {
	addSymbol("T_CONSTANT_ENCAPSED_STRING");
	return T_CONSTANT_ENCAPSED_STRING;
}


b?["\""] {
	addSymbol("T_CONSTANT_ENCAPSED_STRING");
	return T_CONSTANT_ENCAPSED_STRING;
}

b?"<<<"{TABS_AND_SPACES}({LABEL}|([']{LABEL}['])|(["]{LABEL}["])){NEWLINE} {
	return T_START_HEREDOC;
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

