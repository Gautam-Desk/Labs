/*
 * Traversing a linear array in C.
 *
 * This example reads an array of integers from the user and then visits
 * each element in sequence to print it back. The traversal is performed
 * using a for loop, which is equivalent to the classical linear array
 * traversal algorithm:
 *     for k = LB to UB do
 *         visit LA[k]
 *     end for
 *
 * The array has a fixed maximum size of 20 in this example.
 */

#include <stdio.h>

int main(void) {
    int A[20];          /* Storage for up to 20 integers */
    int size;           /* Number of elements actually used */
    int k;

    /* Read the number of elements from the user and validate it. */
    printf("Enter the array size (1 to 20): ");
    if (scanf("%d", &size) != 1 || size < 1 || size > 20) {
        printf("Invalid size. Please enter a value between 1 and 20.\n");
        return 1;
    }

    /* Read each array element one by one. */
    for (k = 0; k < size; k++) {
        printf("Enter element %d: ", k);
        if (scanf("%d", &A[k]) != 1) {
            printf("Invalid input. Expecting an integer.\n");
            return 1;
        }
    }

    /* Print all array elements using linear traversal. */
    printf("The array elements are: ");
    for (k = 0; k < size; k++) {
        printf("%d ", A[k]);
    }
    printf("\n");

    return 0;
}

/*
 * Explanation:
 *
 * 1. The program declares an integer array A with a fixed capacity of 20.
 * 2. It reads the number of elements that the user wants to store in the array.
 * 3. The elements are entered one by one and stored at indices 0 through size-1.
 * 4. The program then traverses the array from index 0 to index size-1.
 * 5. Each visited array element is printed in the same order it was entered.
 *
 * This demonstrates linear traversal of an array: visit each element exactly once
 * using a loop. The `for` loop is the traversal mechanism and `A[k]` is the visited
 * element at each step.
 */