#include <stdio.h>

void ReverseAndOdds(int arr[], int size, int *sum, int *max)
{
    *sum = 0;
    *max = arr[size - 1];

    printf("Odd elements (in reverse order): ");

    for (int i = size - 1; i >= 0; i--)
    {
        *sum += arr[i];

        if (arr[i] > *max)
        {
            *max = arr[i];
        }

        if (arr[i] % 2 != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int size, totalSum, maxElement;

    printf("Enter number of elements (up to 100): ");
    scanf("%d", &size);

    int arr[100];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    ReverseAndOdds(arr, size, &totalSum, &maxElement);

    printf("Sum of elements= %d\n", totalSum);
    printf("Maximum element= %d\n", maxElement);

    return 0;
}
