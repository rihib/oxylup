K = kernel
K_SRCS = \
	$K/main.c \

K_OBJS = $(K_SRCS:.c=.o)
DEPS = $(K_OBJS:.o=.d)

-include $(DEPS)

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
  QEMUOPTS += $(QEMUDEBUGOPTS)
endif

.PHONY: all run clean

all: run

run:
	$(QEMU) $(QEMUOPTS)
