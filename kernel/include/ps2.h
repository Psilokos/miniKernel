#ifndef PS2_H_
# define PS2_H_

enum	ps2_port
  {
    PS2_DATA	= 0x60,
    PS2_ST_CMD	= 0x64
  };

enum	reg_status
  {
    OUT_BUF_FILL	= 0b00000001,
    IN_BUF_FILL		= 0b00000010,
    DATA_FOR_CTRL	= 0b00001000,
    ERR_TIME_OUT	= 0b01000000,
    ERR_PARITY		= 0b10000000
  };

# define IS_OUT_BUF_FILLED(reg_stat)	(reg_stat & OUT_BUF_FILL)

#endif /* !PS2_H_ */
