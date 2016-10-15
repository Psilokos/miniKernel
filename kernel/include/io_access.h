/*
** io_access.h for kernel in /home/lecouv_v/LokiOS/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu Jul 23 03:35:07 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 04:01:06 2015 Victorien LE COUVIOUR--TUFFET
*/

#ifndef IO_ACCESS_H_
# define IO_ACCESS_H_

# define CLI()			__asm__ volatile ("cli")
# define STI()			__asm__ volatile ("sti")

# define IN_B(port, ret)	__asm__ volatile ("in	al, dx" : "=a"(ret) : "d"(port))
# define IN_W(port, ret)	__asm__ volatile ("in	ax, dx" : "=a"(ret) : "d"(port))
# define IN_DW(port, ret)	__asm__ volatile ("in	eax, dx" : "=a"(ret) : "d"(port))

# define OUT_B(port, value)	__asm__ volatile ("out	dx, al" : : "d"(port), "a"(value))
# define OUT_W(port, value)	__asm__ volatile ("out	dx, ax" : : "d"(port), "a"(value))
# define OUT_DW(port, value)	__asm__ volatile ("out	dx, eax" : : "d"(port), "a"(value))

# define IO_WAIT()		OUT_B(0x80, 0x0)

#endif /* !IO_ACCESS_H_ */
