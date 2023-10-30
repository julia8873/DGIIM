#include <stdio.h>			// para printf()
#include <stdlib.h>			// para exit()

int lista[]={1,2,10,  1,2,0b10,  1,2,0x10};
int longlista= sizeof(lista)/sizeof(int);
int resultado= 0;


int suma(int* array, int len){
	
	asm("mov  $0, %eax		\n"
	"mov  $0, %rdx			 \n" 
	"bucle:													 \n"
		"add  (%rdi,%rdx,4), %eax					\n"
		"inc   %rdx												\n"
		"cmp   %rdx,%rsi									\n"
		"jne    bucle											\n"
	
	);
}

int main()
{
    resultado = suma(lista, longlista);
    printf("resultado = %d = %0x hex\n",
           resultado,resultado);
    exit(0);
}

