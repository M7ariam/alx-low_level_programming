section .data
    message db 'Hello, Holberton', 0xA, 0

section .text
    global main

    extern printf

main: 
    push message
    mov   edi, formata
    xor   eax, eax
    call printf
    xor  eax, eax
    ret

format:
    db "%s"
