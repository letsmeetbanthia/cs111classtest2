// HELLO!!😀
#include <stdio.h>

int main(void)
// logic
{
    // input size
    int size;
    printf("Enter the size of array : ");
    scanf("%d", size);
    getchar();

    int arr[size * 2 - 1];

    // input elements of array
    printf("Enter elements of array : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", arr[i]);
        getchar();
    }

    // message
    printf("After splitting new list is : ");

    split(arr, size);
    printf("\n");

    // congrats!! code succeeded
    return 0;
}