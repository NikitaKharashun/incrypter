#include <stdio.h>

int strlen_(char* string)
{
    int length = 0;

    while (string[length] != '\0')
        length++;

    return length;
}

int isInArray(int arr[], int element, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == element)
            return 1;
    }
    return 0;
}


void arrayShow(int* arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d  ", *(arr + i));

    printf("\n");
}
