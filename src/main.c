#include <stdio.h>
#include "declare_list.tab.h"

extern FILE *yyin;
extern FILE *yyout;
extern int yyparse(void);
extern int lines;
extern int found_errors;

int main(int argc, char *argv[]) {
	int option;
	char file[1024];

	printf(" ### Analizador lexico y sintactico ###\n");
	printf(" --- PHP: declare_list ---\n\n");

	if(argc > 1) {
		printf("[ Analizando el archivo %s. ]\n\n", argv[1]);
		yyin=fopen(argv[1], "r");
	}
	else {
		for(;;) {
			printf("# 1) Ver especificacion del proyecto\n# 2) Ingresar texto\n# 3) Abrir file de texto\n# 4) Salir\n\n");
			printf("Opcion> ");
			scanf("%d", &option);
			printf("\n");
			
			if(option == 1) {
				printf("Para ver la especificacion y como utilizar el analizador, abra el archive 'Especificacion de proyecto.pdf'. Este se encuentra en la carpeta principal del proyecto.\n\n");
			}
			else if (option == 2) {
				yyin = stdin;
				break;
			}
			else if (option == 3) {
				printf("Nombre de archivo> ");
				scanf("%s", file);

				yyin = fopen(file, "r");
				if(!yyin) {
					printf("[ERROR] No se encontro el archivo %s\n\n", file);
				}
				else {
					break;
				}
			}
			else if (option == 4) {
				printf("Saliendo...\n");
				return 0;
			}
			else {
				printf("[ERROR] Opcion incorrecta. Vuelva a elegir una opcion\n\n");
			}
		}
	}

	yyparse();
	printf("\nAnalsis lexico: tabla de simbolos\n");
	printSymbolTable();
	printf("\n");
	printf("Analisis sintactico: derivacions\n");
	printTree();

	printf("\n\n[ Se leyeron %d lineas del archivo. ]\n", lines);

	/* Creacion del archivo HTML que contiene el analisis para mejorar la visual */
	char htmlName[] = "analisis.html";

	FILE *htmlFile = fopen(htmlName, "w");
	if(!htmlFile) {
		printf("Error al crear el archivo %s.\n", htmlName);
		return 1;
	}
	fprintf(htmlFile, "<html><head><title>Proyecto de Sintaxis y Semantica de los Lenguajes. Analisis de declare_list.</title><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" /><link type=\"text/css\" rel=stylesheet href=\"src/style.css\" /></head><body><h1>Proyecto: analisis lexico y sintactico de declare_list</h1><h2>Analisis lexico</h2><h3>Tabla de simbolos</h3>");
	fprintf(htmlFile, "<table><tr><td><b>Token</b></td><td><b>Valor</b></td></tr>");
	printSymbolTableToHTML(htmlFile);
	fprintf(htmlFile, "</table>");
	if(found_errors > 0) {
		fprintf(htmlFile, "<h4>Se encontro %d en el analisis.</h4>", found_errors);
	}
	else {
		fprintf(htmlFile, "<h2>Analisis sintactico</h2><h3>Derivaciones del arbol sintactico.</h3>");
		printTreeToHTML(htmlFile);
	}
	fprintf(htmlFile, "<h2>Hecho por Alan Boglioli (legajo 38507)</h2>");
	fprintf(htmlFile, "</body></html>");
	fclose(htmlFile);
	printf("[Se creo un archivo con el analisis.]\nBusque %s en la carpeta principal del proyecto y abrelo con el navegador\n", htmlName);

	printf("Presione una tecla para finalizar.");
	getchar();

	return 0;
}