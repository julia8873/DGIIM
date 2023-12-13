/*
contador.c
 Recibe una señal que se pueda manejar
 Muestra por pantalla la señal + número de veces que se ha recibido ese tipo de señal
 Mensaje inicial indicando las señales que no puede manejar
*/


#include <sys/types.h> //POSIX Standard: 2.6 Primitive System Data Types
#include<limits.h> //Incluye <bits/posix1_lim.h> POSIX Standard: 2.9.2 //Minimum    //Values Added to <limits.h> y <bits/posix2_lim.h>
#include <unistd.h> //POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static void sig_hdlr(int sigNum) {
    static int count[NSIG] = {0}; // Arreglo para contar las señales recibidas
    count[sigNum]++; // Incrementar el contador para la señal actual
    printf("\nRecibida la señal %d. Veces recibidas: %d\n\n", sigNum, count[sigNum]);
}

int main(int argc, char *argv[]){

    struct sigaction sig_act;

    // Vaciar búffer
    if(setvbuf(stdout,NULL,_IONBF,0)){
        perror("\nError en setvbuf");
    }

    printf("Esperando al envio de senales... \n");

    //Inicializar la estructura sig_USR_na para especificar la nueva acci�n para la se�al.
    sig_act.sa_handler = sig_hdlr;

    //'sigemptyset' inicia el conjunto de se�ales dado al conjunto vacio.
    sigemptyset (&sig_act.sa_mask);
    sig_act.sa_flags = 0;

    // Iterar a través de todas las señales posibles y establecer el mismo manejador para cada una
    for (int signal = 1; signal < NSIG; signal++) {
        if (sigaction(signal, &sig_act, NULL) < 0) {
            perror("\nNo puedo manejar la señal ");
            printf("%d \n", signal);
        }
    }

    for (;;) {
        // Esperar indefinidamente
    }

    return 0;
}