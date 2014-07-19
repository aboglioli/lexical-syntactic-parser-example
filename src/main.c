#include <stdio.h>
#include "declare_list.tab.h"

extern FILE *yyin;
extern FILE *yyout;
extern int yyparse(void);

int main(int argc, char *argv[]) {
	char opcion;
	char archivo[1024];

	printf("\x1B[33m<<Analizador lexico y sintactico>>\n");
	printf("\x1B[32mPHP: declare_list\n\n");
	printf("\x1B[0m");

	if(argc > 1) {
		printf("[Analizando el archivo %s.]\n\n", argv[1]);
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