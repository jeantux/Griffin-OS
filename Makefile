ELF_GCC=i686-elf-gcc
ELF_AS=i686-elf-as

FLAGS_GCC=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
FLAGS_LINKER=-ffreestanding -O2 -nostdlib
DIR_DEF=-Isrc/stdio

QEMU=qemu-system-i386

SRC_DIR=src
BIN_DIR=bin

all:
	$(ELF_AS) $(SRC_DIR)/boot.s -o $(BIN_DIR)/boot.o
	$(ELF_GCC) -c $(SRC_DIR)/kernel.c -o $(BIN_DIR)/kernel.o $(FLAGS_GCC) $(DIR_DEF)
	$(ELF_GCC) -T $(SRC_DIR)/linker.ld -o $(BIN_DIR)/griffinOS.bin $(FLAGS_LINKER) $(BIN_DIR)/boot.o $(BIN_DIR)/kernel.o -lgcc

clean:
	rm $(BIN_DIR)/*

run:
	$(QEMU) -M pc-i440fx-3.1 -kernel $(BIN_DIR)/griffinOS.bin