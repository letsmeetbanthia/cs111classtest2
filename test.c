// HELLO!!😀
#include <stdio.h>
#include <stdlib.h>

void split(int *arr, int size)
{
    // this array stores indices of biggest numbers in arr
    // if biggest number occures multiple times
    int highest_num_indices[size];

    // highest_index stores index of very first biggest number index
    int highest_index = 0;

    int tmp = 1;
    // storing indices in highest_num_indices array

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[highest_index])
        {
            highest_index = i;
            tmp = 1;
        }
        else if (arr[i] == arr[highest_index])
        {
            highest_num_indices[tmp] = i;
            tmp++;
        }
    }
    highest_num_indices[0] = highest_index;

    // highest_num_indices array stores all indices having biggest number of array
    // indices of highest_num_indices which stores are from 0 to tmp-1

    // second_highest_index stores index of second highest_index number in an array
    int second_highest_index;

    // this array stores diff of each element of array and biggest number
    int diff[size];

    // storing difference
    for (int i = 0; i < size; i++)
    {
        diff[i] = arr[highest_index] - arr[i];
    }

    int check = 0;
    // findinf the very first number in array which is not highest_index number
    // and storing in 'second_highest_index'
    for (int i = 0; i < size; i++)
    {
        if (diff[i] == 0)
        {
            check = 1;
            continue;
        }
        else
        {
            check = 0;
            second_highest_index = i;
            break;
        }
    }

    // checking whether all elements are same or not
    // if all are same, there is no second highrst number
    // thus no splitting should occur
    // check equals 1 means it never encounterd break in above for loop
    if (check == 1)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        return;
    }

    // finding index of (very first) second highest_index number
    for (int i = 0; i < size; i++)
    {
        if (diff[i] == 0)
        {
            continue;
        }
        else if (diff[i] < diff[second_highest_index])
        {
            second_highest_index = i;
        }
    }

    check = 0;
    int var = 0;
    int i;

    int second_highest = arr[second_highest_index];
    int extra = arr[highest_index] - arr[second_highest_index];

    // splitting the array
    // by creating space and storing extra in created space
    while (var < tmp)
    {
        for (i = size - 1 + check; i >= highest_num_indices[var] + 1 + check; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i] = second_highest;
        arr[i + 1] = extra;
        var++;
        check++;
    }

    // printing resultant array
    for (i = 0; i < size + tmp; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
// logic
{
    // input size
    int size;
    // size must be positive number
    do
    {
        printf("Enter the size of array : ");
        scanf("%d", &size);
        getchar();
    } while (size <= 0);

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