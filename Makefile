##
## Makefile for kernel in /home/lecouv_v/kernel
##
## Made by Victorien LE COUVIOUR--TUFFET
## Login   <lecouv_v@epitech.net>
##
## Started on  Fri Jul 10 14:00:56 2015 Victorien LE COUVIOUR--TUFFET
## Last update Sat Oct 15 02:00:28 2016 Victorien LE COUVIOUR--TUFFET
##

FLOPPY			= floppyA

DIR_BOOT		= boot/
BOOT_SECTOR		= $(DIR_BOOT)bootsect
BOOT_LOADER		= $(DIR_BOOT)bootld

export AS		= nasm
ASFLAGS			= -f bin -I./$(DIR_BOOT)

export RM		= rm -f

KERNEL			= kernel

mkfile_path		:= $(abspath $(lastword $(MAKEFILE_LIST)))
export WDIR		:= $(patsubst %/,%,$(dir $(mkfile_path)))
export DIR_KERNEL	= $(WDIR)/$(KERNEL)/
export DIR_LIB		= $(WDIR)/lib/
export DIR_INC		= $(WDIR)/include/
export DIR_K_INC	= $(DIR_KERNEL)include/
export DIR_LIB_INC	= $(DIR_LIB)include/

all:		$(FLOPPY)

$(FLOPPY):	print_build boot lib $(KERNEL)
		@cat $(BOOT_SECTOR) $(BOOT_LOADER) $(KERNEL)/kernel /dev/zero | dd of=$(FLOPPY) bs=512 count=2880 &> /dev/null
		@printf "\033[31m>>>>>>>>>>---{\033[4;42mFLOPPY-GENERATED-SUCCESSFULLY\033[24;40m}---<<<<<<<<<<\n\033[0m"

usb_boot:	print_build boot lib $(KERNEL)
		@tput sc
		@cat $(BOOT_SECTOR) $(BOOT_LOADER) $(KERNEL)/kernel /dev/zero | sudo dd of=$(filter-out $@, $(MAKECMDGOALS)) bs=512 count=64 &> /dev/null
		@tput rc
		@printf "\033[31m>>>>>---{\033[4;42mBOOTABLE-USB-DEVICE-CREATED-SUCCESSFULLY\033[24;40m}---<<<<\n\033[0m"

boot:		$(DIR_BOOT)bootsect.s $(DIR_BOOT)bootloader.s
		@$(AS) $(ASFLAGS) $(DIR_BOOT)bootsect.s -o $(BOOT_SECTOR)
		@printf "\033[31m>\t\t \033[30;47m{BOOT_SECTOR_ASSEMBLED}\033[31;40m\t\t<\n\033[0m"
		@$(AS) $(ASFLAGS) $(DIR_BOOT)bootloader.s -o $(BOOT_LOADER)
		@printf "\033[31m>\t\t \033[30;47m{BOOT_LOADER_ASSEMBLED}\033[31;40m\t\t<\n\033[0m"

$(KERNEL):
		@printf "\033[31m>\033[35m*******************COMPLILING_KERNEL*******************\033[31m<\n\033[0m"
		@make -C $(DIR_KERNEL) $@ --no-print-directory
		@printf "\033[31m>\033[35m*******************************************************\033[31m<\n\033[0m"

lib:
		@printf ""
		@make -C $(DIR_LIB) $@
		@printf ""

clean_boot:
		@printf "\033[35m*******************DELETING_OBJECTS**********************\n\033[0m"
		@$(RM) $(BOOT_SECTOR)
		@printf "\033[35m*\t\t\033[30;47m{BOOT-SECTOR-DELETED}\033[35;40m\t\t\t*\n\033[0m"
		@$(RM) $(BOOT_LOADER)
		@printf "\033[35m*\t\t\033[30;47m{BOOT-LOADER-DELETED}\033[35;40m\t\t\t*\n\033[0m"

clean:		clean_boot
		@make -C $(KERNEL) $@ --no-print-directory
		@make -C $(DIR_LIB) $@ --no-print-directory
		@printf "\033[35m*********************************************************\n\033[0m"

fclean:		clean_boot
		@make -C $(KERNEL) $@ --no-print-directory
		@make -C $(DIR_LIB) $@ --no-print-directory
		@printf "\033[35m*********************************************************\n\033[0m"
		@$(RM) $(FLOPPY)
		@printf "\t       \033[30;47m{VIRTUAL-FLOPPY-DELETED}\n\033[0m"

print_build:
		@printf "\033[31m>>>>>>>>>>>>>>>>>>>>BUILDING_PROJECT<<<<<<<<<<<<<<<<<<<<<\n\033[0m"

re:		fclean print_build all

.PHONY:		all boot clean fclean $(KERNEL) lib re
