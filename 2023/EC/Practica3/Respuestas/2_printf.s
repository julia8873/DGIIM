# suma.s del Guión anterior
# 0.- ensamblar, linkar y depurar con
#	as  -g   suma.s -o suma.o
#	ld       suma.o -o suma
#	gdb -tui suma

.section .data
lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
longlista:	.int (.-lista)/4
resultado:	.int 0
formato:	.asciz "resultado = %d = 0x%x hex\n"

.section .text
_start:	.global _start

	mov     $lista, %rdi
	mov  longlista, %esi
	call suma
	mov  %eax, resultado	# res = suma(&lista,longlista);
	
	mov $formato, %rdi
	mov resultado, %esi
	mov resultado, %edx
	mov    $0, %eax
	call printf
	
	mov    $0, %edi
	call exit			# _exit(resultado);

suma:
	mov  $0, %eax		# acumulador
	mov  $0, %rdx		# índice
bucle:
	add  (%rdi,%rdx,4), %eax
	inc   %edx
	cmp   %edx,%esi
	jne    bucle

	ret
