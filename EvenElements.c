#include <stdio.h>
int main()
{
    int arr[30];
    printf("Enter any 30 array elements: ");
    for (int i = 0; i < 30; i++)
        scanf("%d", &arr[i]);
    printf("\nAll Even Array elements are:\n");
    for (int i = 0; i < 30; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
