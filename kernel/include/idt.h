/*
** idt.h for kernel in /home/lecouv_v/LokiOS/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu Jul 23 12:59:24 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 14:21:07 2015 Victorien LE COUVIOUR--TUFFET
*/

#ifndef IDT_H_
# define IDT_H_

# include "types.h"

typedef struct __attribute__((packed))	idt32_desc
{
  uint16				offset_low;
  uint16				selector;
  byte					unused;
  byte					gate_type : 4;
  byte					attr : 4;
  uint16				offset_high;
}					idt32_desc_t;

typedef struct __attribute__((packed))	idtr32
{
  uint16				limit;
  uint32				base;
}					idtr32_t;

enum	idt_gate_type
  {
    INTERRUPT_16	= 0x6,
    INTERRUPT_32	= 0xe,
    TRAP_16		= 0x7,
    TRAP_32		= 0xf,
    TASK_32		= 0x5
  };

enum	idt_attr
  {
    PL_HIGH	= 0b0000,
    PL_MED_HIGH	= 0b0010,
    PL_MED_LOW	= 0b0100,
    PL_LOW	= 0b0110,
    IS_PRESENT	= 0b1000
  };

# define IDT_DESC_NB	(256)

# define IDT_BASE	(0x800)
# define IDT_LIMIT	(IDT_DESC_NB * sizeof(idt32_desc_t))

#endif /* !IDT_H_ */
