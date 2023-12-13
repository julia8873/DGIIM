/*
 * Ejercicio 6.1
 * Admite t argumentos.
 *  1. orden de línux
 *  2. "<" o ">"
 *  3. Nombre de un archivo (puede existir o no)
 *  Programa ejecutará la orden que se especifica en 1 e implementará la redirección especificada por 2 hacia 3
 *  Ej: ./ej1.c sort "<" temporal
 *  redirecciona la entrada estándar de sort desde un archivo temporal
 */

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[]){

    if(argc != 4){
        printf("Ejecutar: ./ej1 <comando> <salida o entrada> <archivo>\n");
        exit(-1);
    }

    if( fd = open(argv[3], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR) == 0){
        perror("error en el open\n");
        exit((-1));
    }

    pid_t pid;
    if ( (pid = fork()) < 0){
        perror("\nError en el fork");
        exit(-1);
    }else if(pid == 0){ // Hijo

        if(!strcmp(argv[2], "<")){  // strcmp devuelve 0 si es true
            // Redirigimos la salida con cauce para que lo que se ejecute en el hijo se meta en el fd
            close(STDOUT_FILENO);

            if(fcntl(fd, F_DUPFD, STDOUT_FILENO) == -1)  // también se puede hacer con dup
                perror ("fallo fcntl\n");


            execlp(argv[1], argv[1], argv[3], NULL);

        }else if(!strcmp(argv[2], ">")){
        }
    }
    exit(0);
}