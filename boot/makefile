all:
	pushd ./src
	wget ftp://alpha.gnu.org/gnu/grub/grub-0.97-i386-pc.tar.gz
	tar -xzvpf grub-0.97-i386-pc.tar.gz
	popd
	cat src/grub-0.97-i386-pc/boot/grub/stage1 src/grub-0.97-i386-pc/boot/grub/stage2 pad ../loader/kernel.bin > floppy.img
