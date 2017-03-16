obj-m := myirq.o
KERNELDIR := /home/wgs/linux-4.4.50
all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions
