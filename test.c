// HELLO!!😀
#include <stdio.h>

void split(int *arr, int size)
{
    int big = 0;
    int store_big[size];
    int tmp = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[big])
        {
            big = i;
            tmp = 1;
        }
        else if (arr[i] == arr[big])
        {
            store_big[tmp] = i;
            tmp++;
        }
    }
    // store_big array stores all indices having biggest number of array
    // indices of stor_big array which stores are from 0 to tmp-1
    store_big[0] = big;
    int less;
    int store_less_big[size];
    for (int i = 0; i < size; i++)
    {
        store_less_big[i] = arr[big] - arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (store_less_big[i] == 0)
        {
            continue;
        }
        else
        {
            less = i;
            break;
        }
    }
    for(int i=0;i<size;i++)
    {
        if (store_less_big[i] == 0)
        {
            continue;
        }
        else if(store_less_big[i]<store_less_big[less])
        {
            less = i;
        }
    }
    printf("%d",arr[less]);
}

int main(void)
// logic
{
    // input size
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    getchar();

    int arr[size * 2 - 1];

    // input elements of array
    printf("Enter elements of array : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        getchar();
    }

    // message
    printf("After splitting new list is : ");

    split(arr, size);
    printf("\n");

    // congrats!! code succeeded
    return 0;
}