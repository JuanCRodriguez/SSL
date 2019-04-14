01-Fase Errores
---
Identificar las fases de traducción y errores.


Hipotesis
---
Se utilizó el compilador gcc para generar un archivo en las distintas instancias de compilacion

Autor
---
* Github: JuanCRodriguez
* Legajo: 169154-5
* Nombre: Juan Carlos Rodriguez


Secuencia de pasos
---

**1)Escribir hello2.c, que es una variante de hello.c.**

**2)Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su contenido.**
> gcc -E hello2.c -o hello2.i

Mediante este comando podemos generar el archivo preprocesado. Este se encarga de incluir archivos, directiva #include y de reemplazar comentarios.
Si abrimos el archivo "hello2.i" con el notepad, podemos notar que se agregaron el encabezado, con la respectiva ruta a cada archivo, de varias funciones propias de mingw y de la libreria stdio.h, asi mismo el comentario "/\*medio*/" ya no se ve


**3)Escribir hello3.c, una nueva variante.**


**4)Investigar la semántica de la primera línea.**  
*int printf(const char \*s, ...);*
es correcto semanticamente ya que es el encabezado de una funcion de tipo int llamada "printf" que recibe una cantidad de argumentos variable y termina con ";"

**5)Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i.**
> gcc -E hello3.c -o hello3.i

Podemos notar que solamente se agregó el linemarker del archivo c ya que no hay ninguna bibloteca incluida

**6)Compilar el resultado y generar hello3.s, no ensamblar.**
> gcc hello3.c -S -o hello3.s

Al correr este comando el prompt nos muestra una alerta de tipo error indicando un error sintactico. En este caso, falta } para cerrar la funcion main. Tambien nos muestra una alerta de tipo warning indicando que hay una declaracion implicita de "prontf" y nos pregunta si nos referiamos al encabezado "printf"

7)Corregir en el nuevo archivo hello4.c y empezar de nuevo, generar hello4.s, no ensamblar.

**8)Investigar hello4.s.**
> gcc hello4.c -S -o hello4.s

Se genera el archivo hello4.s donde se encuentra el codigo assembler del programa, podemos ver que guarda el output del programa en el registro LC0

**9)Ensamblar hello4.s en hello4.o, no vincular**
> gcc -c hello4.s -o hello4.o  

**10)Vincular hello4.o con la biblioteca estándar y generar el ejecutable.**
>gcc hello4.o -o stdio.h  

Nos indica que hay una referencia indefinida en 'prontf'

**11)Corregir en hello5.c y generar el ejecutable.**
> gcc hello5.o -o stdio.h  
gcc hello5.o -o hello5.exe

**12)Ejecutar y analizar el resultado.**
> hello5.exe  
La respuesta es 11867580

Se muestra informacion basura en el campo "%d" ya que falta pasarle el argumento "i" a printf

**13)Corregir en hello6.c y empezar de nuevo.**
> gcc hello6.c -o hello6.exe  
hello6.exe  
La respuesta es 42  

Ahora se muestra correctamente la respuesta
 
**14)Escribir hello7.c, una nueva variante.**

**15)Explicar porqué funciona.**

> gcc hello7.c -o hello7.exe  

Se muestran varias alertas de tipo warning indicando la declaracion implicita de la funcion printf y luego se muestra una nota indicando que se va a incluir la libreria estandar ya que el linker detecta que la funcion printf es parte de la libreria estandar
