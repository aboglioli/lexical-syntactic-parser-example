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
			printf("# 1) Ver especificación del proyecto\n# 2) Ingresar texto\n# 3) Abrir file de texto\n# 4) Salir\n\n");
			printf("Opción> ");
			scanf("%d", &option);
			printf("\n");
			
			if(option == 1) {
				printf("Para ver la especificación y cómo utilizar el analizador, abra el archive 'Especificación de proyecto.pdf'. Este se encuentra en la carpeta principal del proyecto.\n\n");
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
					printf("[ERROR] No se encontró el archivo %s\n\n", file);
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
				printf("[ERROR] Opción incorrecta. Vuelva a elegir una opción\n\n");
			}
		}
	}

	yyparse();
	printf("\nAnálsis léxico: tabla de símbolos\n");
	printSymbolTable();
	printf("\n");
	printf("Análisis sintáctico: derivacions\n");
	printTree();

	printf("\n\n[ Se leyeron %d lineas del archivo. ]\n", lines);

	/* Creación del archivo HTML que contiene el análisis para mejorar la visual */
	char htmlName[] = "analisis.html";

	FILE *htmlFile = fopen(htmlName, "w");
	if(!htmlFile) {
		printf("Error al crear el archivo %s.\n", htmlName);
		return 1;
	}
	fprintf(htmlFile, "<html><head><title>Proyecto de Sintaxis y Semántica de los Lenguajes. Análisis de declare_list.</title><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" /><link type=\"text/css\" rel=stylesheet href=\"src/style.css\" /></head><body><h1>Proyecto: análisis léxico y sintáctico de declare_list</h1><h2>Análisis léxico</h2><h3>Tabla de símbolos</h3>");
	fprintf(htmlFile, "<table><tr><td><b>Token</b></td><td><b>Valor</b></td></tr>");
	printSymbolTableToHTML(htmlFile);
	fprintf(htmlFile, "</table>");
	if(found_errors > 0) {
		fprintf(htmlFile, "<h4>Se encontró %d en el análisis.</h4>", found_errors);
	}
	else {
		fprintf(htmlFile, "<h2>Análisis sintáctico</h2><h3>Derivaciones del árbol sintáctico.</h3>");
		printTreeToHTML(htmlFile);
	}
	fprintf(htmlFile, "<h2>Hecho por Alan Boglioli</h2>");
	fprintf(htmlFile, "</body></html>");
	fclose(htmlFile);
	printf("[Se creó un archivo con el análisis.]\nBusca %s en la carpeta principal del proyecto y abrelo con el navegador\n", htmlName);


	return 0;
}