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
#include <sys/stat.h>
#include <math.h>

int main(int argc, char *argv[]) {

    if(argc != 4) {
        return 1;
    }

    int min = strtol(argv[1], NULL, 10);
    int max = strtol(argv[2], NULL, 10);

    int fd = strtol(argv[3], NULL, 10);

    for (int i = min; i <= max; ++i) {
        int isPrime = 1;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            // Send the prime number to the master
            write(fd, &i, sizeof(int));
        }
    }

    return (0);

}