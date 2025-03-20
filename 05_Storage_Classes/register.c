#include<stdio.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    clock_t start_time = clock();
    register int i;

    for(i = 0; i < 200000000; i++)
    {
        // do something
    }

    clock_t end_time = clock();
    // tính thời gian chạy bằng mili giây

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Run time = %f", time_taken);
    return 0;
}
