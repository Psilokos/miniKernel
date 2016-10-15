;print a string pointed to by DS:SI;
print:
	push ax
	push bx
.print_loop:
	lodsb		; mov al, [ds:si] ; inc si
	or al, 0
	jz .return
	mov ah, 0xe
	mov bx, 0x7
	int 0x10
	jmp .print_loop
.return:
	pop bx
	pop ax
	ret

reboot:
	call print
	mov si, reboot_msg
	call print
	mov ah, 0x0
	int 0x16	; read a char from the keyboard
	int 0x19

reboot_msg:		db 'Press any key to reboot the computer... ', 0
