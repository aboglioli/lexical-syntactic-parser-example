#include <stdio.h>
#include "declare_list.tab.h"

extern FILE *yyin;
extern FILE *yyout;
extern int yyparse(void);
extern int lines;

int main(int argc, char *argv[]) {
	int opcion;
	char archivo[1024];

	printf("\033[01;31m ### Analizador lexico y sintactico ###\033[00m\n");
	printf("\x1B[01;33m --- PHP: declare_list ---\x1B[0m\n\n");

	if(argc > 1) {
		printf("[ Analizando el archivo %s. ]\n\n", argv[1]);
		yyin=fopen(argv[1], "r");
	}
	else {
		for(;;) {
			printf("· 1) Ver especificación del proyecto\n· 2) Ingresar texto\n· 3) Abrir archivo de texto\n· 4) Salir\n\n");
			printf("Opcion> ");
			scanf("%d", &opcion);
			printf("\n");
			
			if(opcion == 1) {
				printf("Especificacion...\n");
			}
			else if (opcion == 2) {
				yyin = stdin;
				break;
			}
			else if (opcion == 3) {
				printf("Nombre de archivo> ");
				scanf("%s", archivo);

				yyin = fopen(archivo, "r");
				if(!yyin) {
					printf("[ERROR] No se encontró el archivo %s\n\n", archivo);
				}
				else {
					break;
				}
			}
			else if (opcion == 4) {
				printf("Saliendo...\n");
				return 0;
			}
			else {
				printf("[ERROR] Opción incorrecta. Vuelva a elegir una opción\n\n");
			}
		}
	}

	yyparse();
	printf("\033[01;31mAnálsis léxico: tabla de símbolos\033[00m\n");
	printSymbolTable();
	printf("\n");
	printf("\033[01;31mAnálisis sintáctico: derivacions\033[00m\n");
	printTree();
	printf("\n\n[ Se leyeron %d lineas del archivo. ]\n", lines);

	return 0;
}