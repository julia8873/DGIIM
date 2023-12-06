/*
P1_Ejercicio_4.c
*/

#include<unistd.h>  /* POSIX Standard: 2.10 Symbolic Constants <unistd.h>
		     		*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>  /* Primitive system data types for abstraction	\
							of implementation-dependent data types.
							POSIX Standard: 2.6 Primitive System Data Types
							<sys/types.h>
						*/
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>


#define S_ISREG2(mode)  ((mode & S_IFMT) == S_IFREG)



int main(int argc, char *argv[]) {
    int i;
    struct stat atributos;
    char tipoArchivo[30];

    if(argc<2){
        printf("\nSintaxis de ejecucion: ej4.c [<nombre_archivo>]+\n\n");
        exit(-1);
    }

    for(int i=0; i<argc; i++){
        printf("%s: ", argv[i]);
        if(lstat(argv[i], &atributos) < 0){
            printf("\n Error al intentar acceder a los atributos de %s", argv[i]);
            perror("\nError en lstat");
        }else{
            if S_ISREG2(atributos.st_mode) strcpy(tipoArchivo, "Regular");
            else strcpy(tipoArchivo,"No es un archivo regular");

            printf("%s \n",tipoArchivo);
        }
    }

}