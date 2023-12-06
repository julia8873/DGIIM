/*
ej1.c
Implementa un programa que realice la siguiente funcionalidad.
 El programa acepta como argumento el nombre de un archivo (pathname), lo abre y lo lee en bloques de tamaño 80 Bytes,
 y crea un nuevo archivo de salida, salida.txt, en el que debe aparecer la siguiente información:

Bloque 1
// Aquí van los primeros 80 Bytes del archivo pasado como argumento.
Bloque 2
// Aquí van los siguientes 80 Bytes del archivo pasado como argumento.
...
Bloque n
// Aquí van los siguientes 80 Bytes del archivo pasado como argumento.
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>  	/* Primitive system data types for abstraction\
			   of implementation-dependent data types.
			   POSIX Standard: 2.6 Primitive System Data Types
			   <sys/types.h>
			*/
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[]){

    int fd_in, fd_out;

    if (argc != 2 && argc != 1){
        printf("Uso: <P1_Ejercicio_2> <pathname>\n");
        exit(EXIT_FAILURE);
    }

    // Fichero de entrada. Solo leer
    if (argc == 2){ // Se ha proporcionado un archivo
        if( (fd_in=open(argv[1],O_RDONLY))<0) {
            printf("\nError %d en open (In)",errno);
            perror("\nError en open");
            exit(EXIT_FAILURE);
        }
    }else{ // No se ha proporcionado archivo. Se lee de la entrada estándar
        fd_in = STDIN_FILENO;
    }

    // Fichero de salida. Si existe lo sobreescribe, y si no existe lo crea.
    if( (fd_out=open("./salida.txt",O_CREAT|O_TRUNC|O_WRONLY, S_IRUSR|S_IWUSR))<0) {
        printf("\nError %d en open (Out)",errno);
        perror("\nError en open");
        exit(EXIT_FAILURE);
    }

    int n_bloque = 0;
    const int TAM_BLOQUE = 80;
    char buff[TAM_BLOQUE];	// Buffer en el que se almacena lo leído

    // Lee paquetes de 80B y los escribe por bloques.
    int n_leidos;
    while (n_leidos = read(fd_in, buff, TAM_BLOQUE)){

        char cabecera[50];
        sprintf(cabecera, "\nBloque %d\n", ++n_bloque);

        // Se escribe en primer lugar el número del bloque
        write(fd_out, cabecera, strlen(cabecera));

        // Se escriben los bits leídos. Es importante notar que no se escriben 80, sino solo los que se ha leído.
        write(fd_out, buff, n_leidos*sizeof(char));
    }


    // Se cierran ambos archivos
    close(fd_in);
    close(fd_out);

    return EXIT_SUCCESS;
}