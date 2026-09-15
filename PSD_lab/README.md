# Problem Solving in C (PSD Lab)

A structured collection of hands-on C programming exercises covering core system-level concepts, memory manipulation, and algorithmic problem solving.

---

## Lab Modules

1. **`01_pointer_arithmetic.c`**
   - Pointer basics, dereferencing, pointer arithmetic, array sum via pointers.
   - Pass-by-reference swap and single-pass min/max extraction.
   - Double pointer (`int **`) dynamic buffer allocation.

2. **`02_string_manipulation.c`**
   - Implementation of string utilities without `<string.h>` (`my_strlen`, `my_strcpy`, `my_strcat`, `my_strcmp`).
   - In-place string reversal with two pointers.
   - Alphanumeric, case-insensitive palindrome detection.

3. **`03_dynamic_records.c`**
   - Dynamic record management for student data.
   - Dynamic array resizing (`malloc`, `realloc`, `free`).
   - Statistical aggregation: class average, highest score lookup.

4. **`04_file_handling.c`**
   - Formatted text stream I/O (`fprintf`, `fscanf`).
   - Raw binary record I/O (`fwrite`, `fread`).
   - Safe file handling and automated cleanup of temporary files.

5. **`05_bitwise_operations.c`**
   - Bit masking: test bit, set bit, clear bit, toggle bit.
   - Power of 2 checking in $O(1)$ bitwise operations.
   - Brian Kernighan's bit-counting algorithm ($O(\text{set bits})$).
   - In-place XOR swap without temporary memory.

---

## Compilation & Execution

Compile any lab file using `gcc`:
```bash
gcc -Wall -Wextra -O2 -std=c11 01_pointer_arithmetic.c -o 01_pointer_arithmetic.exe
./01_pointer_arithmetic.exe
```

Or run all workspace labs using the root test script:
```powershell
.\run_all_labs.ps1
```
