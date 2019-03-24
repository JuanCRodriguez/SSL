#include <stdio.h>

/* Qué: main.c
* Imprime "Hello World" y lo guarda en un archivo "output.txt"
* Juan Carlos Rodriguez
* 24/03/19
*/

int main() {
    char * mensaje;
    FILE* f = fopen("output.txt", "w+");

    mensaje = "Hello, World\n";

    fprintf(f, mensaje);
    printf(mensaje);

    fclose(f);
return 0;
}