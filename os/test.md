# Test

```bash
% make DEBUG=1
clang -ffreestanding -I. -nostdlib -O2 -std=c2x --target=riscv32 -Wall -Werror -Wextra -ggdb3 -gdwarf-5 -Wl,-Tkernel/kernel.ld -z max-page-size=4096 -Wl,-Map=kernel/kernel.map -o kernel/kernel.elf common/stdio.c kernel/main.c
qemu-system-riscv32 -bios default -machine virt -nographic --no-reboot -serial mon:stdio -kernel kernel/kernel.elf

OpenSBI v1.3.1
   ____                    _____ ____ _____
  / __ \                  / ____|  _ \_   _|
 | |  | |_ __   ___ _ __ | (___ | |_) || |
 | |  | | '_ \ / _ \ '_ \ \___ \|  _ < | |
 | |__| | |_) |  __/ | | |____) | |_) || |_
  \____/| .__/ \___|_| |_|_____/|___/_____|
        | |
        |_|

Platform Name             : riscv-virtio,qemu
Platform Features         : medeleg
Platform HART Count       : 1
Platform IPI Device       : aclint-mswi
Platform Timer Device     : aclint-mtimer @ 10000000Hz
Platform Console Device   : uart8250
Platform HSM Device       : ---
Platform PMU Device       : ---
Platform Reboot Device    : sifive_test
Platform Shutdown Device  : sifive_test
Platform Suspend Device   : ---
Platform CPPC Device      : ---
Firmware Base             : 0x80000000
Firmware Size             : 190 KB
Firmware RW Offset        : 0x20000
Firmware RW Size          : 62 KB
Firmware Heap Offset      : 0x27000
Firmware Heap Size        : 34 KB (total), 2 KB (reserved), 8 KB (used), 23 KB (free)
Firmware Scratch Size     : 4096 B (total), 464 B (used), 3632 B (free)
Runtime SBI Version       : 1.0

Domain0 Name              : root
Domain0 Boot HART         : 0
Domain0 HARTs             : 0*
Domain0 Region00          : 0x02000000-0x0200ffff M: (I,R,W) S/U: ()
Domain0 Region01          : 0x80020000-0x8002ffff M: (R,W) S/U: ()
Domain0 Region02          : 0x80000000-0x8001ffff M: (R,X) S/U: ()
Domain0 Region03          : 0x00000000-0xffffffff M: (R,W,X) S/U: (R,W,X)
Domain0 Next Address      : 0x80200000
Domain0 Next Arg1         : 0x87e00000
Domain0 Next Mode         : S-mode
Domain0 SysReset          : yes
Domain0 SysSuspend        : yes

Boot HART ID              : 0
Boot HART Domain          : root
Boot HART Priv Version    : v1.12
Boot HART Base ISA        : rv32imafdch
Boot HART ISA Extensions  : time,sstc
Boot HART PMP Count       : 16
Boot HART PMP Granularity : 4
Boot HART PMP Address Bits: 32
Boot HART MHPM Count      : 16
Boot HART MIDELEG         : 0x00001666
Boot HART MEDELEG         : 0x00f0b509


Hello World!
1 + 2 = 3, 1234abcd
QEMU: Terminated
```
