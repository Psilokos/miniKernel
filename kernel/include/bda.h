#ifndef BDA_H_
# define BDA_H_

enum	bios_data_area			/* address */	/* size of data */
  {
    ADDR_COM1_IO_PORT			= 0x400,	/* word */
    ADDR_COM2_IO_PORT			= 0x402,	/* word */
    ADDR_COM3_IO_PORT			= 0x404,	/* word */
    ADDR_COM4_IO_PORT			= 0x406,	/* word */
    ADDR_LPT1_IO_PORT			= 0x408,	/* word */
    ADDR_LPT2_IO_PORT			= 0x40a,	/* word */
    ADDR_LPT3_IO_PORT			= 0x40c,	/* word */
    ADDR_EXT_BDA_BASE_ADDR		= 0x40e,	/* word */	/* >> 4 */
    ADDR_BIT_FLAGS_DETECT_HARDWARE	= 0x410,	/* word */
    ADDR_KBD_STAT_FLAGS			= 0x417,	/* word */
    ADDR_KBD_BUF			= 0x41e,	/* double word */
    ADDR_DISP_MODE			= 0x449,	/* byte */
    ADDR_TXT_MODE_COL_NB		= 0x44a,	/* word */
    ADDR_BASE_VID_IO_PORT		= 0x463,	/* word */
    ADDR_TIMER_TICKS_NB			= 0x46c,	/* word */
    ADDR_HDD_NB				= 0x475,	/* byte */
    ADDR_KBD_BUF_START			= 0x480,	/* word */
    ADDR_KBD_BUF_END			= 0x482,	/* word */
    ADDR_LAST_KBD_LED_STATE		= 0X497		/* byte */
  };

#endif /* !BDA_H_ */
