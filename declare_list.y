%{
	#include <stdio.h>
	int yylex();
	int yyparse();
	FILE *yyin;
	int linea;
%}

%token T_STRING    "identifier (T_STRING)"
%token T_NAMESPACE       "namespace (T_NAMESPACE)"
%token T_NS_SEPARATOR    "\\ (T_NS_SEPARATOR)"
%token T_ARRAY           "array (T_ARRAY)"
%token T_CLASS_C         "__CLASS__ (T_CLASS_C)"
%token T_TRAIT_C         "__TRAIT__ (T_TRAIT_C)"
%token T_METHOD_C        "__METHOD__ (T_METHOD_C)"
%token T_FUNC_C          "__FUNCTION__ (T_FUNC_C)"
%token T_LINE            "__LINE__ (T_LINE)"
%token T_FILE            "__FILE__ (T_FILE)"
%token T_LNUMBER   "integer number (T_LNUMBER)"
%token T_DNUMBER   "floating-point number (T_DNUMBER)"
%token T_CONSTANT_ENCAPSED_STRING "quoted-string (T_CONSTANT_ENCAPSED_STRING)"
%token T_NAMESPACE       "namespace (T_NAMESPACE)"
%token T_NS_C            "__NAMESPACE__ (T_NS_C)"
%token T_DIR             "__DIR__ (T_DIR)"
%token T_WHITESPACE      "whitespace (T_WHITESPACE)"
%token T_START_HEREDOC   "heredoc start (T_START_HEREDOC)"
%token T_END_HEREDOC     "heredoc end (T_END_HEREDOC)"
%token T_ENCAPSED_AND_WHITESPACE  "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)"
%token T_PAAMAYIM_NEKUDOTAYIM ":: (T_PAAMAYIM_NEKUDOTAYIM)"
%token T_SL "<< (T_SL)"
%token T_SR ">> (T_SR)"
%left T_LOGICAL_OR
%token T_LOGICAL_OR   "or (T_LOGICAL_OR)"
%left T_LOGICAL_XOR
%token T_LOGICAL_XOR  "xor (T_LOGICAL_XOR)"
%left T_LOGICAL_AND
%token T_LOGICAL_AND  "and (T_LOGICAL_AND)"
%left T_BOOLEAN_OR
%token T_BOOLEAN_OR   "|| (T_BOOLEAN_OR)"
%left T_BOOLEAN_AND 
%token T_BOOLEAN_AND  "&& (T_BOOLEAN_AND)"
%token T_IS_EQUAL     "== (T_IS_EQUAL)"
%token T_IS_NOT_EQUAL "!= (T_IS_NOT_EQUAL)"
%token T_IS_IDENTICAL "=== (T_IS_IDENTICAL)"
%token T_IS_NOT_IDENTICAL "!== (T_IS_NOT_IDENTICAL)"
%token T_IS_SMALLER_OR_EQUAL "<= (T_IS_SMALLER_OR_EQUAL)"
%token T_IS_GREATER_OR_EQUAL ">= (T_IS_GREATER_OR_EQUAL)"
%token T_STATIC     "static (T_STATIC)"
%token T_DOUBLE_ARROW    "=> (T_DOUBLE_ARROW)"

%start declare

%%

/* Nivel 0*/
declare:
	declare declare_list | declare_list
;

declare_list:
		T_STRING '=' static_scalar					{ }
	|	declare_list ',' T_STRING '=' static_scalar	{ }
;

/*Nivel 1*/
static_scalar:
		common_scalar	{ }
	|	static_class_name_scalar	{ }
	|	namespace_name 		{ }
	|	T_NAMESPACE T_NS_SEPARATOR namespace_name { }
	|	T_NS_SEPARATOR namespace_name { }
	|	T_ARRAY '(' static_array_pair_list ')' { }
	|	'[' static_array_pair_list ']' { }
	|	static_class_constant { }
	|	T_CLASS_C			{ }
	|	static_operation { }
;

/*Nivel 2*/
common_scalar:
		T_LNUMBER 					{ }
	|	T_DNUMBER 					{ }
	|	T_CONSTANT_ENCAPSED_STRING	{ }
	|	T_LINE 						{ }
	|	T_FILE 						{ }
	|	T_DIR   					{ }
	|	T_TRAIT_C					{ }
	|	T_METHOD_C					{ }
	|	T_FUNC_C					{ }
	|	T_NS_C						{ }
	|	T_START_HEREDOC T_ENCAPSED_AND_WHITESPACE T_END_HEREDOC { }
	|	T_START_HEREDOC T_END_HEREDOC { }
;

static_class_name_scalar:
	class_name T_PAAMAYIM_NEKUDOTAYIM T_CLASS { }
;

namespace_name:
		T_STRING { }
	|	namespace_name T_NS_SEPARATOR T_STRING { }
;

static_array_pair_list:
		/* empty */ { }
	|	non_empty_static_array_pair_list possible_comma	{ }
;

static_class_constant:
		class_name T_PAAMAYIM_NEKUDOTAYIM T_STRING { }
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

/*Nivel 3*/
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
		non_empty_static_array_pair_list ',' static_scalar_value T_DOUBLE_ARROW static_scalar_value { }
	|	non_empty_static_array_pair_list ',' static_scalar_value { }
	|	static_scalar_value T_DOUBLE_ARROW static_scalar_value { }
	|	static_scalar_value { }
;

possible_comma:
		/* empty */
	|	','
;


%%

int yyerror(char *s) {
	printf("Error: %s en línea %d\n", s, linea);
	return 0;
}

int yywrap() {
	return 1;
}

int main(int argc, char *argv[]) {
	char opcion;
	char archivo[1024];

	printf("[DECLARE LIST (PHP)]: Analizador\n");

	if(argc > 1) {
		printf("Analizando el archivo %s.\n", argv[1]);
		yyin=fopen(argv[1], "r");
	}
	else {
		for(;;) {
			printf("· [I]ngresar texto\n· [A]brir archivo de texto\n");
			printf("Opcion: ");
			scanf("%c", &opcion);	
			
			opcion = tolower(opcion);

			if(opcion == 'a') {
				printf("Nombre de archivo: ");
				scanf("%s", archivo);

				yyin = fopen(archivo, "r");
				break;
			}
			else if (opcion == 'i') {
				yyin = stdin;
				break;
			}
			else {
				printf("Opción incorrecta... Vuelva a elegir una opción\n");
			}
		}
	}

	yyparse();

	return 0;
}

