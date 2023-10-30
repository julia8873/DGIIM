.data
msg:    .string "¡hola, mundo!"

.text
        .extern exit
        .extern puts
        .globl main

main:
        push %rbp         # preserva rbp
        mov  %rsp, %rbp   # copia pila
        
        mov $msg, %rdi    # apila msg
        call puts         # llamada a puts
        
        xor %rdi, %rdi    # valor de retorno
        call exit         # llamada a exit
        
        pop %rbp          # recupera rbp
