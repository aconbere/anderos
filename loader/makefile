CFLAGS=-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
SOURCES=$(wildcard *.c)
ASM_SOURCES=$(wildcard *.s)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
ASM_OBJECTS=$(patsubst %.s,%.o,$(ASM_SOURCES))

CC=../cross/local/bin/i586-elf-gcc
LD=../cross/local/bin/i586-elf-ld

all:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o gdt.o gdt.s
	nasm -f elf -o interupt.o interupt.s
	$(CC) -c $(SOURCES) $(CFLAGS)
	$(LD) -T linker.ld -o kernel.bin $(ASM_OBJECTS) $(OBJECTS)

clean:
	-rm *.o kernel.bin

