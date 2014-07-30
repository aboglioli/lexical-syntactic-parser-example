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
	char ret;

	printf(" ### Analizador lexico y sintactico ###\n");
	printf(" --- PHP: declare_list ---\n\n");

	if(argc > 1) {
		printf("[Analizando el archivo %s]\n\n", argv[1]);
		yyin=fopen(argv[1], "r");
	}
	else {
		for(;;) {
			printf("# 1) Ver especificacion del proyecto\n# 2) Ingresar texto\n# 3) Abrir archivo de texto\n# 4) Salir\n\n");
			printf("Opcion> ");
			scanf("%d", &option);
			printf("\n");
			
			if(option == 1) {
				printf("Para ver la especificacion y como utilizar el analizador, abra el archive 'Especificacion de proyecto.pdf'. Este se encuentra en la carpeta principal del proyecto.\n\n");
			}
			else if (option == 2) {
				yyin = stdin;
				printf("[Ingresa las declaraciones a continuacion en una sola linea. Al presionar ENTER comenzara el analisis.]\n\n> ");
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

	while(getchar() != '\n');
	yyparse();
	printf("\nAnalsis lexico: tabla de simbolos\n");
	printSymbolTable();
	if(found_errors > 0) {
		printf("\nSe encontraron %d errores:\n", found_errors);
		printErrors();
	}
	else {
		printf("\n");
		printf("Analisis sintactico: derivacions\n");
		printTree();
	}

	printf("\n\n[Se leyeron %d lineas del archivo]\n", lines);

	/* Creacion del archivo HTML que contiene el analisis para mejorar la visual */
	char htmlName[] = "analisis.html";

	FILE *htmlFile = fopen(htmlName, "w");
	if(!htmlFile) {
		printf("Error al crear el archivo %s.\n", htmlName);
		return 1;
	}
	fprintf(htmlFile, "<html><head><title>Proyecto de Sintaxis y Semántica de los Lenguajes. Análisis de declare_list.</title><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" /><link type=\"text/css\" rel=stylesheet href=\"src/style.css\" /></head><body>");
	fprintf(htmlFile, "<h1>Análisis léxico y sintáctico de declare_list</h1><h3>Declaración a analizar</h3>");
	printStatementToHTML(htmlFile);
	fprintf(htmlFile, "<h2>Análisis lexico</h2><h3>Tabla de símbolos</h3>");
	fprintf(htmlFile, "<table><tr><td><b>Token</b></td><td><b>Valor</b></td></tr>");
	printSymbolTableToHTML(htmlFile);
	fprintf(htmlFile, "</table>");
	if(found_errors > 0) {
		printErrorsToHTML(htmlFile);
	}
	else {
		fprintf(htmlFile, "<h2>Análisis sintáctico</h2><h3>Derivaciones del árbol sintáctico.</h3>");
		printTreeToHTML(htmlFile);
	}
	fprintf(htmlFile, "<h2>Hecho por Alan Boglioli (legajo 38507)</h2>");
	fprintf(htmlFile, "</body></html>");
	fclose(htmlFile);

	printf("[Se creo un archivo con el analisis.]\n### BUSQUE %s EN LA CARPETA PRINCIPAL DEL PROYECTO Y ABRALO CON EL NAVEGADOR ###\n", htmlName);

	system("pause");

	return 0;
}