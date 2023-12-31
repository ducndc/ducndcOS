CURRENT_PATH = $(shell pwd)

include $(CURRENT_PATH)/kernel.config

CPPPARAMS = -m32 -w -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
CPPPARAMS += -I$(CURRENT_PATH)/inc

ASPARAMS = --32
LDPARAMS = -melf_i386

objects = ./src/loader.o 
objects += ./src/gdt.o 
objects += ./src/port.o 
objects += ./src/interruptstubs.o 
objects += ./src/interrupts.o 
objects += ./src/kernel.o

%.o: %.cpp
	g++ $(CPPPARAMS) -o $@ -c $<

%.o: %.s
	as $(ASPARAMS) -o $@ $<

mykernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

install: mykernel.bin
	sudo cp $< /boot/mykernel.bin

mykernel.iso: mykernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg
	echo '	multiboot /boot/mykernel.bin' >> iso/boot/grub/grub.cfg
	echo '	boot' >> iso/boot/grub/grub.cfg
	echo '	}' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

run:
	qemu-system-i386 mykernel.iso

.PHONY: clean
clean:
	rm -f $(objects) mykernel.bin mykernel.iso
