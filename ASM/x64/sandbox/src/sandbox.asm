;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 
; @file     sandbox.asm
;
; @brief    this is just a normal elf64 assembly
;           sandbox to experiment something out!
;
; @author   Jerico G. Despe
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

section .text
	global _start

_start:

	; Insert instructions here and EXPERIMENT! >:)
	; ENJOY!
	
	mov rax, 0x3C ; Set system call to EXIT
	xor rdi, rdi  ; Set error code to 0
	syscall       ; Make kernel call
