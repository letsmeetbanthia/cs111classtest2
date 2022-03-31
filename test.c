// HELLO!!😀
#include <stdio.h>
#include <stdlib.h>

void split(int *arr, int size)
{
    //this array stores indices of biggest numbers in arr
    //if biggest number occures multiple times
    int *store_big=malloc(size*sizeof(int));

    //big stores index of very first biggest number index
    int big = 0;

    int tmp = 1;
    //storing indices in store_big array
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
    store_big[0] = big;

    // store_big array stores all indices having biggest number of array
    // indices of stor_big array which stores are from 0 to tmp-1
    store_big = realloc(store_big,tmp*sizeof(int));

    //less stores index of second highest number in an array
    int less;

    //this array stores diff of each element of array and biggest number
    int store_less_big[size];

    //storing difference
    for (int i = 0; i < size; i++)
    {
        store_less_big[i] = arr[big] - arr[i];
    }

    int check =0;
    //findinf the very first number in array which is not highest number
    //and storing in 'less'
    for (int i = 0; i < size; i++)
    {
        if (store_less_big[i] == 0)
        {
            check=1;
            continue;
        }
        else
        {
            check=0;
            less = i;
            break;
        }
    }

    //checking whether all elements are same or not
    //if all are same, there is no second highrst number
    //thus no splitting should occur
    //check equals 1 means it never encounterd break in above for loop
    if(check==1)
    {
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
        }
        return;
    }

    //finding index of (very first) second highest number
    for (int i = 0; i < size; i++)
    {
        if (store_less_big[i] == 0)
        {
            continue;
        }
        else if (store_less_big[i] < store_less_big[less])
        {
            less = i;
        }
    }

    int counter = 0;
    int var = 0;
    int i;

    int second_highest = arr[less];
    int extra = arr[big]-arr[less];

    //splitting the array
    //by creating space and storing extra in created space
    while (var < tmp)
    {
        for (i = size - 1 + counter; i >= store_big[var] + 1 + counter; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i] = second_highest;
        arr[i+1] = extra;
        var++;
        counter++;
    }

    //free allocated space
    free(store_big);

    //printing resultant array
    for(i=0;i<size+tmp;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main(void)
// logic
{
    // input size
    int size;
    //size must be positive number 
    do
    {
    printf("Enter the size of array : ");
    scanf("%d", &size);
    getchar();
    }while(size<=0);

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