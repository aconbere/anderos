CFLAGS=-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

CC=../cross/local/bin/i586-elf-gcc
LD=../cross/local/bin/i586-elf-ld

all:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o gdt.o gdt.s
	$(CC) -c $(SOURCES) $(CFLAGS)
	$(LD) -T linker.ld -o kernel.bin loader.o gdt.o $(OBJECTS)

clean:
	-rm *.o kernel.bin

