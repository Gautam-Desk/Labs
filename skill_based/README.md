# Skill-Based C Programming Lab

This folder contains advanced modular programming labs and system-level design patterns in C.

---

## Lab Modules

1. **`01_command_line_args.c`**
   - Command-line argument parsing (`argc`, `argv`).
   - Flag validation (`--add`, `--sub`, `--mul`, `--div`) with numerical conversion (`strtod`).
   - Error handling for division by zero and malformed arguments.

2. **`02_function_pointers_callbacks.c`**
   - Function pointer syntax and higher-order array operations.
   - `map`, `filter`, and `reduce` implementations in C.
   - Generic comparator-based sorting (`ascending` and `descending` callbacks).

3. **`03_matrix_transformations.c`**
   - Dynamic 2D matrix allocation and deallocation (`int **`).
   - Rectangular matrix transposition ($O(R \times C)$).
   - In-place 90-degree clockwise matrix rotation via transpose + row reversal.
   - Cofactor expansion determinant calculation for 3x3 matrices.

---

## Compilation & Execution

Compile any lab file with `gcc`:
```bash
gcc -Wall -Wextra -O2 -std=c11 01_command_line_args.c -o 01_command_line_args.exe
./01_command_line_args.exe
```

Or run all workspace labs from the repository root:
```powershell
.\run_all_labs.ps1
```
