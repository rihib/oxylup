ENTRY(main)

SECTIONS {
  . = 0x80200000;

  .text : {
    KEEP(*(.text.boot));
    *(.text .text.*);
  }

  .rodata : ALIGN(4) {
    *(.rodata .rodata.*);
  }

  .data : ALIGN(4) {
    *(.data .data.*);
  }

  .bss : ALIGN(4) {
    *(.bss .bss.* .sbss .sbss.*);
  }
}
