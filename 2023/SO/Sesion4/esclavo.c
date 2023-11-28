/*
 * esclavo.c
 * Recibe un intervalo y busca los números primos entre esos dos intervalos
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int min = argv[1];
    int max = argv[2];
    int primos = 0;
    int i, j, flag;

    for (i = min; i <= max; i++) {
        if (i == 1 || i == 0)
            continue;

        flag = 1;

        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            primos++;
        }
    }

    printf("\n Primos 2 son: %d", primos);

    return (0);

}