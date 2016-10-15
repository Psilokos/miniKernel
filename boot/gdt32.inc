;***********************************************;
;*    GLOBAL DESCRIPTOR TABLE (GDT) 32bits     *;
;***********************************************;
null_desc:;-------------------------------------;
	dq	0x0				;
code_desc:;-------------------------------------;
	dw	0xffff				; limit low
	dw	0x0				; base low
	db	0x0				; base middle
	db	0b10011010			; Access byte
	db	0b11001111			; 4 flags bits | 4 limit high bits
	db	0x0				; base high
data_desc:;-------------------------------------;
	dw	0xffff				; limit low
	dw	0x0				; base low
	db	0x0				; base middle
	db	0b10010010			; Acces byte
	db	0b11001111			; 4 flags bits | 4 limit high bits
	db	0x0				; base high
;***********************************************;

GDTR:
	dw	GDTR - null_desc - 0x1		; limit
	dd	(0x60 << 4) + null_desc		; base
