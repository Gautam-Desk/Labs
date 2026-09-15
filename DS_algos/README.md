# Data Structures — Complete Algorithms Handbook
> **From Beginner to Advanced | Unit 1 → Unit 2 → Unit 3**  
> *Exam-Ready Algorithmic Reference & Revision Guide*

---

## Table of Contents

- [1. How to Read an Algorithm](#1-how-to-read-an-algorithm)
- [2. Algorithm Properties](#2-algorithm-properties)
- [3. Time and Space Complexity](#3-time-and-space-complexity)
- [Unit 1 — Arrays](#unit-1--arrays)
  - [4. Array Basics & Representation](#4-array-basics--representation)
  - [5. Array Address Calculation (1D)](#5-array-address-calculation-1d)
  - [6. Array Traversal](#6-array-traversal)
  - [7. Array Insertion](#7-array-insertion)
  - [8. Array Deletion](#8-array-deletion)
  - [9. Multidimensional Arrays](#9-multidimensional-arrays)
  - [10. Matrix Addition](#10-matrix-addition)
  - [11. Row-Major Address Calculation (2D)](#11-row-major-address-calculation-2d)
  - [12. Column-Major Address Calculation (2D)](#12-column-major-address-calculation-2d)
  - [13. N-Dimensional Address Calculation](#13-n-dimensional-address-calculation)
  - [14. Sparse Matrix (Triplet Representation)](#14-sparse-matrix-triplet-representation)
  - [15. Dynamic Memory Allocation](#15-dynamic-memory-allocation)
- [Unit 1 — Singly Linked List](#unit-1--singly-linked-list)
  - [16. Singly Linked List Representation](#16-singly-linked-list-representation)
  - [17. Singly Linked List Creation](#17-singly-linked-list-creation)
  - [18. Singly Linked List Traversal](#18-singly-linked-list-traversal)
  - [19. Singly Linked List Search](#19-singly-linked-list-search)
  - [20. Singly Linked List Insertion](#20-singly-linked-list-insertion)
  - [21. Singly Linked List Deletion](#21-singly-linked-list-deletion)
- [Unit 1 — Doubly Linked List](#unit-1--doubly-linked-list)
  - [22. Doubly Linked List Representation](#22-doubly-linked-list-representation)
  - [23. Doubly Linked List Creation](#23-doubly-linked-list-creation)
  - [24. Doubly Linked List Traversal](#24-doubly-linked-list-traversal)
  - [25. Doubly Linked List Insertion](#25-doubly-linked-list-insertion)
  - [26. Doubly Linked List Deletion](#26-doubly-linked-list-deletion)
- [Unit 1 — Circular Linked List](#unit-1--circular-linked-list)
  - [27. Circular Linked List Representation](#27-circular-linked-list-representation)
  - [28. Circular List Creation](#28-circular-list-creation)
  - [29. Circular List Traversal](#29-circular-list-traversal)
  - [30. Circular List Insertion](#30-circular-list-insertion)
  - [31. Circular List Deletion](#31-circular-list-deletion)
  - [32. Array-Based Linked List](#32-array-based-linked-list)
- [Unit 1 — Polynomial Operations](#unit-1--polynomial-operations)
  - [33. Polynomial Representation](#33-polynomial-representation)
  - [34. Polynomial Addition](#34-polynomial-addition)
  - [35. Polynomial Multiplication](#35-polynomial-multiplication)
  - [36. Polynomial Subtraction *(Supplemental)*](#36-polynomial-subtraction-supplemental)
  - [37. Polynomial Evaluation *(Supplemental)*](#37-polynomial-evaluation-supplemental)
  - [38. Polynomial Differentiation *(Supplemental)*](#38-polynomial-differentiation-supplemental)
- [Unit 2 — Stack](#unit-2--stack)
  - [39. Stack ADT & Characteristics](#39-stack-adt--characteristics)
  - [40. Stack Using Array](#40-stack-using-array)
  - [41. Stack Using Linked List](#41-stack-using-linked-list)
  - [42. Expression Notations & Precedence](#42-expression-notations--precedence)
  - [43. Postfix Evaluation](#43-postfix-evaluation)
  - [44. Infix to Postfix Conversion](#44-infix-to-postfix-conversion)
  - [45. Infix to Prefix Conversion](#45-infix-to-prefix-conversion)
  - [46. Prefix Evaluation *(Supplemental)*](#46-prefix-evaluation-supplemental)
- [Unit 2 — Recursion](#unit-2--recursion)
  - [47. Recursion Principles](#47-recursion-principles)
  - [48. Factorial](#48-factorial)
  - [49. Fibonacci Sequence](#49-fibonacci-sequence)
  - [50. Tower of Hanoi](#50-tower-of-hanoi)
  - [51. Tail Recursion](#51-tail-recursion)
  - [52. Removing Recursion](#52-removing-recursion)
- [Unit 2 — Queue](#unit-2--queue)
  - [53. Queue ADT](#53-queue-adt)
  - [54. Linear Queue Using Array](#54-linear-queue-using-array)
  - [55. Queue Using Linked List](#55-queue-using-linked-list)
  - [56. Circular Queue](#56-circular-queue)
  - [57. Deque (Double-Ended Queue)](#57-deque-double-ended-queue)
  - [58. Priority Queue](#58-priority-queue)
- [Unit 3 — Searching](#unit-3--searching)
  - [59. Searching Overview](#59-searching-overview)
  - [60. Linear Search](#60-linear-search)
  - [61. Indexed Sequential Search](#61-indexed-sequential-search)
  - [62. Binary Search — Iterative](#62-binary-search--iterative)
  - [63. Binary Search — Recursive](#63-binary-search--recursive)
- [Unit 3 — Hashing](#unit-3--hashing)
  - [64. Hashing Principles](#64-hashing-principles)
  - [65. Division Method](#65-division-method)
  - [66. Mid-Square Method](#66-mid-square-method)
  - [67. Folding Method](#67-folding-method)
  - [68. Multiplication Method](#68-multiplication-method)
  - [69. Collision Resolution Overview](#69-collision-resolution-overview)
  - [70. Separate Chaining (Open Hashing)](#70-separate-chaining-open-hashing)
  - [71. Open Addressing (Closed Hashing)](#71-open-addressing-closed-hashing)
  - [72. Linear Probing](#72-linear-probing)
  - [73. Quadratic Probing](#73-quadratic-probing)
  - [74. Double Hashing](#74-double-hashing)
- [Unit 3 — Sorting](#unit-3--sorting)
  - [75. Sorting Concepts & Terminology](#75-sorting-concepts--terminology)
  - [76. Insertion Sort](#76-insertion-sort)
  - [77. Selection Sort](#77-selection-sort)
  - [78. Bubble Sort](#78-bubble-sort)
  - [79. Quick Sort](#79-quick-sort)
  - [80. Merge Sort](#80-merge-sort)
  - [81. Heap Sort](#81-heap-sort)
  - [82. Radix Sort](#82-radix-sort)
- [83. Complexity Summary Tables](#83-complexity-summary-tables)
- [84. Exam Writing Templates](#84-exam-writing-templates)
- [85. Rapid Revision Checklist & Memory Map](#85-rapid-revision-checklist--memory-map)
- [Final Exam Priority List](#final-exam-priority-list)

---

## 1. How to Read an Algorithm

Standard pseudocode notations used throughout this guide:

| Symbol / Identifier | Meaning |
| :--- | :--- |
| `A` / `LA` | Array / Linear Array |
| `N` | Total number of elements |
| `K` | Position or index in the structure |
| `ITEM` | Data element being inserted, searched, or deleted |
| `HEAD` / `START` | Pointer to the first node of a linked list |
| `TAIL` | Pointer to the last node of a linked list |
| `PTR`, `TEMP`, `PREV` | Temporary / traversal node pointers |
| `FRONT` | Pointer/index to the front of a queue |
| `REAR` | Pointer/index to the rear of a queue |
| `TOP` | Pointer/index to the top of a stack |
| `BA` | Base Address (memory location of the first element) |
| `W` | Size of one element (words or bytes) |
| `LB` | Lower Bound index (e.g., 0 or 1) |
| `UB` | Upper Bound index |

> **Important Exam Rule:** Write algorithms in language-independent numbered steps. C code is a language-specific implementation, not the formal algorithm itself. An algorithm is a finite, unambiguous, step-by-step procedure with well-defined inputs and outputs.

---

## 2. Algorithm Properties

Every valid algorithm must satisfy:
1. **Unambiguous & Clear:** Each step must be precise and clear in its instruction.
2. **Well-Defined Input:** Specifies zero or more clearly defined inputs.
3. **Well-Defined Output:** Produces at least one clearly defined result/output.
4. **Finiteness:** Must terminate after a countable, finite number of steps. Recursion lacking a base case violates finiteness.
5. **Effectiveness / Feasibility:** Each step must be basic enough to be carried out in practice.
6. **Language Independence:** Steps should be executable using any general programming language.

---

## 3. Time and Space Complexity

### 3.1 Time Complexity
The amount of computational time (or operation count) taken by an algorithm to run as a function of input size $n$.

### 3.2 Space Complexity
The total amount of memory space required by an algorithm during execution as a function of input size $n$. Composed of:
- **Fixed part:** Space for constants, variables, program instructions.
- **Variable part:** Space for dynamically allocated structures, recursion stack frames, etc.

*Trade-off:* An algorithm can often trade extra memory for reduced execution time (e.g., hash tables), or save memory at the cost of additional operations (e.g., in-place recalculation).

### 3.3 Asymptotic Notations
- **Big-O ($O$):** Asymptotic Upper Bound. Formal definition:  
  $f(n) = O(g(n))$ if there exist positive constants $c$ and $n_0$ such that $0 \le f(n) \le c \cdot g(n)$ for all $n \ge n_0$.
- **Big-Omega ($\Omega$):** Asymptotic Lower Bound. Formal definition:  
  $f(n) = \Omega(g(n))$ if there exist positive constants $c$ and $n_0$ such that $0 \le c \cdot g(n) \le f(n)$ for all $n \ge n_0$.
- **Big-Theta ($\Theta$):** Asymptotic Tight Bound. Formal definition:  
  $f(n) = \Theta(g(n))$ if there exist positive constants $c_1, c_2$ and $n_0$ such that $0 \le c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n)$ for all $n \ge n_0$.

---

## Unit 1 — Arrays

## 4. Array Basics & Representation

A one-dimensional linear array stores homogeneous elements at contiguous memory locations. For an array with lower bound $LB$ and upper bound $UB$:

$$\text{Length} = UB - LB + 1$$

---

## 5. Array Address Calculation (1D)

### Formula
$$\text{LOC}(A[K]) = BA + W \times (K - LB)$$

- $BA$: Base Address of array $A$
- $W$: Storage size of each element in bytes
- $K$: Required index
- $LB$: Lower bound of the index range

### Algorithm
```text
ADDRESS_1D(A, K, BA, W, LB)
Step 1: Set OFFSET = K - LB
Step 2: Set ADDRESS = BA + (W * OFFSET)
Step 3: Return ADDRESS
Step 4: Exit
```

### Worked Example
For array $A[1300 \dots 1900]$ with $BA = 1020$, $W = 2$ bytes:  
Target element: $A[1700]$  
$$\text{OFFSET} = 1700 - 1300 = 400$$  
$$\text{ADDRESS} = 1020 + (2 \times 400) = 1020 + 800 = 1820$$

---

## 6. Array Traversal

Visiting and processing every element in the array exactly once.

### Algorithm
```text
TRAVERSE_ARRAY(A, LB, UB)
Step 1: Set K = LB
Step 2: Repeat Steps 3-4 while K <= UB:
Step 3:     Process element A[K]
Step 4:     Set K = K + 1
Step 5: Exit
```

- **Time Complexity:** $O(n)$
- **Auxiliary Space:** $O(1)$

---

## 7. Array Insertion

Inserting an element at index $K$ requires shifting all existing elements from index $K$ to $N$ one position to the right, starting from the end to avoid overwriting.

### Algorithm
```text
INSERT_ARRAY(LA, N, K, ITEM)
Step 1: Set J = N
Step 2: Repeat Steps 3-4 while J >= K:
Step 3:     Set LA[J + 1] = LA[J]
Step 4:     Set J = J - 1
Step 5: Set LA[K] = ITEM
Step 6: Set N = N + 1
Step 7: Exit
```

### Complexities
- **At beginning ($K = 0$ or $1$):** $O(n)$ (all $n$ elements shift)
- **At middle ($K = n/2$):** $O(n)$
- **At end ($K = N + 1$):** $O(1)$ (no shifting if capacity exists)

---

## 8. Array Deletion

Deleting an element from index $K$ requires shifting all subsequent elements from $K + 1$ to $N$ one position to the left.

### Algorithm
```text
DELETE_ARRAY(LA, N, K, ITEM)
Step 1: Set ITEM = LA[K]
Step 2: Repeat for J = K to N - 1:
            Set LA[J] = LA[J + 1]
Step 3: Set N = N - 1
Step 4: Return ITEM
Step 5: Exit
```

- **Time Complexity:** Worst case $O(n)$, Best case $O(1)$ (deleting last element).

---

## 9. Multidimensional Arrays

A multidimensional array is an array of arrays. For a 2D array:
$$\text{int } A[M][N];$$
Total elements $= M \times N$.  
In C/C++, multidimensional arrays are stored in **Row-Major Order** (row by row).

---

## 10. Matrix Addition

### Algorithm
```text
MATRIX_ADD(A, B, C, ROWS, COLS)
Step 1: For i = 0 to ROWS - 1:
Step 2:     For j = 0 to COLS - 1:
Step 3:         Set C[i][j] = A[i][j] + B[i][j]
Step 4:     End For
Step 5: End For
Step 6: Display C
Step 7: Exit
```

- **Time Complexity:** $O(\text{ROWS} \times \text{COLS})$
- **Auxiliary Space:** $O(\text{ROWS} \times \text{COLS})$ for output matrix $C$.

---

## 11. Row-Major Address Calculation (2D)

In Row-Major Order, row 0 is stored first, followed by row 1, etc.  
For an array with $M$ rows, $N$ columns, lower row bound $LR$, and lower column bound $LC$:

$$\text{LOC}(A[i][j]) = BA + W \times \left[(i - LR) \times N + (j - LC)\right]$$

### Algorithm
```text
ROW_MAJOR_2D(BA, W, i, j, LR, LC, N)
Step 1: Set ER = i - LR
Step 2: Set EC = j - LC
Step 3: Set OFFSET = (ER * N) + EC
Step 4: Set ADDRESS = BA + (W * OFFSET)
Step 5: Return ADDRESS
Step 6: Exit
```

---

## 12. Column-Major Address Calculation (2D)

In Column-Major Order (used in Fortran, MATLAB), column 0 is stored first, then column 1, etc.  
For an array with $M$ rows:

$$\text{LOC}(A[i][j]) = BA + W \times \left[(j - LC) \times M + (i - LR)\right]$$

### Algorithm
```text
COLUMN_MAJOR_2D(BA, W, i, j, LR, LC, M)
Step 1: Set ER = i - LR
Step 2: Set EC = j - LC
Step 3: Set OFFSET = (EC * M) + ER
Step 4: Set ADDRESS = BA + (W * OFFSET)
Step 5: Return ADDRESS
Step 6: Exit
```

---

## 13. N-Dimensional Address Calculation

For an $N$-dimensional array in Row-Major Order with bounds $LB_k \le I_k \le UB_k$ and lengths $L_k = UB_k - LB_k + 1$:
Effective index: $E_k = I_k - LB_k$

$$\text{OFFSET} = E_N + L_N \times \left(E_{N-1} + L_{N-1} \times \left(\dots (E_2 + L_2 \times E_1)\dots\right)\right)$$

### Generalized Row-Major Algorithm
```text
ROW_MAJOR_ND(BASE, W, E[1..N], L[1..N])
Step 1: Set OFFSET = E[1]
Step 2: For i = 2 to N:
            Set OFFSET = (OFFSET * L[i]) + E[i]
Step 3: Set ADDRESS = BASE + (W * OFFSET)
Step 4: Return ADDRESS
Step 5: Exit
```

### Worked Example: `MAZE(2:8, -4:1, 6:10)`
Find address of `MAZE[5, -1, 8]` with $BA = 200, W = 4$:
- $E_1 = 5 - 2 = 3$, $L_1 = 8 - 2 + 1 = 7$
- $E_2 = -1 - (-4) = 3$, $L_2 = 1 - (-4) + 1 = 6$
- $E_3 = 8 - 6 = 2$, $L_3 = 10 - 6 + 1 = 5$

$$\text{OFFSET} = ((E_1 \times L_2) + E_2) \times L_3 + E_3 = ((3 \times 6) + 3) \times 5 + 2 = (18 + 3) \times 5 + 2 = 107$$
$$\text{ADDRESS} = 200 + (4 \times 107) = 200 + 428 = 628$$

---

## 14. Sparse Matrix (Triplet Representation)

A matrix is sparse if a majority of its elements are zero. It is compactly stored using a 3-column table:  
`[Row, Column, Value]`

```text
Row 0: [Total Rows, Total Columns, Total Non-zero Count]
Subsequent rows: [i, j, value]
```

### Algorithm
```text
SPARSE_TRIPLET(A, ROWS, COLS)
Step 1: Set COUNT = 0
Step 2: For i = 0 to ROWS - 1:
            For j = 0 to COLS - 1:
                If A[i][j] != 0:
                    Set COUNT = COUNT + 1
Step 3: Allocate COMPACT[COUNT + 1][3]
Step 4: Set COMPACT[0][0] = ROWS, COMPACT[0][1] = COLS, COMPACT[0][2] = COUNT
Step 5: Set K = 1
Step 6: For i = 0 to ROWS - 1:
            For j = 0 to COLS - 1:
                If A[i][j] != 0:
                    Set COMPACT[K][0] = i
                    Set COMPACT[K][1] = j
                    Set COMPACT[K][2] = A[i][j]
                    Set K = K + 1
Step 7: Display COMPACT
Step 8: Exit
```

---

## 15. Dynamic Memory Allocation

Dynamic allocation manages memory on the heap at runtime:
- `malloc(size)`: Allocates contiguous block of uninitialized memory. Returns `void*` or `NULL`.
- `calloc(n, size)`: Allocates memory for $n$ elements, initialized to zero.
- `realloc(ptr, new_size)`: Resizes previously allocated block.
- `free(ptr)`: Deallocates heap memory to prevent memory leaks.

### Standard Allocation Pattern
```text
DYNAMIC_ALLOCATE(SIZE)
Step 1: Request SIZE bytes via malloc/calloc
Step 2: Set PTR = address returned
Step 3: If PTR == NULL:
            Print "OVERFLOW: Memory Allocation Failed"
            Exit
Step 4: Use allocated memory buffer
Step 5: Release memory: free(PTR)
Step 6: Set PTR = NULL
Step 7: Exit
```

---

## Unit 1 — Singly Linked List

## 16. Singly Linked List Representation

A sequence of nodes where each node contains data and a pointer to the next node:

```text
HEAD
  │
  ▼
┌──────┬──────┐      ┌──────┬──────┐      ┌──────┬──────┐
│ DATA │ NEXT ├─────►│ DATA │ NEXT ├─────►│ DATA │ NULL │
└──────┴──────┘      └──────┴──────┘      └──────┴──────┘
```

---

## 17. Singly Linked List Creation

### Algorithm
```text
CREATE_SLL(N)
Step 1: Set HEAD = NULL
Step 2: Repeat N times:
            Allocate NEW_NODE
            If NEW_NODE == NULL:
                Print "OVERFLOW"
                Exit
            Read ITEM
            Set NEW_NODE->DATA = ITEM
            Set NEW_NODE->NEXT = NULL
            If HEAD == NULL:
                Set HEAD = NEW_NODE
            Else:
                Set TEMP = HEAD
                While TEMP->NEXT != NULL:
                    Set TEMP = TEMP->NEXT
                Set TEMP->NEXT = NEW_NODE
Step 3: Return HEAD
Step 4: Exit
```

---

## 18. Singly Linked List Traversal

### Algorithm
```text
TRAVERSE_SLL(HEAD)
Step 1: Set PTR = HEAD
Step 2: While PTR != NULL:
            Process PTR->DATA
            Set PTR = PTR->NEXT
Step 3: Exit
```

- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$

---

## 19. Singly Linked List Search

### Algorithm
```text
SEARCH_SLL(HEAD, ITEM)
Step 1: If HEAD == NULL:
            Print "Empty List"
            Return -1
Step 2: Set PTR = HEAD
Step 3: Set POS = 1
Step 4: While PTR != NULL:
            If PTR->DATA == ITEM:
                Print "Found at position ", POS
                Return POS
            Set PTR = PTR->NEXT
            Set POS = POS + 1
Step 5: Print "Item not found"
Step 6: Return -1
Step 7: Exit
```

---

## 20. Singly Linked List Insertion

### 20.1 Insert at Beginning
```text
INSERT_BEGIN_SLL(HEAD, ITEM)
Step 1: Allocate NEW_NODE
Step 2: If NEW_NODE == NULL:
            Print "OVERFLOW"
            Exit
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set NEW_NODE->NEXT = HEAD
Step 5: Set HEAD = NEW_NODE
Step 6: Exit
```
- **Time Complexity:** $O(1)$

### 20.2 Insert at End
```text
INSERT_END_SLL(HEAD, ITEM)
Step 1: Allocate NEW_NODE
Step 2: If NEW_NODE == NULL:
            Print "OVERFLOW"
            Exit
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set NEW_NODE->NEXT = NULL
Step 5: If HEAD == NULL:
            Set HEAD = NEW_NODE
            Exit
Step 6: Set PTR = HEAD
Step 7: While PTR->NEXT != NULL:
            Set PTR = PTR->NEXT
Step 8: Set PTR->NEXT = NEW_NODE
Step 9: Exit
```
- **Time Complexity:** $O(n)$ (without tail pointer)

### 20.3 Insert at Position
```text
INSERT_POSITION_SLL(HEAD, ITEM, POS)
Step 1: If POS < 1:
            Print "Invalid Position"
            Exit
Step 2: Allocate NEW_NODE
Step 3: If NEW_NODE == NULL:
            Print "OVERFLOW"
            Exit
Step 4: Set NEW_NODE->DATA = ITEM
Step 5: If POS == 1:
            Set NEW_NODE->NEXT = HEAD
            Set HEAD = NEW_NODE
            Exit
Step 6: Set TEMP = HEAD, Set I = 1
Step 7: While I < POS - 1 AND TEMP != NULL:
            Set TEMP = TEMP->NEXT
            Set I = I + 1
Step 8: If TEMP == NULL:
            Print "Position out of bounds"
            Exit
Step 9: Set NEW_NODE->NEXT = TEMP->NEXT
Step 10: Set TEMP->NEXT = NEW_NODE
Step 11: Exit
```

---

## 21. Singly Linked List Deletion

### 21.1 Delete from Beginning
```text
DELETE_BEGIN_SLL(HEAD)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW: Empty List"
            Exit
Step 2: Set PTR = HEAD
Step 3: Set HEAD = HEAD->NEXT
Step 4: Free PTR
Step 5: Exit
```
- **Time Complexity:** $O(1)$

### 21.2 Delete from End
```text
DELETE_END_SLL(HEAD)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: If HEAD->NEXT == NULL:
            Free HEAD
            Set HEAD = NULL
            Exit
Step 3: Set PTR = HEAD, Set PREV = NULL
Step 4: While PTR->NEXT != NULL:
            Set PREV = PTR
            Set PTR = PTR->NEXT
Step 5: Set PREV->NEXT = NULL
Step 6: Free PTR
Step 7: Exit
```
- **Time Complexity:** $O(n)$

### 21.3 Delete at Position
```text
DELETE_POSITION_SLL(HEAD, POS)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: If POS == 1:
            Set PTR = HEAD
            Set HEAD = HEAD->NEXT
            Free PTR
            Exit
Step 3: Set TEMP = HEAD, Set I = 1
Step 4: While I < POS - 1 AND TEMP->NEXT != NULL:
            Set TEMP = TEMP->NEXT
            Set I = I + 1
Step 5: If TEMP->NEXT == NULL:
            Print "Invalid Position"
            Exit
Step 6: Set PTR = TEMP->NEXT
Step 7: Set TEMP->NEXT = PTR->NEXT
Step 8: Free PTR
Step 9: Exit
```

---

## Unit 1 — Doubly Linked List

## 22. Doubly Linked List Representation

Each node contains pointers to both the predecessor and successor:

```text
NULL ◄───┌──────┬──────┬──────┐◄───►┌──────┬──────┬──────┐───► NULL
         │ PREV │ DATA │ NEXT │     │ PREV │ DATA │ NEXT │
         └──────┴──────┴──────┘     └──────┴──────┴──────┘
                   ▲
                   │
                 HEAD
```

---

## 23. Doubly Linked List Creation

### Algorithm
```text
CREATE_DLL(N)
Step 1: Set HEAD = NULL, Set TAIL = NULL
Step 2: Repeat N times:
            Allocate NEW_NODE
            If NEW_NODE == NULL:
                Print "OVERFLOW"
                Exit
            Read ITEM
            Set NEW_NODE->DATA = ITEM
            Set NEW_NODE->NEXT = NULL
            Set NEW_NODE->PREV = TAIL
            If HEAD == NULL:
                Set HEAD = NEW_NODE
            Else:
                Set TAIL->NEXT = NEW_NODE
            Set TAIL = NEW_NODE
Step 3: Return HEAD
Step 4: Exit
```

---

## 24. Doubly Linked List Traversal

### 24.1 Forward Traversal
```text
FORWARD_TRAVERSE_DLL(HEAD)
Step 1: Set PTR = HEAD
Step 2: While PTR != NULL:
            Process PTR->DATA
            Set PTR = PTR->NEXT
Step 3: Exit
```

### 24.2 Backward Traversal
```text
BACKWARD_TRAVERSE_DLL(HEAD)
Step 1: If HEAD == NULL: Exit
Step 2: Set PTR = HEAD
Step 3: While PTR->NEXT != NULL:
            Set PTR = PTR->NEXT
Step 4: While PTR != NULL:
            Process PTR->DATA
            Set PTR = PTR->PREV
Step 5: Exit
```

---

## 25. Doubly Linked List Insertion

### 25.1 Insert at Beginning
```text
INSERT_BEGIN_DLL(HEAD, ITEM)
Step 1: Allocate NEW_NODE
Step 2: If NEW_NODE == NULL:
            Print "OVERFLOW"
            Exit
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set NEW_NODE->PREV = NULL
Step 5: Set NEW_NODE->NEXT = HEAD
Step 6: If HEAD != NULL:
            Set HEAD->PREV = NEW_NODE
Step 7: Set HEAD = NEW_NODE
Step 8: Exit
```

### 25.2 Insert at End
```text
INSERT_END_DLL(HEAD, ITEM)
Step 1: Allocate NEW_NODE
Step 2: If NEW_NODE == NULL:
            Print "OVERFLOW"
            Exit
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set NEW_NODE->NEXT = NULL
Step 5: If HEAD == NULL:
            Set NEW_NODE->PREV = NULL
            Set HEAD = NEW_NODE
            Exit
Step 6: Set TEMP = HEAD
Step 7: While TEMP->NEXT != NULL:
            Set TEMP = TEMP->NEXT
Step 8: Set TEMP->NEXT = NEW_NODE
Step 9: Set NEW_NODE->PREV = TEMP
Step 10: Exit
```

### 25.3 Insert at Position
```text
INSERT_POSITION_DLL(HEAD, ITEM, POS)
Step 1: If POS == 1:
            Call INSERT_BEGIN_DLL(HEAD, ITEM)
            Exit
Step 2: Allocate NEW_NODE
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set TEMP = HEAD, Set I = 1
Step 5: While I < POS - 1 AND TEMP != NULL:
            Set TEMP = TEMP->NEXT
            Set I = I + 1
Step 6: If TEMP == NULL:
            Print "Invalid Position"
            Exit
Step 7: Set NEW_NODE->PREV = TEMP
Step 8: Set NEW_NODE->NEXT = TEMP->NEXT
Step 9: If TEMP->NEXT != NULL:
            Set TEMP->NEXT->PREV = NEW_NODE
Step 10: Set TEMP->NEXT = NEW_NODE
Step 11: Exit
```

---

## 26. Doubly Linked List Deletion

### 26.1 Delete from Beginning
```text
DELETE_BEGIN_DLL(HEAD)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: Set PTR = HEAD
Step 3: Set HEAD = HEAD->NEXT
Step 4: If HEAD != NULL:
            Set HEAD->PREV = NULL
Step 5: Free PTR
Step 6: Exit
```

### 26.2 Delete from End
```text
DELETE_END_DLL(HEAD)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: If HEAD->NEXT == NULL:
            Free HEAD
            Set HEAD = NULL
            Exit
Step 3: Set TEMP = HEAD
Step 4: While TEMP->NEXT != NULL:
            Set TEMP = TEMP->NEXT
Step 5: Set TEMP->PREV->NEXT = NULL
Step 6: Free TEMP
Step 7: Exit
```

### 26.3 Delete at Position
```text
DELETE_POSITION_DLL(HEAD, POS)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: Set TEMP = HEAD, Set I = 1
Step 3: While I < POS AND TEMP != NULL:
            Set TEMP = TEMP->NEXT
            Set I = I + 1
Step 4: If TEMP == NULL:
            Print "Invalid Position"
            Exit
Step 5: If TEMP->PREV != NULL:
            Set TEMP->PREV->NEXT = TEMP->NEXT
        Else:
            Set HEAD = TEMP->NEXT
Step 6: If TEMP->NEXT != NULL:
            Set TEMP->NEXT->PREV = TEMP->PREV
Step 7: Free TEMP
Step 8: Exit
```

---

## Unit 1 — Circular Linked List

## 27. Circular Linked List Representation

In a Circular Linked List (CLL), the last node points back to the first node (`HEAD`), forming a continuous cycle with no `NULL` pointers.

---

## 28. Circular List Creation

### Algorithm
```text
CREATE_CLL(N)
Step 1: Set HEAD = NULL
Step 2: Repeat N times:
            Allocate NEW_NODE
            If NEW_NODE == NULL:
                Print "OVERFLOW"
                Exit
            Read ITEM
            Set NEW_NODE->DATA = ITEM
            If HEAD == NULL:
                Set HEAD = NEW_NODE
                Set NEW_NODE->NEXT = HEAD
            Else:
                Set TEMP = HEAD
                While TEMP->NEXT != HEAD:
                    Set TEMP = TEMP->NEXT
                Set TEMP->NEXT = NEW_NODE
                Set NEW_NODE->NEXT = HEAD
Step 3: Return HEAD
Step 4: Exit
```

---

## 29. Circular List Traversal

### Algorithm
```text
TRAVERSE_CLL(HEAD)
Step 1: If HEAD == NULL:
            Print "Empty List"
            Exit
Step 2: Set TEMP = HEAD
Step 3: Repeat:
            Process TEMP->DATA
            Set TEMP = TEMP->NEXT
        Until TEMP == HEAD
Step 4: Exit
```

---

## 30. Circular List Insertion

### 30.1 Insert at Beginning
```text
INSERT_BEGIN_CLL(HEAD, ITEM)
Step 1: Allocate NEW_NODE
Step 2: Set NEW_NODE->DATA = ITEM
Step 3: If HEAD == NULL:
            Set HEAD = NEW_NODE
            Set NEW_NODE->NEXT = HEAD
            Exit
Step 4: Set TEMP = HEAD
Step 5: While TEMP->NEXT != HEAD:
            Set TEMP = TEMP->NEXT
Step 6: Set NEW_NODE->NEXT = HEAD
Step 7: Set TEMP->NEXT = NEW_NODE
Step 8: Set HEAD = NEW_NODE
Step 9: Exit
```

### 30.2 Insert at End
```text
INSERT_END_CLL(HEAD, ITEM)
Step 1: Allocate NEW_NODE
Step 2: Set NEW_NODE->DATA = ITEM
Step 3: If HEAD == NULL:
            Set HEAD = NEW_NODE
            Set NEW_NODE->NEXT = HEAD
            Exit
Step 4: Set TEMP = HEAD
Step 5: While TEMP->NEXT != HEAD:
            Set TEMP = TEMP->NEXT
Step 6: Set TEMP->NEXT = NEW_NODE
Step 7: Set NEW_NODE->NEXT = HEAD
Step 8: Exit
```

### 30.3 Insert at Position *(Supplemental)*
```text
INSERT_POSITION_CLL(HEAD, ITEM, POS)
Step 1: If POS == 1:
            Call INSERT_BEGIN_CLL(HEAD, ITEM)
            Exit
Step 2: Allocate NEW_NODE
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set TEMP = HEAD, Set I = 1
Step 5: While I < POS - 1 AND TEMP->NEXT != HEAD:
            Set TEMP = TEMP->NEXT
            Set I = I + 1
Step 6: If I != POS - 1:
            Print "Position out of range"
            Exit
Step 7: Set NEW_NODE->NEXT = TEMP->NEXT
Step 8: Set TEMP->NEXT = NEW_NODE
Step 9: Exit
```

---

## 31. Circular List Deletion

### 31.1 Delete from Beginning
```text
DELETE_BEGIN_CLL(HEAD)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: If HEAD->NEXT == HEAD:
            Free HEAD
            Set HEAD = NULL
            Exit
Step 3: Set TEMP = HEAD
Step 4: While TEMP->NEXT != HEAD:
            Set TEMP = TEMP->NEXT
Step 5: Set PTR = HEAD
Step 6: Set HEAD = HEAD->NEXT
Step 7: Set TEMP->NEXT = HEAD
Step 8: Free PTR
Step 9: Exit
```

### 31.2 Delete from End
```text
DELETE_END_CLL(HEAD)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: If HEAD->NEXT == HEAD:
            Free HEAD
            Set HEAD = NULL
            Exit
Step 3: Set TEMP = HEAD, Set PREV = NULL
Step 4: While TEMP->NEXT != HEAD:
            Set PREV = TEMP
            Set TEMP = TEMP->NEXT
Step 5: Set PREV->NEXT = HEAD
Step 6: Free TEMP
Step 7: Exit
```

### 31.3 Delete at Position *(Supplemental)*
```text
DELETE_POSITION_CLL(HEAD, POS)
Step 1: If HEAD == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: If POS == 1:
            Call DELETE_BEGIN_CLL(HEAD)
            Exit
Step 3: Set TEMP = HEAD, Set I = 1
Step 4: While I < POS - 1 AND TEMP->NEXT != HEAD:
            Set TEMP = TEMP->NEXT
            Set I = I + 1
Step 5: Set PTR = TEMP->NEXT
Step 6: If PTR == HEAD:
            Print "Invalid Position"
            Exit
Step 7: Set TEMP->NEXT = PTR->NEXT
Step 8: Free PTR
Step 9: Exit
```

---

## 32. Array-Based Linked List

Simulates a linked list using parallel arrays `INFO[]` (data) and `LINK[]` (pointers/indices). `START` points to the active list head, and `AVAIL` points to the head of the free-storage pool.

### Insertion
```text
INSERT_ARRAY_LL(ITEM, LOC)
Step 1: If AVAIL == -1:
            Print "OVERFLOW"
            Exit
Step 2: Set NEW = AVAIL
Step 3: Set AVAIL = LINK[AVAIL]
Step 4: Set INFO[NEW] = ITEM
Step 5: If LOC == -1:
            Set LINK[NEW] = START
            Set START = NEW
            Exit
Step 6: Set LINK[NEW] = LINK[LOC]
Step 7: Set LINK[LOC] = NEW
Step 8: Exit
```

### Traversal
```text
TRAVERSE_ARRAY_LL()
Step 1: Set PTR = START
Step 2: While PTR != -1:
            Process INFO[PTR]
            Set PTR = LINK[PTR]
Step 3: Exit
```

---

## Unit 1 — Polynomial Operations

## 33. Polynomial Representation

A polynomial $P(x) = a_n x^n + \dots + a_1 x + a_0$ is represented as an ordered linked list of non-zero terms:

```text
┌─────────────┬──────────┬──────┐
│ COEFFICIENT │ EXPONENT │ NEXT │
└─────────────┴──────────┴──────┘
```

---

## 34. Polynomial Addition

### Algorithm
```text
POLY_ADD(P1, P2)
Step 1: Set RESULT = NULL
Step 2: While P1 != NULL AND P2 != NULL:
            If P1->EXP > P2->EXP:
                Append (P1->COEFF, P1->EXP) to RESULT
                Set P1 = P1->NEXT
            Else If P2->EXP > P1->EXP:
                Append (P2->COEFF, P2->EXP) to RESULT
                Set P2 = P2->NEXT
            Else:
                Set SUM = P1->COEFF + P2->COEFF
                If SUM != 0:
                    Append (SUM, P1->EXP) to RESULT
                Set P1 = P1->NEXT
                Set P2 = P2->NEXT
Step 3: While P1 != NULL:
            Append (P1->COEFF, P1->EXP) to RESULT
            Set P1 = P1->NEXT
Step 4: While P2 != NULL:
            Append (P2->COEFF, P2->EXP) to RESULT
            Set P2 = P2->NEXT
Step 5: Return RESULT
Step 6: Exit
```
- **Time Complexity:** $O(m + n)$ for polynomials of size $m$ and $n$.

---

## 35. Polynomial Multiplication

### Algorithm
```text
POLY_MULTIPLY(P1, P2)
Step 1: Set RESULT = NULL
Step 2: Set PTR1 = P1
Step 3: While PTR1 != NULL:
            Set PTR2 = P2
            While PTR2 != NULL:
                Set COEFF = PTR1->COEFF * PTR2->COEFF
                Set EXP = PTR1->EXP + PTR2->EXP
                Insert (COEFF, EXP) into RESULT in descending order
                (Combine coefficients if equal exponent exists)
                Set PTR2 = PTR2->NEXT
            Set PTR1 = PTR1->NEXT
Step 4: Return RESULT
Step 5: Exit
```
- **Time Complexity:** $O(m \times n)$

---

## 36. Polynomial Subtraction *(Supplemental)*

Identical to addition, but subtracts coefficients when exponents are equal, and negates remaining terms from $P_2$:

```text
POLY_SUBTRACT(P1, P2)
Step 1: Set RESULT = NULL
Step 2: While P1 != NULL AND P2 != NULL:
            If P1->EXP > P2->EXP:
                Append (P1->COEFF, P1->EXP) to RESULT
                Set P1 = P1->NEXT
            Else If P2->EXP > P1->EXP:
                Append (-P2->COEFF, P2->EXP) to RESULT
                Set P2 = P2->NEXT
            Else:
                Set DIFF = P1->COEFF - P2->COEFF
                If DIFF != 0:
                    Append (DIFF, P1->EXP) to RESULT
                Set P1 = P1->NEXT
                Set P2 = P2->NEXT
Step 3: Append remaining terms of P1 to RESULT
Step 4: Append negated remaining terms (-P2->COEFF, P2->EXP) of P2 to RESULT
Step 5: Return RESULT
Step 6: Exit
```

---

## 37. Polynomial Evaluation *(Supplemental)*

### Direct Evaluation: $\sum c_i x^{e_i}$
```text
EVALUATE_POLYNOMIAL(P, X)
Step 1: Set RESULT = 0
Step 2: Set PTR = P
Step 3: While PTR != NULL:
            Set TERM = PTR->COEFF * (X ^ PTR->EXP)
            Set RESULT = RESULT + TERM
            Set PTR = PTR->NEXT
Step 4: Return RESULT
Step 5: Exit
```

### Horner's Rule (for Dense Polynomials): $O(n)$
$$P(x) = (\dots((a_n x + a_{n-1})x + a_{n-2})\dots)x + a_0$$
```text
HORNER(A, N, X)
Step 1: Set RESULT = A[N]
Step 2: For I = N - 1 down to 0:
            Set RESULT = (RESULT * X) + A[I]
Step 3: Return RESULT
Step 4: Exit
```

---

## 38. Polynomial Differentiation *(Supplemental)*

Applying power rule: $\frac{d}{dx}(c \cdot x^e) = (c \cdot e) \cdot x^{e-1}$. Constant terms ($e=0$) vanish.

```text
POLY_DIFFERENTIATE(P)
Step 1: Set RESULT = NULL
Step 2: Set PTR = P
Step 3: While PTR != NULL:
            If PTR->EXP > 0:
                Set NEW_COEFF = PTR->COEFF * PTR->EXP
                Set NEW_EXP = PTR->EXP - 1
                Append (NEW_COEFF, NEW_EXP) to RESULT
            Set PTR = PTR->NEXT
Step 4: Return RESULT
Step 5: Exit
```

---

## Unit 2 — Stack

## 39. Stack ADT & Characteristics

A Stack is a linear data structure operating under the **LIFO (Last In, First Out)** principle.
- **`PUSH`:** Insert element at `TOP`. Overflow occurs when stack is full.
- **`POP`:** Remove element from `TOP`. Underflow occurs when stack is empty.
- **`PEEK` / `TOP`:** Inspect element at `TOP` without removal.

---

## 40. Stack Using Array

Using an array `STACK[0..MAX-1]`, initialized with `TOP = -1`.

### 40.1 PUSH
```text
PUSH(STACK, TOP, MAX, ITEM)
Step 1: If TOP == MAX - 1:
            Print "OVERFLOW: Stack is full"
            Exit
Step 2: Set TOP = TOP + 1
Step 3: Set STACK[TOP] = ITEM
Step 4: Exit
```

### 40.2 POP
```text
POP(STACK, TOP)
Step 1: If TOP == -1:
            Print "UNDERFLOW: Stack is empty"
            Exit
Step 2: Set ITEM = STACK[TOP]
Step 3: Set TOP = TOP - 1
Step 4: Return ITEM
Step 5: Exit
```

### 40.3 PEEK
```text
PEEK(STACK, TOP)
Step 1: If TOP == -1:
            Print "UNDERFLOW"
            Exit
Step 2: Return STACK[TOP]
Step 3: Exit
```

### 40.4 DISPLAY
```text
DISPLAY_STACK(STACK, TOP)
Step 1: If TOP == -1:
            Print "Stack is Empty"
            Exit
Step 2: For I = TOP down to 0:
            Print STACK[I]
Step 3: Exit
```

---

## 41. Stack Using Linked List

The `TOP` of the stack is maintained at the head of the linked list. Dynamic sizing avoids fixed array overflow.

### 41.1 PUSH
```text
PUSH_LL(TOP, ITEM)
Step 1: Allocate NEW_NODE
Step 2: If NEW_NODE == NULL:
            Print "OVERFLOW"
            Exit
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set NEW_NODE->NEXT = TOP
Step 5: Set TOP = NEW_NODE
Step 6: Exit
```

### 41.2 POP
```text
POP_LL(TOP)
Step 1: If TOP == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: Set PTR = TOP
Step 3: Set ITEM = PTR->DATA
Step 4: Set TOP = TOP->NEXT
Step 5: Free PTR
Step 6: Return ITEM
Step 7: Exit
```

### 41.3 PEEK
```text
PEEK_LL(TOP)
Step 1: If TOP == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: Return TOP->DATA
Step 3: Exit
```

---

## 42. Expression Notations & Precedence

- **Infix:** Operator placed between operands (e.g., $A + B$).
- **Prefix (Polish):** Operator precedes operands (e.g., $+ A B$).
- **Postfix (Reverse Polish):** Operator follows operands (e.g., $A B +$).

### Operator Precedence & Associativity
| Operator | Description | Priority | Associativity |
| :---: | :--- | :---: | :---: |
| `^` / `$` | Exponentiation | 3 (Highest) | Right-to-Left |
| `*`, `/`, `%` | Multiplication, Division, Modulus | 2 | Left-to-Right |
| `+`, `-` | Addition, Subtraction | 1 (Lowest) | Left-to-Right |

---

## 43. Postfix Evaluation

### Algorithm
```text
EVALUATE_POSTFIX(P)
Step 1: Create empty STACK
Step 2: Scan P from left to right token by token:
Step 3:     If token is an operand:
                PUSH(token)
Step 4:     Else if token is an operator OP:
                Set A = POP()
                Set B = POP()
                Set RESULT = B OP A
                PUSH(RESULT)
Step 5: Set ANSWER = POP()
Step 6: Return ANSWER
Step 7: Exit
```

### Worked Trace: `5 6 2 + * 12 4 / -`
1. Push `5`, `6`, `2` $\rightarrow$ Stack: `[5, 6, 2]`
2. `+`: Pop `2`, `6` $\rightarrow 6 + 2 = 8 \rightarrow$ Push `8` $\rightarrow$ Stack: `[5, 8]`
3. `*`: Pop `8`, `5` $\rightarrow 5 \times 8 = 40 \rightarrow$ Push `40` $\rightarrow$ Stack: `[40]`
4. Push `12`, `4` $\rightarrow$ Stack: `[40, 12, 4]`
5. `/`: Pop `4`, `12` $\rightarrow 12 / 4 = 3 \rightarrow$ Push `3` $\rightarrow$ Stack: `[40, 3]`
6. `-`: Pop `3`, `40` $\rightarrow 40 - 3 = 37 \rightarrow$ Push `37` $\rightarrow$ Stack: `[37]`
**Answer:** `37`

---

## 44. Infix to Postfix Conversion

### Algorithm
```text
INFIX_TO_POSTFIX(Q)
Step 1: Initialize empty STACK
Step 2: Push '(' onto STACK
Step 3: Append ')' to expression Q
Step 4: Set output POSTFIX = ""
Step 5: Scan Q from left to right:
Step 6:     If token is an operand:
                Append token to POSTFIX
Step 7:     Else If token == '(':
                PUSH('(')
Step 8:     Else If token is an operator OP:
                While Precedence(TOP) >= Precedence(OP):
                    Append POP() to POSTFIX
                PUSH(OP)
Step 9:     Else If token == ')':
                While TOP != '(':
                    Append POP() to POSTFIX
                POP()  /* Discard '(' */
Step 10: Return POSTFIX
Step 11: Exit
```

### Worked Example: `A + (B * C + D) / E`
- Output: `A B C * D + E / +`

---

## 45. Infix to Prefix Conversion

### Algorithm
```text
INFIX_TO_PREFIX(EXP)
Step 1: Reverse the string EXP.
Step 2: In the reversed string, replace '(' with ')' and ')' with '('.
Step 3: Convert the modified string to postfix using INFIX_TO_POSTFIX.
Step 4: Reverse the resulting postfix expression.
Step 5: Return the reversed string as PREFIX.
Step 6: Exit
```

### Worked Example: `(A + B^C) * D + E^5`
- Prefix: `+ * + A ^ B C D ^ E 5`

---

## 46. Prefix Evaluation *(Supplemental)*

Scan the expression **from right to left**:

```text
EVALUATE_PREFIX(P)
Step 1: Create empty STACK
Step 2: Scan P from right to left token by token:
Step 3:     If token is an operand:
                PUSH(token)
Step 4:     Else if token is an operator OP:
                Set A = POP()
                Set B = POP()
                Set RESULT = A OP B  /* Note order: A OP B */
                PUSH(RESULT)
Step 5: Set ANSWER = POP()
Step 6: Return ANSWER
Step 7: Exit
```

---

## Unit 2 — Recursion

## 47. Recursion Principles

A function that calls itself directly or indirectly. Essential components:
1. **Base Case:** Condition under which recursion terminates directly.
2. **Recursive Case:** Rules that reduce the problem size toward the base case.
- Memory: Each recursive call adds a stack frame to the system call stack. Excessive depth causes **Stack Overflow**.

---

## 48. Factorial

### 48.1 Iterative
```text
FACTORIAL_ITERATIVE(N)
Step 1: Set FACT = 1
Step 2: For K = 1 to N:
            Set FACT = FACT * K
Step 3: Return FACT
Step 4: Exit
```

### 48.2 Recursive
```text
FACTORIAL(N)
Step 1: If N <= 1:
            Return 1
Step 2: Return N * FACTORIAL(N - 1)
```

- **Recurrence:** $T(n) = T(n-1) + O(1) \implies O(n)$ time, $O(n)$ call stack space.

---

## 49. Fibonacci Sequence

Definition: $F_0 = 0, F_1 = 1, F_n = F_{n-1} + F_{n-2}$

### 49.1 Recursive
```text
FIB(N)
Step 1: If N == 0: Return 0
Step 2: If N == 1: Return 1
Step 3: Return FIB(N - 1) + FIB(N - 2)
```
- **Time Complexity:** $O(2^n)$ (Exponential due to overlapping subproblems)

### 49.2 Iterative
```text
FIB_ITERATIVE(N)
Step 1: If N == 0: Return 0
Step 2: If N == 1: Return 1
Step 3: Set F0 = 0, Set F1 = 1
Step 4: For I = 2 to N:
            Set FIB = F0 + F1
            Set F0 = F1
            Set F1 = FIB
Step 5: Return F1
Step 6: Exit
```
- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(1)$

---

## 50. Tower of Hanoi

Rules:
1. Move one disk at a time.
2. Only the top disk of a peg can be moved.
3. No larger disk may be placed atop a smaller disk.

### Algorithm
```text
TOH(N, BEG, AUX, END)
Step 1: If N == 1:
            Print "Move disk from ", BEG, " -> ", END
            Return
Step 2: Call TOH(N - 1, BEG, END, AUX)
Step 3: Print "Move disk from ", BEG, " -> ", END
Step 4: Call TOH(N - 1, AUX, BEG, END)
Step 5: Return
```

- **Number of Moves:** $2^N - 1$
- **Time Complexity:** $O(2^N)$

---

## 51. Tail Recursion

A recursive function is **tail-recursive** if the recursive call is the final operation performed before returning. Compilers can optimize tail recursion into a loop (Tail Call Optimization).

```text
FACT_TAIL(N, ACC)
Step 1: If N <= 1:
            Return ACC
Step 2: Return FACT_TAIL(N - 1, ACC * N)
```
Invoked with `FACT_TAIL(N, 1)`.

---

## 52. Removing Recursion

1. **Loop Replacement:** Tail-recursive algorithms can be directly converted into simple `while` or `for` loops.
2. **Explicit Stack Simulation:** Non-tail recursive algorithms require an explicit stack data structure to store activation records (local variables and return points).

---

## Unit 2 — Queue

## 53. Queue ADT

A Queue operates under the **FIFO (First In, First Out)** principle.
- Elements are inserted at `REAR` (**Enqueue**).
- Elements are removed from `FRONT` (**Dequeue**).

---

## 54. Linear Queue Using Array

Initialization: `FRONT = -1, REAR = -1`.

### 54.1 ENQUEUE
```text
ENQUEUE(Q, SIZE, FRONT, REAR, ITEM)
Step 1: If REAR == SIZE - 1:
            Print "OVERFLOW"
            Exit
Step 2: If FRONT == -1:
            Set FRONT = 0
            Set REAR = 0
        Else:
            Set REAR = REAR + 1
Step 3: Set Q[REAR] = ITEM
Step 4: Exit
```

### 54.2 DEQUEUE
```text
DEQUEUE(Q, FRONT, REAR)
Step 1: If FRONT == -1 OR FRONT > REAR:
            Print "UNDERFLOW"
            Exit
Step 2: Set ITEM = Q[FRONT]
Step 3: If FRONT == REAR:
            Set FRONT = -1
            Set REAR = -1
        Else:
            Set FRONT = FRONT + 1
Step 4: Return ITEM
Step 5: Exit
```

> **Drawback of Linear Queue:** Memory wastage occurs when elements are dequeued; freed spaces cannot be reused even if `FRONT > 0` because `REAR` has reached the array boundary. Solved by **Circular Queues**.

---

## 55. Queue Using Linked List

Uses dynamic nodes with pointers `FRONT` and `REAR`.

### 55.1 ENQUEUE
```text
ENQUEUE_LL(ITEM)
Step 1: Allocate NEW_NODE
Step 2: If NEW_NODE == NULL:
            Print "OVERFLOW"
            Exit
Step 3: Set NEW_NODE->DATA = ITEM
Step 4: Set NEW_NODE->NEXT = NULL
Step 5: If FRONT == NULL:
            Set FRONT = NEW_NODE
            Set REAR = NEW_NODE
        Else:
            Set REAR->NEXT = NEW_NODE
            Set REAR = NEW_NODE
Step 6: Exit
```

### 55.2 DEQUEUE
```text
DEQUEUE_LL()
Step 1: If FRONT == NULL:
            Print "UNDERFLOW"
            Exit
Step 2: Set PTR = FRONT
Step 3: Set ITEM = PTR->DATA
Step 4: Set FRONT = FRONT->NEXT
Step 5: If FRONT == NULL:
            Set REAR = NULL
Step 6: Free PTR
Step 7: Return ITEM
Step 8: Exit
```

---

## 56. Circular Queue

Overcomes memory wastage by connecting the last position back to the first using modulo arithmetic: `(index + 1) MOD N`.

### 56.1 Circular ENQUEUE
```text
CIRCULAR_ENQUEUE(Q, N, FRONT, REAR, ITEM)
Step 1: If (FRONT == 0 AND REAR == N - 1) OR (REAR == FRONT - 1):
            Print "OVERFLOW: Queue is Full"
            Exit
Step 2: If FRONT == -1:
            Set FRONT = 0
            Set REAR = 0
        Else If REAR == N - 1 AND FRONT != 0:
            Set REAR = 0
        Else:
            Set REAR = REAR + 1
Step 3: Set Q[REAR] = ITEM
Step 4: Exit
```

### 56.2 Circular DEQUEUE
```text
CIRCULAR_DEQUEUE(Q, N, FRONT, REAR)
Step 1: If FRONT == -1:
            Print "UNDERFLOW: Queue is Empty"
            Exit
Step 2: Set ITEM = Q[FRONT]
Step 3: If FRONT == REAR:
            Set FRONT = -1
            Set REAR = -1
        Else If FRONT == N - 1:
            Set FRONT = 0
        Else:
            Set FRONT = FRONT + 1
Step 4: Return ITEM
Step 5: Exit
```

---

## 57. Deque (Double-Ended Queue)

Supports insertion and deletion at both ends (`FRONT` and `REAR`).
- **Input-Restricted Deque:** Insertion allowed only at one end; deletion allowed at both ends.
- **Output-Restricted Deque:** Deletion allowed only at one end; insertion allowed at both ends.

### Deque Operations *(Supplemental)*
- `INSERT_FRONT`: `FRONT = (FRONT - 1 + N) MOD N; Q[FRONT] = ITEM`
- `INSERT_REAR`: `REAR = (REAR + 1) MOD N; Q[REAR] = ITEM`
- `DELETE_FRONT`: `ITEM = Q[FRONT]; FRONT = (FRONT + 1) MOD N`
- `DELETE_REAR`: `ITEM = Q[REAR]; REAR = (REAR - 1 + N) MOD N`

---

## 58. Priority Queue

Each element has an associated priority. Elements are served based on priority:
- **Ascending Priority Queue:** Lowest numerical value has highest priority.
- **Descending Priority Queue:** Highest numerical value has highest priority.
- **Implementations:**
  - Unsorted Array: $O(1)$ insert, $O(n)$ delete.
  - Sorted Array: $O(n)$ insert, $O(1)$ delete.
  - Binary Heap: $O(\log n)$ insert, $O(\log n)$ delete.

---

## Unit 3 — Searching

## 59. Searching Overview

- **Internal Searching:** All data resides in primary memory (RAM).
- **External Searching:** Data resides in secondary storage (disks, SSDs).

---

## 60. Linear Search

Sequentially checks each element against the target value.

### Algorithm
```text
LINEAR_SEARCH(A, N, ITEM)
Step 1: For I = 0 to N - 1:
Step 2:     If A[I] == ITEM:
                Print "Found at index ", I
                Return I
Step 3: Print "Item not found"
Step 4: Return -1
Step 5: Exit
```

- **Best Case:** $O(1)$ (target is at index 0)
- **Worst / Average Case:** $O(n)$

---

## 61. Indexed Sequential Search

Requires sorted data. Divides data into blocks of size $k$ and maintains an auxiliary index containing the primary key of each block and its memory address.
1. Search the small index to identify candidate block: $O(n/k)$.
2. Search within the block sequentially: $O(k)$.
3. Optimal block size: $k = \sqrt{n}$, giving total search time $O(\sqrt{n})$.

---

## 62. Binary Search — Iterative

Requires a **sorted array**. Repeatedly divides the search space in half.

### Algorithm
```text
BINARY_SEARCH(A, N, ITEM)
Step 1: Set BEG = 0, Set END = N - 1
Step 2: While BEG <= END:
Step 3:     Set MID = BEG + (END - BEG) / 2
Step 4:     If A[MID] == ITEM:
                Return MID
Step 5:     Else If ITEM < A[MID]:
                Set END = MID - 1
Step 6:     Else:
                Set BEG = MID + 1
Step 7: Return -1  /* Not found */
Step 8: Exit
```

- **Best Case:** $O(1)$
- **Average / Worst Case:** $O(\log n)$
- **Space Complexity:** $O(1)$

---

## 63. Binary Search — Recursive

### Algorithm
```text
BINARY_SEARCH_RECURSIVE(A, BEG, END, ITEM)
Step 1: If BEG > END:
            Return -1
Step 2: Set MID = BEG + (END - BEG) / 2
Step 3: If A[MID] == ITEM:
            Return MID
Step 4: Else If ITEM < A[MID]:
            Return BINARY_SEARCH_RECURSIVE(A, BEG, MID - 1, ITEM)
Step 5: Else:
            Return BINARY_SEARCH_RECURSIVE(A, MID + 1, END, ITEM)
```

- **Time Complexity:** $O(\log n)$
- **Space Complexity:** $O(\log n)$ call stack space.

---

## Unit 3 — Hashing

## 64. Hashing Principles

Hashing maps arbitrary keys to fixed table indices using a hash function:
$$h(K) \rightarrow [0 \dots M-1]$$
- **Collision:** Occurs when two distinct keys hash to the same table slot: $h(K_1) = h(K_2)$ for $K_1 \neq K_2$.

---

## 65. Division Method

$$h(K) = K \pmod M$$
$M$ is typically chosen as a prime number not close to a power of 2 or 10 to minimize collisions.

- Example: $K = 12345, M = 95 \implies h(12345) = 12345 \pmod{95} = 90$.

---

## 66. Mid-Square Method

1. Square the key: $S = K^2$.
2. Extract the middle $r$ digits of $S$.

- Example: $K = 1234 \implies K^2 = 1,522,756$. For table size $M = 100$ ($r = 2$ digits), middle digits $= 22 \implies h(K) = 22$.

---

## 67. Folding Method

1. Partition key $K$ into equal-sized parts $K_1, K_2, \dots, K_p$.
2. Sum the parts: $S = K_1 + K_2 + \dots + K_p$.
3. Discard any final carry.

- Example: $K = 12345678$, 2-digit groups $\implies 12 + 34 + 56 + 78 = 180 \implies$ hash index $= 80$.

---

## 68. Multiplication Method

$$h(K) = \lfloor M \times (K \cdot A \pmod 1)\rfloor$$
where $0 < A < 1$ (Knuth recommends $A \approx \frac{\sqrt{5}-1}{2} \approx 0.6180339887$).

### Worked Example
$K = 12345, A = 0.357840, M = 100$:
1. $K \times A = 12345 \times 0.357840 = 4417.5348$
2. Fractional part $= 0.5348$
3. $M \times 0.5348 = 53.48$
4. $\lfloor 53.48 \rfloor = 53$

---

## 69. Collision Resolution Overview

1. **Separate Chaining (Open Hashing):** Colliding records stored outside the table in linked lists.
2. **Open Addressing (Closed Hashing):** All records stored directly in the table; alternative slots are inspected via systematic probing.

---

## 70. Separate Chaining (Open Hashing)

Each hash table slot contains a pointer to the head of a linked list.

```text
CHAIN_INSERT(TABLE, KEY)
Step 1: Set INDEX = HASH(KEY)
Step 2: Allocate NEW_NODE
Step 3: Set NEW_NODE->KEY = KEY
Step 4: Set NEW_NODE->NEXT = TABLE[INDEX]
Step 5: Set TABLE[INDEX] = NEW_NODE
Step 6: Exit
```

- **Load Factor:** $\alpha = \frac{n}{M}$.
- Average lookup time: $O(1 + \alpha)$.

---

## 71. Open Addressing (Closed Hashing)

All elements reside in the hash table array. Table size $M \ge N$.
> **Important Deletion Rule:** When an element is deleted, mark the slot as `DELETED` (tombstone) rather than `EMPTY`. An `EMPTY` slot halts search probes prematurely, which would cause previously inserted colliding keys to become unreachable.

---

## 72. Linear Probing

Probe sequence offsets linearly by 1:
$$h_i(K) = (h(K) + i) \pmod M \quad \text{for } i = 0, 1, \dots, M-1$$

### Insert Algorithm
```text
LINEAR_PROBE_INSERT(K, M)
Step 1: Set H = HASH(K)
Step 2: For I = 0 to M - 1:
            Set INDEX = (H + I) MOD M
            If TABLE[INDEX] is EMPTY or DELETED:
                Set TABLE[INDEX] = K
                Return SUCCESS
Step 3: Return OVERFLOW  /* Table is full */
Step 4: Exit
```

- **Drawback:** **Primary Clustering** (long contiguous blocks of occupied slots build up, degrading performance to $O(n)$).

---

## 73. Quadratic Probing

Probe sequence offsets quadratically:
$$h_i(K) = (h(K) + c_1 i + c_2 i^2) \pmod M \quad \text{or } (h(K) + i^2) \pmod M$$

- Eliminates Primary Clustering, but suffers from **Secondary Clustering** (keys with the same initial hash follow identical probe sequences).

---

## 74. Double Hashing

Uses two independent hash functions $h_1(K)$ and $h_2(K)$:
$$h_i(K) = [h_1(K) + i \cdot h_2(K)] \pmod M$$
Condition: $h_2(K)$ must be relatively prime to $M$ (e.g., $h_2(K) = 1 + (K \pmod{M-1})$).

### Algorithm
```text
DOUBLE_HASH_INSERT(K, M)
Step 1: Set H1 = h1(K)
Step 2: Set H2 = h2(K)
Step 3: For I = 0 to M - 1:
            Set INDEX = (H1 + I * H2) MOD M
            If TABLE[INDEX] is EMPTY or DELETED:
                Set TABLE[INDEX] = K
                Return SUCCESS
Step 4: Return OVERFLOW
Step 5: Exit
```

---

## Unit 3 — Sorting

## 75. Sorting Concepts & Terminology

- **Internal Sorting:** All data records fit entirely in primary memory (e.g., Quick Sort, Heap Sort).
- **External Sorting:** Data exceeds RAM capacity and is stored on disk/tapes, sorted in chunks, and merged (e.g., Multi-way Merge Sort).
- **Stability:** A sort is **stable** if elements with equal keys maintain their original relative order.
- **In-Place:** An algorithm is **in-place** if it uses $O(1)$ auxiliary memory beyond the input array.

---

## 76. Insertion Sort

Builds the sorted array one element at a time by picking the next element and shifting larger elements to the right.

### Algorithm
```text
INSERTION_SORT(A, N)
Step 1: For I = 1 to N - 1:
Step 2:     Set KEY = A[I]
Step 3:     Set J = I - 1
Step 4:     While J >= 0 AND A[J] > KEY:
                Set A[J + 1] = A[J]
                Set J = J - 1
Step 5:     Set A[J + 1] = KEY
Step 6: End For
Step 7: Exit
```

- **Best Case:** $O(n)$ (already sorted)
- **Worst / Average Case:** $O(n^2)$
- **Stable:** Yes | **In-Place:** Yes

---

## 77. Selection Sort

Repeatedly finds the minimum element from the unsorted sub-array and swaps it into its final sorted position.

### Algorithm
```text
SELECTION_SORT(A, N)
Step 1: For I = 0 to N - 2:
Step 2:     Set MIN_INDEX = I
Step 3:     For J = I + 1 to N - 1:
                If A[J] < A[MIN_INDEX]:
                    Set MIN_INDEX = J
Step 4:     If MIN_INDEX != I:
                Swap A[I] and A[MIN_INDEX]
Step 5: End For
Step 6: Exit
```

- **Best / Average / Worst Case:** $O(n^2)$ comparisons (independent of input order)
- **Swaps:** Exact $O(n)$ swaps
- **Stable:** Usually No | **In-Place:** Yes

---

## 78. Bubble Sort

Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### Standard Algorithm
```text
BUBBLE_SORT(A, N)
Step 1: For I = 0 to N - 2:
Step 2:     For J = 0 to N - 2 - I:
Step 3:         If A[J] > A[J + 1]:
                    Swap A[J] and A[J + 1]
Step 4: Exit
```

### Optimized Algorithm (Early Termination)
```text
BUBBLE_SORT_OPTIMIZED(A, N)
Step 1: For I = 0 to N - 2:
Step 2:     Set SWAPPED = FALSE
Step 3:     For J = 0 to N - 2 - I:
                If A[J] > A[J + 1]:
                    Swap A[J], A[J + 1]
                    Set SWAPPED = TRUE
Step 4:     If SWAPPED == FALSE:
                Break  /* Array is already sorted */
Step 5: Exit
```

- **Best Case:** $O(n)$ (optimized)
- **Worst / Average Case:** $O(n^2)$
- **Stable:** Yes | **In-Place:** Yes

---

## 79. Quick Sort

Divide-and-conquer algorithm that selects a pivot element and partitions the array such that all elements smaller than the pivot are on the left and all larger elements are on the right.

### 79.1 Quicksort
```text
QUICKSORT(A, P, R)
Step 1: If P < R:
Step 2:     Set Q = PARTITION(A, P, R)
Step 3:     Call QUICKSORT(A, P, Q - 1)
Step 4:     Call QUICKSORT(A, Q + 1, R)
Step 5: Exit
```

### 79.2 Partition (Lomuto Scheme, Pivot = `A[R]`)
```text
PARTITION(A, P, R)
Step 1: Set PIVOT = A[R]
Step 2: Set I = P - 1
Step 3: For J = P to R - 1:
            If A[J] <= PIVOT:
                Set I = I + 1
                Swap A[I] and A[J]
Step 4: Swap A[I + 1] and A[R]
Step 5: Return I + 1
Step 6: Exit
```

- **Best / Average Case:** $O(n \log n)$
- **Worst Case:** $O(n^2)$ (when array is already sorted or reverse sorted with end pivot)
- **Stable:** No | **In-Place:** Yes (requires $O(\log n)$ recursive stack space)

---

## 80. Merge Sort

Divide-and-conquer algorithm that divides the array into two halves, recursively sorts them, and merges the sorted halves.

### 80.1 Merge Sort
```text
MERGE_SORT(A, P, R)
Step 1: If P < R:
Step 2:     Set Q = P + (R - P) / 2
Step 3:     Call MERGE_SORT(A, P, Q)
Step 4:     Call MERGE_SORT(A, Q + 1, R)
Step 5:     Call MERGE(A, P, Q, R)
Step 6: Exit
```

### 80.2 Merge Procedure
```text
MERGE(A, P, Q, R)
Step 1: Set N1 = Q - P + 1
Step 2: Set N2 = R - Q
Step 3: Create temporary arrays L[0..N1-1] and R[0..N2-1]
Step 4: Copy A[P..Q] to L, and A[Q+1..R] to R
Step 5: Set I = 0, Set J = 0, Set K = P
Step 6: While I < N1 AND J < N2:
            If L[I] <= R[J]:
                Set A[K] = L[I]
                Set I = I + 1
            Else:
                Set A[K] = R[J]
                Set J = J + 1
            Set K = K + 1
Step 7: While I < N1:
            Set A[K] = L[I], Set I = I + 1, Set K = K + 1
Step 8: While J < N2:
            Set A[K] = R[J], Set J = J + 1, Set K = K + 1
Step 9: Exit
```

- **Best / Average / Worst Case:** $\Theta(n \log n)$
- **Auxiliary Space:** $O(n)$
- **Stable:** Yes | **In-Place:** No

---

## 81. Heap Sort

Comparison-based sort using a Complete Binary Max-Heap where parent $\ge$ children.

### 0-Based Index Formulas
- $\text{LEFT}(i) = 2i + 1$
- $\text{RIGHT}(i) = 2i + 2$
- $\text{PARENT}(i) = \lfloor (i - 1) / 2 \rfloor$

### 81.1 Heap Sort
```text
HEAP_SORT(A, N)
Step 1: Call BUILD_MAX_HEAP(A, N)
Step 2: For I = N - 1 down to 1:
            Swap A[0] and A[I]
            Call MAX_HEAPIFY(A, 0, I)
Step 3: Exit
```

### 81.2 Build Max Heap: $O(n)$
```text
BUILD_MAX_HEAP(A, N)
Step 1: For I = floor(N / 2) - 1 down to 0:
            Call MAX_HEAPIFY(A, I, N)
Step 2: Exit
```

### 81.3 Max Heapify: $O(\log n)$
```text
MAX_HEAPIFY(A, I, HEAP_SIZE)
Step 1: Set L = 2 * I + 1
Step 2: Set R = 2 * I + 2
Step 3: Set LARGEST = I
Step 4: If L < HEAP_SIZE AND A[L] > A[LARGEST]:
            Set LARGEST = L
Step 5: If R < HEAP_SIZE AND A[R] > A[LARGEST]:
            Set LARGEST = R
Step 6: If LARGEST != I:
            Swap A[I] and A[LARGEST]
            Call MAX_HEAPIFY(A, LARGEST, HEAP_SIZE)
Step 7: Exit
```

- **Time Complexity:** $O(n \log n)$ across all cases
- **Auxiliary Space:** $O(1)$
- **Stable:** No | **In-Place:** Yes

---

## 82. Radix Sort

Non-comparative integer sort that sorts keys digit by digit, from Least Significant Digit (LSD) to Most Significant Digit (MSD), using a stable sub-routine (Counting Sort).

### Algorithm
```text
RADIX_SORT_DECIMAL(A, N)
Step 1: Set MAXIMUM = maximum value in array A
Step 2: Set EXP = 1
Step 3: While MAXIMUM / EXP > 0:
Step 4:     Initialize COUNT[0..9] = 0
Step 5:     For I = 0 to N - 1:
                Set D = (A[I] / EXP) MOD 10
                Set COUNT[D] = COUNT[D] + 1
Step 6:     For I = 1 to 9:
                Set COUNT[I] = COUNT[I] + COUNT[I - 1]
Step 7:     For I = N - 1 down to 0:
                Set D = (A[I] / EXP) MOD 10
                Set OUTPUT[COUNT[D] - 1] = A[I]
                Set COUNT[D] = COUNT[D] - 1
Step 8:     Copy OUTPUT[0..N-1] to A[0..N-1]
Step 9:     Set EXP = EXP * 10
Step 10: Exit
```

- **Time Complexity:** $O(d \cdot (n + b))$ where $d = \text{number of digits}$, $b = \text{base (10)}$.
- **Auxiliary Space:** $O(n + b)$
- **Stable:** Yes | **In-Place:** No

---

## 83. Complexity Summary Tables

### 83.1 Searching Algorithms
| Algorithm | Best Time | Average Time | Worst Time | Space | Prerequisite |
| :--- | :---: | :---: | :---: | :---: | :--- |
| **Linear Search** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ | None |
| **Binary Search** | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ | Sorted Array |
| **Indexed Sequential** | $O(1)$ | $O(\sqrt{n})$ | $O(\sqrt{n})$ | $O(\sqrt{n})$ | Sorted Array + Index |

### 83.2 Sorting Algorithms
| Algorithm | Best Time | Average Time | Worst Time | Space | Stable | In-Place |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes | Yes |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | No | Yes |
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes | Yes |
| **Quick Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | No | Yes |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Yes | No |
| **Heap Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(1)$ | No | Yes |
| **Radix Sort** | $O(d(n+b))$ | $O(d(n+b))$ | $O(d(n+b))$ | $O(n+b)$ | Yes | No |

### 83.3 Core Data Structure Operation Complexities
| Data Structure | Access | Search | Insertion (Beg) | Insertion (End) | Deletion (Beg) | Deletion (End) |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Array** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)^*$ | $O(n)$ | $O(1)$ |
| **Singly Linked List** | $O(n)$ | $O(n)$ | $O(1)$ | $O(n)$ | $O(1)$ | $O(n)$ |
| **Doubly Linked List** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)^{**}$ | $O(1)$ | $O(1)^{**}$ |
| **Stack** | $O(n)$ | $O(n)$ | $O(1)$ (Push) | — | $O(1)$ (Pop) | — |
| **Queue** | $O(n)$ | $O(n)$ | — | $O(1)$ (Enqueue) | $O(1)$ (Dequeue) | — |
| **Hash Table** | — | $O(1)$ avg, $O(n)$ worst | $O(1)$ avg | $O(1)$ avg | $O(1)$ avg | $O(1)$ avg |

*\*Assuming capacity exists. \*\*With `TAIL` pointer.*

---

## 84. Exam Writing Templates

### 84.1 Universal Algorithm Presentation Formula
```text
ALGORITHM_NAME(Parameters)
Step 1: [Initialization] Initialize pointers, bounds, or flags.
Step 2: [Boundary Check] Check for OVERFLOW or UNDERFLOW.
Step 3: [Core Processing] Loop or recursive condition.
Step 4: [Pointer / Index Update] Advance pointers or increment indices.
Step 5: [Return / Result] Return computed value or display message.
Step 6: Exit.
```

### 84.2 Linked List Checkpoints
- Always test for:
  1. `HEAD == NULL` (empty list / underflow).
  2. `HEAD->NEXT == NULL` (single-node list).
  3. Updating pointers in the correct order to avoid orphaned memory.
  4. Explicit `free(PTR)` to prevent memory leaks.

### 84.3 Stack & Queue Invariants
- **Stack:** Check `TOP == MAX - 1` on `PUSH`, and `TOP == -1` on `POP`.
- **Queue:** Check `REAR == MAX - 1` on `ENQUEUE`, and `FRONT == -1` or `FRONT > REAR` on `DEQUEUE`.
- **Circular Queue:** Check `(FRONT == (REAR + 1) % N)` for overflow.

### 84.4 Quick Sort / Merge Sort Dual-Component Rule
- Never write Quick Sort or Merge Sort as a single block:
  - Quick Sort must be split into: `QUICKSORT()` and `PARTITION()`.
  - Merge Sort must be split into: `MERGE_SORT()` and `MERGE()`.

---

## 85. Rapid Revision Checklist & Memory Map

```text
DATA STRUCTURES ARCHITECTURE
│
├── UNIT 1: LINEAR STRUCTURES & MEMORY
│   ├── Arrays: 1D / 2D / ND Address calculation, Traversal, Insert, Delete, Sparse Triplet
│   ├── Memory Allocation: malloc(), calloc(), realloc(), free()
│   ├── Singly Linked List: Create, Traverse, Search, Insert/Delete (Beg/Mid/End)
│   ├── Doubly Linked List: Bidirectional links, Insert/Delete (Beg/Mid/End)
│   ├── Circular Linked List: Head-pointing tail, Traversal until Head
│   └── Polynomials: Representation (coeff, exp), Addition O(m+n), Multiplication O(m*n)
│
├── UNIT 2: RESTRICTED STRUCTURES & RECURSION
│   ├── Stack (LIFO): Array vs LL implementation, PUSH/POP/PEEK, Overflow/Underflow
│   ├── Expressions: Infix -> Postfix, Infix -> Prefix, Postfix Evaluation
│   ├── Recursion: Base case vs Recursive step, Factorial, Fibonacci, Tower of Hanoi (2^N - 1)
│   ├── Queue (FIFO): Linear Queue drawback, LL Queue
│   ├── Circular Queue: Modulo arithmetic ((rear + 1) % N)
│   └── Deque & Priority Queue: Input/Output restricted, Min/Max priority
│
└── UNIT 3: SEARCHING, HASHING & SORTING
    ├── Searching: Linear O(n), Binary O(log n), Indexed Sequential O(√n)
    ├── Hashing: Division (K mod M), Mid-Square, Folding, Multiplication
    ├── Collision Resolution:
    │   ├── Separate Chaining (Linked lists per slot)
    │   └── Open Addressing (Linear Probing, Quadratic Probing, Double Hashing)
    └── Sorting:
        ├── O(n^2): Insertion (best O(n)), Selection (O(n) swaps), Bubble
        ├── O(n log n): Quick Sort (Partition), Merge Sort (Merge), Heap Sort (Heapify)
        └── Non-Comparison: Radix Sort O(d(n+b))
```

---

## Final Exam Priority List

Memorize these 26 high-frequency algorithms first:

1. **Array Insertion & Deletion** (with element shift logic)
2. **Row-Major & Column-Major Address Calculations**
3. **Sparse Matrix Triplet Generation**
4. **Singly Linked List:** Insert & Delete at Beginning, End, and Position
5. **Doubly Linked List:** Insert & Delete (4-pointer update rule)
6. **Circular Linked List:** Insert & Delete (updating rear's next to head)
7. **Polynomial Addition** (ordered 3-case merge)
8. **Stack Operations:** `PUSH` and `POP` (Array & Linked List)
9. **Infix to Postfix Conversion** (Operator Stack precedence trace)
10. **Infix to Prefix Conversion** (Reverse $\rightarrow$ Postfix $\rightarrow$ Reverse)
11. **Postfix Expression Evaluation** (Operand stack evaluation)
12. **Recursive Factorial & Fibonacci**
13. **Tower of Hanoi** (Recursive 3-step solution)
14. **Queue:** `ENQUEUE` and `DEQUEUE` (Array & Linked List)
15. **Circular Queue:** `CIRCULAR_ENQUEUE` and `CIRCULAR_DEQUEUE`
16. **Binary Search:** Iterative and Recursive implementations
17. **Hash Functions:** Division, Mid-Square, Folding, Multiplication
18. **Collision Resolution:** Linear Probing vs Double Hashing vs Chaining
19. **Insertion Sort**
20. **Selection Sort**
21. **Bubble Sort** (with `SWAPPED` optimization flag)
22. **Quick Sort & Lomuto Partition**
23. **Merge Sort & Merge Procedure**
24. **Heap Sort:** `BUILD_MAX_HEAP` and `MAX_HEAPIFY`
25. **Radix Sort** (LSD Decimal with Counting Sort)
26. **Polynomial Multiplication**
