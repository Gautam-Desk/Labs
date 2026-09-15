/**
 * Unit 2 — Classical Recursion Algorithms
 * Topics:
 *   - Factorial (Iterative, Recursive, Tail-Recursive)
 *   - Fibonacci (Recursive, Iterative O(n) Time / O(1) Space)
 *   - Tower of Hanoi (3-peg recursive simulation, 2^N - 1 moves)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* ========================================================================= */
/* Factorial                                                                 */
/* ========================================================================= */

unsigned long long fact_iterative(int n) {
    unsigned long long fact = 1;
    for (int k = 1; k <= n; k++) {
        fact *= k;
    }
    return fact;
}

unsigned long long fact_recursive(int n) {
    if (n <= 1) return 1;
    return n * fact_recursive(n - 1);
}

unsigned long long fact_tail_helper(int n, unsigned long long acc) {
    if (n <= 1) return acc;
    return fact_tail_helper(n - 1, acc * n);
}

unsigned long long fact_tail(int n) {
    return fact_tail_helper(n, 1);
}

/* ========================================================================= */
/* Fibonacci                                                                 */
/* ========================================================================= */

unsigned long long fib_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

unsigned long long fib_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    unsigned long long f0 = 0, f1 = 1;
    for (int i = 2; i <= n; i++) {
        unsigned long long fib = f0 + f1;
        f0 = f1;
        f1 = fib;
    }
    return f1;
}

/* ========================================================================= */
/* Tower of Hanoi                                                            */
/* ========================================================================= */

static int toh_move_count = 0;

void toh(int n, char beg, char aux, char end) {
    if (n == 1) {
        toh_move_count++;
        printf("  Move %2d: Move disk 1 from %c -> %c\n", toh_move_count, beg, end);
        return;
    }
    toh(n - 1, beg, end, aux);
    toh_move_count++;
    printf("  Move %2d: Move disk %d from %c -> %c\n", toh_move_count, n, beg, end);
    toh(n - 1, aux, beg, end);
}

int main(void) {
    printf("=== UNIT 2: Classical Recursion Tests ===\n\n");

    /* 1. Factorial tests for N = 5 (Expected: 120) */
    unsigned long long f_it = fact_iterative(5);
    unsigned long long f_rec = fact_recursive(5);
    unsigned long long f_tail = fact_tail(5);
    printf("1. Factorial(5):\n   Iterative = %llu | Recursive = %llu | Tail-Rec = %llu\n",
           f_it, f_rec, f_tail);
    assert(f_it == 120 && f_rec == 120 && f_tail == 120);

    /* 2. Fibonacci tests for N = 10 (Expected: 55) */
    unsigned long long fib_r = fib_recursive(10);
    unsigned long long fib_i = fib_iterative(10);
    printf("\n2. Fibonacci(10):\n   Recursive = %llu | Iterative = %llu (Expected: 55)\n",
           fib_r, fib_i);
    assert(fib_r == 55 && fib_i == 55);

    /* 3. Tower of Hanoi for N = 3 disks (Expected: 2^3 - 1 = 7 moves) */
    printf("\n3. Tower of Hanoi for N = 3 disks (Poles A, B, C):\n");
    toh_move_count = 0;
    toh(3, 'A', 'B', 'C');
    printf("   Total moves executed: %d (Expected: 7)\n", toh_move_count);
    assert(toh_move_count == 7);

    printf("\n>>> All Classical Recursion tests passed successfully!\n\n");
    return 0;
}
