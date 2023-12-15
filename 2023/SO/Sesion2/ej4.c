
/*
Ej4 -> mismo que ej3 pero usando nftw()
*/

#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>		//Needed for open
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>		// Needed por managing directories

#include <ftw.h>

int tama = 0;
int total = 0;
const mode_t perm = S_IXGRP | S_IXOTH;

int visitar(const char*path, const struct stat* atributos, int flags, struct FTW* ftw){

    if((flags != FTW_D) && ((atributos->st_mode & perm) == perm)) {
            printf("%s %li \n", path, atributos->st_ino);
            total++;
            tama+= atributos->st_size;
    }

    return 0;
}


int main(int argc, char *argv[]){

    if(nftw(argc >=2 ? argv[1] : ".", visitar, 10,0) != 0){
        perror("nftw");
    }

    printf("\nLos i-nodos son: \n");

    printf("\nExisten %i archivos regulares con permiso x para grupos y otros\n", total);
    printf("\nEl tamano total ocupado por dichos archivos es %i bytes\n", tama);

}
