#include <stdio.h>
#include "../Header/bubbleSort.h"

static void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n){
    for (int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

void display(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d   ", i, *(arr + i));
    }
}