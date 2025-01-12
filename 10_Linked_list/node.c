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

void display (Node *first)
{
    int i = 0;
    if(first == NULL)
    {
        printf("Ko có node");
    }

    else
    {
        while(first != NULL)
        {
            printf("Node %d: %d\n", i, first->data);
            first = first->next;
            i++;
        }
    }
}

/* thêm 1 node vào phía cuối 
- Tìm node cuối cùng
- Khai báo con trỏ cấp 2 để có thể thao tác trực tiếp với địa chỉ
*/ 
void push_back(Node **first, int data)
{
    // tạo node
    Node *new_node = createNode(data);

    if(*first == NULL) // giải tham chiếu để đọc được địa chỉ node đầu tiên
    {
        *first = new_node;
    } 

    Node *p = *first; // khai báo con trỏ trung gian để không làm việc trực tiếp với first

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = new_node;
}

/*
Chèn 1 node vào vị trí bất kì
- Duyệt địa chỉ để tìm tới node tương ứng
- Thay đổi con trỏ next
*/
void insert(Node **first, int data, int position)
{
    Node *new_node = createNode(data);

    if(*first == NULL)
    {
        *first = new_node;
    }

    Node *p = *first;
    int k = 0;

    while(p->next != NULL && k!= position - 1)
    {
        k++;
        p = p->next;
    }

    if(k == position - 1)
    {
        new_node->next = p->next;
        p->next = new_node;
    }
}
/*
Xóa node đầu tiên
*/
void pop_front(Node **first)
{
    if(*first == NULL)
    {
        printf("ko có node");
    }
    Node *p = *first;
    free(p);
    *first = (*first)->next;
}
/*
Xoá node cuối cùng
*/
void pop_back(Node **first)
{
    if(*first == NULL)
    {
        printf("ko có node");
    }
    
    Node *p = *first;
    if(p->next == NULL)
    {
        free(p);
        *first = NULL;
    }
    while(p->next->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;   
}
int main(int argc, char const *argv[])
{
    Node *first = createNode(1);   // first = 0x01, &first: địa chỉ của con trỏ
    Node *second = createNode(2);  // 0xa5
    Node *third = createNode(3);   // 0xff

    // liên kết 3 node
    first->next = second;
    second->next = third;
    
    

    //insert(&first, 100, 3);

    pop_front(&first);

    pop_back(&first);

    display(first);

    push_back(&first, 15);
    return 0;
}
