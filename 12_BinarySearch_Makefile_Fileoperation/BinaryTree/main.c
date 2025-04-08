#include <stdio.h>
#include <time.h>
#include <stdlib.h>



typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// thêm node mới vào theo thứ tự tăng dần
void add_node(Node **head, int value)
{
    // tạo node mới
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    // trường hợp node đầu hoặc các node kế tiếp < node đầu
    if (*head == NULL || value < (*head)->data)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // trường hợp còn lại
    Node *current = *head;
    while(current->next != NULL && value > current->next->data)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

}

// cấu trúc 1 node trong cây nhị phân
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;  
} TreeNode;

// xây dựng cây tìm kiếm nhị phân
TreeNode *buildTree(Node *head, int start, int end)
{
    if (head == NULL || start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node *node = head;
    for (size_t i = start; i < mid; i++)
    {
        if (node->next == NULL)
            break;
        node = node->next;
    }
    
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = node->data;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

// tạo cây tìm nhị phân
TreeNode *Certainpoint(Node *head)
{
    int lenght = 0;
    Node *node = head;
    while (node != NULL)
    {
        node = node->next;
        ++lenght;
    }

    return buildTree(head, 0, lenght - 1);
}

TreeNode *binarySearch(TreeNode *root, int value)
{
    static int loop = 0;
    loop++;
    printf("số lần lặp: %d\n", loop);

    if (root == NULL)
        return NULL;

    if (value == root->data)
        return root;

    else if (value < root->data)
        return binarySearch(root->left, value);

    else 
        return binarySearch(root->right, value);

}

void print_list(Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
        ++i;
    }
    
}

int main(int argc, char const *argv[])
{
    Node *head =NULL;

    // tạo linked list với 10k phần tử
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int value = rand() % 10000 + 1;
        add_node(&head, value);
    }

    print_list(head);

    TreeNode *root = Certainpoint(head);

    int x = 90
    ;

    TreeNode *result = binarySearch(root, x);

    if (result)
        printf("Tim thay %d\n", result->data);
    else printf("khong tim thay\n");



    return 0;
}