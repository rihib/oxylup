#!/bin/bash

brew install llvm qemu

echo -e "\n\n\n========== Is RISC-V32 supported by your clang? ==========\n"

if clang -print-targets | grep -q riscv32; then
  echo "YES"
else
  echo "NO"
fi

echo -e "\n========== Is RISC-V32 supported by your clang? =========="
