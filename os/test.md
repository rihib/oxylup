# Test

```bash
% make DEBUG=1
clang -ffreestanding -nostdlib -O2 -std=c2x --target=riscv32 -Wall -Werror -Wextra -ggdb3 -gdwarf-5 -Wl,-Tkernel/kernel.ld -z max-page-size=4096 -Wl,-Map=kernel/kernel.map -o kernel/kernel.elf kernel/main.c
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
QEMU 8.2.1 monitor - type 'help' for more information
(qemu) info registers

CPU#0
 V      =   0
 pc       80200000
 mhartid  00000000
 mstatus  80006080
 mstatush 00000000
 hstatus  00000000
 vsstatus 00000000
 mip      00000000
 mie      00000008
 mideleg  00001666
 hideleg  00000000
 medeleg  00f0b509
 hedeleg  00000000
 mtvec    80000550
 stvec    80200000
 vstvec   00000000
 mepc     80200000
 sepc     00000000
 vsepc    00000000
 mcause   00000003
 scause   00000000
 vscause  00000000
 mtval    00000000
 stval    00000000
 htval    00000000
 mtval2   00000000
 mscratch 80026000
 sscratch 00000000
 satp     00000000
 x0/zero  00000000 x1/ra    8000ae28 x2/sp    80025f10 x3/gp    00000000
 x4/tp    80026000 x5/t0    00000001 x6/t1    00000002 x7/t2    00001000
 x8/s0    80025f30 x9/s1    00000001 x10/a0   00000000 x11/a1   87e00000
 x12/a2   00000007 x13/a3   00000019 x14/a4   00000000 x15/a5   00000001
 x16/a6   00000001 x17/a7   00000005 x18/s2   80200000 x19/s3   00000000
 x20/s4   87e00000 x21/s5   00000000 x22/s6   80006800 x23/s7   80020024
 x24/s8   00002000 x25/s9   800222f8 x26/s10  00000000 x27/s11  00000000
 x28/t3   616d6569 x29/t4   00000000 x30/t5   0000001c x31/t6   00000000
 f0/ft0   ffffffff00000000 f1/ft1   ffffffff00000000 f2/ft2   ffffffff00000000 f3/ft3   ffffffff00000000
 f4/ft4   ffffffff00000000 f5/ft5   ffffffff00000000 f6/ft6   ffffffff00000000 f7/ft7   ffffffff00000000
 f8/fs0   ffffffff00000000 f9/fs1   ffffffff00000000 f10/fa0  ffffffff00000000 f11/fa1  ffffffff00000000
 f12/fa2  ffffffff00000000 f13/fa3  ffffffff00000000 f14/fa4  ffffffff00000000 f15/fa5  ffffffff00000000
 f16/fa6  ffffffff00000000 f17/fa7  ffffffff00000000 f18/fs2  ffffffff00000000 f19/fs3  ffffffff00000000
 f20/fs4  ffffffff00000000 f21/fs5  ffffffff00000000 f22/fs6  ffffffff00000000 f23/fs7  ffffffff00000000
 f24/fs8  ffffffff00000000 f25/fs9  ffffffff00000000 f26/fs10 ffffffff00000000 f27/fs11 ffffffff00000000
 f28/ft8  ffffffff00000000 f29/ft9  ffffffff00000000 f30/ft10 ffffffff00000000 f31/ft11 ffffffff00000000
(qemu) q
% llvm-addr2line -e kernel/kernel.elf 80200000
/Users/rihib/dev/oxylup/os/kernel/main.c:2
```
