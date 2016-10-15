[BITS 16]
[ORG 0x0]

%define BTLD_ADDR	0x600
%define BTLD_SIZE	1

	jmp	_start

%include	"utils.inc"

_start:
	; init segments ;
	mov	ax, 0x7c0
	mov	ds, ax		; set data segment to 0x7c00
	mov	es, ax		; set extra segment to 0x7c00
	mov	ax, 0x9000
	mov	ss, ax		; set stack segment to 0x90000
	mov	sp, 0xa000	; set stack pointer to 0xa000 (phys addr: 0x9a000)

	mov	[btdrv], dl

	mov	ah, 0x6
	xor	al, al
	mov	bh, 0x7
	xor	cx, cx
	mov	dh, 24
	mov	dl, 79
	int	0x10

	mov	ah, 0x2
	xor	bh, bh
	xor	dx, dx
	int	0x10

	; init boot drive ;
	xor	ah, ah		; func 0x0
	mov	dl, [btdrv]
	int	0x13
	jc	btdrv_init_fail
	; get drive param ;
	mov	ah, 0x8		; func 0x8
	int	0x13
	jc	btdrv_param_getting_fail
	; loading bootloader ;
	xor	ax, ax
	mov	es, ax
	mov	bx, BTLD_ADDR	; set the base addr to 0x0:BTLD_ADDR
	mov	ah, 0x2		; func 0x2
	mov	al, BTLD_SIZE
	mov	cx, 2		; read from 2nd sector on track 0
	xor	dh, dh		; use head 0
	mov	dl, [btdrv]
	int	0x13
	jc	btdrv_sect_read_fail

	mov	dl, [btdrv]
	jmp	0x0:BTLD_ADDR	; jump to bootloader

;---------ERROR-HANDLING--------;
btdrv_init_fail:		;
	mov	si, err_0x1300	;
	jmp	reboot		;
btdrv_param_getting_fail:	;
	mov	si, err_0x1308	;
	jmp	reboot		;
btdrv_sect_read_fail:		;
	mov	si, err_0x1302	;
	jmp	reboot		;
;-------------------------------;

;**********************************************DATA**********************************************;
;----------VAR----------;									*;
btdrv:		db 0	;									*;
;-----------------------;									*;
;---------------------------------------ERROR_MSG--------------------------------------;	*;
err_0x1300:	db 'ERROR 0x1300: unable to initialized boot drive', 13, 10, 0	       ;	*;
err_0x1302:	db 'ERROR 0x1302: unable to read sector(s) from boot drive', 13, 10, 0 ;	*;
err_0x1308:	db 'ERROR 0x1308: unable to get boot drive parameters', 13, 10, 0      ;	*;
;--------------------------------------------------------------------------------------;	*;
;************************************************************************************************;

	times	0x1fe - ($ - $$)	db 0	; NOP until 0x1fd
	dw	0xaa55				; MBR signature on 0x1fe and 0x1ff
