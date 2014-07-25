%{
	#include <stdio.h>
	int yylex();
	int yyparse();
	FILE *yyin;
	FILE *yyout;
	int lines;

	char *stToken[1024];
	char *stValue[1024];
	int stID ;

	struct s_treeLevel;
	struct s_token {
		char *name;
		int no_terminal;
		int level_ref;
	};
	struct s_treeLevel {
		int level;
		int cant_tokens;
		struct s_token token[128];
	} treeLevel[1024];
	int tLevel = 0;
	int tID = 0;
%}

%union {
	int val;
	float f;
	char *text;
};

%token <text> T_STRING
%token <text> T_RET
%token <text> T_NAMESPACE
%token <text> T_NS_SEPARATOR
%token <text> T_ARRAY
%token <text> T_CLASS
%token <text> T_CLASS_C
%token <text> T_TRAIT_C
%token <text> T_FUNC_C
%token <text> T_METHOD_C
%token <text> T_LINE
%token <text> T_FILE
%token <text> T_DIR
%token <text> T_NS_C
%token <text> T_LNUMBER
%token <text> T_DNUMBER
%token <text> T_CONSTANT_ENCAPSED_STRING
%token <text> T_START_HEREDOC
%token <text> T_END_HEREDOC
%token <text> T_ENCAPSED_AND_WHITESPACE
%token <text> T_DTWO_POINTS
%token <text> T_SL
%token <text> T_SR
%token <text> T_LOGICAL_OR
%token <text> T_LOGICAL_XOR
%token <text> T_LOGICAL_AND
%token <text> T_BOOLEAN_OR
%token <text> T_BOOLEAN_AND
%token <text> T_IS_EQUAL
%token <text> T_IS_NOT_EQUAL
%token <text> T_IS_IDENTICAL
%token <text> T_IS_NOT_IDENTICAL
%token <text> T_IS_SMALLER_OR_EQUAL
%token <text> T_IS_GREATER_OR_EQUAL
%token <text> T_STATIC
%token <text> T_DOUBLE_ARROW
%token <text> T_POW
%token T_END

%type <text> static_scalar
%type <text> common_scalar
%type <text> static_class_name_scalar
%type <text> namespace_name
%type <text> static_array_pair_list
%type <text> static_class_constant
%type <text> static_operation
%type <text> class_name
%type <text> non_empty_static_array_pair_list
%type <text> possible_comma

%start declare_list

%%

declare_list:
		T_STRING '=' static_scalar { addT("T_STRING"); addT("="); addNT("static_scalar"); addLevel(); }
	|	T_STRING '=' static_scalar T_END { addT("T_STRING"); addT("="); addNT("static_scalar"); addT("T_END"); return 0; }		
	|	declare_list ',' T_STRING '=' static_scalar { addNT("declare_list"); addT(","); addT("T_STRING"); addT("="); addNT("static_scalar"); addLevel(); }
	|	declare_list ',' T_STRING '=' static_scalar T_END { addNT("declare_list"); addT(","); addT("T_STRING"); addT("="); addNT("static_scalar"); addT("T_END"); return 0; }
;


static_scalar:
		common_scalar { addNT("common_scalar"); addLevel(); }
	|	static_class_name_scalar { addNT("static_class_name_scalar"); addLevel(); }
	|	namespace_name  { addNT("namespace_name"); addLevel(); }
	|	T_NAMESPACE T_NS_SEPARATOR namespace_name { addT("T_NAMESPACE"); addT("T_NS_SEPARATOR"); addNT("namespace_name"); addLevel(); }
	|	T_NS_SEPARATOR namespace_name { addT("T_NS_SEPARATOR"); addNT("namespace_name"); addLevel(); }
	|	T_ARRAY '(' static_array_pair_list ')' { addT("T_ARRAY"); addT("("); addNT("static_array_pair_list"); addT(")"); addLevel(); }
	|	'[' static_array_pair_list ']' { addT("["); addNT("static_array_pair_list"); addT("]"); addLevel(); }
	|	static_class_constant { addNT("static_class_constant"); addLevel(); }
	|	T_CLASS_C { addT("T_CLASS_C"); addLevel(); addLevel(); }
	|	static_operation { addNT("static_operation"); addLevel(); }
;


common_scalar:
		T_LNUMBER  { addT("T_LNUMBER"); addLevel(); }
	|	T_DNUMBER  { addT("T_DNUMBER"); addLevel(); }
	|	T_CONSTANT_ENCAPSED_STRING { addT("T_CONSTANT_ENCAPSED_STRING"); addLevel(); }
	|	T_LINE  { addT("T_LINE"); addLevel(); }
	|	T_FILE  { addT("T_FILE"); addLevel(); }
	|	T_DIR    { addT("T_DIR"); addLevel(); }
	|	T_TRAIT_C { addT("T_TRAIT_C"); addLevel(); }
	|	T_METHOD_C { addT("T_METHOD_C"); addLevel(); }
	|	T_FUNC_C { addT("T_FUNC_C"); addLevel(); }
	|	T_NS_C { addT("T_NS_C"); addLevel(); }
;
static_class_name_scalar:
	class_name T_DTWO_POINTS { addNT("class_name"); addT("T_DTWO_POINTS"); addLevel(); }
;
namespace_name:
		T_STRING { addT("T_STATIC"); addLevel(); }
	|	namespace_name T_NS_SEPARATOR T_STRING { addNT("namespace_name"); addT("T_NS_SEPARATOR"); addT("T_STRING"); addLevel(); }
;
static_array_pair_list:
		/* empty */ { addT(""); addLevel(); }
	|	non_empty_static_array_pair_list possible_comma { addNT("non_empty_static_array_pair_list"); addNT("possible_comma"); addLevel(); }
;
static_class_constant:
		class_name T_DTWO_POINTS T_STRING { addNT("class_name"); addT("T_DTWO_POINTS"); addT("T_STRING"); addLevel(); }
;
static_operation:
		static_scalar '[' static_scalar ']' { addNT("static_scalar"); addT("["); addNT("static_scalar"); addT("]"); addLevel();}
	|	static_scalar '+' static_scalar { addNT("static_scalar"); addT("+"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '-' static_scalar { addNT("static_scalar"); addT("-"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '*' static_scalar { addNT("static_scalar"); addT("*"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_POW static_scalar { addNT("static_scalar"); addT("T_POW"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '/' static_scalar { addNT("static_scalar"); addT("/"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '%' static_scalar { addNT("static_scalar"); addT("%"); addNT("static_scalar"); addLevel(); }
	|	'!' static_scalar { addT("!"); addNT("static_scalar"); addLevel(); }
	|	'~' static_scalar { addT("~"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '|' static_scalar { addNT("static_scalar"); addT("|"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '&' static_scalar { addNT("static_scalar"); addT("&"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '^' static_scalar { addNT("static_scalar"); addT("^"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_SL static_scalar {  addNT("static_scalar"); addT("T_SL"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_SR static_scalar { addNT("static_scalar"); addT("T_SR"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '.' static_scalar { addNT("static_scalar"); addT("."); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_LOGICAL_XOR static_scalar { addNT("static_scalar"); addT("T_LOGICAL_XOR"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_LOGICAL_AND static_scalar { addNT("static_scalar"); addT("T_LOGICAL_AND"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_LOGICAL_OR static_scalar { addNT("static_scalar"); addT("T_LOGICAL_OR"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_BOOLEAN_AND static_scalar { addNT("static_scalar"); addT("T_BOOLEAN_AND"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_BOOLEAN_OR static_scalar { addNT("static_scalar"); addT("T_BOOLEAN_OR"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_IS_IDENTICAL static_scalar { addNT("static_scalar"); addT("T_IS_IDENTICAL"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_IS_NOT_IDENTICAL static_scalar { addNT("static_scalar"); addT("T_IS_NOT_IDENTICAL"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_IS_EQUAL static_scalar { addNT("static_scalar"); addT("T_IS_EQUAL"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_IS_NOT_EQUAL static_scalar { addNT("static_scalar"); addT("T_IS_NOT_EQUAL"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '<' static_scalar { addNT("static_scalar"); addT("<"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '>' static_scalar { addNT("static_scalar"); addT(">"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_IS_SMALLER_OR_EQUAL static_scalar { addNT("static_scalar"); addT("T_IS_SMALLER_OR_EQUAL"); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_IS_GREATER_OR_EQUAL static_scalar { addNT("static_scalar"); addT("T_IS_GREATER_OR_EQUAL"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '?' ':' static_scalar { addNT("static_scalar"); addT("?"); addT(":"); addNT("static_scalar"); addLevel(); }
	|	static_scalar '?' static_scalar ':' static_scalar { addNT("static_scalar"); addT("?"); addNT("static_scalar"); addT(":"); addNT("static_scalar"); addLevel(); }
	|	'+' static_scalar { addT("+"); addNT("static_scalar"); addLevel(); }
	|	'-' static_scalar { addT("-"); addNT("static_scalar"); addLevel(); }
	|	'(' static_scalar ')' { addT("("); addNT("static_scalar"); addT(")"); addLevel(); }
;


class_name:
		T_STATIC { addT("T_STATIC"); addLevel(); }
	|	namespace_name { addNT("namespace_name"); addLevel(); }
	|	T_NAMESPACE T_NS_SEPARATOR namespace_name { addT("T_NAMESPACE"); addT("T_NS_SEPARATOR"); addNT("namespace_name"); addLevel(); }
	|	T_NS_SEPARATOR namespace_name { addT("T_NS_SEPARATOR"); addNT("namespace_name"); addLevel(); }
;
non_empty_static_array_pair_list:
		non_empty_static_array_pair_list ',' static_scalar T_DOUBLE_ARROW static_scalar { addNT("non_empty_static_array_pair_list"); addT(","); addNT("static_scalar"); addT("T_DOUBLE_ARROW"); addNT("static_scalar"); addLevel(); }
	|	non_empty_static_array_pair_list ',' static_scalar { addNT("non_empty_static_array_pair_list"); addT(","); addNT("static_scalar"); addLevel(); }
	|	static_scalar T_DOUBLE_ARROW static_scalar {  addNT("static_scalar"); addT("T_DOUBLE_ARROW"); addNT("static_scalar"); addLevel(); }
	|	static_scalar { addNT("static_scalar"); addLevel(); }
;
possible_comma:
		/* empty */ { addT(""); addLevel(); }
	|	',' { addT(","); addLevel(); }
;

%%

int yyerror(char *s) {
	printf("Error: %s en línea %d\n", s, lines);
	return 0;
}

int yywrap() {
	return 1;
}

void addT(char *t) {
	treeLevel[tLevel].token[tID].name = (char*) malloc(strlen(t) + 1);
	strcpy(treeLevel[tLevel].token[tID].name, t);
	//printf("%s(%d) ", treeLevel[tLevel].token[tID].name, tID);

	treeLevel[tLevel].token[tID++].no_terminal = 0;
	treeLevel[tLevel].cant_tokens++;
}

void addNT(char *t) {
	treeLevel[tLevel].token[tID].name = (char*) malloc(strlen(t) + 1);
	strcpy(treeLevel[tLevel].token[tID].name, t);

	treeLevel[tLevel].token[tID++].no_terminal = 1;
	treeLevel[tLevel].cant_tokens++;
}

void addLevel() {
	//treeLevel[tLevel].cant_tokens = tID;
	//printf("\n<cant_token: %d>\n", treeLevel[tLevel].cant_tokens);
	tID = 0;
	tLevel++;
}

/* LRULRU */

int printTreeLevel(int n, int i) {
	int j;
	int printed_no_terminals = 0;
	for(j=0; j<treeLevel[n].cant_tokens; j++) {
		if(treeLevel[n].token[j].no_terminal) {
			printed_no_terminals++;
			if(i>0) {
				if(i == 1) {
					printf("\x1b[01;32m");
					printed_no_terminals += printTreeLevel(treeLevel[n].token[j].level_ref, i-1);
					printf("\x1b[00m");
				}
				else {
					printed_no_terminals += printTreeLevel(treeLevel[n].token[j].level_ref, i-1);
				}
			}
			else {
				printf("<%s> ", treeLevel[n].token[j].name);
			}
		}
		else {
			printf("%s ", treeLevel[n].token[j].name);
		}
	}
	return printed_no_terminals;
}

int makeTree(int i) {
	int j;
	int found_no_terminals=0;
	for(j=treeLevel[i].cant_tokens-1; j>=0; --j) {
		if(treeLevel[i].token[j].no_terminal == 1) {
			found_no_terminals++;
			treeLevel[i].token[j].level_ref = i-found_no_terminals;
			//printf("Asignado %d a %s(%d)\n", treeLevel[i].token[j].level_ref, treeLevel[i].token[j].name, i);
			found_no_terminals += makeTree(i-found_no_terminals);
		}
	}
	return found_no_terminals;
}

void printTree() {
	int fnt = makeTree(tLevel);
	int i = 0;
	for(i=0; ; i++) {
		if(printTreeLevel(tLevel, i) == fnt) {
			printf("\n");
			printTreeLevel(tLevel, i+1);
			printf("\n");
			printTreeLevel(tLevel, i+2);
			break;
		}
		printf("\n");
	}
}

void printSymbolTable() {
	int i;
	for(i=0; i<stID; i++) {
		printf("[%s]: %s\n", stToken[i], stValue[i]);
	}
}