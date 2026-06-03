ASM     := nasm
ASFLAGS := -felf64 -Wall
CC      := musl-gcc
CFLAGS  := -static -pipe -c

MUSL   := /usr/lib
LIBGCC := /usr/lib/gcc/x86_64-pc-linux-gnu/16.1.1

STDS_DIR := stds
INCLUDES := -I $(STDS_DIR)/

TARGET := test
SRC    := test.nasm
OBJ    := test.o

.PHONY: all clean re
.SUFFIXES:

all: $(TARGET)

$(STDS_DIR)/printf.o: $(STDS_DIR)/printf.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJ): $(SRC)
	$(ASM) $(ASFLAGS) $(INCLUDES) $< -o $@

$(TARGET): $(OBJ) $(STDS_DIR)/printf.o
	ld -static -z relro -no-pie \
	  $(MUSL)/crt1.o $(MUSL)/crti.o $(LIBGCC)/crtbegin.o \
	  -L$(MUSL) -L$(LIBGCC) \
	  $^ \
	  --start-group $(LIBGCC)/libgcc.a $(LIBGCC)/libgcc_eh.a -lc --end-group \
	  $(LIBGCC)/crtend.o $(MUSL)/crtn.o \
	  -o $@

clean:
	rm -f $(TARGET) $(OBJ)

re: clean all

