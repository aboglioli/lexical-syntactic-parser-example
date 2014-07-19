%{
	#include <stdio.h>
	int yylex();
	int yyparse();
	FILE *yyin;
	FILE *yyout;
	int lines;
%}

/*%union {
	int i;
	float f;
	char c;
	char *t;
}*/

%token T_STRING
%token T_RET
%token T_NAMESPACE
%token T_NS_SEPARATOR
%token T_ARRAY
%token T_CLASS
%token T_CLASS_C
%token T_TRAIT_C
%token T_FUNC_C
%token T_METHOD_C
%token T_LINE
%token T_FILE
%token T_DIR
%token T_NS_C
%token T_LNUMBER
%token T_DNUMBER
%token T_CONSTANT_ENCAPSED_STRING
%token T_START_HEREDOC
%token T_END_HEREDOC
%token T_ENCAPSED_AND_WHITESPACE
%token T_DTWO_POINTS
%token T_SL
%token T_SR
%token T_LOGICAL_OR
%token T_LOGICAL_XOR
%token T_LOGICAL_AND
%token T_BOOLEAN_OR
%token T_BOOLEAN_AND
%token T_IS_EQUAL
%token T_IS_NOT_EQUAL
%token T_IS_IDENTICAL
%token T_IS_NOT_IDENTICAL
%token T_IS_SMALLER_OR_EQUAL
%token T_IS_GREATER_OR_EQUAL
%token T_STATIC
%token T_DOUBLE_ARROW
%token T_POW

%start declare

%%

declare:
		declare possible_ret {printf("\n");}
	|	declare_list possible_ret {printf("\n");}
	|	declare declare_list possible_ret {printf("\n");}
declare_list:
		T_STRING '=' static_scalar { }
	|	declare_list ',' T_STRING '=' static_scalar { }
;


static_scalar:
		common_scalar { }
	|	static_class_name_scalar { }
	|	namespace_name  { }
	|	T_NAMESPACE T_NS_SEPARATOR namespace_name { }
	|	T_NS_SEPARATOR namespace_name { }
	|	T_ARRAY '(' static_array_pair_list ')' { }
	|	'[' static_array_pair_list ']' { }
	|	static_class_constant { }
	|	T_CLASS_C { }
	|	static_operation { }
;
possible_ret:
		/* empty*/ { }
	|	'\n' { }


common_scalar:
		T_LNUMBER  { }
	|	T_DNUMBER  { }
	|	T_CONSTANT_ENCAPSED_STRING { }
	|	T_LINE  { }
	|	T_FILE  { }
	|	T_DIR    { }
	|	T_TRAIT_C { }
	|	T_METHOD_C { }
	|	T_FUNC_C { }
	|	T_NS_C { }
	|	T_START_HEREDOC T_ENCAPSED_AND_WHITESPACE T_END_HEREDOC { }
	|	T_START_HEREDOC T_END_HEREDOC { }
;
static_class_name_scalar:
	class_name T_DTWO_POINTS { }
;
namespace_name:
		T_STRING { }
	|	namespace_name T_NS_SEPARATOR T_STRING { }
;
static_array_pair_list:
		/* empty */ { }
	|	non_empty_static_array_pair_list possible_comma { }
;
static_class_constant:
		class_name T_DTWO_POINTS T_STRING { }
;
static_operation:
		static_scalar '[' static_scalar ']' { }
	|	static_scalar '+' static_scalar { }
	|	static_scalar '-' static_scalar { }
	|	static_scalar '*' static_scalar { }
	|	static_scalar T_POW static_scalar { }
	|	static_scalar '/' static_scalar { }
	|	static_scalar '%' static_scalar { }
	|	'!' static_scalar { }
	|	'~' static_scalar { }
	|	static_scalar '|' static_scalar { }
	|	static_scalar '&' static_scalar { }
	|	static_scalar '^' static_scalar { }
	|	static_scalar T_SL static_scalar { }
	|	static_scalar T_SR static_scalar { }
	|	static_scalar '.' static_scalar { }
	|	static_scalar T_LOGICAL_XOR static_scalar { }
	|	static_scalar T_LOGICAL_AND static_scalar { }
	|	static_scalar T_LOGICAL_OR static_scalar { }
	|	static_scalar T_BOOLEAN_AND static_scalar { }
	|	static_scalar T_BOOLEAN_OR static_scalar { }
	|	static_scalar T_IS_IDENTICAL static_scalar { }
	|	static_scalar T_IS_NOT_IDENTICAL static_scalar { }
	|	static_scalar T_IS_EQUAL static_scalar { }
	|	static_scalar T_IS_NOT_EQUAL static_scalar { }
	|	static_scalar '<' static_scalar { }
	|	static_scalar '>' static_scalar { }
	|	static_scalar T_IS_SMALLER_OR_EQUAL static_scalar { }
	|	static_scalar T_IS_GREATER_OR_EQUAL static_scalar { }
	|	static_scalar '?' ':' static_scalar { }
	|	static_scalar '?' static_scalar ':' static_scalar { }
	|	'+' static_scalar { }
	|	'-' static_scalar { }
	|	'(' static_scalar ')' { }
;


class_name:
		T_STATIC { }
	|	namespace_name { }
	|	T_NAMESPACE T_NS_SEPARATOR namespace_name { }
	|	T_NS_SEPARATOR namespace_name { }
;
namespace_name:
		T_STRING { }
	|	namespace_name T_NS_SEPARATOR T_STRING { }
;
non_empty_static_array_pair_list:
		non_empty_static_array_pair_list ',' possible_ret static_scalar T_DOUBLE_ARROW static_scalar { }
	|	non_empty_static_array_pair_list ',' possible_ret static_scalar { }
	|	static_scalar T_DOUBLE_ARROW static_scalar { }
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



