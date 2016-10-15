/*
** idt.c for kernel in /home/lecouv_v/LokiOS/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu Jul 23 14:18:20 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 18:03:19 2015 Victorien LE COUVIOUR--TUFFET
*/

#include "idt.h"
#include "interrupt.h"
#include "string.h"

idt32_desc_t	kidt32[256];
idtr32_t	kidtr32;

static inline void	init_idt32_desc(idt32_desc_t *const desc_ptr, uint32 const offset,
					uint16 const selector, byte const gate_type, byte const attr)
{
  desc_ptr->offset_low	= offset;
  desc_ptr->selector	= selector;
  desc_ptr->gate_type	= gate_type;
  desc_ptr->attr	= attr;
  desc_ptr->offset_high	= offset >> 16;
}

static inline void	lidt(void)
{
  memcpy((void *)kidtr32.base, kidt32, kidtr32.limit);

  __asm__ volatile ("lidt	(kidtr32)");
}

void		init_idt32(void)
{
  uint16	reg_cs;
  uint16	i;

  __asm__ volatile ("mov	ax, cs" : "=a"(reg_cs));
  i = 0;
  while (i < IDT_DESC_NB)
    init_idt32_desc(kidt32 + i++, (uint32)&int_handler_default, reg_cs, INTERRUPT_32, PL_HIGH | IS_PRESENT);
  init_idt32_desc(kidt32 + 33, (uint32)&int_handler_keyboard, reg_cs, INTERRUPT_32, PL_HIGH | IS_PRESENT);

  kidtr32.base = IDT_BASE;
  kidtr32.limit = IDT_LIMIT;
  lidt();
}
