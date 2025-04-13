#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *task1(void *data){
    static int i = 0;
    for (int i=0; i<8; i++){
        printf("count task1: %d\n", i++);
        sleep(1);
    }
}
void *task2(void *data){
    static int i = 0;
    while(1){
        printf("count task2: %d\n", i++);
        sleep(3);
    }
}
void *display(void *a){
    while(1){
        printf("%s\n", (char*)a);
        sleep(1);
    }
}
int main(int argc, char const *argv[]){
    pthread_t t1; // luồng 1
    pthread_t t2; // luồng 2
    pthread_t t3; // luồng 3

    char *ptr = "Hello\n";
   
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_create(&t3, NULL, display, ptr);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    while(1)
    {
        printf("Hello world\n");
        sleep(1);
    }
    return 0;
}


    