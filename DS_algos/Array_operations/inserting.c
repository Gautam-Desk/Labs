/*
 * Array Insertion Algorithm in C
 *
 * Algorithm:
 * 1. Read the number of elements n in the array.
 * 2. Read n elements into the array.
 * 3. Read the value to insert and the insertion position.
 * 4. If the position is valid (0 <= pos <= n) and the array is not full:
 *       a. Shift elements from the end to pos one place right.
 *       b. Insert the new value at A[pos].
 *       c. Increase n by 1.
 *    Otherwise, print an error message.
 * 5. Print the array after insertion.
 */

#include <stdio.h>

int main(void)
{
    int A[20]; /* Fixed-size array with maximum capacity 20 */
    int n;     /* Current number of elements */
    int value; /* Value to insert */
    int pos;   /* Insertion position (0-based index) */
    int i;

    printf("Enter number of elements (max 20): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);
    printf("Enter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n || n >= 20)
    {
        printf("Invalid position or array is full.\n");
        return 1;
    }

    for (i = n; i > pos; i--)
    {
        A[i] = A[i - 1];
    }

    A[pos] = value;
    n++;

    printf("Array after insertion:\n");
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
 * 1. The program starts by declaring a fixed-size array A with capacity 20.
 * 2. It reads the current number of elements `n` from the user, then reads
 *    exactly `n` integer values into the array.
 * 3. The program asks for the new value to insert and the position where
 *    the element should be inserted. The position uses 0-based indexing.
 * 4. It checks that the insertion position is valid and that the array has
 *    space for one more element.
 * 5. To make room, elements from the end of the current segment are shifted
 *    one position to the right, starting from index `n` down to `pos + 1`.
 * 6. The new value is then stored at `A[pos]`, and the array size `n` is
 *    incremented by one.
 * 7. Finally, the updated array elements are printed in order.
 *
 * This algorithm shows how insertion in an array requires shifting elements
 * to maintain the contiguous structure of the array. If you insert at the
 * beginning, nearly every element must move; inserting at the end only adds
 * the value without shifting other elements.
 */
