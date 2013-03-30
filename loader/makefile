LINKS=loader.o kernel.o
CFLAGS=-Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs
SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

CC=../cross/local/bin/i586-elf-gcc
LD=../cross/local/bin/i586-elf-ld

all:
	nasm -f elf -o loader.o loader.s
	$(CC) -o kernel.o $(SOURCES) $(CFLAGS)

clean:
	-rm *.o kernel.bin

link:
	$(LD) -T linker.ld -o kernel.bin $(LINKS)
