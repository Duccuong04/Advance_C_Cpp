#include <stdio.h>
#include "../Header/binarySearch.h"


int binarySearch(int *arr, int ArraySize, int x){
    int left = 0, right = ArraySize - 1;

    while (right >= left)
    {
        int mid = (left + right) / 2;

        if (x == arr[mid])
            return mid;
        else if (x > arr[mid])
            left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
}

