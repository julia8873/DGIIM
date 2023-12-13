// ej3.c
/*
 Suspende la ejecución del proceso actual hasta que se reciba la señal SIGUSR1
*/

#include <stdio.h>
#include <signal.h>

int main()
{
    sigset_t new_mask;

    /* inicializar la nueva mascara de se�ales */
    sigemptyset(&new_mask);

    // Llenamos set con todas las señales excepto SIGUSR1
    sigfillset(&new_mask);
    sigdelset(&new_mask, SIGUSR1);

    /*esperar a señal SIGUSR1 */
    sigsuspend(&new_mask);

}