/*
** interrupt.c for kernel in /home/lecouv_v/LokiOS/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu Jul 23 16:12:39 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 16:27:17 2015 Victorien LE COUVIOUR--TUFFET
*/

#include "interrupt.h"
#include "io_access.h"
#include "keyboard.h"
#include "keymap.h"
#include "ps2.h"
#include "screen.h"
#include "types.h"

void	int_handler_default(void)
{
  INT_START();
  INT_END();
}

static inline void	wait_keycode(void)
{
  byte			reg_stat;

  do
    IN_B(PS2_ST_CMD, reg_stat);
  while (!IS_OUT_BUF_FILLED(reg_stat));
}

void	int_handler_keyboard(void)
{
  byte	scan_code;

  INT_START();

  wait_keycode();
  IN_B(PS2_DATA, scan_code);
  if (!IS_KEY_RELEASED(scan_code))
    _putchar(keymap_qwerty[scan_code - 1]);

  INT_END();
}
