/*
** screen.h for kernel in /home/lecouv_v/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Fri Jul 10 00:50:34 2015 Victorien LE COUVIOUR--TUFFET
** Last update Mon Jul 20 20:21:36 2015 Victorien LE COUVIOUR--TUFFET
*/

#ifndef SCREEN_H_
# define SCREEN_H_

# include "types.h"

# define VGA_REG_HIGH_CURS_POS	(14)
# define VGA_REG_LOW_CURS_POS	(15)

# define VIDEO_MEM_START	(0xb8000)
# define VIDEO_MEM_END		(VIDEO_MEM_START + WS_COL * WS_ROW * UNIT_SIZE)

# define WS_COL			(80)
# define WS_ROW			(25)
# define UNIT_SIZE		(2)

# define BACKGROUND(col)		(col << 4)
# define FOREGROUND(col)		(col)
# define GET_ATTR(bg_col, fg_col)	(BACKGROUND(bg_col) | FOREGROUND(fg_col))

enum	mod_txt_col
  {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    LIGHT_BROWN,
    WHITE
  };

typedef struct	s_screen
{
  vect2		curs;
  uint8		attr;
  uint16        base_vid_io_port;
}		screen_t;

extern screen_t	screen;

void	init_screen(void);
void	move_cursor(uint8 const x, uint8 const y);
void	_putchar(char const c);
void	_putnbr(int nb);
void	_putstr(char const *s);
void	_scroll_up(uint32 const n);

#endif /* !SCREEN_H_ */
