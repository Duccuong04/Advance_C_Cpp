#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;

  
        if (arr[mid] == x)  return mid;

   
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

  
        return binarySearch(arr, mid + 1, r, x);
    }




    return -1;
}

void swap(int *a, int *b)
{
    int temp = *a; // 0x02 (10), 0x03 (20)
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
       
        for (j = 0; j < n - i - 1; j++)
        {
           
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main()
{
	int n, x, i;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Nhap cac phan tu cua mang: ");
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf_s("i = %d\n", arr[i]);
    }

    printf_s("Nhap gia tri can tim: ");
    scanf_s("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf_s("Khong tim thay %d trong mang.\n", x);
    else
        printf_s("Tim thay %d tai vi tri %d trong mang.\n", x, result);
    free(arr);
    return 0;
}

