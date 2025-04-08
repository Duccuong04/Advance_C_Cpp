#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insert(int *arr, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", arr + i);
    }
}

void swap(int *a, int *b){
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

int binarySearch(int *arr, int ArraySize, int x){
    //bubbleSort(arr, ArraySize);

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

void display(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("arr[%d] = %d  ", i, *(arr + i));
    }
}

void generateRandom(int *arr, int size){
    // khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    // sinh ngẫu nhiên các phần tử cho mảng
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 10000;
    }
}

int main(int argc, char const *argv[])
{
    int n = 10000, x;
   
    int *arr = (int*)malloc(n * sizeof(int));

    generateRandom(arr, n);
    display(arr, n);

    printf("Nhập giá trị cần tìm: "); scanf("%d", &x);

    bubbleSort(arr, n);
    display(arr, n);

    printf("\n");

    printf("Tìm thấy %d ở arr[%d]", x, binarySearch(arr, n, x));

    free(arr);


    return 0;
}