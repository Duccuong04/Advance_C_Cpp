#include <stdio.h>
#include <unistd.h>
void task1(){
    static int count = 0;
    count++;
    printf("Count taks1: %d\n", count);
    sleep(1);
}
void task2(){
    static int count = 0;
    count++;
    printf("Count taks2: %d\n", count);
    sleep(3);
}
int main(int argc, char const *argv[]){
    while(1){
        task1();
        task2();
    }
    return 0;
}
