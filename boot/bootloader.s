[BITS 16]
[ORG 0x0]

%define KADDR	0x1000
%define KSIZE	10

	jmp	_start

%include	"utils.inc"

_start:
	mov	ax, 0x60
	mov	ds, ax		; set data segment to 0x600
	mov	es, ax		; set extra segment to 0x600
	mov	ax, 0x9000
	mov	ss, ax		; set stack segment to 0x90000
	mov	sp, 0xa000	; set stack pointer to 0xa000 (phys addr: 0x9a000)

	mov	[btdrv], dl

	; init boot drive ;
	xor	ah, ah		; func 0x0
	mov	dl, [btdrv]
	int	0x13
	jc	btdrv_init_fail
	; get drive param ;
	mov	ah, 0x8		; func 0x8
	int	0x13
	jc	btdrv_param_getting_fail
	; loading kernel ;
	mov	si, kload_msg
	call	print
	mov	ax, KADDR
	mov	es, ax
	xor	bx, bx		; set the base addr to KADDR:0x0
	mov	ah, 0x2		; func 0x2
	mov	al, KSIZE
	mov	cx, 3		; read from 3rd sector on track 0
	xor	dh, dh		; use head 0
	mov	dl, [btdrv]
	int	0x13
	jc	btdrv_sect_read_fail
	mov	si, done_msg
	call	print

	; switch to protected mode ;
	cli
	lgdt	[GDTR]
	mov	eax, cr0
	or	ax, 0b1
	mov	cr0, eax

	; set the selectors to 0b10000 (index=2 | TI=0 | RPL=0) ;
	mov	ax, 0b10000
	mov	ds, ax
	mov	es, ax
	mov	fs, ax
	mov	gs, ax
	mov	ss, ax

	mov	esp, 0x9ffff	; stack begins to 0x9ffff (just before the kernel)

	; jump to kernel ;
	jmp	dword 0b1000:0x10000	; set the code selector to 0b1000 (index=1 | TI=0 | RPL=0)

btdrv_init_fail:
	mov	si, err_0x1300
	jmp	reboot
btdrv_param_getting_fail:
	mov	si, err_0x1308
	jmp	reboot
btdrv_sect_read_fail:
	mov	si, err_0x1302
	jmp	reboot

;**********************************************DATA**********************************************;
;--------------VAR--------------;								*;
%include	"gdt32.inc"	;								*;
				;								*;
btdrv:		db 0		;								*;
;-------------------------------;								*;
;----------------------MSG----------------------;						*;
newline:	db 10, 0			;						*;
kload_msg:	db 'loading kernel... ', 0	;						*;
done_msg:	db 'done.', 13, 10, 0		;						*;
;-----------------------------------------------;						*;
;---------------------------------------ERROR_MSG--------------------------------------;	*;
err_0x1300:	db 'ERROR 0x1300: unable to initialized boot drive', 13, 10, 0	       ;	*;
err_0x1302:	db 'ERROR 0x1302: unable to read sector(s) from boot drive', 13, 10, 0 ;	*;
err_0x1308:	db 'ERROR 0x1308: unable to get boot drive parameters', 13, 10, 0      ;	*;
;--------------------------------------------------------------------------------------;	*;
;************************************************************************************************;

	times	0x200 - ($ - $$)	db 0
