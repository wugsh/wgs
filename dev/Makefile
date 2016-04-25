ifneq ($(KERNELRELEASE),)

	obj-m:=memdev.o

else

KERNELDIR:=/lib/modules/$(shell uname -r)/build

PWD:=$(shell pwd)

default:

	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:

	rm  *.o *.mod.c *.mod.o *.ko

endif
