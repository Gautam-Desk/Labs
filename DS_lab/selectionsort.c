#include <stdio.h>
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}