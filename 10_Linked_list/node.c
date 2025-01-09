#include <stdio.h>
#include <stdlib.h>

// khai báo 1 Node gồm 2 thành phần là data và 1 con trỏ
typedef struct Node
{
    int data;
    struct Node *next; // con trỏ mang kiểu struct Node vì nó cũng mang địa chỉ của Node khác (gồm dữ liệu và địa chỉ tiếp theo)
} Node;

// thay vì trả về kiểu void, trả về địa chỉ cụ thể, truyền địa chỉ này vào các hàm khác nhau để tái sử dụng. Dùng hàm trả về con trỏ
Node* createNode(int value)
{
    // cấp phát 1 vùng địa chi để lưu dữ liệu và con trỏ của Node
    Node *node = (Node*)malloc(sizeof(Node));
    // khởi tạo dữ liệu
    node->data = value;
    node->next = NULL;
    return node; // trả về địa chỉ 
}

/* thêm 1 node vào phía cuối 
- Tìm node cuối cùng
*/ 
void push_back(Node **first, int data)
{
    // tạo node
    Node *new_node = createNode(data);

    if(*first == NULL)
    {
        *first = new_node;
    } 

    while((*first)->next != NULL)
    {
        *first = (*first)->next;
    }

    (*first)->next = new_node;
}

int main(int argc, char const *argv[])
{
    Node *first = createNode(1);   // first = 0x01, &first: địa chỉ của con trỏ
    Node *second = createNode(2);  // 0xa5
    Node *third = createNode(3);   // 0xff

    // liên kết 3 node
    first->next = second;
    second->next = third;
    return 0;
}
