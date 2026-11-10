;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; @file     entry.asm
;
; @brief    this is just a normal elf64 assembly
;           program that prints "Hello, world!"
;           on the terminal screen
;
; @author   Jerico G. Despe
;

; FILE DESCRIPTORS:
%assign STDOUT      0x01

; SYSTEM CALLS
%assign WRITE       0x01
%assign EXIT        0x3C

section .text
	global _start:          ; Entry point

_start:
	mov rdi, STDOUT         ; set file descriptor to stdout
	mov rax, WRITE          ; set system call to write
	mov rsi, helloWorld     ; initialize char buff
	mov rdx, helloWorldLen  ; initialize char count
	syscall                 ; call kernel

	xor rdi, rdi            ; set error_code to 0 due to no errors
	mov rax, EXIT           ; set system call to exit
	syscall                 ; call kernel

section .data
	helloWorld     db "Hello, world!", 0x0A
	helloWorldLen  equ $- helloWorld
