//P3_Ejercicio_4.c

#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

#include <sys/wait.h>

int main(int argc, char *argv[]){

    int procs_vivos = 5;	// Número de hijos vivos

    pid_t pid_hijos[procs_vivos]; // Array para guardar los PID de los hijos

    pid_t retval;
    for (int i=0; i<procs_vivos; i++){		// Creación de los procesos hijos
        if ((retval = fork()) < 0){
            printf("Error al crear el proceso hijo\n");
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (retval == 0){	// Código del hijo
            printf("Soy el hijo %d, mi padre es %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }

        pid_hijos[i] = retval;
    }

    for(int i=0; i<procs_vivos; i+=2){ // Empezamos por los impares

        if((retval = waitpid(pid_hijos[i], NULL, 0)) <= 0){
            printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        printf("\n Impares: \n");
        printf("Acaba de finilizar mi hijo con PID %d\n", retval);
        printf("Solo me quedan %d hijos vivos\n", --procs_vivos);

    }

    for(int i=1; i<procs_vivos; i+=2){ // Empezamos por los impares

        if((retval = waitpid(pid_hijos[i], NULL, 0)) <= 0){
            printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        printf("\n Pares: \n");
        printf("Acaba de finilizar mi hijo con PID %d\n", retval);
        printf("Solo me quedan %d hijos vivos\n", --procs_vivos);

    }


    exit(EXIT_SUCCESS);
}