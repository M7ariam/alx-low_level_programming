section .data
    message db 'Hello, Holberton', 0xA, 0

section .text
    global main

    extern printf

main: 
          mov   edi, format
	  xor   eax, eax
	  call  printf
	  mov 	eax, 0
	  ret
format: db `Hello, Holberton\n`,0
