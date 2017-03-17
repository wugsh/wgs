ifneq ($(KERNELRELEASE),)
	obj-m = call_usermodehelper.o
 # Otherwise we were called directly from the command
 # # line; invoke the kernel build system.
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
 
clean:
	rm -fr .*cmd .tmp* *odule* *o *mod.c *~
endif
