# Labs Repository

A structured repository of academic labs, data structures and algorithms implementations, problem-solving exercises, and web development workshops in C and HTML/CSS.

---

## Repository Structure

### 1. `DS_algos/` — Data Structures & Algorithms (Units 1 to 5)
A comprehensive, modular algorithmic reference and working C implementation for data structures:
- **`unit1_arrays_linked_lists/`**:
  - `01_array_operations.c` (Traversal, insertion, deletion, address calculation)
  - `02_sparse_matrix.c` (Triplet representation, matrix operations)
  - `03_singly_linked_list.c` (Creation, traversal, search, insertion, deletion)
  - `04_doubly_linked_list.c` (Bidirectional traversal, insert/delete at pos)
  - `05_circular_linked_list.c` (Circular list operations)
  - `06_polynomial_operations.c` (Polynomial addition and multiplication via linked list)
  - `07_array_linked_list.c` (Array-based linked list simulation)
- **`unit2_stacks_queues/`**:
  - `01_stack_array.c` & `02_stack_linked_list.c` (Stack ADT implementations)
  - `03_expression_conversion_eval.c` (Infix to Postfix/Prefix, Postfix evaluation)
  - `04_recursion_classic.c` (Tower of Hanoi, Fibonacci, Factorial, Tail recursion)
  - `05_linear_queue_array.c` & `06_queue_linked_list.c` (Linear queue ADTs)
  - `07_circular_queue.c` (Circular queue with modulo indexing)
  - `08_deque.c` (Double-ended queue — input and output restricted)
  - `09_priority_queue.c` (Ascending and descending priority queues)
- **`unit3_searching_hashing_sorting/`**:
  - `01_searching_algorithms.c` (Linear Search, Binary Search iterative & recursive)
  - `02_hashing_techniques.c` (Division, folding, mid-square; Linear & Quadratic probing, Chaining)
  - `03_elementary_sorting.c` (Bubble Sort, Insertion Sort, Selection Sort)
  - `04_advanced_sorting.c` (Quick Sort, Merge Sort, Heap Sort, Radix Sort)
- **`unit4_trees/`**:
  - `01_binary_tree_traversals.c` (Inorder, Preorder, Postorder, Level-Order traversal)
  - `02_binary_search_tree.c` (BST Insert, Search, Min/Max, 3-case Deletion)
  - `03_avl_tree.c` (Self-balancing AVL tree with LL/RR/LR/RL rotations)
  - `04_binary_heap_priority_queue.c` (Min/Max Heap, heapify, insert, extract, Heap Sort)
- **`unit5_graphs/`**:
  - `01_graph_representation_traversal.c` (Adjacency Matrix/List, BFS, DFS)
  - `02_minimum_spanning_tree.c` (Kruskal's with Disjoint Set Union & Prim's algorithm)
  - `03_shortest_paths.c` (Dijkstra's Single Source & Floyd-Warshall All-Pairs Shortest Path)
- **Build & Test**:
  - `Makefile`: Build individual units (`make unit1`, `make unit4`, etc.) or all tests (`make test`).
  - `run_all.ps1`: Automated PowerShell test harness compiling and running all units.

---

### 2. `DS_lab/` — Data Structures Lab Programs
Individual C lab programs and assignment implementations:
- `bubblesort.c`, `insertionsort.c`, `selectionsort.c`, `merge.c`
- `doubly.c`, `linkatbeg.c`, `linkatend.c`, `node.c`, `ls.c`

---

### 3. `PSD_lab/` — Problem Solving in C (PSD)
Hands-on problem solving and systems-level C exercises:
- `01_pointer_arithmetic.c`: Pointers, pointer arithmetic, pointer-to-pointer.
- `02_string_manipulation.c`: Standard string operations without string.h.
- `03_dynamic_records.c`: Structures and dynamic memory allocation (`malloc`/`free`).
- `04_file_handling.c`: Text and binary file I/O operations.
- `05_bitwise_operations.c`: Low-level bitwise operations and masks.

---

### 4. `skill_based/` — Skill-Based C Programming
Advanced modular programming techniques in C:
- `01_command_line_args.c`: Parsing and validating `argc` and `argv`.
- `02_function_pointers_callbacks.c`: Function pointers, comparator patterns.
- `03_matrix_transformations.c`: Dynamic 2D arrays, rotations, transpose.

---

### 5. `workshop_lab/` — Web Development Workshop
HTML & CSS lab assignments, UI experiments, and comprehensive showcase portal:
- `index.html`: Interactive glassmorphic showcase portal for all workshop files.
- `assignment-1/`: Multi-page assignment suite (`about.html`, `calligram.html`, `marquee.html`, etc.).
- `complex_table.html`, `table.html`, `form1.html`, `list.html`, `Description_list.html`, etc.

---

## How to Build & Run

### Compiling and Running Data Structures (`DS_algos`)
```powershell
# Using PowerShell test harness:
cd DS_algos
.\run_all.ps1

# Or using Make (if installed):
make all
make test
```

### Running Workspace-Wide Test Harness
```powershell
# From root directory:
.\run_all_labs.ps1
```

### Viewing Web Workshop
Open `workshop_lab/index.html` in any modern web browser.
