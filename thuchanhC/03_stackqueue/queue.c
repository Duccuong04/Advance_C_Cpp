#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Mảng lưu trữ các thành phần trong queue
 */
typedef struct 
{
    int *item; // mảng lưu trữ giá trị các phần tử
    int size;  // số lượng phần tử tối đa có thể đưa vào
    int front; // chỉ số của phần tử đầu hàng đợi
    int rear;  // chỉ số của phần tử cuối hàng đợi
} Queue;

/**
 * Hàm khởi tạo các giá trị trong Queue
 * Giá trị mặc định khi queue rỗng front = rear = -1, thêm phần tử đầu tiên front = rear = 0
 */
void init(Queue *queue, int size)
{
    queue->size = size;
    queue->item = (int*)malloc(size * sizeof(int));
    queue->front = queue->rear = -1;
}

/**
 * Hàm kiểm tra queue đầy chưa
 */
bool isFull(Queue queue)
{
    return (queue.rear = queue.size - 1) ? true : false;
}

/**
 * Hàm kiểm tra queue rỗng
 * 2 trường hợp Queue rỗng
 */
bool isEmpty(Queue queue)
{
    return ((queue.front == -1) || queue.front == queue.rear + 1) ? true : false;
} 


/**
 * Enqueue thêm phần tử vào cuối hàng đợi
 */
void enqueue(Queue *queue, int data)
{
    // Kiểm tra queue đã đầy chưa
    if(isFull(*queue))
    {
        printf("Hàng đợi đầy\n");
    }
    else
    {
        // Nếu queue rỗng, tăng front = rear = 0
        if(queue->front == -1 && queue->rear == -1)
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            // tăng rear để thêm phần tử
            ++queue->rear;
        }

        queue->item[queue->rear] = data;

        printf("Enqueue");
    }
}

/**
 *  Hàm lấy phần tử ở đầu hàng đợi
 *  
 * */
int dequeue(Queue *queue)
{
    if(isEmpty(*queue)) // giải tham chiếu để lấy được thông tin của địa chỉ
    {
        printf("Hàng đợi rỗng\n");
        return -1;
    }
    else
    {
        int dequeue_value = queue->item[queue->front]; // lấy phần tử ở đầu hàng đợi

        queue->item[queue->front] = 0; // cho phần tử đầu hàng đợi = 0

        if(queue->front == queue->rear && queue->rear == queue->size - 1)
        {
            queue->front = queue->rear = -1;
        } // nếu rear lớn nhất và front = rear (tức là đã lấy hết phần tử)
        else
        {
            queue->front ++; // ko nằm trong TH trên thì chỉ tăng front lên 1
        }

        return dequeue_value;

    }
}

/**
 * Hàm lấy tất cả các giá trị trong Queue
 */
void display(Queue queue)
{
    if(isEmpty(queue))
    {
        printf("Hàng đợi rỗng\n");
    }
    else
    {
        printf("Queue: ");

        for(int i = queue.front; i <= queue.rear; i++)
        {
            printf("%d", queue.item[i]);
        }
        printf("\n");
    }
}

int front(Queue queue)
{
    if(isEmpty(queue))
    {
        printf("Hàng đợi rỗng\n");
        return -1;
    }
    else
    {
        return queue.item[queue.front];

    }
}

int rear(Queue queue)
{
    if(isEmpty(queue))
    {
        printf("Hàng đợi rỗng\n");
        return -1;
    }
    else
    {
        return queue.item[queue.rear];

    }
}

int main(int argc, char const *argv[])
{
    Queue liQueue;

    int size = 5;

    init(&liQueue, size);

    enqueue(&liQueue, 1);
    enqueue(&liQueue, 2);
    enqueue(&liQueue, 3);
    enqueue(&liQueue, 4);
    enqueue(&liQueue, 5);
    enqueue(&liQueue, 6);

    printf("Front: %d\n", front(liQueue));

    display(liQueue);

    printf("Dequeue %d\n", dequeue(&liQueue));

    display(liQueue);

    return 0;
}
