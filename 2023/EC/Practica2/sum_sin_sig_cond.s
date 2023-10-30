.section .data
lista: 		.int 0x10000000, 0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000, 0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000

longlista:	.int (.-lista)/4
resultado:	.quad 0

formato:	.asciz "suma = %lu = 0x%lx hex\n"

.section .text
#_start:	.global _start
main:	.global main
	call trabajar
	call imprim_C
	call acabar_L
	call acabar_C
	ret

trabajar:
	mov	$lista, %rbx
	mov	longlista, %rcx
	call	suma
	mov	%eax, resultado
	mov	%edx, resultado+4
	ret

suma:
	mov 	$0, %r8
	mov	$0, %eax
	mov 	$0, %rdx
	
bucle:
	add	(%rbx,%r8,4), %eax
	jnc	no_acarreo
	add 	$1, %edx
	ret
	
no_acarreo:
	inc	%r8
	cmp	%r8, %rcx
	jne	bucle
	ret
	
imprim_C:
	mov	$formato, %rdi
	mov	resultado, %rsi
	mov	resultado, %rdx
	mov 	$0, %eax
	call	printf
	ret

acabar_L:
	mov	$60, %rax
	mov	resultado, %edi
	syscall
	ret
acabar_C:
	mov	resultado, %edi
	call	exit
	ret

