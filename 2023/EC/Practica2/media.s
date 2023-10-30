.section .data
lista: 		.int 0x0fffffff
longlista:	.int 16
resultado:	.int 0

formato:	.asciz "suma = %u = 0x%x hex\n"

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
	mov	longlista, %ecx
	call	suma
	mov	%eax, resultado
	ret

suma:
	push	%rdx
	mov	$0, %eax
	mov 	$0, %rdx
bucle:
	add	(%rbx), %rax
	inc	%edx
	cmp	%edx,%ecx

	jne	bucle
	pop	%rdx
	ret

imprim_C:
	mov	$formato, %rdi
	mov	resultado, %esi
	mov	resultado, %edx
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

