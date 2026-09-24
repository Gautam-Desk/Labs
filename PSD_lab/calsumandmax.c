#include <stdio.h>
void calSumAndMax(int arr[], int size, int *sum, int *max)
{
    *sum = 0;
    *max = arr[0];

    for (int i = 0; i < size; i++)
    {
        *sum += arr[i];

        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
}
int main()
{
    int size, totalSum, maxElement;

    printf("Enter number of elements ");
    scanf("%d", &size);

    int arr[100];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    calSumAndMax(arr, size, &totalSum, &maxElement);

    printf("Sum of all elements = %d\n", totalSum);
    printf("Maximum element = %d\n", maxElement);

    return 0;
}
