%{
	#include <stdio.h>
	int yylex();
	int yyparse();
	FILE *yyin;
	FILE *yyout;
	int lines;
	char *stack[1024];
	int i_stack=0;
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
		T_STRING '=' static_scalar { }
	|	declare_list ',' T_STRING '=' static_scalar { }
	|	declare_list ',' T_STRING '=' static_scalar T_END { printStack(); return 0; }
;


static_scalar:
		common_scalar { }
	|	static_class_name_scalar { }
	|	namespace_name  { }
	|	T_NAMESPACE T_NS_SEPARATOR namespace_name { }
	|	T_NS_SEPARATOR namespace_name { }
	|	T_ARRAY '(' static_array_pair_list ')' { printf(""); }
	|	'[' static_array_pair_list ']' { }
	|	static_class_constant { }
	|	T_CLASS_C { }
	|	static_operation { }
;


common_scalar:
		T_LNUMBER  { pushStack($1); }
	|	T_DNUMBER  { pushStack($1); }
	|	T_CONSTANT_ENCAPSED_STRING { pushStack($1); }
	|	T_LINE  { pushStack($1); }
	|	T_FILE  { pushStack($1); }
	|	T_DIR    { pushStack($1); }
	|	T_TRAIT_C { pushStack($1); }
	|	T_METHOD_C { pushStack($1); }
	|	T_FUNC_C { pushStack($1); }
	|	T_NS_C { pushStack($1); }
	|	T_START_HEREDOC T_ENCAPSED_AND_WHITESPACE T_END_HEREDOC { pushStack($1); }
	|	T_START_HEREDOC T_END_HEREDOC { pushStack($1); }
;
static_class_name_scalar:
	class_name T_DTWO_POINTS { printf(""); }
;
namespace_name:
		T_STRING { printf(""); }
	|	namespace_name T_NS_SEPARATOR T_STRING { printf(""); }
;
static_array_pair_list:
		/* empty */ { }
	|	non_empty_static_array_pair_list possible_comma { printf("");  }
;
static_class_constant:
		class_name T_DTWO_POINTS T_STRING { printf(""); }
;
static_operation:
		static_scalar '[' static_scalar ']' { }
	|	static_scalar '+' static_scalar { }
	|	static_scalar '-' static_scalar { }
	|	static_scalar '*' static_scalar { }
	|	static_scalar T_POW static_scalar { printf(""); }
	|	static_scalar '/' static_scalar { }
	|	static_scalar '%' static_scalar { }
	|	'!' static_scalar { }
	|	'~' static_scalar { }
	|	static_scalar '|' static_scalar { }
	|	static_scalar '&' static_scalar { }
	|	static_scalar '^' static_scalar { }
	|	static_scalar T_SL static_scalar { printf(""); }
	|	static_scalar T_SR static_scalar { printf(""); }
	|	static_scalar '.' static_scalar { }
	|	static_scalar T_LOGICAL_XOR static_scalar { printf(""); }
	|	static_scalar T_LOGICAL_AND static_scalar { printf(""); }
	|	static_scalar T_LOGICAL_OR static_scalar { printf(""); }
	|	static_scalar T_BOOLEAN_AND static_scalar { printf(""); }
	|	static_scalar T_BOOLEAN_OR static_scalar { printf(""); }
	|	static_scalar T_IS_IDENTICAL static_scalar { printf(""); }
	|	static_scalar T_IS_NOT_IDENTICAL static_scalar { printf(""); }
	|	static_scalar T_IS_EQUAL static_scalar { printf(""); }
	|	static_scalar T_IS_NOT_EQUAL static_scalar { printf(""); }
	|	static_scalar '<' static_scalar { }
	|	static_scalar '>' static_scalar { }
	|	static_scalar T_IS_SMALLER_OR_EQUAL static_scalar { printf(""); }
	|	static_scalar T_IS_GREATER_OR_EQUAL static_scalar { printf(""); }
	|	static_scalar '?' ':' static_scalar { }
	|	static_scalar '?' static_scalar ':' static_scalar { }
	|	'+' static_scalar { }
	|	'-' static_scalar { }
	|	'(' static_scalar ')' { }
;


class_name:
		T_STATIC { printf(""); }
	|	namespace_name { }
	|	T_NAMESPACE T_NS_SEPARATOR namespace_name { printf(""); }
	|	T_NS_SEPARATOR namespace_name { printf(""); }
;
non_empty_static_array_pair_list:
		non_empty_static_array_pair_list ',' static_scalar T_DOUBLE_ARROW static_scalar { printf(""); }
	|	non_empty_static_array_pair_list ',' static_scalar { }
	|	static_scalar T_DOUBLE_ARROW static_scalar { printf(""); }
	|	static_scalar { }
;
possible_comma:
		/* empty */ { }
	|	',' { }
;

%%

int yyerror(char *s) {
	printf("Error: %s en línea %d\n", s, lines);
	return 0;
}

int yywrap() {
	return 1;
}

void pushStack(char *s) {
	stack[i_stack] = (char*) malloc(strlen(s) + 1);
	strcpy(stack[i_stack++], s);
}

void printStack() {
	int i;
	for(i=0; i<i_stack; i++) {
		printf("S[%d]: %s; ", i, stack[i]);
	}
	printf("\n");
}