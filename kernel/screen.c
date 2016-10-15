/*
** screen.c for kernel in /home/lecouv_v/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu Jul  9 23:51:37 2015 Victorien LE COUVIOUR--TUFFET
** Last update Mon Jul 20 20:27:01 2015 Victorien LE COUVIOUR--TUFFET
*/

#include "bda.h"
#include "io_access.h"
#include "screen.h"
#include "types.h"

screen_t		screen	= {{0, 0}, 0x0, 0x0};

void	init_screen(void)
{
  screen.base_vid_io_port	= *(uint16 *)ADDR_BASE_VID_IO_PORT;
}

inline void		move_cursor(uint8 const x, uint8 const y)
{
  register uint16 const	pos	= y * WS_COL + x;

  OUT_B(screen.base_vid_io_port, VGA_REG_LOW_CURS_POS);
  OUT_B(screen.base_vid_io_port + 1, pos);
  OUT_B(screen.base_vid_io_port, VGA_REG_HIGH_CURS_POS);
  OUT_B(screen.base_vid_io_port + 1, pos >> 8);
}

void		_putchar(char const c)
{
  uint8		*unit_ptr;

  if (c == '\n')
    {
      screen.curs.x = 0;
      screen.curs.y++;
    }
  else if (c == '\t')
    screen.curs.x = screen.curs.x + 8 - screen.curs.x % 8;
  else if (c == '\r')
    screen.curs.x = 0;
  else if (c == '\b')
    screen.curs.x -= ((screen.curs.x) ? (1) : (0));
  else
    {
      unit_ptr = (uint8 *)VIDEO_MEM_START + screen.curs.y * WS_COL * UNIT_SIZE + screen.curs.x * UNIT_SIZE;
      *unit_ptr = c;
      *(unit_ptr + 1) = screen.attr;
      screen.curs.x++;
    }
  if (screen.curs.x >= WS_COL)
    {
      screen.curs.y++;
      screen.curs.x -= WS_COL;
    }
  if (screen.curs.y >= WS_ROW)
    _scroll_up(screen.curs.y - WS_ROW + 1);
  move_cursor(screen.curs.x, screen.curs.y);
}

static void	_putnbr_rec(int const nb)
{
  if (nb / 10)
    _putnbr_rec(nb / 10);
  _putchar(nb % 10 + 48);
}

void	_putnbr(int nb)
{
  if (nb < 0)
    {
      _putchar('-');
      nb = -nb;
    }
  _putnbr_rec(nb);
}

void	_putstr(char const *s)
{
  while (*s)
    _putchar(*s++);
}

void		_scroll_up(uint32 const n)
{
  uint8		*unit_ptr;
  uint32 const	shift = n * WS_COL * UNIT_SIZE;

  unit_ptr = (uint8 *)VIDEO_MEM_START;
  while (unit_ptr < (uint8 *)VIDEO_MEM_END)
    {
      if (unit_ptr + shift < (uint8 *)VIDEO_MEM_END)
	{
	  *unit_ptr = *(unit_ptr + shift);
	  *(unit_ptr + 1) = *(unit_ptr + shift + 1);
	}
      else
	{
	  *unit_ptr = 0;
	  *(unit_ptr + 1) = 0;
	}
      unit_ptr += UNIT_SIZE;
    }
  screen.curs.y = ((n < screen.curs.y) ? (screen.curs.y - n) : (0));
}
