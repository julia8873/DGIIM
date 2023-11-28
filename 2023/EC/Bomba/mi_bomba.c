// gcc -Og bomba.c -o bomba -no-pie -fno-guess-branch-probability
#include <stdio.h> // para printf(), fgets(), scanf()
#include <stdlib.h> // para exit()
#include <string.h> // para strncmp()
#include <sys/time.h> // para gettimeofday(), struct timeval
#include <string.h>

#define SIZE 100
#define TLIM 60
char password[]="sumbrolle\n"; // contraseña encriptada
int passcode = 49791; // pin


void boom(void){
    printf( "\n"
            "***************\n"
            "*** BOOM!!! ***\n"
            "***************\n"
            "\n");
    exit(-1);
}
void defused(void){
    printf( "\n"
            "·························\n"
            "··· bomba desactivada ···\n"
            "·························\n"
            "\n");
    exit(0);
}

// CODIFICAR CONTRASEÑA
// VOCALES: aeiou
//     a = e  e = i  i = o  o = u  u = a

void encrypt_psswd(char encrypted[]) {
    char letra;

    for (int i = 0; i < strlen(encrypted); i++) {
        letra = encrypted[i];
        switch (letra) {
            case 'a':
                encrypted[i] = 'e';
                break;
            case 'e':
                encrypted[i] = 'i';
                break;
            case 'i':
                encrypted[i] = 'o';
                break;
            case 'o':
                encrypted[i] = 'u';
                break;
            case 'u':
                encrypted[i] = 'a';
                break;
        }
    }
}


// CODIFICAR PIN
// NÚMEROS:
//     1 = 8 ; 2 = 7 ; 3 = 6 ; 4 = 5

void encrypt_passcode(int *encrypted) {
    // Convertir el entero a una cadena de caracteres
    char str[SIZE];
    sprintf(str, "%d", *encrypted);

    // Restar 9 a cada dígito
    for (int i = 0; i < strlen(str); i++) {
        str[i] = '0' + ('9' - str[i]);
    }

    // Convertir la cadena de nuevo a un entero
    sscanf(str, "%d", encrypted);
}



int main(){
    char pw[SIZE], encrypted_pw[SIZE], pc_str[SIZE];
    int pc, n, encrypted_pc;

    struct timeval tv1,tv2; // gettimeofday() secs-usecs
    gettimeofday(&tv1,NULL);

    do printf("\nIntroduce la contraseña: ");
    while ( fgets(pw, SIZE, stdin) == NULL );

    // CODIFICAR CONTRASEÑA
    strcpy(encrypted_pw, pw);
    encrypt_psswd(encrypted_pw);    // sombrilla -> sumbrolle

    if ( strncmp(encrypted_pw,password,sizeof(password)) )
        boom();

    gettimeofday(&tv2,NULL);
    if ( tv2.tv_sec - tv1.tv_sec > TLIM )
        boom();


    do { printf("\nIntroduce el pin: ");
        // primero comprueba si es un int
        // Sigue pidiendo contraseña hasta que sea int
        if ((n=scanf("%i",&pc))==0)
            // Si es int pone n a 1
            scanf("%*s" )==1; }
    while ( n!=1 );

    // CODIFICAR PIN
    encrypted_pc = pc;
    encrypt_passcode(&encrypted_pc);   // 50208  -> 49791

    if ( encrypted_pc != passcode )
        boom();

    gettimeofday(&tv1,NULL);
    if ( tv1.tv_sec - tv2.tv_sec > TLIM )
        boom();
    defused();

}