/*
** pic.c for kernel in /home/lecouv_v/LokiOS/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Wed Jul 22 18:49:53 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 04:31:01 2015 Victorien LE COUVIOUR--TUFFET
*/

#include "io_access.h"
#include "pic.h"

void	init_pic(void)
{
  OUT_B(PIC_MASTER_CMD, ICW1_ICW4 | ICW1_INIT);
  OUT_B(PIC_SLAVE_CMD, ICW1_ICW4 | ICW1_INIT);
  IO_WAIT();

  OUT_B(PIC_MASTER_DATA, ICW2_MASTER);
  OUT_B(PIC_SLAVE_DATA, ICW2_SLAVE);
  IO_WAIT();

  OUT_B(PIC_MASTER_DATA, ICW3_MASTER);
  OUT_B(PIC_SLAVE_DATA, ICW3_SLAVE);
  IO_WAIT();

  OUT_B(PIC_MASTER_DATA, ICW4_8086);
  OUT_B(PIC_SLAVE_DATA, ICW4_8086);
  IO_WAIT();

  OUT_B(PIC_MASTER_DATA, 0x0);
  OUT_B(PIC_SLAVE_DATA, 0x0);
  IO_WAIT();
}
