.section .data
lista: 	.int 0,-1

#.int 0x10000000, 0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000, 0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000,0x10000000


longlista:	.int (.-lista)/4
resultado:	.quad 0
formato:	.asciz "suma = %ld = 0x%lx hex\n"

.section .text
#_start:	.global _start
main:	.global main
	call trabajar
	call imprim_C
	call acabar_C
	ret

trabajar:
	mov	$lista, %rbx
	call suma
	mov	%esi, resultado
	mov	%edi, resultado+4
	ret
	
suma:
	mov $0, %eax
	mov 	$0, %esi
	mov	$0, %edi 
	mov  $0, %rcx
	
bucle:
	mov (%rbx, %rcx, 4), %eax
	cltd
	add	%eax, %esi
	adc   %edx, %edi
	inc	%rcx
	cmp	%rcx, longlista
	jne	bucle
	ret
	
imprim_C:
	mov	$formato, %rdi
	mov	resultado, %rsi
	mov	resultado, %rdx
	mov 	$0, %rax
	call	printf
	ret
	
acabar_C:
	mov $0, %rax
	mov	resultado, %edi
	call	_exit
	ret
