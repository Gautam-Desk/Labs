/*
 * Array Deletion Algorithm in C
 *
 * Algorithm:
 * 1. Read the number of elements n in the array.
 * 2. Read n elements into the array.
 * 3. Read the position of the element to delete.
 * 4. If the position is valid (0 <= pos < n):
 *       a. Shift all elements after pos one position to the left.
 *       b. Decrease the size n by 1.
 *    Otherwise, print an error message.
 * 5. Print the updated array after deletion.
 *
 * This example uses 0-based indexing for array positions.
 */

#include <stdio.h>

int main(void)
{
    int A[20]; /* Fixed-size array with maximum capacity 20 */
    int n;     /* Current number of elements */
    int pos;   /* Position to delete (0-based index) */
    int i;

    printf("Enter number of elements (max 20): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n)
    {
        printf("Invalid position. No deletion performed.\n");
        return 1;
    }

    /* Shift elements left to overwrite the deleted element. */
    for (i = pos; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }

    n--; /* Decrease the size of the array after deletion. */

    printf("Array after deletion:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

/*
 * Explanation:
 *
 * 1. The program begins by declaring an integer array A with fixed capacity.
 * 2. It reads the number of elements `n` and then reads each element into A.
 * 3. The user specifies the index position of the element to delete.
 * 4. The program checks whether the position is valid for the current array size.
 * 5. If valid, elements after the deleted position are shifted left by one index.
 *    This overwrites the element at `pos` and closes the gap.
 * 6. The array size `n` is decremented to reflect the removed element.
 * 7. The updated array is printed, showing the array after deletion.
 *
 * Deletion in an array requires shifting because arrays must remain contiguous.
 * The element removed is not physically deleted from memory, but the logical size
 * of the array is reduced and later elements are moved left.
 */