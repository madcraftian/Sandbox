bits 16

segment .data
	msg db 'Hello, world!', 0x0D, 0x0A, '$'

segment stack stack
	resb 256

segment code
..start:
	mov ax, data
	mov ds, ax
	
	mov ah, 09h
	mov dx, msg
	int 21h

	mov ax, 4c00h
	int 21h
