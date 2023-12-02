# Practica 4, Actividad 4.1: explicacion de la bomba

# CONTRASEÑA: sombrilla
# PIN: 50208

# MODIFICADA: sumbrolle
# PIN: 49791

# Describe el proceso logico seguido
# primero: para descubrir las claves, y
# despues: para cambiarlas
# Pensado para ejecutar mediante "source explain.gdb"
# o desde linea de comandos con gdb -q -x explain.gdb

# Renombrar temporalmente el fichero "bomba-gdb.gdb"
# para que no se cargue automat. al hacer "file bomba"

# funciona sobre la bomba original, para recompilarla
# usar la orden gcc en la primera linea de bomba.c
# gcc -Og bomba.c -o bomba -no-pie -fno-guess-branch-probability

########################################################
### DESENCRIPTAR CONTRASEÑA
########################################################
### cargar el programa
    gdb bomba
### util para la sesion interactiva, no para source/gdb -q -x
# layout asm
# layout regs
### arrancar programa
### Miramos donde se define la función <encrypt_psswd>
    br *main+131
    run
### Introducimos 'hola' como contraseña
# Podemos imprimir el valor de rax
#  p(char*) $rax   # -> sale 'hola\n'

### Vamos hasta el primer jump <encrypt_psswd+165>
    br *encrypt_psswd+165
    
### continuamos con ni hasta <encrypt_psswd+201>
# Notamos que se llama a strlen para coger la longitud de la contraseña
# Podemos ver que $rax = 5 -> longitud de la contraseña 'hola\n'
# También notamos que en $rbx hay un contador que empieza desde 0
# Luego hay un jb -> Entonces estamos recorriendo la contraseña

### En <encrypt_psswd+42> vemos que se mueve el primer caracter 'h' al registro $eax
# Ahora eax = 104 que en ASCII es 'h'

### Continuamos hasta el cmp en <encrypt_psswd+55>
# antes hemos restado 0x61 a $rax, dejándolo con 7, que en ASCII es [bell]
# Notamos que en cmp se compara con el valor 0x14 que es [SHIFT OUT] en ASCII
# entonces en este caso no entra

### Podemos seguir avanzando e ir imprimiendo el valor de $rax
# Vemos como cambia la contraseña

### Notemos que en el <encrypt_psswd+58>
# No se salta si la letra guardada es una vocal, en cuyo caso la modifica

### En el <encrypt_psswd+111> el valor de $rax es e
# Es decir, ha pasado de a -> e.


### Notemos que en <main+155> se mueve a %rdi el valor de la 
###   contraseña ya encriptada
# Imprimimos contraseña encriptada
	p(char*) $rdi    # -> sale 'hule\n'

### Podemos repetir el proceso metiendo contraseñas con vocales
# y ver cual es el patrón:
# a->e, e->i, i->o, o->u, u->a

### Tenemos la contraseña encriptada guardada en la dirección 0x404070
# Imprimimos con:
	p(char*) 0x404070
# Nos sale "sumbrolle\n"
### Desencriptamos con el patrón anterior -> contraseña = "sombrilla"

    
########################################################

########################################################
### DESENCRIPTAR PIN (procedimiento análogo)
########################################################
### cargar el programa
    gdb bomba
### util para la sesion interactiva, no para source/gdb -q -x
# layout asm
# layout regs
### arrancar programa
### Miramos donde se define la función <encrypt_passcode>
    br *encrypt_passcode
    run
### Introducimos la contraseña ya desencriptada de antes:
    sombrilla
### Introducimos como pin 12345

### Tenemos el pin original en 0x40407c
# Imprimir con p/d *0x40407c -> sale 49791

### Continuamos hasta <encrypt_passcode+214>
# El valor de nuestro pin encriptado está en %rsi
### Alternativamente podemos ir hasta el main,
# Antes del cmp, en <main+353> y ver el valor de %edx

### Nuestro pin nuevo -> 87654
# Entonces, lo que se ha hecho es:
# 1->8, 2->7, 3->6, 4->5, 5->4
### Si ponemos otro pin, veremos que:
# 1<->8, 2<->7, 3<->6, 4<->5, 0<->9

### Cogemos el pin encriptado original:
# 49791 = 50208

### Introducimos entonces:
# Contraseña: sombrilla
# PIN: 50208

    
########################################################
### DESACTIVAR BOMBA SIN CONTRASEÑA NI PIN
########################################################
### cargar el programa
    gdb bomba
### util para la sesion interactiva, no para source/gdb -q -x
# layout asm
# layout regs
### arrancar programa
    br main
    run
### Notemos que en la línea <main+167> se llama a <boom> por
### por lo que tendremos que hacer un break en el test antes del je
    br *main+163
    cont
### escribir "hola" cuando pida contraseña
### ahora mismo estamos viendo de donde sale la contraseña
### 0x401520 <main+145> lea 0x2b49(%rip),%rsi # 0x404070 <password>
### imprimir la contraseña y recordar que esta en 0x404070 longitud 13B
# p(char* )$rsi
# p(char* )0x404070
    p(char[0xd])password
# Sale "sumbrolle\n\000\000\177"
### dejar que strncmp salga mal y corregir eax=0 para evitar boom()
    set $eax=0
    ni
### siguiente bomba es por tiempo
### Rompemos en el cmp
### Falsear tiempo = 0 -> ponemos rdx a 0
    br *main+209
    set $rdx=0
### siguiente bomba es por pin
### Rompemos en el cmp y ponemos rdx a 0
    br *main+353
### escribir "123" cuando pida pin
### imprimir el pin y recordar que esta en 0x40407c tipo int
# p*(int*)0x40407c
    p (int )passcode
### Hacemos que el cmp de true poniendo el pin correcto
    set $edx=49791

### siguiente bomba es por tiempo
### Rompemos en el cmp
### Falsear tiempo = 0 -> ponemos rdx a 0
    br *main+399
    set $rdx=0
    cont
### hemos llegado al final
    quit
########################################################

### permitir escribir en el ejecutable
set write on
### reabrir ejecutable con permisos r/w
file bomba
### realizar los cambios
set {char[13]}0x404070="sumbrolle\n"
set {int }0x40407c=49791
### comprobar las instrucciones cambiadas
p (char[0xd])password
p (int )passcode
### salir para desbloquear el ejecutable
quit
########################################################
