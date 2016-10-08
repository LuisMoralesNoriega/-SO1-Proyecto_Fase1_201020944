#
# Makefile for the Linux proc filesystem routines.
#

obj-m   += LAMN_Procesos.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=${PWD} modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=${PWD} clean	

