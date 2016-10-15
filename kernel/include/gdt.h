/*
** gdt32.h for kernel in /home/lecouv_v/kernel/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Sun Jul 19 19:02:56 2015 Victorien LE COUVIOUR--TUFFET
** Last update Mon Jul 20 17:44:56 2015 Victorien LE COUVIOUR--TUFFET
*/

#ifndef GDT_H_
# define GDT_H_

# include "types.h"

typedef struct __attribute__((packed))	gdt32_desc
{
  uint16				limit_low;
  uint16				base_low;
  uint8					base_middle;
  byte					access;
  byte					limit_high : 4;
  byte					flags : 4;
  byte					base_high;
}					gdt32_desc_t;

typedef struct __attribute__((packed))	gdtr32
{
  uint16				limit;
  uint32				base;
}					gdtr32_t;

enum	gdt_access
  {
    IS_ACCESSED		= 0b00000001,
    IS_READABLE		= 0b00000010,
    IS_WRITABLE		= 0b00000010,
    IS_EXPAND_DOWN	= 0b00000100,
    IS_CONFORMING	= 0b00000100,
    IS_CODE_SEG		= 0b00001000,
    IS_NORM_DESC	= 0b00010000,
    PL_HIGH		= 0b00000000,
    PL_MED_HIGH		= 0b00100000,
    PL_MED_LOW		= 0b01000000,
    PL_LOW		= 0b01100000,
    IS_PRESENT		= 0b10000000
  };

enum	gdt_flags
  {
    IS_IA32	= 0b0100,
    GR_4096	= 0b1000
  };

enum	gdt_index
  {
    NULL_DESC,
    KCODE_DESC,
    KDATA_DESC,
    KSTACK_DESC,
    UCODE_DESC,
    UDATA_DESC,
    USTACK_DESC,
    GDT_DESC_NB
  };

#endif /* !GDT_H_ */
