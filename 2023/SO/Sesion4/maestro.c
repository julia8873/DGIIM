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

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: %s <min> <max>\n", argv[0]);
        return 1;
    }

    int fd[2];
    pid_t PID;

    // Intervalos
    int min = strtol(argv[1], NULL, 10);
    int max = strtol(argv[2], NULL, 10);

    // Print numbers
    printf("Intervalo: %d-%d\n", min, max);
    pipe(fd); // Llamada al sistema para crear un pipe

    // Convert to string
    char min1_str[80], max1_str[80], fd_str[80];
    sprintf(min1_str, "%d", min);
    sprintf(max1_str, "%d", max/2);
    sprintf(fd_str, "%d", fd[1]);


    if ( (PID= fork())<0) {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }

    if (PID == 0) {
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        // NOTA: si usamos execl hay que cast el Null -> (char*)NULL
        execlp("/home/julia/Desktop/DGIIM/2023/SO/Sesion4/esclavo","esclavo", min1_str, max1_str, fd_str ,NULL);
    }
    else {
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        int prime;
        while (read(fd[0], &prime, sizeof(int)) > 0) {
            printf("%d  ", prime);
        }
    }

    printf("\n");
    printf("Segundo intervalo: \n");
    // Segundo Intervalo
    int fd2[2];
    pid_t PID2;

    pipe(fd2);

    char min_2[80], max_2[80], fd2_str[80];
    sprintf(min_2, "%d\n", max/2);
    sprintf(max_2, "%d\n", max);
    sprintf(fd2_str, "%d\n", fd2[1]);

    if((PID2 =fork()) < 0){
        perror("Error en el fork");
        exit(-1);
    }

    if(PID2 == 0){
        close(fd2[0]);
        dup2(fd2[1], STDOUT_FILENO);
        execlp("/home/julia/Desktop/DGIIM/2023/SO/Sesion4/esclavo", "esclavo", min_2, max_2, fd2_str, NULL);
    }else{
        close(fd2[1]);
        dup2(fd2[0], STDIN_FILENO);
        int num;
        while(read(fd2[0], &num, sizeof(num))){
            printf("%d  ", num);
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}