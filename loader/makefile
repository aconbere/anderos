
all:
	nasm -f elf -o loader.o loader.s
	i586-elf-gcc -o kernel.o -c kernel.c -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs
	i586-elf-ld -T linker.ld -o kernel.bin loader.o kernel.o
