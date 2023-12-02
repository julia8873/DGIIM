/*
 * maestro.c
 * Recibe un intervalo y lo divide en dos
 * Se lo pasa a dos esclavos.c y estos buscan los números primos entre esos dos intervalos
 * Luego imprime los números primos
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Usage: %s <min> <max>\n", argv[0]);
        return 1;
    }

    int fd[2], fd2[2];
    pid_t PID, PID2 ;
    char buffer[80];

    // Intervalos
    int min = strtol(argv[1], NULL, 10);
    int max = strtol(argv[2], NULL, 10);
    // Imprimir números
    printf("Intervalo: %d-%d\n", min, max);
    // Dividir intervalos
    int max_1 = max/2;
    int min_2 = max_1 +1;
    printf("Intervalo 1: %d-%d\n", min, max_1);
    printf("Intervalo 2: %d-%d\n", min_2, max);



    pipe(fd);

    if( (PID = fork() < 0)){
        perror("\nError en fork");
        exit(-1);
    }

    if(PID == 0){
        printf("Soy Hijo. Enviando Argumentos \n");
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        printf("hola \n");
        execl("./esclavo", "esclavo", min, max_1, NULL);

    }else{
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        printf("Soy Padre. Recibido Argumentos \n");
        int primos = read(fd[0], buffer, sizeof(buffer));
        printf("\n Primos 1 son: %d", primos);
    }

    return(0);

}