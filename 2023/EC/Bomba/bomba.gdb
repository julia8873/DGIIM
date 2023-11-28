# P4,E2:ejecutable sin comprobaciones
# Automatizar modifs a los dos saltos
# Pensado para "source bomba.gdb"
# desde shell: gdb –q –x bomba.gdb
# renombrar fichero "bomba-gdb.gdb"
# que no se cargue auto "file bomba"


### permitir escribir en ejecutable
set write on

### reabrir ejecutable con perm. r/w
file bomba

### comprobar direcciones a cambiar
x/i 0x4012ad
x/i 0x40132a

### realizar los cambios
set {char} 0x4012ad=0xeb
set {char} 0x40132a=0xeb

### comprobar instrucciones cambiadas
x/i 0x4012ad
x/i 0x40132a

### salir para desbloquear ejecutable
quit