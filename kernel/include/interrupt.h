/*
** interrupt.h for kernel in /home/lecouv_v/LokiOS/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu Jul 23 18:04:04 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 18:04:54 2015 Victorien LE COUVIOUR--TUFFET
*/

#ifndef INTERRUPT_H_
# define INTERRUPT_H_

# include "pic.h"

# define INT_START()	__asm__ volatile ("pusha")
# define INT_END()				\
  {						\
    SEND_EOI();					\
    __asm__ volatile ("popa\n"			\
		      "leave\n"			\
		      "iret");			\
  }

void	int_handler_clock(void);
void	int_handler_default(void);
void	int_handler_keyboard(void);

#endif /* !INTERRUPT_H_ */
