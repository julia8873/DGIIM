#################################################
# printf32.s
# gcc -m32 printf32.s -o printf32
#################################################

.extern printf     # printf en otro sitio
.globl main        # función principal

#################################################

.data
i:      .int 12345         # variable entera
f:      .string "i = %d\n" # cadena de formato

#################################################

.text
main:   push  i            # apila i
        push  $f           # apila f
        xor   %eax, %eax   # n de registros vectoriales
        call  printf       # llamada a printf
        add   $8, %esp     # restaura pila

        movl  $1, %eax     # exit
        xorl  %ebx, %ebx   # 0
        int   $0x80        # llamada a exit

#################################################
