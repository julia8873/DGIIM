#include <stdio.h> // para printf()
#include <stdlib.h> // para exit()
#include <sys/time.h> // para gettimeofday(), struct timeval
#include <stdint.h>

int resultado=0;

#ifndef TEST
#define TEST 1
#endif
/* -------------------------------------------------------------------- */
	#if TEST==1	
/* -------------------------------------------------------------------- */
		#define SIZE 4
		unsigned lista[SIZE]={0x80000000, 0x00400000, 0x00000200, 0x00000001};
		#define RESULT 4
/* -------------------------------------------------------------------- */
#elif TEST==2
/* -------------------------------------------------------------------- */
	#define SIZE 8
		unsigned lista[SIZE]={0x7fffffff, 0xffbfffff, 0xfffffdff, 0xfffffffe,
	0x01000023, 0x00456700, 0x8900ab00, 0x00cd00ef};
	#define RESULT 2
/* -------------------------------------------------------------------- */
#elif TEST==4 || TEST==0
/* -------------------------------------------------------------------- */
		#define NBITS 20
		#define SIZE (1<<NBITS) // tamaño suficiente para tiempo apreciable
		unsigned lista[SIZE]; // unsigned para desplazamiento derecha lógico
		#define RESULT ( ? * ( ? << ?-1 ) ) // pistas para deducir fórmula
/* -------------------------------------------------------------------- */
#else
		#error "Definir TEST entre 0..4"
	
#endif
/* -------------------------------------------------------------------- */

#define WSIZE 8*sizeof(long)
int popcount1(unsigned * array, size_t len)
{
	int result = 0;
	size_t j;
	
	for (int i = 0; i < len; i++){
		
		unsigned long x = array[i];
		
		for(j=0; j< WSIZE; j++){
			result += x & 0x1;
			x >>= 1;
		}
		
	}
	
	return result;
}

int popcount2(unsigned* array, size_t len)
{
	int result = 0;
	
	for(int i=0; i<len; i++){
		unsigned long x = array[i];
		
		while (x){
			result += x & 0x1;
			x >>= 1;
		}
	}
	
	
	return result;
}

int popcount3(unsigned* array, size_t len){
	
	int result = 0;
	
	for (int i=0; i<len; i++) {
		unsigned long x = array[i];
		
		asm("\n"
        "ini3: \n\t"
        "shr %[x] \n\t"
        "adc $0, %[r] \n\t" // Utilizamos ADC para sumar directamente el acarreo al resultado
		"test %[x], %[x] \n\t"
        "jnz ini3 \n\t" // Saltar si el resultado de SHR no es cero (ZF=0)
        : [r]"+r" (result)
        : [x] "r" (x)
		);
	}
	return result;
} 

int popcount4(unsigned* array, size_t len){
	
	int result = 0;
	
	for(int i=0; i<len; i++){
		unsigned long x = array[i];
		
		asm( "\n"
			"clc			\n\t"   // clear carry flag
		"ini4:					\n\t"
			"adc $0, %[r]  \n\t" 
			"shr %[x] 		\n\t"  // Desplazamos x a la derecha
			"jnz ini4 			\n\t"  // Volvemos al bucle si ZF != 0 (si es 0 ha acabado)
		"fin4:					\n\t"
			"adc $0, %[r]  \n\t"   // Por si último bit es 1
			
		: [r] "+r" (result)
		: [x] "r" (x));
	}
	return result;
}

int popcount5(unsigned * array, size_t len){
	int result = 0;
	int i;
	
	for(int j=0; j<len; j++){
		unsigned long x = array[j];
		long val = 0;
		for( i=0; i < 8; i++){
			val += x & 0x0101010101010101L;
			x >>= 1;
		}
		
		val += (val >> 32);
		val += (val >> 16);
		val += (val >> 8);
		result += val & 0xFF;
		
	}
	return result;
}

//types and constants used in the functions below
//uint64_t is an unsigned 64-bit integer type (defined in C99 version of C language)
const uint64_t m1 = 0x5555555555555555; //binary: 0101...
const uint64_t m2 = 0x3333333333333333; //binary: 00110011..
const uint64_t m4 = 0x0f0f0f0f0f0f0f0f; //binary: 4 zeros, 4 ones ...
const uint64_t m8 = 0x00ff00ff00ff00ff; //binary: 8 zeros, 8 ones ...
const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones

//This is a naive implementation, shown for comparison,
int popcount6(unsigned * array, size_t len)
{
	int result = 0;
	
	for(int i=0; i<len; i++){
		uint64_t x = array[i];
		
		x = (x & m1 ) + ((x >> 1) & m1 ); //put count of each 2 bits into those 2 bits
		x = (x & m2 ) + ((x >> 2) & m2 ); //put count of each 4 bits into those 4 bits
		x = (x & m4 ) + ((x >> 4) & m4 ); //put count of each 8 bits into those 8 bits
		x = (x & m8 ) + ((x >> 8) & m8 ); //put count of each 16 bits into those 16 bits
		x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits
		x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into those 64 bits
		
		result += x;
		
	}
	
	return	result;
}

// Wikipedia popcount "naive" implementation *** 128b ***
int popcount7(unsigned* array, size_t len)
{
	size_t i;
	unsigned long x1,x2;
	int result=0;
	
	if (len & 0x3) printf("leyendo 128b pero len no múltiplo de 4\n");
	
	for (i=0; i<len; i+=4)
	{
		x1 = *(unsigned long*) &array[i];
		x2 = *(unsigned long*) &array[i+2];
		
		x1 = (x1 & m1 ) + ((x1 >> 1) & m1 ); //put count of each 2 bits into those 2 b
		x1 = (x1 & m2 ) + ((x1 >> 2) & m2 ); //put count of each 4 bits into those 4 bits
		x1 = (x1 & m4 ) + ((x1 >> 4) & m4 ); //put count of each 8 bits into those 8 bits
		x1 = (x1 & m8 ) + ((x1 >> 8) & m8 ); //put count of each 16 bits into those 16 bits
		x1 = (x1 & m16) + ((x1 >> 16) & m16); //put count of each 32 bits into those 32 bits
		x1 = (x1 & m32) + ((x1 >> 32) & m32); //put count of each 64 bits into those 64 b
		
		x2 = (x2 & m1 ) + ((x2 >> 1) & m1 );
		x2= (x2 & m2 ) + ((x2 >> 2) & m2 ); //put count of each 4 bits into those 4 bits
		x2 = (x2 & m4 ) + ((x2 >> 4) & m4 ); //put count of each 8 bits into those 8 bits
		x2 = (x2 & m8 ) + ((x2 >> 8) & m8 ); //put count of each 16 bits into those 16 bits
		x2 = (x2 & m16) + ((x2 >> 16) & m16); //put count of each 32 bits into those 32 bits
		x2 = (x2 & m32) + ((x2 >> 32) & m32);
		
		
		result+= x1+x2;
	}
	return result;
}

// Versión SSSE3 (pshufb) web http:/wm.ite.pl/articles/sse-popcount.html
int popcount8(unsigned* array, size_t len){
	size_t i;
	int val, result=0;
	int SSE_mask[] = {0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
	int SSE_LUTb[] = {0x02010100, 0x03020201, 0x03020201, 0x04030302};
	// 3 2 1 0 7 6 5 4 1110 9 8 15141312
	if (len & 0x3) printf("leyendo 128b pero len no múltiplo de 4\n");
	for (i=0; i<len; i+=4) {
			asm("movdqu %[x], %%????\n\t"
			"movdqa %%xmm0, %%???? \n\t" // x: two copies xmm0-1
			"movdqu %[m], %%???? \n\t" // mask: xmm6
			"psrlw $4 , %%???? \n\t"
			"pand %%xmm6, %%xmm0 \n\t" //; xmm0 – lower nibbles
			"pand %%xmm6, %%xmm1 \n\t" //; xmm1 – higher nibbles
			"movdqu %[l], %%???? \n\t" //; since instruction pshufb modifies LUT
			"movdqa %%xmm2, %%???? \n\t" //; we need 2 copies
			"pshufb %%xmm0, %%xmm2 \n\t" //; xmm2 = vector of popcount lower nibbles
			"pshufb %%xmm1, %%xmm3 \n\t" //; xmm3 = vector of popcount upper nibbles
			"paddb %%????, %%xmm3 \n\t" //; xmm3 – vector of popcount for bytes
			"pxor %%????, %%xmm0 \n\t" //; xmm0 = 0,0,0,0
			"psadbw %%????, %%xmm3 \n\t" //; xmm3 = [pcnt bytes0..7|pcnt bytes8..15]
			"movhlps %%????, %%xmm0 \n\t" //; xmm0 = [ 0 |pcnt bytes0..7 ]
			"paddd %%????, %%xmm0 \n\t" //; xmm0 = [ not needed |pcnt bytes0..15]
			"movd %%xmm0, %[val] "
			: [val]"=r" (val)
			: [x] "m" (array[i]),
			[m] "m" (SSE_mask[0]),
			[l] "m" (SSE_LUTb[0])
		);
		result += val;
	}
	return result;
}

/*
// Versión SSE4.2 (popcount)
int popcount9(unsigned* array, size_t len){
size_t i;
unsigned x;
int val, result=0;
for (i=0; i<len; i++)
{
x = array[i];
asm("popcnt %???, %???"
: [val] "=r" (val)
: [x] "r" (x)
);
result += val;
}
return result;
}
*/

/*
// popcount 128bit p/mejorar prestaciones
int popcount10(unsigned* array, size_t len){
size_t i;
unsigned long x1,x2;
long val; int result=0;
if (len & 0x3) printf(
"leyendo 128b pero len no múltiplo de 4\n");
for (i=0; i<len; i+=4) {
x1 = *(unsigned long*) &array[i ];
x2 = *(unsigned long*) &array[i+2];
asm("popcnt %[x1], %???? \n\t"
"popcnt %[x2], %???? \n\t"
"add %????, %[val]\n\t"
: [val]"=&r" (val)
: [x1] "r" (x1),
[x2] "r" (x2)
);
result += val;
}
return result;
}
*/


void crono(int (*func)(), char* msg){
	struct timeval tv1,tv2; // gettimeofday() secs-usecs
	long tv_usecs; // y sus cuentas
	
	gettimeofday(&tv1,NULL);
	resultado = func(lista, SIZE);
	gettimeofday(&tv2,NULL);
	tv_usecs=(tv2.tv_sec -tv1.tv_sec )*1E6+
	(tv2.tv_usec-tv1.tv_usec);
	
	#if TEST==0
		printf( "%ld" "\n", tv_usecs);
	#else
		printf("resultado = %d\t", resultado);
		printf("%s:%9ld us\n", msg, tv_usecs);
	#endif
}
int main()
{
	#if TEST==0 || TEST==4
	size_t i; // inicializar array
	
	for (i=0; i<SIZE; i++)
		lista[i]=i;
	#endif
	
	crono(popcount1 , "popcount1 (lenguaje C - for)");
	crono(popcount2 , "popcount2 (lenguaje C - while)");
	crono(popcount3 , "popcount3 (leng.ASM-body while 4i)");
	crono(popcount4 , "popcount4 (leng.ASM-body while 3i)");	
	crono(popcount5 , "popcount5 (CS:APP2e 3.49-group 8b)");
	crono(popcount6 , "popcount6 (Wikipedia- naive - 32b)");
	crono(popcount7 , "popcount7 (Wikipedia- naive -128b)");
	crono(popcount8 , "popcount8 (asm SSE3 - pshufb 128b)");
//	crono(popcount9 , "pkopcount9 (asm SSE4- popcount 32b)");
//	crono(popcount10, "popcount10(asm SSE4- popcount128b)");

	#if TEST != 0
		printf("calculado = %d\n", RESULT);
	#endif
	exit(0);
	
}