%{
	#include <stdio.h>
	int yylex();
	int yyparse();
	FILE *yyin;
	int linea;
%}

/*%union {
	int entero;
	char *texto;
	char caracter;
}*/

%token T_STRING
%token RETORNO
%token '='

/*%type <texto> static_scalar
%type <texto> expresion*/

%start declare

%%

declare:			declare declare_list | declare_list 
declare_list:		T_STRING '=' T_STRING RETORNO 	{ printf("Correcta!"); }
			|		'=' T_STRING RETORNO				{ printf("Error (linea %d), se esperaba un T_STRING al inicio\n", linea); }
			|		T_STRING '=' RETORNO				{ printf("Error (linea %d), se esperaba un T_STRING al final\n", linea); }
			|		T_STRING RETORNO					{ printf("Error (linea %d), formato: T_STRING '=' T_STRING\n", linea); }
			|		RETORNO								{}

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

