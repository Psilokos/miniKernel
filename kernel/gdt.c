/*
** gdt.c for kernel in /home/lecouv_v/kernel/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Sun Jul 19 20:14:54 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 18:12:15 2015 Victorien LE COUVIOUR--TUFFET
*/

#include "gdt.h"

static gdt32_desc_t	kgdt32[GDT_DESC_NB];
static gdtr32_t		kgdtr32;

static void	init_gdt32_desc(gdt32_desc_t *const desc_ptr, uint32 const base,
				uint32 const limit, byte const access, byte const flags)
{
  desc_ptr->limit_low	= limit;
  desc_ptr->base_low	= base;
  desc_ptr->base_middle	= base >> 16;
  desc_ptr->access	= access;
  desc_ptr->limit_high	= limit >> 16;
  desc_ptr->flags	= flags;
  desc_ptr->base_high	= base >> 24;
}

static inline void	lgdt(void)
{
  __asm__ volatile ("lgdt	(kgdtr32)\n"
		    "mov	ax, 0b10000\n"
		    "mov	ds, ax\n"
		    "mov	es, ax\n"
		    "mov	fs, ax\n"
		    "mov	gs, ax\n"
		    "jmp	0b1000:cs_reset\n"
		    "cs_reset:");
}

void		init_gdt32(void)
{
  byte	access[GDT_DESC_NB];
  byte	flags[GDT_DESC_NB];

  access[NULL_DESC]	= 0b0;
  access[KCODE_DESC]	= IS_PRESENT | PL_HIGH | IS_NORM_DESC | IS_CODE_SEG | IS_WRITABLE;
  access[KDATA_DESC]	= IS_PRESENT | PL_HIGH | IS_NORM_DESC | IS_READABLE;
  access[KSTACK_DESC]	= IS_PRESENT | PL_HIGH | IS_NORM_DESC | IS_EXPAND_DOWN | IS_READABLE;
  access[UCODE_DESC]	= IS_PRESENT | PL_LOW | IS_NORM_DESC | IS_CODE_SEG | IS_WRITABLE;
  access[UDATA_DESC]	= IS_PRESENT | PL_LOW | IS_NORM_DESC | IS_READABLE;
  access[USTACK_DESC]	= IS_PRESENT | PL_LOW | IS_NORM_DESC | IS_EXPAND_DOWN | IS_READABLE;

  flags[NULL_DESC]	= 0b0;
  flags[KCODE_DESC]	= GR_4096 | IS_IA32;
  flags[KDATA_DESC]	= IS_IA32;
  flags[KSTACK_DESC]	= GR_4096 | IS_IA32;
  flags[UCODE_DESC]	= GR_4096 | IS_IA32;
  flags[UDATA_DESC]	= GR_4096 | IS_IA32;
  flags[USTACK_DESC]	= GR_4096 | IS_IA32;

  init_gdt32_desc(kgdt32 + NULL_DESC,	0x0,		0x0,		0b0,			0b0);
  init_gdt32_desc(kgdt32 + KCODE_DESC,	0x0,		0xfffff,	access[KCODE_DESC],	flags[KCODE_DESC]);
  init_gdt32_desc(kgdt32 + KDATA_DESC,	0x0,		0xfffff,	access[KDATA_DESC],	flags[KDATA_DESC]);
  init_gdt32_desc(kgdt32 + KSTACK_DESC,	0x0,		0x0,		access[KSTACK_DESC],	flags[KSTACK_DESC]);
  init_gdt32_desc(kgdt32 + UCODE_DESC,	0x30000,	0xfffff,	access[UCODE_DESC],	flags[UCODE_DESC]);
  init_gdt32_desc(kgdt32 + UDATA_DESC,	0x30000,	0xfffff,	access[UCODE_DESC],	flags[UCODE_DESC]);
  init_gdt32_desc(kgdt32 + USTACK_DESC,	0x0,		0x20,		access[USTACK_DESC],	flags[USTACK_DESC]);

  kgdtr32.base	= (uint32)kgdt32;
  kgdtr32.limit	= GDT_DESC_NB * sizeof(gdt32_desc_t);
  lgdt();
}
