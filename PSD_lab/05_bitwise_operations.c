/**
 * Problem Solving in C (PSD Lab) — Bitwise Operations & Bit Manipulation
 * Topics:
 *   - Bitwise Operators (&, |, ^, ~, <<, >>)
 *   - Check, Set, Clear, and Toggle Bit at Position k
 *   - Test if an Integer is a Power of Two
 *   - Count Set Bits (Hamming Weight / Brian Kernighan's Algorithm)
 *   - Swap Two Integers using In-Place XOR
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool is_bit_set(int n, int k) {
    return (n & (1 << k)) != 0;
}

int set_bit(int n, int k) {
    return n | (1 << k);
}

int clear_bit(int n, int k) {
    return n & ~(1 << k);
}

int toggle_bit(int n, int k) {
    return n ^ (1 << k);
}

bool is_power_of_two(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int count_set_bits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); /* Clears the lowest set bit */
        count++;
    }
    return count;
}

void xor_swap(int *a, int *b) {
    if (a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

int main(void) {
    printf("========================================================\n");
    printf("   PSD Lab: Bitwise Operations & Bit Tricks\n");
    printf("========================================================\n\n");

    /* 1. Bit testing and manipulation on n = 12 (binary: 0000 1100) */
    int n = 12;
    assert(is_bit_set(n, 2) == true);
    assert(is_bit_set(n, 3) == true);
    assert(is_bit_set(n, 0) == false);

    /* Set bit 0 -> 12 | 1 = 13 */
    int s = set_bit(n, 0);
    printf("Set bit 0 of %d -> %d\n", n, s);
    assert(s == 13);

    /* Clear bit 2 -> 12 & ~4 = 8 */
    int c = clear_bit(n, 2);
    printf("Clear bit 2 of %d -> %d\n", n, c);
    assert(c == 8);

    /* Toggle bit 3 -> 12 ^ 8 = 4 */
    int t = toggle_bit(n, 3);
    printf("Toggle bit 3 of %d -> %d\n", n, t);
    assert(t == 4);

    /* 2. Power of two check */
    assert(is_power_of_two(1) == true);
    assert(is_power_of_two(16) == true);
    assert(is_power_of_two(1024) == true);
    assert(is_power_of_two(18) == false);
    assert(is_power_of_two(0) == false);

    /* 3. Count set bits (Brian Kernighan's Algorithm) */
    assert(count_set_bits(7) == 3);     /* 0111 -> 3 */
    assert(count_set_bits(15) == 4);    /* 1111 -> 4 */
    assert(count_set_bits(1023) == 10); /* 10 ones */

    /* 4. XOR Swap */
    int a = 1234, b = 5678;
    xor_swap(&a, &b);
    printf("XOR Swap: a = %d, b = %d\n", a, b);
    assert(a == 5678 && b == 1234);

    printf("\n[PASS] All Bitwise Manipulation tests passed successfully!\n");
    return 0;
}
