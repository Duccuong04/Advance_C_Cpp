#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../Header/random.h"

void generateRandom(int *arr, int size){
    // khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    // sinh ngẫu nhiên các phần tử cho mảng
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 10000;
    }
}