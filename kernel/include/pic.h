/*
** pic.h for kernel in /home/lecouv_v/LokiOS/kernel
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Wed Jul 22 18:50:11 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 16:15:03 2015 Victorien LE COUVIOUR--TUFFET
*/

#ifndef PIC_H_
# define PIC_H_

enum	pic_port
  {
    PIC_MASTER_CMD	= 0x20,
    PIC_MASTER_DATA	= 0x21,
    PIC_SLAVE_CMD	= 0xa0,
    PIC_SLAVE_DATA	= 0xa1
  };

enum	reg_icw1
  {
    ICW1_ICW4		= 0b00000001,
    ICW1_SINGLE		= 0b00000010,
    ICW1_ITV4		= 0b00000100,
    ICW1_LVL_TRIG	= 0b00001000,
    ICW1_INIT		= 0b00010000
  };

enum	reg_icw2
  {
    ICW2_MASTER	= 0x20,
    ICW2_SLAVE	= 0x70
  };

enum	reg_icw3
  {
    ICW3_MASTER	= 0b00000100,
    ICW3_SLAVE	= 2
  };

enum	reg_icw4
  {
    ICW4_8086		= 0b00000001,
    ICW4_AUTO_EOI	= 0b00000010,
    ICW4_BUF_SLAVE	= 0b00001000,
    ICW4_BUF_MASTER	= 0b00001100,
    ICW4_SFNM		= 0b00010000
  };

# define PIC_EOI	(0x20)

# define SEND_EOI()	OUT_B(PIC_MASTER_CMD, PIC_EOI)

#endif /* !PIC_H_ */
