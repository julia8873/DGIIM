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

int main(int argc, char *argv[]){
    int fd[2];
    pid_t PID;
    char buffer[80];

    // Intervalos
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    // Imprimir números
    printf("\n Intervalo: %d - %d", min, max);

    pipe(fd);

    if( (PID = fork() < 0)){
        perror("\nError en fork");
        exit(-1);
    }

    // Dividir intervalos
    int max_1 = max/2;
    int min_2 = max_1 +1;


    if(PID == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        printf("Soy Hijo. Enviando Argumentos \n");
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