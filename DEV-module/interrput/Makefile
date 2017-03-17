obj-m := myirq.o
KERNELDIR := /usr/src/linux-headers-3.16.0-4-amd64 
all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c *.order *.symvers .tmp_versions
