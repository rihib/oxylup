C = common
K = kernel

C_SRCS = \
	$C/stdio.c
K_SRCS = \
	$K/main.c

C_OBJS = $(C_SRCS:.c=.o)
K_OBJS = $(K_SRCS:.c=.o)
DEPS = $(C_OBJS:.o=.d) $(K_OBJS:.o=.d)

-include $(DEPS)

# Compiler
CC = clang
CDEBUGFLAGS = \
	-ggdb3 \
	-gdwarf-5
CFLAGS = \
	-ffreestanding \
	-I. \
	-nostdlib \
	-O2 \
	-std=c2x \
	--target=riscv32 \
	-Wall \
	-Werror \
	-Wextra
LDDEBUGFLAGS = \
	-Wl,-Map=$K/kernel.map
LDFLAGS = \
	-Wl,-T$K/kernel.ld \
  -z max-page-size=4096

# QEMU
QEMU = qemu-system-riscv32
QEMUDEBUGOPTS = \
	--no-reboot \
	-serial mon:stdio
QEMUOPTS = \
	-bios default \
	-machine virt \
	-nographic

ifdef DEBUG
	CFLAGS += $(CDEBUGFLAGS)
	LDFLAGS += $(LDDEBUGFLAGS)
  QEMUOPTS += $(QEMUDEBUGOPTS)
endif

.PHONY: all run clean

all: run

run: $K/kernel.elf
	$(QEMU) $(QEMUOPTS) -kernel $K/kernel.elf

$K/kernel.elf: $(K_SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(C_SRCS) $(K_SRCS)

clean:
	rm -f $K/kernel.elf $K/kernel.map $C/*.o $C/*.d $K/*.o $K/*.d
