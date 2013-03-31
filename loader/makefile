CFLAGS=-Wall -Wextra -nostdlib -ffreestanding -O2

SOURCES=$(wildcard *.c)
ASM_SOURCES=$(wildcard *.s)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
ASM_OBJECTS=$(patsubst %.s,%.o,$(ASM_SOURCES))

CC=../cross/local/bin/i586-elf-gcc
LD=../cross/local/bin/i586-elf-gcc

all:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o gdt.o gdt.s
	nasm -f elf -o interupt.o interupt.s
	$(CC) -c $(SOURCES) $(CFLAGS)
	$(LD) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib $(ASM_OBJECTS) $(OBJECTS) -lgcc

clean:
	-rm *.o kernel.bin

