/*
 * ej1.c
 *
 * Ejecución: <ej1.c> <numero>
 *
 * Programa crea proceso hijo que se encarga de comprobar si dicho número es un número par o impar
 * El proceso padre comprobará si dicho número es divisible por 4 e informará si lo es o no
 *
 */

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

    // Comprobamos argumentos

    if(argc != 2){
        printf("\nError numero de argumentos. Ejecutar: <ej1.c> <numero>\n");
        exit(-1);
    }

    // Coger número
    int num = atoi(argv[1]);


    // Creamos hijo
    pid_t pid;

    if((pid = fork()) < 0){
        printf("\nError en el fork");
        exit(-1);
    }else if(pid == 0){ // hijo
        if(num % 2 == 0)  printf("\n%i es par\n", num);
        else printf("\n%i es impar\n", num);
    }else{  // Padre
        sleep(1);
        if(num % 4 == 0) printf("\n%i es divisible por 4\n", num);
        else printf("\n%i no es divisible por 4\n", num);
    }

    return EXIT_SUCCESS;

}