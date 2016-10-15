/*
** _start.c for kernel in /home/lecouv_v/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Fri Jul 10 23:14:49 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 12:58:06 2015 Victorien LE COUVIOUR--TUFFET
*/

#include "init.h"
#include "io_access.h"
#include "screen.h"

int		main(void);
static void	print_launch(void);

void	_start(void)
{
  init_screen();
  print_launch();

  screen.attr = GET_ATTR(BLACK, WHITE);
  _putstr("initializing PIC...\t");
  init_pic();
  screen.attr = GET_ATTR(BLACK, GREEN);
  _putstr("DONE\n");

  screen.attr = GET_ATTR(BLACK, WHITE);
  _putstr("loading IDT...\t\t");
  init_idt32();
  screen.attr = GET_ATTR(BLACK, GREEN);
  _putstr("DONE\n");

  screen.attr = GET_ATTR(BLACK, WHITE);
  _putstr("loading GDT...\t\t");
  init_gdt32();
  __asm__ volatile ("mov	ax, 0b11000\n"
  		    "mov	ss, ax\n"
  		    "mov	esp, 0x10003");
  main();
}

int	main(void)
{
  screen.attr = GET_ATTR(BLACK, GREEN);
  _putstr("DONE\n");
  STI();
  while (1)
    ;
}

static void	print_launch(void)
{
  screen.curs.x = 32;
  screen.curs.y = 2;
  screen.attr = GET_ATTR(BLUE, BLACK);
  _putstr("*****************\n");

  screen.curs.x = 32;
  _putchar('*');
  screen.attr = GET_ATTR(MAGENTA, BLACK);
  _putstr("KERNEL*LAUNCHED");
  screen.attr = GET_ATTR(BLUE, BLACK);
  _putstr("*\n");

  screen.curs.x = 32;
  _putstr("*****************\n\n");
}

void	test_task(void)
{
  while (1)
    ;
}
