;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 
; @file     sandbox.asm
;
; @brief    this is just a normal elf32 assembly
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
	
	mov eax, 0x01
	mov ebx, 0x00
	syscall
