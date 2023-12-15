
/*
P2_Ejercicio_2.c
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

int main(int argc, char *argv[]){

    if(argc != 2 && argc != 1){
        printf("\nError en argumentos. <ej3.c> <pathname>");
        exit(-1);
    }

    // Abrimos directorio

    DIR *directorio;

    if((directorio = opendir(argv[1])) == NULL){
        printf("\nError en open");
        exit(-1);
    }

    // Máscara
    mode_t mask = S_IXGRP | S_IXOTH;
    struct stat atributos;

    struct dirent *entry;
    int total = 0;
    int tama = 0;

    printf("\nLos i-nodos son:\n");

    while((entry = readdir(directorio)) != NULL){

        // Se saltan los directorios que mantienen la jerarquía
        if ((strcmp(entry->d_name, "." )==0) || (strcmp(entry->d_name, "..")==0))
            continue;

        char path_entrada[500];	// Compongo para que las rutas sean absolutas, ya que si no, no funciona
        sprintf(path_entrada, "%s/%s", argv[1], entry->d_name);

        // tipo y permisos de entrada
        if(lstat(path_entrada, &atributos) < 0){
            printf("\nError en lstat");
            exit(-1);
        }else{
            if(((atributos.st_mode & mask) == mask) && S_ISREG(atributos.st_mode)){
                printf("%s %li \n", entry->d_name, entry->d_ino);
                total ++;
                tama += atributos.st_size;
            }
        }
    }

    printf("\nExisten %i archivos regulares con permiso x para grupos y otros\n", total);
    printf("\nEl tamano total ocupado por dichos archivos es %i bytes\n", tama);
    closedir(directorio);

    return (EXIT_SUCCESS);

}