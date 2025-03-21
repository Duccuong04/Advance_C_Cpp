#include <stdio.h>
#include <stdlib.h>

int main() {
    // Sử dụng malloc()
    int* arr1 = (int*)malloc(5 * sizeof(int));
    printf("Sau khi malloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]); // Dữ liệu rác
    }
    printf("\n");

    // Sử dụng calloc()
    int* arr2 = (int*)calloc(5, sizeof(int));
    printf("Sau khi calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]); // Tất cả là 0
    }
    printf("\n");

    // Sử dụng realloc()
    arr1 = (int*)realloc(arr1, 10 * sizeof(int));
    printf("Sau khi realloc (mở rộng lên 10 phần tử):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr1[i]); // 5 phần tử đầu giữ nguyên, 5 phần tử mới là dữ liệu rác
    }
    printf("\n");

    // Giải phóng bộ nhớ
    free(arr1);
    free(arr2);

    return 0;
}
