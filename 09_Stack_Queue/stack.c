#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    int *item; // khai báo mảng lưu trữ phần từ, cấp phát động, có thể thay đổi số phần tử của mảng
    int size;  // số lượng phần tử của mảng
    int top;   // chỉ số lấy giá trị ở đỉnh
} Stack;

// hàm khởi tạo
void init(Stack *stack1, int size1)
{
    stack1->size = size1;
    stack1->item = (int *)malloc(size1 * sizeof(int)); // cấp phát 1 phân vùng nhớ để lưu trữ mảng
    stack1->top = -1; // ban đầu stack rỗng
}  

// kiểm tra stack đầy
bool isFull(Stack stack)
{
    return (stack.top == stack.size - 1) ? true : false;
}

// kiểm tra stack rỗng
bool isEmpty(Stack stack)
{
    return (stack.top == -1) ? true : false;
}

// thêm phần tử
void push(Stack *stack, int data)
{
    if(isFull(*stack) == false) // truyền vào *stack để đọc giá trị
    {
        stack->item[++stack->top] = data;
    }
    else
    {
        printf("Stack đầy!\n");
    }
}

// xóa phần tử
int pop(Stack *stack)
{
    if(isEmpty(*stack) == false)
    {
        return stack->item[stack->top--];
    }
    else
    {
        printf("Stack rỗng\n");
        return -1;
    }
}

// đọc giá trị đỉnh stack
int top(Stack stack)
{
    if(isEmpty(stack) == false) // truyền vào stack
    {
        return stack.item[stack.top];
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    Stack stack;

    int size = 5;
    init(&stack, size);

    printf("push process\n");
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);

    for(int i = 0; i <stack.size; i++)
    {
        printf("Value: %d, Adr: %p\n", stack.item[i], &stack.item[i]);
    }

    printf("Top = %d\n", top(stack));

    printf("pop process\n");
    for(int i = 0; i < stack.size; i++)
    {
        printf("data at top: %d - addr: %p\n", top(stack), &(stack.item[stack.top]));
        pop(&stack);
    } 
    return 0;
}
