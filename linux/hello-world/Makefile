ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m := hello_world_kernel.o

else
# normal makefile

# path to kernel directory
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif